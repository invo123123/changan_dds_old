/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： mADC_Application_Service-V1.5
  CmVersion： v2.0.3
  ServiceVersion: V1.0.2
  ServiceLatestModifyTime: 2023-06-07T19:58:47
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef Basc_RemoteMove_SKELETON_HPP
#define Basc_RemoteMove_SKELETON_HPP
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
#include "changan/Basc_RemoteMove.h"
#include "changan/base_skeleton.hpp"
#include "changan/base_wait.hpp"
#include <iostream>
#include <string.h>
#include <mutex>
namespace com {
namespace changan {
namespace carCabin {
namespace remoteMove {
namespace skeleton {
	extern void on_carCabin_Basc_RemoteMove_request_data_available(int32_t reader, void* arg);

	class Basc_RemoteMove_service_interface {
	public:
	    virtual ~Basc_RemoteMove_service_interface() = default;

		virtual uint8_t RR_ScreenCoordinate(const uint32_t &Xapp,const uint32_t &Yapp) = 0;
		virtual uint8_t RR_FunSwitch(const uint8_t &State,const std::string &RoomId) = 0;
	};
    class Basc_RemoteMove_Skeleton :public Basc_RemoteMove_service_interface, public IBaseWait,public IBaseSkeleton,public ConsumerMatchedStatusHandler{
		public:
			Basc_RemoteMove_Skeleton(Basc_RemoteMove_service_interface* service,std::string config="");
			bool init();
			bool destroy();
			void wait_client_online();
            const std::string get_service_name() {
				return this->service_name;
			}
			uint8_t RR_ScreenCoordinate(const uint32_t &Xapp,const uint32_t &Yapp) {
				return this->_service->RR_ScreenCoordinate(Xapp,Yapp);
			}
			uint8_t RR_FunSwitch(const uint8_t &State,const std::string &RoomId) {
				return this->_service->RR_FunSwitch(State,RoomId);
			}
            dds_return_t send_reply(carCabin_Basc_RemoteMove_Reply* reply);

		private:
		    std::string _config;
			bool init_flag=false;
			std::mutex init_mutex;

			const std::string service_name="Basc_RemoteMove_skeleton";
			Basc_RemoteMove_service_interface * _service;
			dds_rpc_handle_t dds_rpc_request_handle= { -1, -1, -1 };
			dds_rpc_handle_t dds_rpc_reply_handle= { -1, -1, -1 };

	};

}
}
}
}
}
#endif

