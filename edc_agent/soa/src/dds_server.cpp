#include "changan/dds_server.hpp"
#include <iostream>
#include "changan/global_config.hpp"
namespace com
{
	namespace changan
	{
		namespace rpc_service
		{
			std::unordered_map<std::string, IBaseSkeleton *> DDSServer::_service_instances;
			com::changan::threadpool DDSServer::_thread_pool(DEFAULT_SERVER_THREAD_NUM);
			std::mutex DDSServer::cb_mtx_;
			void DDSServer::run(std::string config_path)
			{
				if (!config_path.empty())
				{
					ddsrt_setenv("AUTOCOREDDS_URI", config_path.data());
				}
				for (const auto &it : _service_instances)
				{
					std::cout << "service :" << it.first << " start init" << std::endl;
					it.second->init();
					std::cout << "service :" << it.first << " end init" << std::endl;
				}
			}
			IBaseSkeleton *DDSServer::get_service(const std::string service_name)
			{
				auto it = _service_instances.find(service_name);
				if (it == _service_instances.end()){
					return NULL;
				}
				return it->second;
			}
			void DDSServer::register_service(IBaseSkeleton *service)
			{
				_service_instances[service->get_service_name()] = service;
			}
		}
	}
}