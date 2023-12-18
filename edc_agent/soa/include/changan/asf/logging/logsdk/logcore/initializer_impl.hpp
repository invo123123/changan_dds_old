#ifndef ASF_LOGGING_LOGSDK_LOGCORE_INITIALIZER_IMPL_HPP
#define ASF_LOGGING_LOGSDK_LOGCORE_INITIALIZER_IMPL_HPP

#include <mutex>

#include "asf/logging/logsdk/logcore/sdk_context.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {

// forward declaration
class LoggerManager;

class InitializerImpl
{
public:
    InitializerImpl();
    ~InitializerImpl();

    bool DoInitialize(const std::string& conf_file);
    bool DoInitializeWithConfData(const std::string& conf_data);

    std::shared_ptr<SdkContext>& GetContext();
    const std::shared_ptr<SdkContext>& GetContext() const;

    std::shared_ptr<LoggerManager>& GetLoggerManager();
    const std::shared_ptr<LoggerManager>& GetLoggerManager() const;

private:
    bool Initialize();

private:
    std::mutex init_mutex_;
    bool initialized_{ false };

    std::shared_ptr<SdkContext> sdk_context_;
    std::shared_ptr<LoggerManager> logger_manager_;
};

extern std::shared_ptr<InitializerImpl> g_initializer_impl;
extern std::mutex g_initializer_impl_mutex;

} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_LOGCORE_INITIALIZER_IMPL_HPP