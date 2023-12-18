/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.0.5
  ServiceLatestModifyTime: 2023-11-21T15:20:28
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#include "changan/Basc_APAInteract_Proxy.hpp"
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
    void Basc_APAInteract_Ntf_AD_APACustSlot_trigger(carDrive_Basc_APAInteract_Ntf* notify_data){
	    Basc_APAInteract_Proxy::get_instance().Ntf_AD_APACustSlot.trigger(notify_data->data._u.Basc_APAInteract_Ntf_AD_APACustSlot);
		carDrive_Basc_APAInteract_Ntf_free(notify_data, DDS_FREE_ALL);
    }
    void Basc_APAInteract_Ntf_AD_APADynguidance_trigger(carDrive_Basc_APAInteract_Ntf* notify_data){
	    Basc_APAInteract_Proxy::get_instance().Ntf_AD_APADynguidance.trigger(notify_data->data._u.Basc_APAInteract_Ntf_AD_APADynguidance);
		carDrive_Basc_APAInteract_Ntf_free(notify_data, DDS_FREE_ALL);
    }
    void Basc_APAInteract_Ntf_AD_APADynrecommd_trigger(carDrive_Basc_APAInteract_Ntf* notify_data){
	    Basc_APAInteract_Proxy::get_instance().Ntf_AD_APADynrecommd.trigger(notify_data->data._u.Basc_APAInteract_Ntf_AD_APADynrecommd);
		carDrive_Basc_APAInteract_Ntf_free(notify_data, DDS_FREE_ALL);
    }
    void Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_trigger(carDrive_Basc_APAInteract_Ntf* notify_data){
	    Basc_APAInteract_Proxy::get_instance().Ntf_AD_APAFctnIndnMsg.trigger(notify_data->data._u.Basc_APAInteract_Ntf_AD_APAFctnIndnMsg);
		carDrive_Basc_APAInteract_Ntf_free(notify_data, DDS_FREE_ALL);
    }
    void on_Basc_APAInteract_Ntf_AD_APACustSlot_data_available(int32_t reader, void* arg){
        ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_Ntf_AD_APACustSlot_data_available");
    	dds_return_t rc;
		carDrive_Basc_APAInteract_Ntf* data;
		void* samples[1];
		samples[0] = carDrive_Basc_APAInteract_Ntf__alloc();
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0){
			ASF_LOG_ERROR_ARGS("on_Basc_APAInteract_Ntf_AD_APACustSlot_data_available dds_take_next faild rc=[%d]", rc);
			//printf("dds_take_next failed!\n");
        }
		if (infos[0].valid_data){
            data = (carDrive_Basc_APAInteract_Ntf*)samples[0];
            ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_Ntf_AD_APACustSlot_data_available, hashId=[%d]", data->data._d);
			DDSClient::execute(Basc_APAInteract_Ntf_AD_APACustSlot_trigger,data);
			return;
		}
		carDrive_Basc_APAInteract_Ntf_free(samples[0],DDS_FREE_ALL);
	}
    void on_Basc_APAInteract_Ntf_AD_APADynguidance_data_available(int32_t reader, void* arg){
        ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_Ntf_AD_APADynguidance_data_available");
    	dds_return_t rc;
		carDrive_Basc_APAInteract_Ntf* data;
		void* samples[1];
		samples[0] = carDrive_Basc_APAInteract_Ntf__alloc();
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0){
			ASF_LOG_ERROR_ARGS("on_Basc_APAInteract_Ntf_AD_APADynguidance_data_available dds_take_next faild rc=[%d]", rc);
			//printf("dds_take_next failed!\n");
        }
		if (infos[0].valid_data){
            data = (carDrive_Basc_APAInteract_Ntf*)samples[0];
            ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_Ntf_AD_APADynguidance_data_available, hashId=[%d]", data->data._d);
			DDSClient::execute(Basc_APAInteract_Ntf_AD_APADynguidance_trigger,data);
			return;
		}
		carDrive_Basc_APAInteract_Ntf_free(samples[0],DDS_FREE_ALL);
	}
    void on_Basc_APAInteract_Ntf_AD_APADynrecommd_data_available(int32_t reader, void* arg){
        ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_Ntf_AD_APADynrecommd_data_available");
    	dds_return_t rc;
		carDrive_Basc_APAInteract_Ntf* data;
		void* samples[1];
		samples[0] = carDrive_Basc_APAInteract_Ntf__alloc();
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0){
			ASF_LOG_ERROR_ARGS("on_Basc_APAInteract_Ntf_AD_APADynrecommd_data_available dds_take_next faild rc=[%d]", rc);
			//printf("dds_take_next failed!\n");
        }
		if (infos[0].valid_data){
            data = (carDrive_Basc_APAInteract_Ntf*)samples[0];
            ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_Ntf_AD_APADynrecommd_data_available, hashId=[%d]", data->data._d);
			DDSClient::execute(Basc_APAInteract_Ntf_AD_APADynrecommd_trigger,data);
			return;
		}
		carDrive_Basc_APAInteract_Ntf_free(samples[0],DDS_FREE_ALL);
	}
    void on_Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_data_available(int32_t reader, void* arg){
        ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_data_available");
    	dds_return_t rc;
		carDrive_Basc_APAInteract_Ntf* data;
		void* samples[1];
		samples[0] = carDrive_Basc_APAInteract_Ntf__alloc();
		dds_sample_info_t infos[1];
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0){
			ASF_LOG_ERROR_ARGS("on_Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_data_available dds_take_next faild rc=[%d]", rc);
			//printf("dds_take_next failed!\n");
        }
		if (infos[0].valid_data){
            data = (carDrive_Basc_APAInteract_Ntf*)samples[0];
            ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_data_available, hashId=[%d]", data->data._d);
			DDSClient::execute(Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_trigger,data);
			return;
		}
		carDrive_Basc_APAInteract_Ntf_free(samples[0],DDS_FREE_ALL);
	}
	void on_carDrive_Basc_APAInteract_reply_data_available(int32_t reader, void* arg) {
		ASF_LOG_DEBUG_ARGS("on_carDrive_Basc_APAInteract_reply_data_available");
		dds_return_t rc;
		carDrive_Basc_APAInteract_Reply* reply;
		void* samples[MAX_SAMPLES];
		dds_sample_info_t infos[MAX_SAMPLES];
		samples[0] = carDrive_Basc_APAInteract_Reply__alloc();
		rc = dds_take_next(reader, samples, infos);
		if (rc < 0) {
			ASF_LOG_ERROR_ARGS("on_carDrive_Basc_APAInteract_reply_data_available dds_take_next faild rc=[%d]", rc);
			//printf("dds_take_next failed!\n");
		}
		if (infos[0].valid_data) {
			reply = (carDrive_Basc_APAInteract_Reply*)samples[0];
			auto sp = std::shared_ptr<void>{
				samples[0],
				[](void* ptr) {
					carDrive_Basc_APAInteract_Reply_free(ptr,DDS_FREE_ALL);
				}
			};
			int32_t funID = reply->data._d;
			ASF_LOG_DEBUG_ARGS("on_carDrive_Basc_APAInteract_reply_data_available, hashId=[%d], reqId=[%d]", funID, reply->header.relatedRequestId.sequence_number.low);
			switch (funID) {
				case carDrive_Basc_APAInteract_Get_AD_APACustSlot_Hash:
				case carDrive_Basc_APAInteract_Get_AD_APADynguidance_Hash:
				case carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Hash:
				case carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Hash:
				case carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash:
				case carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash:
				case carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash:
				case carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash:
				case carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash:
				case carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Hash:
				case carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash:
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

	Basc_APAInteract_Proxy::Basc_APAInteract_Proxy(){

    }

    void on_Basc_APAInteract_request_publication_matched_cb(dds_entity_t writer, const dds_publication_matched_status_t  status, void* arg) {
		ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_request_publication_matched_cb, writer=[%d], current_count=[%d]", writer, status.current_count);
		Basc_APAInteract_Proxy *pTmp = &Basc_APAInteract_Proxy::get_instance();
		auto handler=Basc_APAInteract_Proxy::get_instance().get_provider_matched_handler();
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
	
	void on_Basc_APAInteract_reply_sublication_matched_cb(dds_entity_t reader, const dds_subscription_matched_status_t  status, void* arg) {
		ASF_LOG_DEBUG_ARGS("on_Basc_APAInteract_reply_sublication_matched_cb, reader=[%d], current_count=[%d]", reader, status.current_count);
		Basc_APAInteract_Proxy *pTmp = &Basc_APAInteract_Proxy::get_instance();
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


	void Basc_APAInteract_Proxy::wait_server_online()
	{
		this->wait_for_sub_online(dds_rpc_reply_handle.reader);
	}

	bool Basc_APAInteract_Proxy::init(std::string config) {
	    std::lock_guard<std::mutex> guard(init_mutex);
	    if(this->init_flag){
	        return true;
	    }
		logconfig_Skeleton::get_instance().init(config);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->get_service_name()+"_"+this->Ntf_AD_APACustSlot.get_name(),
		    &carDrive_Basc_APAInteract_Ntf_desc,
			&on_Basc_APAInteract_Ntf_AD_APACustSlot_data_available,
			NULL,
			&dds_Ntf_AD_APACustSlot_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->get_service_name()+"_"+this->Ntf_AD_APADynguidance.get_name(),
		    &carDrive_Basc_APAInteract_Ntf_desc,
			&on_Basc_APAInteract_Ntf_AD_APADynguidance_data_available,
			NULL,
			&dds_Ntf_AD_APADynguidance_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->get_service_name()+"_"+this->Ntf_AD_APADynrecommd.get_name(),
		    &carDrive_Basc_APAInteract_Ntf_desc,
			&on_Basc_APAInteract_Ntf_AD_APADynrecommd_data_available,
			NULL,
			&dds_Ntf_AD_APADynrecommd_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->get_service_name()+"_"+this->Ntf_AD_APAFctnIndnMsg.get_name(),
		    &carDrive_Basc_APAInteract_Ntf_desc,
			&on_Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_data_available,
			NULL,
			&dds_Ntf_AD_APAFctnIndnMsg_handle,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config);
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			this->service_name + "_reply",
			&carDrive_Basc_APAInteract_Reply_desc,
			&on_carDrive_Basc_APAInteract_reply_data_available,
			NULL,
			&dds_rpc_reply_handle,
			&on_Basc_APAInteract_reply_sublication_matched_cb,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config
		);
		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			this->service_name + "_request",
			&carDrive_Basc_APAInteract_Request_desc,
			&dds_rpc_request_handle,
            &on_Basc_APAInteract_request_publication_matched_cb,{PROXY_TOKEN, PROXY_TOKEN, ""},config
		);

		this->init_flag = true;
		return true;
	}

	bool Basc_APAInteract_Proxy::destroy() {
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::destroy");
		std::lock_guard<std::mutex> guard(init_mutex);
	    if (!this->init_flag) {
			return true;
		}
		if (!DDSUtil::dds_client_destroy(&dds_Ntf_AD_APACustSlot_handle)) {
			return false;
		}
		if (!DDSUtil::dds_client_destroy(&dds_Ntf_AD_APADynguidance_handle)) {
			return false;
		}
		if (!DDSUtil::dds_client_destroy(&dds_Ntf_AD_APADynrecommd_handle)) {
			return false;
		}
		if (!DDSUtil::dds_client_destroy(&dds_Ntf_AD_APAFctnIndnMsg_handle)) {
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

	Msg<AD_APACustSlotData> Basc_APAInteract_Proxy::Get_AD_APACustSlot( size_t dds_rpc_time_out) {
		Msg<AD_APACustSlotData> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::Get_AD_APACustSlot dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carDrive_Basc_APAInteract_Get_AD_APACustSlot_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::Get_AD_APACustSlot pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_Get_AD_APACustSlot_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.Get_AD_APACustSlot.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<AD_APADynguidanceData> Basc_APAInteract_Proxy::Get_AD_APADynguidance( size_t dds_rpc_time_out) {
		Msg<AD_APADynguidanceData> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::Get_AD_APADynguidance dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carDrive_Basc_APAInteract_Get_AD_APADynguidance_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::Get_AD_APADynguidance pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_Get_AD_APADynguidance_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.Get_AD_APADynguidance.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<AD_APADynrecommdData> Basc_APAInteract_Proxy::Get_AD_APADynrecommd( size_t dds_rpc_time_out) {
		Msg<AD_APADynrecommdData> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::Get_AD_APADynrecommd dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::Get_AD_APADynrecommd pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.Get_AD_APADynrecommd.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<AD_APAFctnIndnMsgData> Basc_APAInteract_Proxy::Get_AD_APAFctnIndnMsg( size_t dds_rpc_time_out) {
		Msg<AD_APAFctnIndnMsgData> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::Get_AD_APAFctnIndnMsg dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;

		_rpc_request->data._d = carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::Get_AD_APAFctnIndnMsg pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.Get_AD_APAFctnIndnMsg.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_APAInteract_Proxy::RR_EDC_APADrvrReqOnOff(const EDC_APADrvrReqOnOffData &EDC_APADrvrReqOnOffData_,const RequestInfo &RequestInfo_, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::RR_EDC_APADrvrReqOnOff dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_EDC_APADrvrReqOnOff.EDC_APADrvrReqOnOffData = EDC_APADrvrReqOnOffData_;
		_rpc_request->data._u.RR_EDC_APADrvrReqOnOff.RequestInfo = RequestInfo_;

		_rpc_request->data._d = carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::RR_EDC_APADrvrReqOnOff pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_EDC_APADrvrReqOnOff.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_APAInteract_Proxy::RR_EDC_APADrvrReqSlotID(const EDC_APADrvrReqSlotIDData &EDC_APADrvrReqSlotIDData_,const RequestInfo &RequestInfo_, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::RR_EDC_APADrvrReqSlotID dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_EDC_APADrvrReqSlotID.EDC_APADrvrReqSlotIDData = EDC_APADrvrReqSlotIDData_;
		_rpc_request->data._u.RR_EDC_APADrvrReqSlotID.RequestInfo = RequestInfo_;

		_rpc_request->data._d = carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::RR_EDC_APADrvrReqSlotID pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_EDC_APADrvrReqSlotID.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_APAInteract_Proxy::RR_EDC_APAParkInSelect(const EDC_APAParkInSelectData &EDC_APAParkInSelectData_,const RequestInfo &RequestInfo_, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::RR_EDC_APAParkInSelect dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_EDC_APAParkInSelect.EDC_APAParkInSelectData = EDC_APAParkInSelectData_;
		_rpc_request->data._u.RR_EDC_APAParkInSelect.RequestInfo = RequestInfo_;

		_rpc_request->data._d = carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::RR_EDC_APAParkInSelect pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_EDC_APAParkInSelect.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_APAInteract_Proxy::RR_EDC_APADynamicOperate(const EDC_APADynamicOperateData &EDC_APADynamicOperateData_,const RequestInfo &RequestInfo_, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::RR_EDC_APADynamicOperate dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_EDC_APADynamicOperate.EDC_APADynamicOperateData = EDC_APADynamicOperateData_;
		_rpc_request->data._u.RR_EDC_APADynamicOperate.RequestInfo = RequestInfo_;

		_rpc_request->data._d = carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::RR_EDC_APADynamicOperate pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_EDC_APADynamicOperate.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_APAInteract_Proxy::RR_EDC_APAParkOutSelect(const EDC_APAParkOutSelectData &EDC_APAParkOutSelectData_,const RequestInfo &RequestInfo_, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::RR_EDC_APAParkOutSelect dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_EDC_APAParkOutSelect.EDC_APAParkOutSelectData = EDC_APAParkOutSelectData_;
		_rpc_request->data._u.RR_EDC_APAParkOutSelect.RequestInfo = RequestInfo_;

		_rpc_request->data._d = carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::RR_EDC_APAParkOutSelect pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_EDC_APAParkOutSelect.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_APAInteract_Proxy::RR_EDC_APACustSlot(const EDC_APACustSlotData &EDC_APACustSlotData_,const RequestInfo &RequestInfo_, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::RR_EDC_APACustSlot dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_EDC_APACustSlot.EDC_APACustSlotData = EDC_APACustSlotData_;
		_rpc_request->data._u.RR_EDC_APACustSlot.RequestInfo = RequestInfo_;

		_rpc_request->data._d = carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::RR_EDC_APACustSlot pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_EDC_APACustSlot.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
	Msg<uint8_t> Basc_APAInteract_Proxy::RR_EDC_RADSDrvrReq(const EDC_RADSDrvrReqData &EDC_RADSDrvrReqData_,const RequestInfo &RequestInfo_, size_t dds_rpc_time_out) {
		Msg<uint8_t> _rpc_result;
		carDrive_Basc_APAInteract_Request* _rpc_request = carDrive_Basc_APAInteract_Request__alloc();

		dds_guid_t _temp_guid = { 0 };
		dds_return_t rc = dds_get_guid(dds_rpc_request_handle.writer, &_temp_guid);
		if (DDS_RETCODE_OK != rc)
		{
			ASF_LOG_ERROR_ARGS("Basc_APAInteract_Proxy::RR_EDC_RADSDrvrReq dds_get_guid faild rc=[%d], writer=[%d]", rc, dds_rpc_request_handle.writer);
			_rpc_result.code = DDS_RPC_REMOTE_EX_UNSUPPORTED;
			return _rpc_result;
		}

		memcpy(&_rpc_request->header.requestId, &_temp_guid, sizeof(dds_guid_t));
		DDS_SequenceNumber_t _rpc_client_sn = com::changan::rpc_service::DDSClient::get_rpc_request_id();
		_rpc_request->header.requestId.sequence_number = _rpc_client_sn;
		_rpc_request->data._u.RR_EDC_RADSDrvrReq.EDC_RADSDrvrReqData = EDC_RADSDrvrReqData_;
		_rpc_request->data._u.RR_EDC_RADSDrvrReq.RequestInfo = RequestInfo_;

		_rpc_request->data._d = carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash;
		ASF_LOG_DEBUG_ARGS("Basc_APAInteract_Proxy::RR_EDC_RADSDrvrReq pre async_call, hashId=[%d], reqId=[%d]", carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash, _rpc_client_sn.low);
		auto _rpc_future = com::changan::rpc_service::DDSClient::async_call(_rpc_client_sn.low, dds_rpc_request_handle.writer, _rpc_request);
		carDrive_Basc_APAInteract_Request_free(_rpc_request, DDS_FREE_ALL);

		auto _rpc_status = _rpc_future.wait_for(std::chrono::milliseconds(dds_rpc_time_out));
		if (_rpc_status == std::future_status::timeout ||
			_rpc_status == std::future_status::deferred) {
			_rpc_result.code = DDS_RPC_REMOTE_TIMEOUT_EXCEPTION;
			return _rpc_result;
		}
		auto sp =_rpc_future.get();
		auto _rpc_ret = (carDrive_Basc_APAInteract_Reply*)sp.get();

		_rpc_result.code = _rpc_ret->header.remoteEx;
		if (_rpc_result.code == DDS_RPC_REMOTE_EX_OK) {
			_rpc_result.data = _rpc_ret->data._u.RR_EDC_RADSDrvrReq.return_;
			_rpc_result.autoFreePtr = sp;
		}
		return _rpc_result;
	}
    Basc_APAInteract_Proxy::~Basc_APAInteract_Proxy(){

    }

	Basc_APAInteract_Proxy& Basc_APAInteract_Proxy::get_instance()
	{
		static Basc_APAInteract_Proxy instance;
		return instance;
	}
}
}
}
}
}
