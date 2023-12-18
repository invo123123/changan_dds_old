#ifndef ASF_LOGGING_LOGSDK_INITIALIZER_H
#define ASF_LOGGING_LOGSDK_INITIALIZER_H

#include <string>
#include <asf/logging/logsdk/common.h>

namespace asf {
namespace logging {
namespace logsdk {

/**
 * \brief The Initializer class provides some useful interfaces to initialize the asf_logsdk.
 * 
 * Before logging, you should call Initializer::DoInitialize(). 
 * It is recommended to call it at the beginning of `main()` function.
 * 
 * Call Initializer::Shutdown() to shutdown the asf_logsdk when the SDK no longer used.
 */
class Initializer
{
public:
    /**
     * \brief Initialize the asf_logsdk with given \a conf_file.
     * 
     * \param conf_file The asf_logsdk configuration file, in json format.
     * 
     * \note The return value should not be discarded.
     */
    static bool DoInitialize(const std::string& conf_file) ASF_LOGGING_LOGSDK_ATTR_NODISCARD;

    /**
     * \brief Initialize the asf_logsdk with given configuration data in json format.
     * 
     * \param conf_data The asf_logsdk configuration data in json format.
     * 
     * \note The return value should not be discarded.
     */
    static bool DoInitializeWithConfData(const std::string& conf_data) ASF_LOGGING_LOGSDK_ATTR_NODISCARD;

    /**
     * \brief Returns the 'AppId' filed in the configuration data.
     *  
     * Returns an empty string if the logsdk is not initialized.
     * 
     * \since v1.4.1
     */
    static std::string GetAppId();

    /**
     * \brief Returns the 'DomainId' filed in the configuration data.
     * 
     * Returns an empty string if the logsdk is not initialized.
     * 
     * \since v1.4.1
     */
    static std::string GetDomainId();

    /**
     * \brief Returns the 'LogFileDir' filed in the configuration data.
     * 
     * Returns an empty string if the logsdk is not initialized.
     * 
     * \since v1.4.1
     */
    static std::string GetLogFileDir();

    /**
     * \brief Returns \c true if the asf_logsdk is initialized, otherwise returns \c false.
     * \since v1.4.0
     */
    static bool IsInitialized();

    /**
     * \brief Shutdown the asf_logsdk when the SDK no longer used.
     * \since v1.3.1
     * 
     * \note You can initialize the logsdk agin after shutdown since v1.4.0.
     */
    static void Shutdown();

    /**
     * \brief Get the application directory path.
     * 
     * Get the result from system API first, if failed, parse path from \a default_app_file_path.
     * 
     * \param default_app_file_path The default application file path, is usually ``argv[0]``.
     */
    static std::string GetApplicationDirPath(const std::string& default_app_file_path = std::string());
};

} // namespace logsdk
} // namespace logging
} // namespace asf

#endif // ASF_LOGGING_LOGSDK_INITIALIZER_H