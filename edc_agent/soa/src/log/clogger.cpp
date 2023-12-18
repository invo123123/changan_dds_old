#include "asf/logging/logsdk/clogger.h"

#include <cstdio>
#include <cstdarg>
#include <memory>
#include <thread>
#include <algorithm>

#include "asf/logging/logsdk/initializer.hpp"
#include "asf/logging/logsdk/logging_macro.hpp"

namespace asf_logging_logsdk4c {

// log message buffer for per thread.
thread_local std::unique_ptr<char[]> g_log_message_buffer;
// log message buffer size for per thread
thread_local std::size_t g_log_message_buffer_size = 0;
// The maximum length of log message buffer
constexpr std::size_t kMaxLengthOfLogMesssageBuffer = 1024;

static void log_vsnprintf(asf::logging::logsdk::LogStream& log_stream, const char* format, va_list& args)
{
    va_list args_copy;
    va_copy(args_copy, args);

    std::size_t size = std::vsnprintf(nullptr, 0, format, args);
    if (size <= 0)
    {
        va_end(args_copy);
        return;
    }

    // If the required memory space over limits, a temp buffer is applied to 
    // prevent the resident from occupying a large amount of memory space.
    if (size >= kMaxLengthOfLogMesssageBuffer)
    {
        std::unique_ptr<char[]> buffer(new char[size + 1]);
        std::vsnprintf(buffer.get(), size + 1, format, args_copy);
        va_end(args_copy);
        log_stream << asf::logging::logsdk::StringView(buffer.get(), size);
    }
    else
    {
        // Reapply the memory if the required memory space is larger than the current buffer size.
        // Otherwise, use it directly. 
        if (size >= g_log_message_buffer_size)
        {
            g_log_message_buffer.reset(nullptr);
            g_log_message_buffer = std::unique_ptr<char[]>(new char[size + 1]);
            g_log_message_buffer_size = size + 1;
        }
        std::vsnprintf(g_log_message_buffer.get(), size + 1, format, args_copy);
        va_end(args_copy);
        log_stream << asf::logging::logsdk::StringView(g_log_message_buffer.get(), size);
    }
}

void logger_log(asf::logging::logsdk::Logger& logger, asf_logsdk_loglevel_t level,
    const char* trace_id, const char* format, va_list& args)
{
    if (!logger.IsValid() || level >= ASF_LOGSDK_LOGLEVEL_OFF || level < ASF_LOGSDK_LOGLEVEL_TRACE)
    {
        return;
    }

    if (level < static_cast<asf_logsdk_loglevel_t>(logger.GetLogLevel()))
    {
        return;
    }

    asf::logging::logsdk::LogStream stream(logger.Log(static_cast<asf::logging::logsdk::LogLevel>(level),
        std::string(trace_id ? trace_id : asf::logging::logsdk::Logger::kDefaultTraceId)));

    va_list args_copy;
    va_copy(args_copy, args);
    asf_logging_logsdk4c::log_vsnprintf(stream, format, args_copy);
    va_end(args_copy);
}

void logger_log_with_source_loc(asf::logging::logsdk::Logger& logger, asf_logsdk_loglevel_t level,
    const char* trace_id, const char* file, uint_least32_t line, const char* format, va_list& args)
{
    if (!logger.IsValid() || level >= ASF_LOGSDK_LOGLEVEL_OFF || level < ASF_LOGSDK_LOGLEVEL_TRACE)
    {
        return;
    }

    if (level < static_cast<asf_logsdk_loglevel_t>(logger.GetLogLevel()))
    {
        return;
    }
    
    asf::logging::logsdk::LogStream stream(logger.Log(static_cast<asf::logging::logsdk::LogLevel>(level),
        std::string(trace_id ? trace_id : asf::logging::logsdk::Logger::kDefaultTraceId)));

    stream << (file ? asf::logging::logsdk::ExtractFileName(file) : ASF_LOGGING_LOGSDK_DEFAULT_FILE) << ':' << line << ' ';

    va_list args_copy;
    va_copy(args_copy, args);
    asf_logging_logsdk4c::log_vsnprintf(stream, format, args_copy);
    va_end(args_copy);
}

} // namespace asf_logging_logsdk4c

int asf_clogger_initialize(const char* conf_file)
{
    if (!conf_file)
    {
        return -1;
    }

    if (asf::logging::logsdk::Initializer::DoInitialize(conf_file))
    {
        return 0;
    }
    return -1;
}

int asf_clogger_is_initialized()
{
    return asf::logging::logsdk::Initializer::IsInitialized();
}

int asf_clogger_initialize_with_conf_data(const char* conf_data)
{
    if (!conf_data)
    {
        return -1;
    }

    if (asf::logging::logsdk::Initializer::DoInitializeWithConfData(conf_data))
    {
        return 0;
    }
    return -1;
}

void asf_clogger_shutdown()
{
    asf::logging::logsdk::Initializer::Shutdown();
}

asf_logsdk_loglevel_t asf_clogger_global_flush_level()
{
    return static_cast<asf_logsdk_loglevel_t>(asf::logging::logsdk::Logger::GetGlobalFlushLevel());
}

int asf_clogger_set_global_flush_level(asf_logsdk_loglevel_t level)
{
    if (level >= ASF_LOGSDK_LOGLEVEL_TRACE && level <= ASF_LOGSDK_LOGLEVEL_OFF)
    {
        if (asf::logging::logsdk::Logger::SetGlobalFlushLevel(static_cast<asf::logging::logsdk::LogLevel>(level)))
        {
            return 0;
        }
    }
    return -1;
}

asf_logsdk_loglevel_t asf_clogger_flush_level(const char* logger_name)
{
    if (!logger_name)
    {
        return ASF_LOGSDK_LOGLEVEL_INVALID;
    }
    
    auto logger = asf::logging::logsdk::Logger::GetInstance(logger_name);
    return static_cast<asf_logsdk_loglevel_t>(logger.GetFlushLevel());
}

void asf_clogger_set_flush_level(const char* logger_name, asf_logsdk_loglevel_t level)
{
    if (!logger_name)
    {
        return;
    }

    if (level >= ASF_LOGSDK_LOGLEVEL_TRACE && level <= ASF_LOGSDK_LOGLEVEL_OFF)
    {
        auto logger = asf::logging::logsdk::Logger::GetInstance(logger_name);
        logger.SetFlushLevel(static_cast<asf::logging::logsdk::LogLevel>(level));
    }
}

int asf_clogger_app_dir_path(char* dest, int size, const char* default_app_file_path)
{
    if (!dest || size <= 0)
    {
        return 0;
    }

    std::string path = asf::logging::logsdk::Initializer::GetApplicationDirPath(
        default_app_file_path ? default_app_file_path : "");

    if (path.empty())
    {
        return 0;
    }

    int real_size = std::min(size, static_cast<int>(path.size()));
    if (real_size > 0)
    {
        std::copy_n(path.data(), real_size, dest);
    }
    return real_size;
}

void asf_clogger_log(const char* logger_name, asf_logsdk_loglevel_t level,
    const char* format, ...)
{
    if (!logger_name || !format)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    auto logger = asf::logging::logsdk::Logger::GetInstance(logger_name);
    asf_logging_logsdk4c::logger_log(logger, level, nullptr, format, args);
    va_end(args);
}

void asf_clogger_log_default(asf_logsdk_loglevel_t level, const char* format, ...)
{
    if (!format)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    auto logger = asf::logging::logsdk::Logger::GetDefault();
    asf_logging_logsdk4c::logger_log(logger, level, nullptr, format, args);
    va_end(args);
}

void asf_clogger_log_with_source_loc(const char* logger_name, asf_logsdk_loglevel_t level, const char* file, 
    uint_least32_t line, const char* format, ...)
{
    if (!logger_name || !format)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    auto logger = asf::logging::logsdk::Logger::GetInstance(logger_name);
    asf_logging_logsdk4c::logger_log_with_source_loc(logger, level, nullptr, file, line, format, args);
    va_end(args);
}

void asf_clogger_log_default_with_source_loc(asf_logsdk_loglevel_t level, const char* file, 
    uint_least32_t line, const char* format, ...)
{
    if (!format)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    auto logger = asf::logging::logsdk::Logger::GetDefault();
    asf_logging_logsdk4c::logger_log_with_source_loc(logger, level, nullptr, file, line, format, args);
    va_end(args);
}

void asf_clogger_log_with_tid(const char* logger_name, asf_logsdk_loglevel_t level,
    const char* trace_id, const char* format, ...)
{    
    if (!logger_name || !format)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    auto logger = asf::logging::logsdk::Logger::GetInstance(logger_name);
    asf_logging_logsdk4c::logger_log(logger, level, trace_id, format, args);
    va_end(args);
}

void asf_clogger_log_default_with_tid(asf_logsdk_loglevel_t level,
    const char* trace_id, const char* format, ...)
{    
    if (!format)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    auto logger = asf::logging::logsdk::Logger::GetDefault();
    asf_logging_logsdk4c::logger_log(logger, level, trace_id, format, args);
    va_end(args);
}

void asf_clogger_log_with_tid_and_source_loc(const char* logger_name, asf_logsdk_loglevel_t level, 
    const char* trace_id, const char* file, uint_least32_t line, const char* format, ...)
{
    if (!logger_name || !format)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    auto logger = asf::logging::logsdk::Logger::GetInstance(logger_name);
    asf_logging_logsdk4c::logger_log_with_source_loc(logger, level, trace_id, file, line, format, args);
    va_end(args);
}

void asf_clogger_log_default_with_tid_and_source_loc(asf_logsdk_loglevel_t level, 
    const char* trace_id, const char* file, uint_least32_t line, const char* format, ...)
{
    if (!format)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    auto logger = asf::logging::logsdk::Logger::GetDefault();
    asf_logging_logsdk4c::logger_log_with_source_loc(logger, level, trace_id, file, line, format, args);
    va_end(args);
}

void asf_clogger_flush(const char* logger_name)
{
    if (!logger_name)
    {
        return;
    }

    asf::logging::logsdk::Logger::GetInstance(logger_name).Flush();
}

void asf_clogger_flush_default()
{
    asf::logging::logsdk::Logger::GetDefault().Flush();
}

void asf_clogger_flush_all()
{
    asf::logging::logsdk::Logger::FlushAll();
}