/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V1.1
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-24T12:03:34
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "changan/Sys_LoChrgfun_Proxy.hpp"
#include <string.h>
#include "dds/ddsrt/sync.h"
#include <iostream>
#include "changan/Car_Control_fl_Proxy_gw.hpp"

#include "changan/Car_Control.h"
#include "changan/string_util.hpp"
namespace com {
namespace changan {
namespace carControl {
namespace PDU {
namespace proxy {
	using CarControlFLProxyGw = com::changan::carControl::proxy::CarControlFLProxyGw;

	Sys_LoChrgfun_Proxy::Sys_LoChrgfun_Proxy(){

    }

	bool Sys_LoChrgfun_Proxy::init(std::string config) {
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

	void Sys_LoChrgfun_Proxy::wait_server_online()
	{
		CarControlFLProxyGw::get_instance().wait_server_online();
	}
	Msg<ResponseInfo> Sys_LoChrgfun_Proxy::RR_LoChrgfuncSet(const uint8_t &LoUMode,const RequestInfo &RequestInfo_, size_t dds_rpc_time_out) {
		Msg<ResponseInfo> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Sys_LoChrgfun_Proxy::RR_LoChrgfuncSet dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.Sys_LoChrgfun_RR_LoChrgfuncSet.LoUMode = LoUMode;
		_rpc_request->data._u.Sys_LoChrgfun_RR_LoChrgfuncSet.RequestInfo = RequestInfo_;

		_rpc_request->data._d = carControl_Car_Control_Sys_LoChrgfun_RR_LoChrgfuncSet_Hash;
		ASF_LOG_DEBUG_ARGS("Sys_LoChrgfun_Proxy::RR_LoChrgfuncSet pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Sys_LoChrgfun_RR_LoChrgfuncSet_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Sys_LoChrgfun_RR_LoChrgfuncSet.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Sys_LoChrgfun_Proxy::Get_LoChrgfuncsts( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Sys_LoChrgfun_Proxy::Get_LoChrgfuncsts dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Sys_LoChrgfun_Get_LoChrgfuncsts_Hash;
		ASF_LOG_DEBUG_ARGS("Sys_LoChrgfun_Proxy::Get_LoChrgfuncsts pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Sys_LoChrgfun_Get_LoChrgfuncsts_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Sys_LoChrgfun_Get_LoChrgfuncsts.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<OperationInfo> Sys_LoChrgfun_Proxy::Get_SrvOperInfo( size_t dds_rpc_time_out) {
		Msg<OperationInfo> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Sys_LoChrgfun_Proxy::Get_SrvOperInfo dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Sys_LoChrgfun_Get_SrvOperInfo_Hash;
		ASF_LOG_DEBUG_ARGS("Sys_LoChrgfun_Proxy::Get_SrvOperInfo pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Sys_LoChrgfun_Get_SrvOperInfo_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Sys_LoChrgfun_Get_SrvOperInfo.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
    Sys_LoChrgfun_Proxy::~Sys_LoChrgfun_Proxy(){

    }

	Sys_LoChrgfun_Proxy& Sys_LoChrgfun_Proxy::get_instance()
	{
		static Sys_LoChrgfun_Proxy instance;
		return instance;
	}

	bool Sys_LoChrgfun_Proxy::is_init(){
		return this->init_flag;
	}
}
}
}
}
}
