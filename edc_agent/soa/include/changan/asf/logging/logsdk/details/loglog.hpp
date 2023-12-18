#ifndef ASF_LOGGING_LOGSDK_DETAILS_LOG_LOG_HPP
#define ASF_LOGGING_LOGSDK_DETAILS_LOG_LOG_HPP

#include <string>
#include <atomic>
#include <iostream>

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

/**
 * \brief Log interface for internal logging.
 */
class LogLog
{
public:
    template<typename... Args>
    static std::string FormatString(const char* fmt, Args&&... args);

public:
    static LogLog& GetInstance();

    /**
     * \brief Enable log or not.
     */
    void SetEnabled(bool enabled);

    /**
     * \brief Returns true if is enabled, otherwise rteurns false.
     */
    bool IsEnabled() const;

    /**
     * \brief This method is used to output asf_logsdk internal debug statements.
     * 
     * Output goes to <code>std::cout</code>.
     */
    void Debug(const std::string& msg) const;

    template<typename... Args>
    void Debug(const char* fmt, Args&&...args) const;

    /**
     * This method is used to output asf_logsdk internal warning statements. 
     * 
     * Output goes to <code>std::cerr</code>.
     */
    void Warn(const std::string& msg) const;

    template<typename... Args>
    void Warn(const char* fmt, Args&&...args) const;

    /**
     * \brief This method is used to output asf_logsdk internal error statements. 
     * 
     * Output goes to <code>std::cerr</code>. 
     * Optionally, this method can throw std::runtime_error exception too.
     */
    void Error(const std::string& msg) const;

    template<typename... Args>
    void Error(const char* fmt, Args&&...args) const;

    void SetLogPrefix(const std::string& prefix);
    void SetLogWarnPrefix(const std::string& prefix);
    void SetLogErrorPrefix(const std::string& prefix);

private:
    LogLog() = default;
    ~LogLog() = default;
    LogLog(const LogLog&) = delete;
    LogLog& operator=(const LogLog&) = delete;

private:
    std::string log_prefix_{"[asf_logsdk]: "};
    std::string log_warn_prefix_{"[asf_logsdk]: [WARN] "};
    std::string log_error_prefix_{"[asf_logsdk]: [ERROR] "};
    /**
     * Enable the internal logging or not
     */
    std::atomic_bool enabled_{ true };
};

template<typename... Args>
void LogLog::Debug(const char* fmt, Args&&...args) const
{
    Debug(FormatString(fmt, std::forward<Args>(args)...));
}

template<typename... Args>
void LogLog::Warn(const char* fmt, Args&&...args) const
{
    Warn(FormatString(fmt, std::forward<Args>(args)...));
}

template<typename... Args>
void LogLog::Error(const char* fmt, Args&&...args) const
{
    Error(FormatString(fmt, std::forward<Args>(args)...));
}

template<typename... Args>
std::string LogLog::FormatString(const char* fmt, Args&&... args)
{
#ifdef __GNUC__
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wformat-security"
#endif // for gcc compiler, ignore
    if (!fmt)
    {
        return std::string();
    }

    if (sizeof...(Args) == 0)
    {
        return std::string(fmt);
    }
    else
    {
        auto size = std::snprintf(nullptr, 0, fmt, args...);
        if (size > 0)
        {
            std::string result(size + 1, '\0');
            std::snprintf(&(result[0]), size + 1, fmt, args...);
            result.resize(size);
            return result;
        }
        return std::string();
    }

#ifdef __GNUC__
#   pragma GCC diagnostic pop
#endif
}

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf

#include <asf/logging/logsdk/details/utils.hpp>

#ifdef ASF_LOGGING_LOGSDK_DEBUG
    #define ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE(msg) \
        const std::string _file = asf::logging::logsdk::details::Utils::ExtractFileName(__FILE__); \
        std::string _msg = _file + ':' + std::to_string(__LINE__) + " " + msg

    #define ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE_ARGS(fmt, ...) \
        const std::string _file = asf::logging::logsdk::details::Utils::ExtractFileName(__FILE__); \
        std::string _msg = _file + ':' + std::to_string(__LINE__) + " " + asf::logging::logsdk::details::LogLog::FormatString(fmt, __VA_ARGS__)
#else
    #define ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE(msg) \
        const std::string& _msg = msg

    #define ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE_ARGS(fmt, ...) \
        std::string _msg = asf::logging::logsdk::details::LogLog::FormatString(fmt, __VA_ARGS__)
#endif

#define ASF_LOGSDK_INTERNAL_DEBUG(msg) \
    do { \
        ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE(msg); \
        asf::logging::logsdk::details::LogLog::GetInstance().Debug(_msg); \
    } while (0)

#define ASF_LOGSDK_INTERNAL_DEBUG_ARGS(fmt, ...) \
    do { \
        ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE_ARGS(fmt, __VA_ARGS__); \
        asf::logging::logsdk::details::LogLog::GetInstance().Debug(_msg); \
    } while (0)

#define ASF_LOGSDK_INTERNAL_WARN(msg) \
    do { \
        ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE(msg); \
        asf::logging::logsdk::details::LogLog::GetInstance().Warn(_msg); \
    } while (0)

#define ASF_LOGSDK_INTERNAL_WARN_ARGS(fmt, ...) \
    do { \
        ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE_ARGS(fmt, __VA_ARGS__); \
        asf::logging::logsdk::details::LogLog::GetInstance().Warn(_msg); \
    } while (0)

#define ASF_LOGSDK_INTERNAL_ERROR(msg) \
    do { \
        ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE(msg); \
        asf::logging::logsdk::details::LogLog::GetInstance().Error(_msg); \
    } while (0)

#define ASF_LOGSDK_INTERNAL_ERROR_ARGS(fmt, ...) \
    do { \
        ASF_LOGSDK_INTERNAL_LOGLOG_MESSAGE_ARGS(fmt, __VA_ARGS__); \
        asf::logging::logsdk::details::LogLog::GetInstance().Error(_msg); \
    } while (0)

#ifdef ASF_LOGGING_LOGSDK_TRACE_CLASS
#   define ASF_LOGSDK_TRACE_ENTRY()    std::cout << "@ [ENTRY] " << __FUNCTION__ << std::endl
#   define ASF_LOGSDK_TRACE_EXIT()     std::cout << "@ [EXIT] " << __FUNCTION__ << std::endl
#else
#   define ASF_LOGSDK_TRACE_ENTRY()
#   define ASF_LOGSDK_TRACE_EXIT()
#endif

#endif // ASF_LOGGING_LOGSDK_DETAILS_LOG_LOG_HPP