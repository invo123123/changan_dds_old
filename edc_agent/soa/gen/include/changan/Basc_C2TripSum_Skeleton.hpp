/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.1
  ServiceLatestModifyTime: 2023-08-17T18:17:18
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_C2TripSum_SKELETON_HPP
#define Basc_C2TripSum_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_C2TripSum.h"
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
        class Basc_C2TripSum_C2TripSummary{
            private:
                dds_rpc_handle_t dds_C2TripSummary_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_C2TripSum_skeleton_C2TripSummary";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_C2TripSum_Ntf_desc, &dds_C2TripSummary_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_C2TripSummary_event_handle);
				}
				void send(const C2TripSum &data) {
					carDrive_Basc_C2TripSum_Ntf event_data;
					event_data.data._d = carDrive_Basc_C2TripSum_C2TripSummary_Hash;
					event_data.data._u.Basc_C2TripSum_C2TripSummary = data;
                    dds_write(dds_C2TripSummary_event_handle.writer, &event_data);
				}
        };
	}

	class Basc_C2TripSum_service_interface {
	public:
	    virtual ~Basc_C2TripSum_service_interface() = default;

	};
    class Basc_C2TripSum_Skeleton :public Basc_C2TripSum_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_C2TripSum_Skeleton(Basc_C2TripSum_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
            events::Basc_C2TripSum_C2TripSummary C2TripSummary;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_C2TripSum_skeleton";
			Basc_C2TripSum_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

