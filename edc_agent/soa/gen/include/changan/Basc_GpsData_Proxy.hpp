/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.1.0
  ServiceLatestModifyTime: 2023-05-29T15:21:40
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_GpsData_Proxy_HPP
#define Basc_GpsData_Proxy_HPP
#include <string.h>
#include <future>
#include <chrono>
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "dds/ddsrt/sync.h"
#include "changan/Basc_GpsData.h"
#include "changan/base_proxy.hpp"
#include "changan/base_wait.hpp"
#include "changan/dds_client.hpp"
#include <mutex>

namespace com {
namespace changan {
namespace carCabin {
namespace testClass {
namespace proxy {
	namespace events {
        class Basc_GpsData_Evt_GpsData{
			public:
			    void set_receive_handler(const EventReceiveHandler<const GpsDatas&> &handler) {
					handler_list.push_back(handler);
				};
			    void clear_receive_handler()
			  	{
				  if(!handler_list.empty())
				  {
				  	handler_list.clear();
				  }
			  	}
				void trigger(const GpsDatas &data){
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
				std::list<EventReceiveHandler<const GpsDatas&>> handler_list;
			    std::string event_name="Evt_GpsData";
        };
	}
	class Basc_GpsData_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler, public dds_link_count{
		public:
		    static Basc_GpsData_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool destroy();
            events::Basc_GpsData_Evt_GpsData Evt_GpsData;
			DDS_GuidPrefix_t guid;
			const std::string get_service_name() {
				return this->service_name;
			}

		private:
		    const std::string service_name = "Basc_GpsData_skeleton";

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Evt_GpsData_handle = { -1,-1,-1 };

            bool init_flag = false;
            std::mutex init_mutex;

			Basc_GpsData_Proxy();
			~Basc_GpsData_Proxy();

			Basc_GpsData_Proxy(const Basc_GpsData_Proxy& signal);

			const Basc_GpsData_Proxy& operator=(const Basc_GpsData_Proxy& signal);
	};
}
}
}
}
}
#endif

