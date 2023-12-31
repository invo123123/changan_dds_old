/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.2
  ServiceLatestModifyTime: 2023-11-29T15:27:54
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_DTCUploadC2MCU_SKELETON_HPP
#define Basc_DTCUploadC2MCU_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_DTCUploadC2MCU.h"
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
        class Basc_DTCUploadC2MCU_Ntf_DTCinfo_C2MCU{
            private:
                dds_rpc_handle_t dds_Ntf_DTCinfo_C2MCU_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_DTCUploadC2MCU_skeleton_Ntf_DTCinfo_C2MCU";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_DTCUploadC2MCU_Ntf_desc, &dds_Ntf_DTCinfo_C2MCU_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_DTCinfo_C2MCU_event_handle);
				}
				void send(const DTCArrayInfo_Struct &data) {
					carDrive_Basc_DTCUploadC2MCU_Ntf event_data;
					event_data.data._d = carDrive_Basc_DTCUploadC2MCU_Ntf_DTCinfo_C2MCU_Hash;
					event_data.data._u.Basc_DTCUploadC2MCU_Ntf_DTCinfo_C2MCU = data;
                    dds_write(dds_Ntf_DTCinfo_C2MCU_event_handle.writer, &event_data);
				}
        };
        class Basc_DTCUploadC2MCU_Ntf_DTCinfo_C2Sensor{
            private:
                dds_rpc_handle_t dds_Ntf_DTCinfo_C2Sensor_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_DTCUploadC2MCU_skeleton_Ntf_DTCinfo_C2Sensor";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_DTCUploadC2MCU_Ntf_desc, &dds_Ntf_DTCinfo_C2Sensor_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_DTCinfo_C2Sensor_event_handle);
				}
				void send(const DTCArrayInfo_Struct &data) {
					carDrive_Basc_DTCUploadC2MCU_Ntf event_data;
					event_data.data._d = carDrive_Basc_DTCUploadC2MCU_Ntf_DTCinfo_C2Sensor_Hash;
					event_data.data._u.Basc_DTCUploadC2MCU_Ntf_DTCinfo_C2Sensor = data;
                    dds_write(dds_Ntf_DTCinfo_C2Sensor_event_handle.writer, &event_data);
				}
        };
        class Basc_DTCUploadC2MCU_Ntf_clear_DTC{
            private:
                dds_rpc_handle_t dds_Ntf_clear_DTC_event_handle = { -1, -1, -1 };
				std::string _topic_name = "Basc_DTCUploadC2MCU_skeleton_Ntf_clear_DTC";
			public:
			    void init(std::string config = "") {
					DDSUtil::event_pub_init(DDS_DOMAIN_ID, _topic_name, &carDrive_Basc_DTCUploadC2MCU_Ntf_desc, &dds_Ntf_clear_DTC_event_handle,NULL, {PROXY_TOKEN, PROXY_TOKEN, ""}, config);
			    }
				bool destroy() {
					return DDSUtil::dds_client_destroy(&dds_Ntf_clear_DTC_event_handle);
				}
				void send(const DTCArrayInfo_Struct &data) {
					carDrive_Basc_DTCUploadC2MCU_Ntf event_data;
					event_data.data._d = carDrive_Basc_DTCUploadC2MCU_Ntf_clear_DTC_Hash;
					event_data.data._u.Basc_DTCUploadC2MCU_Ntf_clear_DTC = data;
                    dds_write(dds_Ntf_clear_DTC_event_handle.writer, &event_data);
				}
        };
	}
	extern void on_carDrive_Basc_DTCUploadC2MCU_request_data_available(int32_t reader, void* arg);

	class Basc_DTCUploadC2MCU_service_interface {
	public:
	    virtual ~Basc_DTCUploadC2MCU_service_interface() = default;

		virtual uint8_t getDtcInfo() = 0;
	};
    class Basc_DTCUploadC2MCU_Skeleton :public Basc_DTCUploadC2MCU_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_DTCUploadC2MCU_Skeleton(Basc_DTCUploadC2MCU_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			uint8_t getDtcInfo() {
				return this->_service->getDtcInfo();
			}
            dds_return_t send_reply(carDrive_Basc_DTCUploadC2MCU_Reply* reply);
            events::Basc_DTCUploadC2MCU_Ntf_DTCinfo_C2MCU Ntf_DTCinfo_C2MCU;
            events::Basc_DTCUploadC2MCU_Ntf_DTCinfo_C2Sensor Ntf_DTCinfo_C2Sensor;
            events::Basc_DTCUploadC2MCU_Ntf_clear_DTC Ntf_clear_DTC;

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_DTCUploadC2MCU_skeleton";
			Basc_DTCUploadC2MCU_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

