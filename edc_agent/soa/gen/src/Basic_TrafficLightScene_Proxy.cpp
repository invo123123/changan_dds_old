/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.5.2
  ServiceLatestModifyTime: 2023-03-15T13:43:54
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#include "changan/Basic_TrafficLightScene_Proxy.hpp"
#include <string.h>
#include "dds/ddsrt/sync.h"
#include <iostream>
#include "changan/string_util.hpp"
#include "changan/dds_client.hpp"
namespace com {
namespace changan {
namespace carDrive {
namespace BasicService {
namespace proxy {
    using namespace com::changan::rpc_service;
    using namespace com::changan::soa_log::skeleton;
    void Basic_TrafficLightScene_Ntf_TrafficLight_trigger(carDrive_Basic_TrafficLightScene_Ntf* notify_data){
	    Basic_TrafficLightScene_Proxy::get_instance().Ntf_TrafficLight.trigger(notify_data->data._u.Basic_TrafficLightScene_Ntf_TrafficLight);
		carDrive_Basic_TrafficLightScene_Ntf_free(notify_data, DDS_FREE_ALL);
    }
    void on_Basic_TrafficLightScene_Ntf_TrafficLight_data_available(int32_t reader, void* arg){
        ASF_LOG_DEBUG_ARGS("on_Basic_TrafficLightScene_Ntf_TrafficLight_data_available");
    	dds_return_t rc;
		carDrive_Basic_TrafficLightScene_Ntf* data;
		void* samples[1];
		samples[0] = carDrive_Basic_TrafficLightScene_Ntf__alloc();
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0){
			ASF_LOG_ERROR_ARGS("on_Basic_TrafficLightScene_Ntf_TrafficLight_data_available dds_take_next faild rc=[%d]", rc);
			//printf("dds_take_next failed!\n");
        }
		if (infos[0].valid_data){
            data = (carDrive_Basic_TrafficLightScene_Ntf*)samples[0];
            ASF_LOG_DEBUG_ARGS("on_Basic_TrafficLightScene_Ntf_TrafficLight_data_available, hashId=[%d]", data->data._d);
			DDSClient::execute(Basic_TrafficLightScene_Ntf_TrafficLight_trigger,data);
			return;
		}
		carDrive_Basic_TrafficLightScene_Ntf_free(samples[0],DDS_FREE_ALL);
	}

	Basic_TrafficLightScene_Proxy::Basic_TrafficLightScene_Proxy(){

    }

    void on_Basic_TrafficLightScene_request_publication_matched_cb(dds_entity_t writer, const dds_publication_matched_status_t  status, void* arg) {
		ASF_LOG_DEBUG_ARGS("on_Basic_TrafficLightScene_request_publication_matched_cb, writer=[%d], current_count=[%d]", writer, status.current_count);
		Basic_TrafficLightScene_Proxy *pTmp = &Basic_TrafficLightScene_Proxy::get_instance();
		auto handler=Basic_TrafficLightScene_Proxy::get_instance().get_provider_matched_handler();
		if(NULL!=handler){
			ProviderMatchedStatus data=DDSUtil::get_provider_matched_status(writer,status);
			if(data.is_online == true)
            {
                pTmp->add_link_count();
            }
			else
            {
                pTmp->subtract_link_count();
            }
            if(pTmp->get_link_count() < 2)
            {
               data.is_online = false;
            }
            handler(data);
		}
	}
	
	void on_Basic_TrafficLightScene_reply_sublication_matched_cb(dds_entity_t reader, const dds_subscription_matched_status_t  status, void* arg) {
		ASF_LOG_DEBUG_ARGS("on_Basic_TrafficLightScene_reply_sublication_matched_cb, reader=[%d], current_count=[%d]", reader, status.current_count);
		Basic_TrafficLightScene_Proxy *pTmp = &Basic_TrafficLightScene_Proxy::get_instance();
        auto handler = pTmp->get_provider_matched_handler();
        if(NULL!=handler){
            ConsumerMatchedStatus ConsumerData=DDSUtil::get_consumer_matched_status(reader,status);
            ProviderMatchedStatus ProviderData;
			ProviderData.is_online = false;
            if(ConsumerData.is_online == true)
            {
                pTmp->add_link_count();
            }
            else
            {
                pTmp->subtract_link_count();
            }
            
            if(pTmp->get_link_count() == 2)
            {
                ProviderData.is_online = true;
            }
            handler(ProviderData);
        }
    }


	void Basic_TrafficLightScene_Proxy::wait_server_online()
	{
		this->wait_for_sub_online(dds_rpc_reply_handle.reader);
	}

	bool Basic_TrafficLightScene_Proxy::init(std::string config) {
	    std::lock_guard<std::mutex> guard(init_mutex);
	    if(this->init_flag){
	        return true;
	    }
		logconfig_Skeleton::get_instance().init(config);
		DDSUtil::event_sub_init(0,
			"hmi_interface____HmiInterface__BasicTrafficLightScene",
		    &carDrive_Basic_TrafficLightScene_Ntf_desc,
			&on_Basic_TrafficLightScene_Ntf_TrafficLight_data_available,
			NULL,
			&dds_Ntf_TrafficLight_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config);

		this->init_flag = true;
		return true;
	}

	bool Basic_TrafficLightScene_Proxy::destroy() {
		ASF_LOG_DEBUG_ARGS("Basic_TrafficLightScene_Proxy::destroy");
		std::lock_guard<std::mutex> guard(init_mutex);
	    if (!this->init_flag) {
			return true;
		}
		if (!DDSUtil::dds_client_destroy(&dds_Ntf_TrafficLight_handle)) {
			return false;
		}
		this->init_flag = false;
		return true;
	}

    Basic_TrafficLightScene_Proxy::~Basic_TrafficLightScene_Proxy(){

    }

	Basic_TrafficLightScene_Proxy& Basic_TrafficLightScene_Proxy::get_instance()
	{
		static Basic_TrafficLightScene_Proxy instance;
		return instance;
	}
}
}
}
}
}

