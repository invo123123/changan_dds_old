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
#ifndef NN_LOG_H
#define NN_LOG_H

#include <stdarg.h>

#include "dds/ddsrt/log.h"
#include "dds/ddsi/ddsi_time.h"
#include "dds/ddsrt/rusage.h"

#if defined (__cplusplus)
extern "C" {
#endif

#define GVTRACE(...)        DDS_CTRACE (&gv->logconfig, __VA_ARGS__)
#define GVLOG(cat, ...)     DDS_CLOG ((cat), &gv->logconfig, __VA_ARGS__)
#define GVWARNING(...)      DDS_CLOG (DDS_LC_WARNING, &gv->logconfig, __VA_ARGS__)
#define GVERROR(...)        DDS_CLOG (DDS_LC_ERROR, &gv->logconfig, __VA_ARGS__)
#define GVDATA(...)         DDS_CLOG (DDS_LC_DATA, &gv->logconfig, __VA_ARGS__)

#define RSTTRACE(...)       DDS_CTRACE (&rst->gv->logconfig, __VA_ARGS__)

#define ETRACE(e_, ...)     DDS_CTRACE (&(e_)->e.gv->logconfig, __VA_ARGS__)
#define EETRACE(e_, ...)    DDS_CTRACE (&(e_)->gv->logconfig, __VA_ARGS__)
#define ELOG(cat, e_, ...)  DDS_CLOG ((cat), &(e_)->e.gv->logconfig, __VA_ARGS__)
#define EELOG(cat, e_, ...) DDS_CLOG ((cat), &(e_)->gv->logconfig, __VA_ARGS__)

/* There are quite a few places where discovery-related things are logged, so abbreviate those
   a bit */
#define GVLOGDISC(...)      DDS_CLOG (DDS_LC_DISCOVERY, &gv->logconfig, __VA_ARGS__)
#define ELOGDISC(e_,...)    DDS_CLOG (DDS_LC_DISCOVERY, &(e_)->e.gv->logconfig, __VA_ARGS__)
#define EELOGDISC(e_, ...)  DDS_CLOG (DDS_LC_DISCOVERY, &(e_)->gv->logconfig, __VA_ARGS__)

/* LOG_THREAD_CPUTIME must be considered private. */
#if DDSRT_HAVE_RUSAGE
#define LOG_THREAD_CPUTIME(logcfg, guard)                                \
    do {                                                                 \
        if ((logcfg)->c.mask & DDS_LC_TIMING) {                          \
            ddsrt_mtime_t tnowlt = ddsrt_time_monotonic ();              \
            if (tnowlt.v >= (guard).v) {                                 \
                ddsrt_rusage_t usage;                                    \
                if (ddsrt_getrusage(DDSRT_RUSAGE_THREAD, &usage) == 0) { \
                    DDS_CLOG(                                            \
                        DDS_LC_TIMING,                                   \
                        (logcfg),                                        \
                        "thread_cputime %d.%09d\n",                      \
                        (int)(usage.stime / DDS_NSECS_IN_SEC),           \
                        (int)(usage.stime % DDS_NSECS_IN_SEC));          \
                    (guard).v = tnowlt.v + DDS_NSECS_IN_SEC;             \
                }                                                        \
            }                                                            \
        }                                                                \
    } while (0)
#else
#define LOG_THREAD_CPUTIME(logcfg, guard) (void)(guard)
#endif /* DDSRT_HAVE_RUSAGE */

#if defined (__cplusplus)
}
#endif

#endif /* NN_LOG_H */
