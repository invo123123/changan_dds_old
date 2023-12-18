#include "asf/logging/logsdk/details/dir.hpp"

#include <queue>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#  define ASF_OS_WINDOWS
#  include <windows.h>
#  include <cstring>
#  ifdef _MSC_VER
#    pragma warning (disable:4996)
#    pragma warning (disable:4251)
#  endif
#else
#  include <dirent.h>
#endif

namespace asf {
namespace logging {
namespace logsdk {
namespace details {
namespace dir {

#ifdef ASF_OS_WINDOWS

struct dirent
{
    char d_name[MAX_PATH + 1];
    WIN32_FIND_DATAA data;
};

struct DIR
{
    char* dirname;          /* directory being scanned */
    dirent current;         /* current entry */
    int dirent_filled;      /* is current un-processed? */
    HANDLE search_handle;
};

static void setdirname(DIR* dp);
static int initdir(DIR* dp);
static DIR* opendir(const char* dirname);
static dirent* readdir(DIR* dp);
static int closedir(DIR* dp);
#if 0
static void rewinddir (DIR* dp);
#endif // if 0

static void setdirname(DIR* dp)
{
    if (strlen(dp->current.data.cFileName) > MAX_PATH)
    {
        return;
    }

    strncpy(dp->current.d_name, dp->current.data.cFileName, MAX_PATH);
    dp->current.d_name[MAX_PATH] = '\0';
}

static int initdir(DIR* dp)
{
    if (!dp || !dp->dirname)
    {
        errno = EBADF;
        return -1;
    }

    dp->dirent_filled = 0;
    dp->search_handle = ::FindFirstFileA(dp->dirname, &dp->current.data);
    if (dp->search_handle == INVALID_HANDLE_VALUE)
    {
        // something went wrong but we don't know what. ::GetLastError() could
        // give us more information about the error, but then we should map
        // the error code into errno.
        errno = ENOENT;
        return -1;
    }

    setdirname(dp);
    dp->dirent_filled = 1;

    return 0;
}

static DIR* opendir(const char* dirname)
{
    if (!dirname)
    {
        errno = EBADF;
        return nullptr;
    }

    DIR* dp = new DIR();
    dp->dirname = new char[strlen(dirname) + 1 + strlen("\\*.*")];
    strcpy(dp->dirname, dirname);
    char* p = strchr(dp->dirname, '\0');

    if (dp->dirname < p  && *(p - 1) != '\\'  &&  *(p - 1) != '/'  &&  *(p - 1) != ':')
    {
        strcpy(p++, "/");
    }

    strcpy(p, "*"); // scan files with and without extension in win32

    if (initdir(dp) != 0)
    {
        delete[] dp->dirname;
        delete dp;
        return nullptr;
    }
    return dp;
}

static dirent* readdir(DIR* dp)
{
    if (!dp || dp->search_handle == INVALID_HANDLE_VALUE)
    {
        errno = EBADF;
        return nullptr;
    }

    if (dp->dirent_filled != 0)
    {
        dp->dirent_filled = 0;
    } 
    else
    {
        if (::FindNextFileA (dp->search_handle, &dp->current.data) == FALSE)
        {
            /* Last file has been processed or an error occured */
            ::FindClose(dp->search_handle);
            dp->search_handle = INVALID_HANDLE_VALUE;
            errno = ENOENT;
            return nullptr;
        }
        setdirname(dp);
    }

    return &dp->current;
}

static int closedir(DIR* dp)
{
    if (!dp)
    {
        errno = EBADF;
        return -1;
    }

    if (dp->dirname)
    {
        delete[] dp->dirname;
        dp->dirname = nullptr;
    }

    if (dp->search_handle != INVALID_HANDLE_VALUE)
    {
        if (::FindClose(dp->search_handle) == FALSE) {
            // unkown error
            return -1;
        }
    }

    memset(dp, 0, sizeof(*dp));
    dp->search_handle = INVALID_HANDLE_VALUE;
    delete dp;

    return 0;
}

#if 0
static void rewinddir(DIR* dp)
{
    if (!dp || !dp->dirname)
    {
        errno = EBADF;
        return;
    }

    if (dp->search_handle != INVALID_HANDLE_VALUE)
    {
        if (::FindClose(dp->search_handle) == FALSE)
        {
            /* Unknown error */
            errno = EBADF;
        }
    }

    initdir(dp);
}
#endif // if 0

#endif

static bool IsDir(const std::string& path)
{    
    DIR* dir = opendir(path.c_str());
    if (!dir)
    {
        return false;
    }
    closedir(dir);
    return true;
}

std::vector<std::string> ListFileNames(const std::string& folder, bool full_path,
    const std::function<bool(const std::string&)>& filter, 
    const std::function<bool()>& loop_predicate)
{
    using ResultType = std::vector<std::string>;
    ResultType file_list;

    if (folder.empty())
    {
        return file_list;
    }

    // try to open directory
    DIR* dir = opendir(folder.c_str());
    if (!dir)
    {
        return file_list;
    }

    // iterate through all the files and directories
    dirent* ent = nullptr;
    while ((ent = readdir(dir)) != nullptr)
    {
        if (loop_predicate && !loop_predicate())
        {
            closedir(dir);
            return ResultType();  // return empty if the loop is canceled
        }

        std::string name(ent->d_name);
        if (name == "." || name == "..")
        {
            continue;
        }

        std::string path = folder + '/' + name;
        std::string& file_name = full_path ? path : name;

        if (IsDir(path) || (filter && !filter(file_name)))
        {
            continue;
        }

        file_list.emplace_back(std::move(file_name));
    }

    closedir(dir);
    return file_list;
}

} // namespace dir
} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf
