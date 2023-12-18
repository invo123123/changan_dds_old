/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.3
  ServiceLatestModifyTime: 2023-08-22T19:12:49
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_FileTransmitServer_SKELETON_HPP
#define Basc_FileTransmitServer_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_FileTransmitServer.h"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include <mutex>
namespace com {
namespace changan {
namespace carDrive {
namespace C2Controller {
namespace skeleton {
	namespace events {
        class Basc_FileTransmitServer_Ntf_FileTransmit{
            private:
                dds_rpc_handle_t dds_Ntf_FileTransmit_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_FileTransmitServer_skeleton_Ntf_FileTransmit";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_FileTransmitServer_Ntf_desc, &dds_Ntf_FileTransmit_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_FileTransmit_event_handle);
				}
				void send(const DDSData_Msg &data) {
					carDrive_Basc_FileTransmitServer_Ntf event_data;
					event_data.data._d = carDrive_Basc_FileTransmitServer_Ntf_FileTransmit_Hash;
					event_data.data._u.Basc_FileTransmitServer_Ntf_FileTransmit = data;
                    dds_write(dds_Ntf_FileTransmit_event_handle.writer, &event_data);
				}
        };
	}
	extern void on_carDrive_Basc_FileTransmitServer_request_data_available(int32_t reader, void* arg);

	class Basc_FileTransmitServer_service_interface {
	public:
	    virtual ~Basc_FileTransmitServer_service_interface() = default;

		virtual FileEntity RR_FileReq(const uint32_t &fileType) = 0;
		virtual uint8_t RR_ReceivedFile(const uint32_t &fileId,const uint8_t &received) = 0;
	};
    class Basc_FileTransmitServer_Skeleton :public Basc_FileTransmitServer_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_FileTransmitServer_Skeleton(Basc_FileTransmitServer_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			FileEntity RR_FileReq(const uint32_t &fileType) {
				return this->_service->RR_FileReq(fileType);
			}
			uint8_t RR_ReceivedFile(const uint32_t &fileId,const uint8_t &received) {
				return this->_service->RR_ReceivedFile(fileId,received);
			}
            dds_return_t send_reply(carDrive_Basc_FileTransmitServer_Reply* reply);
            events::Basc_FileTransmitServer_Ntf_FileTransmit Ntf_FileTransmit;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_FileTransmitServer_skeleton";
			Basc_FileTransmitServer_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif
