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


#ifndef SECURITY_CORE_PLUGINS_H_
#define SECURITY_CORE_PLUGINS_H_

#include <stdint.h>
#include "dds/export.h"
#include "dds/ddsrt/retcode.h"
#include "dds/ddsrt/dynlib.h"
#include "dds/ddsi/ddsi_domaingv.h"
#include "dds/security/dds_security_api.h"

struct ddsrt_log_cfg;

typedef struct dds_security_plugin {
  ddsrt_dynlib_t lib_handle;
  plugin_init func_init;
  plugin_finalize func_finalize;
  char *name;
} dds_security_plugin;

/* we are using our own security plugin configuration (not certificates etc)
 * because we do not want to depend on DDSI configuration data types.
 *
 * A configuration data type is needed because there are traverses to properties several times
 */

typedef struct dds_security_plugin_config {
  char *library_path;
  char *library_init;
  char *library_finalize;
} dds_security_plugin_config;

typedef struct dds_security_plugin_suite_config{
  dds_security_plugin_config authentication;
  dds_security_plugin_config cryptography;
  dds_security_plugin_config access_control;
} dds_security_plugin_suite_config;

DDS_EXPORT dds_return_t dds_security_plugin_release(const dds_security_plugin *security_plugin, void *context);
DDS_EXPORT dds_return_t dds_security_check_plugin_configuration(const dds_security_plugin_suite_config *security_suite_config, struct ddsi_domaingv *gv);
DDS_EXPORT dds_return_t dds_security_load_security_library(const dds_security_plugin_config *plugin_config, dds_security_plugin *security_plugin,
    void **security_plugin_context, struct ddsi_domaingv *gv);
DDS_EXPORT dds_return_t dds_security_verify_plugin_functions(
    dds_security_authentication *authentication_context, dds_security_plugin *auth_plugin,
    dds_security_cryptography *crypto_context, dds_security_plugin *crypto_plugin,
    dds_security_access_control *access_control_context, dds_security_plugin *ac_plugin,
    struct ddsi_domaingv *gv);

#endif /* SECURITY_CORE_PLUGINS_H_ */
