#ifndef ASF_LOGGING_LOGSDK_LOGGING_MACRO_HPP
#define ASF_LOGGING_LOGSDK_LOGGING_MACRO_HPP

#include <asf/logging/logsdk/logger.hpp>

namespace asf {
namespace logging {
namespace logsdk {

/**
 * \brief Extract file name from \a file_path.
 * 
 * This function is used to extract file name from <code>__FILE__</code> macro.
 */
static inline StringView ExtractFileName(const StringView& file_path)
{
    auto index = file_path.find_last_of(ASF_LOGGING_LOGSDK_FOLDER_SEPS, 
                                        StringView::npos, 
                                        ASF_LOGGING_LOGSDK_FOLDER_SEPS_COUNT);
    return file_path.substr(index + 1);
}

} // namespace logsdk
} // namespace logging
} // namespace asf

#define ASF_LOGGER_LOG(logger, level) \
        logger.Log(level) << asf::logging::logsdk::ExtractFileName(__FILE__) << ':' << __LINE__ << ' '

#define ASF_LOGGER_TRACE(logger) \
        ASF_LOGGER_LOG(logger, asf::logging::logsdk::LogLevel::kTrace)

#define ASF_LOGGER_DEBUG(logger) \
        ASF_LOGGER_LOG(logger, asf::logging::logsdk::LogLevel::kDebug)

#define ASF_LOGGER_INFO(logger) \
        ASF_LOGGER_LOG(logger, asf::logging::logsdk::LogLevel::kInfo)

#define ASF_LOGGER_WARN(logger) \
        ASF_LOGGER_LOG(logger, asf::logging::logsdk::LogLevel::kWarn)

#define ASF_LOGGER_ERROR(logger) \
        ASF_LOGGER_LOG(logger, asf::logging::logsdk::LogLevel::kError)

#define ASF_LOGGER_FATAL(logger) \
        ASF_LOGGER_LOG(logger, asf::logging::logsdk::LogLevel::kFatal)

// -------------------------------------------------------------------------

#define ASF_LOGGER_LOG_TID(logger, level, trace_id) \
        logger.Log(level, trace_id) << asf::logging::logsdk::ExtractFileName(__FILE__) << ':' << __LINE__ << ' '

#define ASF_LOGGER_TRACE_TID(logger, trace_id) \
        ASF_LOGGER_LOG_TID(logger, asf::logging::logsdk::LogLevel::kTrace, trace_id)

#define ASF_LOGGER_DEBUG_TID(logger, trace_id) \
        ASF_LOGGER_LOG_TID(logger, asf::logging::logsdk::LogLevel::kDebug, trace_id)

#define ASF_LOGGER_INFO_TID(logger, trace_id) \
        ASF_LOGGER_LOG_TID(logger, asf::logging::logsdk::LogLevel::kInfo, trace_id)

#define ASF_LOGGER_WARN_TID(logger, trace_id) \
        ASF_LOGGER_LOG_TID(logger, asf::logging::logsdk::LogLevel::kWarn, trace_id)

#define ASF_LOGGER_ERROR_TID(logger, trace_id) \
        ASF_LOGGER_LOG_TID(logger, asf::logging::logsdk::LogLevel::kError, trace_id)

#define ASF_LOGGER_FATAL_TID(logger, trace_id) \
        ASF_LOGGER_LOG_TID(logger, asf::logging::logsdk::LogLevel::kFatal, trace_id)

// -------------------------------------------------------------------------

#define ASF_LOGGER_LOG_ARGS(logger, level, fmt, ...) logger.LogArgs(level, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_TRACE_ARGS(logger, fmt, ...) \
       ASF_LOGGER_LOG_ARGS(logger, asf::logging::logsdk::LogLevel::kTrace, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_DEBUG_ARGS(logger, fmt, ...) \
       ASF_LOGGER_LOG_ARGS(logger, asf::logging::logsdk::LogLevel::kDebug, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_INFO_ARGS(logger, fmt, ...) \
       ASF_LOGGER_LOG_ARGS(logger, asf::logging::logsdk::LogLevel::kInfo, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_WARN_ARGS(logger, fmt, ...) \
       ASF_LOGGER_LOG_ARGS(logger, asf::logging::logsdk::LogLevel::kWarn, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_ERROR_ARGS(logger, fmt, ...) \
       ASF_LOGGER_LOG_ARGS(logger, asf::logging::logsdk::LogLevel::kError, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_FATAL_ARGS(logger, fmt, ...) \
       ASF_LOGGER_LOG_ARGS(logger, asf::logging::logsdk::LogLevel::kFatal, fmt, ##__VA_ARGS__)

// -------------------------------------------------------------------------

#define ASF_LOGGER_LOG_ARGS_TID(logger, level, trace_id, fmt, ...) \
        ASF_LOGGER_LOG_TID(logger, level, trace_id) << asf::logging::logsdk::Formatter(fmt, ##__VA_ARGS__)

#define ASF_LOGGER_TRACE_ARGS_TID(logger, trace_id, fmt, ...) \
       ASF_LOGGER_LOG_ARGS_TID(logger, asf::logging::logsdk::LogLevel::kTrace, trace_id, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_DEBUG_ARGS_TID(logger, trace_id, fmt, ...) \
       ASF_LOGGER_LOG_ARGS_TID(logger, asf::logging::logsdk::LogLevel::kDebug, trace_id, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_INFO_ARGS_TID(logger, trace_id, fmt, ...) \
       ASF_LOGGER_LOG_ARGS_TID(logger, asf::logging::logsdk::LogLevel::kInfo, trace_id, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_WARN_ARGS_TID(logger, trace_id, fmt, ...) \
       ASF_LOGGER_LOG_ARGS_TID(logger, asf::logging::logsdk::LogLevel::kWarn, trace_id, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_ERROR_ARGS_TID(logger, trace_id, fmt, ...) \
       ASF_LOGGER_LOG_ARGS_TID(logger, asf::logging::logsdk::LogLevel::kError, trace_id, fmt, ##__VA_ARGS__)

#define ASF_LOGGER_FATAL_ARGS_TID(logger, trace_id, fmt, ...) \
       ASF_LOGGER_LOG_ARGS_TID(logger, asf::logging::logsdk::LogLevel::kFatal, trace_id, fmt, ##__VA_ARGS__)

// -------------------------------------------------------------------------

#define ASF_LOGGER_LOG_FMT(logger, level, ...) logger.LogFormat(level, ##__VA_ARGS__)

#define ASF_LOGGER_TRACE_FMT(logger, ...) \
       ASF_LOGGER_LOG_FMT(logger, asf::logging::logsdk::LogLevel::kTrace, ##__VA_ARGS__)

#define ASF_LOGGER_DEBUG_FMT(logger, ...) \
       ASF_LOGGER_LOG_FMT(logger, asf::logging::logsdk::LogLevel::kDebug, ##__VA_ARGS__)

#define ASF_LOGGER_INFO_FMT(logger, ...) \
       ASF_LOGGER_LOG_FMT(logger, asf::logging::logsdk::LogLevel::kInfo, ##__VA_ARGS__)

#define ASF_LOGGER_WARN_FMT(logger, ...) \
       ASF_LOGGER_LOG_FMT(logger, asf::logging::logsdk::LogLevel::kWarn, ##__VA_ARGS__)

#define ASF_LOGGER_ERROR_FMT(logger, ...) \
       ASF_LOGGER_LOG_FMT(logger, asf::logging::logsdk::LogLevel::kError, ##__VA_ARGS__)

#define ASF_LOGGER_FATAL_FMT(logger, ...) \
       ASF_LOGGER_LOG_FMT(logger, asf::logging::logsdk::LogLevel::kFatal, ##__VA_ARGS__)

// -------------------------------------------------------------------------

#define ASF_LOGGER_LOG_FMT_TID(logger, level, trace_id, ...) \
        ASF_LOGGER_LOG_TID(logger, level, trace_id) << asf::logging::logsdk::StlFormatFormatter(__VA_ARGS__)

#define ASF_LOGGER_TRACE_FMT_TID(logger, trace_id, ...) \
       ASF_LOGGER_LOG_FMT_TID(logger, asf::logging::logsdk::LogLevel::kTrace, trace_id, ##__VA_ARGS__)

#define ASF_LOGGER_DEBUG_FMT_TID(logger, trace_id, ...) \
       ASF_LOGGER_LOG_FMT_TID(logger, asf::logging::logsdk::LogLevel::kDebug, trace_id, ##__VA_ARGS__)

#define ASF_LOGGER_INFO_FMT_TID(logger, trace_id, ...) \
       ASF_LOGGER_LOG_FMT_TID(logger, asf::logging::logsdk::LogLevel::kInfo, trace_id, ##__VA_ARGS__)

#define ASF_LOGGER_WARN_FMT_TID(logger, trace_id, ...) \
       ASF_LOGGER_LOG_FMT_TID(logger, asf::logging::logsdk::LogLevel::kWarn, trace_id, ##__VA_ARGS__)

#define ASF_LOGGER_ERROR_FMT_TID(logger, trace_id, ...) \
       ASF_LOGGER_LOG_FMT_TID(logger, asf::logging::logsdk::LogLevel::kError, trace_id, ##__VA_ARGS__)

#define ASF_LOGGER_FATAL_FMT_TID(logger, trace_id, ...) \
       ASF_LOGGER_LOG_FMT_TID(logger, asf::logging::logsdk::LogLevel::kFatal, trace_id, ##__VA_ARGS__)

// -------------------------------------------------------------------------

#define ASF_LOGGING_DEFAULT_LOGGER asf::logging::logsdk::Logger::GetDefault()

#define ASF_LOG_LOG(level) ASF_LOGGER_LOG(ASF_LOGGING_DEFAULT_LOGGER, level)
#define ASF_LOG_TRACE() ASF_LOG_LOG(asf::logging::logsdk::LogLevel::kTrace)
#define ASF_LOG_DEBUG() ASF_LOG_LOG(asf::logging::logsdk::LogLevel::kDebug)
#define ASF_LOG_INFO()  ASF_LOG_LOG(asf::logging::logsdk::LogLevel::kInfo)
#define ASF_LOG_WARN()  ASF_LOG_LOG(asf::logging::logsdk::LogLevel::kWarn)
#define ASF_LOG_ERROR() ASF_LOG_LOG(asf::logging::logsdk::LogLevel::kError)
#define ASF_LOG_FATAL() ASF_LOG_LOG(asf::logging::logsdk::LogLevel::kFatal)

//#define ASF_LOG_ARGS(level, fmt, ...) ASF_LOGGING_DEFAULT_LOGGER.LogArgs(level, fmt, ##__VA_ARGS__)
#define ASF_LOG_ARGS(level, fmt, ...)
#define ASF_LOG_TRACE_ARGS(fmt, ...)  ASF_LOG_ARGS(asf::logging::logsdk::LogLevel::kTrace, fmt, ##__VA_ARGS__)
#define ASF_LOG_DEBUG_ARGS(fmt, ...)  ASF_LOG_ARGS(asf::logging::logsdk::LogLevel::kDebug, fmt, ##__VA_ARGS__)
#define ASF_LOG_INFO_ARGS(fmt, ...)   ASF_LOG_ARGS(asf::logging::logsdk::LogLevel::kInfo, fmt, ##__VA_ARGS__)
#define ASF_LOG_WARN_ARGS(fmt, ...)   ASF_LOG_ARGS(asf::logging::logsdk::LogLevel::kWarn, fmt, ##__VA_ARGS__)
#define ASF_LOG_ERROR_ARGS(fmt, ...)  ASF_LOG_ARGS(asf::logging::logsdk::LogLevel::kError, fmt, ##__VA_ARGS__)
#define ASF_LOG_FATAL_ARGS(fmt, ...)  ASF_LOG_ARGS(asf::logging::logsdk::LogLevel::kFatal, fmt, ##__VA_ARGS__)

#define ASF_LOG_FMT(level, ...) ASF_LOGGING_DEFAULT_LOGGER.LogFormat(level, ##__VA_ARGS__)
#define ASF_LOG_TRACE_FMT(...)  ASF_LOG_FMT(asf::logging::logsdk::LogLevel::kTrace, __VA_ARGS__)
#define ASF_LOG_DEBUG_FMT(...)  ASF_LOG_FMT(asf::logging::logsdk::LogLevel::kDebug, __VA_ARGS__)
#define ASF_LOG_INFO_FMT(...)   ASF_LOG_FMT(asf::logging::logsdk::LogLevel::kInfo,  __VA_ARGS__)
#define ASF_LOG_WARN_FMT(...)   ASF_LOG_FMT(asf::logging::logsdk::LogLevel::kWarn,  __VA_ARGS__)
#define ASF_LOG_ERROR_FMT(...)  ASF_LOG_FMT(asf::logging::logsdk::LogLevel::kError, __VA_ARGS__)
#define ASF_LOG_FATAL_FMT(...)  ASF_LOG_FMT(asf::logging::logsdk::LogLevel::kFatal, __VA_ARGS__)

#endif // ASF_LOGGING_LOGSDK_LOGGING_MACRO_HPP