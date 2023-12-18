#ifndef ASF_LOGGING_LOGSDK_FORMATTER_H
#define ASF_LOGGING_LOGSDK_FORMATTER_H

#include <string>

namespace asf {
namespace logging {
namespace logsdk {

/**
 * \brief The Formatter class used to format arguments as string to support LogStream.
 */
class Formatter
{
public:
    /**
     * \brief Format arguments as string by given format.
     * 
     * The format \a fmt refer to ``std::sprintf()``.
     * 
     * \tparam Args  Template parameter pack, accepts zero or more arguments (non-types, types, or templates).
     * \param fmt Pointer to a '\0'-terminated multibyte string specifying how to interpret the data.
     * \param args   Arguments specifying data to format.
     * 
     * \return std::string The result of formatted string.
     */
    template<typename... Args>
    static std::string FormatString(const char* fmt, Args&&... args);

public:
    /**
     * \brief Construct a Formatter object with given \a format and \a args.
     * 
     * The format refer to ``std::sprintf()``.
     * 
     * \tparam Args  Template parameter pack, accepts zero or more arguments (non-types, types, or templates).
     * \param format Pointer to a '\0'-terminated multibyte string specifying how to interpret the data.
     * \param args   Arguments specifying data to format.
     */
    template<typename... Args>
    Formatter(const char* format, Args&&...args)
        : data_(FormatString(format, std::forward<Args>(args)...)) { }

    /**
     * \brief Move-constructs a Formatter instance.
     */
    Formatter(Formatter&& rhs) noexcept
        : data_(std::move(rhs.data_)) { }

    /**
     * \brief Move-assigns other to this Formatter instance.
     */
    Formatter& operator=(Formatter&& rhs) noexcept
    {
        Formatter(std::move(rhs)).Swap(*this);
        return *this;
    }

    Formatter() = default;
    Formatter(const Formatter&) = default;
    Formatter& operator=(const Formatter&) = default;

    /**
     * \brief Returns the formatted data stored in the Formatter.
     */
    std::string& GetData()
    {
        return data_;
    }

    /**
     * \brief Returns the constant formatted data stored in the Formatter.
     */
    const std::string& GetData() const
    {
        return data_;
    }

    /**
     * \brief Swaps other formatted data with this formatted data. This operation is very fast and never fails.
     */
    void Swap(Formatter& other) noexcept
    {
        data_.swap(other.data_);
    }

private:
    /**
     * Data stored formatted string.
     */
    std::string data_;
};

template<typename... Args>
std::string Formatter::FormatString(const char* fmt, Args&&... args)
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

} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_FORMATTER_H