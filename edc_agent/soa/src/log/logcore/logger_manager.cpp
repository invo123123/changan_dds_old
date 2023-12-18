#include "asf/logging/logsdk/logcore/logger_manager.hpp"

#include "asf/logging/logsdk/details/utils.hpp"
#include "asf/logging/logsdk/details/loglog.hpp"
#include "asf/logging/logsdk/details/config.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {

LoggerManager::LoggerManager()
{
    ASF_LOGSDK_TRACE_EXIT();
}

LoggerManager::LoggerManager(const std::shared_ptr<SdkContext>& sdk_context)
    : sdk_context_(sdk_context)
{
    ASF_LOGSDK_TRACE_EXIT();
}

LoggerManager::~LoggerManager()
{
    ASF_LOGSDK_TRACE_EXIT();
}

void LoggerManager::SetSdkContext(const std::shared_ptr<SdkContext>& sdk_context)
{
    sdk_context_ = sdk_context;
}

std::shared_ptr<SdkContext>& LoggerManager::GetSdkContext()
{
    return sdk_context_;
}

const std::shared_ptr<SdkContext>& LoggerManager::GetSdkContext() const
{
    return sdk_context_;
}

std::shared_ptr<LoggerImpl> LoggerManager::GetLoggerImpl(const std::string& name)
{
    if (name.empty()) // || !details::Utils::IsFileNameValid(name) 由于这个动作会大量消耗CPU性能，暂时屏蔽
    {
        const std::string app_name = details::Utils::GetApplicationName();
        if (app_name.empty()) // || !details::Utils::IsFileNameValid(app_name) 由于这个动作会大量消耗CPU性能，暂时屏蔽
        {
            return GetLoggerImpl(details::cfg::kDefaultLoggerName);
        }
        return GetLoggerImpl(app_name);
    }

    // find first. Read lock
    {
        details::ReadLockGuard<details::RWMutex> r_lock(mutex_);
        auto it = logger_impl_map_.find(name);
        if (it != logger_impl_map_.end())
        {
            return it->second;
        }
    }

    // if not find, create it. Write lock
    details::WriteLockGuard<details::RWMutex> w_lock(mutex_);
    std::shared_ptr<LoggerImpl> impl = std::make_shared<LoggerImpl>(name);
    impl->Initialize(sdk_context_);
    logger_impl_map_.emplace(name, impl);
    return impl;
}

bool LoggerManager::IsExists(const std::string& name)
{
    if (name.empty())
    {
        return false;
    }

    // read lock
    details::ReadLockGuard<details::RWMutex> r_lock(mutex_);
    auto it = logger_impl_map_.find(name);
    return it != logger_impl_map_.end();
}

void LoggerManager::SetFileLogLevel(spdlog::level::level_enum log_level)
{
    // read lock
    details::ReadLockGuard<details::RWMutex> r_lock(mutex_);

    for (auto& logger_impl : logger_impl_map_)
    {
        auto sink = logger_impl.second->file_sink();
        if (sink)
        {
            sink->set_level(log_level);
            if (log_level < logger_impl.second->level())
                logger_impl.second->set_level(log_level);
        }
        else
            ASF_LOGSDK_INTERNAL_ERROR("LoggerManager::SetFileLogLevel sink Unknown error");
    }
}

void LoggerManager::SetConsoleLogLevel(spdlog::level::level_enum log_level)
{
    // read lock
    details::ReadLockGuard<details::RWMutex> r_lock(mutex_);

    for (auto& logger_impl : logger_impl_map_)
    {
        auto sink = logger_impl.second->console_sink();
        if (sink)
        {
            sink->set_level(log_level);
            if (log_level < logger_impl.second->level())
                logger_impl.second->set_level(log_level);
        }
        else
            ASF_LOGSDK_INTERNAL_ERROR("LoggerManager::SetConsoleLogLevel sink Unknown error");
    }
}

void LoggerManager::SetFlushLevel(spdlog::level::level_enum log_level)
{
    // read lock
    details::ReadLockGuard<details::RWMutex> r_lock(mutex_);

    for (auto& logger_impl : logger_impl_map_)
    {
        try 
        {
            logger_impl.second->flush_on(log_level);
        }
        catch (const std::exception& ex)
        {
            ASF_LOGSDK_INTERNAL_ERROR(ex.what());
        }
        catch (...)
        {
            ASF_LOGSDK_INTERNAL_ERROR("LoggerManager::SetFlushLevel Unknown error");
        }
    }
}

void LoggerManager::FlushAll()
{
    // read lock
    details::ReadLockGuard<details::RWMutex> r_lock(mutex_);

    for (auto& logger_impl : logger_impl_map_)
    {
        try
        {
            // spdlog::sinks::base_sink::flush() is thread safety.
            logger_impl.second->flush();
        }
        catch (const std::exception& ex)
        {
            ASF_LOGSDK_INTERNAL_ERROR(ex.what());
        }
        catch (...)
        {
            ASF_LOGSDK_INTERNAL_ERROR("LoggerManager::FlushAll() Unknown error");
        }
    }
}

} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf