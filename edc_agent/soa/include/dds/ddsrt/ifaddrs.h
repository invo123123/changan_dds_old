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
#ifndef DDSRT_IFADDRS_H
#define DDSRT_IFADDRS_H

#include "dds/ddsrt/sockets.h"

#if defined (__cplusplus)
extern "C" {
#endif

enum ddsrt_iftype {
  DDSRT_IFTYPE_UNKNOWN,
  DDSRT_IFTYPE_WIRED,
  DDSRT_IFTYPE_WIFI
};

struct ddsrt_ifaddrs {
  struct ddsrt_ifaddrs *next;
  char *name;
  uint32_t index;
  uint32_t flags;
  enum ddsrt_iftype type;
  struct sockaddr *addr;
  struct sockaddr *netmask;
  struct sockaddr *broadaddr;
};

typedef struct ddsrt_ifaddrs ddsrt_ifaddrs_t;

DDS_EXPORT dds_return_t
ddsrt_getifaddrs(
  ddsrt_ifaddrs_t **ifap,
  const int *afs);

DDS_EXPORT void
ddsrt_freeifaddrs(
  ddsrt_ifaddrs_t *ifa);

DDS_EXPORT dds_return_t
ddsrt_eth_get_mac_addr(
  char *interface_name,
  unsigned char *mac_addr);

#if defined (__cplusplus)
}
#endif

#endif /* DDSRT_IFADDRS_H */
