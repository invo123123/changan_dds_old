/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： soa_log-V1.1.1
  CmVersion： 1.1.217
  ServiceVersion: V1.1.1
  ServiceLatestModifyTime: 2023-08-21T11:31:03
  Generate Time: Aug 21, 2023 1:50:56 PM
*****************************************************************/
#include "changan/logconfig_P.hpp"
#include <string.h>
#include "dds/ddsrt/sync.h"
#include <iostream>
#include "changan/string_util.hpp"
#include "changan/dds_client.hpp"
char g_service_name[128] = {0};
namespace com {
namespace changan {
namespace soa_log {
namespace proxy {
    using namespace com::changan::rpc_service;
	void on_carDrive_logconfig_reply_data_available(int32_t reader, void* arg) {
		dds_return_t rc;
		carDrive_logconfig_Reply* reply;
		void* samples[MAX_SAMPLES];
		dds_sample_info_t infos[MAX_SAMPLES];
		samples[0] = carDrive_logconfig_Reply__alloc();
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0) {
			ASF_LOG_ERROR_ARGS("dds_take_next failed!");
		}
		if (infos[0].valid_data) {
			reply = (carDrive_logconfig_Reply*)samples[0];
			auto sp = std::shared_ptr<void>{
				samples[0],
				[](void* ptr) {
					carDrive_logconfig_Reply_free(ptr,DDS_FREE_ALL);
				}
			};
			int32_t funID = reply->data._d;
			switch (funID) {
				case carDrive_logconfig_SETSOALOG_Hash:
				{
					uint64_t key = reply->header.relatedRequestId.sequence_number.low;
					com::changan::rpc_service::DDSClient::release(key, sp);
					break;
				}
				default:
				{
					uint64_t key = reply->header.relatedRequestId.sequence_number.low;
					com::changan::rpc_service::DDSClient::release(key, sp);
					break;
				}
			}
		}
	}

	logconfig_Proxy::logconfig_Proxy(){

    }

    void on_logconfig_request_publication_matched_cb(dds_entity_t writer, const dds_publication_matched_status_t  status, void* arg) {
		auto handler=logconfig_Proxy::get_instance().get_provider_matched_handler();
		if(NULL!=handler){
			ProviderMatchedStatus data=DDSUtil::get_provider_matched_status(writer,status);
			handler(data);
		}
	}

	void logconfig_Proxy::wait_server_online()
	{
		this->wait_for_sub_online(dds_rpc_reply_handle.reader);
	}

	bool logconfig_Proxy::init(std::string config) {
	    std::lock_guard<std::mutex> guard(init_mutex);
	    if(this->init_flag){
	        return true;
	    }
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			//this->service_name + "_reply",
			string(g_service_name) + "_reply",
			&carDrive_logconfig_Reply_desc,
			&on_carDrive_logconfig_reply_data_available,
			NULL,
			&dds_rpc_reply_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config
		);

		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			//this->service_name + "_request",
			string(g_service_name) + "_request",
			&carDrive_logconfig_Request_desc,
			&dds_rpc_request_handle,
            &on_logconfig_request_publication_matched_cb,{PROXY_TOKEN, PROXY_TOKEN, ""},config
		);
		this->init_flag = true;
		return true;
	}

	bool logconfig_Proxy::destroy() {
		std::lock_guard<std::mutex> guard(init_mutex);
	    if (!this->init_flag) {
			return true;
		}
		if (!DDSUtil::dds_client_destroy(&dds_rpc_reply_handle)) {
			return false;
		}
		if (!DDSUtil::dds_client_destroy(&dds_rpc_request_handle)) {
			return false;
		}
		this->init_flag = false;
		return true;
	}

	Msg<std::string> logconfig_Proxy::SETSOALOG(const std::string &logLevel,const std::string &logDir, size_t dds_rpc_time_out) {
		Msg<std::string> _rpc_result;
		carDrive_logconfig_Request* _rpc_request = carDrive_logconfig_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		if (DDS_RETCODE_OK != dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid))
		{
			ASF_LOG_ERROR_ARGS("_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED");
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		StringUtil::string_copy(_rpc_request->data._u.SETSOALOG.logLevel, logLevel.data());
		StringUtil::string_copy(_rpc_request->data._u.SETSOALOG.logDir, logDir.data());

		_rpc_request->data._d = carDrive_logconfig_SETSOALOG_Hash;
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_logconfig_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_logconfig_Reply*)sp.get();
		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.SETSOALOG.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
    logconfig_Proxy::~logconfig_Proxy(){

    }

	logconfig_Proxy& logconfig_Proxy::get_instance()
	{
		static logconfig_Proxy instance;
		return instance;
	}
}
}
}
}

