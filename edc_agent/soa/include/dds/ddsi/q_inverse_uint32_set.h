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
#ifndef NN_INVERSE_UINT32_SET_H
#define NN_INVERSE_UINT32_SET_H

#include "dds/ddsrt/avl.h"

#if defined (__cplusplus)
extern "C" {
#endif

struct inverse_uint32_set_node {
  ddsrt_avl_node_t avlnode;
  uint32_t min, max;
};
struct inverse_uint32_set {
  ddsrt_avl_tree_t ids;
  uint32_t cursor;
  uint32_t min, max;
};

void inverse_uint32_set_init(struct inverse_uint32_set *set, uint32_t min, uint32_t max);
void inverse_uint32_set_fini(struct inverse_uint32_set *set);
int inverse_uint32_set_alloc(uint32_t * const id, struct inverse_uint32_set *set);
void inverse_uint32_set_free(struct inverse_uint32_set *set, uint32_t id);

#if defined (__cplusplus)
}
#endif

#endif
