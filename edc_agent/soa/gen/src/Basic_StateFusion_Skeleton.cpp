/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.7
  ServiceLatestModifyTime: 2023-06-12T14:17:48
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#include "changan/Basic_StateFusion_Skeleton.hpp"
#include "changan/dds_server.hpp"
#include <iostream>
#include <thread>
#include <string.h>
#include "changan/string_util.hpp"
#include "changan/business_util.h"

namespace com {
namespace changan {
namespace carDrive {
namespace BasicService {
namespace skeleton {
	using namespace com::changan::rpc_service;
	using namespace com::changan::soa_log::skeleton;
	Basic_StateFusion_Skeleton::Basic_StateFusion_Skeleton(Basic_StateFusion_service_interface* service,std::string config):_config(config),_service(service){}

	void on_Basic_StateFusion_request_subscription_matched_cb(dds_entity_t reader, const dds_subscription_matched_status_t  status, void* arg){
		ASF_LOG_DEBUG_ARGS("on_Basic_StateFusion_request_subscription_matched_cb, reader=[%d], current_count=[%d]", reader, status.current_count);
		Basic_StateFusion_Skeleton * skeleton = (Basic_StateFusion_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basic_StateFusion_skeleton");
		if(NULL==skeleton){
			return;
		}
		auto handler=skeleton->get_consumer_matched_handler();
		if(NULL!=handler){
			ConsumerMatchedStatus data=DDSUtil::get_consumer_matched_status(reader,status);
			handler(data);
		}
	}

	void Basic_StateFusion_Skeleton::wait_client_online()
	{
		this->wait_for_pub_online(dds_rpc_reply_handle.writer);
	}

    bool Basic_StateFusion_Skeleton::init() {
        std::lock_guard<std::mutex> guard(init_mutex);
		if (this->init_flag) {
			return true;
		}
		logconfig_Skeleton::get_instance().init(this->_config);
		this->Ntf_Status.init(this->_config);
		this->init_flag = true;
		return true;

	}

	bool Basic_StateFusion_Skeleton::destroy() {
		ASF_LOG_DEBUG_ARGS("Basic_StateFusion_Skeleton::destroy");
		std::lock_guard<std::mutex> guard(init_mutex);
		if (!this->init_flag) {
			return true;
		}
		this->Ntf_Status.destroy();
		this->init_flag = false;
		return true;
	}

}
}
}
}
}

