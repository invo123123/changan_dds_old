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
 * Copyright(c) 2020 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef DDSRT_SCHED_H
#define DDSRT_SCHED_H

#if defined (__cplusplus)
extern "C" {
#endif

/**
 * @brief Thread scheduling classes
 * @{
 */
typedef enum {
  /** Schedule processes and threads according a platform default.
   *  DDSRT_SCHED_REALTIME for timesharing platforms and
   *  DDSRT_SCHED_TIMESHARE for realtime platforms
   */
  DDSRT_SCHED_DEFAULT,
  /** Schedule processes and threads on realtime basis,
   *  on most platforms implying:
   *  - Fixed Priority
   *  - Preemption
   *  - Either "First In First Out" or "Round Robin"
   */
  DDSRT_SCHED_REALTIME,
  /** Schedule processes and threads on timesharing basis,
    *  on most platforms implying:
    *  - Dynamic Priority to guarantee fair share
    *  - Preemption
    */
  DDSRT_SCHED_TIMESHARE
} ddsrt_sched_t;
/** @} */

#if defined (__cplusplus)
}
#endif

#endif /* DDSRT_SCHED_H */
