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
#ifndef DDSI_QOSCFGELEMS_H
#define DDSI_QOSCFGELEMS_H

#include "dds/features.h"

/* all qos elems*/
static struct cfgelem ddsi_qos_durability_cfgelems[] = {
  ENUM("kind", NULL, 1, "DDS_DURABILITY_VOLATILE",
    MEMBEROF(ddsi_qos_config_topic_listelem, durability.kind),
    FUNCTIONS(0, uf_qos_driability, 0, pf_qos_driability),
    DESCRIPTION("<p>Qos Durability kind.</p>"),
    VALUES("DDS_DURABILITY_VOLATILE", "DDS_DURABILITY_TRANSIENT_LOCAL", "DDS_DURABILITY_TRANSIENT", "DDS_DURABILITY_PERSISTENT")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_durability_cfgelems[] = {
  ENUM("kind", NULL, 1, "DDS_DURABILITY_VOLATILE",
    MEMBEROF(ddsi_qos_config_datareader_listelem, durability.kind),
    FUNCTIONS(0, uf_qos_driability, 0, pf_qos_driability),
    DESCRIPTION("<p>Datareader Qos Durability kind.</p>"),
    VALUES("DDS_DURABILITY_VOLATILE", "DDS_DURABILITY_TRANSIENT_LOCAL", "DDS_DURABILITY_TRANSIENT", "DDS_DURABILITY_PERSISTENT")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_durability_cfgelems[] = {
  ENUM("kind", NULL, 1, "DDS_DURABILITY_VOLATILE",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, durability.kind),
    FUNCTIONS(0, uf_qos_driability, 0, pf_qos_driability),
    DESCRIPTION("<p>Datareader Qos Durability kind.</p>"),
    VALUES("DDS_DURABILITY_VOLATILE", "DDS_DURABILITY_TRANSIENT_LOCAL", "DDS_DURABILITY_TRANSIENT", "DDS_DURABILITY_PERSISTENT")),
  END_MARKER
};

static struct cfgelem ddsi_qos_history_cfgelems[] = {
  ENUM("kind", NULL, 1, "DDS_HISTORY_KEEP_LAST",
    MEMBEROF(ddsi_qos_config_topic_listelem, history.kind),
    FUNCTIONS(0, uf_qos_history, 0, pf_qos_history),
    DESCRIPTION("<p>QOS History kind.</p>"),
    VALUES("DDS_HISTORY_KEEP_LAST", "DDS_HISTORY_KEEP_ALL")),
  INT("depth", NULL, 1, "1",
    MEMBEROF(ddsi_qos_config_topic_listelem, history.depth),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos History depth.</p>")),
  END_MARKER
};


static struct cfgelem ddsi_qos_datareader_history_cfgelems[] = {
  ENUM("kind", NULL, 1, "DDS_HISTORY_KEEP_LAST",
    MEMBEROF(ddsi_qos_config_datareader_listelem, history.kind),
    FUNCTIONS(0, uf_qos_history, 0, pf_qos_history),
    DESCRIPTION("<p>QOS History kind.</p>"),
    VALUES("DDS_HISTORY_KEEP_LAST", "DDS_HISTORY_KEEP_ALL")),
  INT("depth", NULL, 1, "1",
    MEMBEROF(ddsi_qos_config_datareader_listelem, history.depth),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos History depth.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_history_cfgelems[] = {
  ENUM("kind", NULL, 1, "DDS_HISTORY_KEEP_LAST",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, history.kind),
    FUNCTIONS(0, uf_qos_history, 0, pf_qos_history),
    DESCRIPTION("<p>QOS History kind.</p>"),
    VALUES("DDS_HISTORY_KEEP_LAST", "DDS_HISTORY_KEEP_ALL")),
  INT("depth", NULL, 1, "1",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, history.depth),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos History depth.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_resource_limits_cfgelems[] = {
  STRING("max_samples", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_topic_listelem, resource_limits.max_samples),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  STRING("max_instances", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_topic_listelem, resource_limits.max_instances),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  STRING("max_samples_per_instance", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_topic_listelem, resource_limits.max_samples_per_instance),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_resource_limits_cfgelems[] = {
  STRING("max_samples", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datareader_listelem, resource_limits.max_samples),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  STRING("max_instances", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datareader_listelem, resource_limits.max_instances),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  STRING("max_samples_per_instance", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datareader_listelem, resource_limits.max_samples_per_instance),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_resource_limits_cfgelems[] = {
  STRING("max_samples", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, resource_limits.max_samples),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  STRING("max_instances", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, resource_limits.max_instances),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  STRING("max_samples_per_instance", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, resource_limits.max_samples_per_instance),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS History kind.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_reliability_max_blocking_time_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_topic_listelem, reliability.max_blocking_time),
    FUNCTIONS(0, uf_qos_reliability_max_blocking_time_sec, 0, pf_qos_reliability_max_blocking_time_sec),
    DESCRIPTION("<p>Qos reliability max_blocking_time.</p>")),
  INT("nanosec", NULL, 1,  "100000000",
    MEMBEROF(ddsi_qos_config_topic_listelem, reliability.max_blocking_time),
    FUNCTIONS(0, uf_qos_reliability_max_blocking_time_nanosec, 0, pf_qos_reliability_max_blocking_time_nanosec),
    DESCRIPTION("<p>Qos reliability max_blocking_time.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_reliability_max_blocking_time_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datareader_listelem, reliability.max_blocking_time),
    FUNCTIONS(0, uf_qos_datareader_reliability_max_blocking_time_sec, 0, pf_qos_datareader_reliability_max_blocking_time_sec),
    DESCRIPTION("<p>Qos reliability max_blocking_time.</p>")),
  INT("nanosec", NULL, 1,  "100000000",
    MEMBEROF(ddsi_qos_config_datareader_listelem, reliability.max_blocking_time),
    FUNCTIONS(0, uf_qos_datareader_reliability_max_blocking_time_nanosec, 0, pf_qos_datareader_reliability_max_blocking_time_nanosec),
    DESCRIPTION("<p>Qos reliability max_blocking_time.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_reliability_max_blocking_time_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, reliability.max_blocking_time),
    FUNCTIONS(0, uf_qos_datawriter_reliability_max_blocking_time_sec, 0, pf_qos_datawriter_reliability_max_blocking_time_sec),
    DESCRIPTION("<p>Qos reliability max_blocking_time.</p>")),
  INT("nanosec", NULL, 1,  "100000000",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, reliability.max_blocking_time),
    FUNCTIONS(0, uf_qos_datawriter_reliability_max_blocking_time_nanosec, 0, pf_qos_datawriter_reliability_max_blocking_time_nanosec),
    DESCRIPTION("<p>Qos reliability max_blocking_time.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_deadline_period_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_topic_listelem, deadline.deadline),
    FUNCTIONS(0, uf_qos_deadline_time_sec, 0, pf_qos_deadline_time_sec),
    DESCRIPTION("<p>Qos deadline period.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_topic_listelem, deadline.deadline),
    FUNCTIONS(0, uf_qos_deadline_time_nanosec, 0, pf_qos_deadline_time_nanosec),
    DESCRIPTION("<p>Qos deadline period.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_deadline_period_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datareader_listelem, deadline.deadline),
    FUNCTIONS(0, uf_qos_datareader_deadline_time_sec, 0, pf_qos_datareader_deadline_time_sec),
    DESCRIPTION("<p>Qos deadline period.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_datareader_listelem, deadline.deadline),
    FUNCTIONS(0, uf_qos_datareader_deadline_time_nanosec, 0, pf_qos_datareader_deadline_time_nanosec),
    DESCRIPTION("<p>Qos deadline period.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_deadline_period_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, deadline.deadline),
    FUNCTIONS(0, uf_qos_datawriter_deadline_time_sec, 0, pf_qos_datawriter_deadline_time_sec),
    DESCRIPTION("<p>Qos deadline period.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, deadline.deadline),
    FUNCTIONS(0, uf_qos_datawriter_deadline_time_nanosec, 0, pf_qos_datawriter_deadline_time_nanosec),
    DESCRIPTION("<p>Qos deadline period.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_liveliness_lease_duration_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_topic_listelem, liveliness.lease_duration),
    FUNCTIONS(0, uf_qos_liveliness_lease_duration_sec, 0, pf_qos_liveliness_lease_duration_sec),
    DESCRIPTION("<p>Qos liveliness lease_duration.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_topic_listelem, liveliness.lease_duration),
    FUNCTIONS(0, uf_qos_liveliness_lease_duration_nanosec, 0, pf_qos_liveliness_lease_duration_nanosec),
    DESCRIPTION("<p>Qos liveliness lease_duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_liveliness_lease_duration_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datareader_listelem, liveliness.lease_duration),
    FUNCTIONS(0, uf_qos_datareader_liveliness_lease_duration_sec, 0, pf_qos_datareader_liveliness_lease_duration_sec),
    DESCRIPTION("<p>Qos liveliness lease_duration.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_datareader_listelem, liveliness.lease_duration),
    FUNCTIONS(0, uf_qos_datareader_liveliness_lease_duration_nanosec, 0, pf_qos_datareader_liveliness_lease_duration_nanosec),
    DESCRIPTION("<p>Qos liveliness lease_duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_liveliness_lease_duration_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, liveliness.lease_duration),
    FUNCTIONS(0, uf_qos_datawriter_liveliness_lease_duration_sec, 0, pf_qos_datawriter_liveliness_lease_duration_sec),
    DESCRIPTION("<p>Qos liveliness lease_duration.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, liveliness.lease_duration),
    FUNCTIONS(0, uf_qos_datawriter_liveliness_lease_duration_nanosec, 0, pf_qos_datawriter_liveliness_lease_duration_nanosec),
    DESCRIPTION("<p>Qos liveliness lease_duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_lifespan_duration_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_topic_listelem, lifespan.duration),
    FUNCTIONS(0, uf_qos_lifespan_duration_sec, 0, pf_qos_lifespan_duration_sec),
    DESCRIPTION("<p>Qos liveliness lease_duration.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_topic_listelem, lifespan.duration),
    FUNCTIONS(0, uf_qos_lifespan_duration_nanosec, 0, pf_qos_lifespan_duration_nanosec),
    DESCRIPTION("<p>Qos livelineddsi_qos_config_topic_listelemss lease_duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_lifespan_duration_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, lifespan.duration),
    FUNCTIONS(0, uf_qos_datawriter_lifespan_duration_sec, 0, pf_qos_datawriter_lifespan_duration_sec),
    DESCRIPTION("<p>Qos liveliness lease_duration.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, lifespan.duration),
    FUNCTIONS(0, uf_qos_datawriter_lifespan_duration_nanosec, 0, pf_qos_datawriter_lifespan_duration_nanosec),
    DESCRIPTION("<p>Qos livelineddsi_qos_config_topic_listelemss lease_duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_latency_budget_duration_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_topic_listelem, latency_budget.duration),
    FUNCTIONS(0, uf_qos_latency_budget_duration_sec, 0, pf_qos_latency_budget_duration_sec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  INT("nanosec", NULL, 1,  "0",
    MEMBEROF(ddsi_qos_config_topic_listelem, latency_budget.duration),
    FUNCTIONS(0, uf_qos_latency_budget_duration_nanosec, 0, pf_qos_latency_budget_duration_nanosec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_latency_budget_duration_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datareader_listelem, latency_budget.duration),
    FUNCTIONS(0, uf_qos_datareader_latency_budget_duration_sec, 0, pf_qos_datareader_latency_budget_duration_sec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  INT("nanosec", NULL, 1,  "0",
    MEMBEROF(ddsi_qos_config_datareader_listelem, latency_budget.duration),
    FUNCTIONS(0, uf_qos_datareader_latency_budget_duration_nanosec, 0, pf_qos_datareader_latency_budget_duration_nanosec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_latency_budget_duration_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, latency_budget.duration),
    FUNCTIONS(0, uf_qos_datawriter_latency_budget_duration_sec, 0, pf_qos_datawriter_latency_budget_duration_sec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  INT("nanosec", NULL, 1,  "0",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, latency_budget.duration),
    FUNCTIONS(0, uf_qos_datawriter_latency_budget_duration_nanosec, 0, pf_qos_datawriter_latency_budget_duration_nanosec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_ownership_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_OWNERSHIP_SHARED",
    MEMBEROF(ddsi_qos_config_topic_listelem, ownership.kind),
    FUNCTIONS(0, uf_qos_ownership, 0, pf_qos_ownership),
    DESCRIPTION("<p>QOS owership kind.</p>"),
    VALUES("DDS_OWNERSHIP_SHARED", "DDS_OWNERSHIP_EXCLUSIVE")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_ownership_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_OWNERSHIP_SHARED",
    MEMBEROF(ddsi_qos_config_datareader_listelem, ownership.kind),
    FUNCTIONS(0, uf_qos_ownership, 0, pf_qos_ownership),
    DESCRIPTION("<p>QOS owership kind.</p>"),
    VALUES("DDS_OWNERSHIP_SHARED", "DDS_OWNERSHIP_EXCLUSIVE")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_ownership_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_OWNERSHIP_SHARED",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, ownership.kind),
    FUNCTIONS(0, uf_qos_ownership, 0, pf_qos_ownership),
    DESCRIPTION("<p>QOS owership kind.</p>"),
    VALUES("DDS_OWNERSHIP_SHARED", "DDS_OWNERSHIP_EXCLUSIVE")),
  END_MARKER
};

static struct cfgelem ddsi_qos_reliability_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_RELIABILITY_BEST_EFFORT",
    MEMBEROF(ddsi_qos_config_topic_listelem, reliability.kind),
    FUNCTIONS(0, uf_qos_reliability, 0, pf_qos_reliability),
    DESCRIPTION("<p>QOS reliability kind.</p>"),
    VALUES("DDS_RELIABILITY_BEST_EFFORT", "DDS_RELIABILITY_RELIABLE")),
  GROUP("max_blocking_time", ddsi_qos_reliability_max_blocking_time_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic reliability.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_reliability_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_RELIABILITY_BEST_EFFORT",
    MEMBEROF(ddsi_qos_config_datareader_listelem, reliability.kind),
    FUNCTIONS(0, uf_qos_reliability, 0, pf_qos_reliability),
    DESCRIPTION("<p>QOS reliability kind.</p>"),
    VALUES("DDS_RELIABILITY_BEST_EFFORT", "DDS_RELIABILITY_RELIABLE")),
  GROUP("max_blocking_time", ddsi_qos_datareader_reliability_max_blocking_time_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic reliability.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_reliability_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_RELIABILITY_BEST_EFFORT",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, reliability.kind),
    FUNCTIONS(0, uf_qos_reliability, 0, pf_qos_reliability),
    DESCRIPTION("<p>QOS reliability kind.</p>"),
    VALUES("DDS_RELIABILITY_BEST_EFFORT", "DDS_RELIABILITY_RELIABLE")),
  GROUP("max_blocking_time", ddsi_qos_datawriter_reliability_max_blocking_time_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic reliability.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_deadline_cfgelems[] = {  
  GROUP("period", ddsi_qos_deadline_period_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic deadline period.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_deadline_cfgelems[] = {  
  GROUP("period", ddsi_qos_datareader_deadline_period_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader deadline period.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_deadline_cfgelems[] = {  
  GROUP("period", ddsi_qos_datawriter_deadline_period_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter deadline period.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_liveliness_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_LIVELINESS_AUTOMATIC",
    MEMBEROF(ddsi_qos_config_topic_listelem, liveliness.kind),
    FUNCTIONS(0, uf_qos_liveliness, 0, pf_qos_liveliness),
    DESCRIPTION("<p>QOS liveliness kind.</p>"),
    VALUES("DDS_LIVELINESS_AUTOMATIC", "DDS_LIVELINESS_MANUAL_BY_PARTICIPANT", "DDS_LIVELINESS_MANUAL_BY_TOPIC")),  
  GROUP("lease_duration", ddsi_qos_liveliness_lease_duration_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic deadline lease_duration.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_liveliness_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_LIVELINESS_AUTOMATIC",
    MEMBEROF(ddsi_qos_config_datareader_listelem, liveliness.kind),
    FUNCTIONS(0, uf_qos_liveliness, 0, pf_qos_liveliness),
    DESCRIPTION("<p>QOS liveliness kind.</p>"),
    VALUES("DDS_LIVELINESS_AUTOMATIC", "DDS_LIVELINESS_MANUAL_BY_PARTICIPANT", "DDS_LIVELINESS_MANUAL_BY_TOPIC")),  
  GROUP("lease_duration", ddsi_qos_datareader_liveliness_lease_duration_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic deadline lease_duration.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_liveliness_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_LIVELINESS_AUTOMATIC",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, liveliness.kind),
    FUNCTIONS(0, uf_qos_liveliness, 0, pf_qos_liveliness),
    DESCRIPTION("<p>QOS liveliness kind.</p>"),
    VALUES("DDS_LIVELINESS_AUTOMATIC", "DDS_LIVELINESS_MANUAL_BY_PARTICIPANT", "DDS_LIVELINESS_MANUAL_BY_TOPIC")),  
  GROUP("lease_duration", ddsi_qos_datawriter_liveliness_lease_duration_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic deadline lease_duration.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_lifespan_cfgelems[] = {  
  GROUP("duration", ddsi_qos_lifespan_duration_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic lifespan duration.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_lifespan_cfgelems[] = {  
  GROUP("duration", ddsi_qos_datawriter_lifespan_duration_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter lifespan duration.</p>"
    )),
  END_MARKER
};


static struct cfgelem ddsi_qos_latency_budget_cfgelems[] = {  
  GROUP("duration", ddsi_qos_latency_budget_duration_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic latency_budget duration.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_latency_budget_cfgelems[] = {  
  GROUP("duration", ddsi_qos_datareader_latency_budget_duration_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader latency_budget duration.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_latency_budget_cfgelems[] = {  
  GROUP("duration", ddsi_qos_datawriter_latency_budget_duration_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter latency_budget duration.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_reader_data_lifecycle_nowriter_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datareader_listelem, reader_data_lifecycle.autopurge_nowriter_samples_delay),
    FUNCTIONS(0, uf_qos_datareader_data_lifecycle_nowriter_sec, 0, pf_qos_datareader_data_lifecycle_nowriter_sec),
    DESCRIPTION("<p>Qos reader_data_lifecycle autopurge_nowriter_samples_delay.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_datareader_listelem, reader_data_lifecycle.autopurge_nowriter_samples_delay),
    FUNCTIONS(0, uf_qos_datareader_data_lifecycle_nowriter_nanosec, 0, pf_qos_datareader_data_lifecycle_nowriter_nanosec),
    DESCRIPTION("<p>Qos reader_data_lifecycle autopurge_nowriter_samples_delay.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_reader_data_lifecycle_disposed_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datareader_listelem, reader_data_lifecycle.autopurge_disposed_samples_delay),
    FUNCTIONS(0, uf_qos_datareader_data_lifecycle_disposed_sec, 0, pf_qos_datareader_data_lifecycle_disposed_sec),
    DESCRIPTION("<p>Qos reader_data_lifecycle pf_qos_datareader_data_lifecycle_disposed_sec.</p>")),
  INT("nanosec", NULL, 1,  "DDS_INFINITY",
    MEMBEROF(ddsi_qos_config_datareader_listelem, reader_data_lifecycle.autopurge_disposed_samples_delay),
    FUNCTIONS(0, uf_qos_datareader_data_lifecycle_disposed_nanosec, 0, pf_qos_datareader_data_lifecycle_disposed_nanosec),
    DESCRIPTION("<p>Qos reader_data_lifecycle pf_qos_datareader_data_lifecycle_disposed_sec.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_reader_data_lifecycle_cfgelems[] = {  
  GROUP("autopurge_nowriter_samples_delay", ddsi_qos_datareader_reader_data_lifecycle_nowriter_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader reader_data_lifecycle autopurge_nowriter_samples_delay.</p>"
    )),
  GROUP("autopurge_disposed_samples_delay", ddsi_qos_datareader_reader_data_lifecycle_disposed_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader reader_data_lifecycle autopurge_disposed_samples_delay.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_writer_data_lifecycle_cfgelems[] = {  
  BOOL("autodispose_unregistered_instances", NULL, 1, "true",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, writer_data_lifecycle.autodispose_unregistered_instances),
    FUNCTIONS(0, uf_boolean, 0, pf_boolean),
    DESCRIPTION(
      "<p>Qos writer_data_lifecycle autodispose_unregistered_instances.</p>"
    )),
  END_MARKER
};

static struct cfgelem ddsi_qos_transport_priority_cfgelems[] = {  
  INT("value", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_topic_listelem, transport_priority.value),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos transport_priority value.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_transport_priority_cfgelems[] = {  
  INT("value", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, transport_priority.value),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos datawriter transport_priority value.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_destination_order_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP",
    MEMBEROF(ddsi_qos_config_topic_listelem, destination_order.kind),
    FUNCTIONS(0, uf_qos_destination_order, 0, pf_qos_destination_order),
    DESCRIPTION("<p>QOS destination_order kind.</p>"),
    VALUES("DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP", "DDS_DESTINATIONORDER_BY_SOURCE_TIMESTAMP")), 
  END_MARKER
};

static struct cfgelem ddsi_qos_datareader_destination_order_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP",
    MEMBEROF(ddsi_qos_config_datareader_listelem, destination_order.kind),
    FUNCTIONS(0, uf_qos_destination_order, 0, pf_qos_destination_order),
    DESCRIPTION("<p>QOS destination_order kind.</p>"),
    VALUES("DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP", "DDS_DESTINATIONORDER_BY_SOURCE_TIMESTAMP")), 
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_destination_order_cfgelems[] = {  
  ENUM("kind", NULL, 1, "DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, destination_order.kind),
    FUNCTIONS(0, uf_qos_destination_order, 0, pf_qos_destination_order),
    DESCRIPTION("<p>QOS destination_order kind.</p>"),
    VALUES("DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP", "DDS_DESTINATIONORDER_BY_SOURCE_TIMESTAMP")), 
  END_MARKER
};

static struct cfgelem ddsi_qos_durability_service_service_cleanup_delay_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_topic_listelem, durability_service.service_cleanup_delay),
    FUNCTIONS(0, uf_qos_durability_service_service_cleanup_delay_sec, 0, pf_qos_durability_service_service_cleanup_delay_sec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  INT("nanosec", NULL, 1,  "0",
    MEMBEROF(ddsi_qos_config_topic_listelem, durability_service.service_cleanup_delay),
    FUNCTIONS(0, uf_qos_durability_service_service_cleanup_delay_nanosec, 0, pf_qos_durability_service_service_cleanup_delay_nanosec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_durability_service_service_cleanup_delay_cfgelems[] = {
  INT("sec", NULL, 1,  "-1",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, durability_service.service_cleanup_delay),
    FUNCTIONS(0, uf_qos_datawriter_durability_service_service_cleanup_delay_sec, 0, pf_qos_datawriter_durability_service_service_cleanup_delay_sec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  INT("nanosec", NULL, 1,  "0",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, durability_service.service_cleanup_delay),
    FUNCTIONS(0, uf_qos_datawriter_durability_service_service_cleanup_delay_nanosec, 0, pf_qos_datawriter_durability_service_service_cleanup_delay_nanosec),
    DESCRIPTION("<p>Qos latency_budget duration.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_durability_service_cfgelems[] = {
  GROUP("service_cleanup_delay", ddsi_qos_durability_service_service_cleanup_delay_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic durability_service service_cleanup_delay.</p>"
    )),
  ENUM("history_kind", NULL, 1, "DDS_HISTORY_KEEP_LAST",
    MEMBEROF(ddsi_qos_config_topic_listelem, durability_service.history.kind),
    FUNCTIONS(0, uf_qos_history, 0, pf_qos_history),
    DESCRIPTION("<p>QOS durability_service history kind.</p>"),
    VALUES("DDS_HISTORY_KEEP_LAST", "DDS_HISTORY_KEEP_ALL")),
  INT("history_depth", NULL, 1, "1",
    MEMBEROF(ddsi_qos_config_topic_listelem, durability_service.history.depth),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos durability_service history depth.</p>")),
  STRING("max_samples", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_topic_listelem, durability_service.resource_limits.max_samples),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS durability_service history kind.</p>")),
  STRING("max_instances", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_topic_listelem, durability_service.resource_limits.max_instances),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS durability_service history kind.</p>")),
  STRING("max_samples_per_instance", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_topic_listelem, durability_service.resource_limits.max_samples_per_instance),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS durability_service history kind.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_durability_service_cfgelems[] = {
  GROUP("service_cleanup_delay", ddsi_qos_datawriter_durability_service_service_cleanup_delay_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter durability_service service_cleanup_delay.</p>"
    )),
  ENUM("history_kind", NULL, 1, "DDS_HISTORY_KEEP_LAST",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, durability_service.history.kind),
    FUNCTIONS(0, uf_qos_history, 0, pf_qos_history),
    DESCRIPTION("<p>QOS durability_service history kind.</p>"),
    VALUES("DDS_HISTORY_KEEP_LAST", "DDS_HISTORY_KEEP_ALL")),
  INT("history_depth", NULL, 1, "1",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, durability_service.history.depth),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos durability_service history depth.</p>")),
  STRING("max_samples", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, durability_service.resource_limits.max_samples),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS durability_service history kind.</p>")),
  STRING("max_instances", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, durability_service.resource_limits.max_instances),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS durability_service history kind.</p>")),
  STRING("max_samples_per_instance", NULL, 1, "DDS_LENGTH_UNLIMITED",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, durability_service.resource_limits.max_samples_per_instance),
    FUNCTIONS(0, uf_qos_resource_limits, 0, pf_qos_resource_limits),
    DESCRIPTION("<p>QOS durability_service history kind.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_topic_data_cfgelems[] = {
  STRING("value", NULL, 1, "",
    MEMBEROF(ddsi_qos_config_topic_listelem, topic_data.value),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of topic topic_data.</p>"
    )),
  INT("length", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_topic_listelem, topic_data.length),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos participant topic_data length.</p>")),
  END_MARKER
};

static struct cfgelem qos_participant_user_data_cfgelems[] = {
  STRING("value", NULL, 1, "",
    MEMBEROF(ddsi_qos_config_participant_listelem, user_data.value),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of participant user_data.</p>"
    )),
  INT("length", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_participant_listelem, user_data.length),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos participant user_data length.</p>")),
  END_MARKER
};

static struct cfgelem qos_publisher_presentation_cfgelems[] = {
  ENUM("access_scope", NULL, 1, "DDS_PRESENTATION_INSTANCE",
    MEMBEROF(ddsi_qos_config_publisher_listelem, presentation.access_scope),
    FUNCTIONS(0, uf_qos_presentation_access_scope, 0, pf_qos_presentation_access_scope),
    DESCRIPTION("<p>QOS publisher presentation access_scope.</p>"),
    VALUES("DDS_PRESENTATION_INSTANCE", "DDS_PRESENTATION_TOPIC", "DDS_PRESENTATION_GROUP")),
  BOOL("coherent_access", NULL, 1, "false",
    MEMBEROF(ddsi_qos_config_publisher_listelem, presentation.coherent_access),
    FUNCTIONS(0, uf_boolean, 0, pf_boolean),
    DESCRIPTION(
      "<p>Qos presentation coherent_access.</p>"
    )),
  BOOL("ordered_access", NULL, 1, "false",
    MEMBEROF(ddsi_qos_config_publisher_listelem, presentation.ordered_access),
    FUNCTIONS(0, uf_boolean, 0, pf_boolean),
    DESCRIPTION(
      "<p>Qos presentation ordered_access.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_publisher_group_data_cfgelems[] = {
  STRING("value", NULL, 1, "",
    MEMBEROF(ddsi_qos_config_publisher_listelem, group_data.value),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of publisher group_data value.</p>"
    )),
  INT("length", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_publisher_listelem, group_data.length),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos publisher group_data length.</p>")),
  END_MARKER
};

static struct cfgelem qos_publisher_partition_cfgelems[] = {
  STRING("name", NULL, 1, "",
    MEMBEROF(ddsi_qos_config_publisher_listelem, partition.strs),
    FUNCTIONS(0, uf_patition, ff_patition, pf_patition),
    DESCRIPTION(
      "<p>The Qos of publisher partition str.</p>" 
    )),
  INT("n", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_publisher_listelem, partition.n),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos publisher partition n.</p>")),
  END_MARKER
};

static struct cfgelem qos_subscriber_presentation_cfgelems[] = {
  ENUM("access_scope", NULL, 1, "DDS_PRESENTATION_INSTANCE",
    MEMBEROF(ddsi_qos_config_subscriber_listelem, presentation.access_scope),
    FUNCTIONS(0, uf_qos_presentation_access_scope, 0, pf_qos_presentation_access_scope),
    DESCRIPTION("<p>QOS subscriber presentation access_scope.</p>"),
    VALUES("DDS_PRESENTATION_INSTANCE", "DDS_PRESENTATION_TOPIC", "DDS_PRESENTATION_GROUP")),
  BOOL("coherent_access", NULL, 1, "false",
    MEMBEROF(ddsi_qos_config_subscriber_listelem, presentation.coherent_access),
    FUNCTIONS(0, uf_boolean, 0, pf_boolean),
    DESCRIPTION(
      "<p>Qos presentation coherent_access.</p>"
    )),
  BOOL("ordered_access", NULL, 1, "false",
    MEMBEROF(ddsi_qos_config_subscriber_listelem, presentation.ordered_access),
    FUNCTIONS(0, uf_boolean, 0, pf_boolean),
    DESCRIPTION(
      "<p>Qos presentation ordered_access.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_subscriber_group_data_cfgelems[] = {
  STRING("value", NULL, 1, "",
    MEMBEROF(ddsi_qos_config_subscriber_listelem, group_data.value),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of subscriber group_data value.</p>"
    )),
  INT("length", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_subscriber_listelem, group_data.length),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos subscriber group_data length.</p>")),
  END_MARKER
};

static struct cfgelem qos_subscriber_partition_cfgelems[] = {
  STRING("name", NULL, 1, "",
    MEMBEROF(ddsi_qos_config_subscriber_listelem, partition.strs),
    FUNCTIONS(0, uf_patition, ff_patition, pf_patition),
    DESCRIPTION(
      "<p>The Qos of subscriber partition str.</p>" 
    )),
  INT("n", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_subscriber_listelem, partition.n),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos subscriber partition n.</p>")),
  END_MARKER
};

static struct cfgelem qos_datareader_user_data_cfgelems[] = {
  STRING("value", NULL, 1, "",
    MEMBEROF(ddsi_qos_config_datareader_listelem, user_data.value),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of datareader user_data.</p>"
    )),
  INT("length", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_datareader_listelem, user_data.length),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos datareader user_data length.</p>")),
  END_MARKER
};

static struct cfgelem qos_datawriter_user_data_cfgelems[] = {
  STRING("value", NULL, 1, "",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, user_data.value),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of datawriter user_data.</p>"
    )),
  INT("length", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, user_data.length),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION("<p>Qos datawriter user_data length.</p>")),
  END_MARKER
};

static struct cfgelem ddsi_qos_datawriter_ownership_strength_cfgelems[] = {
  INT("value", NULL, 1, "0",
    MEMBEROF(ddsi_qos_config_datawriter_listelem, ownership_strength.value),
    FUNCTIONS(0, uf_int, 0, pf_int),
    DESCRIPTION(
      "<p>The Qos of datawriter ownership_strength.</p>"
    )),
  END_MARKER
};
// end

static struct cfgelem qos_participant_cfgelems[] = {
  GROUP("user_data", qos_participant_user_data_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic user_data.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_participant_cfgattrs[] = {
  STRING("name", NULL, 0, NULL,
    MEMBEROF(ddsi_qos_config_participant_listelem, name),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of participant attributes.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_topic_cfgelems[] = {
  GROUP("topic_data", ddsi_qos_topic_data_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic topic_data.</p>"
    )),
  GROUP("durability", ddsi_qos_durability_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic durability.</p>"
    )),
  GROUP("history", ddsi_qos_history_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic history.</p>"
    )),
  GROUP("resource_limits", ddsi_qos_resource_limits_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic resource limits.</p>"
    )),
  GROUP("ownership", ddsi_qos_ownership_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic ownership.</p>"
    )),
  GROUP("reliability", ddsi_qos_reliability_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic reliability.</p>"
    )),
  GROUP("deadline", ddsi_qos_deadline_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic deadline.</p>"
    )),
  GROUP("liveliness", ddsi_qos_liveliness_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic liveliness.</p>"
    )),
  GROUP("lifespan", ddsi_qos_lifespan_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic lifespan.</p>"
    )),
  GROUP("latency_budget", ddsi_qos_latency_budget_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic latency_budget.</p>"
    )),
  GROUP("transport_priority", ddsi_qos_transport_priority_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic transport_priority.</p>"
    )),
  GROUP("destination_order", ddsi_qos_destination_order_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic destination_order.</p>"
    )),
  GROUP("durability_service", ddsi_qos_durability_service_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic durability_service.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_topic_cfgattrs[] = {
  STRING("name", NULL, 0, NULL,
    MEMBEROF(ddsi_qos_config_topic_listelem, name),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of topic attributes.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_publisher_cfgelems[] = {
  GROUP("presentation", qos_publisher_presentation_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of publisher presentation.</p>"
    )),
  GROUP("group_data", qos_publisher_group_data_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of publisher group_data.</p>"
    )),
  GROUP("partition", qos_publisher_partition_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of publisher partition.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_publisher_cfgattrs[] = {
  STRING("name", NULL, 0, NULL,
    MEMBEROF(ddsi_qos_config_publisher_listelem, name),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of publisher attributes.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_subscriber_cfgelems[] = {
  GROUP("presentation", qos_subscriber_presentation_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of subscriber presentation.</p>"
    )),
  GROUP("group_data", qos_subscriber_group_data_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of subscriber group_data.</p>"
    )),
  GROUP("partition", qos_subscriber_partition_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of subscriber partition.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_subscriber_cfgattrs[] = {
  STRING("name", NULL, 0, NULL,
    MEMBEROF(ddsi_qos_config_subscriber_listelem, name),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of subscriber attributes.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_datareader_cfgelems[] = {
  GROUP("user_data", qos_datareader_user_data_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader user_data.</p>"
    )),
  GROUP("durability", ddsi_qos_datareader_durability_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader durability.</p>"
    )),
  GROUP("history", ddsi_qos_datareader_history_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader history.</p>"
    )),
  GROUP("resource_limits", ddsi_qos_datareader_resource_limits_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader resource limits.</p>"
    )),
  GROUP("ownership", ddsi_qos_datareader_ownership_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader ownership.</p>"
    )),
  GROUP("reliability", ddsi_qos_datareader_reliability_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader reliability.</p>"
    )),
  GROUP("deadline", ddsi_qos_datareader_deadline_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader deadline.</p>"
    )),
  GROUP("liveliness", ddsi_qos_datareader_liveliness_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader liveliness.</p>"
    )),
  GROUP("latency_budget", ddsi_qos_datareader_latency_budget_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader latency_budget.</p>"
    )),
  GROUP("destination_order", ddsi_qos_datareader_destination_order_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader destination_order.</p>"
    )),
  GROUP("reader_data_lifecycle", ddsi_qos_datareader_reader_data_lifecycle_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datareader reader_data_lifecycle.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_datareader_cfgattrs[] = {
  STRING("name", NULL, 0, NULL,
    MEMBEROF(ddsi_qos_config_datareader_listelem, name),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of datareader attributes.</p>"
    )),
  END_MARKER
};


static struct cfgelem qos_datawriter_cfgelems[] = {
  GROUP("user_data", qos_datawriter_user_data_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter user_data.</p>"
    )),
  GROUP("durability", ddsi_qos_datawriter_durability_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter durability.</p>"
    )),
  GROUP("history", ddsi_qos_datawriter_history_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter history.</p>"
    )),
  GROUP("resource_limits", ddsi_qos_datawriter_resource_limits_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter resource limits.</p>"
    )),
  GROUP("ownership", ddsi_qos_datawriter_ownership_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter ownership.</p>"
    )),
  GROUP("ownership_strength", ddsi_qos_datawriter_ownership_strength_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter ownership_strength.</p>"
    )),
  GROUP("reliability", ddsi_qos_datawriter_reliability_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter reliability.</p>"
    )),
  GROUP("deadline", ddsi_qos_datawriter_deadline_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter deadline.</p>"
    )),
  GROUP("liveliness", ddsi_qos_datawriter_liveliness_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter liveliness.</p>"
    )),
  GROUP("latency_budget", ddsi_qos_datawriter_latency_budget_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter latency_budget.</p>"
    )),
  GROUP("destination_order", ddsi_qos_datawriter_destination_order_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter destination_order.</p>"
    )),
  GROUP("writer_data_lifecycle", ddsi_qos_datawriter_writer_data_lifecycle_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter reader_data_lifecycle.</p>"
    )),
  GROUP("lifespan", ddsi_qos_datawriter_lifespan_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter lifespan.</p>"
    )),
   GROUP("transport_priority", ddsi_qos_datawriter_transport_priority_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of datawriter transport_priority.</p>"
    )),
  GROUP("durability_service", ddsi_qos_datawriter_durability_service_cfgelems, NULL, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION(
      "<p>The Qos of topic durability_service.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_datawriter_cfgattrs[] = {
  STRING("name", NULL, 0, NULL,
    MEMBEROF(ddsi_qos_config_datawriter_listelem, name),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of datawriter attributes.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_profile_cfgelems[] = {
  GROUP("participant_qos", qos_participant_cfgelems, qos_participant_cfgattrs, INT_MAX,
    MEMBEROF(ddsi_qos_config_profile_listelem, qos_participants),
    FUNCTIONS(if_domain_participant_qos, 0, 0, 0),
    DESCRIPTION(
      "<p>The list of participant Qos.</p>"
    )),
  GROUP("topic_qos", qos_topic_cfgelems, qos_topic_cfgattrs, INT_MAX,
    MEMBEROF(ddsi_qos_config_profile_listelem, qos_topic),
    FUNCTIONS(if_topic_qos, 0, 0, 0),
    DESCRIPTION(
      "<p>The list of topic Qos.</p>"
    )),
  GROUP("publisher_qos", qos_publisher_cfgelems, qos_publisher_cfgattrs, INT_MAX,
    MEMBEROF(ddsi_qos_config_profile_listelem, qos_publisher),
    FUNCTIONS(if_publisher_qos, 0, 0, 0),
    DESCRIPTION(
      "<p>The list of publisher Qos.</p>"
    )),
  GROUP("subscriber_qos", qos_subscriber_cfgelems, qos_subscriber_cfgattrs, INT_MAX,
    MEMBEROF(ddsi_qos_config_profile_listelem, qos_subscriber),
    FUNCTIONS(if_subscriber_qos, 0, 0, 0),
    DESCRIPTION(
      "<p>The list of subscriber Qos.</p>"
    )),
  GROUP("datareader_qos", qos_datareader_cfgelems, qos_datareader_cfgattrs, INT_MAX,
    MEMBEROF(ddsi_qos_config_profile_listelem, qos_datareader),
    FUNCTIONS(if_datareader_qos, 0, 0, 0),
    DESCRIPTION(
      "<p>The list of datareader Qos.</p>"
    )),
  GROUP("datawriter_qos", qos_datawriter_cfgelems, qos_datawriter_cfgattrs, INT_MAX,
    MEMBEROF(ddsi_qos_config_profile_listelem, qos_datawriter),
    FUNCTIONS(if_datawriter_qos, 0, 0, 0),
    DESCRIPTION(
      "<p>The list of datareader Qos.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_profile_cfgattrs[] = {
  STRING("name", NULL, 0, NULL,
    MEMBEROF(ddsi_qos_config_profile_listelem, name),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of profile attributes.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_librarys_cfgelems[] = {
  GROUP("qos_profile", qos_profile_cfgelems, qos_profile_cfgattrs, INT_MAX,
    MEMBEROF(ddsi_qos_config_library_listelem, qos_profiles),
    FUNCTIONS(if_qos_profile, 0, 0, 0),
    DESCRIPTION(
      "<p>The list of profile elements.</p>"
    )),
  END_MARKER
};

static struct cfgelem qos_librarys_cfgattrs[] = {
  STRING("name", NULL, 0, NULL,
    MEMBEROF(ddsi_qos_config_library_listelem, name),
    FUNCTIONS(0, uf_string, ff_free, pf_string),
    DESCRIPTION(
      "<p>The Qos of library attributes.</p>"
    )),
  END_MARKER
};

/* root node */
static struct cfgelem qos_root_cfgelems[] = {
  GROUP("qos_library", qos_librarys_cfgelems, qos_librarys_cfgattrs, INT_MAX,
    QOSMEMBER(qos_librarys),
    FUNCTIONS(if_qos_library, 0, 0, 0),
    DESCRIPTION(
      "<p>The General Qos element.</p>"
    )),
  MOVED("qos_library", "AutoCoreDDS/Domain/Qos_librarys"), 
  END_MARKER
};


static struct cfgelem qos_root_cfgattrs[] = {
  NOP("xmlns"),
  NOP("xmlns:xsi"),
  NOP("xsi:schemaLocation"),
  NOP("xsi:noNamespaceSchemaLocation"),
  END_MARKER
};

/* General entrance to the API */
static struct cfgelem autocoredds_qos_root_cfgelems[] = {
  GROUP("AutoCoreDDS", qos_root_cfgelems, qos_root_cfgattrs, 1,
    NOMEMBER,
    NOFUNCTIONS,
    DESCRIPTION("AutoCoreDDS configuration")),
  END_MARKER
};

#endif /* DDSI_QOSCFGELEMS_H */
