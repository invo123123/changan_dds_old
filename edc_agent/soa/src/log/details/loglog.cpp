#include "asf/logging/logsdk/details/loglog.hpp"

#include <iostream>

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

void LogLog::SetLogPrefix(const std::string& prefix)
{   
    log_prefix_ = prefix;
}   

void LogLog::SetLogWarnPrefix(const std::string& prefix)
{
    log_warn_prefix_ = prefix;
}

void LogLog::SetLogErrorPrefix(const std::string& prefix)
{
    log_error_prefix_ = prefix;
}

LogLog& LogLog::GetInstance()
{
    static LogLog instance;
    return instance;
}

void LogLog::SetEnabled(bool enabled)
{
    enabled_ = enabled;
}

bool LogLog::IsEnabled() const
{
    return enabled_;
}

void LogLog::Debug(const std::string& msg) const
{
    if (enabled_)
    {
        std::cout << log_prefix_ << msg << std::endl;
    }
}

void LogLog::Warn(const std::string& msg) const
{
    if (enabled_)
    {
        std::cerr << log_warn_prefix_ << msg << std::endl;
    }
}

void LogLog::Error(const std::string& msg) const
{
    if (enabled_)
    {
        std::cerr << log_error_prefix_ << msg << std::endl;
    }
}

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf