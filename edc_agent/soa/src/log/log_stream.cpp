#include "asf/logging/logsdk/log_stream.hpp"

#include <cstring>
#include <spdlog/common.h>

#include "asf/logging/logsdk/details/loglog.hpp"
#include "asf/logging/logsdk/details/log_level_helper.hpp"
#include "asf/logging/logsdk/logcore/logger_impl.hpp"

namespace asf {
namespace logging {
namespace logsdk {

class LogStreamPrivate
{
public:
    LogStreamPrivate(const std::shared_ptr<logcore::LoggerImpl>& impl, spdlog::level::level_enum log_level, const std::string& trace_id)
        : impl_(impl)
        , log_level_(log_level)
    {
        impl_->format_log_prefix(log_level_, buff_, trace_id);
    }

    ~LogStreamPrivate()
    {
        impl_->log(log_level_, spdlog::string_view_t(buff_.data(), buff_.size()));
    }

    std::shared_ptr<logcore::LoggerImpl> impl_;
    spdlog::level::level_enum log_level_;
    spdlog::memory_buf_t buff_;
};

// --------------------------------------------------------------

LogStream::LogStream(const std::shared_ptr<logcore::LoggerImpl>& impl, LogLevel log_level, const std::string& trace_id)
{
    if (impl && details::LogLevelHelper::CastLogLevel(log_level) >= impl->level() && log_level != LogLevel::kOff)
    {
        pri_ = std::unique_ptr<LogStreamPrivate>(
            new LogStreamPrivate(impl, details::LogLevelHelper::CastLogLevel(log_level), trace_id));
    }
}

LogStream::LogStream(LogStream&& rhs) noexcept
    : pri_(std::move(rhs.pri_))
{ }

LogStream::~LogStream()
{ }

LogLevel LogStream::GetLogLevel() const
{
    if (pri_)
    {
        return details::LogLevelHelper::CastLogLevel(pri_->log_level_);
    }
    return LogLevel::kOff;
}

LogStream& LogStream::operator<<(bool t)
{
    static constexpr StringView true_value("true", 4);
    static constexpr StringView false_value("false", 5);

    if (pri_)
    {
        pri_->buff_.append(t ? true_value : false_value);
    }
    return *this;
}

LogStream& LogStream::operator<<(char t)
{
    if (pri_)
    {
        pri_->buff_.push_back(t);
    }
    return *this;
}

LogStream& LogStream::operator<<(signed char t)
{
    if (pri_)
    {
        pri_->buff_.push_back(static_cast<char>(t));
    }
    return *this;
}

LogStream& LogStream::operator<<(unsigned char t)
{
    if (pri_)
    {
        pri_->buff_.push_back(static_cast<char>(t));
    }
    return *this;
}

LogStream& LogStream::operator<<(short t)
{
    if (pri_)
    {
        spdlog::details::fmt_helper::append_int(static_cast<int>(t), pri_->buff_);
    }
    return *this;
}

LogStream& LogStream::operator<<(unsigned short t)
{
    if (pri_)
    {
        spdlog::details::fmt_helper::append_int(static_cast<unsigned int>(t), pri_->buff_);
    }
    return *this;
}

LogStream& LogStream::operator<<(int t)
{
    if (pri_)
    {
        spdlog::details::fmt_helper::append_int(t, pri_->buff_);
    }
    return *this;
}

LogStream& LogStream::operator<<(unsigned int t)
{
    if (pri_)
    {
        spdlog::details::fmt_helper::append_int(t, pri_->buff_);
    }
    return *this;
}

LogStream& LogStream::operator<<(long t)
{
    if (pri_)
    {
        spdlog::details::fmt_helper::append_int(t, pri_->buff_);
    }
    return *this;
}

LogStream& LogStream::operator<<(unsigned long t)
{
    if (pri_)
    {
        spdlog::details::fmt_helper::append_int(t, pri_->buff_);
    }
    return *this;
}

LogStream& LogStream::operator<<(long long t)
{
    if (pri_)
    {
        spdlog::details::fmt_helper::append_int(t, pri_->buff_);
    }
    return *this;
}

LogStream& LogStream::operator<<(unsigned long long t)
{
    if (pri_)
    {
        spdlog::details::fmt_helper::append_int(t, pri_->buff_);
    }
    return *this;
}

LogStream& LogStream::operator<<(float t)
{
    if (pri_)
    {
        std::string value = std::to_string(t);
        pri_->buff_.append(value.data(), value.data() + value.size());
    }
    return *this;
}

LogStream& LogStream::operator<<(double t)
{
    if (pri_)
    {
        std::string value = std::to_string(t);
        pri_->buff_.append(value.data(), value.data() + value.size());   
    }
    return *this;
}

LogStream& LogStream::operator<<(long double t)
{
    if (pri_)
    {
        std::string value = std::to_string(t);
        pri_->buff_.append(value.data(), value.data() + value.size());   
    }
    return *this;
}

LogStream& LogStream::operator<<(const char* t)
{
    if (pri_ && t)
    {
        pri_->buff_.append(t, t + std::strlen(t));
    }
    return *this;
}

LogStream& LogStream::operator<<(const std::string& t)
{
    if (pri_)
    {
        pri_->buff_.append(t.data(), t.data() + t.size());   
    }
    return *this;
}

LogStream& LogStream::operator<<(std::nullptr_t)
{
    if (pri_)
    {
        pri_->buff_.append(StringView("(nullptr)", 9));   
    }
    return *this;
}

LogStream& LogStream::operator<<(const void* const t)
{
    if (!pri_)
    {
        return *this;
    }

    if (!t)
    {
        pri_->buff_.append(StringView("(nil)", 5));
    }
    else
    {
        std::uintptr_t addr = reinterpret_cast<std::uintptr_t>(t);
        static const char hex[] = {'0', '1', '2', '3', '4', 
                                   '5', '6', '7', '8', '9', 
                                   'a', 'b', 'c', 'd', 'e', 'f'};
        pri_->buff_.push_back('0');
        pri_->buff_.push_back('x');

        bool valid = false;
        for (int i = (2 * sizeof(t) - 1); i >= 0; --i)
        {
            char ch = hex[(addr >> (4 * i)) & 0xF];
            if (ch != '0')
            {
                valid = true;
            }
            if (valid)
            {
                pri_->buff_.push_back(ch);
            }
        }
    }

    return *this;
}

LogStream& LogStream::operator<<(const Formatter& formatter)
{
    if (pri_)
    {
        (*this) << formatter.GetData();  
    }
    return *this;
}

LogStream& LogStream::operator<<(const StlFormatFormatter& formatter)
{
    if (pri_)
    {
        const auto& data = formatter.GetData();
        pri_->buff_.append(data.data(), data.data() + data.size());   
    }
    return *this;
}

LogStream& LogStream::operator<<(const StringView& sv)
{
    if (pri_)
    {
        pri_->buff_.append(sv.data(), sv.data() + sv.size());
    }
    return *this; 
}

} // namespace logsdk
} // namespace logging
} // namespace asf