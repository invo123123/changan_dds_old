#include "asf/logging/logsdk/details/configurator.hpp"

#include <cstdio>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/filewritestream.h>

#include "asf/logging/logsdk/details/utils.hpp"
#include "asf/logging/logsdk/details/config.hpp"
#include "asf/logging/logsdk/details/loglog.hpp"
#include "asf/logging/logsdk/details/log_level_helper.hpp"

namespace asf {
namespace logging {
namespace logsdk {
namespace details {

namespace {

constexpr const char* kFileLogLevelKey = "FileLogLevel";
constexpr const char* kConsoleLogLevelKey = "ConsoleLogLevel";
constexpr const char* kFlushLevelKey = "FlushLevel";
constexpr const char* kDefaultFlushLevel = cfg::kErrorLogLevelName;
constexpr const char* kDefaultFileLogLevel = cfg::kErrorLogLevelName;
constexpr const char* kDefaultConsoleLogLevel = cfg::kInfoLogLevelName;

} // namespace

class ConfiguratorPrivate
{
public:
    static std::string ReadFile(const std::string& conf_file, bool* is_ok = nullptr);

    ConfiguratorPrivate();

    bool LoadConfiguration(const std::string& conf_file);

    bool LoadConfigurationData(const std::string& conf_data);

    bool IsLoaded() const;

    void CorrectConfiguration();

    bool SaveString(const char* key, const std::string& value, std::string& error_msg);

private:
    void LogParseKeyWarn(const char* key);
    void LogParseKeyError(const char* key);

private:
    static bool ParseJsonString(const rapidjson::Value& json_doc, const char* key, std::string& data);
    static bool ParseJsonSizeT(const rapidjson::Value& json_doc, const char* key, std::size_t& data);
    static bool ParseJsonBool(const rapidjson::Value& json_doc, const char* key, bool& data);

public:
    ConfigurationData data_;
    mutable std::mutex mutex_;
    bool is_loaded_{ false };
    std::string conf_file_name_;
    rapidjson::Document json_doc_;
};

std::string ConfiguratorPrivate::ReadFile(const std::string& conf_file, bool* is_ok)
{
    std::ifstream file(conf_file);
    if (!file.is_open())
    {
        if (is_ok)
        {
            *is_ok = false;
        }
        return std::string();
    }

    std::string data = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    if (is_ok)
    {
        *is_ok = true;
    }

    return data;
}

ConfiguratorPrivate::ConfiguratorPrivate()
{
    json_doc_.SetObject();
}

bool ConfiguratorPrivate::LoadConfiguration(const std::string& conf_file)
{
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (is_loaded_)
        {
            return true;
        }
    }

    // read conf file
    bool read_ok = false;
    std::string conf_data = ReadFile(conf_file, &read_ok);
    if (!read_ok)
    {
        std::string msg = "Can not open config file '" + conf_file + "' : " + std::strerror(errno);
        ASF_LOGSDK_INTERNAL_ERROR(msg);
        return false;
    }

    if (LoadConfigurationData(conf_data))
    {
        std::lock_guard<std::mutex> lock(mutex_);
        conf_file_name_ = conf_file;
        return true;
    }

    return false;
}

bool ConfiguratorPrivate::LoadConfigurationData(const std::string& conf_data)
{
    std::lock_guard<std::mutex> lock(mutex_);

    if (is_loaded_)
    {
        return true;
    }

    // Check json format
    if (json_doc_.Parse(conf_data.c_str()).HasParseError())
    {
        ASF_LOGSDK_INTERNAL_ERROR("Failed to parse configuration data in json format!");
        LogLog::GetInstance().Debug(conf_data);
        return false;
    }

    // parse app id
    const char* key = "AppId";
    if (!ParseJsonString(json_doc_, key, data_.app_id))
    {
        LogParseKeyError(key);
        return false;
    }

    // parse domain id
    key = "DomainId";
    if (!ParseJsonString(json_doc_, key, data_.domain_id))
    {
        LogParseKeyError(key);
        return false;
    }

    key = "DefaultLogger";
    if (!ParseJsonString(json_doc_, key, data_.default_logger_name))
    {
        LogParseKeyWarn(key);
    }

    // parse file log level
    key = kFileLogLevelKey;
    if (!ParseJsonString(json_doc_, key, data_.file_log_level))
    {
        LogParseKeyWarn(key);
        // 尝试解析 "LogLevel"， 向下兼容
        ParseJsonString(json_doc_, "LogLevel", data_.file_log_level);
    }

    // parse console log level
    key = kConsoleLogLevelKey;
    if (!ParseJsonString(json_doc_, key, data_.console_log_level))
    {
        LogParseKeyWarn(key);
        // 尝试解析 "LogLevel"， 向下兼容
        ParseJsonString(json_doc_, "LogLevel", data_.file_log_level);
    }

    // parse flush level
    key = kFlushLevelKey;
    if (!ParseJsonString(json_doc_, key, data_.flush_level))
    {
        LogParseKeyWarn(key);
    }

    // parse log file dir
    key = "LogFileDir";
    if (!ParseJsonString(json_doc_, key, data_.log_file_dir))
    {
        LogParseKeyWarn(key);
    }

    // parse maximum size of log file
    key = "LogFileMaxSize";
    if (!ParseJsonSizeT(json_doc_, key, data_.log_file_max_size))
    {
        LogParseKeyWarn(key);
        ASF_LOGSDK_INTERNAL_DEBUG_ARGS("Set %s to %zd", key, data_.log_file_max_size);
    }

    // parse maximum log files to rotate
    key = "MaxLogFiles";
    if (!ParseJsonSizeT(json_doc_, key, data_.max_log_files))
    {
        LogParseKeyWarn(key);
        ASF_LOGSDK_INTERNAL_DEBUG_ARGS("Set %s to %zd", key, data_.max_log_files);
    }

    // parse compress
    key = "Compress";
    if (!ParseJsonBool(json_doc_, key, data_.compress))
    {
        LogParseKeyWarn(key);
    }

    CorrectConfiguration();
    is_loaded_ = true;
    return true;
}

bool ConfiguratorPrivate::IsLoaded() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return is_loaded_;
}

void ConfiguratorPrivate::CorrectConfiguration()
{
    const std::string app_dir_path = Utils::GetApplicationDirPath();
    auto lmd_replace_str = [](std::string& origin_string, 
                              const std::string& string_need_replace, 
                              const std::string& string_to_replace) {
        std::size_t pos = origin_string.find(string_need_replace);
        if (pos != std::string::npos)
        {
            origin_string.replace(pos, string_need_replace.size(), string_to_replace);
        }
    };

    // app id
    auto lmd_warn_to_update_appid = [this]() {
        ASF_LOGSDK_INTERNAL_WARN(
            "AppId in asf_logsdk configuration file is invalid, update to " + data_.app_id);
    };
    if (data_.app_id.empty() || !Utils::IsFileNameValid(data_.app_id))
    {
        std::string default_app_id = Utils::GetApplicationName();
        if (default_app_id.empty())
        {
            default_app_id = cfg::KDefaultAppId;
        }
        data_.app_id = default_app_id;
        lmd_warn_to_update_appid();
    }
    if (data_.app_id.size() > cfg::kMaxAppIdLength)
    {
        data_.app_id.resize(cfg::kMaxAppIdLength);
        lmd_warn_to_update_appid();
    }

    // domain id
    auto lmd_warn_to_update_domain_id = [this]() {
        ASF_LOGSDK_INTERNAL_WARN(
            "DomainId in asf_logsdk configuration file is invalid, update to " + data_.domain_id);
    };
    if (data_.domain_id.empty())
    {
        data_.domain_id = cfg::KDefaultDomainId;
        lmd_warn_to_update_domain_id();
    }
    else
    {
        if (data_.domain_id.size() > cfg::kMaxDomainIdLength)
        {
            data_.domain_id.resize(cfg::kMaxDomainIdLength);
            lmd_warn_to_update_domain_id();
        }
    }

    // default logger
    auto lmd_warn_to_update_default_logger = [this]() {
        ASF_LOGSDK_INTERNAL_WARN(
            "DefaultLogger in asf_logsdk configuration is invalid, update to " + data_.default_logger_name);
    };
    lmd_replace_str(data_.default_logger_name, cfg::kAppIdIdentifier, data_.app_id);
    if (!Utils::IsFileNameValid(data_.default_logger_name))
    {
        data_.default_logger_name = Utils::GetApplicationName();
        lmd_warn_to_update_default_logger();
    }
    if (data_.default_logger_name.size() > cfg::kMaxLoggerNameLength)
    {
        data_.default_logger_name.resize(cfg::kMaxLoggerNameLength);
        lmd_warn_to_update_default_logger();
    }

    // file log level
    Utils::AsciiToUpper(data_.file_log_level);
    if (!details::LogLevelHelper::IsLevelStringValid(data_.file_log_level))
    {
        data_.file_log_level = kDefaultFileLogLevel;
        ASF_LOGSDK_INTERNAL_WARN(
            "LogLevel in asf_logsdk configuration file is invalid, update to " + data_.file_log_level);
    }

    // console log level
    Utils::AsciiToUpper(data_.console_log_level);
    if (!details::LogLevelHelper::IsLevelStringValid(data_.console_log_level))
    {
        data_.console_log_level = kDefaultConsoleLogLevel;
        ASF_LOGSDK_INTERNAL_WARN(
            "LogLevel in asf_logsdk configuration file is invalid, update to " + data_.console_log_level);
    }

    // flush level
    Utils::AsciiToUpper(data_.flush_level);
    if (!details::LogLevelHelper::IsLevelStringValid(data_.flush_level))
    {
        data_.flush_level = kDefaultFlushLevel;
        ASF_LOGSDK_INTERNAL_WARN(
            "FlushLevel in asf_logsdk configuration file is invalid, update to " + data_.flush_level);
    }

    // log file dir
    lmd_replace_str(data_.log_file_dir, cfg::kAppIdIdentifier, data_.app_id);
    lmd_replace_str(data_.log_file_dir, cfg::kAppDirIdentifier, app_dir_path);
    if (!Utils::IsPathValid(data_.log_file_dir))
    {
        data_.log_file_dir = std::string(cfg::kLogFileDirPrefix) + cfg::kDefaultLogFileDir;
        ASF_LOGSDK_INTERNAL_WARN(
            "LogFileDir in asf_logsdk configuration file is invalid, update to " + data_.log_file_dir);
    }

    // maximum size of log file
    if (data_.log_file_max_size < cfg::kMinSizeOfLogFile || 
        data_.log_file_max_size > cfg::kMaxSizeOfLogFile)
    {
        data_.log_file_max_size = cfg::kDefaultLogFileMaxSize;
        ASF_LOGSDK_INTERNAL_WARN_ARGS("%s %zd", 
            "LogFileMaxSize in asf_logsdk configuration file is invalid, update to ", 
            data_.log_file_max_size);
    }

    // max files
    if (data_.max_log_files == 0)
    {
        data_.max_log_files = cfg::kDefaultMaxLogFiles;
        ASF_LOGSDK_INTERNAL_WARN_ARGS("%s %zd", 
            "MaxFiles in asf_logsdk configuration file is 0, update to ", 
            data_.max_log_files);
    }

    if (data_.max_log_files > cfg::kMaxLogFilesLimit)
    {
        data_.max_log_files = cfg::kMaxLogFilesLimit;
        ASF_LOGSDK_INTERNAL_WARN_ARGS("%s %zd", 
            "MaxFiles in asf_logsdk configuration file is out of range, update to ", 
            data_.max_log_files);
    }
}

bool ConfiguratorPrivate::SaveString(const char* key, const std::string& value, std::string& error_msg)
{
    if (!json_doc_.IsObject())
    {
        error_msg = "The asf_logsdk configuration is not loaded";
        return false;
    }

    if (!json_doc_.HasMember(key))
    {
        error_msg = std::string("No member ") + key + " in config content";
        return false;
    }

    json_doc_[key].SetString(value.data(), value.size(), json_doc_.GetAllocator());

    // If SDK is initialized with conf data, the dont need to save to configuration file.
    if (conf_file_name_.empty())
    {
        ASF_LOGSDK_INTERNAL_DEBUG("Initialized with conf data, skip save level");
        return true;
    }

    std::FILE* fp = std::fopen(conf_file_name_.c_str(), "w");
    if (!fp)
    {
        error_msg = "unable to open file " + conf_file_name_ + " : " + std::strerror(errno);
        return false;
    }

    char write_buffer[1024] = { 0 };
    rapidjson::FileWriteStream os(fp, write_buffer, sizeof(write_buffer));
    rapidjson::PrettyWriter<rapidjson::FileWriteStream> writer(os);
    bool is_write_ok = json_doc_.Accept(writer);
    (void)std::fclose(fp);
    return is_write_ok;
}

void ConfiguratorPrivate::LogParseKeyWarn(const char* key)
{
    LogLog::GetInstance().Warn(std::string(" failed to parse ") + key + " from " + conf_file_name_);
}

void ConfiguratorPrivate::LogParseKeyError(const char* key)
{
    LogLog::GetInstance().Error(std::string(" failed to parse ") + key + " from " + conf_file_name_);
}

bool ConfiguratorPrivate::ParseJsonString(const rapidjson::Value& json_doc, const char* key, std::string& data)
{
    if (!key || !json_doc.HasMember(key))
    {
        return false;
    }

    auto& value = json_doc[key];
    if (value.IsString())
    {
        data = std::string(value.GetString(), value.GetStringLength());
        return true;
    }
    return false;
}

bool ConfiguratorPrivate::ParseJsonSizeT(const rapidjson::Value& json_doc, const char* key, std::size_t& data)
{
    if (!key || !json_doc.HasMember(key))
    {
        return false;
    }

    auto& value = json_doc[key];
    if (value.IsUint64())
    {
        data = value.GetUint64();
        return true;
    }
    return false;
}

bool ConfiguratorPrivate::ParseJsonBool(const rapidjson::Value& json_doc, const char* key, bool& data)
{
    if (!key || !json_doc.HasMember(key))
    {
        return false;
    }

    auto& value = json_doc[key];
    if (value.IsBool())
    {
        data = value.GetBool();
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------

Configurator::Configurator()
    : pri_(new ConfiguratorPrivate())
{
    ASF_LOGSDK_TRACE_ENTRY();
    // set default value
    pri_->data_.app_id = Utils::GetApplicationName();
    pri_->data_.domain_id = cfg::KDefaultDomainId;
    // pri_->data_.dds_conf_file = "";
    pri_->data_.console_log_level = kDefaultConsoleLogLevel;
    pri_->data_.file_log_level = kDefaultFileLogLevel;
    pri_->data_.flush_level = kDefaultFlushLevel;
    pri_->data_.log_file_dir = std::string(cfg::kLogFileDirPrefix) + cfg::kDefaultLogFileDir;
    pri_->data_.log_file_max_size = cfg::kDefaultLogFileMaxSize;
    pri_->data_.max_log_files = cfg::kDefaultMaxLogFiles;
    pri_->data_.compress = false;
    ASF_LOGSDK_TRACE_EXIT();
}

Configurator::~Configurator() 
{
    ASF_LOGSDK_TRACE_EXIT();
}

bool Configurator::LoadConfiguration(const std::string& conf_file)
{
    return pri_->LoadConfiguration(conf_file);
}

bool Configurator::LoadConfigurationData(const std::string& conf_data)
{
    return pri_->LoadConfigurationData(conf_data);
}

bool Configurator::IsLoaded() const
{
    return pri_->IsLoaded();
}

void Configurator::SetAppId(const std::string& app_id)
{
    std::lock_guard<std::mutex> lock(pri_->mutex_);
    pri_->data_.app_id = app_id;
}

bool Configurator::SetFileLogLevel(const std::string& log_level, std::string& error_msg)
{
    std::lock_guard<std::mutex> lock(pri_->mutex_);
    if (!pri_->is_loaded_)
    {
        error_msg = "configuration is not loaded";
        return false;
    }

    if (!pri_->SaveString(kFileLogLevelKey, log_level, error_msg))
    {
        ASF_LOGSDK_INTERNAL_WARN("Failed to save file sink's log level");
        return false;
    }
    pri_->data_.file_log_level = log_level;
    return true;
}

bool Configurator::SetConsoleLogLevel(const std::string& log_level, std::string& error_msg)
{
    std::lock_guard<std::mutex> lock(pri_->mutex_);
    if (!pri_->is_loaded_)
    {
        return false;
    }

    if (!pri_->SaveString(kConsoleLogLevelKey, log_level, error_msg))
    {
        ASF_LOGSDK_INTERNAL_WARN("Failed to save console sink's log level: " + error_msg);
        return false;
    }
    pri_->data_.console_log_level = log_level;
    return true;
}

bool Configurator::SetFlushLevel(const std::string& flush_level)
{
    std::lock_guard<std::mutex> lock(pri_->mutex_);
    if (!pri_->is_loaded_)
    {
        return false;
    }

    std::string error_msg;
    if (!pri_->SaveString(kFlushLevelKey, flush_level, error_msg))
    {
        ASF_LOGSDK_INTERNAL_WARN("Failed to save flush level to configuration file " + error_msg);
        return false;
    }
    pri_->data_.flush_level = flush_level;
    return true;
}

std::string Configurator::GetFileLogLevel() const
{
    std::lock_guard<std::mutex> lock(pri_->mutex_);
    return pri_->data_.file_log_level;
}

std::string Configurator::GetConsoleLogLevel() const
{
    std::lock_guard<std::mutex> lock(pri_->mutex_);
    return pri_->data_.console_log_level;
}

std::string Configurator::GetFlushLevel() const
{
    std::lock_guard<std::mutex> lock(pri_->mutex_);
    return pri_->data_.flush_level;
}

const ConfigurationData& Configurator::GetData() const
{
    return pri_->data_;
}

} // namespace details
} // namespace logsdk
} // namespace logging
} // namespace asf