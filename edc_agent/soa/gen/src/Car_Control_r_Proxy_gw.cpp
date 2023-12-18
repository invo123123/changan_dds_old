/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: 
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#include "Car_Control_r_Proxy_gw.hpp"
#include "changan/Car_Control.h"
#include "changan/dds_client.hpp"
#include "changan/Basc_EleAirSuspModSet_Proxy.hpp"
#include "changan/Basc_EleAirSuspModSts_Proxy.hpp"
#include "changan/Basc_RearWiperFltSts_Proxy.hpp"
#include "changan/Basc_TailGateSts_Proxy.hpp"
namespace com {
	namespace changan {
		namespace carControl {
			namespace proxy {
				using namespace com::changan::rpc_service;
				using namespace com::changan::soa_log::skeleton;
				void Basc_EleAirSuspModSet_Ntf_EleAirSuspHighModSet_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_EleAirSuspModSet_Proxy = com::changan::carControl::CHS_SUSP::proxy::Basc_EleAirSuspModSet_Proxy;
					if(Basc_EleAirSuspModSet_Proxy::get_instance().is_init()){
						Basc_EleAirSuspModSet_Proxy::get_instance().Ntf_EleAirSuspHighModSet.trigger(notify_data->data._u.Car_Control_Basc_EleAirSuspModSet_Ntf_EleAirSuspHighModSet);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_EleAirSuspModSet_Ntf_EleAirSuspIntenModSet_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_EleAirSuspModSet_Proxy = com::changan::carControl::CHS_SUSP::proxy::Basc_EleAirSuspModSet_Proxy;
					if(Basc_EleAirSuspModSet_Proxy::get_instance().is_init()){
						Basc_EleAirSuspModSet_Proxy::get_instance().Ntf_EleAirSuspIntenModSet.trigger(notify_data->data._u.Car_Control_Basc_EleAirSuspModSet_Ntf_EleAirSuspIntenModSet);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_EleAirSuspModSet_Ntf_EleAirSuspAutoModSet_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_EleAirSuspModSet_Proxy = com::changan::carControl::CHS_SUSP::proxy::Basc_EleAirSuspModSet_Proxy;
					if(Basc_EleAirSuspModSet_Proxy::get_instance().is_init()){
						Basc_EleAirSuspModSet_Proxy::get_instance().Ntf_EleAirSuspAutoModSet.trigger(notify_data->data._u.Car_Control_Basc_EleAirSuspModSet_Ntf_EleAirSuspAutoModSet);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_EleAirSuspModSts_Proxy = com::changan::carControl::CHS_SUSP::proxy::Basc_EleAirSuspModSts_Proxy;
					if(Basc_EleAirSuspModSts_Proxy::get_instance().is_init()){
						Basc_EleAirSuspModSts_Proxy::get_instance().Ntf_EleAirSuspIntenModSts.trigger(notify_data->data._u.Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_EleAirSuspModSts_Proxy = com::changan::carControl::CHS_SUSP::proxy::Basc_EleAirSuspModSts_Proxy;
					if(Basc_EleAirSuspModSts_Proxy::get_instance().is_init()){
						Basc_EleAirSuspModSts_Proxy::get_instance().Ntf_EleAirSuspHighModSts.trigger(notify_data->data._u.Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_EleAirSuspModSts_Proxy = com::changan::carControl::CHS_SUSP::proxy::Basc_EleAirSuspModSts_Proxy;
					if(Basc_EleAirSuspModSts_Proxy::get_instance().is_init()){
						Basc_EleAirSuspModSts_Proxy::get_instance().Ntf_EleAirSuspHighModCHASts.trigger(notify_data->data._u.Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_EleAirSuspModSts_Proxy = com::changan::carControl::CHS_SUSP::proxy::Basc_EleAirSuspModSts_Proxy;
					if(Basc_EleAirSuspModSts_Proxy::get_instance().is_init()){
						Basc_EleAirSuspModSts_Proxy::get_instance().Ntf_EleAirSuspAutoModSts.trigger(notify_data->data._u.Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_RearWiperFltSts_Ntf_WiperFltSts_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_RearWiperFltSts_Proxy = com::changan::carControl::WiperWasher::proxy::Basc_RearWiperFltSts_Proxy;
					if(Basc_RearWiperFltSts_Proxy::get_instance().is_init()){
						Basc_RearWiperFltSts_Proxy::get_instance().Ntf_WiperFltSts.trigger(notify_data->data._u.Car_Control_Basc_RearWiperFltSts_Ntf_WiperFltSts);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_TailGateSts_Ntf_LockSt_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_TailGateSts_Proxy = com::changan::carControl::Tailgate::proxy::Basc_TailGateSts_Proxy;
					if(Basc_TailGateSts_Proxy::get_instance().is_init()){
						Basc_TailGateSts_Proxy::get_instance().Ntf_LockSt.trigger(notify_data->data._u.Car_Control_Basc_TailGateSts_Ntf_LockSt);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_TailGateSts_Ntf_TailGateSysSt_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_TailGateSts_Proxy = com::changan::carControl::Tailgate::proxy::Basc_TailGateSts_Proxy;
					if(Basc_TailGateSts_Proxy::get_instance().is_init()){
						Basc_TailGateSts_Proxy::get_instance().Ntf_TailGateSysSt.trigger(notify_data->data._u.Car_Control_Basc_TailGateSts_Ntf_TailGateSysSt);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_TailGateSts_Ntf_MotCurPosVIT_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_TailGateSts_Proxy = com::changan::carControl::Tailgate::proxy::Basc_TailGateSts_Proxy;
					if(Basc_TailGateSts_Proxy::get_instance().is_init()){
						Basc_TailGateSts_Proxy::get_instance().Ntf_MotCurPosVIT.trigger(notify_data->data._u.Car_Control_Basc_TailGateSts_Ntf_MotCurPosVIT);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_TailGateSts_Ntf_TailGateWinSt_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_TailGateSts_Proxy = com::changan::carControl::Tailgate::proxy::Basc_TailGateSts_Proxy;
					if(Basc_TailGateSts_Proxy::get_instance().is_init()){
						Basc_TailGateSts_Proxy::get_instance().Ntf_TailGateWinSt.trigger(notify_data->data._u.Car_Control_Basc_TailGateSts_Ntf_TailGateWinSt);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_TailGateSts_Ntf_WinCurPosVIT_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_TailGateSts_Proxy = com::changan::carControl::Tailgate::proxy::Basc_TailGateSts_Proxy;
					if(Basc_TailGateSts_Proxy::get_instance().is_init()){
						Basc_TailGateSts_Proxy::get_instance().Ntf_WinCurPosVIT.trigger(notify_data->data._u.Car_Control_Basc_TailGateSts_Ntf_WinCurPosVIT);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_TailGateSts_Ntf_TailGateSysSwSt_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_TailGateSts_Proxy = com::changan::carControl::Tailgate::proxy::Basc_TailGateSts_Proxy;
					if(Basc_TailGateSts_Proxy::get_instance().is_init()){
						Basc_TailGateSts_Proxy::get_instance().Ntf_TailGateSysSwSt.trigger(notify_data->data._u.Car_Control_Basc_TailGateSts_Ntf_TailGateSysSwSt);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
				void Basc_TailGateSts_Ntf_TailGateSysSwFltSt_trigger(carControl_Car_Control_Ntf* notify_data) {
					using Basc_TailGateSts_Proxy = com::changan::carControl::Tailgate::proxy::Basc_TailGateSts_Proxy;
					if(Basc_TailGateSts_Proxy::get_instance().is_init()){
						Basc_TailGateSts_Proxy::get_instance().Ntf_TailGateSysSwFltSt.trigger(notify_data->data._u.Car_Control_Basc_TailGateSts_Ntf_TailGateSysSwFltSt);
					}
					carControl_Car_Control_Ntf_free(notify_data, DDS_FREE_ALL);
				}
			    void on_carControl_r_notify_data_available_gw(int32_t reader, void* arg) {
			    	ASF_LOG_DEBUG_ARGS("on_carControl_r_notify_data_available_gw");
			    	dds_return_t rc;
					carControl_Car_Control_Ntf* data;
					void* samples[MAX_SAMPLES];
					dds_sample_info_t infos[MAX_SAMPLES];
					samples[0] = carControl_Car_Control_Ntf__alloc();
					rc = dds_take_next(reader, samples, infos);
					if (rc < 0) {
						ASF_LOG_ERROR_ARGS("on_carControl_r_notify_data_available_gw dds_take_next faild rc=[%d]", rc);
					}
					if (infos[0].valid_data) {
						data = (carControl_Car_Control_Ntf*)samples[0];
						int event_id = data->data._d;
						ASF_LOG_DEBUG_ARGS("on_carControl_notify_data_available_gw, hashId=[%d]", event_id);
						switch (event_id)
						{
						case carControl_Car_Control_Basc_EleAirSuspModSet_Ntf_EleAirSuspHighModSet_Hash:
						{
						    DDSClient::execute(Basc_EleAirSuspModSet_Ntf_EleAirSuspHighModSet_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_EleAirSuspModSet_Ntf_EleAirSuspIntenModSet_Hash:
						{
						    DDSClient::execute(Basc_EleAirSuspModSet_Ntf_EleAirSuspIntenModSet_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_EleAirSuspModSet_Ntf_EleAirSuspAutoModSet_Hash:
						{
						    DDSClient::execute(Basc_EleAirSuspModSet_Ntf_EleAirSuspAutoModSet_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts_Hash:
						{
						    DDSClient::execute(Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts_Hash:
						{
						    DDSClient::execute(Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts_Hash:
						{
						    DDSClient::execute(Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts_Hash:
						{
						    DDSClient::execute(Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_RearWiperFltSts_Ntf_WiperFltSts_Hash:
						{
						    DDSClient::execute(Basc_RearWiperFltSts_Ntf_WiperFltSts_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_TailGateSts_Ntf_LockSt_Hash:
						{
						    DDSClient::execute(Basc_TailGateSts_Ntf_LockSt_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_TailGateSts_Ntf_TailGateSysSt_Hash:
						{
						    DDSClient::execute(Basc_TailGateSts_Ntf_TailGateSysSt_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_TailGateSts_Ntf_MotCurPosVIT_Hash:
						{
						    DDSClient::execute(Basc_TailGateSts_Ntf_MotCurPosVIT_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_TailGateSts_Ntf_TailGateWinSt_Hash:
						{
						    DDSClient::execute(Basc_TailGateSts_Ntf_TailGateWinSt_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_TailGateSts_Ntf_WinCurPosVIT_Hash:
						{
						    DDSClient::execute(Basc_TailGateSts_Ntf_WinCurPosVIT_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_TailGateSts_Ntf_TailGateSysSwSt_Hash:
						{
						    DDSClient::execute(Basc_TailGateSts_Ntf_TailGateSysSwSt_trigger, data);
							return;
						}
						case carControl_Car_Control_Basc_TailGateSts_Ntf_TailGateSysSwFltSt_Hash:
						{
						    DDSClient::execute(Basc_TailGateSts_Ntf_TailGateSysSwFltSt_trigger, data);
							return;
						}
						default:
							break;
						}
					}
					carControl_Car_Control_Ntf_free(samples[0], DDS_FREE_ALL);
				}

	  			CarControlRProxyGw::CarControlRProxyGw() {
				}

	  			void CarControlRProxyGw::wait_server_online()
	  			{
	  				this->wait_for_sub_online(dds_mcu_rpc_handle.reader);
	  			}

	  			bool CarControlRProxyGw::init(std::string config) {
                    std::lock_guard<std::mutex> guard(init_mutex);
					if (this->init_flag) {
						return true;
					}
		  			logconfig_Skeleton::get_instance().init(config);
					uint8_t  service_id_array[467] = {0x0,0x0,0x0,0x20,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x40,0x0,0x40,0x0,0x60,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0x8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6,0x0,0x0,0x0,0x0,0x0,0x0,0x40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x9,0x80,0x0,0x0,0xc0,0x20,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x20,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x10,0x8,0x2,0x98,0x0,0x40,0x80,0x0,0x2,0x0,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x2};
					DDSUtil::event_sub_init(DDS_DOMAIN_ID,
						"viu_r_mcu_notify",
						&carControl_Car_Control_Ntf_desc,
						&on_carControl_r_notify_data_available_gw,
						NULL,
						&this->dds_mcu_notify_handle,
		  				NULL,
						{PROXY_TOKEN, PROXY_TOKEN, "ntf"} ,
						{467,service_id_array},
						config);

					DDSUtil::event_sub_init(DDS_DOMAIN_ID,
		  				"viu_r_mcu_rpc_service_reply",
		  				&carControl_Car_Control_Reply_desc,
		  				&on_carControl_r_rpc_reply_data_available,
						NULL,
						&this->dds_mcu_rpc_handle,
		  				&on_CarControlRProxy_reply_sublication_matched_cb<CarControlRProxyGw>,
		  				{PROXY_TOKEN, PROXY_TOKEN, "*rpc"},
		  				{},
		  				config
					);

					DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			  			"viu_r_mcu_rpc_service_request",
						&carControl_Car_Control_Request_desc,
						&this->dds_mcu_rpc_handle,
			  			&on_CarControlRProxy_request_publication_matched_cb<CarControlRProxyGw>,
			  			{PROXY_TOKEN, PROXY_TOKEN, "*rpc"},
		  				config,
				  		&on_CarControlRProxy_request_topicdata_checkable_cb<CarControlRProxyGw>
					);
					this->init_flag = true;
					return true;
				}
				CarControlRProxyGw& CarControlRProxyGw::get_instance()
				{
					static CarControlRProxyGw instance;
					return instance;
				}
			}
		}
	}
}

