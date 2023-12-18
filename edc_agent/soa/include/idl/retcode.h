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
 * Copyright(c) 2021 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef IDL_RETCODE_H
#define IDL_RETCODE_H

#include <stdint.h>

typedef int32_t idl_retcode_t;

/**
 * @name IDL_Return_Code
 */
/** @{ */
/** Success */
#define IDL_RETCODE_OK (0)
/** Push more tokens */
#define IDL_RETCODE_PUSH_MORE (-1)
/** Processor needs refill in order to continue */
#define IDL_RETCODE_NEED_REFILL (-2)
/** Syntax error */
#define IDL_RETCODE_SYNTAX_ERROR (-3)
/** Semantic error */
#define IDL_RETCODE_SEMANTIC_ERROR (-4)
/** Operation failed due to lack of resources */
#define IDL_RETCODE_NO_MEMORY (-5)
/** */
#define IDL_RETCODE_ILLEGAL_EXPRESSION (-6)
/** */
#define IDL_RETCODE_OUT_OF_RANGE (-7)
/** Permission denied */
#define IDL_RETCODE_NO_ACCESS (-8)
/** No such file or directory */
#define IDL_RETCODE_NO_ENTRY (-9)
/** Operation failed due to lack of disk space */
#define IDL_RETCODE_NO_SPACE (-10)
/** */
#define IDL_RETCODE_BAD_FORMAT (-11)
/** */
#define IDL_RETCODE_BAD_PARAMETER (-12)
/** @} */
#define IDL_RETCODE_UNSUPPORTED (-13)
/** @} */

#endif /* IDL_RETCODE_H */
