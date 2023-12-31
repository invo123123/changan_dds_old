/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V1.3
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-02-06T16:34:40
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_EleAirSuspModSts_SKELETON_HPP
#define Basc_EleAirSuspModSts_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/string_util.hpp"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include "changan/Car_Control_r_Skeleton.hpp"
#include "changan/Car_Control.h"
#include <mutex>
namespace com {
namespace changan {
namespace carControl {
namespace CHS_SUSP {
namespace skeleton {
	namespace events {
		using CarControlRSkeleton = com::changan::carControl::skeleton::CarControlRSkeleton;
        class Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts{
            private:
                dds_rpc_handle_t dds_Ntf_EleAirSuspIntenModSts_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_EleAirSuspModSts_skeleton_Ntf_EleAirSuspIntenModSts";
			public:
			    Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts() {
			    }
			    ~Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts() {
                }
                void send(const EleAirSuspIntenModSts &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts_Hash;
					ntf_message._u.Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlRSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts{
            private:
                dds_rpc_handle_t dds_Ntf_EleAirSuspHighModSts_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_EleAirSuspModSts_skeleton_Ntf_EleAirSuspHighModSts";
			public:
			    Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts() {
			    }
			    ~Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts() {
                }
                void send(const EleAirSuspHighModSts &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts_Hash;
					ntf_message._u.Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlRSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts{
            private:
                dds_rpc_handle_t dds_Ntf_EleAirSuspHighModCHASts_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_EleAirSuspModSts_skeleton_Ntf_EleAirSuspHighModCHASts";
			public:
			    Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts() {
			    }
			    ~Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts() {
                }
                void send(const EleAirSuspHighModCHASts &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts_Hash;
					ntf_message._u.Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlRSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts{
            private:
                dds_rpc_handle_t dds_Ntf_EleAirSuspAutoModSts_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_EleAirSuspModSts_skeleton_Ntf_EleAirSuspAutoModSts";
			public:
			    Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts() {
			    }
			    ~Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts() {
                }
                void send(const EleAirSuspAutoModSts &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts_Hash;
					ntf_message._u.Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlRSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlRSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
	}
	extern void on_carControl_Basc_EleAirSuspModSts_request_data_available(int32_t reader, void* arg);

	class Basc_EleAirSuspModSts_service_interface {
	public:
	    virtual ~Basc_EleAirSuspModSts_service_interface() = default;

		virtual EleAirSuspIntenModSts Get_EleAirSuspIntenModSts() = 0;
		virtual EleAirSuspHighModSts Get_EleAirSuspHighModSts() = 0;
		virtual EleAirSuspHighModCHASts Get_EleAirSuspHighModCHASts() = 0;
		virtual EleAirSuspAutoModSts Get_EleAirSuspAutoModSts() = 0;
	};
    class Basc_EleAirSuspModSts_Skeleton :public Basc_EleAirSuspModSts_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_EleAirSuspModSts_Skeleton(Basc_EleAirSuspModSts_service_interface* service,std::string config="");
			bool init();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			EleAirSuspIntenModSts Get_EleAirSuspIntenModSts() {
				return this->_service->Get_EleAirSuspIntenModSts();
			}
			EleAirSuspHighModSts Get_EleAirSuspHighModSts() {
				return this->_service->Get_EleAirSuspHighModSts();
			}
			EleAirSuspHighModCHASts Get_EleAirSuspHighModCHASts() {
				return this->_service->Get_EleAirSuspHighModCHASts();
			}
			EleAirSuspAutoModSts Get_EleAirSuspAutoModSts() {
				return this->_service->Get_EleAirSuspAutoModSts();
			}
            dds_return_t send_reply(carControl_Car_Control_Reply* reply);
            events::Basc_EleAirSuspModSts_Ntf_EleAirSuspIntenModSts Ntf_EleAirSuspIntenModSts;
            events::Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModSts Ntf_EleAirSuspHighModSts;
            events::Basc_EleAirSuspModSts_Ntf_EleAirSuspHighModCHASts Ntf_EleAirSuspHighModCHASts;
            events::Basc_EleAirSuspModSts_Ntf_EleAirSuspAutoModSts Ntf_EleAirSuspAutoModSts;


		private:
		    std::string _config;
			const std::string service_name="Basc_EleAirSuspModSts_skeleton";
			Basc_EleAirSuspModSts_service_interface * _service;

			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };
	};

}
}
}
}
}
#endif

