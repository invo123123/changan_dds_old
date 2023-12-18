/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V2.1
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-05-30T17:34:20
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "changan/Basc_PhysicsStDoor_Proxy.hpp"
#include <string.h>
#include "dds/ddsrt/sync.h"
#include <iostream>
#include "changan/Car_Control_fl_Proxy_gw.hpp"

#include "changan/Car_Control.h"
#include "changan/string_util.hpp"
namespace com {
namespace changan {
namespace carControl {
namespace Door {
namespace proxy {
	using CarControlFLProxyGw = com::changan::carControl::proxy::CarControlFLProxyGw;

	Basc_PhysicsStDoor_Proxy::Basc_PhysicsStDoor_Proxy(){

    }

	bool Basc_PhysicsStDoor_Proxy::init(std::string config) {
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

	void Basc_PhysicsStDoor_Proxy::wait_server_online()
	{
		CarControlFLProxyGw::get_instance().wait_server_online();
	}
	Msg<ObjStTypeDoorAll_Struct> Basc_PhysicsStDoor_Proxy::Get_PhyStAll( size_t dds_rpc_time_out) {
		Msg<ObjStTypeDoorAll_Struct> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_PhysicsStDoor_Proxy::Get_PhyStAll dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_PhysicsStDoor_Get_PhyStAll_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_PhysicsStDoor_Proxy::Get_PhyStAll pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_PhysicsStDoor_Get_PhyStAll_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_PhysicsStDoor_Get_PhyStAll.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<ObjStTypeCurPosVITAll_Struct> Basc_PhysicsStDoor_Proxy::Get_PosAll( size_t dds_rpc_time_out) {
		Msg<ObjStTypeCurPosVITAll_Struct> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_PhysicsStDoor_Proxy::Get_PosAll dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_PhysicsStDoor_Get_PosAll_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_PhysicsStDoor_Proxy::Get_PosAll pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_PhysicsStDoor_Get_PosAll_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_PhysicsStDoor_Get_PosAll.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<DoorDrvStAll_Struct> Basc_PhysicsStDoor_Proxy::Get_DoorStAll( size_t dds_rpc_time_out) {
		Msg<DoorDrvStAll_Struct> _rpc_result;

		carControl_Car_Control_Request* _rpc_request = carControl_Car_Control_Request__alloc();

		dds_guid_t _temp_guid = { 0 };

		dds_return_t rc = dds_get_guid(CarControlFLProxyGw::get_instance().get_rpc_handle().writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_PhysicsStDoor_Proxy::Get_DoorStAll dds_get_guid faild rc=[%d]", rc);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carControl_Car_Control_Basc_PhysicsStDoor_Get_DoorStAll_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_PhysicsStDoor_Proxy::Get_DoorStAll pre call, hashId=[%d], reqId=[%d]", carControl_Car_Control_Basc_PhysicsStDoor_Get_DoorStAll_Hash, _rpc_client_sn.low);
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
			_rpc_result.data = _rpc_ret->data._u.Basc_PhysicsStDoor_Get_DoorStAll.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
    Basc_PhysicsStDoor_Proxy::~Basc_PhysicsStDoor_Proxy(){

    }

	Basc_PhysicsStDoor_Proxy& Basc_PhysicsStDoor_Proxy::get_instance()
	{
		static Basc_PhysicsStDoor_Proxy instance;
		return instance;
	}

	bool Basc_PhysicsStDoor_Proxy::is_init(){
		return this->init_flag;
	}
}
}
}
}
}

