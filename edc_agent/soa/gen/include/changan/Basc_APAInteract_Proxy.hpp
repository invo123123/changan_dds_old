/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.0.5
  ServiceLatestModifyTime: 2023-11-21T15:20:28
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_APAInteract_Proxy_HPP
#define Basc_APAInteract_Proxy_HPP
#include <string.h>
#include <future>
#include <chrono>
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "dds/ddsrt/sync.h"
#include "changan/Basc_APAInteract.h"
#include "changan/base_proxy.hpp"
#include "changan/base_wait.hpp"
#include "changan/dds_client.hpp"
#include <mutex>

namespace com {
namespace changan {
namespace carDrive {
namespace C2Controller {
namespace proxy {
	namespace events {
        class Basc_APAInteract_Ntf_AD_APACustSlot{
			public:
			    void set_receive_handler(const EventReceiveHandler<const AD_APACustSlotData&> &handler) {
					handler_list.push_back(handler);
				};
			    void clear_receive_handler()
			  	{
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			  	}
				void trigger(const AD_APACustSlotData &data){
				  if(!handler_list.empty())
				  {
					 for(auto it :handler_list)
					 {
						it(data);
					 }
				  }
				};
				std::string get_name() {
					return this->event_name;
				}
			private:
				std::list<EventReceiveHandler<const AD_APACustSlotData&>> handler_list;
			    std::string event_name="Ntf_AD_APACustSlot";
        };
        class Basc_APAInteract_Ntf_AD_APADynguidance{
			public:
			    void set_receive_handler(const EventReceiveHandler<const AD_APADynguidanceData&> &handler) {
					handler_list.push_back(handler);
				};
			    void clear_receive_handler()
			  	{
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			  	}
				void trigger(const AD_APADynguidanceData &data){
				  if(!handler_list.empty())
				  {
					 for(auto it :handler_list)
					 {
						it(data);
					 }
				  }
				};
				std::string get_name() {
					return this->event_name;
				}
			private:
				std::list<EventReceiveHandler<const AD_APADynguidanceData&>> handler_list;
			    std::string event_name="Ntf_AD_APADynguidance";
        };
        class Basc_APAInteract_Ntf_AD_APADynrecommd{
			public:
			    void set_receive_handler(const EventReceiveHandler<const AD_APADynrecommdData&> &handler) {
					handler_list.push_back(handler);
				};
			    void clear_receive_handler()
			  	{
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			  	}
				void trigger(const AD_APADynrecommdData &data){
				  if(!handler_list.empty())
				  {
					 for(auto it :handler_list)
					 {
						it(data);
					 }
				  }
				};
				std::string get_name() {
					return this->event_name;
				}
			private:
				std::list<EventReceiveHandler<const AD_APADynrecommdData&>> handler_list;
			    std::string event_name="Ntf_AD_APADynrecommd";
        };
        class Basc_APAInteract_Ntf_AD_APAFctnIndnMsg{
			public:
			    void set_receive_handler(const EventReceiveHandler<const AD_APAFctnIndnMsgData&> &handler) {
					handler_list.push_back(handler);
				};
			    void clear_receive_handler()
			  	{
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			  	}
				void trigger(const AD_APAFctnIndnMsgData &data){
				  if(!handler_list.empty())
				  {
					 for(auto it :handler_list)
					 {
						it(data);
					 }
				  }
				};
				std::string get_name() {
					return this->event_name;
				}
			private:
				std::list<EventReceiveHandler<const AD_APAFctnIndnMsgData&>> handler_list;
			    std::string event_name="Ntf_AD_APAFctnIndnMsg";
        };
	}
	extern void on_carDrive_Basc_APAInteract_reply_data_available(int32_t reader, void* arg);
	class Basc_APAInteract_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler, public dds_link_count{
		public:
		    static Basc_APAInteract_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool destroy();
            events::Basc_APAInteract_Ntf_AD_APACustSlot Ntf_AD_APACustSlot;
            events::Basc_APAInteract_Ntf_AD_APADynguidance Ntf_AD_APADynguidance;
            events::Basc_APAInteract_Ntf_AD_APADynrecommd Ntf_AD_APADynrecommd;
            events::Basc_APAInteract_Ntf_AD_APAFctnIndnMsg Ntf_AD_APAFctnIndnMsg;
			DDS_GuidPrefix_t guid;
			Msg<AD_APACustSlotData> Get_AD_APACustSlot() {
				return this->Get_AD_APACustSlot<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<AD_APACustSlotData> Get_AD_APACustSlot() {
				return this->Get_AD_APACustSlot( TIMEOUT);
			}
			Msg<AD_APADynguidanceData> Get_AD_APADynguidance() {
				return this->Get_AD_APADynguidance<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<AD_APADynguidanceData> Get_AD_APADynguidance() {
				return this->Get_AD_APADynguidance( TIMEOUT);
			}
			Msg<AD_APADynrecommdData> Get_AD_APADynrecommd() {
				return this->Get_AD_APADynrecommd<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<AD_APADynrecommdData> Get_AD_APADynrecommd() {
				return this->Get_AD_APADynrecommd( TIMEOUT);
			}
			Msg<AD_APAFctnIndnMsgData> Get_AD_APAFctnIndnMsg() {
				return this->Get_AD_APAFctnIndnMsg<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<AD_APAFctnIndnMsgData> Get_AD_APAFctnIndnMsg() {
				return this->Get_AD_APAFctnIndnMsg( TIMEOUT);
			}
			Msg<uint8_t> RR_EDC_APADrvrReqOnOff(const EDC_APADrvrReqOnOffData &EDC_APADrvrReqOnOffData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APADrvrReqOnOff<DEFAULT_TIMEOUT>(EDC_APADrvrReqOnOffData,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> RR_EDC_APADrvrReqOnOff(const EDC_APADrvrReqOnOffData &EDC_APADrvrReqOnOffData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APADrvrReqOnOff(EDC_APADrvrReqOnOffData,RequestInfo, TIMEOUT);
			}
			Msg<uint8_t> RR_EDC_APADrvrReqSlotID(const EDC_APADrvrReqSlotIDData &EDC_APADrvrReqSlotIDData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APADrvrReqSlotID<DEFAULT_TIMEOUT>(EDC_APADrvrReqSlotIDData,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> RR_EDC_APADrvrReqSlotID(const EDC_APADrvrReqSlotIDData &EDC_APADrvrReqSlotIDData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APADrvrReqSlotID(EDC_APADrvrReqSlotIDData,RequestInfo, TIMEOUT);
			}
			Msg<uint8_t> RR_EDC_APAParkInSelect(const EDC_APAParkInSelectData &EDC_APAParkInSelectData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APAParkInSelect<DEFAULT_TIMEOUT>(EDC_APAParkInSelectData,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> RR_EDC_APAParkInSelect(const EDC_APAParkInSelectData &EDC_APAParkInSelectData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APAParkInSelect(EDC_APAParkInSelectData,RequestInfo, TIMEOUT);
			}
			Msg<uint8_t> RR_EDC_APADynamicOperate(const EDC_APADynamicOperateData &EDC_APADynamicOperateData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APADynamicOperate<DEFAULT_TIMEOUT>(EDC_APADynamicOperateData,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> RR_EDC_APADynamicOperate(const EDC_APADynamicOperateData &EDC_APADynamicOperateData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APADynamicOperate(EDC_APADynamicOperateData,RequestInfo, TIMEOUT);
			}
			Msg<uint8_t> RR_EDC_APAParkOutSelect(const EDC_APAParkOutSelectData &EDC_APAParkOutSelectData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APAParkOutSelect<DEFAULT_TIMEOUT>(EDC_APAParkOutSelectData,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> RR_EDC_APAParkOutSelect(const EDC_APAParkOutSelectData &EDC_APAParkOutSelectData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APAParkOutSelect(EDC_APAParkOutSelectData,RequestInfo, TIMEOUT);
			}
			Msg<uint8_t> RR_EDC_APACustSlot(const EDC_APACustSlotData &EDC_APACustSlotData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APACustSlot<DEFAULT_TIMEOUT>(EDC_APACustSlotData,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> RR_EDC_APACustSlot(const EDC_APACustSlotData &EDC_APACustSlotData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_APACustSlot(EDC_APACustSlotData,RequestInfo, TIMEOUT);
			}
			Msg<uint8_t> RR_EDC_RADSDrvrReq(const EDC_RADSDrvrReqData &EDC_RADSDrvrReqData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_RADSDrvrReq<DEFAULT_TIMEOUT>(EDC_RADSDrvrReqData,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> RR_EDC_RADSDrvrReq(const EDC_RADSDrvrReqData &EDC_RADSDrvrReqData,const RequestInfo &RequestInfo) {
				return this->RR_EDC_RADSDrvrReq(EDC_RADSDrvrReqData,RequestInfo, TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			}

		private:
		    const std::string service_name = "Basc_APAInteract_skeleton";
			Msg<AD_APACustSlotData> Get_AD_APACustSlot( size_t dds_rpc_time_out);
			Msg<AD_APADynguidanceData> Get_AD_APADynguidance( size_t dds_rpc_time_out);
			Msg<AD_APADynrecommdData> Get_AD_APADynrecommd( size_t dds_rpc_time_out);
			Msg<AD_APAFctnIndnMsgData> Get_AD_APAFctnIndnMsg( size_t dds_rpc_time_out);
			Msg<uint8_t> RR_EDC_APADrvrReqOnOff(const EDC_APADrvrReqOnOffData &EDC_APADrvrReqOnOffData,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);
			Msg<uint8_t> RR_EDC_APADrvrReqSlotID(const EDC_APADrvrReqSlotIDData &EDC_APADrvrReqSlotIDData,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);
			Msg<uint8_t> RR_EDC_APAParkInSelect(const EDC_APAParkInSelectData &EDC_APAParkInSelectData,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);
			Msg<uint8_t> RR_EDC_APADynamicOperate(const EDC_APADynamicOperateData &EDC_APADynamicOperateData,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);
			Msg<uint8_t> RR_EDC_APAParkOutSelect(const EDC_APAParkOutSelectData &EDC_APAParkOutSelectData,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);
			Msg<uint8_t> RR_EDC_APACustSlot(const EDC_APACustSlotData &EDC_APACustSlotData,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);
			Msg<uint8_t> RR_EDC_RADSDrvrReq(const EDC_RADSDrvrReqData &EDC_RADSDrvrReqData,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_AD_APACustSlot_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_AD_APADynguidance_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_AD_APADynrecommd_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_AD_APAFctnIndnMsg_handle = { -1,-1,-1 };

            bool init_flag = false;
            std::mutex init_mutex;

			Basc_APAInteract_Proxy();
			~Basc_APAInteract_Proxy();

			Basc_APAInteract_Proxy(const Basc_APAInteract_Proxy& signal);

			const Basc_APAInteract_Proxy& operator=(const Basc_APAInteract_Proxy& signal);
	};
}
}
}
}
}
#endif

