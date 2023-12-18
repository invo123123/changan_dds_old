#include "asf/logging/logsdk/details/utils.hpp"

#include <limits.h> // PATH_MAX on posix

#include <cstring>
#include <cstdlib>
#include <memory>
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>

#include "asf/logging/logsdk/details/dir.hpp"

// qnx
#if defined(__QNXNTO__) || defined(__QNX__)
#  define ASF_OS_QNX
#endif

#if defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
#  define ASF_OS_MACOS
#  include <unistd.h>
#  include <libproc.h>
#endif

// Linux / Android
#if defined(__linux__) || defined(__linux) || defined(__ANDROID__)
#  define ASF_OS_LINUX
#  include <unistd.h> // readlink
#endif

// windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#  define ASF_OS_WINDOWS
#  include <windows.h>
#  include <processthreadsapi.h>
#endif

#if defined(PATH_MAX)   // posix
#  define ASF_MAX_PATH  PATH_MAX
#elif defined(MAX_PATH) // windows
#  define ASF_MAX_PATH  MAX_PATH
#else
#  define ASF_MAX_PATH  4096
#endif

#if defined(ASF_LOGGING_HAS_PTHREAD)
#  include <pthread.h>
#endif

#include <sys/stat.h> // for stat

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

#if defined(ASF_OS_WINDOWS) && !defined(__MINGW32__)
static std::wstring StringToWString(const std::string& str)
{
    int len = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
    WCHAR* buffer = new WCHAR[len + 1];
    ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
    buffer[len] = '\0';
    std::wstring result(buffer);
    delete[] buffer;
    return result;
}
#endif

std::string Utils::GetApplicationFilePath(const std::string& default_path)
{
    
#if defined(ASF_OS_WINDOWS)
    TCHAR buffer[ASF_MAX_PATH] = { 0 };
    DWORD len = GetModuleFileName(NULL, buffer, ASF_MAX_PATH);
    if (0 == len)
    {
        return default_path;
    }
#  if defined(UNICODE)
    // char char_buffer[ASF_MAX_PATH] = { 0 };
    int real_len = ::WideCharToMultiByte(CP_ACP, 0, buffer, -1, NULL, 0, NULL, NULL);
    if (0 == real_len)
    {
        return default_path;
    }
    std::unique_ptr<char[]> char_buff(new char[real_len + 1]);
    real_len = ::WideCharToMultiByte(CP_ACP, 0, buffer, -1, char_buff.get(), real_len + 1, NULL, NULL);
    return std::string(char_buff.get(), real_len);
#  else
    return std::string(buffer, len);
#  endif

#elif defined(ASF_OS_QNX)

	const char* app_proc_file = "/proc/self/exefile";
	std::ifstream file(app_proc_file);
    if (!file.is_open())
    {
        return default_path;
    }

    std::string app_file_path = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    // 移除末尾的结束符
    if (!app_file_path.empty() && app_file_path.back() == 0)
    {
        app_file_path.resize(app_file_path.size() - 1);
    }
    file.close();
    return app_file_path;

#elif defined(ASF_OS_LINUX)

    constexpr std::size_t size = ASF_MAX_PATH + 1;
    char buffer[size] = { 0 };
    auto count = readlink("/proc/self/exe", buffer, size);
    if (count < 0 || static_cast<std::size_t>(count) >= size)
    {
        return default_path;
    }

    buffer[count] = '\0';
    return std::string(buffer, count);
#elif defined(ASF_OS_MACOS)
    constexpr std::size_t kMaxPathSize = PROC_PIDPATHINFO_MAXSIZE;
    char buff[kMaxPathSize] = { 0 };
    auto count = ::proc_pidpath(::getpid(), buff, sizeof(buff));
    if (count < 0 || static_cast<std::size_t>(count) > kMaxPathSize)
    {
        return default_path;
    }
    return std::string(buff, count);
#else
    return default_path;
#endif
}

std::string Utils::GetApplicationDirPath(const std::string& default_app_file_path)
{
    std::string app_file_path = GetApplicationFilePath(default_app_file_path);

    if (app_file_path.empty())
    {
        return std::string();
    }

    std::size_t pos = app_file_path.find_last_of("/\\");
    if (pos == std::string::npos)
    {
        return std::string();
    }

    return app_file_path.substr(0, pos);
}

std::string Utils::GetApplicationName(const std::string& default_app_file_path)
{
    std::string app_file_path = GetApplicationFilePath(default_app_file_path);
    std::size_t pos = app_file_path.find_last_of("/\\");
    pos = (pos == std::string::npos ? 0 : pos + 1);

    std::string app_name;
    std::size_t count = 0;

#if defined(_WIN32)
    std::size_t dot_pos = app_file_path.rfind('.');
    if (dot_pos == std::string::npos || dot_pos < pos)
    {
        dot_pos = app_file_path.size();
    }
    count = dot_pos - pos;
#else
    count = app_file_path.size() - pos;
#endif
    app_name = app_file_path.substr(pos, count);
    return app_name;
}

bool Utils::IsFileNameValid(const std::string& name)
{
    std::regex reg_ex("[\\/:*?\"<>|&$#]");
    return !std::regex_search(name, reg_ex);
}

bool Utils::IsPathValid(const std::string& path)
{
    if (path.empty())
    {
        return false;
    }

    std::regex reg_ex("[:*?\"<>|&$#]");
#ifdef ASF_OS_WINDOWS
    if (path.size() > 2 && path[1] == ':')  // C:/xxx...
    {
        return !std::regex_search(path.substr(2), reg_ex);
    }
    else
    {
        return !std::regex_search(path, reg_ex);
    }
#else
    return !std::regex_search(path, reg_ex);
#endif
}

void Utils::AsciiToUpper(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](char c) -> char {
        if (c >= 'a' && c <= 'z')
        {
            return c - 'a' + 'A';
        }
        return c;
    });
}

const char* Utils::ExtractFileName(const char* path)
{
    if (!path)
    {
        return nullptr;
    }

    size_t len = std::strlen(path);
    if (len == 0)
    {
        return nullptr;
    }

    const char* rbegin = path + (len - 1);
    const char* rend = path - 1;
    const char* it = rbegin;
    while (it != rend)
    {
        if (*it == '/'
#ifdef ASF_OS_WINDOWS
            || *it == '\\'
#endif // ASF_OS_WINDOWS
        ) 
        {
            break;
        }
        --it;
    }

    if (it == rbegin)
    {
        return nullptr;
    }

    if (it == rend)
    {
        return path;
    }
    return path + (it - path) + 1;
}

void Utils::ParseFile(const std::string& path, std::string& dir, std::string& file_name)
{
    if (path.empty())
    {
        dir = std::string("");
        file_name = std::string("");
        return;
    }

    auto pos = path.find_last_of("/\\");
    if (pos == std::string::npos)
    {
        dir = std::string("");
        file_name = path;
        return;
    }

    if (pos == path.size() - 1)
    {
        dir = path;
        file_name = std::string("");
        return;
    }

    dir = path.substr(0, pos + 1);
    file_name = path.substr(pos + 1);
}

bool Utils::SetThreadName(std::thread::native_handle_type thread_handle, const std::string& name)
{
#if defined(ASF_OS_WINDOWS) && !defined(__MINGW32__)
    std::wstring wname = StringToWString(name);
    HRESULT result = ::SetThreadDescription(thread_handle, wname.c_str());
    return SUCCEEDED(result);
#else
    return (0 == ::pthread_setname_np(thread_handle, name.c_str()));
#endif
    return false;
}

// logger_yyMMdd_hhmmsszzz.log
std::string::const_reverse_iterator Utils::FindLoggerName(const std::string& file_name)
{
    auto it = file_name.crbegin();
    bool sep_found = false;
    while (it != file_name.crend())
    {
        if (*it == '_')
        {
            if (sep_found)
            {
                ++it;
                break;
            } 
            else 
            {
                sep_found = true;
            }
        }
        ++it;
    }
    return it;
}

// logger_yyMMdd_hhmmsszzz.log
bool Utils::IsLogFileMatchLogger(const std::string& file_name, const std::string& logger_name)
{
    auto it = FindLoggerName(file_name);
    if (it == file_name.crend())
    {
        return false;
    }

    if (static_cast<size_t>(std::distance(it, file_name.crend())) != logger_name.size())
    {
        return false;
    }

    return std::equal(it, file_name.crend(), logger_name.rbegin());
}

bool Utils::IsStringBeginWith(const std::string& str, const std::string& begin)
{
    if (begin.size() > str.size())
    {
        return false;
    }
    return (0 == std::char_traits<char>::compare(str.c_str(), begin.c_str(), begin.size()));
}

bool Utils::IsStringEndsWith(const std::string& str, const char* ends)
{
    if (!ends)
    {
        return false;
    }
    std::size_t ends_len = std::char_traits<char>::length(ends);
    return str.size() >= ends_len && str.compare(str.size() - ends_len, ends_len, ends) == 0;
}

// 有可能 x.log  x.log.tar.gz  x.log.gz 同时存在，那么需要删除三者
void Utils::KeepLogFileCount(const std::string& dir, const std::string& logger_name, size_t remain_count,
    const std::function<bool()>& loop_predicate, std::vector<std::string>* file_list)
{
    std::vector<std::string> file_name_list = dir::ListFileNames(dir, false, 
        [&](const std::string& file_name) -> bool {
            return IsLogFileMatchLogger(file_name, logger_name);
        }, loop_predicate);
    
    if (file_name_list.empty() || file_name_list.size() < remain_count)
    {
        return;
    }

    // (1)文件排序，x.log.gz 将排在 x.log 后，以升序排序
    std::sort(file_name_list.begin(), file_name_list.end());

    // (2) 移除重复的日志文件，比如 x.log 与 x.log.gz 视为同一个日志文件，保留 x.log
    auto it_b = file_name_list.begin();
    auto it = std::next(it_b);
    while (it_b != file_name_list.end() && it != file_name_list.end())
    {
        // 如果 x.log.gz 和 x.log 同时存在，则删除 x.log.gz， 保留 x.log
        while (it != file_name_list.end() && IsStringBeginWith(*it, *it_b))
        {
            // delete
            std::string file = dir + '/' + (*it);
            (void)std::remove(file.c_str());

            it = file_name_list.erase(it);
        }
        it_b = it;
        if (it_b == file_name_list.end())
        {
            break;
        }
        it = std::next(it_b);
    }

    // (3) 保留末尾的 n 个文件，其余文件删除
    if (file_name_list.size() > remain_count)
    {
        for (size_t i = 0; i < file_name_list.size() - remain_count; ++i)
        {
            std::string file = dir + '/' + file_name_list[i];
            (void)std::remove(file.c_str());
        }
    }

    if (file_list)
    {
        *file_list = std::move(file_name_list);
    }
}

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf