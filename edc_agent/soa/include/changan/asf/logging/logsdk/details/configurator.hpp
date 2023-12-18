#ifndef ASF_LOGGING_LOGSDK_DETAILS_CONFIGURATOR_HPP
#define ASF_LOGGING_LOGSDK_DETAILS_CONFIGURATOR_HPP

#include <string>
#include <vector>
#include <mutex>
#include <memory>

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

struct ConfigurationData
{
    /** APP ID */
    std::string app_id;
    /** Domain ID */
    std::string domain_id;

    /** The default logger name */
    std::string default_logger_name;

    /** The log level for file, "trace/debug/info/warn/error/fatal/off", case insensitive */
    std::string file_log_level;
    /** The log level for console, "trace/debug/info/warn/error/fatal/off", case insensitive */
    std::string console_log_level;
    /** The flush level for file mode, "trace/debug/info/warn/error/fatal/off", case insensitive */
    std::string flush_level;
    /** The directory to save log files. */
    std::string log_file_dir;
    /** The maximum size of single log file, in KB. default is 1MB. */
    std::size_t log_file_max_size;

    /** The maximum count of files to rotate. */
    std::size_t max_log_files;

    /** Compress the log file or not */
    bool compress;
};

class ConfiguratorPrivate;

/**
 * \brief The global configuration class for asf_logsdk.
 */
class Configurator
{
public:
    Configurator();
    ~Configurator();

    Configurator(const Configurator&) = delete;
    Configurator& operator=(const Configurator&) = delete;

    /**
     * \brief Load asf_logsdk configuration file.
     * 
     * \param conf_file The asf-log SDK configuration file in json format named like <code>asf_logsdk.conf</code>.
     * \retval true Load success
     * \retval false Load failed
     */
    bool LoadConfiguration(const std::string& conf_file);

    /**
     * \brief Load asf_logsdk configuration string data in json format.
     * 
     * like: 
     * ```json
     * { "AppId" : "LOGM", "DomainId" : "ECU1", ... }
     * ```
     * 
     * \param conf_data The configuration string data in json format.
     * \retval true Load success
     * \retval false Load failed
     */
    bool LoadConfigurationData(const std::string& conf_data);

    /**
     * \brief Returns \c true if the asf_logsdk configuration file is loaded OK, otherwise returns \c false.
     */
    bool IsLoaded() const;

    /**
     * \brief Set the app_id object
     * 
     * \note This operation will change the app_id loaded from configuration file.
     * \note Thread safe
     */
    void SetAppId(const std::string& app_id);

    /**
     * \brief Set the log level.
     * 
     * \note This operation will change the log level loaded from configuration file.
     * \note Thread safe
     */
    bool SetFileLogLevel(const std::string& log_level, std::string& error_msg);
    bool SetConsoleLogLevel(const std::string& log_level, std::string& error_msg);
    bool SetFlushLevel(const std::string& flush_level);

    /**
     * \brief Get the file log level.
     * 
     * \note Thread safe
     */
    std::string GetFileLogLevel() const;
    std::string GetConsoleLogLevel() const;
    std::string GetFlushLevel() const;

    /**
     * \brief Get the const reference configuration data.
     * 
     * \note Not thread safe.
     * 
     * \note Call GetFileLogLevel() if you want to get the file sink log level.
     */
    const ConfigurationData& GetData() const;

private:
    std::unique_ptr<ConfiguratorPrivate> pri_;
};

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_DETAILS_CONFIGURATOR_HPP