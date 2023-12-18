/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V2.1
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-15T18:31:05
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Enh_Horn_SKELETON_HPP
#define Enh_Horn_SKELETON_HPP
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
namespace Horn {
namespace skeleton {
	namespace events {
		using CarControlFLSkeleton = com::changan::carControl::skeleton::CarControlFLSkeleton;
        class Enh_Horn_Ntf_SrvOperInfo{
            private:
                dds_rpc_handle_t dds_Ntf_SrvOperInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_Horn_skeleton_Ntf_SrvOperInfo";
			public:
			    Enh_Horn_Ntf_SrvOperInfo() {
			    }
			    ~Enh_Horn_Ntf_SrvOperInfo() {
                }
                void send(const OperationInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_Horn_Ntf_SrvOperInfo_Hash;
					ntf_message._u.Car_Control_Enh_Horn_Ntf_SrvOperInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_Horn_Ntf_SrvOperInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Enh_Horn_Ntf_HornLogicSt{
            private:
                dds_rpc_handle_t dds_Ntf_HornLogicSt_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_Horn_skeleton_Ntf_HornLogicSt";
			public:
			    Enh_Horn_Ntf_HornLogicSt() {
			    }
			    ~Enh_Horn_Ntf_HornLogicSt() {
                }
                void send(const uint8_t &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_Horn_Ntf_HornLogicSt_Hash;
					ntf_message._u.Car_Control_Enh_Horn_Ntf_HornLogicSt = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_Horn_Ntf_HornLogicSt_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Enh_Horn_Ntf_OperationCode{
            private:
                dds_rpc_handle_t dds_Ntf_OperationCode_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Enh_Horn_skeleton_Ntf_OperationCode";
			public:
			    Enh_Horn_Ntf_OperationCode() {
			    }
			    ~Enh_Horn_Ntf_OperationCode() {
                }
                void send(const OperationCode &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Enh_Horn_Ntf_OperationCode_Hash;
					ntf_message._u.Car_Control_Enh_Horn_Ntf_OperationCode = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Enh_Horn_Ntf_OperationCode_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
	}
	extern void on_carControl_Enh_Horn_request_data_available(int32_t reader, void* arg);

	class Enh_Horn_service_interface {
	public:
	    virtual ~Enh_Horn_service_interface() = default;

		virtual ResponseInfo RR_HornCtrl(const HornCtrlCmd &HornCtrlCmd,const RequestInfo &RequestInfo) = 0;
		virtual OperationInfo Get_SrvOperInfo() = 0;
		virtual uint8_t Get_HornLogicSt() = 0;
	};
    class Enh_Horn_Skeleton :public Enh_Horn_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Enh_Horn_Skeleton(Enh_Horn_service_interface* service,std::string config="");
			bool init();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			ResponseInfo RR_HornCtrl(const HornCtrlCmd &HornCtrlCmd,const RequestInfo &RequestInfo) {
				return this->_service->RR_HornCtrl(HornCtrlCmd,RequestInfo);
			}
			OperationInfo Get_SrvOperInfo() {
				return this->_service->Get_SrvOperInfo();
			}
			uint8_t Get_HornLogicSt() {
				return this->_service->Get_HornLogicSt();
			}
            dds_return_t send_reply(carControl_Car_Control_Reply* reply);
            events::Enh_Horn_Ntf_SrvOperInfo Ntf_SrvOperInfo;
            events::Enh_Horn_Ntf_HornLogicSt Ntf_HornLogicSt;
            events::Enh_Horn_Ntf_OperationCode Ntf_OperationCode;


		private:
		    std::string _config;
			const std::string service_name="Enh_Horn_skeleton";
			Enh_Horn_service_interface * _service;

			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };
	};

}
}
}
}
}
#endif
