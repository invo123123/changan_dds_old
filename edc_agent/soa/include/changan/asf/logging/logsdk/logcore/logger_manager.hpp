#ifndef ASF_LOGGING_LOGSDK_LOGCORE_LOGGER_MANAGER_HPP
#define ASF_LOGGING_LOGSDK_LOGCORE_LOGGER_MANAGER_HPP

#include <map>
#include <memory>

#include "asf/logging/logsdk/details/rwmutex.hpp"
#include "asf/logging/logsdk/logcore/sdk_context.hpp"
#include "asf/logging/logsdk/logcore/logger_impl.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace logcore {

/**
 * \brief The LoggerManager class manages all LoggerImpl.
 */
class LoggerManager
{
public:
    LoggerManager();
    explicit LoggerManager(const std::shared_ptr<SdkContext>& sdk_context);
    ~LoggerManager();

    void SetSdkContext(const std::shared_ptr<SdkContext>& sdk_context);

    std::shared_ptr<SdkContext>& GetSdkContext();
    const std::shared_ptr<SdkContext>& GetSdkContext() const;
    
    /**
     * \brief Retrieve a LoggerImpl with given \a name. 
     * 
     * If the named logger already exists, then the existing instance will be returned. 
     * Otherwise, a new instance is created.
     * 
     * Since the \a name will be used to crate log file, it should be meet the file naming convention.
     * If not, the default logger named "default" will returned.
     */
    std::shared_ptr<LoggerImpl> GetLoggerImpl(const std::string& name);

    /**
     * \brief Returns \c true if the logger named \a name exists, otherwise returns false.
     */
    bool IsExists(const std::string& name);

    /**
     * \brief Set all loggers' file log level.
     */
    void SetFileLogLevel(spdlog::level::level_enum log_level);

    /**
     * \brief Set all loggers' console log level.
     */
    void SetConsoleLogLevel(spdlog::level::level_enum log_level);

    /**
     * \brief Set all loggers' flush level.
     */
    void SetFlushLevel(spdlog::level::level_enum log_level);

    /**
     * \brief Flushes all loggers.
     */
    void FlushAll();

private:
    LoggerManager(const LoggerManager&) = delete;
    LoggerManager& operator=(const LoggerManager&) = delete;

private:
    std::map<std::string, std::shared_ptr<LoggerImpl>> logger_impl_map_;
    details::RWMutex mutex_;

    std::shared_ptr<SdkContext> sdk_context_;
};

} // namespace logcore
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_LOGCORE_LOGGER_MANAGER_HPP