/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.3
  ServiceLatestModifyTime: 2023-08-22T19:12:49
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_FileTransmitServer_Proxy_HPP
#define Basc_FileTransmitServer_Proxy_HPP
#include <string.h>
#include <future>
#include <chrono>
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "dds/ddsrt/sync.h"
#include "changan/Basc_FileTransmitServer.h"
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
        class Basc_FileTransmitServer_Ntf_FileTransmit{
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
			    std::string event_name="Ntf_FileTransmit";
        };
	}
	extern void on_carDrive_Basc_FileTransmitServer_reply_data_available(int32_t reader, void* arg);
	class Basc_FileTransmitServer_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler, public dds_link_count{
		public:
		    static Basc_FileTransmitServer_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool destroy();
            events::Basc_FileTransmitServer_Ntf_FileTransmit Ntf_FileTransmit;
			DDS_GuidPrefix_t guid;
			Msg<FileEntity> RR_FileReq(const uint32_t &fileType) {
				return this->RR_FileReq<DEFAULT_TIMEOUT>(fileType);
			}
			template<size_t TIMEOUT>
			Msg<FileEntity> RR_FileReq(const uint32_t &fileType) {
				return this->RR_FileReq(fileType, TIMEOUT);
			}
			Msg<uint8_t> RR_ReceivedFile(const uint32_t &fileId,const uint8_t &received) {
				return this->RR_ReceivedFile<DEFAULT_TIMEOUT>(fileId,received);
			}
			template<size_t TIMEOUT>
			Msg<uint8_t> RR_ReceivedFile(const uint32_t &fileId,const uint8_t &received) {
				return this->RR_ReceivedFile(fileId,received, TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			}

		private:
		    const std::string service_name = "Basc_FileTransmitServer_skeleton";
			Msg<FileEntity> RR_FileReq(const uint32_t &fileType, size_t dds_rpc_time_out);
			Msg<uint8_t> RR_ReceivedFile(const uint32_t &fileId,const uint8_t &received, size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };
            dds_rpc_handle_t dds_Ntf_FileTransmit_handle = { -1,-1,-1 };

            bool init_flag = false;
            std::mutex init_mutex;

			Basc_FileTransmitServer_Proxy();
			~Basc_FileTransmitServer_Proxy();

			Basc_FileTransmitServer_Proxy(const Basc_FileTransmitServer_Proxy& signal);

			const Basc_FileTransmitServer_Proxy& operator=(const Basc_FileTransmitServer_Proxy& signal);
	};
}
}
}
}
}
#endif

