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
 * Copyright(c) 2019 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef DDSRT_NETSTAT_H
#define DDSRT_NETSTAT_H

#include <stdint.h>

#include "dds/export.h"
#include "dds/config.h"
#include "dds/ddsrt/retcode.h"

#if DDSRT_HAVE_NETSTAT

#if defined(__cplusplus)
extern "C" {
#endif

struct ddsrt_netstat {
  uint64_t ipkt;
  uint64_t opkt;
  uint64_t ibytes;
  uint64_t obytes;
};

/**
 * @brief Platform dependent control structure for network statistics
 */
struct ddsrt_netstat_control;

/**
 * @brief Prepare for gathering network statistics for specified interface.
 */
DDS_EXPORT dds_return_t
ddsrt_netstat_new (
  struct ddsrt_netstat_control **control,
  const char *device);

/**
 * @brief Release resources for gathering network statistics.
 */
DDS_EXPORT dds_return_t
ddsrt_netstat_free (
  struct ddsrt_netstat_control *control);

/**
 * @brief Get network statistics.
 */
DDS_EXPORT dds_return_t
ddsrt_netstat_get (
  struct ddsrt_netstat_control *control,
  struct ddsrt_netstat *stats);

#if defined(__cplusplus)
}
#endif

#endif /* DDSRT_HAVE_NETSTAT */

#endif /* DDSRT_NETSTAT_H */
