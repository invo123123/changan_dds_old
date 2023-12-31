/*
 *  Copyright(c) 2021 to 2023 AutoCore Technology (Nanjing) Co., Ltd. All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without specific prior written
 *    permission.
 */

/*
 * Copyright(c) 2006 to 2018 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */

/** @file
 *
 * @brief DDS C Logging API
 *
 * This header file defines the public API for logging and controlling logging
 * in the DDS C language binding.
 */
#ifndef DDS_LOG_H
#define DDS_LOG_H

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include "dds/export.h"
#include "dds/ddsrt/attributes.h"
#include "dds/ddsrt/process.h"

#if defined(CACFG_DDS_THIRDPARTY_LOG_SUPPORT)
	#if (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
	#include "dds/ddsrt/log/clogger.h"
	#endif

	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
	#include "dds/ddsrt/log/caslog.h"
	#endif

	#if defined(CACFG_COMB_BOARD_AG35)
	#include "dds/ddsrt/log/AL_Log.h"
	#include "dds/ddsrt/log/IL_Log.h"
	#endif
#endif

#if defined (__cplusplus)
extern "C" {
#endif

/** @defgroup log_categories Convenience log category definitions.
 *
 * These defines expand into numeric values that can be ORed together to
 * specify messages of which categories must be passed to the respective sinks.
 *
 * Every category other than DDS_LC_FATAL, DDS_LC_ERROR, DDS_LC_WARNING and
 * DDS_LC_INFO automatically falls into the trace category.
 *
 * @{
 */

#define MAX_LOG_DIR_LEN (256)
#define MAX_LOG_PATH_LEN (512)

/** Fatal error condition. Immediate abort on sink return. */
#define DDS_LC_FATAL (1u)
/** Error condition. */
#define DDS_LC_ERROR (2u)
/** Warning condition. */
#define DDS_LC_WARNING (4u)
/** Informational message. */
#define DDS_LC_INFO (8u)
/** Debug/trace messages related to configuration settings. */
#define DDS_LC_CONFIG (16u)
/** Debug/trace messages related to node discovery. */
#define DDS_LC_DISCOVERY (32u)
/** Currently unused. */
#define DDS_LC_DATA (64u)
/** Debug/trace messages for which no specialized category exists (yet). */
#define DDS_LC_TRACE (128u)
/** Debug/trace messages related to receive administration. */
#define DDS_LC_RADMIN (256u)
/** Debug/trace messages related to timing. */
#define DDS_LC_TIMING (512u)
/** Debug/trace messages related to send administration. */
#define DDS_LC_TRAFFIC (1024u)
/** Currently unused. */
#define DDS_LC_TOPIC (2048u)
/** Debug/trace messages related to TCP communication. */
#define DDS_LC_TCP (4096u)
/** Debug/trace messages related to parameter list processing. */
#define DDS_LC_PLIST (8192u)
/** Debug/trace messages related to the writer history cache. */
#define DDS_LC_WHC (16384u)
/** Debug/trace messages related to throttling. */
#define DDS_LC_THROTTLE (32768u)
/** Reader history cache. */
#define DDS_LC_RHC (65536u)
/** Include content in traces. */
#define DDS_LC_CONTENT (131072u)
/** Debug/trace messages related to SHMEM */
#define DDS_LC_SHM (262144u)
/** Changan Error condition. */
#define DDS_LC_CA_ERROR (524288u)
/** Changan Warning condition. */
#define DDS_LC_CA_WARNING (1048576u)
/** Changan Informational message. */
#define DDS_LC_CA_INFO (2097152u)
/** All common trace categories. */
#define DDS_LC_ALL \
    (DDS_LC_FATAL | DDS_LC_ERROR | DDS_LC_WARNING | DDS_LC_INFO | \
     DDS_LC_CONFIG | DDS_LC_DISCOVERY | DDS_LC_DATA | DDS_LC_TRACE | \
     DDS_LC_TIMING | DDS_LC_TRAFFIC | DDS_LC_TCP | DDS_LC_THROTTLE | \
     DDS_LC_CONTENT | DDS_LC_SHM)
/** @}*/

#define DDS_LOG_MASK \
    (DDS_LC_FATAL | DDS_LC_ERROR | DDS_LC_WARNING | DDS_LC_INFO)

#define DDS_TRACE_MASK \
    (~DDS_LOG_MASK)

#if defined(CACFG_COMB_BOARD_AG35)
    #undef LOG_TAG
    #define LOG_TAG "professional"
#endif

/** Structure with log message and meta data passed to callbacks. */
typedef struct {
  /** Log category the message falls into. */
  uint32_t priority;
  /** Log domain id, UINT32_MAX is global. */
  uint32_t domid;
  /** Filename where message was generated. */
  const char *file;
  /** Line number in file where message was generated. */
  uint32_t line;
  /** Name of function message where message was generated. */
  const char *function;
  /** Log message. */
  const char *message;
  /** Size of log message. */
  size_t size;
  /** Default log message header length */
  size_t hdrsize;
  size_t filesize;
} dds_log_data_t;

/** Function signature that log and trace callbacks must adhere too. */
typedef void (*dds_log_write_fn_t) (void *, const dds_log_data_t *);

/** Semi-opaque type for log/trace configuration. */
struct ddsrt_log_cfg_common {
  /** Mask for testing whether the xLOG macro should forward to the
      function (and so incur the cost of constructing the parameters).
      Messages in DDS_LOG_MASK are rare, so the overhead of calling
      the function and then dropping the message is not an issue, unlike
      for messages in DDS_TRACE_MASK. */
  uint32_t mask;

  /** The actual configured trace mask */
  uint32_t tracemask;

  /** Domain id for reporting; UINT32_MAX = no domain */
  uint32_t domid;

  ddsrt_pid_t pid;

  bool is_stderr;
  char filename[MAX_LOG_PATH_LEN];
  size_t tracefilesize;
  uint32_t max_file_size;
  int max_file_num;
};

typedef struct ddsrt_log_cfg {
  struct ddsrt_log_cfg_common c;
  union {
    dds_log_write_fn_t fnptr;
    void *ptr;
    uint32_t u32;
    unsigned char pad[72];
  } u;
} ddsrt_log_cfg_t;

DDS_EXPORT extern uint32_t *const dds_log_mask;

/**
 * @brief Get currently enabled log and trace categories.
 *
 * @returns A uint32_t with enabled categories set.
 */
DDS_INLINE_EXPORT inline uint32_t
dds_get_log_mask(void)
{
    return *dds_log_mask;
}

/**
 * @brief Set enabled log and trace categories.
 *
 * @param[in]  cats  Log and trace categories to enable.
 */
DDS_EXPORT void
dds_set_log_mask(
    uint32_t cats);

/**
 * @private
 */
DDS_EXPORT void
dds_set_log_file(
    FILE *file);

/**
 * @private
 */
DDS_EXPORT void
dds_set_trace_file(
    FILE *file);

/**
 * @brief Register callback to receive log messages
 *
 * Callbacks registered to handle log messages will receive messages of type
 * info, warning, error and fatal. Messages that fall into the trace category
 * will never be delivered to the callback.
 *
 * This operation is synchronous and only returns once the operation is
 * registered with all threads. Meaning that neither callback or userdata will
 * be referenced by the DDS stack on return.
 *
 * @param[in]  callback  Function pointer matching dds_log_write_fn signature
 *                       or a null pointer to restore the default sink.
 * @param[in]  userdata  User specified data passed along with each invocation
 *                       of callback.
 */
DDS_EXPORT void
dds_set_log_sink(
    dds_log_write_fn_t callback,
    void *userdata);

/**
 * @brief Register callback to receive trace messages
 *
 * Callbacks registered to handle trace messages will receive messages of type
 * info, warning, error and fatal as well as all message types that fall into
 * the trace category depending on the log mask.
 *
 * This operation is synchronous and only returns once the operation is
 * registered with all threads. Meaning that neither callback or
 * userdata will be referenced by the DDS stack on return.
 *
 * @param[in]  callback  Function pointer matching dds_log_write_fn_t signature
 *                       or a null pointer to restore the default sink.
 * @param[in]  userdata  User specified data passed along with each invocation
 *                       of callback.
 */
DDS_EXPORT void
dds_set_trace_sink(
    dds_log_write_fn_t callback,
    void *userdata);

/**
 * @brief Initialize a struct ddsrt_log_cfg for use with dds_log_cfg
 *
 * Callbacks registered to handle log messages will receive messages of type
 * info, warning, error and fatal. Messages that fall into the trace category
 * will never be delivered to the callback.
 *
 * Callbacks registered to handle trace messages will receive messages of type
 * info, warning, error and fatal as well as all message types that fall into
 * the trace category depending on the log mask.
 *
 * This operation is synchronous and only returns once the operation is
 * registered with all threads. Meaning that neither callback or
 * userdata will be referenced by the DDS stack on return.
 *
 * @param[out] cfg            On return, initialised to make dds_log_cfg invoked
 *                            with this config object behave as specified by the
 *                            other parameters.
 * @param[in]  domid          Numerical identifier in log/trace, UINT32_MAX is
 *                            reserved for global logging.
 * @param[in]  tracemask      Mask determining which traces should be written.
 * @param[in]  log_fp         File for default sink.
 * @param[in]  trace_fp       File for default sink.
 */
DDS_EXPORT void
dds_log_cfg_init(
    struct ddsrt_log_cfg *cfg,
    uint32_t domid,
    uint32_t tracemask,
    FILE *log_fp,
    FILE *trace_fp);

/**
 * @brief Write a log or trace message for a specific logging configuraiton
 * (categories, id, sinks).
 *
 * Direct use of #dds_log is discouraged. Use #DDS_CINFO, #DDS_CWARNING,
 * #DDS_CERROR, #DDS_CTRACE or #DDS_CLOG instead.
 */
DDS_EXPORT void
dds_log_cfg(
    const struct ddsrt_log_cfg *cfg,
    uint32_t prio,
    const char *file,
    uint32_t line,
    const char *func,
    const char *fmt,
    ...)
  ddsrt_attribute_format_printf(6, 7);

/**
 * @brief Write a log or trace message to the global configuration but with
 * specific domain (intended solely for use during domain start-up, while
 * the domain-specific logging/tracing hasn't been set yet).
 *
 * Write a log or trace message to one (or both) of the currently active sinks.
 *
 * Direct use of #dds_log_id is discouraged. Use #DDS_ILOG instead.
 */
DDS_EXPORT void
dds_log_id(
    uint32_t prio,
    uint32_t domid,
    const char *file,
    uint32_t line,
    const char *func,
    const char *fmt,
    ...)
  ddsrt_attribute_format_printf(6, 7);

/**
 * @brief Write a log or trace message to the global log/trace.
 *
 * Write a log or trace message to one (or both) of the currently active sinks.
 *
 * Direct use of #dds_log is discouraged. Use #DDS_INFO, #DDS_WARNING,
 * #DDS_ERROR, #DDS_FATAL or #DDS_LOG instead.
 */
DDS_EXPORT void
dds_log(
    uint32_t prio,
    const char *file,
    uint32_t line,
    const char *func,
    const char *fmt,
    ...)
  ddsrt_attribute_format_printf(5, 6);

#if defined(__linux) || defined(__QNXNTO__)
/**
* @brief user stace init
*
* @param log_path  log path, if log_path is null, trace file is created under $HOME/autocore/
* @param is_stderr stderr or file
* @return void
* */
  DDS_EXPORT void 
  dds_user_trace_init(const char* log_path, bool is_stderr);
#endif

/**
 * @brief Set the strings of dds banner extra info.
 *
 * @param[out]  buf      Source buffer of the extra info
 * @param[in]   buflen   The length of the provided buffer (must be > 0).
 *
 * @return void
 */
DDS_EXPORT void dds_banner_set_extra(
    char * buf, 
    size_t buflen);

/**
* @brief print dds banner info to stdout
*
* @param void
* @return void
* */
void dds_banner_print (void);

/**
* @brief print dds banner info to stdout once
*
* @param void
* @return void
* */
void dds_banner_print_once (void);

/**
* @brief log file name end with server ID
* 
* @param serverID 
* @return void 
*/
  DDS_EXPORT void dds_set_logid(uint32_t serverID);

#if defined(CACFG_DDS_THIRDPARTY_LOG_SUPPORT)
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
	LogLevel dds_get_log_level_platform(uint32_t cat);
	#endif

	#if (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
	asf_logsdk_loglevel_t dds_get_log_level_platform(uint32_t cat);
	#endif

	#if defined(CACFG_COMB_BOARD_AG35)
	enum IL_Log_level dds_get_log_level_platform(uint32_t cat);
	#endif
#endif
/**
 * @brief Undecorated function name of the current function.
 *
 * Behavior of DDS_FUNCTION outside a function is undefined. Note that
 * implementations differ across compilers and compiler versions. It might be
 * implemented as either a string literal or a constant variable.
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#   define DDS_FUNCTION __func__
#elif defined(__cplusplus) && (__cplusplus >= 201103)
#   define DDS_FUNCTION __func__
#elif defined(__GNUC__)
#   define DDS_FUNCTION __FUNCTION__
#elif defined(__clang__)
#   define DDS_FUNCTION __FUNCTION__
#elif defined(__ghs__)
#   define DDS_FUNCTION __FUNCTION__
#elif (defined(__SUNPRO_C) || defined(__SUNPRO_CC))
/* Solaris Studio had support for __func__ before it supported __FUNCTION__.
   Compiler flag -features=extensions is required on older versions. */
#   define DDS_FUNCTION __func__
#elif defined(__FUNCTION__)
/* Visual Studio */
#   define DDS_FUNCTION __FUNCTION__
#elif defined(__vxworks)
/* At least versions 2.9.6 and 3.3.4 of the GNU C Preprocessor only define
   __GNUC__ if the entire GNU C compiler is in use. VxWorks 5.5 targets invoke
   the preprocessor separately resulting in __GNUC__ not being defined. */
#   define DDS_FUNCTION __FUNCTION__
#else
#   warning "DDS_FUNCTION is not supported"
#   define DDS_FUNCTION ""
#endif

/**
 * @brief Function signature of the current function.
 *
 * See comments on DDS_FUNCTION for details.
 */
#if defined(__GNUC__)
#   define DDS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif defined(__clang__)
#   define DDS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif defined(__ghs__)
#   define DDS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif (defined(__SUNPRO_C) && __SUNPRO_C >= 0x5100)
/* Solaris Studio supports __PRETTY_FUNCTION__ in C since version 12.1 */
#   define DDS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif (defined(__SUNPRO_CC) && __SUNPRO_CC >= 0x5120)
/* Solaris Studio supports __PRETTY_FUNCTION__ in C++ since version 12.3 */
#   define DDS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif defined(__FUNCSIG__)
/* Visual Studio */
#   define DDS_PRETTY_FUNCTION __FUNCSIG__
#elif defined(__vxworks)
/* See comments on __vxworks macro above. */
#   define DDS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#else
/* Fall back to DDS_FUNCTION. */
#   define DDS_PRETTY_FUNCTION DDS_FUNCTION
#endif

/**
 * @brief Write a log message.
 *
 * Write a log or trace message to the currently active log and/or trace sinks
 * if the log category is enabled. Whether or not the category is enabled is
 * checked before any dds_log-related activities to save a couple of % CPU.
 *
 * Only messages that fall into one of the log categories are passed onto
 * dds_log. While messages that fall into a trace category could have been
 * passed just as easily, they are rejected so that tracing is kept entirely
 * separate from logging, if only cosmetic.
 */
#if defined(CACFG_DDS_THIRDPARTY_LOG_SUPPORT)
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_LOG(cat, ...) \
		((dds_get_log_mask() & (cat)) ? \
		(LOGBASE(dds_get_log_level_platform(cat), DDS_FUNCTION, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0) 
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_LOG(cat, ...) \
		((dds_get_log_mask() & (cat)) ? \
		(asf_clogger_log_default_with_source_loc(dds_get_log_level_platform(cat), __FILE__, __LINE__, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_LOG(cat, ...) \
		((dds_get_log_mask() & (cat)) ? \
		(AL_Log_base(DDS_FUNCTION, dds_get_log_level_platform(cat), LOG_TAG, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0)
	#else
		#define DDS_LOG(cat, ...) \
		((dds_get_log_mask() & (cat)) ? \
		dds_log((cat), __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__) : 0)
	#endif
#else
	#define DDS_LOG(cat, ...) \
		((dds_get_log_mask() & (cat)) ? \
		dds_log((cat), __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__) : 0)
#endif
/**
 * @brief Write a log message with a domain id override.
 *
 * Write a log or trace message to the currently active log and/or trace sinks
 * if the log category is enabled. Whether or not the category is enabled is
 * checked before any dds_log-related activities to save a couple of % CPU.
 *
 * Only messages that fall into one of the log categories are passed onto
 * dds_log. While messages that fall into a trace category could have been
 * passed just as easily, they are rejected so that tracing is kept entirely
 * separate from logging, if only cosmetic.
 */
#if defined(CACFG_DDS_THIRDPARTY_LOG_SUPPORT)
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_ILOG(cat, domid, ...) \
		((dds_get_log_mask() & (cat)) ? \
		(LOGBASE(dds_get_log_level_platform(cat), DDS_FUNCTION, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_ILOG(cat, domid, ...) \
		((dds_get_log_mask() & (cat)) ? \
		(asf_clogger_log_default_with_source_loc(dds_get_log_level_platform(cat), __FILE__, __LINE__, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_ILOG(cat, domid, ...) \
		((dds_get_log_mask() & (cat)) ? \
		(AL_Log_base(DDS_FUNCTION, dds_get_log_level_platform(cat), LOG_TAG, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0)
	#else
		#define DDS_ILOG(cat, domid, ...) \
		((dds_get_log_mask() & (cat)) ? \
		dds_log_id((cat), (domid), __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__) : 0)
	#endif
#else
	#define DDS_ILOG(cat, domid, ...) \
	((dds_get_log_mask() & (cat)) ? \
	dds_log_id((cat), (domid), __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__) : 0)
#endif
/**
 * @brief Write a log message using a specific config.
 *
 * Write a log or trace message to the currently active log and/or trace sinks
 * if the log category is enabled. Whether or not the category is enabled is
 * checked before any dds_log-related activities to save a couple of % CPU.
 *
 * Only messages that fall into one of the log categories are passed onto
 * dds_log. While messages that fall into a trace category could have been
 * passed just as easily, they are rejected so that tracing is kept entirely
 * separate from logging, if only cosmetic.
 */
#if defined(CACFG_DDS_THIRDPARTY_LOG_SUPPORT)
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_CLOG(cat, cfg, ...) \
		(((cfg)->c.mask & (cat)) ? \
		(LOGBASE(dds_get_log_level_platform(cat), DDS_FUNCTION, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_CLOG(cat, cfg, ...) \
		(((cfg)->c.mask & (cat)) ? \
		(asf_clogger_log_default_with_source_loc(dds_get_log_level_platform(cat), __FILE__, __LINE__, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_CLOG(cat, cfg, ...) \
		(((cfg)->c.mask & (cat)) ? \
		(AL_Log_base(DDS_FUNCTION, dds_get_log_level_platform(cat), LOG_TAG, __VA_ARGS__), (cat & DDS_LC_FATAL ? abort() : 0)) : 0)
	#else
		#define DDS_CLOG(cat, cfg, ...) \
		(((cfg)->c.mask & (cat)) ? \
		dds_log_cfg((cfg), (cat), __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__) : 0)
	#endif

	/** Write a log message of type #DDS_LC_TRACE into global log. */
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_TRACE(...) \
		((dds_get_log_mask() & (DDS_LC_TRACE)) ? \
		LOGBASE(LOG_DBG, DDS_FUNCTION, __VA_ARGS__) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_TRACE(...) \
		((dds_get_log_mask() & (DDS_LC_TRACE)) ? \
		asf_log_debug_ex(__VA_ARGS__) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_TRACE(...) \
		((dds_get_log_mask() & (DDS_LC_TRACE)) ? \
		LOGD(__VA_ARGS__) : 0)
	#else
		#define DDS_TRACE(...) \
		dds_log(DDS_LC_TRACE, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif

	/** Write a log message of type #DDS_LC_INFO into global log. */
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_INFO(...) \
		((dds_get_log_mask() & (DDS_LC_INFO)) ? \
		LOGBASE(LOG_INF, DDS_FUNCTION, __VA_ARGS__) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_INFO(...) \
		((dds_get_log_mask() & (DDS_LC_INFO)) ? \
		asf_log_info_ex(__VA_ARGS__) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_INFO(...) \
		((dds_get_log_mask() & (DDS_LC_INFO)) ? \
		LOGI(__VA_ARGS__) : 0)
	#else
		#define DDS_INFO(...) \
		dds_log(DDS_LC_INFO, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif

	/** Write a log message of type #DDS_LC_WARNING into global log. */
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_WARNING(...) \
		((dds_get_log_mask() & (DDS_LC_WARNING)) ? \
		LOGBASE(LOG_WAR, DDS_FUNCTION, __VA_ARGS__) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_WARNING(...) \
		((dds_get_log_mask() & (DDS_LC_WARNING)) ? \
		asf_log_warn_ex(__VA_ARGS__) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_WARNING(...) \
		((dds_get_log_mask() & (DDS_LC_WARNING)) ? \
		LOGW(__VA_ARGS__) : 0)
	#else
		#define DDS_WARNING(...) \
		dds_log(DDS_LC_WARNING, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif

	/** Write a log message of type #DDS_LC_ERROR into global log. */
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_ERROR(...) \
		((dds_get_log_mask() & (DDS_LC_ERROR)) ? \
		LOGBASE(LOG_ERR, DDS_FUNCTION, __VA_ARGS__) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_ERROR(...) \
		((dds_get_log_mask() & (DDS_LC_ERROR)) ? \
		asf_log_error_ex(__VA_ARGS__) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_ERROR(...) \
		((dds_get_log_mask() & (DDS_LC_ERROR)) ? \
		LOGE(__VA_ARGS__) : 0)
	#else
		#define DDS_ERROR(...) \
		dds_log(DDS_LC_ERROR, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif

	/** Write a log message of type #DDS_LC_ERROR into global log and abort. */
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_FATAL(...) \
		((dds_get_log_mask() & (DDS_LC_FATAL)) ? \
		(LOGBASE(LOG_CRI, DDS_FUNCTION, __VA_ARGS__), abort()) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_FATAL(...) \
		((dds_get_log_mask() & (DDS_LC_FATAL)) ? \
		(asf_log_fatal_ex(__VA_ARGS__), abort()) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_FATAL(...) \
		((dds_get_log_mask() & (DDS_LC_FATAL)) ? \
		(LOGE(__VA_ARGS__), abort()) : 0)
	#else
		#define DDS_FATAL(...) \
		dds_log(DDS_LC_FATAL, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif

	/** Write a log message of type #DDS_LC_DATA into global log. */ 
	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_DATA(...) \
		((dds_get_log_mask() & (DDS_LC_DATA)) ? \
		LOGBASE(LOG_INF, DDS_FUNCTION, __VA_ARGS__) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_DATA(...) \
		((dds_get_log_mask() & (DDS_LC_DATA)) ? \
		asf_log_info_ex(__VA_ARGS__) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_DATA(...) \
		((dds_get_log_mask() & (DDS_LC_DATA)) ? \
		LOGI(__VA_ARGS__) : 0)
	#else
		#define DDS_DATA(...) \
		dds_log(DDS_LC_DATA, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif

	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_CA_ERROR(...) \
		((dds_get_log_mask() & (DDS_LC_CA_ERROR)) ? \
		LOGBASE(LOG_DBG, DDS_FUNCTION, __VA_ARGS__) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_CA_ERROR(...) \
		((dds_get_log_mask() & (DDS_LC_CA_ERROR)) ? \
		asf_log_debug_ex(__VA_ARGS__) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_CA_ERROR(...) \
		((dds_get_log_mask() & (DDS_LC_CA_ERROR)) ? \
		LOGD(__VA_ARGS__) : 0)
	#else
		#define DDS_CA_ERROR(...) \
		dds_log(DDS_LC_CA_ERROR, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif

	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_CA_WARNING(...) \
		((dds_get_log_mask() & (DDS_LC_CA_WARNING)) ? \
		LOGBASE(LOG_DBG, DDS_FUNCTION, __VA_ARGS__) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_CA_WARNING(...) \
		((dds_get_log_mask() & (DDS_LC_CA_WARNING)) ? \
		asf_log_debug_ex(__VA_ARGS__) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_CA_WARNING(...) \
		((dds_get_log_mask() & (DDS_LC_CA_WARNING)) ? \
		LOGD(__VA_ARGS__) : 0)
	#else
		#define DDS_CA_WARNING(...) \
		dds_log(DDS_LC_CA_WARNING, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif

	#if defined(CACFG_COMB_BOARD_EDC_QNX700)
		#define DDS_CA_INFO(...) \
		((dds_get_log_mask() & (DDS_LC_CA_INFO)) ? \
		LOGBASE(LOG_DBG, DDS_FUNCTION, __VA_ARGS__) : 0)
	#elif (defined(CACFG_COMB_BOARD_ORIN_LINUX) || defined(CACFG_COMB_BOARD_ANDROID8155))
		#define DDS_CA_INFO(...) \
		((dds_get_log_mask() & (DDS_LC_CA_INFO)) ? \
		asf_log_debug_ex(__VA_ARGS__) : 0)
	#elif defined(CACFG_COMB_BOARD_AG35)
		#define DDS_CA_INFO(...) \
		((dds_get_log_mask() & (DDS_LC_CA_INFO)) ? \
		LOGD(__VA_ARGS__) : 0)
	#else
		#define DDS_CA_INFO(...) \
		dds_log(DDS_LC_CA_INFO, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
	#endif
#else
	#define DDS_CLOG(cat, cfg, ...) \
	(((cfg)->c.mask & (cat)) ? \
	dds_log_cfg((cfg), (cat), __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__) : 0)

	#define DDS_TRACE(...) \
	dds_log(DDS_LC_TRACE, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)

	#define DDS_INFO(...) \
	dds_log(DDS_LC_INFO, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)

	#define DDS_WARNING(...) \
	dds_log(DDS_LC_WARNING, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)	

	#define DDS_ERROR(...) \
	dds_log(DDS_LC_ERROR, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)

	#define DDS_FATAL(...) \
	dds_log(DDS_LC_FATAL, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)

	#define DDS_DATA(...) \
	dds_log(DDS_LC_DATA, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)

	#define DDS_CA_ERROR(...) \
	dds_log(DDS_LC_CA_ERROR, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)

	#define DDS_CA_WARNING(...) \
	dds_log(DDS_LC_CA_WARNING, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)

	#define DDS_CA_INFO(...) \
	dds_log(DDS_LC_CA_INFO, __FILE__, __LINE__, DDS_FUNCTION, __VA_ARGS__)
#endif

/* MSVC mishandles __VA_ARGS__ while claiming to be conforming -- and even
   if they have a defensible implement, they still differ from every other
   compiler out there.  An extra layer of macro expansion works around it. */
#define DDS_CLOG_MSVC_WORKAROUND(x) x

/** Write a log message of type #DDS_LC_INFO using specific logging config. */
#define DDS_CINFO(...) \
  DDS_CLOG_MSVC_WORKAROUND(DDS_CLOG(DDS_LC_INFO, __VA_ARGS__))
/** Write a log message of type #DDS_LC_WARNING using specific logging config. */
#define DDS_CWARNING(...) \
  DDS_CLOG_MSVC_WORKAROUND(DDS_CLOG(DDS_LC_WARNING, __VA_ARGS__))
/** Write a log message of type #DDS_LC_ERROR using specific logging config. */
#define DDS_CERROR(...) \
  DDS_CLOG_MSVC_WORKAROUND(DDS_CLOG(DDS_LC_ERROR, __VA_ARGS__))
/** Write a #DDS_LC_TRACE message using specific logging config. */
#define DDS_CTRACE(...) \
  DDS_CLOG_MSVC_WORKAROUND(DDS_CLOG(DDS_LC_TRACE, __VA_ARGS__))
/** Write a log message of type #DDS_LC_DATA using specific logging config. */
#define DDS_CDATA(...) \
  DDS_CLOG_MSVC_WORKAROUND(DDS_CLOG(DDS_LC_DATA, __VA_ARGS__))
#if defined (__cplusplus)
}
#endif

#endif /* DDS_LOG_H */
