/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.1
  ServiceLatestModifyTime: 2023-08-17T18:18:24
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_ADASScore_SKELETON_HPP
#define Basc_ADASScore_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_ADASScore.h"
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
        class Basc_ADASScore_Ntf_C2_ADASScore{
            private:
                dds_rpc_handle_t dds_Ntf_C2_ADASScore_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_ADASScore_skeleton_Ntf_C2_ADASScore";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_ADASScore_Ntf_desc, &dds_Ntf_C2_ADASScore_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_C2_ADASScore_event_handle);
				}
				void send(const C2_ADASScore &data) {
					carDrive_Basc_ADASScore_Ntf event_data;
					event_data.data._d = carDrive_Basc_ADASScore_Ntf_C2_ADASScore_Hash;
					event_data.data._u.Basc_ADASScore_Ntf_C2_ADASScore = data;
                    dds_write(dds_Ntf_C2_ADASScore_event_handle.writer, &event_data);
				}
        };
	}
	extern void on_carDrive_Basc_ADASScore_request_data_available(int32_t reader, void* arg);

	class Basc_ADASScore_service_interface {
	public:
	    virtual ~Basc_ADASScore_service_interface() = default;

		virtual C2_GetADASScore Get_C2_GetADASScore() = 0;
	};
    class Basc_ADASScore_Skeleton :public Basc_ADASScore_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_ADASScore_Skeleton(Basc_ADASScore_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			C2_GetADASScore Get_C2_GetADASScore() {
				return this->_service->Get_C2_GetADASScore();
			}
            dds_return_t send_reply(carDrive_Basc_ADASScore_Reply* reply);
            events::Basc_ADASScore_Ntf_C2_ADASScore Ntf_C2_ADASScore;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_ADASScore_skeleton";
			Basc_ADASScore_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

