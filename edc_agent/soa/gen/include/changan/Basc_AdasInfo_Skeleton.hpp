/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.0
  ServiceLatestModifyTime: 2023-01-30T17:08:11
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_AdasInfo_SKELETON_HPP
#define Basc_AdasInfo_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_AdasInfo.h"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include <mutex>
namespace com {
namespace changan {
namespace carCabin {
namespace Basc_AdasInfo {
namespace skeleton {
	namespace events {
        class Basc_AdasInfo_Ntf_ADAS_MapCommonSignal{
            private:
                dds_rpc_handle_t dds_Ntf_ADAS_MapCommonSignal_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_AdasInfo_skeleton_Ntf_ADAS_MapCommonSignal";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carCabin_Basc_AdasInfo_Ntf_desc, &dds_Ntf_ADAS_MapCommonSignal_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_ADAS_MapCommonSignal_event_handle);
				}
				void send(const ADAS_MapCommonSignal &data) {
					carCabin_Basc_AdasInfo_Ntf event_data;
					event_data.data._d = carCabin_Basc_AdasInfo_Ntf_ADAS_MapCommonSignal_Hash;
					event_data.data._u.Basc_AdasInfo_Ntf_ADAS_MapCommonSignal = data;
                    dds_write(dds_Ntf_ADAS_MapCommonSignal_event_handle.writer, &event_data);
				}
        };
        class Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal{
            private:
                dds_rpc_handle_t dds_Ntf_ADAS_MapNavigationSignal_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_AdasInfo_skeleton_Ntf_ADAS_MapNavigationSignal";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carCabin_Basc_AdasInfo_Ntf_desc, &dds_Ntf_ADAS_MapNavigationSignal_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_ADAS_MapNavigationSignal_event_handle);
				}
				void send(const ADAS_MapNavigationSignal &data) {
					carCabin_Basc_AdasInfo_Ntf event_data;
					event_data.data._d = carCabin_Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal_Hash;
					event_data.data._u.Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal = data;
                    dds_write(dds_Ntf_ADAS_MapNavigationSignal_event_handle.writer, &event_data);
				}
        };
        class Basc_AdasInfo_Ntf_AdasMapTrafficSign{
            private:
                dds_rpc_handle_t dds_Ntf_AdasMapTrafficSign_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_AdasInfo_skeleton_Ntf_AdasMapTrafficSign";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carCabin_Basc_AdasInfo_Ntf_desc, &dds_Ntf_AdasMapTrafficSign_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_AdasMapTrafficSign_event_handle);
				}
				void send(const ADAS_MapTrafficSign &data) {
					carCabin_Basc_AdasInfo_Ntf event_data;
					event_data.data._d = carCabin_Basc_AdasInfo_Ntf_AdasMapTrafficSign_Hash;
					event_data.data._u.Basc_AdasInfo_Ntf_AdasMapTrafficSign = data;
                    dds_write(dds_Ntf_AdasMapTrafficSign_event_handle.writer, &event_data);
				}
        };
	}

	class Basc_AdasInfo_service_interface {
	public:
	    virtual ~Basc_AdasInfo_service_interface() = default;

	};
    class Basc_AdasInfo_Skeleton :public Basc_AdasInfo_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_AdasInfo_Skeleton(Basc_AdasInfo_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
            events::Basc_AdasInfo_Ntf_ADAS_MapCommonSignal Ntf_ADAS_MapCommonSignal;
            events::Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal Ntf_ADAS_MapNavigationSignal;
            events::Basc_AdasInfo_Ntf_AdasMapTrafficSign Ntf_AdasMapTrafficSign;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_AdasInfo_skeleton";
			Basc_AdasInfo_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif
