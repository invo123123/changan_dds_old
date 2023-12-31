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
 * Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */

#ifndef DDS_SECURITY_API_H
#define DDS_SECURITY_API_H

#include "dds/ddsi/ddsi_domaingv.h"
#include "dds_security_api_access_control.h"
#include "dds_security_api_authentication.h"
#include "dds_security_api_cryptography.h"


#if defined (__cplusplus)
extern "C" {
#endif

/* Integration functions for Security plugins */
typedef int (*plugin_init)(const char *argument, void **context, struct ddsi_domaingv *gv);
typedef int (*plugin_finalize)(void *context);

#if defined (__cplusplus)
}
#endif

#endif /* DDS_SECURITY_API_H */
