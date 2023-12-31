/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  ServiceVersion: V3.0
  CmVersion： v2.0.3
  ServiceLatestModifyTime: 2023-09-12T15:21:18
  Generate Time: 2023-12-11 18:07:58
*****************************************************************/
#ifndef Basc_ExtrLiActCtrlInfo_SKELETON_HPP
#define Basc_ExtrLiActCtrlInfo_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/string_util.hpp"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include "changan/Car_Control_fl_Skeleton.hpp"
#include "changan/Car_Control.h"
#include <mutex>
namespace com {
namespace changan {
namespace carControl {
namespace ExteriorLight {
namespace skeleton {
	namespace events {
		using CarControlFLSkeleton = com::changan::carControl::skeleton::CarControlFLSkeleton;
        class Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo{
            private:
                dds_rpc_handle_t dds_Ntf_PosnLiInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_PosnLiInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo() {
                }
				void send(const carControl_Secure_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo_PosnLiActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo{
            private:
                dds_rpc_handle_t dds_Ntf_LoBeamInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_LoBeamInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo() {
                }
				void send(const carControl_Secure_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo_LoBeamActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo{
            private:
                dds_rpc_handle_t dds_Ntf_HiBeamInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_HiBeamInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo() {
                }
				void send(const carControl_Secure_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo_HiBeamActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_RvsLiInfo{
            private:
                dds_rpc_handle_t dds_Ntf_RvsLiInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_RvsLiInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_RvsLiInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_RvsLiInfo() {
                }
                void send(const RvsLiActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_RvsLiInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_RvsLiInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_RvsLiInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_DRLInfo{
            private:
                dds_rpc_handle_t dds_Ntf_DRLInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_DRLInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_DRLInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_DRLInfo() {
                }
                void send(const DRLActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_DRLInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_DRLInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_DRLInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo{
            private:
                dds_rpc_handle_t dds_Ntf_BrkLiInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_BrkLiInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo() {
                }
				void send(const carControl_Secure_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo_BrkLiActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo{
            private:
                dds_rpc_handle_t dds_Ntf_TurnLiInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_TurnLiInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo() {
                }
				void send(const carControl_Secure_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo_TurnLiActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_FogInfo{
            private:
                dds_rpc_handle_t dds_Ntf_FogInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_FogInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_FogInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_FogInfo() {
                }
                void send(const FogActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_FogInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_FogInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_FogInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_ThrLiInfo{
            private:
                dds_rpc_handle_t dds_Ntf_ThrLiInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_ThrLiInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_ThrLiInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_ThrLiInfo() {
                }
                void send(const ThrLiActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_ThrLiInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_ThrLiInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_ThrLiInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_LogoInfo{
            private:
                dds_rpc_handle_t dds_Ntf_LogoInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_LogoInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_LogoInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_LogoInfo() {
                }
                void send(const LogoActCtrlInfo &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LogoInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LogoInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LogoInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
        class Basc_ExtrLiActCtrlInfo_Ntf_LicenseInfo{
            private:
                dds_rpc_handle_t dds_Ntf_LicenseInfo_event_handle = { -1, -1, -1 };
                std::string _topic_name = "Basc_ExtrLiActCtrlInfo_skeleton_Ntf_LicenseInfo";
			public:
			    Basc_ExtrLiActCtrlInfo_Ntf_LicenseInfo() {
			    }
			    ~Basc_ExtrLiActCtrlInfo_Ntf_LicenseInfo() {
                }
                void send(const uint8_t &data){
                    carControl_Car_Control_Ntf * notify = carControl_Car_Control_Ntf__alloc();
					carControl_Car_Control_Ntf_Message  ntf_message;
					ntf_message._d = carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LicenseInfo_Hash;
					ntf_message._u.Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LicenseInfo = data;
					notify->data = ntf_message;
					dds_return_t rc = CarControlFLSkeleton::get_instance().send(notify);
					ASF_LOG_DEBUG_ARGS("CarControlFLSkeleton::send, hashId=[%d], rc=[%d]", carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LicenseInfo_Hash, rc);
					carControl_Car_Control_Ntf_free(notify, DDS_FREE_ALL);
				}
        };
	}
	extern void on_carControl_Basc_ExtrLiActCtrlInfo_request_data_available(int32_t reader, void* arg);

	class Basc_ExtrLiActCtrlInfo_service_interface {
	public:
	    virtual ~Basc_ExtrLiActCtrlInfo_service_interface() = default;

		virtual PosnLiActCtrlInfo Get_PosnLiInfo() = 0;
		virtual LoBeamActCtrlInfo Get_LoBeamInfo() = 0;
		virtual HiBeamActCtrlInfo Get_HiBeamInfo() = 0;
		virtual RvsLiActCtrlInfo Get_RvsLiInfo() = 0;
		virtual DRLActCtrlInfo Get_DRLInfo() = 0;
		virtual BrkLiActCtrlInfo Get_BrkLiInfo() = 0;
		virtual TurnLiActCtrlInfo Get_TurnLiInfo() = 0;
		virtual FogActCtrlInfo Get_FogInfo() = 0;
		virtual ThrLiActCtrlInfo Get_ThrLiInfo() = 0;
		virtual LogoActCtrlInfo Get_LogoInfo() = 0;
		virtual uint8_t Get_LicenseInfo() = 0;
	};
    class Basc_ExtrLiActCtrlInfo_Skeleton :public Basc_ExtrLiActCtrlInfo_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_ExtrLiActCtrlInfo_Skeleton(Basc_ExtrLiActCtrlInfo_service_interface* service,std::string config="");
			bool init();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			PosnLiActCtrlInfo Get_PosnLiInfo() {
				return this->_service->Get_PosnLiInfo();
			}
			LoBeamActCtrlInfo Get_LoBeamInfo() {
				return this->_service->Get_LoBeamInfo();
			}
			HiBeamActCtrlInfo Get_HiBeamInfo() {
				return this->_service->Get_HiBeamInfo();
			}
			RvsLiActCtrlInfo Get_RvsLiInfo() {
				return this->_service->Get_RvsLiInfo();
			}
			DRLActCtrlInfo Get_DRLInfo() {
				return this->_service->Get_DRLInfo();
			}
			BrkLiActCtrlInfo Get_BrkLiInfo() {
				return this->_service->Get_BrkLiInfo();
			}
			TurnLiActCtrlInfo Get_TurnLiInfo() {
				return this->_service->Get_TurnLiInfo();
			}
			FogActCtrlInfo Get_FogInfo() {
				return this->_service->Get_FogInfo();
			}
			ThrLiActCtrlInfo Get_ThrLiInfo() {
				return this->_service->Get_ThrLiInfo();
			}
			LogoActCtrlInfo Get_LogoInfo() {
				return this->_service->Get_LogoInfo();
			}
			uint8_t Get_LicenseInfo() {
				return this->_service->Get_LicenseInfo();
			}
            dds_return_t send_reply(carControl_Car_Control_Reply* reply);
            events::Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo Ntf_PosnLiInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo Ntf_LoBeamInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo Ntf_HiBeamInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_RvsLiInfo Ntf_RvsLiInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_DRLInfo Ntf_DRLInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo Ntf_BrkLiInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo Ntf_TurnLiInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_FogInfo Ntf_FogInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_ThrLiInfo Ntf_ThrLiInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_LogoInfo Ntf_LogoInfo;
            events::Basc_ExtrLiActCtrlInfo_Ntf_LicenseInfo Ntf_LicenseInfo;


		private:
		    std::string _config;
			const std::string service_name="Basc_ExtrLiActCtrlInfo_skeleton";
			Basc_ExtrLiActCtrlInfo_service_interface * _service;

			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };
	};

}
}
}
}
}
#endif

