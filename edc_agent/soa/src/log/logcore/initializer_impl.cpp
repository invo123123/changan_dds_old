#include "asf/logging/logsdk/logcore/initializer_impl.hpp"

#include <fstream>

#include "asf/logging/logsdk/logcore/logger_manager.hpp"
#include "asf/logging/logsdk/details/loglog.hpp"
#include "asf/logging/logsdk/details/config.hpp"
#include "asf/logging/logsdk/details/log_level_helper.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {

std::shared_ptr<InitializerImpl> g_initializer_impl;
std::mutex g_initializer_impl_mutex;

InitializerImpl::InitializerImpl()
    : sdk_context_(std::make_shared<SdkContext>())
    , logger_manager_(std::make_shared<LoggerManager>())
{
    ASF_LOGSDK_TRACE_EXIT();
}

InitializerImpl::~InitializerImpl()
{
    ASF_LOGSDK_TRACE_EXIT();
}

std::shared_ptr<SdkContext>& InitializerImpl::GetContext()
{
    return sdk_context_;
}

const std::shared_ptr<SdkContext>& InitializerImpl::GetContext() const
{
    return sdk_context_;
}

std::shared_ptr<LoggerManager>& InitializerImpl::GetLoggerManager()
{
    return logger_manager_;
}

const std::shared_ptr<LoggerManager>& InitializerImpl::GetLoggerManager() const
{
    return logger_manager_;
}

bool InitializerImpl::DoInitialize(const std::string& conf_file)
{
    std::lock_guard<std::mutex> lock(init_mutex_);
    if (initialized_)
    {
        return true;
    }

    sdk_context_->configurator = std::make_shared<details::Configurator>();
    if (!sdk_context_->configurator->LoadConfiguration(conf_file))
    {
        return false;
    }

    initialized_ = Initialize();
    return initialized_;
}

bool InitializerImpl::DoInitializeWithConfData(const std::string& conf_data)
{
    std::lock_guard<std::mutex> lock(init_mutex_);
    if (initialized_)
    {
        return true;
    }

    sdk_context_->configurator = std::make_shared<details::Configurator>();
    if (!sdk_context_->configurator->LoadConfigurationData(conf_data))
    {
        return false;
    }

    initialized_ = Initialize();
    return initialized_;
}

bool InitializerImpl::Initialize()
{
    auto configuration_data = sdk_context_->configurator->GetData();

    // FileCompressor
    if (configuration_data.compress)
    {
        sdk_context_->file_compressor = std::make_shared<details::FileCompressor>(configuration_data.max_log_files);
    }

    // LoggerManager
    logger_manager_->SetSdkContext(sdk_context_);

    return true;
}

} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf