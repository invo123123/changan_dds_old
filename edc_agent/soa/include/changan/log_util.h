#ifdef PLATFORM_ANDROID
#include <android/log.h>
#define LOG_TAG "ds-cm-tool"
#define log_info(fmt, ...)  ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##__VA_ARGS__))
#define log_warn(fmt, ...)  ((void)__android_log_print(ANDROID_LOG_WARN, LOG_TAG, fmt, ##__VA_ARGS__))
#define log_error(fmt, ...) ((void)__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##__VA_ARGS__))
#define log_debug(fmt, ...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##__VA_ARGS__))
#else
#include <stdio.h>
#define LOG_TAG "ds-cm-tool"
#define log_info(fmt, ...)  printf("[%s] [INFO] "#fmt"\n",  LOG_TAG, ##__VA_ARGS__)
#define log_warn(fmt, ...)  printf("[%s] [WARN] "#fmt"\n",  LOG_TAG, ##__VA_ARGS__)
#define log_error(fmt, ...) printf("[%s] [ERROR] "#fmt"\n", LOG_TAG, ##__VA_ARGS__)
#define log_debug(fmt, ...) printf("[%s] [DEBUG] "#fmt"\n", LOG_TAG, ##__VA_ARGS__)
#endif