
/*
 *  Copyright(c) 2020 to 2021 AutoCore Technology (Nanjing) Co., Ltd. All rights reserved.
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
 *  Eclipse Distribution License - v 1.0
 *  Copyright (c) 2007, Eclipse Foundation, Inc. and its licensors.
 *  All rights reserved.
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *  Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
 *  in the documentation and/or other materials provided with the distribution.
 *  Neither the name of the Eclipse Foundation, Inc. nor the names of its contributors may be used to endorse or promote products 
 *  derived from this software without specific prior written permission.
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
 *  BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL 
 *  THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 
 
/*
 * Copyright(c) 2006 to 2018 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef _TAS_API_H_
#define _TAS_API_H_

#if defined (__cplusplus)
extern "C" {
#endif
#include <stddef.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>

/**********************************************************************************
 *                         Define  Macro
 **********************************************************************************/

#define  TSN_TAS_OK                (0)
#define  TSN_TAS_ERROR             (-1)
#define  TAS_BASE_KEY           0x35C5
#define  TAS_BASE_KEY_OFFSET_RX           1
#define  TAS_BASE_KEY_OFFSET_TX           2
#define  TAS_BASE_KEY_OFFSET_CONF         3
#define  TAS_BASE_KEY_OFFSET_SEMAPHORE_W  4
#define  TAS_BASE_KEY_OFFSET_SEMAPHORE_R  5
#define  TAS_KEY_OFFSET_SEMAPHORE_W    (TAS_BASE_KEY + TAS_BASE_KEY_OFFSET_SEMAPHORE_W)
#define  TAS_KEY_OFFSET_SEMAPHORE_R    (TAS_BASE_KEY + TAS_BASE_KEY_OFFSET_SEMAPHORE_R)
#define  TAS_SHM_MAX_ARR_TX         (8)
#define  TAS_SHM_MAX_ARR_RX         (8)
#define  TAS_SHM_ARR_RX_GROUP       (2)
#define  TAS_MAX_PAYLOAD         1432
#define  TAS_MAX_GATE_INFO       64
#define  TAS_IPADDR_STR_LEN      16
#define  TAS_INTERFACE_STR_LEN   32
#define DEBUG 1
#define TAS_LISTEN_MAX_PORT      4

#if DEBUG
#define  TAS_DATA_OFFSET         34
#else
#define  TAS_DATA_OFFSET         18
#endif

#define  TAS_MAX_PRI              7
#define  TAS_DEFAULT_PRI          3
#define  TAS_MIN_VLAN_ID          1
#define  TAS_DEFAULT_VLAN_ID      3
#define  TAS_MAX_VLAN_ID          4094
#define TAS_MAC_ADDR_LEN          6
#define TAS_PKG_UNICAST           (0)
#define TAS_PKG_MULTICAST         (1)
#define TAS_PEER_INFO_NUM         4
#define TAS_MQ_TX_FILE         "/opt/tas_mq_tx_file"
#define TAS_MQ_RX_FILE         "/opt/tas_mq_rx_file"
#define MQ_TX_ID           1
#define MQ_RX_ID           2
#define MSG_RD_PERMISSION  0444
#define MSG_WR_PERMISSION  0222

/**
 * @brief Encode CallBack Function, implemented by User.
 *
 * @param user_buf The user data buffer
 * @param shm_buf The encode dst buffer, data address plus TAS_DATA_OFFSET
 * @return int value indicating success or failure
 * @retval TSN_TAS_OK
 *            Success
 * @retval TSN_TAS_ERROR
 *            An internal error has occurred.
 */
typedef int (*Encode_Callback)(void *user_buf, void *shm_buf, int len);


/**
 * @brief Decode CallBack Function, implemented by User.
 *
 * @param user_buf The user data buffer
 * @param shm_buf The decode src buffer, data address plus TAS_DATA_OFFSET
 * @return int value indicating success or failure
 * @retval TSN_TAS_OK
 *            Success
 * @retval TSN_TAS_ERROR
 *            An internal error has occurred.
 */
typedef int (*Decode_Callback)(void *user_buf, void *shm_buf, int* len);


/**********************************************************************************
*                   Struct Define
**********************************************************************************/
/**
 * @brief TSN TAS handle Struct
 *
 */
typedef struct tas_handle
{
    void             *tx_shm;               /** Tx Data Field */
    void             *rx_shm;               /** Rx Data Field */
    void             *conf_shm;             /** Conf Data Field */
}TAS_HANDLE;

/**
 * @brief TSN TAS Channel Key Struct
 *
 */
typedef struct tas_ch_key
{
    uint32_t     puid;                        /** Tx Global User_ID/Process_ID */
    uint8_t      pri;                         /** Tx Topic/Flow Priority */
    uint8_t      rsvd[3];                     /** member not use current */
}TAS_CH_KEY;

typedef struct tas_tx_peerinfo
{
    uint8_t      flag;                         /* Use this struct or not. 0: not, 1 or other: use*/
    uint16_t     vlanid;                      /** vlanid */
    uint32_t     dstid;                        /** dstid,  processID/threadID……*/
    unsigned char  destmac[TAS_MAC_ADDR_LEN]; /** dstmac    TAS_MAC_ADDR_LEN=6 */
}__attribute__((packed, aligned(1))) TAS_TX_PEERINFO;

typedef struct tas_tx_buf
{
    uint64_t     hw_ts;
    uint8_t      pri;
    uint32_t     srcid;
    uint8_t      multicast;
    unsigned char  srcmac[TAS_MAC_ADDR_LEN];
    TAS_TX_PEERINFO  peerInfo[TAS_PEER_INFO_NUM];
    int32_t          data_len;
    char         data[TAS_MAX_PAYLOAD];
}__attribute__((packed, aligned(1))) TAS_TX_BUF;

typedef struct tas_rx_buf
{
    uint64_t     hw_ts;
    uint8_t      multicast;
    uint32_t     srcid;
    uint32_t     dstid;
    uint8_t      pri;
    int          data_len;
    char         data[TAS_MAX_PAYLOAD];
}__attribute__((packed, aligned(1))) TAS_RX_BUF;

typedef struct tas_tx_msg_buf {
    long type;
    TAS_TX_BUF tx_data;
}__attribute__((packed, aligned(1))) TAS_TX_MSG_BUF;


typedef struct tas_rx_msg_buf {
    long type;
    TAS_RX_BUF rx_data;
}__attribute__((packed, aligned(1))) TAS_RX_MSG_BUF;

#if defined (__cplusplus)
}
#endif

#endif
