/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: v1.0
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-18T18:34:08
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_BucSwtSts_SKELETON_HPP
#define Basc_BucSwtSts_SKELETON_HPP
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
namespace BasicService {
namespace skeleton {
	namespace events {
		using CarControlFLSkeleton = com::changan::carControl::skeleton::CarControlFLSkeleton;
        class Basc_BucSwtSts_Ntf_BucSwtSts{
            private:
                dds_rpc_handle_t dds_Ntf_BucSwtSts_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_BucSwtSts_skeleton_Ntf_BucSwtSts";
			public:
			    Basc_BucSwtSts_Ntf_BucSwtSts() {
			    }
			    ~Basc_BucSwtSts_Ntf_BucSwtSts() {
                }
                void send(const BucSwtSts &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_BucSwtSts_Ntf_BucSwtSts_Hash;
					ntf_message._u.Car_Control_Basc_BucSwtSts_Ntf_BucSwtSts = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_BucSwtSts_Ntf_BucSwtSts_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
	}
	extern void on_carControl_Basc_BucSwtSts_request_data_available(int32_t reader, void* arg);

	class Basc_BucSwtSts_service_interface {
	public:
	    virtual ~Basc_BucSwtSts_service_interface() = default;

		virtual BucSwtSts Get_BucSwtSts() = 0;
	};
    class Basc_BucSwtSts_Skeleton :public Basc_BucSwtSts_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_BucSwtSts_Skeleton(Basc_BucSwtSts_service_interface* service,std::string config="");
			bool init();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			BucSwtSts Get_BucSwtSts() {
				return this->_service->Get_BucSwtSts();
			}
            dds_return_t send_reply(carControl_Car_Control_Reply* reply);
            events::Basc_BucSwtSts_Ntf_BucSwtSts Ntf_BucSwtSts;


		private:
		    std::string _config;
			const std::string service_name="Basc_BucSwtSts_skeleton";
			Basc_BucSwtSts_service_interface * _service;

			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };
	};

}
}
}
}
}
#endif

