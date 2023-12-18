/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.10
  ServiceLatestModifyTime: 2023-08-22T09:49:06
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basic_SmartDrivingTips_SKELETON_HPP
#define Basic_SmartDrivingTips_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basic_SmartDrivingTips.h"
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
        class Basic_SmartDrivingTips_Ntf_SmartDriveTips{
            private:
                dds_rpc_handle_t dds_Ntf_SmartDriveTips_event_handle = { -1, -1, -1 };
				std::string _topic_name = "hmi_interface____HmiInterface__BasicSmartDrivingTips";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(0, _topic_name, &carDrive_Basic_SmartDrivingTips_Ntf_desc, &dds_Ntf_SmartDriveTips_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_SmartDriveTips_event_handle);
				}
				void send(const DDSData_Msg &data) {
					carDrive_Basic_SmartDrivingTips_Ntf event_data;
					event_data.data._d = carDrive_Basic_SmartDrivingTips_Ntf_SmartDriveTips_Hash;
					event_data.data._u.Basic_SmartDrivingTips_Ntf_SmartDriveTips = data;
                    dds_write(dds_Ntf_SmartDriveTips_event_handle.writer, &event_data);
				}
        };
	}

	class Basic_SmartDrivingTips_service_interface {
	public:
	    virtual ~Basic_SmartDrivingTips_service_interface() = default;

	};
    class Basic_SmartDrivingTips_Skeleton :public Basic_SmartDrivingTips_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basic_SmartDrivingTips_Skeleton(Basic_SmartDrivingTips_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
            events::Basic_SmartDrivingTips_Ntf_SmartDriveTips Ntf_SmartDriveTips;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basic_SmartDrivingTips_skeleton";
			Basic_SmartDrivingTips_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

