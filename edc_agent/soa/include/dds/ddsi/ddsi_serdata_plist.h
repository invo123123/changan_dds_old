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
#ifndef DDSI_SERDATA_PLIST_H
#define DDSI_SERDATA_PLIST_H

#include "dds/ddsi/q_protocol.h" /* for nn_parameterid_t */
#include "dds/ddsi/ddsi_keyhash.h"
#include "dds/ddsi/ddsi_serdata.h"
#include "dds/ddsi/ddsi_sertype.h"

#include "dds/dds.h"

#if defined (__cplusplus)
extern "C" {
#endif

/* There is an alignment requirement on the raw data (it must be at
   offset mod 8 for the conversion to/from a dds_stream to work).
   So we define two types: one without any additional padding, and
   one where the appropriate amount of padding is inserted */
#define DDSI_SERDATA_PLIST_PREPAD     \
  struct ddsi_serdata c;              \
  uint32_t pos;                       \
  uint32_t size;                      \
  nn_vendorid_t vendorid;             \
  nn_protocol_version_t protoversion; \
  ddsi_keyhash_t keyhash
#define DDSI_SERDATA_PLIST_POSTPAD    \
  uint16_t identifier;                \
  uint16_t options;                   \
  char data[]

struct ddsi_serdata_plist_unpadded {
  DDSI_SERDATA_PLIST_PREPAD;
  DDSI_SERDATA_PLIST_POSTPAD;
};

#ifdef __GNUC__
#define DDSI_SERDATA_PLIST_PAD(n) ((n) % 8)
#else
#define DDSI_SERDATA_PLIST_PAD(n) (n)
#endif

struct ddsi_serdata_plist {
  DDSI_SERDATA_PLIST_PREPAD;
  char pad[DDSI_SERDATA_PLIST_PAD (8 - (offsetof (struct ddsi_serdata_plist_unpadded, data) % 8))];
  DDSI_SERDATA_PLIST_POSTPAD;
};

#undef DDSI_SERDATA_PLIST_PAD
#undef DDSI_SERDATA_PLIST_POSTPAD
#undef DDSI_SERDATA_PLIST_PREPAD

struct ddsi_sertype_plist {
  struct ddsi_sertype c;
  uint16_t encoding_format; /* CDR_ENC_FORMAT_(PLAIN|DELIMITED|PL) */
  nn_parameterid_t keyparam;
};

extern DDS_EXPORT const struct ddsi_sertype_ops ddsi_sertype_ops_plist;
extern DDS_EXPORT const struct ddsi_serdata_ops ddsi_serdata_ops_plist;

#if defined (__cplusplus)
}
#endif

#endif
