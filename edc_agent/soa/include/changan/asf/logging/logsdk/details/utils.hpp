#ifndef ASF_LOGGING_LOGSDK_DETAILS_UTILS_HPP
#define ASF_LOGGING_LOGSDK_DETAILS_UTILS_HPP

#include <ctime>
#include <chrono>
#include <string>
#include <thread>
#include <vector>
#include <functional>

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

class Utils
{
public:
    /**
     * \brief Get current time stamp
     * 
     * e.g. 
     *  std::int64_t current_ts = GetCurrentTimeStamp<std::int64_t, std::chrono::milliseconds>();
     */
    template<class T, class Duration, class Clock = std::chrono::system_clock>
    inline static T GetCurrentTimeStamp()
    {
        return std::chrono::duration_cast<std::chrono::duration<T, typename Duration::period>>(
            Clock::now().time_since_epoch()).count();
    }

    /**
     * \brief return fraction of a second of the given time_point.
     * 
     * e.g.
     *  auto tp = std::chrono::system_clock::now();
     *  TimeFraction<std::chrono::milliseconds>(tp) -> will return the millis part of the second
     */
    template<typename ToDuration, class Clock = std::chrono::system_clock>
    inline static ToDuration TimeFraction(typename Clock::time_point tp)
    {
        auto duration = tp.time_since_epoch();
        auto secs = std::chrono::duration_cast<std::chrono::seconds>(duration);
        return std::chrono::duration_cast<ToDuration>(duration) - std::chrono::duration_cast<ToDuration>(secs);
    }

    /**
     * \brief Get the application file path.
     * 
     * Get the result from system API first, if failed, return \a default_path.
     * 
     * \param default_path The default application file path, is usually ``argv[0]``.
     */
    static std::string GetApplicationFilePath(const std::string& default_path = std::string());

    /**
     * \brief Get the application directory path.
     * 
     * Get the result from system API first, if failed, parse path from \a default_app_file_path.
     * 
     * \param default_app_file_path The default application file path, is usually ``argv[0]``.
     */
    static std::string GetApplicationDirPath(const std::string& default_app_file_path = std::string());

    /**
     * \brief Get the application name without path.
     * 
     * For example, if you run the "/usr/bin/my_exec" or "C:\\bin\\my_exec.exe", 
     * this function will return "my_exec"。
     * 
     * \param default_app_file_path The default application file path, is usually ``argv[0]``.
     * 
     * \note The return value may be empty string.
     */
    static std::string GetApplicationName(const std::string& default_app_file_path = std::string());

    /**
     * \brief Check if file name is valid or not.
     */
    static bool IsFileNameValid(const std::string& name);

    /**
     * \brief Check if path is valid or not.
     */
    static bool IsPathValid(const std::string& path);

    /**
     * \brief Transform \a str to upper.
     */
    static void AsciiToUpper(std::string& str);

    /**
     * \brief Returns the name of the file, excluding the path.
     */
    static const char* ExtractFileName(const char* file_path);

    static void ParseFile(const std::string& path, std::string& dir, std::string& file_name);

    /**
     * \brief Set the thread's name, 15 characters limit on POSIX.
     */
    static bool SetThreadName(std::thread::native_handle_type thread_id, const std::string& name);

    /**
     * \brief Find logger name from \a file_name.
     * 
     * file_name can be full path.
     */
    static std::string::const_reverse_iterator FindLoggerName(const std::string& file_name);

    /**
     * \brief Returns true if the \a file_name is the logger's log file; otherwise returns false.
     * 
     * \note file_name must be just file name, not include path. 
     */
    static bool IsLogFileMatchLogger(const std::string& file_name, const std::string& logger_name);

    /**
     * \brief Returns true if \a str begin with \a begin.
     */
    static bool IsStringBeginWith(const std::string& str, const std::string& begin);

    /**
     * \brief Returns true if \a str ends with \a ends.
     */
    static bool IsStringEndsWith(const std::string& str, const char* ends);

    /**
     * \brief Keep the log file count with max_files. 
     * 
     * If the log file is greater than \a remain_count, then find the oldest log file and delete it.
     * If the log file is less than \a remain_count, do nothing.
     * 
     * \param dir the log file dir.
     * \param logger_name the name of logger.
     * \param remain_count Number of log file to remain.
     * \param loop_predicate Continuous scanning condition, if false, the scan ends prematurely.
     * \param[out] file_list The remianing log files only contain the file name, arrange in ascending order.
     */
    static void KeepLogFileCount(const std::string& dir, const std::string& logger_name, size_t remain_count,
        const std::function<bool()>& loop_predicate = nullptr, std::vector<std::string>* file_list = nullptr);
};

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf


#endif // ASF_LOGGING_LOGSDK_DETAILS_UTILS_HPP