/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.3
  ServiceLatestModifyTime: 2023-08-22T19:12:49
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#include "changan/Basc_FileTransmitServer_Proxy.hpp"
#include <string.h>
#include "dds/ddsrt/sync.h"
#include <iostream>
#include "changan/string_util.hpp"
#include "changan/dds_client.hpp"
namespace com {
namespace changan {
namespace carDrive {
namespace C2Controller {
namespace proxy {
    using namespace com::changan::rpc_service;
    using namespace com::changan::soa_log::skeleton;
    void Basc_FileTransmitServer_Ntf_FileTransmit_trigger(carDrive_Basc_FileTransmitServer_Ntf* notify_data){
	    Basc_FileTransmitServer_Proxy::get_instance().Ntf_FileTransmit.trigger(notify_data->data._u.Basc_FileTransmitServer_Ntf_FileTransmit);
		carDrive_Basc_FileTransmitServer_Ntf_free(notify_data, DDS_FREE_ALL);
    }
    void on_Basc_FileTransmitServer_Ntf_FileTransmit_data_available(int32_t reader, void* arg){
        ASF_LOG_DEBUG_ARGS("on_Basc_FileTransmitServer_Ntf_FileTransmit_data_available");
    	dds_return_t rc;
		carDrive_Basc_FileTransmitServer_Ntf* data;
		void* samples[1];
		samples[0] = carDrive_Basc_FileTransmitServer_Ntf__alloc();
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0){
			ASF_LOG_ERROR_ARGS("on_Basc_FileTransmitServer_Ntf_FileTransmit_data_available dds_take_next faild rc=[%d]", rc);
			//printf("dds_take_next failed!\n");
        }
		if (infos[0].valid_data){
            data = (carDrive_Basc_FileTransmitServer_Ntf*)samples[0];
            ASF_LOG_DEBUG_ARGS("on_Basc_FileTransmitServer_Ntf_FileTransmit_data_available, hashId=[%d]", data->data._d);
			DDSClient::execute(Basc_FileTransmitServer_Ntf_FileTransmit_trigger,data);
			return;
		}
		carDrive_Basc_FileTransmitServer_Ntf_free(samples[0],DDS_FREE_ALL);
	}
	void on_carDrive_Basc_FileTransmitServer_reply_data_available(int32_t reader, void* arg) {
		ASF_LOG_DEBUG_ARGS("on_carDrive_Basc_FileTransmitServer_reply_data_available");
		dds_return_t rc;
		carDrive_Basc_FileTransmitServer_Reply* reply;
		void* samples[MAX_SAMPLES];
		dds_sample_info_t infos[MAX_SAMPLES];
		samples[0] = carDrive_Basc_FileTransmitServer_Reply__alloc();
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0) {
			ASF_LOG_ERROR_ARGS("on_carDrive_Basc_FileTransmitServer_reply_data_available dds_take_next faild rc=[%d]", rc);
			//printf("dds_take_next failed!\n");
		}
		if (infos[0].valid_data) {
			reply = (carDrive_Basc_FileTransmitServer_Reply*)samples[0];
			auto sp = std::shared_ptr<void>{
				samples[0],
				[](void* ptr) {
					carDrive_Basc_FileTransmitServer_Reply_free(ptr,DDS_FREE_ALL);
				}
			};
			int32_t funID = reply->data._d;
			ASF_LOG_DEBUG_ARGS("on_carDrive_Basc_FileTransmitServer_reply_data_available, hashId=[%d], reqId=[%d]", funID, reply->header.relatedRequestId.sequence_number.low);
			switch (funID) {
				case carDrive_Basc_FileTransmitServer_RR_FileReq_Hash:
				case carDrive_Basc_FileTransmitServer_RR_ReceivedFile_Hash:
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

	Basc_FileTransmitServer_Proxy::Basc_FileTransmitServer_Proxy(){

    }

    void on_Basc_FileTransmitServer_request_publication_matched_cb(dds_entity_t writer, const dds_publication_matched_status_t  status, void* arg) {
		ASF_LOG_DEBUG_ARGS("on_Basc_FileTransmitServer_request_publication_matched_cb, writer=[%d], current_count=[%d]", writer, status.current_count);
		Basc_FileTransmitServer_Proxy *pTmp = &Basc_FileTransmitServer_Proxy::get_instance();
		auto handler=Basc_FileTransmitServer_Proxy::get_instance().get_provider_matched_handler();
		if(NULL!=handler){
			ProviderMatchedStatus data=DDSUtil::get_provider_matched_status(writer,status);
			if(data.is_online == true)
            {
                pTmp->add_link_count();
            }
			else
            {
                pTmp->subtract_link_count();
            }
            if(pTmp->get_link_count() < 2)
            {
               data.is_online = false;
            }
            handler(data);
		}
	}
	
	void on_Basc_FileTransmitServer_reply_sublication_matched_cb(dds_entity_t reader, const dds_subscription_matched_status_t  status, void* arg) {
		ASF_LOG_DEBUG_ARGS("on_Basc_FileTransmitServer_reply_sublication_matched_cb, reader=[%d], current_count=[%d]", reader, status.current_count);
		Basc_FileTransmitServer_Proxy *pTmp = &Basc_FileTransmitServer_Proxy::get_instance();
        auto handler = pTmp->get_provider_matched_handler();
        if(NULL!=handler){
            ConsumerMatchedStatus ConsumerData=DDSUtil::get_consumer_matched_status(reader,status);
            ProviderMatchedStatus ProviderData;
			ProviderData.is_online = false;
            if(ConsumerData.is_online == true)
            {
                pTmp->add_link_count();
            }
            else
            {
                pTmp->subtract_link_count();
            }
            
            if(pTmp->get_link_count() == 2)
            {
                ProviderData.is_online = true;
            }
            handler(ProviderData);
        }
    }


	void Basc_FileTransmitServer_Proxy::wait_server_online()
	{
		this->wait_for_sub_online(dds_rpc_reply_handle.reader);
	}

	bool Basc_FileTransmitServer_Proxy::init(std::string config) {
	    std::lock_guard<std::mutex> guard(init_mutex);
	    if(this->init_flag){
	        return true;
	    }
		logconfig_Skeleton::get_instance().init(config);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->get_service_name()+"_"+this->Ntf_FileTransmit.get_name(),
		    &carDrive_Basc_FileTransmitServer_Ntf_desc,
			&on_Basc_FileTransmitServer_Ntf_FileTransmit_data_available,
			NULL,
			&dds_Ntf_FileTransmit_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->service_name + "_reply",
			&carDrive_Basc_FileTransmitServer_Reply_desc,
			&on_carDrive_Basc_FileTransmitServer_reply_data_available,
			NULL,
			&dds_rpc_reply_handle,
			&on_Basc_FileTransmitServer_reply_sublication_matched_cb,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config
		);
		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			this->service_name + "_request",
			&carDrive_Basc_FileTransmitServer_Request_desc,
			&dds_rpc_request_handle,
            &on_Basc_FileTransmitServer_request_publication_matched_cb,{PROXY_TOKEN, PROXY_TOKEN, ""},config
		);

		this->init_flag = true;
		return true;
	}

	bool Basc_FileTransmitServer_Proxy::destroy() {
		ASF_LOG_DEBUG_ARGS("Basc_FileTransmitServer_Proxy::destroy");
		std::lock_guard<std::mutex> guard(init_mutex);
	    if (!this->init_flag) {
			return true;
		}
		if (!DDSUtil::dds_client_destroy(&dds_Ntf_FileTransmit_handle)) {
			return false;
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

	Msg<FileEntity> Basc_FileTransmitServer_Proxy::RR_FileReq(const uint32_t &fileType, size_t dds_rpc_time_out) {
		Msg<FileEntity> _rpc_result;
		carDrive_Basc_FileTransmitServer_Request* _rpc_request = carDrive_Basc_FileTransmitServer_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_FileTransmitServer_Proxy::RR_FileReq dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_FileReq.fileType = fileType;

		_rpc_request->data._d = carDrive_Basc_FileTransmitServer_RR_FileReq_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_FileTransmitServer_Proxy::RR_FileReq pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_FileTransmitServer_RR_FileReq_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_FileTransmitServer_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_FileTransmitServer_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_FileReq.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_FileTransmitServer_Proxy::RR_ReceivedFile(const uint32_t &fileId,const uint8_t &received, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;
		carDrive_Basc_FileTransmitServer_Request* _rpc_request = carDrive_Basc_FileTransmitServer_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_FileTransmitServer_Proxy::RR_ReceivedFile dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_ReceivedFile.fileId = fileId;
		_rpc_request->data._u.RR_ReceivedFile.received = received;

		_rpc_request->data._d = carDrive_Basc_FileTransmitServer_RR_ReceivedFile_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_FileTransmitServer_Proxy::RR_ReceivedFile pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_FileTransmitServer_RR_ReceivedFile_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_FileTransmitServer_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_FileTransmitServer_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_ReceivedFile.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
    Basc_FileTransmitServer_Proxy::~Basc_FileTransmitServer_Proxy(){

    }

	Basc_FileTransmitServer_Proxy& Basc_FileTransmitServer_Proxy::get_instance()
	{
		static Basc_FileTransmitServer_Proxy instance;
		return instance;
	}
}
}
}
}
}

