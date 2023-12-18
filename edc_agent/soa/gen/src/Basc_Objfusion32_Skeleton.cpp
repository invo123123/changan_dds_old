/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.7
  ServiceLatestModifyTime: 2023-06-26T18:41:39
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#include "changan/Basc_Objfusion32_Skeleton.hpp"
#include "changan/dds_server.hpp"
#include <iostream>
#include <thread>
#include <string.h>
#include "changan/string_util.hpp"
#include "changan/business_util.h"

namespace com {
namespace changan {
namespace carDrive {
namespace C2Controller {
namespace skeleton {
	using namespace com::changan::rpc_service;
	using namespace com::changan::soa_log::skeleton;
	Basc_Objfusion32_Skeleton::Basc_Objfusion32_Skeleton(Basc_Objfusion32_service_interface* service,std::string config):_config(config),_service(service){}

	void on_Basc_Objfusion32_request_subscription_matched_cb(dds_entity_t reader, const dds_subscription_matched_status_t  status, void* arg){
		ASF_LOG_DEBUG_ARGS("on_Basc_Objfusion32_request_subscription_matched_cb, reader=[%d], current_count=[%d]", reader, status.current_count);
		Basc_Objfusion32_Skeleton * skeleton = (Basc_Objfusion32_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_Objfusion32_skeleton");
		if(NULL==skeleton){
			return;
		}
		auto handler=skeleton->get_consumer_matched_handler();
		if(NULL!=handler){
			ConsumerMatchedStatus data=DDSUtil::get_consumer_matched_status(reader,status);
			handler(data);
		}
	}

	void Basc_Objfusion32_Skeleton::wait_client_online()
	{
		this->wait_for_pub_online(dds_rpc_reply_handle.writer);
	}

    bool Basc_Objfusion32_Skeleton::init() {
        std::lock_guard<std::mutex> guard(init_mutex);
		if (this->init_flag) {
			return true;
		}
		logconfig_Skeleton::get_instance().init(this->_config);
		this->Ntf_Objfusion32.init(this->_config);
		this->init_flag = true;
		return true;

	}

	bool Basc_Objfusion32_Skeleton::destroy() {
		ASF_LOG_DEBUG_ARGS("Basc_Objfusion32_Skeleton::destroy");
		std::lock_guard<std::mutex> guard(init_mutex);
		if (!this->init_flag) {
			return true;
		}
		this->Ntf_Objfusion32.destroy();
		this->init_flag = false;
		return true;
	}

}
}
}
}
}
