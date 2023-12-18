// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#ifndef SOA_LOG__H
#define SOA_LOG__H

#include "asf/logging/logsdk.h"
#include <iostream>
#include <memory>
#include <mutex>

#define MAX_LOG_LEVEL_LEN  (128)

typedef struct {
    int         soa_log_level;
    const char *str_log_level;
}T_logLevel;

class Soa_log{
    private:
        Soa_log();
        ~Soa_log();
        Soa_log(Soa_log &) = delete;
        Soa_log& operator=(const Soa_log &) = delete;
        void const_log_json_config();

        bool init_flag = false;
        std::mutex init_mutex;
        const std::string AppId_key = "\"AppId\"";
        std::string AppId_value = "\"LOGM\"";
        const std::string DomainId_key = "\"DomainId\"";
        std::string DomainId_value = "\"ECU1\"";
        const std::string DefaultLogger_key = "\"DefaultLogger\"";
        std::string DefaultLogger_value = "\"\"";
        //TRACE/DEBUG/INFO/WARN/ERROR/FATAL/OFF
        const std::string ConsoleLogLevel_key = "\"ConsoleLogLevel\"";
        std::string ConsoleLogLevel_value = "\"OFF\"";
        const std::string FileLogLevel_key = "\"FileLogLevel\"";
        std::string FileLogLevel_value = "\"OFF\"";
        const std::string FlushLevel_key = "\"FlushLevel\"";
        std::string FlushLevel_value = "\"ERROR\"";
        const std::string LogFileDir_key = "\"LogFileDir\"";
        std::string LogFileDir_value = "\"${AppDir}/log\"";
        const std::string LogFileMaxSize_key = "\"LogFileMaxSize\"";
        int  LogFileMaxSize_value = 20480;
        const std::string MaxLogFiles_key = "\"MaxLogFiles\"";
        int MaxLogFiles_value = 5;
        const std::string Compress_key = "\"Compress\"";
        std::string Compress_value = "false";

        std::string log_config_json;
    public:
        static Soa_log &Instance();
        bool init_soaLog();
        int modify_soalog_config(char *logLevel, char *logDir);
        int modify_soalog_level(int logLevel);
        void set_FileLogLevel(int logLevel);
        std::string get_FileLogLevel();
        std::string get_log_json_config();
};

#endif