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
 * Copyright(c) 2021 Apex.AI, Inc
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */

#ifndef _DDS_BASIC_TYPES_H_
#define _DDS_BASIC_TYPES_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Handle to an entity
 * @ingroup entity
 *
 * A valid entity handle will always have a positive integer value.
 * Should the value be negative, it is one of the DDS_RETCODE_*
 * error codes.
 */
typedef int32_t dds_entity_t;

#define DDS_GUID_LENGTH  16

/**
 * @anchor DDS_MIN_PSEUDO_HANDLE
 * @ingroup internal
 * @brief Pseudo Handle origin
 *
 * Some handles in AutoCoreDDS are 'fake', most importantly the builtin topic handles.
 * These handles are derived from this constant.
 */
#define DDS_MIN_PSEUDO_HANDLE ((dds_entity_t)0x7fff0000)

/**
 * @anchor DDS_AUTOCOREDDS_HANDLE
 * @ingroup internal
 * @brief Special handle representing the entity corresponding to the AutoCoreDDS library itself
 */
#define DDS_AUTOCOREDDS_HANDLE ((dds_entity_t)(DDS_MIN_PSEUDO_HANDLE + 256))

#endif /*_DDS_PUBLIC_TYPES_H_*/
