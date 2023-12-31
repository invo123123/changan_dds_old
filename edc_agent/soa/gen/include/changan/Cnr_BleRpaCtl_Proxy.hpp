/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V1.2
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-07-17T13:54:30
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Cnr_BleRpaCtl_Proxy_HPP
#define Cnr_BleRpaCtl_Proxy_HPP
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
namespace Key {
namespace proxy {
	namespace events {
        class Cnr_BleRpaCtl_Ntf_SrvOperInfo{
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
        class Cnr_BleRpaCtl_Ntf_BleRpaCtl{
			public:
			    void set_receive_handler(const EventReceiveHandler<const BLERpaCmdReq&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const BLERpaCmdReq &data){
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
				std::list<EventReceiveHandler<const BLERpaCmdReq&>> handler_list;
			    std::string event_name="Ntf_BleRpaCtl";
        };
        class Cnr_BleRpaCtl_Ntf_OperationCode{
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
	extern void on_carControl_Cnr_BleRpaCtl_reply_data_available(int32_t reader, void* arg);
	class Cnr_BleRpaCtl_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static Cnr_BleRpaCtl_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool uninit();
			bool is_init();
            events::Cnr_BleRpaCtl_Ntf_SrvOperInfo Ntf_SrvOperInfo;
            events::Cnr_BleRpaCtl_Ntf_BleRpaCtl Ntf_BleRpaCtl;
            events::Cnr_BleRpaCtl_Ntf_OperationCode Ntf_OperationCode;
			DDS_GuidPrefix_t guid;
			Msg<OperationInfo> Get_SrvOperInfo() {
				return this->Get_SrvOperInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<OperationInfo> Get_SrvOperInfo() {
				return this->Get_SrvOperInfo( TIMEOUT);
			}
			Msg<ResponseInfo> RR_BleRpaCtl(const BLERpaCmdRsp &BLERpaCmdRsp,const RequestInfo &RequestInfo) {
				return this->RR_BleRpaCtl<DEFAULT_TIMEOUT>(BLERpaCmdRsp,RequestInfo);
			}
			template<size_t TIMEOUT>
			Msg<ResponseInfo> RR_BleRpaCtl(const BLERpaCmdRsp &BLERpaCmdRsp,const RequestInfo &RequestInfo) {
				return this->RR_BleRpaCtl(BLERpaCmdRsp,RequestInfo, TIMEOUT);
			}
			Msg<BLERpaCmdReq> Get_BleRpaCtl() {
				return this->Get_BleRpaCtl<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<BLERpaCmdReq> Get_BleRpaCtl() {
				return this->Get_BleRpaCtl( TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			};
			uint16_t get_service_id(){
				return this->service_id;
			}

		private:
		    const std::string service_name = "Cnr_BleRpaCtl_skeleton";
			Msg<OperationInfo> Get_SrvOperInfo( size_t dds_rpc_time_out);
			Msg<ResponseInfo> RR_BleRpaCtl(const BLERpaCmdRsp &BLERpaCmdRsp,const RequestInfo &RequestInfo, size_t dds_rpc_time_out);
			Msg<BLERpaCmdReq> Get_BleRpaCtl( size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_SrvOperInfo_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_BleRpaCtl_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_OperationCode_handle = { -1,-1,-1 };
            bool init_flag = false;
            std::mutex init_mutex;
			const uint16_t service_id = 2831;

			Cnr_BleRpaCtl_Proxy();
			~Cnr_BleRpaCtl_Proxy();

			Cnr_BleRpaCtl_Proxy(const Cnr_BleRpaCtl_Proxy& signal);

			const Cnr_BleRpaCtl_Proxy& operator=(const Cnr_BleRpaCtl_Proxy& signal);
	};
}
}
}
}
}
#endif

