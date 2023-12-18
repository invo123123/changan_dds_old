#pragma once
#include "Dynamic.h"
#include "adapter.h"
#include "global_config.hpp"
#include "dds_client.hpp"
#include<functional>
#include <map>
#include "struct_protobuf_convert.hpp"

using namespace com::changan::rpc_service;

//#define carControl_Car_Control_Cnr_HdLampCtrl_RR_CombHdLampCtrl_Hash 1111

class CRpcClient : public CRpcDynamic<CRpcClient>
{
public:
	static void Init(std::string config="");

	static void Request(int32_t hashId, const void *request, int requestSize, void** reply, size_t &replySize, DDS_RPC_RemoteExceptionCode_t& errorCode, size_t timeOut = DEFAULT_TIMEOUT)
	{

		if(request == nullptr || requestSize == 0){
			// printf("CVIURpcClient::Request request point null hashId: %d \n", hashId);
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}
		
		string skeletonName;
		for (auto it = m_config.skeletons.client.begin(); it != m_config.skeletons.client.end(); it++)
		{
			if (it->second.hash_ids.find(hashId) != it->second.hash_ids.end())
			{
				skeletonName = it->first;
				break;
			}
		}
		auto it = m_config.skeletons.client.find(skeletonName);
		if (it == m_config.skeletons.client.end())
		{
			// printf("CRpcClient::Call m_config.skeletons.find(hash= %d,topic =%s ) failed\n",
			// 	   hashId,skeletonName.c_str()); 
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}

		auto itRp = m_rps.find(skeletonName);
		if (itRp == m_rps.end())
		{
			// printf("CRpcClient::Call m_rps.find %s failed\n",
			// 	   skeletonName.c_str());
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}

		const dds_topic_descriptor_t *pDesc = GetDesc(it->second.request_topic_name);
		if (!pDesc)
		{
			// printf("CRpcClient::Call %s GetDesc(%s) NULL\n", skeletonName.c_str(), it->second.request_topic_name.c_str());
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}

		dds_guid_t _temp_guid = {0};
		if (DDS_RETCODE_OK != dds_get_guid(itRp->second.request.writer, &_temp_guid))
		{
			// printf("CRpcClient::Call %s dds_get_guid fail\n", skeletonName.c_str());
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}

		void *_rpc_request = dds_alloc(pDesc->m_size);
		
		memcpy((uint8_t *)_rpc_request + GetOfs_RpcRequestHeaderRequestId(hashId), &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = DDSClient::get_rpc_request_id();
		memcpy((uint8_t *)_rpc_request + GetOfs_RpcRequestHeaderRequestIdSequenceNumber(hashId), &_rpc_client_sn, sizeof(DDS_SequenceNumber_t));

		void * requestData=(void  *)malloc(get_in_struct_size_of(hashId));

		funtransform itReq =get_transform(hashId); 
		size_t req_size = get_in_struct_size_of(hashId);
		if(itReq.is_found)
		{
			itReq.in_pb2type((const void *)request, requestSize, requestData);
		} else {
			// printf("hashId no FOUND hashId=%d\n", hashId);
			errorCode = DDS_RPC_REMOTE_METHOD_NOT_FOUND;
			dds_sample_free(_rpc_request, pDesc, DDS_FREE_ALL);
			free(requestData);
			return ;
		}

		memcpy((uint8_t *)_rpc_request + GetOfs_RpcRequestData_uUnknownOp(hashId), requestData, req_size);
		free(requestData);
		memcpy((uint8_t *)_rpc_request + GetOfs_RpcRequestData_d(pDesc), &hashId, sizeof(int32_t));

		auto _rpc_future = DDSClient::async_call(_rpc_client_sn.low, itRp->second.request.writer, _rpc_request);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(timeOut));

		dds_sample_free(_rpc_request, pDesc, DDS_FREE_ALL);

		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred)
		{
			errorCode = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return ;
		}
		
		auto sp = _rpc_future.get();
		void *_rpc_ret = sp.get();
		
		memcpy(&errorCode, (uint8_t *)_rpc_ret + GetOfs_RpcReplyHeaderRemoteEx(hashId), sizeof(DDS_RPC_RemoteExceptionCode_t));
		if (errorCode == DDS_RPC_REMOTE_EX_OK)
		{
			// convert_to_pb_state_machine_2((const void *)((uint8_t *)_rpc_ret + GetOfs_RpcReplyData_uUnknownOp()), reply_buf, replySize);
			itReq.out_type2pb((const void *)((uint8_t *)_rpc_ret + GetOfs_RpcReplyData_uUnknownOp(hashId)), reply, &replySize);
			// printf("reply_size=%ld\n", replySize);
		}
		return ;
	}

private:
	static void OnReplyDataAvailable(int32_t reader, void *arg);
	
};

class CRpcServer : public CRpcDynamic<CRpcServer>
{
public:
	static void Init(std::string config="");
	static void Reply(int32_t hashId, HandleRequest hr);

private:
	static void OnRequestDataAvailable(int32_t reader, void *arg);
	static void OnRequest(
		void *request,
		dds_entity_t writer,
		const dds_topic_descriptor_t *requestcDesc,
		const dds_topic_descriptor_t *replyDesc,
		string skeletonName,
		int32_t hashId);
	static void OnRequestDef(
		void *request,
		dds_entity_t writer,
		const dds_topic_descriptor_t *requestcDesc,
		const dds_topic_descriptor_t *replyDesc);

private:
	static map<ServiceInterface, HandleRequest> m_hrs;
};


/********************************************   viu rpc  *****************************************************/



class CVIURpcClient : public CRpcDynamic<CVIURpcClient>
{
public:
	static void Init(std::string config=""); 
	 
	static void Request(int32_t hashId, const void *request, int requestSize, void** reply, size_t &replySize, DDS_RPC_RemoteExceptionCode_t& errorCode, size_t timeOut = DEFAULT_TIMEOUT)
	{
		//printf("CVIURpcClient::Request  hashId:(%d )  \n", hashId);

		if(request == nullptr || requestSize == 0){
			//printf("CVIURpcClient::Request request point null hashId: %d \n", hashId);
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}

		string skeletonName;
		// find seketon name
		for (auto it = m_config.mcu_skeletons.client.viu_mcu.begin(); it != m_config.mcu_skeletons.client.viu_mcu.end(); it++)
		{
			if (it->second.hash_ids.find(hashId) != it->second.hash_ids.end())
			{
				skeletonName = it->first;
				break;
			}
		}

		// find viu_mcu data
		auto it = m_config.mcu_skeletons.client.viu_mcu.find(skeletonName);
		if (it == m_config.mcu_skeletons.client.viu_mcu.end())
		{
			// printf("CVIURpcClient::Call m_config.mcu_skeletons.client.viu_mcu.find( %d )   failed\n",
			// 	   hashId);
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}

		auto itRp = m_rps_viu.find(skeletonName);
		if (itRp == m_rps_viu.end())
		{
			// printf("CRpcClient::Call m_rps.find %s failed\n",
			// 	   skeletonName.c_str());
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}
		const dds_topic_descriptor_t *pDesc = GetDesc(it->second.request_topic_name);
		if (!pDesc)
		{
			// printf("CRpcClient::Call %s GetDesc(%s) NULL\n", skeletonName.c_str(), it->second.request_topic_name.c_str());
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}

		dds_guid_t _temp_guid = {0};
		if (DDS_RETCODE_OK != dds_get_guid(itRp->second.request.writer, &_temp_guid))
		{
			// printf("CRpcClient::Call %s dds_get_guid fail\n", skeletonName.c_str());
			errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return ;
		}
		
		void *_rpc_request = dds_alloc(pDesc->m_size);
	
		memcpy((uint8_t *)_rpc_request + GetOfs_RpcRequestHeaderRequestId(hashId), &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = DDSClient::get_rpc_request_id();
		memcpy((uint8_t *)_rpc_request + GetOfs_RpcRequestHeaderRequestIdSequenceNumber(hashId), &_rpc_client_sn, sizeof(DDS_SequenceNumber_t));

		void * requestData=(void  *)malloc(get_in_struct_size_of(hashId));
		// get data transform function
		funtransform itReq =get_transform(hashId); 
		size_t req_size = get_in_struct_size_of(hashId);
		if(itReq.is_found)
		{
			itReq.in_pb2type((const void *)request, requestSize, requestData);
		} else {
			// problem: sample data not complete but it want to free it with dds_sample_free by pDesc
			errorCode = DDS_RPC_REMOTE_METHOD_NOT_FOUND;
			dds_sample_free(_rpc_request, pDesc, DDS_FREE_ALL);
			free(requestData);
			return ;
		}

		// data._u copy param in struct to sample data
		memcpy((uint8_t *)_rpc_request + GetOfs_RpcRequestData_uUnknownOp(hashId), requestData, req_size);
		free(requestData);
		// data._d copy hash id to sample 
		memcpy((uint8_t *)_rpc_request + GetOfs_RpcRequestData_d(pDesc), &hashId, sizeof(int32_t));

		// async call                 
		auto _rpc_future = DDSClient::async_call(_rpc_client_sn.low, itRp->second.request.writer, _rpc_request);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(timeOut));

		dds_sample_free(_rpc_request, pDesc, DDS_FREE_ALL);

		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred)
		{
			errorCode = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			
			return ;
		}

		auto sp = _rpc_future.get();
		void *_rpc_ret = sp.get();

		memcpy(&errorCode, (uint8_t *)_rpc_ret + GetOfs_RpcReplyHeaderRemoteEx(hashId), sizeof(DDS_RPC_RemoteExceptionCode_t));
		if (errorCode == DDS_RPC_REMOTE_EX_OK)
		{
			itReq.out_type2pb((const void *)((uint8_t *)_rpc_ret + GetOfs_RpcReplyData_uUnknownOp(hashId)), reply, &replySize);
			// printf("reply_size=%ld\n", replySize);
		}
		return ;
	}

private:
	static void OnReplyDataAvailable(int32_t reader, void *arg);
	static bool dds_topic_filter (const void *vsample, void *arg);
	
};

#ifdef viu_rpc_server_enable
class CVIURpcServer : public CRpcDynamic<CVIURpcServer>
{
public:
	static void Init(std::string config="");
	static void Reply(int32_t hashId, HandleRequest hr);

private:
	static void OnRequestDataAvailable(int32_t reader, void *arg);
	static void OnRequest(
		void *request,
		dds_entity_t writer,
		const dds_topic_descriptor_t *requestcDesc,
		const dds_topic_descriptor_t *replyDesc,
		string skeletonName,
		int32_t hashId);
	static void OnRequestDef(
		void *request,
		dds_entity_t writer,
		const dds_topic_descriptor_t *requestcDesc,
		const dds_topic_descriptor_t *replyDesc);

private:
	static map<ServiceInterface, HandleRequest> m_hrs_viu;
};

#endif