#include "changan/dds_util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "changan/domain_factory.hpp"
#include "changan/string_util.hpp"
#include "changan/local_cache.hpp"
#include "qos_gen.h"
#include <changan/log_util.h>
#include <inttypes.h>
#include <sys/time.h>
#include <set>
#include <vector>


using namespace com::changan;

#define MAX_USERDATA_LEN 1024
#define MAX_NUM 50

lru::Cache<uint64_t,std::string> DDSUtil::provider_matched_id_cache(1000,100);
lru::Cache<uint64_t,std::string> DDSUtil::consumer_matched_id_cache(1000,100);

static int provideCount = 0;
static int consumeCount = 0;
static vector<int64_t> pVec;
static vector<int64_t> cVec;
char pbuf[MAX_NUM];
char cbuf[MAX_NUM];
char set_user_data[MAX_USERDATA_LEN-DDS_GUID_LENGTH] = {0};
char check_user_data[MAX_USERDATA_LEN-DDS_GUID_LENGTH] = {0};

const char * TOKEN_STR[MAX_TOKENS] = {
    "PROXY_TOKEN",  "DIRECT_MCU_TOKEN",  "LOCAL_MCU_TOKEN", "DIRECT_MCU_TOKEN,LOCAL_MCU_TOKEN"
};

int64_t get_ts() {
	struct timeval tv;
	if (gettimeofday(&tv, NULL) == -1) {
		return 0;
	}

	return (int64_t)(tv.tv_sec*1000+tv.tv_usec/1000);
}

bool do_not_set_userdata(dds_entity_t participant) {
    dds_qos_t * pqos = dds_create_qos ();
    if (NULL == pqos) {
        DDS_FATAL("dds_create_qos fail\n");
    }
    dds_return_t rc = dds_get_qos(participant, pqos);
    if (rc != DDS_RETCODE_OK) {
        dds_delete_qos(pqos);
        return true;
    }
    void * user_data = NULL;
    size_t lu = 0;
    dds_qget_userdata(pqos, &user_data, &lu);
    if (lu <= 0) {
        dds_delete_qos(pqos);
        return true;
    }
    dds_delete_qos(pqos);
    return false;
}

void set_userdata_qos(dds_entity_t participant, std::string setup_token) {
    dds_qos_t * pqos = dds_create_qos ();
    const char * set_user_data = setup_token.data();
    char udata[MAX_USERDATA_LEN]  = {0};
    dds_guid_t participant_guid = {0};
    if(0 != strlen(set_user_data))
    {
        dds_return_t rc = dds_get_guid(participant, &participant_guid);
        if (rc < 0)
            DDS_FATAL("dds_get_guid: %s\n", dds_strretcode(-rc));
        memcpy(udata, &participant_guid, DDS_GUID_LENGTH);
        strncpy(&udata[DDS_GUID_LENGTH], set_user_data, strlen(set_user_data));
        printf("set userdata = %s\n", udata+DDS_GUID_LENGTH);

        dds_qset_userdata (pqos, udata, DDS_GUID_LENGTH + strlen(udata+DDS_GUID_LENGTH)+1);
        dds_set_qos(participant, pqos);
    }
    dds_delete_qos(pqos);
}

bool on_userdata_checkable(int32_t entity, const uint8_t guid[DDS_GUID_LENGTH], const unsigned char* userdata_value, uint32_t userdata_len, void* arg)
{
  (void)entity;
  char* keydata = (char *)arg;
  printf("keydata =%p\n", keydata);
  uint32_t i;

  if(userdata_len < DDS_GUID_LENGTH)
  {
    printf("userdata_len(%d) should be larger than DDS_GUID_LENGTH(16)!\n", userdata_len);
    return false;
  }

  printf("GUID OF PARTICIPANT = ");
  for (i = 0; i < DDS_GUID_LENGTH; i++)
  {
    printf("%02x", guid[i]);
  }
  printf("\n");

  printf("GUID IN USERDATA = ");
  for (i = 0; i < DDS_GUID_LENGTH; i++)
  {
    printf("%02x", userdata_value[i]);
  }
  printf("\n");
  printf("KEY IN USERDATA    = %s\n", (char *)&userdata_value[DDS_GUID_LENGTH]);
printf("keydata    = %s\n", keydata);

  if(0 == memcmp(userdata_value, guid, DDS_GUID_LENGTH) && NULL != strstr(keydata, (const char*)&userdata_value[DDS_GUID_LENGTH]))
  {
    printf("======== Check USERDATA OK!!! ========\n");
    return true;
  }
  else
  {
    printf("======== Check USERDATA NoOK!!! ========\n");
    return false;
  }
}

bool DDSUtil::dds_rpc_client_guid_gen(dds_entity_t entity, DDS_GUID_t *guid)
{
    dds_guid_t temp_guid = {0};
    if (DDS_RETCODE_OK != dds_get_guid(entity, &temp_guid))
    {
        printf("dds_rpc_client_guid_gen failed!\n");
        return false;
    }
    memcpy(guid, &temp_guid, sizeof(dds_guid_t));
    return true;
}

bool DDSUtil::event_sub_init(uint32_t domain_id,
                             std::string topic_name, const dds_topic_descriptor_t *topic_desc,
                             dds_on_data_available_fn data_available_cb,
                             dds_topic_filter_arg_fn topic_filter_cb,  
                             dds_rpc_handle_t *handle,
                             dds_on_subscription_matched_fn subscription_matched_fn,
                             TokenEncapsulation token_encap,
                             ServiceIdEncapsulation service_id_encap,
                             std::string config,
                             void *arg
                             )
{
    dds_entity_t participant = -1;
    dds_entity_t topic = -1;
    dds_entity_t subscriber = -1;
    dds_entity_t reader = -1;
    //dds_entity_t waitset_rd = -1;
    //dds_subscription_matched_status_t status_rd = {0};
    //dds_return_t rc = DDS_RETCODE_ERROR;
    //dds_qos_t *qos = NULL;
    dds_listener_t *listener = NULL;
    const char * check_token_str = TOKEN_STR[token_encap.check_token];
    const char * setup_token_str = TOKEN_STR[token_encap.setup_token];
    dds_listener_t *plistener = NULL;

    qos_params* qps = get_qos_params(topic_name);

    printf("sub topic init\n");
    if(0 != strlen(check_token_str))
    {
        plistener = dds_create_listener(NULL);
        dds_lset_userdata_checkable_arg (plistener, on_userdata_checkable, (void*)check_token_str, false);
    }
    if (handle->participant < 0)
    {
        
        /* Create a Participant. */
        participant = DomainFactory::create_participant(domain_id, token_encap.setup_token, config, plistener);
        if (do_not_set_userdata(participant)) {
            set_userdata_qos(participant, setup_token_str);
        }
    }
    else
    {
        participant = handle->participant;
    }
    if (participant < 0)
        printf("dds_create_participant: %s\n", dds_strretcode(-participant));

    printf("sub topic: %s\n", topic_name.data());
    /* Create a Request Topic. */
    dds_qos_t* tqos = dds_create_qos ();
    dds_qset_topicdata (tqos, service_id_encap.service_ids, service_id_encap.service_num);
    topic = dds_create_topic(
        participant, topic_desc, (char *)topic_name.data(), tqos, NULL);
    delete_qos(tqos);
    
    if (topic < 0)
        printf("dds_create_topic: %s\n", dds_strretcode(-topic));

    if (NULL != topic_filter_cb)
    {  
        if(0 == memcmp(token_encap.partitions.data(), "ntf", 3) )
        {
            dds_topic_set_filter_serdata(topic,(dds_topic_filter_special_fn)topic_filter_cb);
        }
        else if(0 == memcmp(token_encap.partitions.data(), "*rpc", 4) )
        {
            dds_set_topic_filter_and_arg (topic , topic_filter_cb, (void*)arg);
        }
        else
        {
            printf("invalid  topic  filter   %s\n", token_encap.partitions.data());
        }
    }
    //-----------------------------------------------------------------------
    /*Create a subscriber*/
    dds_qos_t* subscriber_qos = dds_create_qos();
    if(0 < token_encap.partitions.length())
    {
        const char * p_data_str = token_encap.partitions.data();
        dds_qset_partition(subscriber_qos, 1, &p_data_str);
    }
    subscriber = dds_create_subscriber(participant, subscriber_qos, NULL);
    delete_qos(subscriber_qos);
    if (subscriber < 0)
        printf("dds_create_subscriber: %s\n", dds_strretcode(-subscriber));

    /* Create a reliable Reader. */
    //qos = dds_create_qos();
    //dds_qset_reliability(qos, DDS_RELIABILITY_RELIABLE, DDS_SECS(10));
    // if(isSupportListener)
   // void * topic_name_arg= (void *)topic_name.data();
    listener = dds_create_listener((void*)arg);

    if (NULL != data_available_cb)
    {
        dds_lset_data_available(listener, data_available_cb);
    }
    if (NULL != subscription_matched_fn)
    {
        dds_lset_subscription_matched(listener, subscription_matched_fn);
    }
    if(!qps){
        dds_qos_t* qos = dds_create_qos();
        //与VIU直链，不通过SOA_Proxy的NTF的服务，qos设置为：尽力而为
        if ((strstr(TOKEN_STR[DIRECT_AND_LOCAL_VIU_TOKEN], setup_token_str) != NULL)
        &&(strstr(token_encap.partitions.data(), "ntf") != NULL)
        &&(strstr(topic_name.data(),"_mcu_notify")))
        {
            dds_qset_reliability(qos, DDS_RELIABILITY_BEST_EFFORT, DDS_SECS(1));
        }
        else
        {
            dds_qset_reliability(qos, DDS_RELIABILITY_RELIABLE, DDS_SECS(10));
        }
        dds_qset_history(qos, DDS_HISTORY_KEEP_ALL, 0);
        reader = dds_create_reader(subscriber, topic, qos, listener);
        dds_delete_qos(qos);
    }
    else{
        dds_qos_t* reader_qos = create_reader_qos(qps);
        reader = dds_create_reader(subscriber, topic, reader_qos, listener);
        delete_qos(reader_qos);
    }

    if (reader < 0)
        printf("dds_create_reader: %s\n", dds_strretcode(-reader));
    //dds_delete_qos(qos);
    //----------------------------------------------------------------------

    /*rc = dds_set_status_mask(reader, DDS_SUBSCRIPTION_MATCHED_STATUS);
    if (rc != DDS_RETCODE_OK)
        printf("dds_set_status_mask: %s\n", dds_strretcode(-rc));*/

    // waitset_rd = dds_create_waitset(participant);
    // if (waitset_rd < 0)
    //     printf("dds_create_waitset: %s\n", dds_strretcode(-waitset_rd));

    // rc = dds_waitset_attach(waitset_rd, reader, (dds_attach_t)NULL);
    // if (rc < 0)
    //     printf("dds_waitset_attach: %s\n", dds_strretcode(-rc));

    // while (true) {
    //	 // 2)
    // rc = dds_get_subscription_matched_status(reader, &status_rd);
    // printf("==,%d,current_count:%d,total_count:%d\n", rc,status_rd.current_count, status_rd.total_count);
    // if ( rc!= DDS_RETCODE_OK)
    // {
    //     printf("get_publication_matched_status or get_subscription_matched_status failed!\n");
    //     goto RPC_INIT_FAILURE;
    // }

    // if (matches.current_count >= 1) {
    //	 break;
    // }
    // 3)
    /* if ((rc = dds_waitset_wait(waitset_rd, NULL, 0, DDS_SECS(10))) < 0)
         printf("dds_waitset_wait: %s\n", dds_strretcode(-rc));
     else
         dds_waitset_detach(waitset_rd, reader);*/
    //-------------------------------------------------------------------------------
    printf("sub topic init done\n");
    goto RPC_INIT_OK;

RPC_INIT_OK:
    handle->participant = participant;
    handle->reader = reader;
    return true;

// RPC_INIT_FAILURE:
//     handle->participant = -1;
//     handle->writer = -1;
//     handle->reader = -1;
//     return false;
}
bool DDSUtil::event_pub_init(uint32_t domain_id,
                             std::string topic_name, const dds_topic_descriptor_t *topic_desc,
                             dds_rpc_handle_t *handle,
                             dds_on_publication_matched_fn publication_matched_cb,
                             TokenEncapsulation token_encap,
                             std::string config,
                             dds_on_topicdata_checkable_fn topicdata_checkable_fn)
{
    dds_entity_t participant = -1;
    dds_entity_t writer = -1;
    dds_entity_t topic_req = -1;
    dds_entity_t publisher = -1;
    //dds_entity_t waitset_wr = -1;
    //dds_publication_matched_status_t status_wr = {0};
    //dds_return_t rc = DDS_RETCODE_ERROR;
    const char * check_token_str = TOKEN_STR[token_encap.check_token];
    const char * setup_token_str = TOKEN_STR[token_encap.setup_token];
    printf("check_user_data=%s\n", check_token_str);
    dds_listener_t *plistener = NULL;
    //dds_qos_t *qos = NULL;

    qos_params* qps = get_qos_params(topic_name);

    printf("pub topic start init\n");
    if(0 != strlen(check_token_str))
    {
        plistener = dds_create_listener(NULL);
        dds_lset_userdata_checkable_arg (plistener, on_userdata_checkable, (void *)check_token_str, false);
    }
    if (handle->participant < 0)
    {
        /* Create a Participant. */
        participant = DomainFactory::create_participant(domain_id,  token_encap.setup_token, config, plistener);
        if (do_not_set_userdata(participant)) {
            set_userdata_qos(participant, setup_token_str);
        }
    }
    else
    {
        participant = handle->participant;
    }
    if (participant < 0)
    {
        printf("dds_create_participant: %s\n", dds_strretcode(-participant));
    }


    /* Create a Request Topic. */
    dds_qos_t* topic_qos = create_topic_qos(qps);
    topic_req = dds_create_topic(participant, topic_desc, (char *)topic_name.data(), topic_qos, NULL);
    delete_qos(topic_qos);
    if (topic_req < 0)
    {
        printf("dds_create_topic: %s\n", dds_strretcode(-topic_req));
    }
    /* Set topic filter*/

    //-----------------------------------------------------------------

    /*Create a publisher*/
    dds_qos_t* publisher_qos = dds_create_qos();
    if(0 < token_encap.partitions.length())
    {
        const char * p_data_str = token_encap.partitions.data();
        dds_qset_partition(publisher_qos, 1, &p_data_str);
    }
    publisher = dds_create_publisher(participant, publisher_qos, NULL);
    delete_qos(publisher_qos);
    if (publisher < 0)
    {
        printf("dds_create_publisher: %s\n", dds_strretcode(-publisher));
    }

    /* Create a Writer. */
    //qos = dds_create_qos();
    //dds_qset_reliability(qos, DDS_RELIABILITY_RELIABLE, DDS_SECS(10));
    // dds_qset_history(qos, DDS_HISTORY_KEEP_ALL, 100);
	dds_qos_t* writer_qos;
	if(!qps){
		writer_qos = dds_create_qos();
		dds_qset_reliability(writer_qos, DDS_RELIABILITY_RELIABLE, DDS_SECS(10));
		dds_qset_history(writer_qos, DDS_HISTORY_KEEP_ALL, 0);
	} else {
		writer_qos = create_writer_qos(qps);
	}

	dds_listener_t* listener_w = NULL;
    if (NULL != publication_matched_cb || NULL != topicdata_checkable_fn)
    {
        listener_w = dds_create_listener(NULL);
    }

    if (NULL != publication_matched_cb) {
    	dds_lset_publication_matched(listener_w, publication_matched_cb);
    }

    if (NULL != topicdata_checkable_fn) {
    	dds_lset_topicdata_checkable(listener_w, topicdata_checkable_fn);
    }

    writer = dds_create_writer(publisher, topic_req, writer_qos, listener_w);

    delete_qos(writer_qos);

    if (writer < 0)
    {
        printf("dds_create_writer: %s\n", dds_strretcode(-writer));
    }
    //dds_delete_qos(qos);

    //------------------------------------------------------------------
    /* Create a reliable Reader. */

    //-------------------------------------------------

    // Prepare waitset for peer reader
    // rc = dds_set_status_mask(writer, DDS_PUBLICATION_MATCHED_STATUS);
    // if (rc != DDS_RETCODE_OK) {
    //     printf("dds_set_status_mask: %s\n", dds_strretcode(-rc));
    // }

    // waitset_wr = dds_create_waitset(participant);
    // if (waitset_wr < 0) {
    //     printf("dds_create_waitset: %s\n", dds_strretcode(-waitset_wr));
    // }
    // rc = dds_waitset_attach(waitset_wr, writer, (dds_attach_t)NULL);
    // if (rc < 0) {
    //     printf("dds_waitset_attach: %s\n", dds_strretcode(-rc));
    // }
    // //-----------------------------------------------------------------

    // if (dds_get_publication_matched_status(writer, &status_wr) != DDS_RETCODE_OK) {
    //     printf("get_publication_matched_status or get_subscription_matched_status failed!\n");
    // }

    // Block until peer(server) is available
    /* if ((rc = dds_waitset_wait(waitset_wr, NULL, 0, DDS_SECS(10))) < 0) {
         printf("dds_waitset_wait: %s\n", dds_strretcode(-rc));
     }
     else {
         dds_waitset_detach(waitset_wr, writer);
     }*/
    printf("pub topic create done\n");
    handle->participant = participant;
    handle->writer = writer;
    return true;
}

dds_return_t DDSUtil::send(dds_entity_t writer, const void *data)
{
    return dds_write(writer, data);
}

bool DDSUtil::dds_client_destroy(dds_rpc_handle_t *handle)
{
    dds_return_t rc;

    assert(NULL != handle);

    // Clean-up!
    // Deleting the participant will delete all its children recursively as well.
    //目前一个domainId一个participant，如果只是为了注销某个服务，不需要把整个participant给删除，否则其余服务无法通信
	// rc = dds_delete(handle->participant);
    // if (rc != DDS_RETCODE_OK)
    // {
    //     printf("dds_delete: %s\n", dds_strretcode(-rc));
    //     return false;
    // }
    // else
    // {
    //     handle->participant = -1;
    //     handle->writer = -1;
    //     handle->reader = -1;
    //     return true;
    // }
    if (handle->writer != -1) {
         auto r = dds_delete(handle->writer);
         if (r != DDS_RETCODE_OK) {
             log_error("dds_delete writer %d ret %d\n",
                 handle->writer, r);
             return false;
         }

         handle->writer = -1;
     }
     if(handle->reader != -1) {
        auto r = dds_delete(handle->reader);
        if (r != DDS_RETCODE_OK) {
            log_error("dds_delete reader %d ret %d\n",
                handle->reader, r);
            return false;
        }
        handle->reader = -1;
    }
    return true;
}

ProviderMatchedStatus DDSUtil::get_provider_matched_status(dds_entity_t writer, const dds_publication_matched_status_t &status)
{
    provideCount += 1;
    int64_t times = get_ts();
	pVec.push_back(times);
    std::string timeStr;
	for(vector<int64_t>::iterator it =pVec.begin();it!=pVec.end();)
	{
		sprintf(pbuf,"%lld",*it);
		timeStr += pbuf;
		timeStr += " ";
		it++;
		memset(pbuf,0,MAX_NUM);
	}
	log_info("get_provider_matched_status providerCount=%d, total_count=%d, current_count=%d,current_time=%lld, all_time=%s", provideCount, status.total_count, status.current_count,times, timeStr.c_str());

    ProviderMatchedStatus data;
    data.total_count = status.total_count;
    data.current_count = status.current_count;
    data.is_online=status.current_count>0;
    if (status.current_count > 0 && status.current_count_change > 0)
    {
        dds_builtintopic_endpoint_t *sub_data = dds_get_matched_subscription_data(writer, status.last_subscription_handle);
        if (sub_data != NULL)
        {
            data.provider_id = StringUtil::uint8_to_hex_string(sub_data->key.v, 16);
           provider_matched_id_cache.insert(status.last_subscription_handle, data.provider_id);
        }
    }
    if(status.current_count_change<0){
        provider_matched_id_cache.try_get(status.last_subscription_handle,data.provider_id);
        provider_matched_id_cache.remove(status.last_subscription_handle);
    }
    return data;
}
ConsumerMatchedStatus DDSUtil::get_consumer_matched_status(dds_entity_t reader, const dds_subscription_matched_status_t &status)
{
	consumeCount += 1;
    int64_t times = get_ts();
	cVec.push_back(times);
    std::string timeStr;
	for(vector<int64_t>::iterator it =cVec.begin();it!=cVec.end();)
	{
		sprintf(cbuf,"%lld",*it);
		timeStr += cbuf;
		timeStr += " ";
		it++;
        memset(cbuf,0,MAX_NUM);
	}
	log_info("get_consumer_matched_status cosumeCount=%d, total_count=%d, current_count=%d,current_time=%lld, all_time=%s", consumeCount, status.total_count, status.current_count,times, timeStr.c_str());
	
    ConsumerMatchedStatus data;
    data.total_count = status.total_count;
    data.current_count = status.current_count;
    data.is_online=status.current_count>0;
    if (status.current_count > 0 && status.current_count_change > 0)
    {
        dds_builtintopic_endpoint_t *pub_data = dds_get_matched_publication_data(reader, status.last_publication_handle);
        if (pub_data != NULL)
        {
            data.consumer_id = StringUtil::uint8_to_hex_string(pub_data->key.v, 16);
            consumer_matched_id_cache.insert(status.last_publication_handle, data.consumer_id);
        }
    }
    if(status.current_count_change<0){
        consumer_matched_id_cache.try_get(status.last_publication_handle,data.consumer_id);
        consumer_matched_id_cache.remove(status.last_publication_handle);
    }
    return data;
}