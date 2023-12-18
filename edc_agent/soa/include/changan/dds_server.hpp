#ifndef DDS_SERVER_HPP
#define DDS_SERVER_HPP
#include <unordered_map>
#include "base_skeleton.hpp"
#include "threadpool.hpp"
#include "dds/ddsrt/environ.h"
#include "changan/logconfig_S.hpp"
namespace com {
	namespace changan {
		namespace rpc_service {
			class DDSServer
			{
			public:
                            static void run(std::string config_path="");
				static void register_service(IBaseSkeleton* service);
				static IBaseSkeleton* get_service(const std::string service_name);
				template<class F, class... Args>
				static void execute(F&& f, Args&&... args)
				{
                    _thread_pool.addThreadWhenFirst();
					_thread_pool.commit(f, args...);
				}
			private:
				static std::unordered_map<std::string, IBaseSkeleton*> _service_instances;
				static com::changan::threadpool _thread_pool;
				static std::mutex cb_mtx_;
			};
		}
	}
}

#endif // !DDS_SERVER_HPP


