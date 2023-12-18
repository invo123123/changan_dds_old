/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V1.4
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-02-06T15:22:04
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "changan/Basc_EleAirSuspModSet_Proxy.hpp"
#include <string.h>
#include "dds/ddsrt/sync.h"
#include <iostream>
#include "changan/Car_Control_r_Proxy_gw.hpp"

#include "changan/Car_Control.h"
#include "changan/string_util.hpp"
namespace com {
namespace changan {
namespace carControl {
namespace CHS_SUSP {
namespace proxy {
	using CarControlRProxyGw = com::changan::carControl::proxy::CarControlRProxyGw;

	Basc_EleAirSuspModSet_Proxy::Basc_EleAirSuspModSet_Proxy(){

    }

	bool Basc_EleAirSuspModSet_Proxy::init(std::string config) {
	    std::lock_guard<std::mutex> guard(init_mutex);
		if (this->init_flag) {
			return true;
		}

		CarControlRProxyGw::get_instance().register_topicdata_checkable_handler(this->get_service_id(), this->get_provider_matched_handler());
		CarControlRProxyGw::get_instance().register_provider_matched_handler(this->get_service_name(),this->get_service_id(),this->get_provider_matched_handler());
		CarControlRProxyGw::get_instance().init(config);

		this->init_flag = true;
		return true;
	}

	void Basc_EleAirSuspModSet_Proxy::wait_server_online()
	{
		CarControlRProxyGw::get_instance().wait_server_online();
	}
	Msg<uint8_t> Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspHighModSet( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlRProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspHighModSet dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspHighModSet pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet_Hash, _rpc_client_sn.low);
		auto _rpc_future = CarControlRProxyGw::get_instance().call(_rpc_client_sn.low, _rpc_request);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_EleAirSuspModSet_Get_EleAirSuspHighModSet.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspIntenModSet( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlRProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspIntenModSet dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspIntenModSet pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet_Hash, _rpc_client_sn.low);
		auto _rpc_future = CarControlRProxyGw::get_instance().call(_rpc_client_sn.low, _rpc_request);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_EleAirSuspModSet_Get_EleAirSuspIntenModSet.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspHighModSet(const uint8_t &EleAirSuspHighModSet, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlRProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspHighModSet dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet.EleAirSuspHighModSet = EleAirSuspHighModSet;

		_rpc_request->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspHighModSet pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet_Hash, _rpc_client_sn.low);
		auto _rpc_future = CarControlRProxyGw::get_instance().call(_rpc_client_sn.low, _rpc_request);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspHighModSet.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspIntenModSet(const uint8_t &EleAirSuspIntenModSet, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlRProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspIntenModSet dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet.EleAirSuspIntenModSet = EleAirSuspIntenModSet;

		_rpc_request->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspIntenModSet pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet_Hash, _rpc_client_sn.low);
		auto _rpc_future = CarControlRProxyGw::get_instance().call(_rpc_client_sn.low, _rpc_request);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspIntenModSet.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspAutoModSet( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlRProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspAutoModSet dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_EleAirSuspModSet_Proxy::Get_EleAirSuspAutoModSet pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet_Hash, _rpc_client_sn.low);
		auto _rpc_future = CarControlRProxyGw::get_instance().call(_rpc_client_sn.low, _rpc_request);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_EleAirSuspModSet_Get_EleAirSuspAutoModSet.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspAutoModSet(const uint8_t &EleAirSuspAutoModSet, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlRProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspAutoModSet dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet.EleAirSuspAutoModSet = EleAirSuspAutoModSet;

		_rpc_request->data._d = carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_EleAirSuspModSet_Proxy::Set_EleAirSuspAutoModSet pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet_Hash, _rpc_client_sn.low);
		auto _rpc_future = CarControlRProxyGw::get_instance().call(_rpc_client_sn.low, _rpc_request);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_EleAirSuspModSet_Set_EleAirSuspAutoModSet.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
    Basc_EleAirSuspModSet_Proxy::~Basc_EleAirSuspModSet_Proxy(){

    }

	Basc_EleAirSuspModSet_Proxy& Basc_EleAirSuspModSet_Proxy::get_instance()
	{
		static Basc_EleAirSuspModSet_Proxy instance;
		return instance;
	}

	bool Basc_EleAirSuspModSet_Proxy::is_init(){
		return this->init_flag;
	}
}
}
}
}
}

