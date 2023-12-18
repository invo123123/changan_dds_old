#ifndef ASF_LOGGING_LOGSDK_COMMON_H
#define ASF_LOGGING_LOGSDK_COMMON_H

#include <stddef.h>
#include <stdint.h>

/**
 * \defgroup Common-API asf_logsdk APIs for both C and C++
 * 
 * This module lists the both C and C++ APIs of asf_logsdk.
 * 
 * @{
 */

#define ASF_LOGGING_LOGSDK_AUX_STR(x) #x

#define ASF_LOGGING_LOGSDK_MAKE_VERSION(major, minor, patch) \
    (major * 1000 * 1000u + minor * 1000u + patch)

#define ASF_LOGGING_LOGSDK_MAKE_VERSION_STR(major, minor, patch) \
    ASF_LOGGING_LOGSDK_AUX_STR(major) "." ASF_LOGGING_LOGSDK_AUX_STR(minor) "." ASF_LOGGING_LOGSDK_AUX_STR(patch)

// ASF_LOGGING_LOGSDK_VERSION_X : 
//     the version number of asf_logsdk. It must be kept on a single line. 
//     It is used by CMake build systems to parse version number.

/** The major version of asf_logsdk. */
#define ASF_LOGGING_LOGSDK_VERSION_MAJOR 1
/** The minor version of asf_logsdk. */
#define ASF_LOGGING_LOGSDK_VERSION_MINOR 5
/** The patch version of asf_logsdk. */
#define ASF_LOGGING_LOGSDK_VERSION_PATCH 1

/**
 * \def ASF_LOGGING_LOGSDK_VERSION_SUFFIX
 * 
 * The suffix of current version.
 * - Alpha : An early version that is still in development and undergoing testing.
 * - Beta  : A slightly more stable version that is almost complete, but may still undergo testing and buf fixing.
 * - RC    : Release Candidate. A version that has passed the beta stage and is considered to be ready for release, 
 *           but may have some minor bugs to fix.
 * - GA    : General Availability. A version that has completed all development and testing and is now available 
 *           to the generic public for use. 
 */
#define ASF_LOGGING_LOGSDK_VERSION_SUFFIX "RC2"

/** This is asf_logsdk's version number as unsigned integer. */
#define ASF_LOGGING_LOGSDK_VERSION \
    ASF_LOGGING_LOGSDK_MAKE_VERSION(ASF_LOGGING_LOGSDK_VERSION_MAJOR,\
                                    ASF_LOGGING_LOGSDK_VERSION_MINOR,\
                                    ASF_LOGGING_LOGSDK_VERSION_PATCH)

/** This macro expands to a string that specifies asf_logsdk's version number (for example, "1.0.0"). */
#define ASF_LOGGING_LOGSDK_VERSION_STR \
    ASF_LOGGING_LOGSDK_MAKE_VERSION_STR(ASF_LOGGING_LOGSDK_VERSION_MAJOR, \
                                        ASF_LOGGING_LOGSDK_VERSION_MINOR, \
                                        ASF_LOGGING_LOGSDK_VERSION_PATCH)

/**
 * \def ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE
 * 
 * The format attribute specifies that a function takes printf, scanf, strftime or strfmon style arguments
 * which should be type-checked against a formart string.
 */
#if defined(__GNUC__) && __GNUC__ >= 3
#  define ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(archetype, format_index, first_arg_index) \
     __attribute__ ((format (archetype, format_index, first_arg_index)))
#else
#  define ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(archetype, fmt_index, first_arg_index) /* empty */
#endif

#if defined(__GNUC__) && (__GNUC__ >= 4)
#   define ASF_LOGGING_LOGSDK_ATTR_NODISCARD    __attribute__((warn_unused_result))
#else
#   define ASF_LOGGING_LOGSDK_ATTR_NODISCARD
#endif

/**
 * \def ASF_LOGGING_LOGSDK_FILE
 * 
 * Expands to the name of the current input file, in the form of a C string constant.
 * This is the path by which the preprocessor opened the file, not the short name specified
 * in <code>\#include</code> or as the input file name argument.
 */
#define ASF_LOGGING_LOGSDK_FILE    __FILE__

/**
 * \def ASF_LOGGING_LOGSDK_FUNC_INFO
 * 
 * Expands to a string that describe the function the macro resides in. 
 * How this string looks more specifically is compiler dependent. 
 * With GNU GCC it is typically the function signature.
 * 
 * If this macro is used outside a function, the behavior is undefined.
 */
#if defined (__GNUC__) && (__GNUC__ >= 4)
#   define ASF_LOGGING_LOGSDK_FUNC_INFO     __PRETTY_FUNCTION__
#else
#   define ASF_LOGGING_LOGSDK_FUNC_INFO     __FUNCTION__
#endif

#if defined (__GNUC__) \
    && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8)) \
    && ! defined (__INTEL_COMPILER) \
    && ! defined (__CUDACC__)
#  define ASF_LOGGING_LOGSDK_CALLER_FILE()      __builtin_FILE ()
#  define ASF_LOGGING_LOGSDK_CALLER_LINE()      __builtin_LINE ()
#  define ASF_LOGGING_LOGSDK_CALLER_FUNCTION()  __builtin_FUNCTION ()
#else
#  define ASF_LOGGING_LOGSDK_CALLER_FILE()      (nullptr)
#  define ASF_LOGGING_LOGSDK_CALLER_LINE()      (-1)
#  define ASF_LOGGING_LOGSDK_CALLER_FUNCTION()  (nullptr)
#endif

/**
 * \def ASF_LOGGING_LOGSDK_DEFAULT_FILE
 * 
 * The default source file name for logging.
*/
#define ASF_LOGGING_LOGSDK_DEFAULT_FILE     "file"

/**
 * \def ASF_LOGGING_LOGSDK_FOLDER_SEPS
 * 
 * The ASF_LOGGING_LOGSDK_FOLDER_SEPS macro describes folder separator.
*/
#ifdef _WIN32
#   define ASF_LOGGING_LOGSDK_FOLDER_SEPS "\\/"
#   define ASF_LOGGING_LOGSDK_FOLDER_SEPS_COUNT 2ull
#else
#   define ASF_LOGGING_LOGSDK_FOLDER_SEPS "/"
#   define ASF_LOGGING_LOGSDK_FOLDER_SEPS_COUNT 1ull
#endif

/** @} */

/**
 * \defgroup C-API asf_logsdk APIs for C 
 * 
 * This module lists the C APIs of asf_logsdk.
 * 
 * @{
 */

/**
 * \typedef int asf_logsdk_loglevel_t
 * 
 * Defines the minimum set of priorities recognized by the system,
 * that is {@link #ASF_LOGSDK_LOGLEVEL_TRACE}, {@link #ASF_LOGSDK_LOGLEVEL_DEBUG}, {@link
 * #ASF_LOGSDK_LOGLEVEL_INFO}, {@link #ASF_LOGSDK_LOGLEVEL_WARN}, {@link #ASF_LOGSDK_LOGLEVEL_ERROR},
 * and {@link #ASF_LOGSDK_LOGLEVEL_FATAL}.
 */
typedef int asf_logsdk_loglevel_t;

/** 
 * \def ASF_LOGSDK_LOGLEVEL_TRACE
 * 
 * The <code>ASF_LOGSDK_LOGLEVEL_TRACE</code> LogLevel is usually used to "trace" entry
 * and exiting of methods. 
 */
#define ASF_LOGSDK_LOGLEVEL_TRACE       0

/** 
 * \def ASF_LOGSDK_LOGLEVEL_DEBUG
 * 
 * The <code>ASF_LOGSDK_LOGLEVEL_DEBUG</code> LogLevel used to record more detailed process
 * information than INFO logs to help developers analyze service processer and locate faults.
 * DEBUG logs are not recorded in official versions by default. They are available in debug
 * versions or in official versions with the debug function enabled. 
 */
#define ASF_LOGSDK_LOGLEVEL_DEBUG       1

/** 
 * \def ASF_LOGSDK_LOGLEVEL_INFO
 * 
 * The <code>ASF_LOGSDK_LOGLEVEL_INFO</code> LogLevel used to record key service process nodes
 * and exceptions (for example, no network signal or log failure) that occur during service
 * running. These logs should be recorded by the dominant module in the service to avoid
 * repeated logging conducted by multiple invoked modules or low-level functions.
 */
#define ASF_LOGSDK_LOGLEVEL_INFO        2

/** 
 * \def ASF_LOGSDK_LOGLEVEL_WARN
 * 
 * The <code>ASF_LOGSDK_LOGLEVEL_WARN</code> LogLevel indicates a severe, unexpected fault that
 * has little impact on users and can be rectified by the programs themselves or through simple
 * operations.
 */
#define ASF_LOGSDK_LOGLEVEL_WARN        3

/** 
 * \def ASF_LOGSDK_LOGLEVEL_ERROR
 * 
 * The <code>ASF_LOGSDK_LOGLEVEL_ERROR</code> LogLevel indicates a prohram or functional error
 * that affects the normal running or use of the functionality and can be fixed at a high cost,
 * for example, by resetting data.
 */
#define ASF_LOGSDK_LOGLEVEL_ERROR       4

/** 
 * \def ASF_LOGSDK_LOGLEVEL_FATAL
 * 
 * The <code>ASF_LOGSDK_LOGLEVEL_FATAL</code> LogLevel indicates that a program or functionality
 * is about to crash and the fault cannot be rectified.
 */
#define ASF_LOGSDK_LOGLEVEL_FATAL       5

/**
 * \def ASF_LOGSDK_LOGLEVEL_OFF
 * 
 * The <code>ASF_LOGSDK_LOGLEVEL_OFF</code> LogLevel is used to turn off logging. 
 */
#define ASF_LOGSDK_LOGLEVEL_OFF         6

/**
 * \def ASF_LOGSDK_LOGLEVEL_INVALID
 * 
 * The <code>ASF_LOGSDK_LOGLEVEL_INVALID</code> indicates an invalid level value.
 */
#define ASF_LOGSDK_LOGLEVEL_INVALID     -1

/**
 * \def ASF_LOGSDK_DEFAULT_TRACE_ID
 * 
 * The default trace id for logging.
 */
#define ASF_LOGSDK_DEFAULT_TRACE_ID     "0"

/** @} */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup Common-API
 * @{
 */

/**
 * \brief Returns the asf_logsdk version number as unsigned integer.
 * 
 * \see ASF_LOGGING_LOGSDK_VERSION
 */
unsigned int asf_logsdk_version();

/**
 * \brief Returns the asf_logsdk version number as a string.
 */
const char* asf_logsdk_version_str();

/**
 * \brief Returns the length of app id in asf_logsdk.
 */
size_t asf_logsdk_app_id_length();

/**
 * \brief Get the app id in asf_logsdk.
 * 
 * \param[out] buff buffer to receive app id value, returns a '\0'-terminated multibyte string.
 * \param len  the length of \a buff.
 * \return the real length of app id.
 */
size_t asf_logsdk_app_id(char* buff, size_t len);

/**
 * \brief Returns the length of domain id in asf_logsdk.
 */
size_t asf_logsdk_domain_id_length();

/**
 * \brief Get the domain id in asf_logsdk.
 * 
 * \param[out] buff buffer to receive domain id value, returns a '\0'-terminated multibyte string.
 * \param len  the length of \a buff.
 * \return the real length of domain id.
 */
size_t asf_logsdk_domain_id(char* buff, size_t len);

/**
 * \brief Returns the name of log level. 
 * 
 * If the \a log_level is less than ASF_LOGSDK_LOGLEVEL_TRACE, 
 * or is greater than ASF_LOGSDK_LOGLEVEL_OFF, returns empty string "".
 */
const char* asf_logsdk_loglevel_name(asf_logsdk_loglevel_t level);

/**
 * \brief If \a enable is non-zero, the internal log is enabled; otherwise the internal log is disabled.
 * \since v1.4.1
 */
void asf_logsdk_set_internal_log_enabled(int enable);

/**
 * \brief Returns `1` if asf_logsdk intrenal log is enabled, otherwise returns `0`.
 * \since v1.4.1
 */
int asf_logsdk_is_internal_log_enabled();

/** @} */

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus

/**
 * \defgroup CPP-API asf_logsdk APIs for C++
 * 
 * This module lists the C++ APIs of asf_logsdk.
 * 
 * @{
 */

namespace asf {
namespace logging {
namespace logsdk {

/**
 * \brief log level enumeration for cplusplus.
 */
enum class LogLevel
{
    kTrace    = ASF_LOGSDK_LOGLEVEL_TRACE,
    kDebug    = ASF_LOGSDK_LOGLEVEL_DEBUG,
    kInfo     = ASF_LOGSDK_LOGLEVEL_INFO,
    kWarn     = ASF_LOGSDK_LOGLEVEL_WARN,
    kError    = ASF_LOGSDK_LOGLEVEL_ERROR,
    kFatal    = ASF_LOGSDK_LOGLEVEL_FATAL,
    kOff      = ASF_LOGSDK_LOGLEVEL_OFF
};

/**
 * \brief Returns the name of log level.
 */
const char* GetLogLevelName(LogLevel level);

} // namespace logsdk
} // namespace logging
} // namespace asf

/** @} */

#endif // __cplusplus

#endif // ASF_LOGGING_LOGSDK_COMMON_H
