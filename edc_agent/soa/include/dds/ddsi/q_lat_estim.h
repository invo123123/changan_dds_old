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
#ifndef NN_LAT_ESTIM_H
#define NN_LAT_ESTIM_H

#include "dds/ddsi/q_log.h"

#if defined (__cplusplus)
extern "C" {
#endif

#define NN_LAT_ESTIM_MEDIAN_WINSZ 7

struct nn_lat_estim {
  /* median filtering with a small window in an attempt to remove the
     worst outliers */
  int index;
  float window[NN_LAT_ESTIM_MEDIAN_WINSZ];
  /* simple alpha filtering for smoothing */
  float smoothed;
};

void nn_lat_estim_init (struct nn_lat_estim *le);
void nn_lat_estim_fini (struct nn_lat_estim *le);
void nn_lat_estim_update (struct nn_lat_estim *le, int64_t est);
double nn_lat_estim_current (const struct nn_lat_estim *le);
int nn_lat_estim_log (uint32_t logcat, const struct ddsrt_log_cfg *logcfg, const char *tag, const struct nn_lat_estim *le);

#if defined (__cplusplus)
}
#endif

#endif /* NN_LAT_ESTIM_H */
