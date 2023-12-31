/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V1.3
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-07-25T12:58:51
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_MFSSwtInfo_Proxy_HPP
#define Basc_MFSSwtInfo_Proxy_HPP
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
namespace SteerWheel {
namespace proxy {
	namespace events {
        class Basc_MFSSwtInfo_Ntf_SwtInfo{
			public:
			    void set_receive_handler(const EventReceiveHandler<const MFSSwtInfo&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const MFSSwtInfo &data){
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
				std::list<EventReceiveHandler<const MFSSwtInfo&>> handler_list;
			    std::string event_name="Ntf_SwtInfo";
        };
        class Basc_MFSSwtInfo_Ntf_FltSt{
			public:
				void set_receive_handler(const EventReceiveHandler<const carControl_Secure_Car_Control_Basc_MFSSwtInfo_Ntf_FltSt_MFSFltStInfo&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const carControl_Secure_Car_Control_Basc_MFSSwtInfo_Ntf_FltSt_MFSFltStInfo &data){
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
				std::list<EventReceiveHandler<const carControl_Secure_Car_Control_Basc_MFSSwtInfo_Ntf_FltSt_MFSFltStInfo&>> handler_list;
			    std::string event_name="Ntf_FltSt";
        };
	}
	extern void on_carControl_Basc_MFSSwtInfo_reply_data_available(int32_t reader, void* arg);
	class Basc_MFSSwtInfo_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static Basc_MFSSwtInfo_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool uninit();
			bool is_init();
            events::Basc_MFSSwtInfo_Ntf_SwtInfo Ntf_SwtInfo;
            events::Basc_MFSSwtInfo_Ntf_FltSt Ntf_FltSt;
			DDS_GuidPrefix_t guid;
			Msg<MFSSwtInfo> Get_SwtInfo() {
				return this->Get_SwtInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<MFSSwtInfo> Get_SwtInfo() {
				return this->Get_SwtInfo( TIMEOUT);
			}
			Msg<MFSFltStInfo> Get_FltSt() {
				return this->Get_FltSt<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<MFSFltStInfo> Get_FltSt() {
				return this->Get_FltSt( TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			};
			uint16_t get_service_id(){
				return this->service_id;
			}

		private:
		    const std::string service_name = "Basc_MFSSwtInfo_skeleton";
			Msg<MFSSwtInfo> Get_SwtInfo( size_t dds_rpc_time_out);
			Msg<MFSFltStInfo> Get_FltSt( size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_SwtInfo_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_FltSt_handle = { -1,-1,-1 };
            bool init_flag = false;
            std::mutex init_mutex;
			const uint16_t service_id = 3325;

			Basc_MFSSwtInfo_Proxy();
			~Basc_MFSSwtInfo_Proxy();

			Basc_MFSSwtInfo_Proxy(const Basc_MFSSwtInfo_Proxy& signal);

			const Basc_MFSSwtInfo_Proxy& operator=(const Basc_MFSSwtInfo_Proxy& signal);
	};
}
}
}
}
}
#endif

