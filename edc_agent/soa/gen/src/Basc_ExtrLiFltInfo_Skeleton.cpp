/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V2.3
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-07-25T12:19:34
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "changan/Basc_ExtrLiFltInfo_Skeleton.hpp"
#include "changan/dds_server.hpp"
#include <iostream>
#include <thread>
#include <string.h>
#include "changan/string_util.hpp"

namespace com {
namespace changan {
namespace carControl {
namespace ExteriorLight {
namespace skeleton {
    void on_carControl_Basc_ExtrLiFltInfo_request_data_available(int32_t reader, void* arg){
		Basc_ExtrLiFltInfo_Skeleton * skeleton = (Basc_ExtrLiFltInfo_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_ExtrLiFltInfo_skeleton");
		if(NULL==skeleton){
			return;
		}
		dds_return_t rc;
		ASF_LOG_DEBUG_ARGS("RPC server on data available!");
		carControl_Car_Control_Request* request= carControl_Car_Control_Request__alloc();;
		static void* samples[1];
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0)
			DDS_FATAL("dds_take_next failed!\n");

		if (infos[0].valid_data)
		{
			request = (carControl_Car_Control_Request*)samples[0];
			int32_t funID = request->data._d;
			switch (funID) {
			case carControl_Car_Control_Basc_ExtrLiFltInfo_Get_PosnLiFltInfo_Hash:
			{
				PosnLiFltInfo ret = skeleton->Get_PosnLiFltInfo();
				carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
				reply_msg->header.relatedRequestId = request->header.requestId;
				reply_msg->data._d = carControl_Car_Control_Basc_ExtrLiFltInfo_Get_PosnLiFltInfo_Hash;
				reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
				reply_msg->data._u.Basc_ExtrLiFltInfo_Get_PosnLiFltInfo.return_ = ret;
				skeleton->send_reply(reply_msg);
				carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				break;
			}
			case carControl_Car_Control_Basc_ExtrLiFltInfo_Get_LoBeamFltInfo_Hash:
			{
				LoBeamFltInfo ret = skeleton->Get_LoBeamFltInfo();
				carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
				reply_msg->header.relatedRequestId = request->header.requestId;
				reply_msg->data._d = carControl_Car_Control_Basc_ExtrLiFltInfo_Get_LoBeamFltInfo_Hash;
				reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
				reply_msg->data._u.Basc_ExtrLiFltInfo_Get_LoBeamFltInfo.return_ = ret;
				skeleton->send_reply(reply_msg);
				carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				break;
			}
			case carControl_Car_Control_Basc_ExtrLiFltInfo_Get_HiBeamFltInfo_Hash:
			{
				HiBeamFltInfo ret = skeleton->Get_HiBeamFltInfo();
				carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
				reply_msg->header.relatedRequestId = request->header.requestId;
				reply_msg->data._d = carControl_Car_Control_Basc_ExtrLiFltInfo_Get_HiBeamFltInfo_Hash;
				reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
				reply_msg->data._u.Basc_ExtrLiFltInfo_Get_HiBeamFltInfo.return_ = ret;
				skeleton->send_reply(reply_msg);
				carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				break;
			}
			case carControl_Car_Control_Basc_ExtrLiFltInfo_Get_RvsLiFltInfo_Hash:
			{
				RvsLiFltInfo ret = skeleton->Get_RvsLiFltInfo();
				carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
				reply_msg->header.relatedRequestId = request->header.requestId;
				reply_msg->data._d = carControl_Car_Control_Basc_ExtrLiFltInfo_Get_RvsLiFltInfo_Hash;
				reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
				reply_msg->data._u.Basc_ExtrLiFltInfo_Get_RvsLiFltInfo.return_ = ret;
				skeleton->send_reply(reply_msg);
				carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				break;
			}
			case carControl_Car_Control_Basc_ExtrLiFltInfo_Get_DRLFltInfo_Hash:
			{
				DRLFltInfo ret = skeleton->Get_DRLFltInfo();
				carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
				reply_msg->header.relatedRequestId = request->header.requestId;
				reply_msg->data._d = carControl_Car_Control_Basc_ExtrLiFltInfo_Get_DRLFltInfo_Hash;
				reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
				reply_msg->data._u.Basc_ExtrLiFltInfo_Get_DRLFltInfo.return_ = ret;
				skeleton->send_reply(reply_msg);
				carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				break;
			}
			case carControl_Car_Control_Basc_ExtrLiFltInfo_Get_BrkLiFltInfo_Hash:
			{
				BrkLiFltInfo ret = skeleton->Get_BrkLiFltInfo();
				carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
				reply_msg->header.relatedRequestId = request->header.requestId;
				reply_msg->data._d = carControl_Car_Control_Basc_ExtrLiFltInfo_Get_BrkLiFltInfo_Hash;
				reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
				reply_msg->data._u.Basc_ExtrLiFltInfo_Get_BrkLiFltInfo.return_ = ret;
				skeleton->send_reply(reply_msg);
				carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				break;
			}
			case carControl_Car_Control_Basc_ExtrLiFltInfo_Get_TurnLiFltInfo_Hash:
			{
				TurnLiFltInfo ret = skeleton->Get_TurnLiFltInfo();
				carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
				reply_msg->header.relatedRequestId = request->header.requestId;
				reply_msg->data._d = carControl_Car_Control_Basc_ExtrLiFltInfo_Get_TurnLiFltInfo_Hash;
				reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
				reply_msg->data._u.Basc_ExtrLiFltInfo_Get_TurnLiFltInfo.return_ = ret;
				skeleton->send_reply(reply_msg);
				carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				break;
			}
			case carControl_Car_Control_Basc_ExtrLiFltInfo_Get_FogFltInfo_Hash:
			{
				FogFltInfo ret = skeleton->Get_FogFltInfo();
				carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
				reply_msg->header.relatedRequestId = request->header.requestId;
				reply_msg->data._d = carControl_Car_Control_Basc_ExtrLiFltInfo_Get_FogFltInfo_Hash;
				reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
				reply_msg->data._u.Basc_ExtrLiFltInfo_Get_FogFltInfo.return_ = ret;
				skeleton->send_reply(reply_msg);
				carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				break;
			}
			default:
				break;
			}
		}
	}
	Basc_ExtrLiFltInfo_Skeleton::Basc_ExtrLiFltInfo_Skeleton(Basc_ExtrLiFltInfo_service_interface* service,std::string config):_config(config),_service(service){}

	void Basc_ExtrLiFltInfo_Skeleton::wait_client_online()
	{
		using CarControlFLSkeleton = com::changan::carControl::skeleton::CarControlFLSkeleton;
		CarControlFLSkeleton::get_instance().wait_client_online();
	}

    bool Basc_ExtrLiFltInfo_Skeleton::init() {
        using CarControlFLSkeleton = com::changan::carControl::skeleton::CarControlFLSkeleton;
		CarControlFLSkeleton::get_instance().register_consumer_matched_handler(this->get_service_name(),this->get_consumer_matched_handler());
		CarControlFLSkeleton::get_instance().init(this->_config);
		return true;
	}

	dds_return_t Basc_ExtrLiFltInfo_Skeleton::send_reply(carControl_Car_Control_Reply* reply) {
		return DDSUtil::send(dds_rpc_reply_handle.writer, reply);
	}
}
}
}
}
}

