/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.0.5
  ServiceLatestModifyTime: 2023-11-21T15:20:28
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#include "changan/Basc_APAInteract_Skeleton.hpp"
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
	void carDrive_Basc_APAInteract_Get_AD_APACustSlot(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->Get_AD_APACustSlot");
		AD_APACustSlotData ret = skeleton->Get_AD_APACustSlot();
		ASF_LOG_DEBUG_ARGS("after skeleton->Get_AD_APACustSlot");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_Get_AD_APACustSlot_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.Get_AD_APACustSlot.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_Get_AD_APADynguidance(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->Get_AD_APADynguidance");
		AD_APADynguidanceData ret = skeleton->Get_AD_APADynguidance();
		ASF_LOG_DEBUG_ARGS("after skeleton->Get_AD_APADynguidance");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_Get_AD_APADynguidance_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.Get_AD_APADynguidance.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_Get_AD_APADynrecommd(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->Get_AD_APADynrecommd");
		AD_APADynrecommdData ret = skeleton->Get_AD_APADynrecommd();
		ASF_LOG_DEBUG_ARGS("after skeleton->Get_AD_APADynrecommd");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.Get_AD_APADynrecommd.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->Get_AD_APAFctnIndnMsg");
		AD_APAFctnIndnMsgData ret = skeleton->Get_AD_APAFctnIndnMsg();
		ASF_LOG_DEBUG_ARGS("after skeleton->Get_AD_APAFctnIndnMsg");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.Get_AD_APAFctnIndnMsg.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_EDC_APADrvrReqOnOff");
		uint8_t ret = skeleton->RR_EDC_APADrvrReqOnOff(request->data._u.RR_EDC_APADrvrReqOnOff.EDC_APADrvrReqOnOffData,request->data._u.RR_EDC_APADrvrReqOnOff.RequestInfo);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_EDC_APADrvrReqOnOff");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_EDC_APADrvrReqOnOff.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_EDC_APADrvrReqSlotID");
		uint8_t ret = skeleton->RR_EDC_APADrvrReqSlotID(request->data._u.RR_EDC_APADrvrReqSlotID.EDC_APADrvrReqSlotIDData,request->data._u.RR_EDC_APADrvrReqSlotID.RequestInfo);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_EDC_APADrvrReqSlotID");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_EDC_APADrvrReqSlotID.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_EDC_APAParkInSelect");
		uint8_t ret = skeleton->RR_EDC_APAParkInSelect(request->data._u.RR_EDC_APAParkInSelect.EDC_APAParkInSelectData,request->data._u.RR_EDC_APAParkInSelect.RequestInfo);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_EDC_APAParkInSelect");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_EDC_APAParkInSelect.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_EDC_APADynamicOperate");
		uint8_t ret = skeleton->RR_EDC_APADynamicOperate(request->data._u.RR_EDC_APADynamicOperate.EDC_APADynamicOperateData,request->data._u.RR_EDC_APADynamicOperate.RequestInfo);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_EDC_APADynamicOperate");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_EDC_APADynamicOperate.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_EDC_APAParkOutSelect");
		uint8_t ret = skeleton->RR_EDC_APAParkOutSelect(request->data._u.RR_EDC_APAParkOutSelect.EDC_APAParkOutSelectData,request->data._u.RR_EDC_APAParkOutSelect.RequestInfo);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_EDC_APAParkOutSelect");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_EDC_APAParkOutSelect.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_RR_EDC_APACustSlot(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_EDC_APACustSlot");
		uint8_t ret = skeleton->RR_EDC_APACustSlot(request->data._u.RR_EDC_APACustSlot.EDC_APACustSlotData,request->data._u.RR_EDC_APACustSlot.RequestInfo);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_EDC_APACustSlot");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_EDC_APACustSlot.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq(carDrive_Basc_APAInteract_Request * request){
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		ASF_LOG_DEBUG_ARGS("pre skeleton->RR_EDC_RADSDrvrReq");
		uint8_t ret = skeleton->RR_EDC_RADSDrvrReq(request->data._u.RR_EDC_RADSDrvrReq.EDC_RADSDrvrReqData,request->data._u.RR_EDC_RADSDrvrReq.RequestInfo);
		ASF_LOG_DEBUG_ARGS("after skeleton->RR_EDC_RADSDrvrReq");
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->data._d = carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
		reply_msg->data._u.RR_EDC_RADSDrvrReq.return_ = ret;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
		}
	void carDrive_Basc_APAInteract_Deal_Invalid_Method(carDrive_Basc_APAInteract_Request * request){
		if (BussinessUtil::isEventType(request->data._d)) {
			return;
		}
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		carDrive_Basc_APAInteract_Reply* reply_msg = carDrive_Basc_APAInteract_Reply__alloc();
		reply_msg->header.relatedRequestId = request->header.requestId;
		reply_msg->header.remoteEx = DDS_RPC_REMOTE_METHOD_NOT_FOUND;
		skeleton->send_reply(reply_msg);
		carDrive_Basc_APAInteract_Reply_free(reply_msg, DDS_FREE_ALL);
		carDrive_Basc_APAInteract_Request_free(request, DDS_FREE_ALL);
	}
    void on_carDrive_Basc_APAInteract_request_data_available(int32_t reader, void* arg){
    	ASF_LOG_DEBUG_ARGS("on_carDrive_Basc_APAInteract_request_data_available");
		dds_return_t rc;
		//printf("RPC server on data available!\n");
		void* samples[1];
		samples[0] = carDrive_Basc_APAInteract_Request__alloc();
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0) {
			ASF_LOG_ERROR_ARGS("on_carDrive_Basc_APAInteract_request_data_available, dds_take_next faild, rc=[%d]",rc);
			DDS_FATAL("dds_take_next failed!\n");
		}
		if (infos[0].valid_data)
		{
			carDrive_Basc_APAInteract_Request* request = (carDrive_Basc_APAInteract_Request*)samples[0];
			int32_t funID = request->data._d;
			ASF_LOG_DEBUG_ARGS("on_carDrive_Basc_APAInteract_request_data_available, hashId=[%d], reqId=[%d]", funID,  request->header.requestId.sequence_number.low);			switch (funID) {
				case carDrive_Basc_APAInteract_Get_AD_APACustSlot_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_Get_AD_APACustSlot, request);
					break;
				}
				case carDrive_Basc_APAInteract_Get_AD_APADynguidance_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_Get_AD_APADynguidance, request);
					break;
				}
				case carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_Get_AD_APADynrecommd, request);
					break;
				}
				case carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg, request);
					break;
				}
				case carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff, request);
					break;
				}
				case carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID, request);
					break;
				}
				case carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect, request);
					break;
				}
				case carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate, request);
					break;
				}
				case carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect, request);
					break;
				}
				case carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_RR_EDC_APACustSlot, request);
					break;
				}
				case carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq, request);
					break;
				}
				default:
				{
					DDSServer::execute(carDrive_Basc_APAInteract_Deal_Invalid_Method,request);
					break;
				}
			}
			return;
		}
		carDrive_Basc_APAInteract_Request_free(samples[0],DDS_FREE_ALL);
	}
	Basc_APAInteract_Skeleton::Basc_APAInteract_Skeleton(Basc_APAInteract_service_interface* service,std::string config):_config(config),_service(service){}

	void on_Basc_APAInteract_request_subscription_matched_cb(dds_entity_t reader, const dds_subscription_matched_status_t  status, void* arg){
		ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_request_subscription_matched_cb, reader=[%d], current_count=[%d]", reader, status.current_count);
		Basc_APAInteract_Skeleton * skeleton = (Basc_APAInteract_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_APAInteract_skeleton");
		if(NULL==skeleton){
			return;
		}
		auto handler=skeleton->get_consumer_matched_handler();
		if(NULL!=handler){
			ConsumerMatchedStatus data=DDSUtil::get_consumer_matched_status(reader,status);
			handler(data);
		}
	}

	void Basc_APAInteract_Skeleton::wait_client_online()
	{
		this->wait_for_pub_online(dds_rpc_reply_handle.writer);
	}

    bool Basc_APAInteract_Skeleton::init() {
        std::lock_guard<std::mutex> guard(init_mutex);
		if (this->init_flag) {
			return true;
		}
		logconfig_Skeleton::get_instance().init(this->_config);
		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			this->service_name + "_reply",
			&carDrive_Basc_APAInteract_Reply_desc,
			&dds_rpc_reply_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},this->_config
		);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->service_name + "_request",

			&carDrive_Basc_APAInteract_Request_desc,
			&on_carDrive_Basc_APAInteract_request_data_available,
			NULL,
			&dds_rpc_request_handle,
			&on_Basc_APAInteract_request_subscription_matched_cb,{PROXY_TOKEN, PROXY_TOKEN, ""},{},this->_config
		);
		this->Ntf_AD_APACustSlot.init(this->_config);
		this->Ntf_AD_APADynguidance.init(this->_config);
		this->Ntf_AD_APADynrecommd.init(this->_config);
		this->Ntf_AD_APAFctnIndnMsg.init(this->_config);
		this->init_flag = true;
		return true;

	}

	bool Basc_APAInteract_Skeleton::destroy() {
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Skeleton::destroy");
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
		this->Ntf_AD_APACustSlot.destroy();
		this->Ntf_AD_APADynguidance.destroy();
		this->Ntf_AD_APADynrecommd.destroy();
		this->Ntf_AD_APAFctnIndnMsg.destroy();
		this->init_flag = false;
		return true;
	}

	dds_return_t Basc_APAInteract_Skeleton::send_reply(carDrive_Basc_APAInteract_Reply* reply) {
		dds_return_t rc = DDSUtil::send(dds_rpc_reply_handle.writer, reply);
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Skeleton::send_reply hashId=[%d], reqId=[%d], rc=[%d]", reply->data._d, reply->header.relatedRequestId.sequence_number.low, rc);
		return rc;
	}
}
}
}
}
}

