#ifndef ASF_LOGGING_LOGSDK_LOGGER_HPP
#define ASF_LOGGING_LOGSDK_LOGGER_HPP

#include <asf/logging/logsdk/log_stream.hpp>

namespace asf {
namespace logging {
namespace logsdk {

// forward declaration.
namespace logcore {
class LoggerImpl;
} // namespace logcore

/**
 * \brief The Logger class is a handle for logging and provides a series of interfaces for logging.
 */
class Logger
{
public:
    /**
     * Default value of trace id argument. Reference to {@link #ASF_LOGSDK_DEFAULT_TRACE_ID}.
     */
    static const std::string kDefaultTraceId;

public:
    /**
     * \brief Retrieve a logger with given \a name. 
     * 
     * If the named logger already exists, then the existing instance will be returned. 
     * Otherwise, a new instance is created.
     * 
     * Since the \a name will be used to crate log file, it should be meet the file naming convention.
     * If the \a name contains one of "\/:*?\"<>|&$#", \a name is invalid.
     * If \a name is invalid or empty, the default logger named application-name will be returned.
     */
    static Logger GetInstance(const std::string& name);

    /**
     * \brief Return default logger instance.
     * \since v1.4.2
     * 
     * The default logger name is configured in the configuration.
     * 
     * If asf_logsdk is not initialized, returns an invalid logger.
     */
    static Logger GetDefault();

    /**
     * \brief Returns \c true if the logger named \a name exists, otherwise returns false.
     *
     * \param name The name of the logger to search for.
     */
    static bool IsExists(const std::string& name);

    /**
     * \brief Constructs an invalid logger.
     * \since v1.3.1
     * 
     * \note An invalid logger will not output any log message.
     */
    Logger() noexcept;

    /**
     * \brief Constructs a logger with \a name.
     * \since v1.3.2
     * 
     * \note The SDK must be initialized before construct the logger.
     * \sa GetInstance()
     */
    Logger(const std::string& name);

    /**
     * \brief Constructs a copy of other.
     */
    Logger(const Logger& rhs) noexcept;

    /**
     * \brief Move-constructs a Logger instance.
     */
    Logger(Logger&& rhs) noexcept;

    /**
     * \brief Assigns \a other to this Logger.
     */
    Logger& operator=(const Logger& other) noexcept;

    /**
     * \brief Move-assigns \a other to this Logger instance.
     */
    Logger& operator=(Logger&& other) noexcept;

    /**
     * \brief Destructor.
     */
    virtual ~Logger();

    /**
     * \brief Returns the name of this logger.
     */
    const std::string& GetName() const;

    /**
     * \brief Returns \c true if this logger is valid, otherwise returns \c false.
     * \since v1.4.2
     */
    bool IsValid() const;

    /**
     * \brief Set the file log level for this logger.
     * \since v1.3.2
     * 
     * \sa GetFileLogLevel(), SetConsoleLogLevel(), SetGlobalFileLogLevel()
     */
    void SetFileLogLevel(LogLevel level);

    /**
     * \brief Get this logger's file log level.
     * \since v1.3.2
     * 
     * \sa SetFileLogLevel(), GetGlobalFileLogLevel(), GetConsoleLogLevel()
     */
    LogLevel GetFileLogLevel() const;

    /**
     * \brief Set the global file log level.
     * \since v1.3.2
     * 
     * If the SDK is initialized with a configuration file, the parameters \a level 
     * will be update to the configuration file.
     * 
     * \note This function affect all loggers since v1.5.1
     * 
     * \sa GetGlobalFileLogLevel(), SetFileLogLevel(), SetGlobalConsoleLogLevel()
     */
    static bool SetGlobalFileLogLevel(LogLevel level);

    /**
     * \brief Returns the global file log level of the asf_logsdk.
     * \since v1.3.2
     * 
     * \sa SetGlobalFileLogLevel(), GetFileLogLevel(), GetGlobalConsoleLogLevel()
     */
    static LogLevel GetGlobalFileLogLevel();

    /**
     * \brief Set the console log level for this logger.
     * \since v1.3.2
     * 
     * \sa GetConsoleLogLevel(), SetFileLogLevel(), SetGlobalConsoleLogLevel()
     */
    void SetConsoleLogLevel(LogLevel level);

    /**
     * \brief Get this logger's console log level.
     * \since v1.3.2
     * 
     * \sa SetConsoleLogLevel(), GetGlobalConsoleLogLevel(), SetFileLogLevel()
     */
    LogLevel GetConsoleLogLevel() const;

    /**
     * \brief Set the global console log level.
     * \since v1.3.2
     * 
     * If the SDK is initialized with a configuration file, the parameters \a level 
     * will be update to the configuration file.
     * 
     * \note This function affect all loggers since v1.5.1
     * 
     * \sa GetGlobalConsoleLogLevel(), SetConsoleLogLevel(), SetGlobalFileLogLevel()
     */
    static bool SetGlobalConsoleLogLevel(LogLevel level);

    /**
     * \brief Returns the global file log level of the asf_logsdk.
     * \since v1.3.2
     * 
     * \sa SetGlobalConsoleLogLevel(), GetConsoleLogLevel(), GetGlobalFileLogLevel()
     */
    static LogLevel GetGlobalConsoleLogLevel();

    /**
     * \brief Returns the log level of this logger.
     * \since v1.5.1
     * 
     * \return The minmum log level of all sinks.
     * 
     * \sa GetConsoleLogLevel(), GetFileLogLevel()
     */
    LogLevel GetLogLevel() const;

    /**
     * \brief Flushes the log message to log file immediately.
     * \since v1.2.1
     * 
     * \sa FlushAll()
     */
    void Flush();

    /**
     * \brief Flushes all loggers.
     * \since v1.2.1
     * 
     * \sa Flush()
     */
    static void FlushAll();

    /**
     * \brief Get this logger's flush level.
     * \since v1.2.1
     * 
     * If a log's level is greater than the flush level, then flush immediately after logging.
     * 
     * \sa GetGlobalFlushLevel()
     */
    LogLevel GetFlushLevel() const;

    /**
     * \brief Set the flush level for this logger.
     * \since v1.2.1
     * 
     * \sa SetGlobalFlushLevel()
     */
    void SetFlushLevel(LogLevel level);

    /**
     * \brief Set the global flush level for all loggers. 
     * \since v1.2.1
     * 
     * This function does not change the flush level of logger that has been created.
     * 
     * \sa GetGlobalFlushLevel(), GetFlushLevel()
     */
    static bool SetGlobalFlushLevel(LogLevel level);

    /**
     * \brief Returns the global flush level.
     * \since v1.2.1
     * 
     * If a log's level is greater than the flush level, then flush immediately after logging.
     * 
     * \sa SetGlobalFlushLevel(), SetFlushLevel()
     */
    static LogLevel GetGlobalFlushLevel();

    /**
     * \brief Returns the LogStream instance with given log level and trace id.
     * 
     * If \a trace_id is empty, use default trace id.
     */
    LogStream Log(LogLevel log_level, const std::string& trace_id = kDefaultTraceId) const;

    /**
     * \brief Returns the LogStream instance with \c trace log level and trace id.
     * 
     * If \a trace_id is empty, use default trace id.
     * 
     * \sa Log()
     */
    LogStream Trace(const std::string& trace_id = kDefaultTraceId) const;

    /**
     * \brief Returns the LogStream instance with \c debug log level and trace id.
     * 
     * If \a trace_id is empty, use default trace id.
     * 
     * \sa Log()
     */
    LogStream Debug(const std::string& trace_id = kDefaultTraceId) const;

    /**
     * \brief Returns the LogStream instance with \c info log level and trace id.
     * 
     * If \a trace_id is empty, use default trace id.
     * 
     * \sa Log()
     */
    LogStream Info(const std::string& trace_id = kDefaultTraceId) const;

    /**
     * \brief Returns the LogStream instance with \c warn log level and trace id.
     * 
     * If \a trace_id is empty, use default trace id.
     * 
     * \sa Log()
     */
    LogStream Warn(const std::string& trace_id = kDefaultTraceId) const;

    /**
     * \brief Returns the LogStream instance with \c error log level and trace id.
     * 
     * If \a trace_id is empty, use default trace id.
     * 
     * \sa Log()
     */
    LogStream Error(const std::string& trace_id = kDefaultTraceId) const;

    /**
     * \brief Returns the LogStream instance with \c fatal log level and trace id.
     * 
     * If \a trace_id is empty, use default trace id.
     * 
     * \sa Log()
     */
    LogStream Fatal(const std::string& trace_id = kDefaultTraceId) const;
    
    /**
     * \brief Returns the LogStream instance with given log level and default trace id \ref kDefaultTraceId 
     *        and arguments, arguments will be formatted.
     * 
     * The format \a fmt refer to ``std::sprintf()``.
     * 
     * \code
     *      Logger logger = Logger::GetInstance("default");
     *      logger.LogArgs(LogLevel::kTrace, "%s %d", "This is a trace message, index = ", 10);
     *      logger.LogArgs(LogLevel::kTrace, "This is a trace message, index = ") << 10;
     * \endcode
     * 
     * \tparam Args     Template parameter pack, accepts zero or more arguments (non-types, types, or templates).
     * \param log_level The level of this log.
     * \param fmt       Pointer to a '\0'-terminated multibyte string specifying how to interpret the data.
     * \param args      Arguments specifying data to fmt.
     * 
     * \sa Log()
     */
    template<typename... Args>
    LogStream LogArgs(LogLevel log_level, const char* fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c trace log level and default trace id \ref kDefaultTraceId 
     *        and arguments, arguments will be formatted.
     * 
     * \sa LogArgs()
     */
    template<typename... Args>
    LogStream TraceArgs(const char* fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c debug log level and default trace id \ref kDefaultTraceId 
     *        and arguments, arguments will be formatted.
     * 
     * \sa LogArgs()
     */
    template<typename... Args>
    LogStream DebugArgs(const char* fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c info log level and default trace id \ref kDefaultTraceId 
     *        and arguments, arguments will be formatted.
     * 
     * \sa LogArgs()
     */
    template<typename... Args>
    LogStream InfoArgs(const char* fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c warn log level and default trace id \ref kDefaultTraceId 
     *        and arguments, arguments will be formatted.
     * 
     * \sa LogArgs()
     */
    template<typename... Args>
    LogStream WarnArgs(const char* fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c error log level and default trace id \ref kDefaultTraceId 
     *        and arguments, arguments will be formatted.
     * 
     * \sa LogArgs()
     */
    template<typename... Args>
    LogStream ErrorArgs(const char* fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c fatal log level and default trace id \ref kDefaultTraceId 
     *        and arguments, arguments will be formatted.
     * 
     * \sa LogArgs()
     */
    template<typename... Args>
    LogStream FatalArgs(const char* fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with given log level and arguments, 
     *        arguments will be formatted.
     * \since v1.3.2
     *
     * The format \a fmt refer to ``std::format`` (Since C++20).
     * 
     * \tparam Args     Template parameter pack, accepts zero or more arguments (non-types, types, or templates).
     * \param log_level The level of this log.
     * \param fmt       Parameter whose initialization is valid only if the argument is convertible to spdlog::string_view_t,
     *                  and the result of conversion is a constant expression and a valid format string for \a Args.    
     * \param args      Arguments to be formatted.
     */
    template<typename... Args>
    LogStream LogFormat(LogLevel log_level, spdlog::format_string_t<Args...> fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with given log level and arguments, 
     *        arguments will be formatted.
     * \since v1.3.2 
     * 
     * This overload participates in overload resolution only if the type \a T can convert to format_string.
     * 
     * \tparam T        The type of \a msg.
     * \param log_level The level of this log.
     * \param msg       The log msg.
     */
    template<typename T, 
             typename std::enable_if<!spdlog::is_convertible_to_any_format_string<const T&>::value, int>::type = 0>
    LogStream LogFormat(LogLevel log_level, const T& msg) const;

    /**
     * \brief The realization of LogFormat(log_level, "xxx")
     * \since v1.3.2
     *
     * \param log_level The level of this log.
     * \param msg       The log msg.
     */
    LogStream LogFormat(LogLevel log_level, StringView msg) const;

    /**
     * \brief Returns the LogStream instance with \c trace log level and arguments, arguments will be formatted.
     * \since v1.3.2
     * 
     * \sa LogFormat()
     */
    template<typename... Args>
    LogStream TraceFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c debug log level and arguments, arguments will be formatted.
     * \since v1.3.2
     * 
     * \sa LogFormat()
     */
    template<typename... Args>
    LogStream DebugFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c info log level and arguments, arguments will be formatted.
     * \since v1.3.2
     * 
     * \sa LogFormat()
     */
    template<typename... Args>
    LogStream InfoFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c warn log level and arguments, arguments will be formatted.
     * \since v1.3.2
     * 
     * \sa LogFormat()
     */
    template<typename... Args>
    LogStream WarnFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c error log level and arguments, arguments will be formatted.
     * \since v1.3.2
     * 
     * \sa LogFormat()
     */
    template<typename... Args>
    LogStream ErrorFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const;

    /**
     * \brief Returns the LogStream instance with \c fatal log level and arguments, arguments will be formatted.
     * \since v1.3.2
     * 
     * \sa LogFormat()
     */
    template<typename... Args>
    LogStream FatalFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const;

    /**
     * \brief Append a sink ptr to this logger.
     * 
     * \note This function is not thread safe, just call when the logger is not logging.
     *       Recommend to call when construct the logger for the first time.
     * 
     * \since v1.3.2
     */
    void AppendSink(spdlog::sink_ptr sink);

protected:
    /**
     * This constructor created a new <code>Logger</code> instance with a pointer to a Logger implementation.
     *
     * \param pri A pointer to the Logger implementation, cannot be NULL.
     */
    Logger(const std::shared_ptr<logcore::LoggerImpl>& pri);

    /**
     * Swaps logger \a other with this logger. This operation is very fast and never fails.
     */
    void Swap(Logger& other) noexcept;

protected:
    std::shared_ptr<logcore::LoggerImpl> impl_;
};

/* ---------------------------------- LogArgs template implementation ---------------------------------- */

template<typename... Args>
LogStream Logger::LogArgs(LogLevel log_level, const char* fmt, Args&&... args) const
{
    if (log_level < this->GetLogLevel())
    {
        return LogStream(nullptr, log_level, "");
    }
    LogStream stream(Log(log_level));
    stream << Formatter::FormatString(fmt, std::forward<Args>(args)...);
    return stream;
}

template<typename... Args>
LogStream Logger::TraceArgs(const char* fmt, Args&&... args) const
{
    return LogArgs(LogLevel::kTrace, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::DebugArgs(const char* fmt, Args&&... args) const
{
    return LogArgs(LogLevel::kDebug, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::InfoArgs(const char* fmt, Args&&... args) const
{
    return LogArgs(LogLevel::kInfo, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::WarnArgs(const char* fmt, Args&&... args) const
{
    return LogArgs(LogLevel::kWarn, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::ErrorArgs(const char* fmt, Args&&... args) const
{
    return LogArgs(LogLevel::kError, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::FatalArgs(const char* fmt, Args&&... args) const
{
    return LogArgs(LogLevel::kFatal, fmt, std::forward<Args>(args)...);
}

/* ---------------------------------- LogFormat template implementation ---------------------------------- */

template<typename... Args>
LogStream Logger::LogFormat(LogLevel log_level, 
                            spdlog::format_string_t<Args...> fmt, Args&&... args) const
{
    if (log_level < this->GetLogLevel())
    {
        return LogStream(nullptr, log_level, "");
    }
    LogStream stream(Log(log_level));
    stream << StlFormatFormatter(fmt, std::forward<Args>(args)...);
    return stream;
}

template<typename T, typename std::enable_if<!spdlog::is_convertible_to_any_format_string<const T&>::value, int>::type>
LogStream Logger::LogFormat(LogLevel log_level, const T& msg) const
{
    if (log_level < this->GetLogLevel())
    {
        return LogStream(nullptr, log_level, "");
    }
    LogStream stream(Log(log_level));
    stream << StlFormatFormatter(msg);
    return stream;
}

template<typename... Args>
LogStream Logger::TraceFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const
{
    return LogFormat(LogLevel::kTrace, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::DebugFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const
{
    return LogFormat(LogLevel::kDebug, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::InfoFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const
{
    return LogFormat(LogLevel::kInfo, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::WarnFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const
{
    return LogFormat(LogLevel::kWarn, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::ErrorFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const
{
    return LogFormat(LogLevel::kError, fmt, std::forward<Args>(args)...);
}

template<typename... Args>
LogStream Logger::FatalFormat(spdlog::format_string_t<Args...> fmt, Args&&... args) const
{
    return LogFormat(LogLevel::kFatal, fmt, std::forward<Args>(args)...);
}

} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_LOGGER_HPP