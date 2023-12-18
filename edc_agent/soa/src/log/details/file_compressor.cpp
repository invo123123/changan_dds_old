#include "asf/logging/logsdk/details/file_compressor.hpp"

#include <cstdio>
#include <cstring>
#include <thread>
#include <queue>
#include <condition_variable>
#include <functional>
#include <algorithm>

#include "asf/logging/logsdk/details/loglog.hpp"
#include "asf/logging/logsdk/details/config.hpp"
#include "asf/logging/logsdk/details/utils.hpp"

#include <spdlog/details/os.h>

// #ifndef ASF_LOGGING_LOGSDK_DISABLE_ZLIB
// #include <zlib.h>
// #endif

#if defined(_WIN32)
#  define ASF_LOGGING_LOGSDK_DISALLOW_SYSTEM_PRINT " 1>nul 2>nul"
#else
#  define ASF_LOGGING_LOGSDK_DISALLOW_SYSTEM_PRINT " > /dev/null 2>&1"
#endif

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

namespace {

// xxx.log --> xxx.log.tar.gz
bool CompressFileWithTarCommand(const std::string& source_file)
{
    if (!spdlog::details::os::path_exists(source_file))
    {
        return false;
    }

    std::string dir;
    std::string file_name;
    Utils::ParseFile(source_file, dir, file_name);
    if (dir.empty() || file_name.empty())
    {
        return false;
    }

    // tar -czf "<dst_dir>/xxx.log.tar.gz" -C "<src_dir>" "xxx.log"
    const std::string target_file = source_file + ".tar.gz";
    constexpr const char kCmdPrefix[] = "tar -czf ";
    constexpr size_t kCmdPrefixLen = std::extent<decltype(kCmdPrefix)>::value - 1ull;
    std::string cmd;
    const std::size_t expected_cmd_len = kCmdPrefixLen + target_file.size() + dir.size() + file_name.size() + 24;
    cmd.reserve(expected_cmd_len);
    cmd += kCmdPrefix;

    cmd += '"';
    cmd += target_file;
    cmd += '"';

    cmd += " -C ";
    cmd += '"';
    cmd += dir;
    cmd += '"';
    cmd += ' ';

    cmd += '"';
    cmd += file_name;
    cmd += '"';

    cmd += ASF_LOGGING_LOGSDK_DISALLOW_SYSTEM_PRINT;

    return (0 == std::system(cmd.c_str()));
}

// #ifndef ASF_LOGGING_LOGSDK_DISABLE_ZLIB

// /**
//  * \brief Compress file in gz format.
//  * 
//  * xxx.log --> xxx.log.gz
//  */
// bool CompressFileWithZlib(const std::string& source_file)
// {
//     std::FILE* file = std::fopen(source_file.c_str(), "rb");
//     if (!file)
//     {
//         std::string message = "Failed to open source file " + source_file + " for compression: ";
//         message += std::strerror(errno);
//         ASF_LOGSDK_INTERNAL_ERROR(message);
//         return false;
//     }

//     const std::string target_file = source_file + ".gz";
//     gzFile gz_file = gzopen(target_file.c_str(), "wb");
//     if (!gz_file)
//     {
//         std::string message = "Failed to open target file " + target_file + " for compression: ";
//         message += std::strerror(errno);
//         ASF_LOGSDK_INTERNAL_ERROR(message);
//         std::fclose(file);
//         return false;
//     }

//     constexpr std::size_t in_buffer_len = 1024;
//     char in_buffer[in_buffer_len] = { 0 };
//     std::size_t num_read = 0;

//     while ((num_read = std::fread(in_buffer, 1, in_buffer_len, file)) > 0)
//     {
//         // total_read += num_read;
//         // gzwrite() returns 0 in case of error.
//         if (0 == gzwrite(gz_file, in_buffer, static_cast<unsigned int>(num_read)))
//         {
//             std::fclose(file);
//             gzclose(gz_file);
//             (void)std::remove(target_file.c_str());
//             ASF_LOGSDK_INTERNAL_ERROR("Write into gz_file failed");
//             return false;
//         }
//     }
//     std::fclose(file);
//     gzclose(gz_file);
//     return true;
// }

// #else

bool CompressFileWithZlib(const std::string& source_file)
{
    (void)source_file;
    return false;
}

// #endif // ASF_LOGGING_LOGSDK_DISABLE_ZLIB

 } // namespace

// The max number of tasks.
constexpr std::size_t kMaxTaskNum = 2000ull;
// The real compress function.
using CompressFunc = std::function<bool(const std::string&)>;

static CompressFunc GetCompressFunc()
{
    constexpr const char* cmd = "tar --version" ASF_LOGGING_LOGSDK_DISALLOW_SYSTEM_PRINT;
    
    if (0 == std::system(cmd))
    {
        return std::bind(CompressFileWithTarCommand, std::placeholders::_1);
    }

    return std::bind(CompressFileWithZlib, std::placeholders::_1);
}

class FileCompressorPrivate
{
public:
    FileCompressorPrivate();
    ~FileCompressorPrivate();

    static bool Compress(const std::string& source_file, const CompressFunc& compress_func);
    bool Compress(const std::string& source_file);

    void AsyncCompress(std::string&& file);

private:
    void ThreadFunc();
    static bool ParseLogFile(const std::string& log_file, std::string& dir, std::string& logger_name);

public:
    size_t max_log_files_{ 0 };

private:
    std::mutex mutex_;
    std::thread th_;
    std::atomic_bool thread_running_flag_{ false };
    std::condition_variable cv_;
    std::queue<std::string> tasks_;
    CompressFunc compress_file_func_;
};

FileCompressorPrivate::FileCompressorPrivate()
{
    ASF_LOGSDK_TRACE_ENTRY();

    compress_file_func_ = GetCompressFunc();

    ASF_LOGSDK_TRACE_EXIT();
}

FileCompressorPrivate::~FileCompressorPrivate()
{
    ASF_LOGSDK_TRACE_ENTRY();

    thread_running_flag_ = false;
    cv_.notify_one();
    if (th_.joinable())
    {
        th_.join();
    }
    ASF_LOGSDK_TRACE_EXIT();
}

bool FileCompressorPrivate::Compress(const std::string& source_file, 
    const CompressFunc& compress_func)
{
    if (!compress_func || !compress_func(source_file))
    {
        return false;
    }

    // if compress successfully, remove the source file.
    if (std::remove(source_file.c_str()) != 0)
    {
        std::string message = "[Compression] Failed to remove source file " + source_file + ": ";
        message += std::strerror(errno);
        ASF_LOGSDK_INTERNAL_WARN(message);
    }

    return true;
}

bool FileCompressorPrivate::Compress(const std::string& source_file)
{
    return Compress(source_file, compress_file_func_);
}

void FileCompressorPrivate::AsyncCompress(std::string&& file)
{
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (tasks_.size() > kMaxTaskNum)
        {
            ASF_LOGSDK_INTERNAL_WARN_ARGS("The log file in FileCompressor queue limit reached, limit is %lu", kMaxTaskNum);
        }
        else
        {
            tasks_.push(std::move(file));
        }
    }

    if (thread_running_flag_)
    {
        cv_.notify_one();
        return;
    }

    if (th_.joinable())
    {
        th_.join();
    }
    th_ = std::thread(&FileCompressorPrivate::ThreadFunc, this);
    if (!Utils::SetThreadName(th_.native_handle(), "asf_logsdk_fcps"))
    {
        ASF_LOGSDK_INTERNAL_WARN("Set FileCompressor thread name failed");
    }
}

bool FileCompressorPrivate::ParseLogFile(const std::string& log_file, std::string& dir, std::string& logger_name)
{
    std::string file_name;
    Utils::ParseFile(log_file, dir, file_name);

    if (dir.empty() || file_name.empty())
    {
        return false;
    }

    // parse logger_name
    auto it = Utils::FindLoggerName(file_name);
    
    if (it != file_name.crend())
    {
        logger_name = file_name.substr(0, std::distance(it, file_name.crend()));
        return true;
    }

    return false;
}

void FileCompressorPrivate::ThreadFunc()
{
    thread_running_flag_ = true;
    while (thread_running_flag_)
    {
        std::size_t task_num = 0;
        std::string file;

        // 压缩线程不会一直存在，超过30秒还没有任务添加进来时，停掉线程
        {
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.wait_for(lock, std::chrono::seconds(30), [this]() -> bool {   // false 则继续等待， true则解除等待
                return !thread_running_flag_ || !tasks_.empty();
            });

            if (!thread_running_flag_)
            {
                return;
            }

            if (tasks_.empty()) // timeout or thread_running_flag_ == false, exit
            {
                thread_running_flag_ = false;
                return;
            }
            
            file = std::move(tasks_.front());
            tasks_.pop();

            task_num = tasks_.size();
        }

        // 尝试清除多余文件
        std::string log_dir;
        std::string logger_name;
        if (!ParseLogFile(file, log_dir, logger_name))
        {
            continue;
        }

        details::Utils::KeepLogFileCount(log_dir, logger_name, max_log_files_, [this]() -> bool {
            return thread_running_flag_;
        });

        // 如果任务数量过多，则压缩速率低，此时可以选择不压缩
        if (task_num <= max_log_files_)
        {
            Compress(file);
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// --------------------------------------------------------

FileCompressor::FileCompressor(size_t max_log_files)
    : pri_(new FileCompressorPrivate())
{
    pri_->max_log_files_ = max_log_files;
    if (max_log_files == 0)
    {
        ASF_LOGSDK_INTERNAL_WARN("FileCompressor: The max file is zero");
    }
    ASF_LOGSDK_TRACE_EXIT();
}

FileCompressor::~FileCompressor()
{
    ASF_LOGSDK_TRACE_EXIT();
}

bool FileCompressor::Compress(const std::string& source_file)
{
    return FileCompressorPrivate::Compress(source_file, GetCompressFunc());
}

void FileCompressor::AsyncCompress(std::string&& source_file)
{
    pri_->AsyncCompress(std::move(source_file));
}

void FileCompressor::AsyncCompress(const std::string& source_file)
{
    std::string tmp(source_file);
    AsyncCompress(std::move(tmp));
}

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf