#ifndef ASF_LOGGING_LOGSDK_LOGCORE_SIZE_FILE_SINK_HPP
#define ASF_LOGGING_LOGSDK_LOGCORE_SIZE_FILE_SINK_HPP

#include <chrono>

#include <spdlog/details/os.h>
#include <spdlog/details/null_mutex.h>
#include <spdlog/details/file_helper.h>
#include <spdlog/sinks/base_sink.h>

#include "asf/logging/logsdk/details/utils.hpp"
#include "asf/logging/logsdk/details/dir.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {
namespace sinks {

/**
 * The default file suffix of log file.
 */
static constexpr const char kLogFileSuffix[] = ".log";
static constexpr std::size_t kLogFileSuffixLen = std::extent<decltype(kLogFileSuffix)>::value - 1;

using filename_t = spdlog::filename_t;

template<typename Mutex>
class size_file_sink : public spdlog::sinks::base_sink<Mutex>
{
public:
    size_file_sink(const filename_t& log_dir, const filename_t& base_file_name, std::size_t max_size, 
        const std::function<void(filename_t&&, const filename_t&)>& after_open,
        const std::function<void(const filename_t&, const filename_t&)>& last_file_closed);
    ~size_file_sink() override;

    filename_t filename();

protected:
    filename_t calc_filename();

protected:
    void rotate_();
    void sink_it_(const spdlog::details::log_msg& msg) override;
    void flush_() override;
    void set_pattern_(const std::string&) override { }
    void set_formatter_(std::unique_ptr<spdlog::formatter>) override { }

private:
    filename_t log_dir_;
    filename_t base_file_name_;
    std::size_t max_size_;
    std::size_t current_size_;
    std::unique_ptr<spdlog::details::file_helper> file_helper_;
    std::FILE* file_stream_{ nullptr };
    std::function<void(filename_t&&, const filename_t&)> after_open_;
    std::function<void(const filename_t&, const filename_t&)> last_file_closed_;
};

// -------------------------------------------------------------------------

template<typename Mutex>
SPDLOG_INLINE size_file_sink<Mutex>::size_file_sink(const filename_t& log_dir, 
    const filename_t& base_file_name, std::size_t max_size,
    const std::function<void(filename_t&&, const filename_t&)>& after_open,
    const std::function<void(const filename_t&, const filename_t&)>& last_file_closed)
    : log_dir_(log_dir)
    , base_file_name_(base_file_name)
    , max_size_(max_size)
    , current_size_(0)
    , after_open_(after_open)
    , last_file_closed_(last_file_closed)
{
    if (max_size == 0)
    {
        spdlog::throw_spdlog_ex("rotating sink constructor: max_size arg cannot be zero");
    }

    // cancel formatter
    spdlog::sinks::base_sink<Mutex>::formatter_.reset();

    // set file event handles
    spdlog::file_event_handlers file_event_handle;
    file_event_handle.after_open = [this](const spdlog::filename_t&, std::FILE* file_stream) {
        file_stream_ = file_stream;
    };
    file_event_handle.before_close = [this](const spdlog::filename_t&, std::FILE*) {
        file_stream_ = nullptr;
    };
    file_helper_ = std::unique_ptr<spdlog::details::file_helper>(new spdlog::details::file_helper(file_event_handle));

    std::vector<std::string> file_name_list = details::dir::ListFileNames(log_dir, false, 
        [&](const std::string& file_name) -> bool {
            return details::Utils::IsLogFileMatchLogger(file_name, base_file_name);
    }, nullptr);
    
    if (!file_name_list.empty())
    {
        std::sort(file_name_list.begin(), file_name_list.end());
        std::string& last_log_file = file_name_list.back();
        // log suffix is ".log"?
        if (details::Utils::IsStringEndsWith(last_log_file, kLogFileSuffix))
        {
            try
            {
                file_helper_->open(log_dir + '/' + last_log_file, false);
                current_size_ = file_helper_->size();
            } 
            catch (...) 
            {
                current_size_ = 0;
            }
        }
    }
}

template<typename Mutex>
SPDLOG_INLINE size_file_sink<Mutex>::~size_file_sink()
{
    if (file_helper_ && file_stream_)
    {
        file_helper_->close();
        if (last_file_closed_)
        {
            last_file_closed_(file_helper_->filename(), base_file_name_);
        }
    }
}

template<typename Mutex>
SPDLOG_INLINE filename_t size_file_sink<Mutex>::filename()
{
    std::lock_guard<Mutex> lock(spdlog::sinks::base_sink<Mutex>::mutex_);
    return file_helper_ ? file_helper_->filename() : filename_t();
}

template<typename Mutex>
SPDLOG_INLINE filename_t size_file_sink<Mutex>::calc_filename()
{
    const auto time_point = std::chrono::system_clock::now();
    const std::tm tm_value = spdlog::details::os::localtime(std::chrono::system_clock::to_time_t(time_point));
    const auto duration = time_point.time_since_epoch();
    auto secs = std::chrono::duration_cast<std::chrono::seconds>(duration);
    auto msecs = std::chrono::duration_cast<std::chrono::milliseconds>(duration) - 
                 std::chrono::duration_cast<std::chrono::milliseconds>(secs);

    // logger_YYMMDD_hhmmsszzz.log
    return spdlog::fmt_lib::format(SPDLOG_FILENAME_T("{}/{}_{:04d}{:02d}{:02d}_{:02d}{:02d}{:02d}{:03d}{}"),
        log_dir_, base_file_name_,
        tm_value.tm_year + 1900, tm_value.tm_mon + 1, tm_value.tm_mday,                         // YYMMDD
        tm_value.tm_hour, tm_value.tm_min, tm_value.tm_sec, static_cast<int>(msecs.count()),    // hhmmsszzz
        kLogFileSuffix);
}

template<typename Mutex>
SPDLOG_INLINE void size_file_sink<Mutex>::rotate_()
{
    file_helper_->close();
    spdlog::filename_t file_name = file_helper_->filename();
    file_helper_->open(calc_filename(), true);
    if (after_open_)
    {
        after_open_(std::move(file_name), base_file_name_);
    }
    current_size_ = 0;
}

template<typename Mutex>
SPDLOG_INLINE void size_file_sink<Mutex>::sink_it_(const spdlog::details::log_msg &msg)
{
    constexpr char kEol[] = SPDLOG_EOL;
    constexpr size_t kEolLen = std::extent<decltype(kEol)>::value - 1;

    // open log file
    if (!file_stream_)
    {
        rotate_();
    }

    auto new_size = current_size_ + msg.payload.size() + kEolLen;

    // rotate if the new estimated file size exceeds max size.
    // rotate only if the real size > 0 to better deal with full disk (see issue #2261).
    // we only check the real size when new_size > max_size_ because it is relatively expensive.
    if (new_size > max_size_)
    {
        file_helper_->flush();
        if (file_helper_->size() > 0)
        {
            rotate_();
            new_size = msg.payload.size() + kEolLen;
        }
    }

    auto lmd_throw_write_failed = [this] {
        spdlog::throw_spdlog_ex("Failed writing to file " + 
            spdlog::details::os::filename_to_str(file_helper_->filename()), errno);
    };

    // write payload and EOL
    if (std::fwrite(msg.payload.data(), 1, msg.payload.size(), file_stream_) != msg.payload.size())
    {
        lmd_throw_write_failed();
    }
    // write line break
    if (std::fwrite(kEol, 1, kEolLen, file_stream_) != kEolLen)
    {
        lmd_throw_write_failed();
    }

    current_size_ = new_size;
}

template<typename Mutex>
SPDLOG_INLINE void size_file_sink<Mutex>::flush_()
{
    file_helper_->flush();
}

// -----------------------------------------------------------------------

using size_file_sink_mt = size_file_sink<std::mutex>;
using size_file_sink_st = size_file_sink<spdlog::details::null_mutex>;

} // namespace sinks
} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_LOGCORE_SIZE_FILE_SINK_HPP