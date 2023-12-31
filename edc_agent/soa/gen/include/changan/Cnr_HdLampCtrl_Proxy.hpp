/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V3.0
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-15T19:19:54
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Cnr_HdLampCtrl_Proxy_HPP
#define Cnr_HdLampCtrl_Proxy_HPP
#include <string.h>
#include <future>
#include <chrono>
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "dds/ddsrt/sync.h"
#include "changan/base_proxy.hpp"
#include "changan/base_wait.hpp"
#include "changan/dds_client.hpp"
#include <mutex>
#include "changan/Car_Control.h"
namespace com {
namespace changan {
namespace carControl {
namespace ExteriorLight {
namespace proxy {
	namespace events {
        class Cnr_HdLampCtrl_Ntf_SrvOperInfo{
			public:
			    void set_receive_handler(const EventReceiveHandler<const OperationInfo&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const OperationInfo &data){
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
				std::list<EventReceiveHandler<const OperationInfo&>> handler_list;
			    std::string event_name="Ntf_SrvOperInfo";
        };
        class Cnr_HdLampCtrl_Ntf_HdLampRunMod{
			public:
			    void set_receive_handler(const EventReceiveHandler<const uint8_t&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const uint8_t &data){
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
				std::list<EventReceiveHandler<const uint8_t&>> handler_list;
			    std::string event_name="Ntf_HdLampRunMod";
        };
        class Cnr_HdLampCtrl_Ntf_ClusterPosnLiSt{
			public:
			    void set_receive_handler(const EventReceiveHandler<const uint8_t&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const uint8_t &data){
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
				std::list<EventReceiveHandler<const uint8_t&>> handler_list;
			    std::string event_name="Ntf_ClusterPosnLiSt";
        };
        class Cnr_HdLampCtrl_Ntf_ClusterLoBeamSt{
			public:
			    void set_receive_handler(const EventReceiveHandler<const uint8_t&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const uint8_t &data){
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
				std::list<EventReceiveHandler<const uint8_t&>> handler_list;
			    std::string event_name="Ntf_ClusterLoBeamSt";
        };
        class Cnr_HdLampCtrl_Ntf_OperationCode{
			public:
			    void set_receive_handler(const EventReceiveHandler<const OperationCode&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const OperationCode &data){
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
				std::list<EventReceiveHandler<const OperationCode&>> handler_list;
			    std::string event_name="Ntf_OperationCode";
        };
	}
	extern void on_carControl_Cnr_HdLampCtrl_reply_data_available(int32_t reader, void* arg);
	class Cnr_HdLampCtrl_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static Cnr_HdLampCtrl_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool uninit();
			bool is_init();
            events::Cnr_HdLampCtrl_Ntf_SrvOperInfo Ntf_SrvOperInfo;
            events::Cnr_HdLampCtrl_Ntf_HdLampRunMod Ntf_HdLampRunMod;
            events::Cnr_HdLampCtrl_Ntf_ClusterPosnLiSt Ntf_ClusterPosnLiSt;
            events::Cnr_HdLampCtrl_Ntf_ClusterLoBeamSt Ntf_ClusterLoBeamSt;
            events::Cnr_HdLampCtrl_Ntf_OperationCode Ntf_OperationCode;
			DDS_GuidPrefix_t guid;
			Msg<ResponseInfo> RR_CombHdLampCtrl(const uint8_t &CombHdLampReq,const RequestInfo &RequestInfo) {
				return this->RR_CombHdLampCtrl<DEFAULT_TIMEOUT>(CombHdLampReq,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<ResponseInfo> RR_CombHdLampCtrl(const uint8_t &CombHdLampReq,const RequestInfo &RequestInfo) {
				return this->RR_CombHdLampCtrl(CombHdLampReq,RequestInfo, TIMEOUT);
			}
			Msg<OperationInfo> Get_SrvOperInfo() {
				return this->Get_SrvOperInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<OperationInfo> Get_SrvOperInfo() {
				return this->Get_SrvOperInfo( TIMEOUT);
			}
			Msg<uint8_t> Get_HdLampRunMod() {
				return this->Get_HdLampRunMod<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> Get_HdLampRunMod() {
				return this->Get_HdLampRunMod( TIMEOUT);
			}
			Msg<uint8_t> Get_ClusterPosnLiSt() {
				return this->Get_ClusterPosnLiSt<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> Get_ClusterPosnLiSt() {
				return this->Get_ClusterPosnLiSt( TIMEOUT);
			}
			Msg<uint8_t> Get_ClusterLoBeamSt() {
				return this->Get_ClusterLoBeamSt<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> Get_ClusterLoBeamSt() {
				return this->Get_ClusterLoBeamSt( TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			};
			uint16_t get_service_id(){
				return this->service_id;
			}

		private:
		    const std::string service_name = "Cnr_HdLampCtrl_skeleton";
			Msg<ResponseInfo> RR_CombHdLampCtrl(const uint8_t &CombHdLampReq,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);
			Msg<OperationInfo> Get_SrvOperInfo( size_t dds_rpc_time_out);
			Msg<uint8_t> Get_HdLampRunMod( size_t dds_rpc_time_out);
			Msg<uint8_t> Get_ClusterPosnLiSt( size_t dds_rpc_time_out);
			Msg<uint8_t> Get_ClusterLoBeamSt( size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_SrvOperInfo_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_HdLampRunMod_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_ClusterPosnLiSt_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_ClusterLoBeamSt_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_OperationCode_handle = { -1,-1,-1 };
            bool init_flag = false;
            std::mutex init_mutex;
			const uint16_t service_id = 1026;

			Cnr_HdLampCtrl_Proxy();
			~Cnr_HdLampCtrl_Proxy();

			Cnr_HdLampCtrl_Proxy(const Cnr_HdLampCtrl_Proxy& signal);

			const Cnr_HdLampCtrl_Proxy& operator=(const Cnr_HdLampCtrl_Proxy& signal);
	};
}
}
}
}
}
#endif

