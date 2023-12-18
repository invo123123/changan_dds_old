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
#ifndef NN_BITSET_H
#define NN_BITSET_H

#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "dds/export.h"
#include "dds/ddsi/q_unused.h"

#if defined (__cplusplus)
extern "C" {
#endif

DDS_INLINE_EXPORT inline int nn_bitset_isset (uint32_t numbits, const uint32_t *bits, uint32_t idx)
{
  return idx < numbits && (bits[idx/32] & (UINT32_C(1) << (31 - (idx%32))));
}

DDS_INLINE_EXPORT inline void nn_bitset_set (UNUSED_ARG_NDEBUG (uint32_t numbits), uint32_t *bits, uint32_t idx)
{
  assert (idx < numbits);
  bits[idx/32] |= UINT32_C(1) << (31 - (idx%32));
}

DDS_INLINE_EXPORT inline void nn_bitset_clear (UNUSED_ARG_NDEBUG (uint32_t numbits), uint32_t *bits, uint32_t idx)
{
  assert (idx < numbits);
  bits[idx/32] &= ~(UINT32_C(1) << (31 - (idx%32)));
}

DDS_INLINE_EXPORT inline void nn_bitset_zero (uint32_t numbits, uint32_t *bits)
{
  memset (bits, 0, 4 * ((numbits + 31) / 32));
}

DDS_INLINE_EXPORT inline void nn_bitset_one (uint32_t numbits, uint32_t *bits)
{
  memset (bits, 0xff, 4 * ((numbits + 31) / 32));

  /* clear bits "accidentally" set */
  if ((numbits % 32) != 0)
  {
    const uint32_t k = numbits / 32;
    const uint32_t n = numbits % 32;
    bits[k] &= ~(~UINT32_C(0) >> n);
  }
}

#if defined (__cplusplus)
}
#endif

#endif /* NN_BITSET_H */
