#ifndef DOMAIN_FACTORY_HPP
#define DOMAIN_FACTORY_HPP
#include "dds/dds.h"
#include <unordered_map>
#include <mutex>
#include "dds/ddsrt/environ.h"
#include <string>
namespace com {
	namespace changan {
		class DomainFactory {
		public:
			static dds_entity_t create_participant(uint32_t domain_id, uint8_t setup_token);
			static dds_entity_t create_participant(uint32_t domain_id, uint8_t setup_token, std::string config_path);
			static dds_entity_t create_participant(uint32_t domain_id, uint8_t setup_token, std::string config_path, dds_listener_t *plistener);
			static dds_entity_t create_participant(uint32_t domain_id, uint8_t setup_token, std::string config_path, dds_qos_t * qos, dds_listener_t *plistener);
		private:
			static std::mutex mutex_;
			static std::unordered_map<std::string, dds_entity_t>
				participant_map_;
		};
	}
}
#endif // !DOMAIN_FACTORY_HPP
