/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V2.0
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-24T11:53:32
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "changan/Sys_TurnLiHzrdSwt_Proxy.hpp"
#include <string.h>
#include "dds/ddsrt/sync.h"
#include <iostream>
#include "changan/Car_Control_fl_Proxy_gw.hpp"

#include "changan/Car_Control.h"
#include "changan/string_util.hpp"
namespace com {
namespace changan {
namespace carControl {
namespace ExteriorLight {
namespace proxy {
	using CarControlFLProxyGw = com::changan::carControl::proxy::CarControlFLProxyGw;

	Sys_TurnLiHzrdSwt_Proxy::Sys_TurnLiHzrdSwt_Proxy(){

    }

	bool Sys_TurnLiHzrdSwt_Proxy::init(std::string config) {
	    std::lock_guard<std::mutex> guard(init_mutex);
		if (this->init_flag) {
			return true;
		}

		CarControlFLProxyGw::get_instance().register_topicdata_checkable_handler(this->get_service_id(), this->get_provider_matched_handler());
		CarControlFLProxyGw::get_instance().register_provider_matched_handler(this->get_service_name(),this->get_service_id(),this->get_provider_matched_handler());
		CarControlFLProxyGw::get_instance().init(config);

		this->init_flag = true;
		return true;
	}

	void Sys_TurnLiHzrdSwt_Proxy::wait_server_online()
	{
		CarControlFLProxyGw::get_instance().wait_server_online();
	}
	Msg<OperationInfo> Sys_TurnLiHzrdSwt_Proxy::Get_SrvOperInfo( size_t dds_rpc_time_out) {
		Msg<OperationInfo> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Sys_TurnLiHzrdSwt_Proxy::Get_SrvOperInfo dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Sys_TurnLiHzrdSwt_Get_SrvOperInfo_Hash;
		ASF_LOG_DEBUG_ARGS("Sys_TurnLiHzrdSwt_Proxy::Get_SrvOperInfo pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Sys_TurnLiHzrdSwt_Get_SrvOperInfo_Hash, _rpc_client_sn.low);
		auto _rpc_future = CarControlFLProxyGw::get_instance().call(_rpc_client_sn.low, _rpc_request);
		carControl_Car_Control_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carControl_Car_Control_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.Sys_TurnLiHzrdSwt_Get_SrvOperInfo.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<ClusterTurnLiSt> Sys_TurnLiHzrdSwt_Proxy::Get_ClusterTurnLiSt( size_t dds_rpc_time_out) {
		Msg<ClusterTurnLiSt> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Sys_TurnLiHzrdSwt_Proxy::Get_ClusterTurnLiSt dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Sys_TurnLiHzrdSwt_Get_ClusterTurnLiSt_Hash;
		ASF_LOG_DEBUG_ARGS("Sys_TurnLiHzrdSwt_Proxy::Get_ClusterTurnLiSt pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Sys_TurnLiHzrdSwt_Get_ClusterTurnLiSt_Hash, _rpc_client_sn.low);
		auto _rpc_future = CarControlFLProxyGw::get_instance().call(_rpc_client_sn.low, _rpc_request);
		carControl_Car_Control_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carControl_Car_Control_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.Sys_TurnLiHzrdSwt_Get_ClusterTurnLiSt.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
    Sys_TurnLiHzrdSwt_Proxy::~Sys_TurnLiHzrdSwt_Proxy(){

    }

	Sys_TurnLiHzrdSwt_Proxy& Sys_TurnLiHzrdSwt_Proxy::get_instance()
	{
		static Sys_TurnLiHzrdSwt_Proxy instance;
		return instance;
	}

	bool Sys_TurnLiHzrdSwt_Proxy::is_init(){
		return this->init_flag;
	}
}
}
}
}
}

