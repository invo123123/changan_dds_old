#pragma once
#include "dds/dds.h"
#include "dds/ddsi/ddsi_xqos.h"
#include <map>

using namespace std;

// QE: qos entity
#define QE_PARTICIPANT 0x1
#define QE_TOPIC       0x2
#define QE_PUBLISHER   0x4
#define QE_SUBSCRIBER  0x8
#define QE_WRITER      0x10
#define QE_READER      0x20

typedef uint32_t qe_combine;

#define DEFINE_QOS(type, name) type name; qe_combine name##_qec;
typedef struct qos_params {
	DEFINE_QOS(dds_durability_qospolicy_t, durability);
	DEFINE_QOS(dds_durability_service_qospolicy_t, durability_service);
	DEFINE_QOS(dds_groupdata_qospolicy_t, groupdata);
	DEFINE_QOS(dds_history_qospolicy_t, history);
	DEFINE_QOS(dds_lifespan_qospolicy_t, lifespan);
	DEFINE_QOS(dds_liveliness_qospolicy_t, liveliness);
	DEFINE_QOS(dds_reliability_qospolicy_t, reliability);
	DEFINE_QOS(dds_resource_limits_qospolicy_t, resource_limits);
	DEFINE_QOS(dds_topicdata_qospolicy_t, topicdata);
	DEFINE_QOS(dds_userdata_qospolicy_t, userdata);
} qos_params;

#ifdef __cplusplus
extern "C" {
#endif

	dds_qos_t* create_participant_qos(qos_params* qps);
	dds_qos_t* create_topic_qos(qos_params* qps);
	dds_qos_t* create_publisher_qos(qos_params* qps);
	dds_qos_t* create_subscriber_qos(qos_params* qps);
	dds_qos_t* create_writer_qos(qos_params* qps);
	dds_qos_t* create_reader_qos(qos_params* qps);
	void delete_qos(dds_qos_t* qos);

#ifdef __cplusplus
}
#endif