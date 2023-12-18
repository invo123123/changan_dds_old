/**
 * Copyright (c) 2022 Quectel Wireless Solution, Co., Ltd. All Rights Reserved.
 * Quectel Wireless Solution Proprietary and Confidential.
 * 
 * @file    IL_Log.h
 * @brief   IL_Log API header
 */ 
#ifndef __IL_LOG_H__
#define __IL_LOG_H__
/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <qlsyslog/ql_sys_log.h>

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
 *    MICRO DEFINITIONS
 ******************************************************************************/

#define LOG_BUFFER_ID               0
#define LOG_MAX_ID_SIZE             (64)    /* max chars allowed in ID string */
#define LOG_MAX_FMT_STR_SIZE        (1024)  /* reasonable format string limit */
// #define LOG_MAX_FMT_STR_SIZE     (244)   /* reasonable format string limit */
#define LOG_MIN_TIMESTAMP_SIZE      (24)    /* min buffer size for timestamp  */

/*
 * extended log messages use the following facility:
 */
//#define IL_SYSLOG_FACILITY    LOG_LOCAL0

/*
 * Convenient macros to generate enums, string tables, and name_val tables
 * from a single token definition list.
 *
 * Item definitions are in the form:
 *   <template>(<string-name>, <enum-name>)
 * For example:
 *   #define SAMPLE_ITEMS(def)        \
 *     def(first,    FIRST_ITEM)    \
 *     def(second,    SECOND_ITEM)    \
 *     def(last,    LAST_ITEM)
 */
#ifndef name_val
struct name_val 
{
    const char *name;
    int val;
};
#endif

/* create enum entry */
#define DEF_ENUM_ENTRY(str_name, enum_name)    enum_name,
/* create name table entry */
#define DEF_NAME_ENTRY(str_name, enum_name)    #str_name,
/* create name_val table entry */
#define DEF_NAMEVAL_ENTRY(str_name, enum_name)    { #str_name, enum_name },

/* define enum */
#define DEF_ENUM(enum_type, item_defs) \
    enum enum_type { item_defs(DEF_ENUM_ENTRY) }
/* define string table for string to enum lookups*/
#define DEF_NAME_TABLE(table_name, item_defs) \
    const char * const table_name[] = { item_defs(DEF_NAME_ENTRY) }
/* define string table for string to enum lookups*/
#define DEF_NAMEVAL_TABLE(table_name, item_defs) \
    struct name_val table_name[] = { \
        item_defs(DEF_NAMEVAL_ENTRY) \
        { NULL, -1 } \
    }

/*
 *  Log priority values, in ascending priority order.(wapper ANDROID_LOG_XXX)
 */
#if 0
    typedef enum {
        QL_SYS_LOG_MIN = 0,
        QL_SYS_LOG_DEFAULT,    /* only for SetMinPriority() */
        QL_SYS_LOG_VERBOSE,
        QL_SYS_LOG_DEBUG,
        QL_SYS_LOG_INFO,
        QL_SYS_LOG_WARN,
        QL_SYS_LOG_ERROR,
        QL_SYS_LOG_FATAL,
        QL_SYS_LOG_SILENT,     /* only for SetMinPriority(); must be last */
        QL_SYS_LOG_MAX
    }QL_SYS_LOG_PRIORITY_E;
#endif
//QL_SYS_LOG_PRIORITY_E;
typedef QL_SYS_LOG_PRIORITY_E QL_SYS_LOG_PRIORITY_E;
    
#ifndef QL_API_LOGV
#define QL_API_LOGV(fmt, ...) \
        ql_api_log_print(__FUNCTION__, __LINE__, QL_SYS_LOG_VERBOSE, fmt, ##__VA_ARGS__)
#endif
#ifndef QL_API_LOGD
#define QL_API_LOGD(fmt, ...) \
        ql_api_log_print(__FUNCTION__, __LINE__, QL_SYS_LOG_DEBUG,   fmt, ##__VA_ARGS__)
#endif
#ifndef QL_API_LOGI
#define QL_API_LOGI(fmt, ...) \
        ql_api_log_print(__FUNCTION__, __LINE__, QL_SYS_LOG_INFO,    fmt, ##__VA_ARGS__)
#endif
#ifndef QL_API_LOGW
#define QL_API_LOGW(fmt, ...) \
        ql_api_log_print(__FUNCTION__, __LINE__, QL_SYS_LOG_WARN,    fmt, ##__VA_ARGS__)
#endif
#ifndef QL_API_LOGE
#define QL_API_LOGE(fmt, ...) \
        ql_api_log_print(__FUNCTION__, __LINE__, QL_SYS_LOG_ERROR,   fmt, ##__VA_ARGS__)
#endif
#ifndef QL_API_LOGF
#define QL_API_LOGF(fmt, ...) \
        ql_api_log_print(__FUNCTION__, __LINE__, QL_SYS_LOG_FATAL,   fmt, ##__VA_ARGS__)
#endif

int ql_api_log_print(const char *func, int line, QL_SYS_LOG_PRIORITY_E level, const char *fmt, ...)
        __attribute__((format(printf, 4, 5)));

/*
 * custom log level definitions. Up to 32 levels supported.
 * Levels are are defined in order from less severe to more severe.
 * Format: def(<string name>, <enum name>)
 */
#define IL_LOG_LEVELS(def)            \
        def(debug,        LOG_IL_MIN)                \
        def(debug,        LOG_IL_DEFAULT)        \
        def(debug,        LOG_IL_VERBOSE)        \
        def(debug,    LOG_IL_DEBUG)        \
        def(info,    LOG_IL_INFO)        \
        def(warning,    LOG_IL_WARN)    \
        def(error,    LOG_IL_ERR)            \
                                        \
        def(NULL,    LOG_IL_NUM_LEVELS)

/*
 * Define  log level enums
 */
DEF_ENUM(IL_Log_level, IL_LOG_LEVELS);


/*******************************************************************************
 *    TYPEDEF TYPES
 ******************************************************************************/
typedef void (*LOG_FUNUC_DEF)(const char *, enum IL_Log_level,const char *,
                                  const char *, va_list);


/*******************************************************************************
 *    GLOBAL VARIABLES DECLARATION
 ******************************************************************************/
enum il_log_options {
    IL_LOG_OPT_NONE                 = 0x0000,
    IL_LOG_OPT_CONSOLE_OUT          = 0x0001,
    IL_LOG_OPT_TIMESTAMPS           = 0x0002,
    IL_LOG_OPT_FUNC_NAMES           = 0x0004,
    IL_LOG_OPT_NO_SYSLOG            = 0x0008,
    IL_LOG_OPT_DEBUG                = 0x0010
};


/*******************************************************************************
 *    GLOBAL FUNCTIONS DECLARATION
 ******************************************************************************/


/*
 * Format and log a message.  Parses an optional
 * embedded in the first byte of the format string
 * Intended to be used by log macros.
 *
 * func - the function name or NULL
 * level - log severity
 * fmt... - format string and optional arguments
 */
/*
 * The same as IL_Log_base().
 *
 * func - the function name or NULL
 * level - log severity
 * fmt... - message format string and argument list
 */
extern void IL_Log_Base_Subsystem(const char *func, enum IL_Log_level level, const char *tag, const char *fmt, ...)
        __attribute__((format(printf, 4, 5)));

/*
 * Hex dump to log message.
 *
 * msg - a tag describing the data (could be the func name)
 * level - log severity
 * buf - data to hex dump
 * len - number of bytes to dump
 */
extern void IL_Log_Base_Hex(const char *func,
    enum IL_Log_level level,
    const char *tag,
    const char *msg,
    const void *buf, size_t len);


/*
 * Initialize logging and set options.
 * If no options required, set options to LOG_OPT_NONE
 */
void IL_Log_Init(unsigned options);

void IL_Log_Set_Options(unsigned options);

void IL_Log_Clear_Options(unsigned options);

uint8_t IL_Log_Debug_Enabled(void);

int32_t IL_Log_Signal(uint32_t sig_num, void *sig_info, void *sig_ptr);

int32_t IL_Log_Backtrace(void);

size_t IL_Log_Get_Timestamp(char *buf, size_t size);

#define LOGD_HEX(msg, buf, len)    IL_Log_Base_Hex(__func__,    LOG_IL_DEBUG, "CaTbox", msg, buf, len)

#define IL_Log_base(func, level, tag, ...)	IL_Log_Base_Subsystem(func,	level,	tag,    __VA_ARGS__)
#define IL_LOGI(...)	IL_Log_base(__func__,	LOG_IL_INFO,	LOG_TAG,	__VA_ARGS__)
#define IL_LOGD(...)	IL_Log_base(__func__,	LOG_IL_DEBUG,	LOG_TAG,	__VA_ARGS__)
#define IL_LOGW(...)	IL_Log_base(__func__,	LOG_IL_WARN,	LOG_TAG,	__VA_ARGS__)
#define IL_LOGE(...)	IL_Log_base(__func__,	LOG_IL_ERR,		LOG_TAG,    __VA_ARGS__)

/**
 * @brief set the log storage file information
 *
 * @param file_path: log file path(include file name)
 * @param file_maxsize: maximum value of a single log file
 * @param file_num: number of log files
 * @param log_tag: log labels that meet storage conditions
 * @param loglevel: log level that meet storage conditions
 *
 * @return
 *   On success, 0 is returned.  On error, -1 is returned.
 */
int32_t IL_Log_File_Set(const char *file_path,int file_maxsize,int file_num, const char *log_tag,int loglevel);

/*
 * Log interface macros
 */
//#define IL_Log_base(func, level, tag, ...) IL_Log_Base_Subsystem(func, level, tag, __VA_ARGS__)
#define LOGI(...) IL_Log_base(__func__, LOG_IL_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...) IL_Log_base(__func__, LOG_IL_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) IL_Log_base(__func__, LOG_IL_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) IL_Log_base(__func__, LOG_IL_ERR,  LOG_TAG, __VA_ARGS__)

#define LOGTI(tag, ...) IL_Log_base(__func__, LOG_IL_INFO, tag, __VA_ARGS__)
#define LOGTD(tag, ...) IL_Log_base(__func__, LOG_IL_DEBUG, tag, __VA_ARGS__)
#define LOGTW(tag, ...) IL_Log_base(__func__, LOG_IL_WARN, tag, __VA_ARGS__)
#define LOGTE(tag, ...) IL_Log_base(__func__, LOG_IL_ERR, tag, __VA_ARGS__)

#ifdef __cplusplus
};
#endif

#endif /*  __IL_LOG_H__ */
