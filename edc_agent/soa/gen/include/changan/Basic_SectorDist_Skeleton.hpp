/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.1
  ServiceLatestModifyTime: 2022-09-20T16:11:37
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basic_SectorDist_SKELETON_HPP
#define Basic_SectorDist_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basic_SectorDist.h"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include <mutex>
namespace com {
namespace changan {
namespace carDrive {
namespace BasicService {
namespace skeleton {
	namespace events {
        class Basic_SectorDist_Ntf_SectorDist{
            private:
                dds_rpc_handle_t dds_Ntf_SectorDist_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basic_SectorDist_skeleton_Ntf_SectorDist";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basic_SectorDist_Ntf_desc, &dds_Ntf_SectorDist_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_SectorDist_event_handle);
				}
				void send(const DDSData_Msg &data) {
					carDrive_Basic_SectorDist_Ntf event_data;
					event_data.data._d = carDrive_Basic_SectorDist_Ntf_SectorDist_Hash;
					event_data.data._u.Basic_SectorDist_Ntf_SectorDist = data;
                    dds_write(dds_Ntf_SectorDist_event_handle.writer, &event_data);
				}
        };
	}
	extern void on_carDrive_Basic_SectorDist_request_data_available(int32_t reader, void* arg);

	class Basic_SectorDist_service_interface {
	public:
	    virtual ~Basic_SectorDist_service_interface() = default;

		virtual DDSData_Msg Get_SectorDist() = 0;
	};
    class Basic_SectorDist_Skeleton :public Basic_SectorDist_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basic_SectorDist_Skeleton(Basic_SectorDist_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			DDSData_Msg Get_SectorDist() {
				return this->_service->Get_SectorDist();
			}
            dds_return_t send_reply(carDrive_Basic_SectorDist_Reply* reply);
            events::Basic_SectorDist_Ntf_SectorDist Ntf_SectorDist;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basic_SectorDist_skeleton";
			Basic_SectorDist_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

