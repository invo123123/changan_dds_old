#ifndef __INVO_TIMER_H_
#define __INVO_TIMER_H_

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>


#define clock_s_f(a)     ((a).tv_sec+(a).tv_nsec/1000000000.0)
#define clock_ms_f(a)    ((a).tv_sec*1000.0+(a).tv_nsec/1000000.0)
#define clock_us_f(a)    ((a).tv_sec*1000000.0+(a).tv_nsec/1000.0)
#define clock_s(a)       ((a).tv_sec+((a).tv_nsec+500000000)/1000000000)
#define clock_ms(a)      ((a).tv_sec*1000+((a).tv_nsec+500000)/1000000)
#define clock_us(a)      ((a).tv_sec*1000000+((a).tv_nsec+500)/1000)
// 注意，不要统一转换为 ns 进行计算，因为根据 long 类型精度计算，以 ns 表示的 s 最多只能表示 2s
#define clock_s_diff(a,b)     (((a).tv_sec-(b).tv_sec)+((a).tv_nsec-(b).tv_nsec+((a).tv_nsec>=(b).tv_nsec?500000000:-500000000))/1000000000)
#define clock_ms_diff(a,b)    (((a).tv_sec-(b).tv_sec)*1000+((a).tv_nsec-(b).tv_nsec+((a).tv_nsec>=(b).tv_nsec?500000:-500000))/1000000)
#define clock_us_diff(a,b)    (((a).tv_sec-(b).tv_sec)*1000000+((a).tv_nsec-(b).tv_nsec+((a).tv_nsec>=(b).tv_nsec?500:-500))/1000)


#define TIME_DEBUG      1
#if TIME_DEBUG
#define TIMER_COUNT_BEGIN(SUFFIX)                                         \
        struct timespec timer_begin_##SUFFIX, timer_end_##SUFFIX;         \
        clock_gettime(CLOCK_MONOTONIC, &timer_begin_##SUFFIX);            \
        clock_gettime(CLOCK_MONOTONIC, &timer_end_##SUFFIX);

#define TIMER_COUNT_END(FUNC,INTER,SUFFIX)                                                                      \
        int timer_inter_##SUFFIX = 0;                                                                           \
        clock_gettime(CLOCK_MONOTONIC, &timer_end_##SUFFIX);                                                    \
        if ((timer_inter_##SUFFIX = clock_ms_diff(timer_end_##SUFFIX, timer_begin_##SUFFIX)) > INTER)           \
            printf("%s timeout, inter(%d)ms\n", #FUNC, timer_inter_##SUFFIX);
#else
#define TIMER_COUNT_BEGIN(SUFFIX)
#define TIMER_COUNT_END(FUNC,INTER,SUFFIX)
#endif

#endif

