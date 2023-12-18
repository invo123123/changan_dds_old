/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V2.1
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-30T17:34:20
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_PhysicsStDoor_Proxy_HPP
#define Basc_PhysicsStDoor_Proxy_HPP
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
namespace Door {
namespace proxy {
	namespace events {
        class Basc_PhysicsStDoor_Ntf_PhyStAll{
			public:
			    void set_receive_handler(const EventReceiveHandler<const ObjStTypeDoorAll_Struct&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const ObjStTypeDoorAll_Struct &data){
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
				std::list<EventReceiveHandler<const ObjStTypeDoorAll_Struct&>> handler_list;
			    std::string event_name="Ntf_PhyStAll";
        };
        class Basc_PhysicsStDoor_Ntf_PosAll{
			public:
			    void set_receive_handler(const EventReceiveHandler<const ObjStTypeCurPosVITAll_Struct&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const ObjStTypeCurPosVITAll_Struct &data){
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
				std::list<EventReceiveHandler<const ObjStTypeCurPosVITAll_Struct&>> handler_list;
			    std::string event_name="Ntf_PosAll";
        };
        class Basc_PhysicsStDoor_Ntf_DoorStALL{
			public:
			    void set_receive_handler(const EventReceiveHandler<const DoorDrvStAll_Struct&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const DoorDrvStAll_Struct &data){
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
				std::list<EventReceiveHandler<const DoorDrvStAll_Struct&>> handler_list;
			    std::string event_name="Ntf_DoorStALL";
        };
	}
	extern void on_carControl_Basc_PhysicsStDoor_reply_data_available(int32_t reader, void* arg);
	class Basc_PhysicsStDoor_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static Basc_PhysicsStDoor_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool uninit();
			bool is_init();
            events::Basc_PhysicsStDoor_Ntf_PhyStAll Ntf_PhyStAll;
            events::Basc_PhysicsStDoor_Ntf_PosAll Ntf_PosAll;
            events::Basc_PhysicsStDoor_Ntf_DoorStALL Ntf_DoorStALL;
			DDS_GuidPrefix_t guid;
			Msg<ObjStTypeDoorAll_Struct> Get_PhyStAll() {
				return this->Get_PhyStAll<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<ObjStTypeDoorAll_Struct> Get_PhyStAll() {
				return this->Get_PhyStAll( TIMEOUT);
			}
			Msg<ObjStTypeCurPosVITAll_Struct> Get_PosAll() {
				return this->Get_PosAll<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<ObjStTypeCurPosVITAll_Struct> Get_PosAll() {
				return this->Get_PosAll( TIMEOUT);
			}
			Msg<DoorDrvStAll_Struct> Get_DoorStAll() {
				return this->Get_DoorStAll<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<DoorDrvStAll_Struct> Get_DoorStAll() {
				return this->Get_DoorStAll( TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			};
			uint16_t get_service_id(){
				return this->service_id;
			}

		private:
		    const std::string service_name = "Basc_PhysicsStDoor_skeleton";
			Msg<ObjStTypeDoorAll_Struct> Get_PhyStAll( size_t dds_rpc_time_out);
			Msg<ObjStTypeCurPosVITAll_Struct> Get_PosAll( size_t dds_rpc_time_out);
			Msg<DoorDrvStAll_Struct> Get_DoorStAll( size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_PhyStAll_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_PosAll_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_DoorStALL_handle = { -1,-1,-1 };
            bool init_flag = false;
            std::mutex init_mutex;
			const uint16_t service_id = 1373;

			Basc_PhysicsStDoor_Proxy();
			~Basc_PhysicsStDoor_Proxy();

			Basc_PhysicsStDoor_Proxy(const Basc_PhysicsStDoor_Proxy& signal);

			const Basc_PhysicsStDoor_Proxy& operator=(const Basc_PhysicsStDoor_Proxy& signal);
	};
}
}
}
}
}
#endif

