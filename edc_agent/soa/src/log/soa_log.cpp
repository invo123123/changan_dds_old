#include "changan/soa_log.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//TRACE/DEBUG/INFO/WARN/ERROR/FATAL/OFF
T_logLevel g_logLevel[] = {
        {0,"TRACE"},
        {1,"DEBUG"},
        {2,"INFO"},
        {3,"WARN"},
        {4,"ERROR"},
        {5,"FATAL"},
        {6,"OFF"},
};


void Soa_log::const_log_json_config()
{
    this->log_config_json = "{" + this->AppId_key           + ":" + this->AppId_value           + "," +
                         this->DomainId_key        + ":" + this->DomainId_value        + "," +
                         this->DefaultLogger_key   + ":" + this->DefaultLogger_value   + "," +
                         this->ConsoleLogLevel_key + ":" + this->ConsoleLogLevel_value + "," +
                         this->FileLogLevel_key    + ":" + this->FileLogLevel_value    + "," +
                         this->FlushLevel_key      + ":" + this->FlushLevel_value      + "," +
                         this->LogFileDir_key      + ":" + this->LogFileDir_value      + "," +
                         this->LogFileMaxSize_key  + ":" + std::to_string(this->LogFileMaxSize_value) + "," +
                         this->MaxLogFiles_key     + ":" + std::to_string(this->MaxLogFiles_value) + "," +
                         this->Compress_key        + ":" + this->Compress_value        + "}";
    return;
}


Soa_log::Soa_log()
{

}

Soa_log::~Soa_log()
{

}

Soa_log &Soa_log::Instance()
{
    static Soa_log m_pSoaLog;
    return m_pSoaLog;
}

bool Soa_log::init_soaLog()
{
    std::lock_guard<std::mutex> guard(init_mutex);
    if(this->init_flag)
    {
        printf("client soa_log is exist\n");
	    return true;
	}
    std::string config_json;
    this->const_log_json_config();
    config_json = this->get_log_json_config();
    printf("config_json is %s\n",config_json.c_str());
    //if (!asf::logging::logsdk::Initializer::DoInitialize("../etc/asf_logsdk.conf"))
    if (!asf::logging::logsdk::Initializer::DoInitializeWithConfData(config_json))
    {
        std::cerr << "Initialize the asf_logsdk failed" << std::endl;
        return false;
    }
    this->init_flag = true;
	return true;
}

void Soa_log::set_FileLogLevel(int logLevel)
{
    char content[MAX_LOG_LEVEL_LEN] = {0};
    for(unsigned int i =0; i<sizeof(g_logLevel)/sizeof(g_logLevel[0]); i++)
    {
        if(g_logLevel[i].soa_log_level== logLevel)
        {
            //this->FileLogLevel_value = std::string("\"") + g_logLevel[i].str_log_level + "\"";
            snprintf(content,sizeof(content),"\"%s\"",g_logLevel[i].str_log_level);
            this->FileLogLevel_value = content;
            break;
        }
    }
    return;
}

std::string Soa_log::get_log_json_config() 
{
	return this->log_config_json;
}

std::string Soa_log::get_FileLogLevel()
{
    return this->FileLogLevel_value;
}

int Soa_log::modify_soalog_config(char *logLevel, char *logDir)
{
    char content[MAX_LOG_LEVEL_LEN] = {0};
    std::string config_json;
    if(logLevel != NULL && strlen(logLevel)!=0)
    {
        //printf("logLevel is [%s]\n",logLevel);
        snprintf(content,sizeof(content),"\"%s\"",logLevel);
        this->FileLogLevel_value = content;
    }
    if(logDir != NULL && strlen(logDir)!=0)
    {
        //printf("logDir is [%s]\n",logDir);
        snprintf(content,sizeof(content),"\"%s\"",logDir);
        this->LogFileDir_value = content;
    }
    this->const_log_json_config();
    config_json =this->get_log_json_config();
    printf("config_json is %s\n",config_json.c_str());
    //没有配置项改变，则不初始化日志
    if(strlen(logLevel)!=0 || strlen(logDir)!=0)
    {
        ASF_LOG_INFO_ARGS("start Initialize the asf_logsdk");
        asf::logging::logsdk::Initializer::Shutdown();
        if (!asf::logging::logsdk::Initializer::DoInitializeWithConfData(config_json))
        {
            std::cerr << "Initialize the asf_logsdk failed" << std::endl;
        }
    }
	return 0;
}

int Soa_log::modify_soalog_level(int logLevel)
{
	printf("modify_soalog_level logLevel[%d]\n",logLevel);
    auto level = static_cast<asf::logging::logsdk::LogLevel>(logLevel);
    asf::logging::logsdk::Logger::GetDefault().SetFileLogLevel(level);
	return 0;
}