/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V1.2
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-11-09T12:36:49
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Sys_TotalMilg_Proxy_HPP
#define Sys_TotalMilg_Proxy_HPP
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
namespace BasicService {
namespace proxy {
	namespace events {
        class Sys_TotalMilg_Ntf_TotalMilg{
			public:
			    void set_receive_handler(const EventReceiveHandler<const uint32_t&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const uint32_t &data){
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
				std::list<EventReceiveHandler<const uint32_t&>> handler_list;
			    std::string event_name="Ntf_TotalMilg";
        };
        class Sys_TotalMilg_Ntf_ReevTotalMilg{
			public:
			    void set_receive_handler(const EventReceiveHandler<const ReevTotalMilg&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const ReevTotalMilg &data){
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
				std::list<EventReceiveHandler<const ReevTotalMilg&>> handler_list;
			    std::string event_name="Ntf_ReevTotalMilg";
        };
        class Sys_TotalMilg_Ntf_TotalMilgM{
			public:
			    void set_receive_handler(const EventReceiveHandler<const uint32_t&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const uint32_t &data){
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
				std::list<EventReceiveHandler<const uint32_t&>> handler_list;
			    std::string event_name="Ntf_TotalMilgM";
        };
	}
	extern void on_carControl_Sys_TotalMilg_reply_data_available(int32_t reader, void* arg);
	class Sys_TotalMilg_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static Sys_TotalMilg_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool uninit();
			bool is_init();
            events::Sys_TotalMilg_Ntf_TotalMilg Ntf_TotalMilg;
            events::Sys_TotalMilg_Ntf_ReevTotalMilg Ntf_ReevTotalMilg;
            events::Sys_TotalMilg_Ntf_TotalMilgM Ntf_TotalMilgM;
			DDS_GuidPrefix_t guid;
			Msg<uint32_t> Get_TotalMilg() {
				return this->Get_TotalMilg<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<uint32_t> Get_TotalMilg() {
				return this->Get_TotalMilg( TIMEOUT);
			}
			Msg<ReevTotalMilg> Get_ReevTotalMilg() {
				return this->Get_ReevTotalMilg<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<ReevTotalMilg> Get_ReevTotalMilg() {
				return this->Get_ReevTotalMilg( TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			};
			uint16_t get_service_id(){
				return this->service_id;
			}

		private:
		    const std::string service_name = "Sys_TotalMilg_skeleton";
			Msg<uint32_t> Get_TotalMilg( size_t dds_rpc_time_out);
			Msg<ReevTotalMilg> Get_ReevTotalMilg( size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_TotalMilg_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_ReevTotalMilg_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_TotalMilgM_handle = { -1,-1,-1 };
            bool init_flag = false;
            std::mutex init_mutex;
			const uint16_t service_id = 2849;

			Sys_TotalMilg_Proxy();
			~Sys_TotalMilg_Proxy();

			Sys_TotalMilg_Proxy(const Sys_TotalMilg_Proxy& signal);

			const Sys_TotalMilg_Proxy& operator=(const Sys_TotalMilg_Proxy& signal);
	};
}
}
}
}
}
#endif

