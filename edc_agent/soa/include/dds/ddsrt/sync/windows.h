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
#ifndef DDSRT_WINDOWS_SYNC_H
#define DDSRT_WINDOWS_SYNC_H

#if defined (__cplusplus)
extern "C" {
#endif

typedef struct {
    CONDITION_VARIABLE cond;
} ddsrt_cond_t;

typedef struct {
    SRWLOCK lock;
} ddsrt_mutex_t;

typedef struct os_rwlock {
    SRWLOCK lock;
    int state; /* -1: exclusive, 0: free, 1: shared */
} ddsrt_rwlock_t;

typedef INIT_ONCE ddsrt_once_t;
#define DDSRT_ONCE_INIT INIT_ONCE_STATIC_INIT

#if defined (__cplusplus)
}
#endif

#endif /* DDSRT_WINDOWS_SYNC_H */
