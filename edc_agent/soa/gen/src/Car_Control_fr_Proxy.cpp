/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: 
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "Car_Control_fr_Proxy.hpp"
#include "changan/Car_Control.h"
#include "changan/dds_util.h"
#include "changan/dds_client.hpp"
#include "changan/Cnr_RiMirrLaneLED_Proxy.hpp"
namespace com {
	namespace changan {
		namespace carControl {
			namespace proxy {
				using namespace com::changan::soa_log::skeleton;
	  			void on_carControl_fr_rpc_reply_data_available(int32_t reader, void* arg) {
	  				ASF_LOG_DEBUG_ARGS("on_carControl_fr_rpc_reply_data_available");
			    	dds_return_t rc;
					carControl_Car_Control_Reply* reply;
					void* samples[MAX_SAMPLES];
					dds_sample_info_t infos[MAX_SAMPLES];
					samples[0] = carControl_Car_Control_Reply__alloc();
					rc = dds_take_next(reader, samples, infos);
					if (rc < 0) {
						ASF_LOG_ERROR_ARGS("on_carControl_rpc_reply_data_available dds_take_next faild rc=[%d]", rc);
						//printf("dds_take_next failed!\n");
					}
					if (infos[0].valid_data) {
						reply = (carControl_Car_Control_Reply*)samples[0];
						auto sp = std::shared_ptr<void>{
							samples[0],
							[](void* ptr) {
								carControl_Car_Control_Reply_free(ptr,DDS_FREE_ALL);
							}
						};
						// 不存在的methodId也需要立即释放，不阻塞客户端
						uint64_t key = reply->header.relatedRequestId.sequence_number.low;
						ASF_LOG_DEBUG_ARGS("on_carControl_rpc_reply_data_available, hashId=[%d], reqId=[%d]", reply->data._d, key);
						com::changan::rpc_service::DDSClient::release(key, sp);
					}
				}
			    void on_carControl_fr_notify_data_available(int32_t reader, void* arg) {
			    	dds_return_t rc;
					carControl_Car_Control_Ntf* data;
					void* samples[MAX_SAMPLES];
					dds_sample_info_t infos[MAX_SAMPLES];
					samples[0] = carControl_Car_Control_Ntf__alloc();
					rc = dds_take_next(reader, samples, infos);
					if (rc < 0) {
						ASF_LOG_ERROR_ARGS("dds_take_next failed!");
					}
					if (infos[0].valid_data) {
						data = (carControl_Car_Control_Ntf*)samples[0];
						int event_id = data->data._d;
						switch (event_id)
						{
						case carControl_Car_Control_Cnr_RiMirrLaneLED_Ntf_SrvOperInfo_Hash:
						{
						    using Cnr_RiMirrLaneLED_Proxy = com::changan::carControl::RearViewMirror::proxy::Cnr_RiMirrLaneLED_Proxy;
							if(Cnr_RiMirrLaneLED_Proxy::get_instance().is_init()){
								Cnr_RiMirrLaneLED_Proxy::get_instance().Ntf_SrvOperInfo.trigger(data->data._u.Car_Control_Cnr_RiMirrLaneLED_Ntf_SrvOperInfo);
							}
							break;
						}
						case carControl_Car_Control_Cnr_RiMirrLaneLED_Ntf_OperationCode_Hash:
						{
						    using Cnr_RiMirrLaneLED_Proxy = com::changan::carControl::RearViewMirror::proxy::Cnr_RiMirrLaneLED_Proxy;
							if(Cnr_RiMirrLaneLED_Proxy::get_instance().is_init()){
								Cnr_RiMirrLaneLED_Proxy::get_instance().Ntf_OperationCode.trigger(data->data._u.Car_Control_Cnr_RiMirrLaneLED_Ntf_OperationCode);
							}
							break;
						}
						default:
							break;
						}
					}
					carControl_Car_Control_Ntf_free(samples[0], DDS_FREE_ALL);
				}
		  		CarControlFRProxy::CarControlFRProxy() {
				}

				dds_rpc_handle_t CarControlFRProxy::get_rpc_handle() {
					return this->dds_mcu_rpc_handle;
				}

		  		void CarControlFRProxy::register_provider_matched_handler(std::string name,uint16_t serviceId, EventReceiveHandler<const ProviderMatchedStatus&> handler){
					if(NULL==handler || name.empty() || serviceId == 0){
			  			return;
			  		}
			  		//provider_matched_handler_map[name]=handler;
                    //解析的bitmap获取服务在线信息
					bool online = false;
					T_topicdata_bitmap *topic_bitmap = get_topicdata_bitmap();
					if(topic_bitmap != NULL)
					{
                        online = get_servive_online(serviceId,topic_bitmap->topicdata_bitmap, topic_bitmap->topicdata_bitmap_len);
					    topicdata_checkable_handler_map[serviceId].bOnline = online;
					}

			  		if(this->init_flag && this->provider_matched_status.is_online){
						ProviderMatchedStatus provider_matched_status={};
                        provider_matched_status.is_online = online;
						handler(provider_matched_status);
			  			//handler(this->provider_matched_status);
						auto it = topicdata_checkable_handler_map.find(serviceId);
						if (it != topicdata_checkable_handler_map.end())
						{
                            topicdata_checkable_handler_map[serviceId].preOnline = provider_matched_status.is_online;
						}
						
			  		}
			  	}

			  	//std::unordered_map<std::string, EventReceiveHandler<const ProviderMatchedStatus&>> CarControlFRProxy::get_registered_provider_matched_handler(){
				//  	return this->provider_matched_handler_map;
				//}

				void CarControlFRProxy::set_last_provider_match_status(ProviderMatchedStatus status){
				  	this->provider_matched_status=status;
				}

				std::future<std::shared_ptr<void>> CarControlFRProxy::call(uint64_t fu_id,const void* data) {
					return com::changan::rpc_service::DDSClient::async_call(fu_id, this->dds_mcu_rpc_handle.writer, data);
				}
				
				void CarControlFRProxy::register_topicdata_checkable_handler(uint16_t serviceId, EventReceiveHandler<const ProviderMatchedStatus&> handler) {
					if (NULL == handler || serviceId == 0) {
						return;
					}

					ViuStatus vs;
					vs.handler = handler;
					vs.bOnline = false;
					topicdata_checkable_handler_map[serviceId] = vs;
				}

				std::unordered_map<uint16_t, ViuStatus>& CarControlFRProxy::get_registered_topicdata_checkable_handler() {
					return this->topicdata_checkable_handler_map;
				}
				
				bool CarControlFRProxy::get_topicdata_online(uint16_t serviceId)
				{
                    auto it = topicdata_checkable_handler_map.find(serviceId);
					if (it != topicdata_checkable_handler_map.end())
					{
                       return topicdata_checkable_handler_map[serviceId].bOnline;
					}
					return false;
				}

				void CarControlFRProxy::set_topicdata_online(uint16_t serviceId, bool online)
				{
					auto it = topicdata_checkable_handler_map.find(serviceId);
					if (it != topicdata_checkable_handler_map.end())
					{
                        topicdata_checkable_handler_map[serviceId].bOnline = online;
					}	
				}

				bool CarControlFRProxy::get_servive_online(uint16_t serviceId, const unsigned char* topicdata_value, uint32_t topicdata_len)
				{
                    bool bOnline = false;
					uint32_t byteIdx = (uint32_t)(serviceId + 7) / 8 - 1;
				
					if (byteIdx <= topicdata_len) {
						uint32_t bitIdx = (serviceId - 1) % 8;
						uint8_t u8 = (uint8_t)topicdata_value[byteIdx];
						bOnline = u8 & (((uint8_t)1) << (8 - bitIdx - 1));							
					}
					return bOnline;
				}

				T_topicdata_bitmap * CarControlFRProxy::get_topicdata_bitmap()
				{
					return &(this->topic_bitmap);
				}
			}
		}
	}
}
