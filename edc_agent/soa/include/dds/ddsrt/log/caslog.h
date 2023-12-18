/*
 * caslog.h
 *
 *  Created on: Jan 28, 2022
 *      Author: changan
 */

#ifndef COMMON_CASLOG_H_
#define COMMON_CASLOG_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/slog.h>
#include <sys/slogcodes.h>
#include <unistd.h>
#define LOG_MAJOR_ID 1234
#define LOG_PREFIX "DDS"
typedef enum
{
    LOG_SHT = 0, //log shutdown  the highest level
    LOG_CRI = 1, //log critical
    LOG_ERR = 2, //log err
    LOG_WAR = 3, //log warning
    LOG_NOT = 4, //log notify
    LOG_INF = 5, //log info
    LOG_DBG = 6, //log debug  the lowest level
} LogLevel;  //

static inline void LOGBASE(LogLevel level,const char * pfunc,const char* fmt, ...)
{
    const int kLogBufferSize = 512;
    static unsigned int minor = 0;
    char buffer[kLogBufferSize];
    int n = sprintf(buffer,"%s[%s] -",LOG_PREFIX,pfunc);
    va_list vap;
    va_start(vap, fmt);
    vsnprintf(buffer + n,kLogBufferSize - n, fmt, vap);
    va_end(vap);
    (void)slogf( _SLOG_SETCODE(LOG_MAJOR_ID, minor),level, "%s", buffer);
}
#define LOGSHT(fmt,args...)    LOGBASE(LOG_SHT,__FUNCTION__,fmt,## args)
#define LOGCRI(fmt,args...)    LOGBASE(LOG_CRI,__FUNCTION__,fmt,## args)
#define LOGERR(fmt,args...)    LOGBASE(LOG_ERR,__FUNCTION__,fmt,## args)
#define LOGWAR(fmt,args...)    LOGBASE(LOG_WAR,__FUNCTION__,fmt,## args)
#define LOGNOT(fmt,args...)    LOGBASE(LOG_NOT,__FUNCTION__,fmt,## args)
#define LOGINF(fmt,args...)    LOGBASE(LOG_INF,__FUNCTION__,fmt,## args)
#define LOGDBG(fmt,args...)    LOGBASE(LOG_DBG,__FUNCTION__,fmt,## args)



#endif /* COMMON_CASLOG_H_ */
