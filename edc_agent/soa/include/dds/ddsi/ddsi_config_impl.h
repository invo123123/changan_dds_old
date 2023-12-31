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
#ifndef NN_CONFIG_H
#define NN_CONFIG_H

#include <stdio.h>

#include "dds/ddsrt/attributes.h"
#include "dds/ddsi/ddsi_config.h"

#if defined (__cplusplus)
extern "C" {
#endif

struct cfgst;
struct ddsrt_log_cfg;

struct cfgst *ddsi_config_init (const char *config, struct ddsi_config *cfg, uint32_t domid) ddsrt_nonnull((1,2));
struct cfgst *ddsi_qos_config_init (const char *config, struct ddsi_qos_config *qoscfg) ddsrt_nonnull((1,2));
void ddsi_config_print_cfgst (struct cfgst *cfgst, const struct ddsrt_log_cfg *logcfg);
char * cfgst_get_config_logging (struct cfgst *cfgst);
void ddsi_config_print_rawconfig (const struct ddsi_config *cfg, const struct ddsrt_log_cfg *logcfg);
void ddsi_config_free_source_info (struct cfgst *cfgst);
void ddsi_config_fini (struct cfgst *cfgst);

#if defined (__cplusplus)
}
#endif

#endif /* NN_CONFIG_H */
