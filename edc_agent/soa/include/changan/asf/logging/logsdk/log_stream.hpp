#ifndef ASF_LOGGING_LOGSDK_LOG_STREAM_HPP
#define ASF_LOGGING_LOGSDK_LOG_STREAM_HPP

#include <string>
#include <memory>

#include <asf/logging/logsdk/common.h>
#include <asf/logging/logsdk/formatter.hpp>
#include <asf/logging/logsdk/stlformat_formatter.hpp>
#include <asf/logging/logsdk/string_view.hpp>

namespace asf {
namespace logging {
namespace logsdk {

// forward declaration.
namespace logcore {
class LoggerImpl;
} // namespace logcore

class LogStreamPrivate;

/**
 * \brief The LogStream class provides a convenient stream-like interface for recording log.
 * 
 * Supports for custom data type.
 * e.g.
 * \code
 *  struct Point
 *  {
 *      int x;
 *      int y;
 *  };
 *  LogStream& operator<<(LogStream& stream, const Point& pt)
 *  {
 *      stream << "Point(" << pt.x << "," << pt.y << ")";
 *      return stream;
 *  }
 * \endcode
 */
class LogStream
{
public:
    /**
     * \brief Construct a new LogStream object with given LoggerImpl \a impl and LogLevel \a log_level.
     */
    LogStream(const std::shared_ptr<logcore::LoggerImpl>& impl, LogLevel log_level, const std::string& trace_id);
    
    /**
     * \brief Move-constructs a LogStream instance.
     */
    LogStream(LogStream&& rhs) noexcept;

    /**
     * \brief Destructor.
     */
    ~LogStream();

    /**
     * \brief Returns the log level of this LogStream.
     */
    LogLevel GetLogLevel() const;

    /**
     * \brief Writes the boolean value \a t to the stream.
     * 
     * If ``t==true``, writes string "true", otherwise writes string "false".
     */
    LogStream& operator<<(bool t);

    /**
     * \brief Writes the character \a t to the stream. 
     */
    LogStream& operator<<(char t);
    LogStream& operator<<(signed char t);
    LogStream& operator<<(unsigned char t);

    /**
     * \brief Writes the integer \a t to the stream. 
     */
    LogStream& operator<<(short t);
    LogStream& operator<<(unsigned short t);
    LogStream& operator<<(int t);
    LogStream& operator<<(unsigned int t);
    LogStream& operator<<(long t);
    LogStream& operator<<(unsigned long t);
    LogStream& operator<<(long long t);
    LogStream& operator<<(unsigned long long t);

    /**
     * \brief Writes the floating point number \a t to the stream. 
     */
    LogStream& operator<<(float t);
    LogStream& operator<<(double t);
    LogStream& operator<<(long double t);

    /**
     * \brief Writes the '\0'-terminated string \a t to the stream. 
     */
    LogStream& operator<<(const char* t);

    /**
     * \brief Writes the string \a t to the stream. 
     */
    LogStream& operator<<(const std::string& t);

    /**
     * \brief Same to write the string "(nullptr)" to the stream.
     */
    LogStream& operator<<(std::nullptr_t);

    /**
     * \brief Writes the address of pointer \a t (in hex form) to the stream.
     * 
     * if ``t==0x00``, same to write string "(nil)".
     */
    LogStream& operator<<(const void* const t);

    /**
     * \brief Writes the result of \a formatter to the stream.
     * 
     * e.g.
     * \code
     *   LogStream stream(...);
     *   stream << Formatter("This a %s message. index = %d", "trace", 0);
     * \endcode
     */
    LogStream& operator<<(const Formatter& formatter);

    /**
     * \brief Writes the result of C++20 style \a formatter to the stream. See std::format since C++20.
     * 
     * e.g.
     * \code
     *   LogStream stream(...);
     *   stream << StlFormatFormatter("{} {}", "trace", 0);
     * \endcode
     */
    LogStream& operator<<(const StlFormatFormatter& formatter);

    /**
     * \brief Writes the string view \a sv to the stream.
     */
    LogStream& operator<<(const StringView& sv);

private:
    /**
     * \brief Disbale copy constructor.
     */
    LogStream(const LogStream&) = delete;

    /**
     * \brief Disbale copy assignment.
     */
    LogStream& operator=(const LogStream&) = delete;

    /**
     * \brief Disbale move assignment.
     */
    LogStream& operator=(LogStream&&) = delete;

private:
    std::unique_ptr<LogStreamPrivate> pri_;
};

/**
 * \brief This function is the key to realize the input of rvalue_reference LogStream.
 */
template<typename T>
LogStream& operator<<(LogStream&& stream, T&& value) noexcept
{
    return (stream << std::forward<T>(value));
}

} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_LOG_STREAM_HPP