#include "asf/logging/logsdk/details/log_level_helper.hpp"

#include <atomic>

#include "asf/logging/logsdk/details/config.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

namespace {

constexpr const spdlog::string_view_t kLogLevelStrings[] = {
    spdlog::string_view_t(cfg::kTraceLogLevelName, 5),  // 0
    spdlog::string_view_t(cfg::kDebugLogLevelName, 5),  // 1
    spdlog::string_view_t(cfg::kInfoLogLevelName, 4),   // 2
    spdlog::string_view_t(cfg::kWarnLogLevelName, 4),   // 3
    spdlog::string_view_t(cfg::kErrorLogLevelName, 5),  // 4
    spdlog::string_view_t(cfg::kFatalLogLevelName, 5),  // 5
    spdlog::string_view_t(cfg::kOffLogLevelName, 3)     // 6
};

constexpr const std::size_t kLogLevelStringLen = std::extent<decltype(kLogLevelStrings)>::value;

} // namespace

bool LogLevelHelper::IsLevelStringValid(const std::string& level_string)
{
    spdlog::string_view_t level_string_view(level_string.data(), level_string.size());
    const spdlog::string_view_t* end = kLogLevelStrings + kLogLevelStringLen;
    return end != std::find(kLogLevelStrings, end, level_string_view);
}

spdlog::level::level_enum LogLevelHelper::GetDefaultLogLevel()
{
    return spdlog::level::level_enum::err;
}

const char* LogLevelHelper::GetDefaultLogLevelString()
{
    return LogLevelToStringView(GetDefaultLogLevel()).data();
}

spdlog::string_view_t LogLevelHelper::LogLevelToStringView(LogLevel level)
{
    return kLogLevelStrings[static_cast<int>(level)];
}

spdlog::string_view_t LogLevelHelper::LogLevelToStringView(spdlog::level::level_enum level)
{
    return kLogLevelStrings[static_cast<int>(level)];
}

std::string LogLevelHelper::LogLevelToString(LogLevel level)
{
    const auto view = LogLevelToStringView(level);
    return std::string(view.data(), view.size());
}

std::string LogLevelHelper::LogLevelToString(spdlog::level::level_enum level)
{
    const auto view = LogLevelToStringView(level);
    return std::string(view.data(), view.size());
}

LogLevel LogLevelHelper::StringToLogLevel(const std::string& level_string, LogLevel default_level)
{
    spdlog::string_view_t level_string_view(level_string.data(), level_string.size());
    for (std::size_t i = 0; i < kLogLevelStringLen; ++i)
    {
        if (kLogLevelStrings[i] == level_string_view)
        {
            return static_cast<LogLevel>(i);
        }
    }
    return default_level;
}

spdlog::level::level_enum LogLevelHelper::StringToSpdLogLevel(
    const std::string& level_string, spdlog::level::level_enum default_level)
{
    if (!IsLevelStringValid(level_string))
    {
        return default_level;
    }
    else
    {
        return CastLogLevel(StringToLogLevel(level_string));
    }
}

LogLevel LogLevelHelper::CastLogLevel(spdlog::level::level_enum level)
{
    switch (level)
    {
    case spdlog::level::level_enum::trace:
        return LogLevel::kTrace;
    case spdlog::level::level_enum::debug:
        return LogLevel::kDebug;
    case spdlog::level::level_enum::info:
        return LogLevel::kInfo;
    case spdlog::level::level_enum::warn:
        return LogLevel::kWarn;
    case spdlog::level::level_enum::err:
        return LogLevel::kError;
    case spdlog::level::level_enum::critical:
        return LogLevel::kFatal;
    default:
        break;
    }
    return LogLevel::kOff;
}

spdlog::level::level_enum LogLevelHelper::CastLogLevel(LogLevel level)
{
    switch (level)
    {
    case LogLevel::kTrace:
        return spdlog::level::level_enum::trace;
    case LogLevel::kDebug:
        return spdlog::level::level_enum::debug;
    case LogLevel::kInfo:
        return spdlog::level::level_enum::info;
    case LogLevel::kWarn:
        return spdlog::level::level_enum::warn;
    case LogLevel::kError:
        return spdlog::level::level_enum::err;
    case LogLevel::kFatal:
        return spdlog::level::level_enum::critical;
    default:
        break;
    }
    return spdlog::level::level_enum::off;
}

spdlog::string_view_t LogLevelHelper::LogLevelToStringViewForOutput(spdlog::level::level_enum level)
{
    switch (level)
    {
    case spdlog::level::level_enum::trace:
        return spdlog::string_view_t(ASF_LOGSDK_LOGLEVEL_NAME_TRACE, 5);
    case spdlog::level::level_enum::debug:
        return spdlog::string_view_t(ASF_LOGSDK_LOGLEVEL_NAME_DEBUG, 5);
    case spdlog::level::level_enum::info:
        return spdlog::string_view_t(ASF_LOGSDK_LOGLEVEL_NAME_INFO " ", 5);
    case spdlog::level::level_enum::warn:
        return spdlog::string_view_t(ASF_LOGSDK_LOGLEVEL_NAME_WARN " ", 5);
    case spdlog::level::level_enum::err:
        return spdlog::string_view_t(ASF_LOGSDK_LOGLEVEL_NAME_ERROR, 5);
    case spdlog::level::level_enum::critical:
        return spdlog::string_view_t(ASF_LOGSDK_LOGLEVEL_NAME_FATAL, 5);
    default:
        break;
    }
    return spdlog::string_view_t(ASF_LOGSDK_LOGLEVEL_NAME_OFF "  ", 5);
}

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf