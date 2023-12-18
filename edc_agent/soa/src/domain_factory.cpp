#include "changan/domain_factory.hpp"

namespace com {
	namespace changan {
		std::mutex DomainFactory::mutex_;
		std::unordered_map<std::string, dds_entity_t>
			DomainFactory::participant_map_;
		dds_entity_t DomainFactory::create_participant(uint32_t domain_id, uint8_t setup_token, std::string config_path, dds_qos_t * qos, dds_listener_t *plistener) {
			std::unique_lock<std::mutex> lock(mutex_);
   		    char DomainIdbuf[20];
			char SetupTokenbuf[20];
			sprintf(DomainIdbuf,"%d",domain_id);
			sprintf(SetupTokenbuf,"%d",setup_token);
			std::string domain_id_setup_token;
			domain_id_setup_token = domain_id_setup_token + DomainIdbuf + "_" + SetupTokenbuf;
			auto it = participant_map_.find(domain_id_setup_token);
			if (it != participant_map_.end()) {
				return it->second;
			}
			if (!config_path.empty()) {
				ddsrt_setenv("AUTOCOREDDS_URI", config_path.data());
			}
			dds_entity_t participant =dds_create_participant(domain_id, qos, plistener);
			while (participant <= 0) {
				dds_sleepfor(DDS_MSECS(1000));
				participant =dds_create_participant(domain_id, qos, plistener);;
			}
			participant_map_.emplace(domain_id_setup_token, participant);
			return participant;
		}
		dds_entity_t DomainFactory::create_participant(uint32_t domain_id, uint8_t setup_token, std::string config_path, dds_listener_t *plistener) {
			return DomainFactory::create_participant(domain_id, setup_token, config_path, NULL, plistener);
		}
		dds_entity_t DomainFactory::create_participant(uint32_t domain_id, uint8_t setup_token) {
			return DomainFactory::create_participant(domain_id, setup_token, "");
		}
		dds_entity_t DomainFactory::create_participant(uint32_t domain_id, uint8_t setup_token, std::string config_path) {
			return DomainFactory::create_participant(domain_id, setup_token, config_path, NULL);
		}

	}
}

