/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V2.3
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-11-06T17:24:34
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_ExtrLiSwtReqInfo_Proxy_HPP
#define Basc_ExtrLiSwtReqInfo_Proxy_HPP
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
        class Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo{
			public:
				void set_receive_handler(const EventReceiveHandler<const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo_uint8&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo_uint8 &data){
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
				std::list<EventReceiveHandler<const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo_uint8&>> handler_list;
			    std::string event_name="Ntf_HdLampSwtReqInfo";
        };
        class Basc_ExtrLiSwtReqInfo_Ntf_TurnLiSwtReqInfo{
			public:
				void set_receive_handler(const EventReceiveHandler<const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_TurnLiSwtReqInfo_TurnLiKeySwtSt&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_TurnLiSwtReqInfo_TurnLiKeySwtSt &data){
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
				std::list<EventReceiveHandler<const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_TurnLiSwtReqInfo_TurnLiKeySwtSt&>> handler_list;
			    std::string event_name="Ntf_TurnLiSwtReqInfo";
        };
        class Basc_ExtrLiSwtReqInfo_Ntf_HzrdSwtReqInfo{
			public:
				void set_receive_handler(const EventReceiveHandler<const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HzrdSwtReqInfo_HzrdKeySwtSt&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HzrdSwtReqInfo_HzrdKeySwtSt &data){
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
				std::list<EventReceiveHandler<const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HzrdSwtReqInfo_HzrdKeySwtSt&>> handler_list;
			    std::string event_name="Ntf_HzrdSwtReqInfo";
        };
        class Basc_ExtrLiSwtReqInfo_Ntf_HiBeamSwtReqInfo{
			public:
				void set_receive_handler(const EventReceiveHandler<const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HiBeamSwtReqInfo_uint8&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HiBeamSwtReqInfo_uint8 &data){
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
				std::list<EventReceiveHandler<const carControl_Secure_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HiBeamSwtReqInfo_uint8&>> handler_list;
			    std::string event_name="Ntf_HiBeamSwtReqInfo";
        };
        class Basc_ExtrLiSwtReqInfo_Ntf_OvertakeSwtReqInfo{
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
			    std::string event_name="Ntf_OvertakeSwtReqInfo";
        };
	}
	extern void on_carControl_Basc_ExtrLiSwtReqInfo_reply_data_available(int32_t reader, void* arg);
	class Basc_ExtrLiSwtReqInfo_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static Basc_ExtrLiSwtReqInfo_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool uninit();
			bool is_init();
            events::Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo Ntf_HdLampSwtReqInfo;
            events::Basc_ExtrLiSwtReqInfo_Ntf_TurnLiSwtReqInfo Ntf_TurnLiSwtReqInfo;
            events::Basc_ExtrLiSwtReqInfo_Ntf_HzrdSwtReqInfo Ntf_HzrdSwtReqInfo;
            events::Basc_ExtrLiSwtReqInfo_Ntf_HiBeamSwtReqInfo Ntf_HiBeamSwtReqInfo;
            events::Basc_ExtrLiSwtReqInfo_Ntf_OvertakeSwtReqInfo Ntf_OvertakeSwtReqInfo;
			DDS_GuidPrefix_t guid;
			Msg<uint8_t> Get_HdLampSwtReqInfo() {
				return this->Get_HdLampSwtReqInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> Get_HdLampSwtReqInfo() {
				return this->Get_HdLampSwtReqInfo( TIMEOUT);
			}
			Msg<TurnLiKeySwtSt> Get_TurnLiSwtReqInfo() {
				return this->Get_TurnLiSwtReqInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<TurnLiKeySwtSt> Get_TurnLiSwtReqInfo() {
				return this->Get_TurnLiSwtReqInfo( TIMEOUT);
			}
			Msg<HzrdKeySwtSt> Get_HzrdSwtReqInfo() {
				return this->Get_HzrdSwtReqInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<HzrdKeySwtSt> Get_HzrdSwtReqInfo() {
				return this->Get_HzrdSwtReqInfo( TIMEOUT);
			}
			Msg<uint8_t> Get_HiBeamSwtReqInfo() {
				return this->Get_HiBeamSwtReqInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> Get_HiBeamSwtReqInfo() {
				return this->Get_HiBeamSwtReqInfo( TIMEOUT);
			}
			Msg<uint8_t> Get_OvertakeSwtReqInfo() {
				return this->Get_OvertakeSwtReqInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> Get_OvertakeSwtReqInfo() {
				return this->Get_OvertakeSwtReqInfo( TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			};
			uint16_t get_service_id(){
				return this->service_id;
			}

		private:
		    const std::string service_name = "Basc_ExtrLiSwtReqInfo_skeleton";
			Msg<uint8_t> Get_HdLampSwtReqInfo( size_t dds_rpc_time_out);
			Msg<TurnLiKeySwtSt> Get_TurnLiSwtReqInfo( size_t dds_rpc_time_out);
			Msg<HzrdKeySwtSt> Get_HzrdSwtReqInfo( size_t dds_rpc_time_out);
			Msg<uint8_t> Get_HiBeamSwtReqInfo( size_t dds_rpc_time_out);
			Msg<uint8_t> Get_OvertakeSwtReqInfo( size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_HdLampSwtReqInfo_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_TurnLiSwtReqInfo_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_HzrdSwtReqInfo_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_HiBeamSwtReqInfo_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_OvertakeSwtReqInfo_handle = { -1,-1,-1 };
            bool init_flag = false;
            std::mutex init_mutex;
			const uint16_t service_id = 2706;

			Basc_ExtrLiSwtReqInfo_Proxy();
			~Basc_ExtrLiSwtReqInfo_Proxy();

			Basc_ExtrLiSwtReqInfo_Proxy(const Basc_ExtrLiSwtReqInfo_Proxy& signal);

			const Basc_ExtrLiSwtReqInfo_Proxy& operator=(const Basc_ExtrLiSwtReqInfo_Proxy& signal);
	};
}
}
}
}
}
#endif

