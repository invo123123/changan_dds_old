#ifndef COMMON_DATA_TYPES
#define COMMON_DATA_TYPES
#include <functional>
#include "changan/rpc_types.h"
#include <string>
#include <memory>
#define MAX_SAMPLES 1
template <typename T>
class Msg {
public:
	T data = {0};
	DDS_RPC_RemoteExceptionCode_t  code= DDS_RPC_REMOTE_EX_UNKNOWN_EXCEPTION;
	std::shared_ptr<void> autoFreePtr;
	bool success() {
		return this->code == DDS_RPC_REMOTE_EX_OK;
	}
};

template <typename T>
using EventReceiveHandler = std::function<void(T)>;

typedef struct ProviderMatchedStatus{
	uint32_t total_count;
	uint32_t current_count = 0;
	std::string provider_id;
	volatile bool is_online;
} ProviderMatchedStatus;

typedef struct ConsumerMatchedStatus
{
  uint32_t total_count;
  uint32_t current_count = 0;
  std::string consumer_id;
  volatile bool is_online;
}
ConsumerMatchedStatus;

typedef struct ViuStatus {
	bool bOnline;
	bool preOnline;
	EventReceiveHandler<const ProviderMatchedStatus&> handler;
} ViuStatus;

typedef struct T_topicdata_bitmap{
	unsigned char topicdata_bitmap[1250];
	uint32_t topicdata_bitmap_len;
} T_topicdata_bitmap;

class ProviderMatchedStatusHandler{
public:
	void set_provider_matched_handler(EventReceiveHandler<const ProviderMatchedStatus&> handler){
		this->m_provider_matched_handler=handler;
	}
	const  EventReceiveHandler<const ProviderMatchedStatus&>  get_provider_matched_handler(){
		return this->m_provider_matched_handler;
	}
private:
	EventReceiveHandler<const ProviderMatchedStatus&> m_provider_matched_handler;
};

class ConsumerMatchedStatusHandler{
public:
	void set_consumer_matched_handler(EventReceiveHandler<const ConsumerMatchedStatus&> handler){
		this->m_consumer_matched_handler=handler;
	}
	const  EventReceiveHandler<const ConsumerMatchedStatus&>  get_consumer_matched_handler(){
		return this->m_consumer_matched_handler;
	}
private:
	EventReceiveHandler<const ConsumerMatchedStatus&> m_consumer_matched_handler;
};

#endif // !COMMON_DATA_TYPES


