/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.5
  ServiceLatestModifyTime: 2023-11-21T15:42:15
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#include "changan/Basic_APAFunctionReq_Skeleton.hpp"
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
	void carDrive_Basic_APAFunctionReq_RR_APAFunctionReq(carDrive_Basic_APAFunctionReq_Request * request){
		Basic_APAFunctionReq_Skeleton * skeleton = (Basic_APAFunctionReq_Skeleton*)DDSServer::get_service("Basic_APAFunctionReq_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_APAFunctionReq");
		APAReqreply ret = skeleton->RR_APAFunctionReq(request->data._u.RR_APAFunctionReq.RR_APAFunctionReq);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_APAFunctionReq");
		carDrive_Basic_APAFunctionReq_Reply* reply_msg = carDrive_Basic_APAFunctionReq_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_APAFunctionReq.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basic_APAFunctionReq_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basic_APAFunctionReq_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basic_APAFunctionReq_RR_APAControleReq(carDrive_Basic_APAFunctionReq_Request * request){
		Basic_APAFunctionReq_Skeleton * skeleton = (Basic_APAFunctionReq_Skeleton*)DDSServer::get_service("Basic_APAFunctionReq_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_APAControleReq");
		APAReqreply ret = skeleton->RR_APAControleReq(request->data._u.RR_APAControleReq.APAControlReq);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_APAControleReq");
		carDrive_Basic_APAFunctionReq_Reply* reply_msg = carDrive_Basic_APAFunctionReq_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basic_APAFunctionReq_RR_APAControleReq_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_APAControleReq.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basic_APAFunctionReq_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basic_APAFunctionReq_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basic_APAFunctionReq_Deal_Invalid_Method(carDrive_Basic_APAFunctionReq_Request * request){
		if (BussinessUtil::isEventType(request->data._d)) {
			return;
		}
		Basic_APAFunctionReq_Skeleton * skeleton = (Basic_APAFunctionReq_Skeleton*)DDSServer::get_service("Basic_APAFunctionReq_skeleton");
		if(NULL==skeleton){
			return;
		}
		carDrive_Basic_APAFunctionReq_Reply* reply_msg = carDrive_Basic_APAFunctionReq_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_METHOD_NOT_FOUND;
		skeleton->send_reply(reply_msg);
		carDrive_Basic_APAFunctionReq_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basic_APAFunctionReq_Request_free(request, DDS_FREE_ALL);
	}
    void on_carDrive_Basic_APAFunctionReq_request_data_available(int32_t reader, void* arg){
    	ASF_LOG_DEBUG_ARGS("on_carDrive_Basic_APAFunctionReq_request_data_available");
		dds_return_t rc;
		//printf("RPC server on data available!\n");
		void* samples[1];
		samples[0] = carDrive_Basic_APAFunctionReq_Request__alloc();
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0) {
			ASF_LOG_ERROR_ARGS("on_carDrive_Basic_APAFunctionReq_request_data_available, dds_take_next faild, rc=[%d]",rc);
			DDS_FATAL("dds_take_next failed!\n");
		}
		if (infos[0].valid_data)
		{
			carDrive_Basic_APAFunctionReq_Request* request = (carDrive_Basic_APAFunctionReq_Request*)samples[0];
			int32_t funID = request->data._d;
			ASF_LOG_DEBUG_ARGS("on_carDrive_Basic_APAFunctionReq_request_data_available, hashId=[%d], reqId=[%d]", funID,  request->header.requestId.sequence_number.low);			switch (funID) {
				case carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Hash:
				{
					DDSServer::execute(carDrive_Basic_APAFunctionReq_RR_APAFunctionReq, request);
					break;
				}
				case carDrive_Basic_APAFunctionReq_RR_APAControleReq_Hash:
				{
					DDSServer::execute(carDrive_Basic_APAFunctionReq_RR_APAControleReq, request);
					break;
				}
				default:
				{
					DDSServer::execute(carDrive_Basic_APAFunctionReq_Deal_Invalid_Method,request);
					break;
				}
			}
			return;
		}
		carDrive_Basic_APAFunctionReq_Request_free(samples[0],DDS_FREE_ALL);
	}
	Basic_APAFunctionReq_Skeleton::Basic_APAFunctionReq_Skeleton(Basic_APAFunctionReq_service_interface* service,std::string config):_config(config),_service(service){}

	void on_Basic_APAFunctionReq_request_subscription_matched_cb(dds_entity_t reader, const dds_subscription_matched_status_t  status, void* arg){
		ASF_LOG_DEBUG_ARGS("on_Basic_APAFunctionReq_request_subscription_matched_cb, reader=[%d], current_count=[%d]", reader, status.current_count);
		Basic_APAFunctionReq_Skeleton * skeleton = (Basic_APAFunctionReq_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basic_APAFunctionReq_skeleton");
		if(NULL==skeleton){
			return;
		}
		auto handler=skeleton->get_consumer_matched_handler();
		if(NULL!=handler){
			ConsumerMatchedStatus data=DDSUtil::get_consumer_matched_status(reader,status);
			handler(data);
		}
	}

	void Basic_APAFunctionReq_Skeleton::wait_client_online()
	{
		this->wait_for_pub_online(dds_rpc_reply_handle.writer);
	}

    bool Basic_APAFunctionReq_Skeleton::init() {
        std::lock_guard<std::mutex> guard(init_mutex);
		if (this->init_flag) {
			return true;
		}
		logconfig_Skeleton::get_instance().init(this->_config);
		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			this->service_name + "_reply",
			&carDrive_Basic_APAFunctionReq_Reply_desc,
			&dds_rpc_reply_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},this->_config
		);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->service_name + "_request",

			&carDrive_Basic_APAFunctionReq_Request_desc,
			&on_carDrive_Basic_APAFunctionReq_request_data_available,
			NULL,
			&dds_rpc_request_handle,
			&on_Basic_APAFunctionReq_request_subscription_matched_cb,{PROXY_TOKEN, PROXY_TOKEN, ""},{},this->_config
		);
		this->Ntf_APAFunctionRes.init(this->_config);
		this->init_flag = true;
		return true;

	}

	bool Basic_APAFunctionReq_Skeleton::destroy() {
		ASF_LOG_DEBUG_ARGS("Basic_APAFunctionReq_Skeleton::destroy");
		std::lock_guard<std::mutex> guard(init_mutex);
		if (!this->init_flag) {
			return true;
		}
		if (!DDSUtil::dds_client_destroy(&dds_rpc_request_handle)) {
			return false;
		}
		if (!DDSUtil::dds_client_destroy(&dds_rpc_reply_handle)) {
			return false;
		}
		this->Ntf_APAFunctionRes.destroy();
		this->init_flag = false;
		return true;
	}

	dds_return_t Basic_APAFunctionReq_Skeleton::send_reply(carDrive_Basic_APAFunctionReq_Reply* reply) {
		dds_return_t rc = DDSUtil::send(dds_rpc_reply_handle.writer, reply);
		ASF_LOG_DEBUG_ARGS("Basic_APAFunctionReq_Skeleton::send_reply hashId=[%d], reqId=[%d], rc=[%d]", reply->data._d, reply->header.relatedRequestId.sequence_number.low, rc);
		return rc;
	}
}
}
}
}
}

