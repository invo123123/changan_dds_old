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
#ifndef Q_QOSMATCH_H
#define Q_QOSMATCH_H

#include "dds/features.h"
#include "dds/ddsi/ddsi_typelib.h"
#include "dds/ddsi/q_entity.h"
#if defined (__cplusplus)
extern "C" {
#endif

struct dds_qos;

/* perform reader/writer QoS (and topic name, type name, partition) matching;
   mask can be used to exclude some of these (including topic name and type
   name, so be careful!)

   reason will be set to the policy id of one of the mismatching QoS, or to
   DDS_INVALID_QOS_POLICY_ID if there is no mismatch or if the mismatch is
   in topic or type name (those are not really QoS and don't have a policy id)

   rd/wr_type_unknown is set to true in case the matching cannot be completed
   because of missing type information. A type-lookup request is required to get the
   details of the type to do the qos matching (e.g. check assignability) */
bool qos_match_mask_p (
    struct ddsi_domaingv *gv,
    const dds_qos_t *rd_qos,
    const dds_qos_t *wr_qos,
    uint64_t mask,
    dds_qos_policy_id_t *reason
#ifdef DDS_HAS_TYPE_DISCOVERY
    , const struct ddsi_type_pair *rd_type_pair
    , const struct ddsi_type_pair *wr_type_pair
    , bool *rd_typeid_req_lookup
    , bool *wr_typeid_req_lookup
#endif
);

bool qos_match_p (
    struct ddsi_domaingv *gv,
    const dds_qos_t *rd_qos,
    const dds_qos_t *wr_qos,
    dds_qos_policy_id_t *reason
#ifdef DDS_HAS_TYPE_DISCOVERY
    , const struct ddsi_type_pair *rd_type_pair
    , const struct ddsi_type_pair *wr_type_pair
    , bool *rd_typeid_req_lookup
    , bool *wr_typeid_req_lookup
#endif
);

#if defined (__cplusplus)
}
#endif

#endif /* Q_QOSMATCH_H */
