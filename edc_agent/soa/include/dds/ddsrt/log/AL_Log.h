#ifndef __AL_LOG_H__
#define __AL_LOG_H__


#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include "dds/ddsrt/log/IL_Log.h"

/*
 * Logging option flags	(One-hot encoded)
 */
enum al_log_options {
	LOG_OPT_NONE		= 0x0000,
	LOG_OPT_CONSOLE_OUT	= 0x0001,
	LOG_OPT_TIMESTAMPS	= 0x0002,
	LOG_OPT_FUNC_NAMES	= 0x0004,
	LOG_OPT_NO_SYSLOG	= 0x0008,
	LOG_OPT_DEBUG		= 0x0010
};


/*
 * Log interface macros
 */
#undef LOGI
#undef LOGD
#undef LOGW
#undef LOGE
#undef LOGTI
#undef LOGTD
#undef LOGTW
#undef LOGTE
#define AL_Log_base(func, level, tag,fmt, ...)	IL_Log_Base_Subsystem(func,	level,	tag,  fmt, ##__VA_ARGS__)
#define LOGI(fmt, ...)          AL_Log_base(__func__,	LOG_IL_INFO,	LOG_TAG,    fmt, ##__VA_ARGS__)
#define LOGD(fmt, ...)          AL_Log_base(__func__,	LOG_IL_DEBUG,	LOG_TAG,    fmt, ##__VA_ARGS__)
#define LOGW(fmt, ...)          AL_Log_base(__func__,	LOG_IL_WARN,	LOG_TAG,    fmt, ##__VA_ARGS__)
#define LOGE(fmt, ...)          AL_Log_base(__func__,	LOG_IL_ERR,	LOG_TAG,    fmt, ##__VA_ARGS__)

#define LOGTI(tag,fmt, ...)     AL_Log_base(__func__,	LOG_IL_INFO,	tag,        fmt, ##__VA_ARGS__)
#define LOGTD(tag,fmt, ...)     AL_Log_base(__func__,	LOG_IL_DEBUG,	tag,        mt, ##__VA_ARGS__)
#define LOGTW(tag,fmt, ...)     AL_Log_base(__func__,	LOG_IL_WARN,	tag,        fmt, ##__VA_ARGS__)
#define LOGTE(tag,fmt, ...)     AL_Log_base(__func__,	LOG_IL_ERR,	tag,        fmt, ##__VA_ARGS__)

/*
 * Initialize logging and set options.
 * If no options required, set options to LOG_OPT_NONE
 */
void AL_Log_init(unsigned options);

/*
 * Enable one or more log options
 */
void AL_Log_set_options(unsigned options);

/*
 * Disable one or more log options
 */
void AL_Log_clear_options(unsigned options);


/*
 * Return 1 if debug logging is enabled, otherwise 0.
 */
uint8_t AL_Log_debug_enabled(void);
int32_t AL_Log_signal(uint32_t sig_num, void *sig_info, void *sig_ptr);

int32_t AL_Log_backtrace(void);

/**
 * @brief generate network config file to oemlog/log
 *
 * @param void
 * 
 * @return 
 *   On success, 0 is returned.  On error, -1 is returned. 
 * 
 * @Owner		: Paul
 * @Date&Time	: 2019-09-23	2:06:10 PM
 */
int32_t AL_Log_netconfig_generate(void);


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
 *
 * @Owner		: zengdecai
 * @Date&Time	: 2022-05-10	10:20:10 AM
 */
int32_t AL_Log_FileSet(
                const char *file_path,
                int file_maxsize,
                int file_num,
                const char *log_tag,
                enum al_log_options loglevel
                );

#ifdef __cplusplus
}
#endif


#endif /*  __AL_LOG_H__ */
