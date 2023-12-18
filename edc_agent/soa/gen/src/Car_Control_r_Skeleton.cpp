/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: 
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "changan/Car_Control_r_Skeleton.hpp"
#include "changan/dds_server.hpp"
#include <iostream>
#include <thread>
#include <string.h>
#include "changan/string_util.hpp"
#include "changan/business_util.h"
#include "changan/Basc_EleAirSuspModSet_Skeleton.hpp"
#include "changan/Basc_EleAirSuspModSts_Skeleton.hpp"
#include "changan/Basc_RearWiperFltSts_Skeleton.hpp"
#include "changan/Basc_TailGateSts_Skeleton.hpp"
namespace com {
	namespace changan {
		namespace carControl {
			namespace skeleton {
				using namespace com::changan::rpc_service;
				using namespace com::changan::soa_log::skeleton;
				void reply_r_service_no_register(DDS_SampleIdentity requestId) {
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = requestId;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_SERVICE_NOT_REGISTER;
				  	CarControlRSkeleton::get_instance().send_reply(reply_msg);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSet_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSet_Skeleton;
				Basc_EleAirSuspModSet_Skeleton* skeleton = (Basc_EleAirSuspModSet_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSet_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_EleAirSuspHighModSet");
				uint8_t ret = skeleton->Get_EleAirSuspHighModSet();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_EleAirSuspHighModSet");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSet_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSet_Skeleton;
				Basc_EleAirSuspModSet_Skeleton* skeleton = (Basc_EleAirSuspModSet_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSet_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_EleAirSuspIntenModSet");
				uint8_t ret = skeleton->Get_EleAirSuspIntenModSet();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_EleAirSuspIntenModSet");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSet_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSet_Skeleton;
				Basc_EleAirSuspModSet_Skeleton* skeleton = (Basc_EleAirSuspModSet_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSet_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Set_EleAirSuspHighModSet");
				uint8_t ret = skeleton->Set_EleAirSuspHighModSet(request->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet.EleAirSuspHighModSet);
					ASF_LOG_DEBUG_ARGS("after skeleton->Set_EleAirSuspHighModSet");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSet_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSet_Skeleton;
				Basc_EleAirSuspModSet_Skeleton* skeleton = (Basc_EleAirSuspModSet_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSet_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Set_EleAirSuspIntenModSet");
				uint8_t ret = skeleton->Set_EleAirSuspIntenModSet(request->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet.EleAirSuspIntenModSet);
					ASF_LOG_DEBUG_ARGS("after skeleton->Set_EleAirSuspIntenModSet");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSet_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSet_Skeleton;
				Basc_EleAirSuspModSet_Skeleton* skeleton = (Basc_EleAirSuspModSet_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSet_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_EleAirSuspAutoModSet");
				uint8_t ret = skeleton->Get_EleAirSuspAutoModSet();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_EleAirSuspAutoModSet");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSet_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSet_Skeleton;
				Basc_EleAirSuspModSet_Skeleton* skeleton = (Basc_EleAirSuspModSet_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSet_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Set_EleAirSuspAutoModSet");
				uint8_t ret = skeleton->Set_EleAirSuspAutoModSet(request->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet.EleAirSuspAutoModSet);
					ASF_LOG_DEBUG_ARGS("after skeleton->Set_EleAirSuspAutoModSet");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspIntenModSts(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSts_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSts_Skeleton;
				Basc_EleAirSuspModSts_Skeleton* skeleton = (Basc_EleAirSuspModSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_EleAirSuspIntenModSts");
				EleAirSuspIntenModSts ret = skeleton->Get_EleAirSuspIntenModSts();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_EleAirSuspIntenModSts");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspIntenModSts_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSts_Get_EleAirSuspIntenModSts.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspIntenModSts_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModSts(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSts_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSts_Skeleton;
				Basc_EleAirSuspModSts_Skeleton* skeleton = (Basc_EleAirSuspModSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_EleAirSuspHighModSts");
				EleAirSuspHighModSts ret = skeleton->Get_EleAirSuspHighModSts();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_EleAirSuspHighModSts");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModSts_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSts_Get_EleAirSuspHighModSts.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModSts_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModCHASts(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSts_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSts_Skeleton;
				Basc_EleAirSuspModSts_Skeleton* skeleton = (Basc_EleAirSuspModSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_EleAirSuspHighModCHASts");
				EleAirSuspHighModCHASts ret = skeleton->Get_EleAirSuspHighModCHASts();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_EleAirSuspHighModCHASts");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModCHASts_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSts_Get_EleAirSuspHighModCHASts.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModCHASts_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspAutoModSts(carControl_Car_Control_Request * request){
					using Basc_EleAirSuspModSts_Skeleton = com::changan::carControl::CHS_SUSP::skeleton::Basc_EleAirSuspModSts_Skeleton;
				Basc_EleAirSuspModSts_Skeleton* skeleton = (Basc_EleAirSuspModSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_EleAirSuspModSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_EleAirSuspAutoModSts");
				EleAirSuspAutoModSts ret = skeleton->Get_EleAirSuspAutoModSts();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_EleAirSuspAutoModSts");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspAutoModSts_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_EleAirSuspModSts_Get_EleAirSuspAutoModSts.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspAutoModSts_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_RearWiperFltSts_Get_WiperFltSts(carControl_Car_Control_Request * request){
					using Basc_RearWiperFltSts_Skeleton = com::changan::carControl::WiperWasher::skeleton::Basc_RearWiperFltSts_Skeleton;
				Basc_RearWiperFltSts_Skeleton* skeleton = (Basc_RearWiperFltSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_RearWiperFltSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_WiperFltSts");
				RWiperFltSt ret = skeleton->Get_WiperFltSts();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_WiperFltSts");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_RearWiperFltSts_Get_WiperFltSts_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_RearWiperFltSts_Get_WiperFltSts.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_RearWiperFltSts_Get_WiperFltSts_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_TailGateSts_Get_LockSt(carControl_Car_Control_Request * request){
					using Basc_TailGateSts_Skeleton = com::changan::carControl::Tailgate::skeleton::Basc_TailGateSts_Skeleton;
				Basc_TailGateSts_Skeleton* skeleton = (Basc_TailGateSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_TailGateSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_LockSt");
				uint8_t ret = skeleton->Get_LockSt();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_LockSt");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_TailGateSts_Get_LockSt_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_TailGateSts_Get_LockSt.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_TailGateSts_Get_LockSt_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_TailGateSts_Get_TailGateSysSt(carControl_Car_Control_Request * request){
					using Basc_TailGateSts_Skeleton = com::changan::carControl::Tailgate::skeleton::Basc_TailGateSts_Skeleton;
				Basc_TailGateSts_Skeleton* skeleton = (Basc_TailGateSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_TailGateSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_TailGateSysSt");
				uint8_t ret = skeleton->Get_TailGateSysSt();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_TailGateSysSt");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_TailGateSts_Get_TailGateSysSt_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_TailGateSts_Get_TailGateSysSt.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_TailGateSts_Get_TailGateSysSt_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_TailGateSts_Get_MotCurPosVIT(carControl_Car_Control_Request * request){
					using Basc_TailGateSts_Skeleton = com::changan::carControl::Tailgate::skeleton::Basc_TailGateSts_Skeleton;
				Basc_TailGateSts_Skeleton* skeleton = (Basc_TailGateSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_TailGateSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_MotCurPosVIT");
				uint8_t ret = skeleton->Get_MotCurPosVIT();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_MotCurPosVIT");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_TailGateSts_Get_MotCurPosVIT_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_TailGateSts_Get_MotCurPosVIT.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_TailGateSts_Get_MotCurPosVIT_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_TailGateSts_Get_TailGateWinSt(carControl_Car_Control_Request * request){
					using Basc_TailGateSts_Skeleton = com::changan::carControl::Tailgate::skeleton::Basc_TailGateSts_Skeleton;
				Basc_TailGateSts_Skeleton* skeleton = (Basc_TailGateSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_TailGateSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_TailGateWinSt");
				uint8_t ret = skeleton->Get_TailGateWinSt();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_TailGateWinSt");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_TailGateSts_Get_TailGateWinSt_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_TailGateSts_Get_TailGateWinSt.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_TailGateSts_Get_TailGateWinSt_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void carControl_Car_Control_Basc_TailGateSts_Get_WinCurPosVIT(carControl_Car_Control_Request * request){
					using Basc_TailGateSts_Skeleton = com::changan::carControl::Tailgate::skeleton::Basc_TailGateSts_Skeleton;
				Basc_TailGateSts_Skeleton* skeleton = (Basc_TailGateSts_Skeleton*)com::changan::rpc_service::DDSServer::get_service("Basc_TailGateSts_skeleton");
					if(NULL==skeleton){
						reply_r_service_no_register(request->header.requestId);
						carControl_Car_Control_Request_free(request, DDS_FREE_ALL);
						return;
					}
					ASF_LOG_DEBUG_ARGS("pre skeleton->Get_WinCurPosVIT");
				uint8_t ret = skeleton->Get_WinCurPosVIT();
					ASF_LOG_DEBUG_ARGS("after skeleton->Get_WinCurPosVIT");
					carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
					reply_msg->header.relatedRequestId = request->header.requestId;
					reply_msg->data._d = carControl_Car_Control_Basc_TailGateSts_Get_WinCurPosVIT_Hash;
					reply_msg->header.remoteEx = DDS_RPC_REMOTE_EX_OK;
					reply_msg->data._u.Basc_TailGateSts_Get_WinCurPosVIT.return_ = ret;
					dds_return_t rc = CarControlRSkeleton::get_instance().send_reply(reply_msg);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send_reply, hashId=[%d], reqId=[%d], rc=[%d]", carControl_Car_Control_Basc_TailGateSts_Get_WinCurPosVIT_Hash, reply_msg->header.relatedRequestId.sequence_number.low, rc);
					carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
				}
				void on_carControl_r_request_data_available(int32_t reader, void* arg) {
					ASF_LOG_DEBUG_ARGS("on_carControl_r_request_data_available");
					dds_return_t rc;
					//printf("RPC server on data available!\n");
					carControl_Car_Control_Request* request;
					void* samples[1];
					dds_sample_info_t infos[1];
					samples[0] = carControl_Car_Control_Request__alloc();
					rc = dds_take_next(reader, samples, infos);
					if (rc < 0) {
						ASF_LOG_ERROR_ARGS("on_carControl_r_request_data_available, dds_take_next faild, rc=[%d]",rc);
						DDS_FATAL("dds_take_next failed!\n");
					}
					if (infos[0].valid_data)
					{
						request = (carControl_Car_Control_Request*)samples[0];
						int32_t funID = request->data._d;
						ASF_LOG_DEBUG_ARGS("on_carControl_r_request_data_available, hashId=[%d], reqId=[%d]", funID,  request->header.requestId.sequence_number.low);
						switch (funID) {
						case carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspIntenModSts_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspIntenModSts, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModSts_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModSts, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModCHASts_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspHighModCHASts, request);
				            return;
				        }
						case carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspAutoModSts_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_EleAirSuspModSts_Get_EleAirSuspAutoModSts, request);
				            return;
				        }
						case carControl_Car_Control_Basc_RearWiperFltSts_Get_WiperFltSts_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_RearWiperFltSts_Get_WiperFltSts, request);
				            return;
				        }
						case carControl_Car_Control_Basc_TailGateSts_Get_LockSt_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_TailGateSts_Get_LockSt, request);
				            return;
				        }
						case carControl_Car_Control_Basc_TailGateSts_Get_TailGateSysSt_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_TailGateSts_Get_TailGateSysSt, request);
				            return;
				        }
						case carControl_Car_Control_Basc_TailGateSts_Get_MotCurPosVIT_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_TailGateSts_Get_MotCurPosVIT, request);
				            return;
				        }
						case carControl_Car_Control_Basc_TailGateSts_Get_TailGateWinSt_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_TailGateSts_Get_TailGateWinSt, request);
				            return;
				        }
						case carControl_Car_Control_Basc_TailGateSts_Get_WinCurPosVIT_Hash:
						{
							DDSServer::execute(carControl_Car_Control_Basc_TailGateSts_Get_WinCurPosVIT, request);
				            return;
				        }
						default:
							carControl_Car_Control_Reply* reply_msg = carControl_Car_Control_Reply__alloc();
							reply_msg->header.relatedRequestId = request->header.requestId;
							reply_msg->header.remoteEx = DDS_RPC_REMOTE_METHOD_NOT_FOUND;
				  			CarControlRSkeleton::get_instance().send_reply(reply_msg);
							carControl_Car_Control_Reply_free(reply_msg, DDS_FREE_ALL);
							break;
						}
					}
					carControl_Car_Control_Request_free(samples[0], DDS_FREE_ALL);
				}
				CarControlRSkeleton::CarControlRSkeleton() {}

				void on_CarControlRSkeleton_request_subscription_matched_cb(dds_entity_t reader, const dds_subscription_matched_status_t  status, void* arg) {
					ASF_LOG_DEBUG_ARGS("on_CarControlRSkeleton_request_subscription_matched_cb, reader=[%d], current_count=[%d]", reader, status.current_count);
					auto handlers=CarControlRSkeleton::get_instance().get_registered_consumer_matched_handler();
					ConsumerMatchedStatus data=DDSUtil::get_consumer_matched_status(reader,status);
				  	CarControlRSkeleton::get_instance().set_last_consumer_matched_status(data);
					for (const auto& it : handlers) {
						it.second(data);
					}
				}

				void CarControlRSkeleton::wait_client_online()
				{
					this->wait_for_pub_online(dds_mcu_rpc_handle.writer);

				}

				void CarControlRSkeleton::init(std::string config) {
					std::lock_guard<std::mutex> guard(init_mutex);
					if (this->init_flag) {
						return;
					}
					logconfig_Skeleton::get_instance().init(config);
					DDSUtil::event_pub_init(VIU_DDS_DOMAIN_ID,
						"viu_r_mcu_notify",
						&carControl_Car_Control_Ntf_desc,
						&this->dds_mcu_notify_handle,
					  	NULL, {LOCAL_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "*ntf"},
						config);

					uint8_t  service_id_array[291] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x8,0x0,0x0,0x0,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2};
					DDSUtil::event_sub_init(VIU_DDS_DOMAIN_ID,
						"viu_r_mcu_rpc_service_request",
						&carControl_Car_Control_Request_desc,
					  	&on_carControl_r_request_data_available,
						NULL,
						&this->dds_mcu_rpc_handle,
						&on_CarControlRSkeleton_request_subscription_matched_cb,
						{LOCAL_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "rpc"},
						{291,service_id_array},
						config
					);

					DDSUtil::event_pub_init(VIU_DDS_DOMAIN_ID,
						"viu_r_mcu_rpc_service_reply",
						&carControl_Car_Control_Reply_desc,
						&this->dds_mcu_rpc_handle,
						NULL, {LOCAL_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "rpc"},
					  	config
					);





					this->init_flag = true;
				}

				CarControlRSkeleton& CarControlRSkeleton::get_instance() {
					static CarControlRSkeleton instance;
					return instance;
				}
				int32_t CarControlRSkeleton::send(const void* data) {
					return DDSUtil::send(this->dds_mcu_notify_handle.writer, data);
				}
				int32_t CarControlRSkeleton::send_reply(const void* data) {
					return DDSUtil::send(this->dds_mcu_rpc_handle.writer, data);
				}
				void CarControlRSkeleton::register_consumer_matched_handler(std::string name,EventReceiveHandler<const ConsumerMatchedStatus&> handler){
					if(NULL==handler || name.empty()){
						return;
					}
					consumer_matched_handler_map[name]=handler;
					if(this->init_flag && this->consumer_matched_status.current_count>0){
					  	handler(this->consumer_matched_status);
					}
				}
				std::unordered_map<std::string, EventReceiveHandler<const ConsumerMatchedStatus&>> CarControlRSkeleton::get_registered_consumer_matched_handler(){
					return this->consumer_matched_handler_map;
				}
				void CarControlRSkeleton::set_last_consumer_matched_status(ConsumerMatchedStatus status){
					this->consumer_matched_status=status;
				}
			}
		}
	}
}
