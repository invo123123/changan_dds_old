/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  AppVersion： soa_log-V1.1.1
  CmVersion： 1.1.217
  ServiceVersion: V1.1.1
  ServiceLatestModifyTime: 2023-08-21T11:31:03
  Generate Time: Aug 21, 2023 1:50:56 PM
*****************************************************************/
#ifndef logconfig_Proxy_HPP
#define logconfig_Proxy_HPP
#include <string.h>
#include <future>
#include <chrono>
#include "changan/common_data_types.h"
#include "changan/Common.h"
#include "changan/dds_util.h"
#include "dds/ddsrt/sync.h"
#include "changan/logconfig.h"
#include "changan/base_proxy.hpp"
#include "changan/base_wait.hpp"
#include "changan/dds_client.hpp"
#include <mutex>

namespace com {
namespace changan {
namespace soa_log {
namespace proxy {
	extern void on_carDrive_logconfig_reply_data_available(int32_t reader, void* arg);
	class logconfig_Proxy : IBaseProxy,IBaseWait, public ProviderMatchedStatusHandler{
		public:
		    static logconfig_Proxy& get_instance();
			bool init(std::string config="");
			void wait_server_online();
			bool destroy();
			DDS_GuidPrefix_t guid;
			Msg<std::string> SETSOALOG(const std::string &logLevel,const std::string &logDir) {
				return this->SETSOALOG<DEFAULT_TIMEOUT>(logLevel,logDir);
			}
			template<size_t TIMEOUT>
			Msg<std::string> SETSOALOG(const std::string &logLevel,const std::string &logDir) {
				return this->SETSOALOG(logLevel,logDir, TIMEOUT);
			}
			const std::string get_service_name() {
				return this->service_name;
			}

		private:
		    const std::string service_name = "logconfig_skeleton";
			Msg<std::string> SETSOALOG(const std::string &logLevel,const std::string &logDir, size_t dds_rpc_time_out);

			dds_rpc_handle_t dds_rpc_request_handle = {-1,-1,-1};
			dds_rpc_handle_t dds_rpc_reply_handle = { -1,-1,-1 };

            bool init_flag = false;
            std::mutex init_mutex;

			logconfig_Proxy();
			~logconfig_Proxy();

			logconfig_Proxy(const logconfig_Proxy& signal);

			const logconfig_Proxy& operator=(const logconfig_Proxy& signal);
	};
}
}
}
}
#endif

