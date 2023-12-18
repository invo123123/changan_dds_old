#ifndef ASF_LOGGING_LOGSDK_CLOGGER_H
#define ASF_LOGGING_LOGSDK_CLOGGER_H

#include <asf/logging/logsdk/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup C-API
 * @{
 */

/**
 * \brief Initialize asf_logsdk.
 * 
 * \param conf_file The asf_logsdk configuration file name in json format.
 * \return 0 Success.
 * \return -1 Failed.
 * 
 * \note Call this method or asf_clogger_initialize_with_conf_data() first before using asf_logsdk.
 */
int asf_clogger_initialize(const char* conf_file) ASF_LOGGING_LOGSDK_ATTR_NODISCARD;

/**
 * \brief Returns '1' if the asf_logsdk is initialized, otherwise returns '0'.
 * \since v1.4.0
 */
int asf_clogger_is_initialized();

/**
 * \brief Initialize asf_logsdk.
 * 
 * \param conf_data The asf_logsdk configuration data in json format.
 * \return 0 Success.
 * \return -1 Failed.
 * 
 * \note Call this method or asf_clogger_initialize() first before using asf_logsdk.
 */
int asf_clogger_initialize_with_conf_data(const char* conf_data) ASF_LOGGING_LOGSDK_ATTR_NODISCARD;

/**
 * \brief Shutdown the asf_logsdk when the SDK no longer used.
 * 
 * \note You can initialize the logsdk agin after shutdown since v1.4.0.
 */
void asf_clogger_shutdown();

/**
 * \brief Returns the global flush log level.
 * \since v1.2.1
 * 
 * If a log's level is greater than the flush level, then flush immediately after logging.
 * 
 * \sa asf_clogger_set_global_flush_level(), asf_clogger_get_flush_level()
 */
asf_logsdk_loglevel_t asf_clogger_global_flush_level();

/**
 * \brief Set global flush log level for asf_logsdk. 
 * \since v1.2.1
 * 
 * This function does not change the flush level of logger that has been created.
 * 
 * By default, the flush log level is \c ASF_LOGSDK_LOGLEVEL_WARN.
 * 
 * \sa asf_clogger_global_flush_level(), asf_clogger_set_flush_level()
 */
int asf_clogger_set_global_flush_level(asf_logsdk_loglevel_t level);

/**
 * \brief Get the flush level of logger which named \a logger_name.
 * \since v1.2.1
 * 
 * If a log's level is greater than the flush level, then flush immediately after logging.
 * 
 * \param logger_name The logger name of asf clogger.
 * 
 * \note If \a logger_name is empty, use logger named application-name; 
 *       If \a logger_name is \c NULL, returns \c ASF_LOGSDK_LOGLEVEL_INVALID.
 * 
 * \sa asf_clogger_set_flush_level(), asf_clogger_global_flush_level()
 */
asf_logsdk_loglevel_t asf_clogger_flush_level(const char* logger_name);

/**
 * \brief Set the flush level for logger which named \a logger_name.
 * \since v1.2.1
 * 
 * \param logger_name The logger name of asf clogger.
 * \param level The global flush level to set.
 * 
 * \note If \a logger_name is empty, use logger named application-name; If \a logger_name is \c NULL, do nothing.
 * 
 * \sa asf_clogger_get_flush_level(), asf_clogger_global_flush_level()
 */
void asf_clogger_set_flush_level(const char* logger_name, asf_logsdk_loglevel_t level);

/**
 * \brief Get the application directory path.
 * 
 * \param dest [out] buffer to store return value, returned value is '\0'-terminated if \a size is greater than zero.
 * \param size The size of \a dest.
 * \param default_app_file_path The default application file path, 
 *                              is usually <code>argv[0]</code> or <code>NULL</code>.
 * 
 * \return The real size of returned path.
 */
int asf_clogger_app_dir_path(char* dest, int size, const char* default_app_file_path);

/**
 * \brief Record a log with given logger name and \a level and default trace id {@link #ASF_LOGSDK_DEFAULT_TRACE_ID}.
 * 
 * \param logger_name The logger name of asf clogger.
 * \param level       Specify this log's level. \see asf_logsdk_loglevel_t
 * \param format      Pointer to a '\0'-terminated multibyte string specifying how to interpret the data.
 * \param ...         Arguments specifying data to format.
 * 
 * \note If \a logger_name is empty, use logger named application-name; If \a logger_name is \c NULL, do nothing.
 * 
 * \sa asf_clogger_log_with_tid()
 */
void asf_clogger_log(const char* logger_name, asf_logsdk_loglevel_t level,
    const char* format, ...) ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(__printf__, 3, 4);

/**
 * \brief Record a log with default logger and \a level and default trace id {@link #ASF_LOGSDK_DEFAULT_TRACE_ID}.
 * \since v1.4.2
 * 
 * \sa asf_clogger_log()
 */
void asf_clogger_log_default(asf_logsdk_loglevel_t level,
    const char* format, ...) ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(__printf__, 2, 3);

/**
 * \brief Record a log with given logger name and \a level and default trace id {@link #ASF_LOGSDK_DEFAULT_TRACE_ID}
 * and source location.
 * 
 * \param logger_name The logger name of asf clogger.
 * \param level       Specify this log's level. \see asf_logsdk_loglevel_t
 * \param file        The name of the source file that calls this function.
 * \param line        The line of the source file that calls this function.
 * \param format      Pointer to a '\0'-terminated multibyte string specifying how to interpret the data.
 * \param ...         Arguments specifying data to format.
 * 
 * \note If \a logger_name is empty, use logger named application-name; If \a logger_name is \c NULL, do nothing.
 * 
 * \sa asf_clogger_log_with_tid()
 */
void asf_clogger_log_with_source_loc(const char* logger_name, asf_logsdk_loglevel_t level, const char* file, 
    uint_least32_t line, const char* format, ...) ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(__printf__, 5, 6);

/**
 * \brief Record a log with default logger name and \a level and default trace id {@link #ASF_LOGSDK_DEFAULT_TRACE_ID}
 * and source location.
 * \since v1.4.2
 * 
 * \sa asf_clogger_log_with_source_loc()
 */
void asf_clogger_log_default_with_source_loc(asf_logsdk_loglevel_t level, const char* file, 
    uint_least32_t line, const char* format, ...) ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(__printf__, 4, 5);

/**
 * \brief Record a log with given logger name and \a level and trace id.
 * 
 * If trace id is \c NULL or empty string, use default value {@link #ASF_LOGSDK_DEFAULT_TRACE_ID}. 
 * 
 * \param logger_name The logger name of asf clogger.
 * \param level       Specify this log's level. \see asf_logsdk_loglevel_t
 * \param trace_id    Specify the trace id.
 * \param format      Pointer to a '\0'-terminated multibyte string specifying how to interpret the data.
 * \param ...         Arguments specifying data to format.
 * 
 * \note If \a logger_name is empty, use logger named application-name; If \a logger_name is \c NULL, do nothing.
 * 
 * \sa asf_clogger_log()
 */
void asf_clogger_log_with_tid(const char* logger_name, asf_logsdk_loglevel_t level,
    const char* trace_id, const char* format, ...) ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(__printf__, 4, 5);

/**
 * \brief Record a log with default logger name and \a level and trace id.
 * \since v1.4.2
 * 
 * \sa asf_clogger_log_with_tid()
 */
void asf_clogger_log_default_with_tid(asf_logsdk_loglevel_t level,
    const char* trace_id, const char* format, ...) ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(__printf__, 3, 4);

/**
 * \brief Record a log with given logger name and \a level and trace id and source location.
 * 
 * If trace id is \c NULL or empty string, use default value {@link #ASF_LOGSDK_DEFAULT_TRACE_ID}. 
 * 
 * \param logger_name The logger name of asf clogger.
 * \param level       Specify this log's level. \see asf_logsdk_loglevel_t
 * \param trace_id    Specify the trace id.
 * \param file        The name of the source file that calls this function.
 * \param line        The line of the source file that calls this function.
 * \param format      Pointer to a '\0'-terminated multibyte string specifying how to interpret the data.
 * \param ...         Arguments specifying data to format.
 * 
 * \note If \a logger_name is empty, use logger named application-name; If \a logger_name is \c NULL, do nothing.
 * 
 * \sa asf_clogger_log()
 */
void asf_clogger_log_with_tid_and_source_loc(const char* logger_name, asf_logsdk_loglevel_t level, 
    const char* trace_id, const char* file, uint_least32_t line, const char* format, ...) 
    ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(__printf__, 6, 7);

/**
 * \brief Record a log with default logger name and \a level and trace id and source location.
 * \since v1.4.2
 * 
 * \sa asf_clogger_log_with_tid_and_source_loc()
 */
void asf_clogger_log_default_with_tid_and_source_loc(asf_logsdk_loglevel_t level, 
    const char* trace_id, const char* file, uint_least32_t line, const char* format, ...) 
    ASF_LOGGING_LOGSDK_FORMAT_ATTRIBUTE(__printf__, 5, 6);

/**
 * \brief Flush the log message for given logger \a logger_name immediately.
 * \since v1.2.1
 * 
 * \note If \a logger_name is empty, use logger named application-name; If \a logger_name is \c NULL, do nothing.
 *
 * \param logger_name The logger name of asf clogger. If \c NULL or empty, use application-name.
 * 
 * \sa asf_clogger_flush_all()
 */
void asf_clogger_flush(const char* logger_name);

/**
 * \brief Flush the log message for default logger immediately.
 * \since v1.4.2
 * 
 * \sa asf_clogger_flush_all()
 */
void asf_clogger_flush_default();

/**
 * \brief Flush all loggers' log message immediately.
 * \since v1.2.1
 * 
 * \sa asf_clogger_flush()
 */
void asf_clogger_flush_all();

#ifdef __cplusplus
} // extern "C"
#endif

/**
 * Record a log with specified level and default trace id {@link #ASF_LOGSDK_DEFAULT_TRACE_ID}.
 */
#define asf_log_log(logger_name, log_level, format, ...) \
    asf_clogger_log_with_source_loc(logger_name, log_level, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define asf_log_trace(logger_name, format, ...)  \
    asf_log_log(logger_name, ASF_LOGSDK_LOGLEVEL_TRACE, format, ##__VA_ARGS__)

#define asf_log_debug(logger_name, format, ...)  \
    asf_log_log(logger_name, ASF_LOGSDK_LOGLEVEL_DEBUG, format, ##__VA_ARGS__)

#define asf_log_info(logger_name, format, ...)  \
    asf_log_log(logger_name, ASF_LOGSDK_LOGLEVEL_INFO, format, ##__VA_ARGS__)

#define asf_log_warn(logger_name, format, ...)  \
    asf_log_log(logger_name, ASF_LOGSDK_LOGLEVEL_WARN, format, ##__VA_ARGS__)

#define asf_log_error(logger_name, format, ...)  \
    asf_log_log(logger_name, ASF_LOGSDK_LOGLEVEL_ERROR, format, ##__VA_ARGS__)

#define asf_log_fatal(logger_name, format, ...)  \
    asf_log_log(logger_name, ASF_LOGSDK_LOGLEVEL_FATAL, format, ##__VA_ARGS__)

/**
 * Record log with default logger name
 */
#define asf_log_log_ex(log_level, format, ...) \
    asf_clogger_log_default_with_source_loc(log_level, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define asf_log_trace_ex(format, ...) \
    asf_log_log_ex(ASF_LOGSDK_LOGLEVEL_TRACE, format, ##__VA_ARGS__)

#define asf_log_debug_ex(format, ...) \
    asf_log_log_ex(ASF_LOGSDK_LOGLEVEL_DEBUG, format, ##__VA_ARGS__)

#define asf_log_info_ex(format, ...) \
    asf_log_log_ex(ASF_LOGSDK_LOGLEVEL_INFO, format, ##__VA_ARGS__)

#define asf_log_warn_ex(format, ...) \
    asf_log_log_ex(ASF_LOGSDK_LOGLEVEL_WARN, format, ##__VA_ARGS__)

#define asf_log_error_ex(format, ...) \
    asf_log_log_ex(ASF_LOGSDK_LOGLEVEL_ERROR, format, ##__VA_ARGS__)

#define asf_log_fatal_ex(format, ...) \
    asf_log_log_ex(ASF_LOGSDK_LOGLEVEL_FATAL, format, ##__VA_ARGS__)

/**
 * Record a log with specified level and given trace id.
 */
#define asf_log_log_with_tid(logger_name, log_level, trace_id, format, ...) \
    asf_clogger_log_with_tid_and_source_loc(logger_name, log_level, trace_id, __FILE__, __LINE__, format, ##__VA_ARGS__)

#define asf_log_trace_with_tid(logger_name, trace_id, format, ...)  \
    asf_log_log_with_tid(logger_name, ASF_LOGSDK_LOGLEVEL_TRACE, trace_id, format, ##__VA_ARGS__)

#define asf_log_debug_with_tid(logger_name, trace_id, format, ...)  \
    asf_log_log_with_tid(logger_name, ASF_LOGSDK_LOGLEVEL_DEBUG, trace_id, format, ##__VA_ARGS__)

#define asf_log_info_with_tid(logger_name, trace_id, format, ...)  \
    asf_log_log_with_tid(logger_name, ASF_LOGSDK_LOGLEVEL_INFO, trace_id, format, ##__VA_ARGS__)

#define asf_log_warn_with_tid(logger_name, trace_id, format, ...)  \
    asf_log_log_with_tid(logger_name, ASF_LOGSDK_LOGLEVEL_WARN, trace_id, format, ##__VA_ARGS__)

#define asf_log_error_with_tid(logger_name, trace_id, format, ...)  \
    asf_log_log_with_tid(logger_name, ASF_LOGSDK_LOGLEVEL_ERROR, trace_id, format, ##__VA_ARGS__)

#define asf_log_fatal_with_tid(logger_name, trace_id, format, ...)  \
    asf_log_log_with_tid(logger_name, ASF_LOGSDK_LOGLEVEL_FATAL, trace_id, format, ##__VA_ARGS__)

/** @} */

#endif // ASF_LOGGING_LOGSDK_CLOGGER_H