/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.0.0
  ServiceLatestModifyTime: 2023-04-28T16:19:32
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_DMSTransferData_Proxy_HPP
#define Basc_DMSTransferData_Proxy_HPP
#include <string.h>
#include <future>
#include <chrono>
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "dds/ddsrt/sync.h"
#include "changan/Basc_DMSTransferData.h"
#include "changan/base_proxy.hpp"
#include "changan/base_wait.hpp"
#include "changan/dds_client.hpp"
#include <mutex>

namespace com {
namespace changan {
namespace carCabin {
namespace defaultService {
namespace proxy {
	namespace events {
        class Basc_DMSTransferData_Ntf_SendProtoData{
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
			    std::string event_name="Ntf_SendProtoData";
        };
	}
	class Basc_DMSTransferData_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler, public dds_link_count{
		public:
		    static Basc_DMSTransferData_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool destroy();
            events::Basc_DMSTransferData_Ntf_SendProtoData Ntf_SendProtoData;
			DDS_GuidPrefix_t guid;
			const std::string get_service_name() {
				return this->service_name;
			}

		private:
		    const std::string service_name = "Basc_DMSTransferData_skeleton";

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_SendProtoData_handle = { -1,-1,-1 };

            bool init_flag = false;
            std::mutex init_mutex;

			Basc_DMSTransferData_Proxy();
			~Basc_DMSTransferData_Proxy();

			Basc_DMSTransferData_Proxy(const Basc_DMSTransferData_Proxy& signal);

			const Basc_DMSTransferData_Proxy& operator=(const Basc_DMSTransferData_Proxy& signal);
	};
}
}
}
}
}
#endif

