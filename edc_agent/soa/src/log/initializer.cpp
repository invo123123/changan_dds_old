#include "asf/logging/logsdk/initializer.hpp"

#include <cstdlib>
#include <mutex>
#include <iostream>

#include "asf/logging/logsdk/common.h"
#include "asf/logging/logsdk/details/utils.hpp"
#include "asf/logging/logsdk/details/loglog.hpp"
#include "asf/logging/logsdk/logcore/initializer_impl.hpp"

namespace asf {
namespace logging {
namespace logsdk {

static bool g_init_flag = false;

static void InitializeImpl()
{
    if (!logcore::g_initializer_impl)
    {
        logcore::g_initializer_impl = std::make_shared<logcore::InitializerImpl>();
    }
}

static void DeinitializeImpl()
{
    if (logcore::g_initializer_impl)
    {
        logcore::g_initializer_impl.reset();
    }
    g_init_flag = false;
}

bool Initializer::DoInitialize(const std::string& conf_file)
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (g_init_flag)
    {
        return true;
    }

    // 发布版本屏蔽输出
    // std::cout << "-------------------------------------------------------------------------------" << std::endl;
    // std::cout << "** asf_logsdk v" << ASF_LOGGING_LOGSDK_VERSION_STR << '-' <<
    //     ASF_LOGGING_LOGSDK_VERSION_SUFFIX << std::endl;
    // std::cout << "** configuration file: \"" << conf_file << "\"" << std::endl;
    // std::cout << "-------------------------------------------------------------------------------" << std::endl;

    InitializeImpl();
    if (!logcore::g_initializer_impl->DoInitialize(conf_file))
    {
        DeinitializeImpl();
        return false;
    }

    g_init_flag = true;
    return true;
}

bool Initializer::DoInitializeWithConfData(const std::string& conf_data)
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    if (g_init_flag)
    {
        return true;
    }

    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << "** asf_logsdk v" << ASF_LOGGING_LOGSDK_VERSION_STR << '-' <<
        ASF_LOGGING_LOGSDK_VERSION_SUFFIX << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    InitializeImpl();
    if (!logcore::g_initializer_impl->DoInitializeWithConfData(conf_data))
    {
        DeinitializeImpl();
        return false;
    }

    g_init_flag = true;
    return true;
}

std::string Initializer::GetAppId()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    
    if (g_init_flag && 
        logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() && 
        logcore::g_initializer_impl->GetContext()->configurator)
    {
        return logcore::g_initializer_impl->GetContext()->configurator->GetData().app_id;
    }

    return std::string();
}

std::string Initializer::GetDomainId()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);

    if (g_init_flag && 
        logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() && 
        logcore::g_initializer_impl->GetContext()->configurator)
    {
        return logcore::g_initializer_impl->GetContext()->configurator->GetData().domain_id;
    }

    return std::string();
}

std::string Initializer::GetLogFileDir()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);

    if (g_init_flag && 
        logcore::g_initializer_impl && 
        logcore::g_initializer_impl->GetContext() && 
        logcore::g_initializer_impl->GetContext()->configurator)
    {
        return logcore::g_initializer_impl->GetContext()->configurator->GetData().log_file_dir;
    }

    return std::string();
}

bool Initializer::IsInitialized()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    return g_init_flag;
}

void Initializer::Shutdown()
{
    std::lock_guard<std::mutex> lock(logcore::g_initializer_impl_mutex);
    DeinitializeImpl();
}

std::string Initializer::GetApplicationDirPath(const std::string& default_app_file_path)
{
    return details::Utils::GetApplicationDirPath(default_app_file_path);
}

} // namespace logsdk
} // namespace logging
} // namespace asf