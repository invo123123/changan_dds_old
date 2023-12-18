#ifndef ASF_LOGGING_LOGSDK_DETAILS_CONFIG_HPP
#define ASF_LOGGING_LOGSDK_DETAILS_CONFIG_HPP

#include <type_traits>

#define ASF_LOGSDK_LOGLEVEL_NAME_TRACE "TRACE"
#define ASF_LOGSDK_LOGLEVEL_NAME_DEBUG "DEBUG"
#define ASF_LOGSDK_LOGLEVEL_NAME_INFO  "INFO"
#define ASF_LOGSDK_LOGLEVEL_NAME_WARN  "WARN"
#define ASF_LOGSDK_LOGLEVEL_NAME_ERROR "ERROR"
#define ASF_LOGSDK_LOGLEVEL_NAME_FATAL "FATAL"
#define ASF_LOGSDK_LOGLEVEL_NAME_OFF   "OFF"

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

namespace cfg {

/**
 * The maximum length of app id.
 */
static constexpr std::size_t kMaxAppIdLength = 32ull;

/**
 * The maximum length of domain id.
 */
static constexpr std::size_t kMaxDomainIdLength = 32ull;

/**
 * The maximum length of logger name.
 */
static constexpr std::size_t kMaxLoggerNameLength = 128ull;

/**
 * The maximum length of task id.
 */
static constexpr std::size_t kMaxTaskIdLength = 64ull;

/**
 * The max interval in milliseconds, 60 minutes.
 */
static constexpr std::size_t kMaxInterval = 3600ull * 1000ull;

/**
 * The heartbeat interval in milliseconds.
 */
static constexpr int64_t kHeartbeatInterval = 5000ll;

/**
 * The default logger name.
 */
static constexpr const char* kDefaultLoggerName = "default";

/**
 * The log level names.
 */
static constexpr const char* kTraceLogLevelName = ASF_LOGSDK_LOGLEVEL_NAME_TRACE;
static constexpr const char* kDebugLogLevelName = ASF_LOGSDK_LOGLEVEL_NAME_DEBUG;
static constexpr const char* kInfoLogLevelName  = ASF_LOGSDK_LOGLEVEL_NAME_INFO;
static constexpr const char* kWarnLogLevelName  = ASF_LOGSDK_LOGLEVEL_NAME_WARN;
static constexpr const char* kErrorLogLevelName = ASF_LOGSDK_LOGLEVEL_NAME_ERROR;
static constexpr const char* kFatalLogLevelName = ASF_LOGSDK_LOGLEVEL_NAME_FATAL;
static constexpr const char* kOffLogLevelName   = ASF_LOGSDK_LOGLEVEL_NAME_OFF;

/** Fixed log pattern (content/payload) */
static constexpr const char* kLogPattern = "%v";

/**
 * The default app id.
 */
static constexpr const char* KDefaultAppId = "unknown";

/**
 * The default domain id.
 */
static constexpr const char* KDefaultDomainId = "unknown";

/**
 * The app dir identifier used to tag the application path in configuration file.
 */
static constexpr const char* kAppDirIdentifier = "${AppDir}";

/**
 * The app dir identifier used to tag the application id in configuration file.
 */
static constexpr const char* kAppIdIdentifier = "${AppId}";

/**
 * The prefix for log file dir. eg. "/log/"
 */
static constexpr const char* kLogFileDirPrefix = "";

/**
 * The default dir to save log file.
 */
static constexpr const char* kDefaultLogFileDir = "log";

/**
 * The default maximum size of log file, in KB.
 */
static constexpr std::size_t kDefaultLogFileMaxSize = 20480ull;

/**
 * The minimum size of log file, in KB. (1MB)
 */
static constexpr std::size_t kMinSizeOfLogFile = 1024ull;

/**
 * The maximum size of log file, in KB. (2GB)
 */
static constexpr std::size_t kMaxSizeOfLogFile = 1024 * 1024 * 2ull;

/**
 * The default maximum files to rotate,
 */
static constexpr std::size_t kDefaultMaxLogFiles = 5;

/**
 * The limit of max files.
 */
static constexpr std::size_t kMaxLogFilesLimit = 1000;

/**
 * The default source file name of log.
 */
static constexpr const char* kDefaultSourceFileName = "file";

/**
 * The default source file line of log.
 */
static constexpr int kDefaultSourceFileLine = 0;

} // namespace cfg
} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_DETAILS_CONFIG_HPP