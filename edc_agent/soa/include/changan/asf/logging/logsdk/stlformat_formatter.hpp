#ifndef ASF_LOGGING_LOGSDK_STLFORMAT_FORMATTER_HPP
#define ASF_LOGGING_LOGSDK_STLFORMAT_FORMATTER_HPP

#include <spdlog/common.h>

namespace asf {
namespace logging {
namespace logsdk {

/**
 * \brief The StlFormatFormatter class used to format arguments (std::format style, since C++20) 
 *        as string to support LogStream.
 * \since v1.3.2
 */
class StlFormatFormatter
{
public:
    /**
     * \brief Format args according to the format string \a fmt, and return the result as a string.
     * 
     * The format \a fmt refer to ``std::format`` (Since C++20).
     * 
     * \tparam Args Template parameter pack, accepts zero or more arguments (non-types, types, or templates).
     * \param fmt   string view representing the format string.
     * \param args  arguments to be formatted.
     * 
     * \return A spdlog::memory_buf_t object holding the formatted result. 
     */
    template<typename... Args>
    static spdlog::memory_buf_t VFormatString(spdlog::string_view_t fmt, Args&&... args);

    /**
     * \brief Format \a args according to the format string \a fmt, and return the result as a string.
     * 
     * The format \a fmt refer to ``std::format`` (Since C++20).
     * 
     * \tparam Args  Template parameter pack, accepts zero or more arguments (non-types, types, or templates).
     * \param fmt    Parameter whose initialization is valid only if the argument is convertible to spdlog::string_view_t,
     *               and the result of conversion is a constant expression and a valid format string for \a Args.
     * \param args   Arguments to be formatted.
     * 
     * \return A spdlog::memory_buf_t object holding the formatted result. 
     */
    template<typename... Args>
    static spdlog::memory_buf_t FormatString(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        return StlFormatFormatter::VFormatString(spdlog::string_view_t(fmt), std::forward<Args>(args)...);
    }

    /**
     * \brief Format \a t to string.
     * 
     * This function participates in overload resolution only if the type \a T can convert to format_string.
     */
    template<typename T, 
             typename std::enable_if<!spdlog::is_convertible_to_any_format_string<const T &>::value, int>::type = 0>
    static spdlog::memory_buf_t FormatT(const T& t)
    {
        return StlFormatFormatter::VFormatString("{}", t);
    }

public:
    /**
     * \brief Construct a new StlFormatFormatter object.
     * 
     * \see FormatString()
     */
    template<typename... Args>
    StlFormatFormatter(spdlog::format_string_t<Args...> fmt, Args&&...args)
        : data_(FormatString(fmt, std::forward<Args>(args)...))
        , data_view_(data_.data(), data_.size())
    { }

    /**
     * \brief Construct a new StlFormatFormatter object.
     * 
     * This overload participates in overload resolution only if the type \a T can convert to format_string.
     * 
     * \see FormatT()
     */
    template<typename T,
             typename std::enable_if<!spdlog::is_convertible_to_any_format_string<const T &>::value, int>::type = 0>
    explicit StlFormatFormatter(const T& t)
        : data_(FormatT(t))
        , data_view_(data_.data(), data_.size())
    { }

    explicit StlFormatFormatter(spdlog::string_view_t sv)
        : data_view_(sv)
    { }

    /**
     * \brief Move-constructs a StlFormatFormatter instance.
     */
    StlFormatFormatter(StlFormatFormatter&& rhs) noexcept
        : data_(std::move(rhs.data_))
        , data_view_(std::move(rhs.data_view_))
    { }

    /**
     * \brief Move-assigns other to this StlFormatFormatter instance.
     */
    StlFormatFormatter& operator=(StlFormatFormatter&& rhs) noexcept
    {
        StlFormatFormatter(std::move(rhs)).Swap(*this);
        return *this;
    }

    StlFormatFormatter() = default;

    /** 
     * Because spdlog::memory_buf_t has a deleted copy assignment operator.
     */
    StlFormatFormatter(const StlFormatFormatter&) = delete;
    
    /**
     * Because spdlog::memory_buf_t has a deleted copy constructor.
     */
    StlFormatFormatter& operator=(const StlFormatFormatter&) = delete;

    /**
     * \brief Returns the constant formatted data stored in this StlFormatFormatter.
     */
    const spdlog::string_view_t& GetData() const
    {
        return data_view_;
    }

    /**
     * \brief Swaps other formatted data with this formatted data. This operation is very fast and never fails.
     */
    void Swap(StlFormatFormatter& other) noexcept
    {
        std::swap(data_, other.data_);
        std::swap(data_view_, other.data_view_);
    }

private:
    /**
     * Data stored formatted string.
     */
    spdlog::memory_buf_t data_;
    spdlog::string_view_t data_view_;
};

template<typename... Args>
spdlog::memory_buf_t StlFormatFormatter::VFormatString(spdlog::string_view_t fmt, Args&&... args)
{
#ifdef SPDLOG_USE_STD_FORMAT
    spdlog::memory_buf_t buf = std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...));
#else
    spdlog::memory_buf_t buf;
    fmt::detail::vformat_to(buf, fmt, fmt::make_format_args(std::forward<Args>(args)...));
#endif
    return buf;
}

} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_STLFORMAT_FORMATTER_HPP