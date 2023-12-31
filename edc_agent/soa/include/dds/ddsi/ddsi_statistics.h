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
#ifndef _DDSI_STATISTICS_H_
#define _DDSI_STATISTICS_H_

#include <stdint.h>

#if defined (__cplusplus)
extern "C" {
#endif

struct reader;
struct writer;

void ddsi_get_writer_stats (struct writer *wr, uint64_t * __restrict rexmit_bytes, uint32_t * __restrict throttle_count, uint64_t * __restrict time_throttled, uint64_t * __restrict time_retransmit);
void ddsi_get_reader_stats (struct reader *rd, uint64_t * __restrict discarded_bytes);

#if defined (__cplusplus)
}
#endif
#endif
