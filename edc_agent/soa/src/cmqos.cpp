#include "cmqos.h"

typedef uint32_t qos_entitie;

dds_qos_t* create_qos(qos_params* qps, qos_entitie qe) {
	if (qe != QE_READER && qe != QE_WRITER) {
		return NULL;
	}

	if (!qps) {
		return NULL;
	}

	if (!(qps->durability_qec & qe ||
		qps->durability_service_qec & qe ||
		qps->groupdata_qec & qe ||
		qps->history_qec & qe ||
		qps->lifespan_qec & qe ||
		qps->liveliness_qec & qe ||
		qps->reliability_qec & qe ||
		qps->resource_limits_qec & qe ||
		qps->topicdata_qec & qe ||
		qps->userdata_qec & qe)) {
		return NULL;
	}

	dds_qos_t* qos = dds_create_qos();

	if (qps->durability_qec & qe) {
		dds_qset_durability(qos, qps->durability.kind);
	}

	if (qps->durability_service_qec & qe) {
		dds_qset_durability_service(qos,
			qps->durability_service.service_cleanup_delay,
			qps->durability_service.history.kind,
			qps->durability_service.history.depth,
			qps->durability_service.resource_limits.max_samples,
			qps->durability_service.resource_limits.max_instances,
			qps->durability_service.resource_limits.max_samples_per_instance);
	}

	if (qps->groupdata_qec & qe) {
		dds_qset_groupdata(qos,
			qps->groupdata.value,
			qps->groupdata.length);
	}

	if (qps->history_qec & qe) {
		dds_qset_history(qos,
			qps->history.kind,
			qps->history.depth);
	}

	if (qps->lifespan_qec & qe) {
		dds_qset_lifespan(qos, qps->lifespan.duration);
	}

	if (qps->liveliness_qec & qe) {
		dds_qset_liveliness(qos,
			qps->liveliness.kind,
			qps->liveliness.lease_duration);
	}

	if (qps->reliability_qec & qe) {
		dds_qset_reliability(qos,
			qps->reliability.kind,
			qps->reliability.max_blocking_time);
	}

	if (qps->resource_limits_qec & qe) {
		dds_qset_resource_limits(qos,
			qps->resource_limits.max_samples,
			qps->resource_limits.max_instances,
			qps->resource_limits.max_samples_per_instance);
	}

	if (qps->topicdata_qec & qe) {
		dds_qset_topicdata(qos,
			qps->topicdata.value,
			qps->topicdata.length);
	}

	if (qps->userdata_qec & qe) {
		dds_qset_userdata(qos,
			qps->userdata.value,
			qps->userdata.length);
	}

	return qos;
}

dds_qos_t* create_participant_qos(qos_params* qps) {
	return create_qos(qps, QE_PARTICIPANT);
}

dds_qos_t* create_topic_qos(qos_params* qps) {
	return create_qos(qps, QE_TOPIC);
}

dds_qos_t* create_publisher_qos(qos_params* qps) {
	return create_qos(qps, QE_PUBLISHER);
}

dds_qos_t* create_subscriber_qos(qos_params* qps) {
	return create_qos(qps, QE_SUBSCRIBER);
}

dds_qos_t* create_writer_qos(qos_params* qps) {
	return create_qos(qps, QE_WRITER);
}

dds_qos_t* create_reader_qos(qos_params* qps) {
	return create_qos(qps, QE_READER);
}

void delete_qos(dds_qos_t* qos) {
	if (!qos) {
		return;
	}

	dds_delete_qos(qos);
}