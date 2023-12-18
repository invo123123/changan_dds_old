/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V3.0
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-16T13:32:48
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Cnr_DoorLockDrvAll_SKELETON_HPP
#define Cnr_DoorLockDrvAll_SKELETON_HPP
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
        class Cnr_DoorLockDrvAll_Ntf_SrvOperInfo{
            private:
                dds_rpc_handle_t dds_Ntf_SrvOperInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Cnr_DoorLockDrvAll_skeleton_Ntf_SrvOperInfo";
			public:
			    Cnr_DoorLockDrvAll_Ntf_SrvOperInfo() {
			    }
			    ~Cnr_DoorLockDrvAll_Ntf_SrvOperInfo() {
                }
                void send(const OperationInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Cnr_DoorLockDrvAll_Ntf_SrvOperInfo_Hash;
					ntf_message._u.Car_Control_Cnr_DoorLockDrvAll_Ntf_SrvOperInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Cnr_DoorLockDrvAll_Ntf_SrvOperInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Cnr_DoorLockDrvAll_Ntf_OperationCode{
            private:
                dds_rpc_handle_t dds_Ntf_OperationCode_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Cnr_DoorLockDrvAll_skeleton_Ntf_OperationCode";
			public:
			    Cnr_DoorLockDrvAll_Ntf_OperationCode() {
			    }
			    ~Cnr_DoorLockDrvAll_Ntf_OperationCode() {
                }
                void send(const OperationCode &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Cnr_DoorLockDrvAll_Ntf_OperationCode_Hash;
					ntf_message._u.Car_Control_Cnr_DoorLockDrvAll_Ntf_OperationCode = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Cnr_DoorLockDrvAll_Ntf_OperationCode_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
	}
	extern void on_carControl_Cnr_DoorLockDrvAll_request_data_available(int32_t reader, void* arg);

	class Cnr_DoorLockDrvAll_service_interface {
	public:
	    virtual ~Cnr_DoorLockDrvAll_service_interface() = default;

		virtual OperationInfo Get_SrvOperInfo() = 0;
		virtual ResponseInfo RR_ObjDrv(const RequestInfo &RequestInfo,const uint8_t &MotCtrl) = 0;
	};
    class Cnr_DoorLockDrvAll_Skeleton :public Cnr_DoorLockDrvAll_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Cnr_DoorLockDrvAll_Skeleton(Cnr_DoorLockDrvAll_service_interface* service,std::string config="");
			bool init();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			OperationInfo Get_SrvOperInfo() {
				return this->_service->Get_SrvOperInfo();
			}
			ResponseInfo RR_ObjDrv(const RequestInfo &RequestInfo,const uint8_t &MotCtrl) {
				return this->_service->RR_ObjDrv(RequestInfo,MotCtrl);
			}
            dds_return_t send_reply(carControl_Car_Control_Reply* reply);
            events::Cnr_DoorLockDrvAll_Ntf_SrvOperInfo Ntf_SrvOperInfo;
            events::Cnr_DoorLockDrvAll_Ntf_OperationCode Ntf_OperationCode;


		private:
		    std::string _config;
			const std::string service_name="Cnr_DoorLockDrvAll_skeleton";
			Cnr_DoorLockDrvAll_service_interface * _service;

			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };
	};

}
}
}
}
}
#endif
