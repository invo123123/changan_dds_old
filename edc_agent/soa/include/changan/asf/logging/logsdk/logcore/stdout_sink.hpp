#ifndef ASF_LOGGING_LOGSDK_LOGCORE_STDOUT_SINK_HPP
#define ASF_LOGGING_LOGSDK_LOGCORE_STDOUT_SINK_HPP

#include <spdlog/sinks/stdout_sinks.h>

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {
namespace sinks {

// 与 spdlog::sinks::stdout_sink 相比，减少一次format，提升性能
template<typename ConsoleMutex>
class stdout_sink : public spdlog::sinks::stdout_sink<ConsoleMutex>
{
public:
    using mutex_t = typename ConsoleMutex::mutex_t;
    stdout_sink();
    void log(const spdlog::details::log_msg& msg) override;
};

template<typename ConsoleMutex>
SPDLOG_INLINE stdout_sink<ConsoleMutex>::stdout_sink()
{
    //! do not need a formatter
    this->spdlog::sinks::stdout_sink_base<ConsoleMutex>::formatter_.reset();
}

// ------------------------------------------------------------

template<typename ConsoleMutex>
SPDLOG_INLINE void stdout_sink<ConsoleMutex>::log(const spdlog::details::log_msg& msg)
{
#ifdef _WIN32
    if (this->handle_ == INVALID_HANDLE_VALUE)
    {
        return;
    }
    std::lock_guard<mutex_t> lock(this->mutex_);
    ::fflush(this->file_); // flush in case there is something in this file_ already
    auto size = static_cast<DWORD>(msg.payload.size());
    DWORD bytes_written = 0;
    bool ok = ::WriteFile(this->handle_, msg.payload.data(), size, &bytes_written, nullptr) != 0;
    if (!ok)
    {
        spdlog::throw_spdlog_ex("stdout_sink_base: WriteFile() failed. GetLastError(): " + std::to_string(::GetLastError()));
    }
    else
    {
        constexpr char kEol[] = SPDLOG_EOL;
        constexpr size_t kEolLen = std::extent<decltype(kEol)>::value - 1;
        ::WriteFile(this->handle_, kEol, kEolLen, &bytes_written, nullptr);
    }
#else
    std::lock_guard<mutex_t> lock(this->mutex_);
    ::fwrite(msg.payload.data(), sizeof(char), msg.payload.size(), this->file_);
    ::fwrite("\n", sizeof(char), 1, this->file_);
    ::fflush(this->file_); // flush every line to terminal
#endif // WIN32
}

using stdout_sink_mt = stdout_sink<spdlog::details::console_mutex>;
using stdout_sink_st = stdout_sink<spdlog::details::console_nullmutex>;

} // namespace sinks
} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_LOGCORE_STDOUT_SINK_HPP