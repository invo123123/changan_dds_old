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
#ifndef Q_DEBMON_H
#define Q_DEBMON_H

#if defined (__cplusplus)
extern "C" {
#endif

struct debug_monitor;
typedef int (*debug_monitor_cpf_t) (ddsi_tran_conn_t conn, const char *fmt, ...);
typedef int (*debug_monitor_plugin_t) (ddsi_tran_conn_t conn, debug_monitor_cpf_t cpf, void *arg);

struct debug_monitor *new_debug_monitor (struct ddsi_domaingv *gv, int32_t port);
void add_debug_monitor_plugin (struct debug_monitor *dm, debug_monitor_plugin_t fn, void *arg);
bool get_debug_monitor_locator (struct debug_monitor *dm, ddsi_locator_t *locator);
void free_debug_monitor (struct debug_monitor *dm);

#if defined (__cplusplus)
}
#endif

#endif
