/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V1.2
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-07-25T13:37:03
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "changan/Basc_LiSnsrInfo_Proxy.hpp"
#include <string.h>
#include "dds/ddsrt/sync.h"
#include <iostream>
#include "changan/Car_Control_fl_Proxy_gw.hpp"

#include "changan/Car_Control.h"
#include "changan/string_util.hpp"
namespace com {
namespace changan {
namespace carControl {
namespace S2S {
namespace proxy {
	using CarControlFLProxyGw = com::changan::carControl::proxy::CarControlFLProxyGw;

	Basc_LiSnsrInfo_Proxy::Basc_LiSnsrInfo_Proxy(){

    }

	bool Basc_LiSnsrInfo_Proxy::init(std::string config) {
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

	void Basc_LiSnsrInfo_Proxy::wait_server_online()
	{
		CarControlFLProxyGw::get_instance().wait_server_online();
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::RR_LiSnsrThd(const uint8_t &LiSnsrThd, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::RR_LiSnsrThd dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.Basc_LiSnsrInfo_RR_LiSnsrThd.LiSnsrThd = LiSnsrThd;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_RR_LiSnsrThd_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::RR_LiSnsrThd pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_RR_LiSnsrThd_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_RR_LiSnsrThd.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::Get_SolarLe( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_SolarLe dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_SolarLe_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_SolarLe pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_SolarLe_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_SolarLe.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::Get_SolarRi( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_SolarRi dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_SolarRi_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_SolarRi pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_SolarRi_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_SolarRi.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::Get_LiSnsrMod( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_LiSnsrMod dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_LiSnsrMod_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_LiSnsrMod pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_LiSnsrMod_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_LiSnsrMod.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::Get_LiSnsrLoBeamReq( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_LiSnsrLoBeamReq dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_LiSnsrLoBeamReq_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_LiSnsrLoBeamReq pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_LiSnsrLoBeamReq_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_LiSnsrLoBeamReq.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::Get_LiSnsrRunSt( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_LiSnsrRunSt dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_LiSnsrRunSt_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_LiSnsrRunSt pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_LiSnsrRunSt_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_LiSnsrRunSt.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::Get_LiSnsrErrSt( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_LiSnsrErrSt dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_LiSnsrErrSt_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_LiSnsrErrSt pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_LiSnsrErrSt_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_LiSnsrErrSt.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::Get_IRBri( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_IRBri dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_IRBri_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_IRBri pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_IRBri_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_IRBri.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint16_t> Basc_LiSnsrInfo_Proxy::Get_FWBri( size_t dds_rpc_time_out) {
		Msg<uint16_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_FWBri dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_FWBri_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_FWBri pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_FWBri_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_FWBri.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint16_t> Basc_LiSnsrInfo_Proxy::Get_AMBBri( size_t dds_rpc_time_out) {
		Msg<uint16_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_AMBBri dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_AMBBri_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_AMBBri pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_AMBBri_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_AMBBri.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint16_t> Basc_LiSnsrInfo_Proxy::Get_HUDBri( size_t dds_rpc_time_out) {
		Msg<uint16_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_HUDBri dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_HUDBri_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_HUDBri pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_HUDBri_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_HUDBri.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_LiSnsrInfo_Proxy::Get_LostComFltSt( size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_LiSnsrInfo_Proxy::Get_LostComFltSt dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_LiSnsrInfo_Get_LostComFltSt_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_LiSnsrInfo_Proxy::Get_LostComFltSt pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_LiSnsrInfo_Get_LostComFltSt_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_LiSnsrInfo_Get_LostComFltSt.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
    Basc_LiSnsrInfo_Proxy::~Basc_LiSnsrInfo_Proxy(){

    }

	Basc_LiSnsrInfo_Proxy& Basc_LiSnsrInfo_Proxy::get_instance()
	{
		static Basc_LiSnsrInfo_Proxy instance;
		return instance;
	}

	bool Basc_LiSnsrInfo_Proxy::is_init(){
		return this->init_flag;
	}
}
}
}
}
}

