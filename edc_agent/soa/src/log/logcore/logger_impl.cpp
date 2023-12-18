#include "asf/logging/logsdk/logcore/logger_impl.hpp"

#include <algorithm>

#include "asf/logging/logsdk/details/config.hpp"
#include "asf/logging/logsdk/details/loglog.hpp"
#include "asf/logging/logsdk/details/log_level_helper.hpp"
#include "asf/logging/logsdk/details/utils.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {

LoggerImpl::LoggerImpl(const std::string& name)
    : spdlog::logger(name)
{
    ASF_LOGSDK_TRACE_ENTRY();
    set_error_handler([this](const std::string& err_msg) {
        ASF_LOGSDK_INTERNAL_ERROR("in logger " + this->name_ + " : " + err_msg);
    });
    set_level(spdlog::level::level_enum::trace);
    ASF_LOGSDK_TRACE_EXIT();
}

LoggerImpl::~LoggerImpl()
{
    ASF_LOGSDK_TRACE_EXIT();
}

void LoggerImpl::Initialize(const std::shared_ptr<SdkContext>& context)
{
    if (context && context->configurator)
    {
        // set default flush log level
        const spdlog::level::level_enum flush_level = 
            details::LogLevelHelper::StringToSpdLogLevel(context->configurator->GetFlushLevel());
        flush_on(flush_level);

        const spdlog::level::level_enum console_level =
            details::LogLevelHelper::StringToSpdLogLevel(context->configurator->GetConsoleLogLevel());
        const spdlog::level::level_enum file_level =
            details::LogLevelHelper::StringToSpdLogLevel(context->configurator->GetFileLogLevel());
        this->set_level(std::min(console_level, file_level));

        configurator_ = context->configurator;
        compressor_ = context->file_compressor;

        if (!context->configurator->IsLoaded())
        {
            ASF_LOGSDK_INTERNAL_WARN("in logger " + name_ + " : configuration is not loaded");
        }

        if (!name_.empty())
        {
            initialize_console_sink_(context);
            initialize_file_sink_(context);
        }
    }
    else
    {
        ASF_LOGSDK_INTERNAL_WARN("in logger " + name_ + " : context is invalid");
    }
}

const std::shared_ptr<LoggerImpl::file_sink_t>& LoggerImpl::file_sink() const
{
    return file_sink_;
}

const std::shared_ptr<sinks::stdout_sink_mt>& LoggerImpl::console_sink() const
{
    return console_sink_;
}

std::uint8_t& LoggerImpl::get_log_index()
{
    return log_index_;
}

void LoggerImpl::format_log_prefix(spdlog::level::level_enum log_level,
    spdlog::memory_buf_t& dest, const std::string& trace_id)
{
    auto time = std::chrono::system_clock::now();
    std::tm tm_time = spdlog::details::os::localtime(std::chrono::system_clock::to_time_t(time));
    
    dest.push_back('[');

    // date time in format "yyyy/MM/dd hh:mm:ss.uuuuuu"
    spdlog::details::fmt_helper::append_int(tm_time.tm_year + 1900, dest);
    dest.push_back('/');
    spdlog::details::fmt_helper::pad2(tm_time.tm_mon + 1, dest);
    dest.push_back('/');
    spdlog::details::fmt_helper::pad2(tm_time.tm_mday, dest);
    dest.push_back(' ');
    spdlog::details::fmt_helper::pad2(tm_time.tm_hour, dest);
    dest.push_back(':');
    spdlog::details::fmt_helper::pad2(tm_time.tm_min, dest);
    dest.push_back(':');
    spdlog::details::fmt_helper::pad2(tm_time.tm_sec, dest);
    dest.push_back('.');
    auto micros = spdlog::details::fmt_helper::time_fraction<std::chrono::microseconds>(time);
    spdlog::details::fmt_helper::pad6(static_cast<uint32_t>(micros.count()), dest);
    dest.push_back(' ');

    // log index (cycle)
    spdlog::details::fmt_helper::pad3(log_index_++, dest);
    dest.push_back(' ');

    // domain id
    const std::string& domain_id = configurator_->GetData().domain_id;
    dest.append(domain_id.data(), domain_id.data() + domain_id.size());
    dest.push_back(' ');

    // app id
    const std::string& app_id = configurator_->GetData().app_id;
    dest.append(app_id.data(), app_id.data() + app_id.size());
    dest.push_back(' ');

    // logger name
    dest.append(name_.data(), name_.data() + name_.size());
    dest.push_back(' ');

    // level
    spdlog::details::fmt_helper::append_string_view(details::LogLevelHelper::LogLevelToStringViewForOutput(log_level), dest);
    dest.push_back(' ');

    // pid
    static const int pid = spdlog::details::os::pid(); // call only once
    spdlog::details::fmt_helper::append_int(pid, dest);
    dest.push_back(' ');

    // tid
    spdlog::details::fmt_helper::append_int(spdlog::details::os::thread_id(), dest);
    dest.push_back(' ');

    // trace id
    dest.append(trace_id.c_str(), trace_id.c_str() + trace_id.size());

    dest.push_back(']');
    dest.push_back(' ');
}

void LoggerImpl::initialize_console_sink_(const std::shared_ptr<SdkContext>& context)
{
    try
    {
        console_sink_ = std::make_shared<sinks::stdout_sink_mt>();
        // pattern
        // console_sink_->set_pattern(details::cfg::kLogPattern);
        // log level
        spdlog::level::level_enum default_log_level = details::LogLevelHelper::GetDefaultLogLevel();
        console_sink_->set_level(details::LogLevelHelper::StringToSpdLogLevel(
            context->configurator->GetConsoleLogLevel(), default_log_level));
    }
    catch (const std::exception& ex)
    {
        ASF_LOGSDK_INTERNAL_ERROR(ex.what());
        return;
    }
    catch (...)
    {
        ASF_LOGSDK_INTERNAL_ERROR("Unknown error");
        return;
    }

    sinks_.push_back(console_sink_);
}

void LoggerImpl::initialize_file_sink_(const std::shared_ptr<SdkContext>& context)
{
    try
    {
        const auto& conf_data = context->configurator->GetData();

        std::function<void(spdlog::filename_t&&, const spdlog::filename_t&)> after_open = 
            [this](spdlog::filename_t&& file, const spdlog::filename_t&) {
                // 如果 file 为空, 则为首次打开日志文件，不压缩, 由 compressor_ 判断是否需要压缩
                if (!file.empty() && this->compressor_)
                {
                    compressor_->AsyncCompress(std::move(file));
                }
                else
                {
                    details::Utils::KeepLogFileCount(configurator_->GetData().log_file_dir, name_,
                        configurator_->GetData().max_log_files);
                }
        };

        file_sink_ = std::make_shared<file_sink_t>(conf_data.log_file_dir, name_, conf_data.log_file_max_size * 1024,
            after_open, nullptr);
        // log level
        file_sink_->set_level(details::LogLevelHelper::StringToSpdLogLevel(
            context->configurator->GetFileLogLevel(), details::LogLevelHelper::GetDefaultLogLevel()));
    }
    catch (const std::exception& ex)
    {
        ASF_LOGSDK_INTERNAL_ERROR_ARGS("Failed to initialize file sink, detail (%s)", ex.what());
        return;
    }
    catch (...)
    {
        ASF_LOGSDK_INTERNAL_ERROR("Unknown error");
        return;
    }

    this->sinks_.push_back(file_sink_);
}

} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf