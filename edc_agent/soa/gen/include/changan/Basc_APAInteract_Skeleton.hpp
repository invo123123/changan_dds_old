/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.0.5
  ServiceLatestModifyTime: 2023-11-21T15:20:28
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_APAInteract_SKELETON_HPP
#define Basc_APAInteract_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_APAInteract.h"
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
        class Basc_APAInteract_Ntf_AD_APACustSlot{
            private:
                dds_rpc_handle_t dds_Ntf_AD_APACustSlot_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_APAInteract_skeleton_Ntf_AD_APACustSlot";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_APAInteract_Ntf_desc, &dds_Ntf_AD_APACustSlot_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_AD_APACustSlot_event_handle);
				}
				void send(const AD_APACustSlotData &data) {
					carDrive_Basc_APAInteract_Ntf event_data;
					event_data.data._d = carDrive_Basc_APAInteract_Ntf_AD_APACustSlot_Hash;
					event_data.data._u.Basc_APAInteract_Ntf_AD_APACustSlot = data;
                    dds_write(dds_Ntf_AD_APACustSlot_event_handle.writer, &event_data);
				}
        };
        class Basc_APAInteract_Ntf_AD_APADynguidance{
            private:
                dds_rpc_handle_t dds_Ntf_AD_APADynguidance_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_APAInteract_skeleton_Ntf_AD_APADynguidance";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_APAInteract_Ntf_desc, &dds_Ntf_AD_APADynguidance_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_AD_APADynguidance_event_handle);
				}
				void send(const AD_APADynguidanceData &data) {
					carDrive_Basc_APAInteract_Ntf event_data;
					event_data.data._d = carDrive_Basc_APAInteract_Ntf_AD_APADynguidance_Hash;
					event_data.data._u.Basc_APAInteract_Ntf_AD_APADynguidance = data;
                    dds_write(dds_Ntf_AD_APADynguidance_event_handle.writer, &event_data);
				}
        };
        class Basc_APAInteract_Ntf_AD_APADynrecommd{
            private:
                dds_rpc_handle_t dds_Ntf_AD_APADynrecommd_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_APAInteract_skeleton_Ntf_AD_APADynrecommd";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_APAInteract_Ntf_desc, &dds_Ntf_AD_APADynrecommd_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_AD_APADynrecommd_event_handle);
				}
				void send(const AD_APADynrecommdData &data) {
					carDrive_Basc_APAInteract_Ntf event_data;
					event_data.data._d = carDrive_Basc_APAInteract_Ntf_AD_APADynrecommd_Hash;
					event_data.data._u.Basc_APAInteract_Ntf_AD_APADynrecommd = data;
                    dds_write(dds_Ntf_AD_APADynrecommd_event_handle.writer, &event_data);
				}
        };
        class Basc_APAInteract_Ntf_AD_APAFctnIndnMsg{
            private:
                dds_rpc_handle_t dds_Ntf_AD_APAFctnIndnMsg_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_APAInteract_skeleton_Ntf_AD_APAFctnIndnMsg";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_APAInteract_Ntf_desc, &dds_Ntf_AD_APAFctnIndnMsg_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_AD_APAFctnIndnMsg_event_handle);
				}
				void send(const AD_APAFctnIndnMsgData &data) {
					carDrive_Basc_APAInteract_Ntf event_data;
					event_data.data._d = carDrive_Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_Hash;
					event_data.data._u.Basc_APAInteract_Ntf_AD_APAFctnIndnMsg = data;
                    dds_write(dds_Ntf_AD_APAFctnIndnMsg_event_handle.writer, &event_data);
				}
        };
	}
	extern void on_carDrive_Basc_APAInteract_request_data_available(int32_t reader, void* arg);

	class Basc_APAInteract_service_interface {
	public:
	    virtual ~Basc_APAInteract_service_interface() = default;

		virtual AD_APACustSlotData Get_AD_APACustSlot() = 0;
		virtual AD_APADynguidanceData Get_AD_APADynguidance() = 0;
		virtual AD_APADynrecommdData Get_AD_APADynrecommd() = 0;
		virtual AD_APAFctnIndnMsgData Get_AD_APAFctnIndnMsg() = 0;
		virtual uint8_t RR_EDC_APADrvrReqOnOff(const EDC_APADrvrReqOnOffData &EDC_APADrvrReqOnOffData,const RequestInfo &RequestInfo) = 0;
		virtual uint8_t RR_EDC_APADrvrReqSlotID(const EDC_APADrvrReqSlotIDData &EDC_APADrvrReqSlotIDData,const RequestInfo &RequestInfo) = 0;
		virtual uint8_t RR_EDC_APAParkInSelect(const EDC_APAParkInSelectData &EDC_APAParkInSelectData,const RequestInfo &RequestInfo) = 0;
		virtual uint8_t RR_EDC_APADynamicOperate(const EDC_APADynamicOperateData &EDC_APADynamicOperateData,const RequestInfo &RequestInfo) = 0;
		virtual uint8_t RR_EDC_APAParkOutSelect(const EDC_APAParkOutSelectData &EDC_APAParkOutSelectData,const RequestInfo &RequestInfo) = 0;
		virtual uint8_t RR_EDC_APACustSlot(const EDC_APACustSlotData &EDC_APACustSlotData,const RequestInfo &RequestInfo) = 0;
		virtual uint8_t RR_EDC_RADSDrvrReq(const EDC_RADSDrvrReqData &EDC_RADSDrvrReqData,const RequestInfo &RequestInfo) = 0;
	};
    class Basc_APAInteract_Skeleton :public Basc_APAInteract_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_APAInteract_Skeleton(Basc_APAInteract_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			AD_APACustSlotData Get_AD_APACustSlot() {
				return this->_service->Get_AD_APACustSlot();
			}
			AD_APADynguidanceData Get_AD_APADynguidance() {
				return this->_service->Get_AD_APADynguidance();
			}
			AD_APADynrecommdData Get_AD_APADynrecommd() {
				return this->_service->Get_AD_APADynrecommd();
			}
			AD_APAFctnIndnMsgData Get_AD_APAFctnIndnMsg() {
				return this->_service->Get_AD_APAFctnIndnMsg();
			}
			uint8_t RR_EDC_APADrvrReqOnOff(const EDC_APADrvrReqOnOffData &EDC_APADrvrReqOnOffData,const RequestInfo &RequestInfo) {
				return this->_service->RR_EDC_APADrvrReqOnOff(EDC_APADrvrReqOnOffData,RequestInfo);
			}
			uint8_t RR_EDC_APADrvrReqSlotID(const EDC_APADrvrReqSlotIDData &EDC_APADrvrReqSlotIDData,const RequestInfo &RequestInfo) {
				return this->_service->RR_EDC_APADrvrReqSlotID(EDC_APADrvrReqSlotIDData,RequestInfo);
			}
			uint8_t RR_EDC_APAParkInSelect(const EDC_APAParkInSelectData &EDC_APAParkInSelectData,const RequestInfo &RequestInfo) {
				return this->_service->RR_EDC_APAParkInSelect(EDC_APAParkInSelectData,RequestInfo);
			}
			uint8_t RR_EDC_APADynamicOperate(const EDC_APADynamicOperateData &EDC_APADynamicOperateData,const RequestInfo &RequestInfo) {
				return this->_service->RR_EDC_APADynamicOperate(EDC_APADynamicOperateData,RequestInfo);
			}
			uint8_t RR_EDC_APAParkOutSelect(const EDC_APAParkOutSelectData &EDC_APAParkOutSelectData,const RequestInfo &RequestInfo) {
				return this->_service->RR_EDC_APAParkOutSelect(EDC_APAParkOutSelectData,RequestInfo);
			}
			uint8_t RR_EDC_APACustSlot(const EDC_APACustSlotData &EDC_APACustSlotData,const RequestInfo &RequestInfo) {
				return this->_service->RR_EDC_APACustSlot(EDC_APACustSlotData,RequestInfo);
			}
			uint8_t RR_EDC_RADSDrvrReq(const EDC_RADSDrvrReqData &EDC_RADSDrvrReqData,const RequestInfo &RequestInfo) {
				return this->_service->RR_EDC_RADSDrvrReq(EDC_RADSDrvrReqData,RequestInfo);
			}
            dds_return_t send_reply(carDrive_Basc_APAInteract_Reply* reply);
            events::Basc_APAInteract_Ntf_AD_APACustSlot Ntf_AD_APACustSlot;
            events::Basc_APAInteract_Ntf_AD_APADynguidance Ntf_AD_APADynguidance;
            events::Basc_APAInteract_Ntf_AD_APADynrecommd Ntf_AD_APADynrecommd;
            events::Basc_APAInteract_Ntf_AD_APAFctnIndnMsg Ntf_AD_APAFctnIndnMsg;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_APAInteract_skeleton";
			Basc_APAInteract_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

