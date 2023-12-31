/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V1.0
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-15T18:37:07
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Cnr_TPMSWarn_SKELETON_HPP
#define Cnr_TPMSWarn_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/string_util.hpp"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include "changan/Car_Control_fl_Skeleton.hpp"
#include "changan/Car_Control.h"
#include <mutex>
namespace com {
namespace changan {
namespace carControl {
namespace Tyre {
namespace skeleton {
	namespace events {
		using CarControlFLSkeleton = com::changan::carControl::skeleton::CarControlFLSkeleton;
        class Cnr_TPMSWarn_Ntf_TireWarnInfo{
            private:
                dds_rpc_handle_t dds_Ntf_TireWarnInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Cnr_TPMSWarn_skeleton_Ntf_TireWarnInfo";
			public:
			    Cnr_TPMSWarn_Ntf_TireWarnInfo() {
			    }
			    ~Cnr_TPMSWarn_Ntf_TireWarnInfo() {
                }
                void send(const TireWarnInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Cnr_TPMSWarn_Ntf_TireWarnInfo_Hash;
					ntf_message._u.Car_Control_Cnr_TPMSWarn_Ntf_TireWarnInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Cnr_TPMSWarn_Ntf_TireWarnInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
	}
	extern void on_carControl_Cnr_TPMSWarn_request_data_available(int32_t reader, void* arg);

	class Cnr_TPMSWarn_service_interface {
	public:
	    virtual ~Cnr_TPMSWarn_service_interface() = default;

		virtual TireWarnInfo Get_TireWarnInfo() = 0;
	};
    class Cnr_TPMSWarn_Skeleton :public Cnr_TPMSWarn_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Cnr_TPMSWarn_Skeleton(Cnr_TPMSWarn_service_interface* service,std::string config="");
			bool init();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			TireWarnInfo Get_TireWarnInfo() {
				return this->_service->Get_TireWarnInfo();
			}
            dds_return_t send_reply(carControl_Car_Control_Reply* reply);
            events::Cnr_TPMSWarn_Ntf_TireWarnInfo Ntf_TireWarnInfo;


		private:
		    std::string _config;
			const std::string service_name="Cnr_TPMSWarn_skeleton";
			Cnr_TPMSWarn_service_interface * _service;

			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };
	};

}
}
}
}
}
#endif

