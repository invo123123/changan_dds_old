/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.5
  ServiceLatestModifyTime: 2023-11-21T15:42:15
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basic_APAFunctionReq_SKELETON_HPP
#define Basic_APAFunctionReq_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basic_APAFunctionReq.h"
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
        class Basic_APAFunctionReq_Ntf_APAFunctionRes{
            private:
                dds_rpc_handle_t dds_Ntf_APAFunctionRes_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basic_APAFunctionReq_skeleton_Ntf_APAFunctionRes";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basic_APAFunctionReq_Ntf_desc, &dds_Ntf_APAFunctionRes_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_APAFunctionRes_event_handle);
				}
				void send(const APAFunctionRes &data) {
					carDrive_Basic_APAFunctionReq_Ntf event_data;
					event_data.data._d = carDrive_Basic_APAFunctionReq_Ntf_APAFunctionRes_Hash;
					event_data.data._u.Basic_APAFunctionReq_Ntf_APAFunctionRes = data;
                    dds_write(dds_Ntf_APAFunctionRes_event_handle.writer, &event_data);
				}
        };
	}
	extern void on_carDrive_Basic_APAFunctionReq_request_data_available(int32_t reader, void* arg);

	class Basic_APAFunctionReq_service_interface {
	public:
	    virtual ~Basic_APAFunctionReq_service_interface() = default;

		virtual APAReqreply RR_APAFunctionReq(const APAFunctionReq &RR_APAFunctionReq) = 0;
		virtual APAReqreply RR_APAControleReq(const APAControleReq &APAControlReq) = 0;
	};
    class Basic_APAFunctionReq_Skeleton :public Basic_APAFunctionReq_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basic_APAFunctionReq_Skeleton(Basic_APAFunctionReq_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			APAReqreply RR_APAFunctionReq(const APAFunctionReq &RR_APAFunctionReq) {
				return this->_service->RR_APAFunctionReq(RR_APAFunctionReq);
			}
			APAReqreply RR_APAControleReq(const APAControleReq &APAControlReq) {
				return this->_service->RR_APAControleReq(APAControlReq);
			}
            dds_return_t send_reply(carDrive_Basic_APAFunctionReq_Reply* reply);
            events::Basic_APAFunctionReq_Ntf_APAFunctionRes Ntf_APAFunctionRes;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basic_APAFunctionReq_skeleton";
			Basic_APAFunctionReq_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif
