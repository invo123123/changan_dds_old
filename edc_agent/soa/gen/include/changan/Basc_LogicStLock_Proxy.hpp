/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V3.1
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-30T20:52:19
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_LogicStLock_Proxy_HPP
#define Basc_LogicStLock_Proxy_HPP
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
namespace DoorLock {
namespace proxy {
	namespace events {
        class Basc_LogicStLock_Ntf_LocStAll{
			public:
			    void set_receive_handler(const EventReceiveHandler<const LockStAll_Struct&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const LockStAll_Struct &data){
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
				std::list<EventReceiveHandler<const LockStAll_Struct&>> handler_list;
			    std::string event_name="Ntf_LocStAll";
        };
	}
	extern void on_carControl_Basc_LogicStLock_reply_data_available(int32_t reader, void* arg);
	class Basc_LogicStLock_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static Basc_LogicStLock_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool uninit();
			bool is_init();
            events::Basc_LogicStLock_Ntf_LocStAll Ntf_LocStAll;
			DDS_GuidPrefix_t guid;
			Msg<LockStAll_Struct> Get_LocStAll() {
				return this->Get_LocStAll<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<LockStAll_Struct> Get_LocStAll() {
				return this->Get_LocStAll( TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			};
			uint16_t get_service_id(){
				return this->service_id;
			}

		private:
		    const std::string service_name = "Basc_LogicStLock_skeleton";
			Msg<LockStAll_Struct> Get_LocStAll( size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_LocStAll_handle = { -1,-1,-1 };
            bool init_flag = false;
            std::mutex init_mutex;
			const uint16_t service_id = 1080;

			Basc_LogicStLock_Proxy();
			~Basc_LogicStLock_Proxy();

			Basc_LogicStLock_Proxy(const Basc_LogicStLock_Proxy& signal);

			const Basc_LogicStLock_Proxy& operator=(const Basc_LogicStLock_Proxy& signal);
	};
}
}
}
}
}
#endif

