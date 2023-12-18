#include "asf/logging/logsdk/common.h"

#include <cstring>
#include <algorithm>

#include "asf/logging/logsdk/details/loglog.hpp"
#include "asf/logging/logsdk/details/config.hpp"
#include "asf/logging/logsdk/details/configurator.hpp"
#include "asf/logging/logsdk/logcore/initializer_impl.hpp"

#define COMMON_LOG_UNINITALIZED() ASF_LOGSDK_INTERNAL_ERROR("The asf_logsdk is not initialized!");

unsigned int asf_logsdk_version()
{
    return ASF_LOGGING_LOGSDK_VERSION;
}

const char* asf_logsdk_version_str()
{
    return ASF_LOGGING_LOGSDK_VERSION_STR "-" ASF_LOGGING_LOGSDK_VERSION_SUFFIX;
}

size_t asf_logsdk_app_id_length()
{
    std::lock_guard<std::mutex> lock(asf::logging::logsdk::logcore::g_initializer_impl_mutex);
    if (asf::logging::logsdk::logcore::g_initializer_impl)
    {
        const auto context = asf::logging::logsdk::logcore::g_initializer_impl->GetContext();
        if (context && context->configurator)
        {
            return context->configurator->GetData().app_id.size();
        }
    }
    else
    {
        COMMON_LOG_UNINITALIZED();
    }
    return 0;
}

size_t asf_logsdk_app_id(char* buff, size_t len)
{
    if (!buff || len == 0)
    {
        return 0;
    }

    std::memset(buff, 0, len); 

    std::lock_guard<std::mutex> lock(asf::logging::logsdk::logcore::g_initializer_impl_mutex);
    if (asf::logging::logsdk::logcore::g_initializer_impl)
    {
        const auto context = asf::logging::logsdk::logcore::g_initializer_impl->GetContext();
        if (context && context->configurator)
        {
            const std::string& app_id = context->configurator->GetData().app_id;
            size_t real_length = std::min(len, app_id.size());
            std::strncpy(buff, app_id.c_str(), real_length);
            return real_length;
        }
    }
    else
    {
        COMMON_LOG_UNINITALIZED();
    }

    return 0;
}

size_t asf_logsdk_domain_id_length()
{
    std::lock_guard<std::mutex> lock(asf::logging::logsdk::logcore::g_initializer_impl_mutex);
    if (asf::logging::logsdk::logcore::g_initializer_impl)
    {
        const auto context = asf::logging::logsdk::logcore::g_initializer_impl->GetContext();
        if (context && context->configurator)
        {
            return context->configurator->GetData().domain_id.size();
        }
    }
    else
    {
        COMMON_LOG_UNINITALIZED();
    }
    return 0;
}

size_t asf_logsdk_domain_id(char* buff, size_t len)
{
    if (!buff || len == 0)
    {
        return 0;
    }

    std::memset(buff, 0, len);

    std::lock_guard<std::mutex> lock(asf::logging::logsdk::logcore::g_initializer_impl_mutex);
    if (asf::logging::logsdk::logcore::g_initializer_impl)
    {
        const auto context = asf::logging::logsdk::logcore::g_initializer_impl->GetContext();
        if (context && context->configurator)
        {
            const std::string& domain_id = context->configurator->GetData().domain_id;
            size_t real_length = std::min(len, domain_id.size());
            std::strncpy(buff, domain_id.c_str(), real_length);
            return real_length;
        }
    }
    else
    {
        COMMON_LOG_UNINITALIZED();
    }

    return 0;
}

const char* asf_logsdk_loglevel_name(asf_logsdk_loglevel_t level)
{
    switch (level)
    {
    case ASF_LOGSDK_LOGLEVEL_TRACE:
        return asf::logging::logsdk::details::cfg::kTraceLogLevelName;
    case ASF_LOGSDK_LOGLEVEL_DEBUG:
        return asf::logging::logsdk::details::cfg::kDebugLogLevelName;
    case ASF_LOGSDK_LOGLEVEL_INFO:
        return asf::logging::logsdk::details::cfg::kInfoLogLevelName;
    case ASF_LOGSDK_LOGLEVEL_WARN:
        return asf::logging::logsdk::details::cfg::kWarnLogLevelName;
    case ASF_LOGSDK_LOGLEVEL_ERROR:
        return asf::logging::logsdk::details::cfg::kErrorLogLevelName;
    case ASF_LOGSDK_LOGLEVEL_FATAL:
        return asf::logging::logsdk::details::cfg::kFatalLogLevelName;
    case ASF_LOGSDK_LOGLEVEL_OFF:
        return asf::logging::logsdk::details::cfg::kOffLogLevelName;
    default:
        break;
    }
    return "";
}

void asf_logsdk_set_internal_log_enabled(int enable)
{
    asf::logging::logsdk::details::LogLog::GetInstance().SetEnabled(enable);
}

int asf_logsdk_is_internal_log_enabled()
{
    return asf::logging::logsdk::details::LogLog::GetInstance().IsEnabled();
}

#ifdef __cplusplus

namespace asf {
namespace logging {
namespace logsdk {

const char* GetLogLevelName(LogLevel level)
{
    return asf_logsdk_loglevel_name(static_cast<asf_logsdk_loglevel_t>(level));
}

} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // __cplusplus