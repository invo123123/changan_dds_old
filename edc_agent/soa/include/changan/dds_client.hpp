#ifndef DDS_CLIENT_HPP
#define DDS_CLIENT_HPP
#include <unordered_map>
#include <future>
#include <mutex>
#include "changan/common_data_types.h"
#include "changan/dds_util.h"
#include "threadpool.hpp"
#include <iostream>
#include "dds/ddsrt/environ.h"
#include "changan/logconfig_S.hpp"
namespace com {
	namespace changan {
		namespace rpc_service {
			class DDSClient {
			public:
				static const DDS_SequenceNumber_t get_rpc_request_id();
				static void release(uint64_t fu_id, std::shared_ptr<void>& value);
				static std::future<std::shared_ptr<void>> async_call(uint64_t fu_id, dds_entity_t writer, const void* data);
				template<class F, class... Args>
				static void execute(F&& f, Args&&... args)
				{
				    _thread_pool.addThreadWhenFirst();
					_thread_pool.commit(f, args...);
					//std::cout << "thread idl:" << _thread_pool.idlCount() <<" thrCount"<< _thread_pool.thrCount() <<" taskCount"<< _thread_pool.taskCount() << std::endl;
				}
				static void init_from_config(std::string config);
			private:
				static DDS_SequenceNumber_t rpc_request_id;
				static std::mutex cb_mtx_;
				static std::unordered_map<std::uint64_t, std::shared_ptr<std::promise<std::shared_ptr<void>>>>
					future_map_;
				static com::changan::threadpool _thread_pool;
			};
		}
	}
}
#endif // !DDS_CLIENT_HPP
