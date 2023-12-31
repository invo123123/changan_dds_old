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
#ifndef NN_BSWAP_H
#define NN_BSWAP_H

#include <stdint.h>

#include "dds/ddsrt/bswap.h"
#include "dds/ddsrt/misc.h"
#include "dds/ddsi/q_rtps.h" /* for nn_guid_t, nn_guid_prefix_t */
#include "dds/ddsi/q_protocol.h" /* for nn_sequence_number_t */

#if defined (__cplusplus)
extern "C" {
#endif

inline void bswapSN (nn_sequence_number_t *sn)
{
  sn->high = ddsrt_bswap4 (sn->high);
  sn->low = ddsrt_bswap4u (sn->low);
}

ddsi_guid_prefix_t nn_hton_guid_prefix (ddsi_guid_prefix_t p);
ddsi_guid_prefix_t nn_ntoh_guid_prefix (ddsi_guid_prefix_t p);
ddsi_entityid_t nn_hton_entityid (ddsi_entityid_t e);
ddsi_entityid_t nn_ntoh_entityid (ddsi_entityid_t e);
DDS_EXPORT ddsi_guid_t nn_hton_guid (ddsi_guid_t g);
DDS_EXPORT ddsi_guid_t nn_ntoh_guid (ddsi_guid_t g);

void bswap_sequence_number_set_hdr (nn_sequence_number_set_header_t *snset);
void bswap_sequence_number_set_bitmap (nn_sequence_number_set_header_t *snset, uint32_t *bits);
void bswap_fragment_number_set_hdr (nn_fragment_number_set_header_t *fnset);
void bswap_fragment_number_set_bitmap (nn_fragment_number_set_header_t *fnset, uint32_t *bits);

#if defined (__cplusplus)
}
#endif

#endif /* NN_BSWAP_H */
