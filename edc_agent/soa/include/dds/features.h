/*
 * Copyright(c) 2020 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef _DDS_PUBLIC_FEATURES_H_
#define _DDS_PUBLIC_FEATURES_H_

/* Whether or not support for DDS Security is included */
#define DDS_HAS_SECURITY 1

/* Whether or not support for the lifespan QoS is included */
#define DDS_HAS_LIFESPAN 1

/* Whether or not support for generating "deadline missed" events is included */
#define DDS_HAS_DEADLINE_MISSED 1

/* Whether or not support for network partitions is included */
#define DDS_HAS_NETWORK_PARTITIONS 1

/* Whether or not support for source-specific multicast is included */
/* #undef DDS_HAS_SSM */

/* Whether or not features dependent on OpenSSL are included */
/* #undef DDS_HAS_SSL */

/* Whether or not support for type discovery is included */
/* #undef DDS_HAS_TYPE_DISCOVERY */

/* Whether or not support for topic discovery is included */
/* #undef DDS_HAS_TOPIC_DISCOVERY */

/* Whether or not support for Iceoryx support is included */
#define DDS_HAS_SHM 1

/* Whether or not support ACFW runtime specific DDS changes are included */
#define DDS_HAS_ACFW_RPC_PATCHES 1

/* Whether or not support for DDS Security is included */
/* #undef DDS_HAS_STATISTIC */

/* Whether or not support for multiple interface is included */
/* #undef DDS_HAS_MULTI_INTF */

/* Whether or not support for non-blocking discovery mechanism is included */
#define DDS_HAS_NONBLOCK_RPC_DISCOVERY 1

#define DDS_HAS_PCIE 1

#define DDS_HAS_FAST_SPDP 1

/* #undef DDS_HAS_TSN_TAS */

/* #undef DDS_HAS_TSN_FRER */

/* SOA Proxy */
#define SOA_PROXY_INTEGRATION_SCHEME 1

#define DDS_HAS_VENDOR_ID_FILTER 1
#define DDS_HAS_DATA_READER_FILTER 1
/* #undef DDS_HAS_SOA_PROXY_FORWADING_LATENCY */
#endif
