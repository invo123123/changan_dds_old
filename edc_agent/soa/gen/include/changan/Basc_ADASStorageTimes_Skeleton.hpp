/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.0
  ServiceLatestModifyTime: 2023-09-11T10:10:34
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_ADASStorageTimes_SKELETON_HPP
#define Basc_ADASStorageTimes_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_ADASStorageTimes.h"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include <mutex>
namespace com {
namespace changan {
namespace carDrive {
namespace C2Controller {
namespace skeleton {
	namespace events {
        class Basc_ADASStorageTimes_Ntf_ADASStorageTimes{
            private:
                dds_rpc_handle_t dds_Ntf_ADASStorageTimes_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_ADASStorageTimes_skeleton_Ntf_ADASStorageTimes";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_ADASStorageTimes_Ntf_desc, &dds_Ntf_ADASStorageTimes_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_ADASStorageTimes_event_handle);
				}
				void send(const C2_ADASStorageTimes &data) {
					carDrive_Basc_ADASStorageTimes_Ntf event_data;
					event_data.data._d = carDrive_Basc_ADASStorageTimes_Ntf_ADASStorageTimes_Hash;
					event_data.data._u.Basc_ADASStorageTimes_Ntf_ADASStorageTimes = data;
                    dds_write(dds_Ntf_ADASStorageTimes_event_handle.writer, &event_data);
				}
        };
	}
	extern void on_carDrive_Basc_ADASStorageTimes_request_data_available(int32_t reader, void* arg);

	class Basc_ADASStorageTimes_service_interface {
	public:
	    virtual ~Basc_ADASStorageTimes_service_interface() = default;

		virtual C2_ADASStorageTimes Get_ADASStorageTimes() = 0;
	};
    class Basc_ADASStorageTimes_Skeleton :public Basc_ADASStorageTimes_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_ADASStorageTimes_Skeleton(Basc_ADASStorageTimes_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			C2_ADASStorageTimes Get_ADASStorageTimes() {
				return this->_service->Get_ADASStorageTimes();
			}
            dds_return_t send_reply(carDrive_Basc_ADASStorageTimes_Reply* reply);
            events::Basc_ADASStorageTimes_Ntf_ADASStorageTimes Ntf_ADASStorageTimes;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_ADASStorageTimes_skeleton";
			Basc_ADASStorageTimes_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

