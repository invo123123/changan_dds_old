/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: v1.0
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-07-17T13:54:31
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_BLEPhyKeySer_Proxy_HPP
#define Basc_BLEPhyKeySer_Proxy_HPP
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
        class Basc_BLEPhyKeySer_Ntf_BLEPhyKeyInfo{
			public:
			    void set_receive_handler(const EventReceiveHandler<const BLEPhyKeyBascInfo&> &handler) {
					handler_list.push_back(handler);
				};
				void clear_receive_handler()
			    {
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			    }
				void trigger(const BLEPhyKeyBascInfo &data){
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
				std::list<EventReceiveHandler<const BLEPhyKeyBascInfo&>> handler_list;
			    std::string event_name="Ntf_BLEPhyKeyInfo";
        };
	}
	extern void on_carControl_Basc_BLEPhyKeySer_reply_data_available(int32_t reader, void* arg);
	class Basc_BLEPhyKeySer_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static Basc_BLEPhyKeySer_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool uninit();
			bool is_init();
            events::Basc_BLEPhyKeySer_Ntf_BLEPhyKeyInfo Ntf_BLEPhyKeyInfo;
			DDS_GuidPrefix_t guid;
			Msg<BLEPhyKeyBascInfo> Get_BLEPhyKeyInfo() {
				return this->Get_BLEPhyKeyInfo<DEFAULT_TIMEOUT>();
			}
			template<size_t TIMEOUT>
			Msg<BLEPhyKeyBascInfo> Get_BLEPhyKeyInfo() {
				return this->Get_BLEPhyKeyInfo( TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			};
			uint16_t get_service_id(){
				return this->service_id;
			}

		private:
		    const std::string service_name = "Basc_BLEPhyKeySer_skeleton";
			Msg<BLEPhyKeyBascInfo> Get_BLEPhyKeyInfo( size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_BLEPhyKeyInfo_handle = { -1,-1,-1 };
            bool init_flag = false;
            std::mutex init_mutex;
			const uint16_t service_id = 3621;

			Basc_BLEPhyKeySer_Proxy();
			~Basc_BLEPhyKeySer_Proxy();

			Basc_BLEPhyKeySer_Proxy(const Basc_BLEPhyKeySer_Proxy& signal);

			const Basc_BLEPhyKeySer_Proxy& operator=(const Basc_BLEPhyKeySer_Proxy& signal);
	};
}
}
}
}
}
#endif

