/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.2
  ServiceLatestModifyTime: 2023-08-31T15:35:24
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_UssObstDistance_Proxy_HPP
#define Basc_UssObstDistance_Proxy_HPP
#include <string.h>
#include <future>
#include <chrono>
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "dds/ddsrt/sync.h"
#include "changan/Basc_UssObstDistance.h"
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
        class Basc_UssObstDistance_Ntf_UssObstDistance{
			public:
			    void set_receive_handler(const EventReceiveHandler<const DDSData_Msg&> &handler) {
					handler_list.push_back(handler);
				};
			    void clear_receive_handler()
			  	{
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			  	}
				void trigger(const DDSData_Msg &data){
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
				std::list<EventReceiveHandler<const DDSData_Msg&>> handler_list;
			    std::string event_name="Ntf_UssObstDistance";
        };
	}
	class Basc_UssObstDistance_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler, public dds_link_count{
		public:
		    static Basc_UssObstDistance_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool destroy();
            events::Basc_UssObstDistance_Ntf_UssObstDistance Ntf_UssObstDistance;
			DDS_GuidPrefix_t guid;
			const std::string get_service_name() {
				return this->service_name;
			}

		private:
		    const std::string service_name = "Basc_UssObstDistance_skeleton";

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_UssObstDistance_handle = { -1,-1,-1 };

            bool init_flag = false;
            std::mutex init_mutex;

			Basc_UssObstDistance_Proxy();
			~Basc_UssObstDistance_Proxy();

			Basc_UssObstDistance_Proxy(const Basc_UssObstDistance_Proxy& signal);

			const Basc_UssObstDistance_Proxy& operator=(const Basc_UssObstDistance_Proxy& signal);
	};
}
}
}
}
}
#endif

