/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.1.0
  ServiceLatestModifyTime: 2023-05-29T15:21:40
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_GpsData_SKELETON_HPP
#define Basc_GpsData_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_GpsData.h"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include <mutex>
namespace com {
namespace changan {
namespace carCabin {
namespace testClass {
namespace skeleton {
	namespace events {
        class Basc_GpsData_Evt_GpsData{
            private:
                dds_rpc_handle_t dds_Evt_GpsData_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_GpsData_skeleton_Evt_GpsData";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carCabin_Basc_GpsData_Ntf_desc, &dds_Evt_GpsData_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Evt_GpsData_event_handle);
				}
				void send(const GpsDatas &data) {
					carCabin_Basc_GpsData_Ntf event_data;
					event_data.data._d = carCabin_Basc_GpsData_Evt_GpsData_Hash;
					event_data.data._u.Basc_GpsData_Evt_GpsData = data;
                    dds_write(dds_Evt_GpsData_event_handle.writer, &event_data);
				}
        };
	}

	class Basc_GpsData_service_interface {
	public:
	    virtual ~Basc_GpsData_service_interface() = default;

	};
    class Basc_GpsData_Skeleton :public Basc_GpsData_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_GpsData_Skeleton(Basc_GpsData_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
            events::Basc_GpsData_Evt_GpsData Evt_GpsData;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_GpsData_skeleton";
			Basc_GpsData_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

