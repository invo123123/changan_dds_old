#include "changan/dds_client.hpp"
#include "changan/global_config.hpp"
namespace com
{
	namespace changan
	{
		namespace rpc_service
		{
			DDS_SequenceNumber_t DDSClient::rpc_request_id = {0, 0};
			std::mutex DDSClient::cb_mtx_;
			std::unordered_map<std::uint64_t, std::shared_ptr<std::promise<std::shared_ptr<void>>>>
				DDSClient::future_map_;
			com::changan::threadpool DDSClient::_thread_pool(DEFAULT_CLIENT_THREAD_NUM);
			const DDS_SequenceNumber_t DDSClient::get_rpc_request_id()
			{
				std::unique_lock<std::mutex> lock(cb_mtx_);
				DDSClient::rpc_request_id.low++;
				return DDSClient::rpc_request_id;
			}
			void DDSClient::release(uint64_t fu_id, std::shared_ptr<void>&value)
			{
				std::unique_lock<std::mutex> lock(cb_mtx_);
				auto it = future_map_.find(fu_id);
//				std::cout << "rpc id:" << fu_id << " return" << std::endl;
				if (it == future_map_.end())
				{
					// assert("duplicated subscribe");
					return;
				}
				future_map_[fu_id]->set_value(value);
				future_map_.erase(fu_id);
			}
			std::future<std::shared_ptr<void>> DDSClient::async_call(uint64_t fu_id, dds_entity_t writer, const void* data)
			{
				auto p = std::make_shared<std::promise<std::shared_ptr<void>>>();
				std::future<std::shared_ptr<void>> future = p->get_future();
				{
					std::unique_lock<std::mutex> lock(cb_mtx_);
					future_map_.emplace(fu_id, std::move(p));
				}
				DDSUtil::send(writer, data);
				return future;
			}
			void DDSClient::init_from_config(std::string config_path)
			{
				if (!config_path.empty())
				{
					ddsrt_setenv("AUTOCOREDDS_URI", config_path.data());
				}
			}
		}
	}
}
