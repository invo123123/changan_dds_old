#ifndef CHANGAN_DDS_UTIL_HPP
#define CHANGAN_DDS_UTIL_HPP

#include "asf/logging/logsdk.h"
#include "changan/soa_log.h"

#include "dds/dds.h"
#include "rpc_types.h"
#include "changan/common_data_types.h"
#include <string>
#include "changan/local_cache.hpp"
#include "changan/link_count.h"

enum TOKEN {
    PROXY_TOKEN,
    DIRECT_VIU_TOKEN, 
    LOCAL_VIU_TOKEN,
    DIRECT_AND_LOCAL_VIU_TOKEN,
    MAX_TOKENS
};

typedef struct TokenEncapsulation
{
    TOKEN setup_token;
    TOKEN check_token;
    std::string partitions;
} TokenEncapsulation;

typedef struct ServiceIdEncapsulation
{
    int service_num;
    uint8_t * service_ids;
} ServiceIdEncapsulation;


class DDSUtil {
public:
    static bool dds_rpc_client_guid_gen(dds_entity_t entity, DDS_GUID_t* guid);
    static bool event_sub_init(uint32_t domain_id,
        std::string topic_name, const dds_topic_descriptor_t* topic_desc,
        dds_on_data_available_fn data_available_cb,
         dds_topic_filter_arg_fn topic_filter_cb, 
         dds_rpc_handle_t* handle,
         dds_on_subscription_matched_fn subscription_matched_fn=NULL,
         TokenEncapsulation token_encap = {},
         ServiceIdEncapsulation service_id_encap = {},
         std::string config="",
         void *arg=NULL);
    static bool event_pub_init(uint32_t domain_id,
        std::string topic_name, const dds_topic_descriptor_t* topic_desc, 
        dds_rpc_handle_t* handle,
        dds_on_publication_matched_fn  publication_matched_fn=NULL,
        TokenEncapsulation token_encap = {},
        std::string config="",
        dds_on_topicdata_checkable_fn topicdata_checkable_fn=NULL);

    static dds_return_t send(dds_entity_t writer, const void* data);
    static bool dds_client_destroy(dds_rpc_handle_t* handle);
    static ProviderMatchedStatus get_provider_matched_status(dds_entity_t writer, const dds_publication_matched_status_t &status);
    static ConsumerMatchedStatus get_consumer_matched_status(dds_entity_t reader, const dds_subscription_matched_status_t &status);
    
private:
    static lru::Cache<uint64_t,std::string> provider_matched_id_cache;
    static lru::Cache<uint64_t,std::string> consumer_matched_id_cache;
};
#endif // DDS_UTIL_HPP

