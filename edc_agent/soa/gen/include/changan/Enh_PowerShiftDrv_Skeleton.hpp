/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V2.9
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-07-25T13:01:32
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Enh_PowerShiftDrv_SKELETON_HPP
#define Enh_PowerShiftDrv_SKELETON_HPP
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
namespace PDU {
namespace skeleton {
	namespace events {
		using CarControlFLSkeleton = com::changan::carControl::skeleton::CarControlFLSkeleton;
        class Enh_PowerShiftDrv_Ntf_SrvOperInfo{
            private:
                dds_rpc_handle_t dds_Ntf_SrvOperInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_PowerShiftDrv_skeleton_Ntf_SrvOperInfo";
			public:
			    Enh_PowerShiftDrv_Ntf_SrvOperInfo() {
			    }
			    ~Enh_PowerShiftDrv_Ntf_SrvOperInfo() {
                }
                void send(const OperationInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_PowerShiftDrv_Ntf_SrvOperInfo_Hash;
					ntf_message._u.Car_Control_Enh_PowerShiftDrv_Ntf_SrvOperInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_PowerShiftDrv_Ntf_SrvOperInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Enh_PowerShiftDrv_Ntf_PowerShiftSwtSt{
            private:
                dds_rpc_handle_t dds_Ntf_PowerShiftSwtSt_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_PowerShiftDrv_skeleton_Ntf_PowerShiftSwtSt";
			public:
			    Enh_PowerShiftDrv_Ntf_PowerShiftSwtSt() {
			    }
			    ~Enh_PowerShiftDrv_Ntf_PowerShiftSwtSt() {
                }
				void send(const carControl_Secure_Car_Control_Enh_PowerShiftDrv_Ntf_PowerShiftSwtSt_uint8 &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_PowerShiftDrv_Ntf_PowerShiftSwtSt_Hash;
					ntf_message._u.Car_Control_Enh_PowerShiftDrv_Ntf_PowerShiftSwtSt = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_PowerShiftDrv_Ntf_PowerShiftSwtSt_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Enh_PowerShiftDrv_Ntf_OTALockSt{
            private:
                dds_rpc_handle_t dds_Ntf_OTALockSt_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_PowerShiftDrv_skeleton_Ntf_OTALockSt";
			public:
			    Enh_PowerShiftDrv_Ntf_OTALockSt() {
			    }
			    ~Enh_PowerShiftDrv_Ntf_OTALockSt() {
                }
                void send(const uint8_t &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_PowerShiftDrv_Ntf_OTALockSt_Hash;
					ntf_message._u.Car_Control_Enh_PowerShiftDrv_Ntf_OTALockSt = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_PowerShiftDrv_Ntf_OTALockSt_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Enh_PowerShiftDrv_Ntf_PwrPinRstInfo{
            private:
                dds_rpc_handle_t dds_Ntf_PwrPinRstInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_PowerShiftDrv_skeleton_Ntf_PwrPinRstInfo";
			public:
			    Enh_PowerShiftDrv_Ntf_PwrPinRstInfo() {
			    }
			    ~Enh_PowerShiftDrv_Ntf_PwrPinRstInfo() {
                }
                void send(const VIUPwrPortRstInfo_Struct &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_PowerShiftDrv_Ntf_PwrPinRstInfo_Hash;
					ntf_message._u.Car_Control_Enh_PowerShiftDrv_Ntf_PwrPinRstInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_PowerShiftDrv_Ntf_PwrPinRstInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Enh_PowerShiftDrv_Ntf_PowerShiftSwtStVld{
            private:
                dds_rpc_handle_t dds_Ntf_PowerShiftSwtStVld_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_PowerShiftDrv_skeleton_Ntf_PowerShiftSwtStVld";
			public:
			    Enh_PowerShiftDrv_Ntf_PowerShiftSwtStVld() {
			    }
			    ~Enh_PowerShiftDrv_Ntf_PowerShiftSwtStVld() {
                }
				void send(const carControl_Secure_Car_Control_Enh_PowerShiftDrv_Ntf_PowerShiftSwtStVld_uint8 &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_PowerShiftDrv_Ntf_PowerShiftSwtStVld_Hash;
					ntf_message._u.Car_Control_Enh_PowerShiftDrv_Ntf_PowerShiftSwtStVld = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_PowerShiftDrv_Ntf_PowerShiftSwtStVld_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Enh_PowerShiftDrv_Ntf_OperationCode{
            private:
                dds_rpc_handle_t dds_Ntf_OperationCode_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_PowerShiftDrv_skeleton_Ntf_OperationCode";
			public:
			    Enh_PowerShiftDrv_Ntf_OperationCode() {
			    }
			    ~Enh_PowerShiftDrv_Ntf_OperationCode() {
                }
				void send(const carControl_Secure_Car_Control_Enh_PowerShiftDrv_Ntf_OperationCode_OperationCode &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_PowerShiftDrv_Ntf_OperationCode_Hash;
					ntf_message._u.Car_Control_Enh_PowerShiftDrv_Ntf_OperationCode = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_PowerShiftDrv_Ntf_OperationCode_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
	}
	extern void on_carControl_Enh_PowerShiftDrv_request_data_available(int32_t reader, void* arg);

	class Enh_PowerShiftDrv_service_interface {
	public:
	    virtual ~Enh_PowerShiftDrv_service_interface() = default;

		virtual ResponseInfo RR_PowerOn(const uint8_t &PowerCmd,const RequestInfo &RequestInfo) = 0;
		virtual OperationInfo Get_SrvOperInfo() = 0;
		virtual uint8_t Get_PowerShiftSwtSt() = 0;
		virtual ResponseInfo RR_PwrPinCtr(const uint8_t &OTAWGroupStatus,const RequestInfo &RequestInfo,const uint8_t &NUM,const PwrPortCtr_Struct &PwrPortCtr) = 0;
	};
    class Enh_PowerShiftDrv_Skeleton :public Enh_PowerShiftDrv_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Enh_PowerShiftDrv_Skeleton(Enh_PowerShiftDrv_service_interface* service,std::string config="");
			bool init();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			ResponseInfo RR_PowerOn(const uint8_t &PowerCmd,const RequestInfo &RequestInfo) {
				return this->_service->RR_PowerOn(PowerCmd,RequestInfo);
			}
			OperationInfo Get_SrvOperInfo() {
				return this->_service->Get_SrvOperInfo();
			}
			uint8_t Get_PowerShiftSwtSt() {
				return this->_service->Get_PowerShiftSwtSt();
			}
			ResponseInfo RR_PwrPinCtr(const uint8_t &OTAWGroupStatus,const RequestInfo &RequestInfo,const uint8_t &NUM,const PwrPortCtr_Struct &PwrPortCtr) {
				return this->_service->RR_PwrPinCtr(OTAWGroupStatus,RequestInfo,NUM,PwrPortCtr);
			}
            dds_return_t send_reply(carControl_Car_Control_Reply* reply);
            events::Enh_PowerShiftDrv_Ntf_SrvOperInfo Ntf_SrvOperInfo;
            events::Enh_PowerShiftDrv_Ntf_PowerShiftSwtSt Ntf_PowerShiftSwtSt;
            events::Enh_PowerShiftDrv_Ntf_OTALockSt Ntf_OTALockSt;
            events::Enh_PowerShiftDrv_Ntf_PwrPinRstInfo Ntf_PwrPinRstInfo;
            events::Enh_PowerShiftDrv_Ntf_PowerShiftSwtStVld Ntf_PowerShiftSwtStVld;
            events::Enh_PowerShiftDrv_Ntf_OperationCode Ntf_OperationCode;


		private:
		    std::string _config;
			const std::string service_name="Enh_PowerShiftDrv_skeleton";
			Enh_PowerShiftDrv_service_interface * _service;

			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };
	};

}
}
}
}
}
#endif

