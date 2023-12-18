#ifndef ASF_LOGGING_LOGSDK_DETAILS_LOG_LEVEL_HELPER_HPP
#define ASF_LOGGING_LOGSDK_DETAILS_LOG_LEVEL_HELPER_HPP

#include <spdlog/common.h>

#include <asf/logging/logsdk/common.h>

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

class LogLevelHelper
{
public:
    /**
     * \brief Returns \c true if the \a level_string is valid, otherwise returns false.
     */
    static bool IsLevelStringValid(const std::string& level_string);

    /**
     * \brief Returns the default log level.
     */
    static spdlog::level::level_enum GetDefaultLogLevel();

    /**
     * \brief Returns the default log level string.
     */
    static const char* GetDefaultLogLevelString();

    /**
     * \brief Cast asf_logsdk LogLevel value to spdlog log level value.
     */
    static spdlog::level::level_enum CastLogLevel(LogLevel level);

    /**
     * \brief Cast spdlog log level LogLevel value to asf_logsdk log level value.
     */
    static LogLevel CastLogLevel(spdlog::level::level_enum level);

    /**
     * \brief Returns string view of asf_logsdk log level value.
     */
    static spdlog::string_view_t LogLevelToStringView(LogLevel level);

    /**
     * \brief Returns string view of spdlog log level value.
     */
    static spdlog::string_view_t LogLevelToStringView(spdlog::level::level_enum level);

    /**
     * \brief Returns string of asf_logsdk log level value.
     */
    static std::string LogLevelToString(LogLevel level);

    /**
     * \brief Returns string of spdlog log level value.
     */
    static std::string LogLevelToString(spdlog::level::level_enum level);

    /**
     * \brief Cast log level string to asf_logsdk log level value.
     * 
     * If \a level_string is invalid, returns \a default_level.
     */
    static LogLevel StringToLogLevel(const std::string& level_string, LogLevel default_level = LogLevel::kOff);

    /**
     * \brief Cast log level string to spdlog log level value.
     * 
     * If \a level_string is invalid, returns \a default_level.
     */
    static spdlog::level::level_enum StringToSpdLogLevel(const std::string& level_string, 
        spdlog::level::level_enum default_level = spdlog::level::level_enum::off);

    /**
     * \brief Returns string view of spdlog log level value for output.
     */
    static spdlog::string_view_t LogLevelToStringViewForOutput(spdlog::level::level_enum level);
};

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_DETAILS_LOG_LEVEL_HELPER_HPP