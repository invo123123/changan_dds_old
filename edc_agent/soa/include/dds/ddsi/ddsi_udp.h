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
#ifndef _DDSI_UDP_H_
#define _DDSI_UDP_H_

#if defined (__cplusplus)
extern "C" {
#endif

typedef struct nn_udpv4mcgen_address {
  /* base IPv4 MC address is ipv4, host bits are bits base .. base+count-1, this machine is bit idx */
  struct in_addr ipv4;
  uint8_t base;
  uint8_t count;
  uint8_t idx; /* must be last: then sorting will put them consecutively */
} nn_udpv4mcgen_address_t;

#if defined(CACFG_DDS_SHOW_BUILD_INFO_SUPPORT)
  extern uint64_t g_recvBuffSzie;
#endif

DDS_EXPORT int ddsi_udp_init (struct ddsi_domaingv *gv);

#if defined (__cplusplus)
}
#endif

#endif
