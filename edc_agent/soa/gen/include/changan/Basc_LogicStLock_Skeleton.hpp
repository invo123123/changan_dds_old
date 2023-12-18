/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V3.1
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-30T20:52:19
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_LogicStLock_SKELETON_HPP
#define Basc_LogicStLock_SKELETON_HPP
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
namespace DoorLock {
namespace skeleton {
	namespace events {
		using CarControlFLSkeleton = com::changan::carControl::skeleton::CarControlFLSkeleton;
        class Basc_LogicStLock_Ntf_LocStAll{
            private:
                dds_rpc_handle_t dds_Ntf_LocStAll_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_LogicStLock_skeleton_Ntf_LocStAll";
			public:
			    Basc_LogicStLock_Ntf_LocStAll() {
			    }
			    ~Basc_LogicStLock_Ntf_LocStAll() {
                }
                void send(const LockStAll_Struct &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_LogicStLock_Ntf_LocStAll_Hash;
					ntf_message._u.Car_Control_Basc_LogicStLock_Ntf_LocStAll = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_LogicStLock_Ntf_LocStAll_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
	}
	extern void on_carControl_Basc_LogicStLock_request_data_available(int32_t reader, void* arg);

	class Basc_LogicStLock_service_interface {
	public:
	    virtual ~Basc_LogicStLock_service_interface() = default;

		virtual LockStAll_Struct Get_LocStAll() = 0;
	};
    class Basc_LogicStLock_Skeleton :public Basc_LogicStLock_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_LogicStLock_Skeleton(Basc_LogicStLock_service_interface* service,std::string config="");
			bool init();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			LockStAll_Struct Get_LocStAll() {
				return this->_service->Get_LocStAll();
			}
            dds_return_t send_reply(carControl_Car_Control_Reply* reply);
            events::Basc_LogicStLock_Ntf_LocStAll Ntf_LocStAll;


		private:
		    std::string _config;
			const std::string service_name="Basc_LogicStLock_skeleton";
			Basc_LogicStLock_service_interface * _service;

			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };
	};

}
}
}
}
}
#endif
