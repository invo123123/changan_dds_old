#include "asf/logging/logsdk/logger.hpp"

#include "asf/logging/logsdk/logcore/initializer_impl.hpp"
#include "asf/logging/logsdk/logcore/logger_manager.hpp"
#include "asf/logging/logsdk/details/log_level_helper.hpp"
#include "asf/logging/logsdk/details/loglog.hpp"

#define ASF_LOGSDK_UNINITIALIZED_ERROR() \
    ASF_LOGSDK_INTERNAL_ERROR("The asf_logsdk is not initialized!")

#define ASF_LOGSDK_INVALID_LOGGER_ERROR() \
    ASF_LOGSDK_INTERNAL_ERROR("The logger is invalid!")

namespace asf {
namespace logging {
namespace logsdk {

const std::string Logger::kDefaultTraceId = ASF_LOGSDK_DEFAULT_TRACE_ID;

Logger::Logger() noexcept
    : impl_(nullptr)
{ }

Logger::Logger(const std::string& name)
    : impl_(std::move(Logger::GetInstance(name).impl_))
{ }

Logger::Logger(const Logger& rhs) noexcept
    : impl_(rhs.impl_)
{ }

Logger::Logger(Logger&& rhs) noexcept
    : impl_(std::move(rhs.impl_))
{ }

Logger& Logger::operator=(const Logger& rhs) noexcept
{ 
    Logger(rhs).Swap(*this);
    return *this;
}

Logger& Logger::operator=(Logger&& rhs) noexcept
{
    Logger(std::move(rhs)).Swap(*this);
    return *this;
}

Logger::Logger(const std::shared_ptr<logcore::LoggerImpl>& impl)
    : impl_(impl)
{ }

Logger::~Logger()
{ }

Logger Logger::GetInstance(const std::string& name)
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetLoggerManager())
    {
        return Logger(logcore::g_initializer_impl->GetLoggerManager()->GetLoggerImpl(name));
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return Logger();
    }
}

Logger Logger::GetDefault()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetLoggerManager() && 
        logcore::g_initializer_impl->GetContext() &&
        logcore::g_initializer_impl->GetContext()->configurator)
    {
        const std::string& logger_name = 
            logcore::g_initializer_impl->GetContext()->configurator->GetData().default_logger_name;

        static Logger loggerDefault = Logger(logcore::g_initializer_impl->GetLoggerManager()->GetLoggerImpl(logger_name)); // 使用静态局部变量，在后续GetDefault时不会重新创建Logger(频繁创建Logger导致CPU消耗高)
        return loggerDefault;
        //return Logger(logcore::g_initializer_impl->GetLoggerManager()->GetLoggerImpl(logger_name));
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return Logger();
    }
}

bool Logger::IsExists(const std::string& name)
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetLoggerManager())
    {
        return logcore::g_initializer_impl->GetLoggerManager()->IsExists(name);
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return false;
    }
}

LogLevel Logger::GetGlobalFlushLevel()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() &&
        logcore::g_initializer_impl->GetContext()->configurator)
    {
        std::string level_string = logcore::g_initializer_impl->GetContext()->configurator->GetFlushLevel();
        return details::LogLevelHelper::StringToLogLevel(level_string);
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return LogLevel::kOff;
    }
}

bool Logger::SetGlobalFlushLevel(LogLevel level)
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() &&
        logcore::g_initializer_impl->GetContext()->configurator)
    {
        std::string level_string = details::LogLevelHelper::LogLevelToString(level);
        return logcore::g_initializer_impl->GetContext()->configurator->SetFlushLevel(level_string);
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return false;
    }
}

LogLevel Logger::GetFlushLevel() const
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return LogLevel::kOff;
    }
    else
    {
        return details::LogLevelHelper::CastLogLevel(impl_->flush_level());
    }
}

void Logger::SetFlushLevel(LogLevel level)
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return;
    }
    else
    {
        impl_->flush_on(details::LogLevelHelper::CastLogLevel(level));
    }
}

const std::string& Logger::GetName() const
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        static std::string empty_name;
        return empty_name;
    }
    else
    {
        return impl_->name();
    }
}

bool Logger::IsValid() const
{
    return impl_.operator bool();
}

void Logger::SetFileLogLevel(LogLevel level)
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return;
    }

    auto sink = impl_->file_sink();
    if (sink)
    {
        const auto file_level = details::LogLevelHelper::CastLogLevel(level);
        sink->set_level(file_level);
        if (file_level < impl_->level())
        {
            impl_->set_level(file_level);
        }
    }
}

LogLevel Logger::GetFileLogLevel() const
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return LogLevel::kOff;
    }

    auto sink = impl_->file_sink();
    if (sink)
    {
        return details::LogLevelHelper::CastLogLevel(sink->level());
    }
    return LogLevel::kOff;
}

void Logger::SetConsoleLogLevel(LogLevel level)
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return;
    }

    auto sink = impl_->console_sink();
    if (sink)
    {
        const auto console_level = details::LogLevelHelper::CastLogLevel(level);
        sink->set_level(console_level);
        if (console_level < impl_->level())
        {
            impl_->set_level(console_level);
        }
    }
}

LogLevel Logger::GetConsoleLogLevel() const
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return  LogLevel::kOff;
    }

    auto sink = impl_->console_sink();
    if (sink)
    {
        return details::LogLevelHelper::CastLogLevel(sink->level());
    }
    return LogLevel::kOff;
}

bool Logger::SetGlobalFileLogLevel(LogLevel level)
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() &&
        logcore::g_initializer_impl->GetContext()->configurator &&
        logcore::g_initializer_impl->GetLoggerManager())
    {
        std::string level_string = details::LogLevelHelper::LogLevelToString(level);
        std::string error_msg;
        if (logcore::g_initializer_impl->GetContext()->configurator->SetFileLogLevel(level_string, error_msg))
        {
            logcore::g_initializer_impl->GetLoggerManager()->SetFileLogLevel(details::LogLevelHelper::CastLogLevel(level));
            return true;
        }

        return false;
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return false;
    }
}

LogLevel Logger::GetGlobalFileLogLevel()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() &&
        logcore::g_initializer_impl->GetContext()->configurator)
    {
        std::string level_string = logcore::g_initializer_impl->GetContext()->configurator->GetFileLogLevel();
        return details::LogLevelHelper::StringToLogLevel(level_string);
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return LogLevel::kOff;
    }
}

bool Logger::SetGlobalConsoleLogLevel(LogLevel level)
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() &&
        logcore::g_initializer_impl->GetContext()->configurator &&
        logcore::g_initializer_impl->GetLoggerManager())
    {
        std::string level_string = details::LogLevelHelper::LogLevelToString(level);
        std::string error_msg;
        if (logcore::g_initializer_impl->GetContext()->configurator->SetConsoleLogLevel(level_string, error_msg))
        {
            logcore::g_initializer_impl->GetLoggerManager()->SetConsoleLogLevel(details::LogLevelHelper::CastLogLevel(level));
            return true;
        }

        return false;
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return false;
    }
}

LogLevel Logger::GetGlobalConsoleLogLevel()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() &&
        logcore::g_initializer_impl->GetContext()->configurator)
    {
        std::string level_string = logcore::g_initializer_impl->GetContext()->configurator->GetConsoleLogLevel();
        return details::LogLevelHelper::StringToLogLevel(level_string);
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
        return LogLevel::kOff;
    }
}

LogLevel Logger::GetLogLevel() const
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return LogLevel::kOff;
    }
    return details::LogLevelHelper::CastLogLevel(impl_->level());
}

void Logger::Flush()
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return;
    }

    try
    {
        impl_->flush();
    }
    catch (const std::exception& ex)
    {
        ASF_LOGSDK_INTERNAL_ERROR(ex.what());
    }
    catch (...)
    {
        ASF_LOGSDK_INTERNAL_ERROR("Unknown error");
    }
}

void Logger::FlushAll()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetLoggerManager())
    {
        logcore::g_initializer_impl->GetLoggerManager()->FlushAll();
    }
    else
    {
        ASF_LOGSDK_UNINITIALIZED_ERROR();
    }
}

void Logger::Swap(Logger& other) noexcept
{
    impl_.swap(other.impl_);
}

LogStream Logger::Log(LogLevel log_level, const std::string& trace_id) const
{
    LogStream stream(impl_, log_level, trace_id);
    return stream;
}

LogStream Logger::Trace(const std::string& trace_id) const
{
    return Log(LogLevel::kTrace, trace_id);
}

LogStream Logger::Debug(const std::string& trace_id) const
{
    return Log(LogLevel::kDebug, trace_id);
}

LogStream Logger::Info(const std::string& trace_id) const
{
    return Log(LogLevel::kInfo, trace_id);
}

LogStream Logger::Warn(const std::string& trace_id) const
{
    return Log(LogLevel::kWarn, trace_id);
}

LogStream Logger::Error(const std::string& trace_id) const
{
    return Log(LogLevel::kError, trace_id);
}

LogStream Logger::Fatal(const std::string& trace_id) const
{
    return Log(LogLevel::kFatal, trace_id);
}

LogStream Logger::LogFormat(LogLevel log_level, StringView msg) const
{
    LogStream stream(Log(log_level));
    stream << msg;
    return stream;
}

void Logger::AppendSink(spdlog::sink_ptr sink)
{
    if (!impl_)
    {
        ASF_LOGSDK_INVALID_LOGGER_ERROR();
        return;
    }

    if (sink)
    {
        impl_->sinks().push_back(sink);

        if (sink->level() < impl_->level())
        {
            impl_->set_level(sink->level());
        }
    }
}

} // namespace logsdk
} // namespace logging
} // namespace asf