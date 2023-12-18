#include "Rpc.h"
#include "dds_server.hpp"
#include "business_util.h"
#include "dds/dds.h"
#include "dds/ddsrt/sync.h"
#include "dds_util.h"

extern dds_rpc_handle_t  Domainid0_handle;
extern dds_rpc_handle_t  Domainid1_handle; 


static bool operator < (const ServiceInterface& si1, const ServiceInterface& si2) {
	if (si1.serviceName < si2.serviceName) {
		return true;
	}
	else if (si1.serviceName > si2.serviceName) {
		return false;
	}
	else {
		return si1.hashId < si2.hashId;
	}
}

void CRpcClient::Init(std::string config) {

	rpc_param rp;

	rp.request.participant=Domainid0_handle.participant;

	for (auto it =m_config.skeletons.client.begin();it!=m_config.skeletons.client.end();it++ ){

		string skeleton_name  = it->first ;

		const dds_topic_descriptor_t* pRequestDesc = GetDesc(it->second.request_topic_name);
		if (!pRequestDesc) {
			//printf("CRpcClient::Init GetDesc(%s) NULL\n",
			//	it->second.request_topic_name.c_str());
			continue;
		}

		const dds_topic_descriptor_t* pReplyDesc = GetDesc(it->second.reply_topic_name);
		if (!pReplyDesc) {
			//printf("CRpcClient::Init GetDesc(%s) NULL\n",
			//	it->second.reply_topic_name.c_str());
			continue;
		}
		m_rps[skeleton_name] = rp;
		

		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			it->second.request_topic_name,
			pRequestDesc,
			&m_rps[skeleton_name].request,
            NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},
			config
		);

		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			it->second.reply_topic_name,
			pReplyDesc,
			&OnReplyDataAvailable,
			NULL,
			&m_rps[skeleton_name].request,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config,
			(string *)&it->first
		);

	}
}

void CRpcClient::OnReplyDataAvailable(int32_t reader, void* arg) {

	//printf("get data CRpcClient %s !!!!!!!!!!\n",((string *)arg)->c_str());
	
	if(arg ==NULL)
		return;
	auto it = m_config.skeletons.client.find(((string *)arg)->c_str());
	if (it == m_config.skeletons.client.end()) {
		// printf("CRpcClient::OnReplyDataAvailable m_config.skeletons.find %s failed\n",
		// 	((string *)arg)->c_str());
		return;
	}

	const dds_topic_descriptor_t* pDesc = GetDesc(it->second.reply_topic_name);
	if (!pDesc) {
		// printf("CRpcClient::OnReplyDataAvailable %s GetDesc(%s) NULL\n",
		// 	((string *)arg)->c_str(), it->second.reply_topic_name.c_str());
		return;
	}

	dds_return_t rc;
	void* samples[MAX_SAMPLES];
	dds_sample_info_t infos[MAX_SAMPLES];
	samples[0] = dds_alloc(pDesc->m_size);



	rc = dds_take_next(reader, samples, infos);
	if (rc < 0) {
		// printf("CRpcClient::OnReplyDataAvailable %s dds_take_next failed!\n",
		// 	((string *)arg)->c_str();
		dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
		return ;
	}
	//printf("CRpcClient::OnReplyDataAvailable1 = %s  ,reply_topic_name1 =%s  \n",((string *)arg)->c_str(),it->second.reply_topic_name.c_str());
	
	if (infos[0].valid_data) {
		void* reply = samples[0];
		auto sp = std::shared_ptr<void>{
			samples[0],
			[=](void* ptr) {
				
				dds_sample_free(ptr, pDesc, DDS_FREE_ALL);
				//dds_free(ptr);
			}
		};
		int32_t funID = *(int32_t*)((uint8_t*)reply + GetOfs_RpcReplyData_d(pDesc));

		if (it->second.hash_ids.find(funID) != it->second.hash_ids.end()) {

			uint64_t key = (uint64_t)*(uint32_t*)((uint8_t*)reply + GetOfs_RpcReplyHeaderLow(funID));
			com::changan::rpc_service::DDSClient::release(key, sp);
		}
		else {
			uint64_t key = (uint64_t)*(uint32_t*)((uint8_t*)reply + GetOfs_RpcReplyHeaderLow(funID));
			com::changan::rpc_service::DDSClient::release(key, sp);
		}
	}
	else
	{
		dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
	}

}

map<ServiceInterface, HandleRequest> CRpcServer::m_hrs;

void CRpcServer::Init(std::string config) {

	rpc_param rp;
	
	rp.reply.participant=Domainid0_handle.participant;

	for (auto it =m_config.skeletons.server.begin();it!=m_config.skeletons.server.end();it++ ){


		string skeleton_name  = it->first ;

		const dds_topic_descriptor_t* pRequestDesc = GetDesc(it->second.request_topic_name);
		if (!pRequestDesc) {
			printf("CRpcServer::Init GetDesc(%s) NULL\n",
				it->second.request_topic_name.c_str());
			continue;
		}

		const dds_topic_descriptor_t* pReplyDesc = GetDesc(it->second.reply_topic_name);
		if (!pReplyDesc) {
			printf("CRpcServer::Init GetDesc(%s) NULL\n",
				it->second.reply_topic_name.c_str());
			continue;
		}

		m_rps[skeleton_name] = rp;
		
		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			it->second.reply_topic_name,
			pReplyDesc,
			&m_rps[skeleton_name].reply,
			NULL,
			{PROXY_TOKEN, PROXY_TOKEN,""},
			config
		);
	
		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			it->second.request_topic_name,
			pRequestDesc,
			&OnRequestDataAvailable,
			NULL,
			&m_rps[skeleton_name].reply,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config,
			(string *)&it->first
		);	
	}
}

void CRpcServer::Reply( int32_t hashId, HandleRequest hr) {

	for (auto it =m_config.skeletons.server.begin();it!=m_config.skeletons.server.end();it++ ){
		if(it->second.hash_ids.find(hashId)== it->second.hash_ids.end() )
		{
			// printf("CRpcServer::Handle %s it->second.hash_ids.find(%d) failed\n",
			// 	it->first.c_str(), hashId);
			// return;
			continue;

		}
		else
		{
			string skeleton_name  = it->first ;
			ServiceInterface si;
			printf("CRpcServer::Reply skeleton_name=%s, hashId=%d\n", skeleton_name.data(),hashId );
			si.serviceName = skeleton_name;
			si.hashId = hashId;
			m_hrs[si] = hr;
		}
	}
}

void CRpcServer::OnRequestDataAvailable(int32_t reader, void* arg) {
	if(arg ==NULL)
		return;
	auto it = m_config.skeletons.server.find(((string *)arg)->c_str());
	if (it == m_config.skeletons.server.end()) {
		//printf("CRpcServer::OnRequestDataAvailable m_config.skeletons.find %s failed\n",
		//	((string *)arg)->c_str());
		return;
	}

	auto itRp = m_rps.find(((string *)arg)->c_str());
	if (itRp == m_rps.end()) {
		//printf("CRpcServer::OnRequestDataAvailable m_rps.find %s failed\n",
		//	((string *)arg)->c_str());
		return;
	}

	const dds_topic_descriptor_t* pRequestDesc = GetDesc(it->second.request_topic_name);
	if (!pRequestDesc) {
		//printf("CRpcServer::OnRequestDataAvailable %s GetDesc(%s) NULL\n",
		//	((string *)arg)->c_str(), it->second.request_topic_name.c_str());
		return;
	}

	const dds_topic_descriptor_t* pReplyDesc = GetDesc(it->second.reply_topic_name);
	if (!pReplyDesc) {
		//printf("CRpcServer::OnRequestDataAvailable %s GetDesc(%s) NULL\n",
		//	((string *)arg)->c_str(), it->second.reply_topic_name.c_str());
		return;
	}

	dds_return_t rc;
	printf("CRpcServer::OnRequestDataAvailable %s RPC server on data available!\n",(const char*)arg);
	void* samples[1];
	samples[0] = dds_alloc(pRequestDesc->m_size);
	dds_sample_info_t infos[1];
	rc = dds_take_next(reader, samples, infos);
	if (rc < 0){
		// DDS_FATAL("CRpcServer::OnRequestDataAvailable %s dds_take_next failed!\n",
		// ((string *)arg)->c_str());
		dds_sample_free(samples[0], pRequestDesc, DDS_FREE_ALL);
		return ;
	}

	if (infos[0].valid_data)
	{
		void* request = samples[0];
		int32_t funID = *(int32_t*)((uint8_t*)request + GetOfs_RpcRequestData_d(pRequestDesc));

		if (it->second.hash_ids.find(funID) != it->second.hash_ids.end()) {
			DDSServer::execute(
				OnRequest,
				request,
				itRp->second.reply.writer,
				pRequestDesc,
				pReplyDesc,
				((string *)arg)->c_str(),
				funID);
		}
		else {
			//printf("else\n");
			DDSServer::execute(
				OnRequestDef,
				request,
				itRp->second.reply.writer,
				pRequestDesc,
				pReplyDesc);
		}
	}
	else
	{
		dds_sample_free(samples[0], pRequestDesc, DDS_FREE_ALL);//yehuan insert
	}
}

void CRpcServer::OnRequest(
	void* request,
	dds_entity_t writer,
	const dds_topic_descriptor_t* requestDesc,
	const dds_topic_descriptor_t* replyDesc,
	string skeletonName,
	int32_t hashId) {
	ServiceInterface si;
	si.serviceName = skeletonName;
	si.hashId = hashId;

	auto it = m_hrs.find(si);
	if (it == m_hrs.end()) {
		// printf("CRpcServer::OnRequest m_hrs.find(%s, %d) failed\n",
		// 	skeletonName.c_str(), hashId);
		dds_sample_free(request, requestDesc, DDS_FREE_ALL);
		return;
	}

	HandleRequest hr = it->second;	
	if (hr) {
		void* reply_msg= dds_alloc(replyDesc->m_size);
		memcpy((uint8_t*)reply_msg + GetOfs_RpcReplyHeaderRelatedRequestId(hashId),
			(uint8_t*)request + GetOfs_RpcRequestHeaderRequestId(hashId),
			sizeof(DDS_SampleIdentity));
		*(int32_t*)((uint8_t*)reply_msg + GetOfs_RpcReplyData_d(replyDesc)) = hashId;
		

		funtransform itReq =get_transform(hashId); 
		if(itReq.is_found)
		{  
			void*   message_buf;
			size_t  requestSize;
			size_t  replaySize;
			DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;
	
			itReq.in_type2pb((uint8_t*)request + GetOfs_RpcRequestData_uUnknownOp(hashId), &message_buf , &requestSize);

			void* reply_data=NULL; //= (void*)malloc((replyDesc->m_size -GetOfs_RpcReplyData_uUnknownOp(hashId) ));

			hr(hashId,message_buf,requestSize, &reply_data,replaySize,errorCode);

			*(DDS_RPC_RemoteExceptionCode_t*)((uint8_t*)reply_msg + GetOfs_RpcReplyHeaderRemoteEx(hashId)) = errorCode;

			if(errorCode == DDS_RPC_REMOTE_EX_OK )
				itReq.out_pb2type((const void *)reply_data, replaySize, (uint8_t*)reply_msg + GetOfs_RpcReplyData_uUnknownOp(hashId));


			if (reply_data!=NULL){free(reply_data);}
			if(message_buf != NULL){
				free(message_buf);
			}
			
			DDSUtil::send(writer, reply_msg);
		}
		else 
		{
			printf("OnRequest , get_transform(%d)  faild  \n", hashId);
		}
		dds_sample_free(reply_msg, replyDesc, DDS_FREE_ALL);

		dds_sample_free(request, requestDesc, DDS_FREE_ALL);
	}
	else {
		// printf("CRpcServer::OnRequest (%s, %d) hr NULL\n",
		// 	skeletonName.c_str(), hashId);
		dds_sample_free(request, requestDesc, DDS_FREE_ALL);
	}
}

void CRpcServer::OnRequestDef(
	void* request,
	dds_entity_t writer,
	const dds_topic_descriptor_t* requestDesc,
	const dds_topic_descriptor_t* replyDesc) {
	int32_t hashId = *(int32_t*)((uint8_t*)request + GetOfs_RpcRequestData_d(requestDesc));
	if (BussinessUtil::isEventType(hashId)) {
		return;
	}
	
	void* reply_msg = dds_alloc(replyDesc->m_size);
	memcpy((uint8_t*)reply_msg + GetOfs_RpcReplyHeaderRelatedRequestId(hashId),
		(uint8_t*)request + GetOfs_RpcRequestHeaderRequestId(hashId),
		sizeof(DDS_SampleIdentity));
	*(DDS_RPC_RemoteExceptionCode_t*)((uint8_t*)reply_msg+GetOfs_RpcReplyHeaderRemoteEx(hashId)) = DDS_RPC_REMOTE_METHOD_NOT_FOUND;
	DDSUtil::send(writer, reply_msg);
	dds_sample_free(reply_msg, replyDesc, DDS_FREE_ALL);
	dds_sample_free(request, requestDesc, DDS_FREE_ALL);
}

/********************************************   viu rpc  *****************************************************/


/*************************** Client ****************************/
void CVIURpcClient::Init(std::string config) {

	rpc_param rp;
	TokenEncapsulation token_encap;

#ifdef SOA_PROXY
	{
		rp.request.participant = Domainid0_handle.participant;
		token_encap= {PROXY_TOKEN, PROXY_TOKEN, "*rpc"};
	}
#else
	{
		rp.request.participant = Domainid1_handle.participant;
		token_encap= {DIRECT_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "*rpc"};
	}
#endif
	
	for (auto it =m_config.mcu_skeletons.client.viu_mcu.begin();it!=m_config.mcu_skeletons.client.viu_mcu.end();it++ ){

		string skeleton_name  = it->first ;

		const dds_topic_descriptor_t* pRequestDesc = GetDesc(it->second.request_topic_name);
		if (!pRequestDesc) {
			printf("CVIURpcClient::Init GetDesc(%s) NULL\n",
				it->second.request_topic_name.c_str());
			continue;
		}

		const dds_topic_descriptor_t* pReplyDesc = GetDesc(it->second.reply_topic_name);
		if (!pReplyDesc) {
			printf("CVIURpcClient::Init GetDesc(%s) NULL\n",
			  it->second.reply_topic_name.c_str());
			continue;
		}

		m_rps_viu[skeleton_name] = rp; 
		
		DDSUtil::event_pub_init(1,
						it->second.request_topic_name,
						pRequestDesc,
						&m_rps_viu[skeleton_name].request,
		  				NULL,
			  			token_encap,
		  				config,
			  			NULL
					);

		DDSUtil::event_sub_init(1,
						it->second.reply_topic_name,
						pReplyDesc,
						&OnReplyDataAvailable,
						dds_topic_filter,
						&m_rps_viu[skeleton_name].request,
		  				NULL,
		  				token_encap,
		  				{},
		  				config,
						(string *)&it->first
					);
	}

}

void CVIURpcClient::OnReplyDataAvailable(int32_t reader, void* arg) {

	//printf("CVIURpcClient::OnReplyDataAvailable  arg( %s ) !!!!!!!!!!\n",((string *)arg)->c_str());
	
	if(arg ==NULL)
		return;

	auto it = m_config.mcu_skeletons.client.viu_mcu.find(( (string *)arg)->c_str());
	if (it == m_config.mcu_skeletons.client.viu_mcu.end()) {
		// printf("CVIURpcClient::OnReplyDataAvailable m_config.mcu_skeletons.client.viu_mcu.find  %s  failed\n",
		// 	((string *)arg)->c_str());
		return;
	}

	const dds_topic_descriptor_t* pDesc = GetDesc(it->second.reply_topic_name);

	//printf("CVIURpcClient::OnReplyDataAvailable %s  ,   reply_topic_name  (%s) \n",
	//		((string *)arg)->c_str(), it->second.reply_topic_name.c_str());

	if (!pDesc) {
		// printf("CVIURpcClient::OnReplyDataAvailable %s GetDesc(%s) NULL\n",
		// 	((string *)arg)->c_str(), it->second.reply_topic_name.c_str());
		return;
	}

	dds_return_t rc;
	void* samples[MAX_SAMPLES];
	dds_sample_info_t infos[MAX_SAMPLES];
	samples[0] = dds_alloc(pDesc->m_size);
	rc = dds_take_next(reader, samples, infos);
	if (rc < 0) {
		// printf("CRpcClient::OnReplyDataAvailable %s dds_take_next failed!\n",
		// 	((string *)arg)->c_str());
		dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
		return;
	}

	//printf("CVIURpcClient::OnReplyDataAvailable   samples[0] = %p    \n",samples[0]);

	if (infos[0].valid_data) {
		void* reply = samples[0];
		auto sp = std::shared_ptr<void>{
			samples[0],
			[=](void* ptr) {
				dds_sample_free(ptr, pDesc, DDS_FREE_ALL);
				//dds_free(ptr);
			}
		};
		int32_t funID = *(int32_t*)((uint8_t*)reply + GetOfs_RpcReplyData_d(pDesc));
		if (it->second.hash_ids.find(funID) != it->second.hash_ids.end()) {
			
			uint64_t key = (uint64_t)*(uint32_t*)((uint8_t*)reply + GetOfs_RpcReplyHeaderLow(funID));

			//printf("CVIURpcClient::OnReplyDataAvailable find ( funID = %d ,  key= %ld)  ok !\n",funID,key );
			com::changan::rpc_service::DDSClient::release(key, sp);
		}
		else {
			//printf("CVIURpcClient::OnReplyDataAvailable find ( %d )  false !\n",funID);
			// uint64_t key = (uint64_t)*(uint32_t*)((uint8_t*)reply + GetOfs_RpcReplyHeaderLow(funID));
			// com::changan::rpc_service::DDSClient::release(key, sp);
		}
		return ;
	}
	else
	{
		dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
	}

}


bool CVIURpcClient::dds_topic_filter (const void *vsample, void *arg)
{
    
    const carControl_Car_Control_Reply * sample = (carControl_Car_Control_Reply *)vsample;
    bool ret = false;
    
	//static ddsrt_mutex_t   m_mutex;

    if (!sample)
        return false;
    
   // ddsrt_mutex_lock (&m_mutex);

    if (sample->data._d == 0)
		return false;

    auto it = m_config.mcu_skeletons.client.viu_mcu.find(((string *)arg)->c_str());
	if (it == m_config.mcu_skeletons.client.viu_mcu.end()) {
		//printf("CVIURpcClient::dds_topic_filter   find (%s)  failed\n",
		//	((string *)arg)->c_str());
		ret = false;
	}
	else
	{
		auto hash = it->second.hash_ids.find(sample->data._d);
		if (hash == it->second.hash_ids.end())
		{
			ret = false;
		}
		else
		{
			ret = true;
		}
	}
	//printf("CVIURpcClient::dds_topic_filter   return  %s \n",ret ==true?"true":"false");
   // ddsrt_mutex_unlock (&m_mutex);
        
    return ret;
}



/*************************** Server ****************************/
#ifdef viu_rpc_server_enable
map<ServiceInterface, HandleRequest> CVIURpcServer::m_hrs_viu;

void CVIURpcServer::Init(std::string config) {

	rpc_param rp;
	TokenEncapsulation token_encap;

#ifdef SOA_PROXY
	{
		rp.reply.participant = Domainid0_handle.participant;
		token_encap= {PROXY_TOKEN, PROXY_TOKEN, "rpc"};
	}
#else
	{
		rp.reply.participant = Domainid1_handle.participant;
		token_encap= {DIRECT_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "rpc"};
	}
#endif

	for (auto it =m_config.mcu_skeletons.server.viu_mcu.begin();it!=m_config.mcu_skeletons.server.viu_mcu.end();it++ ){


		string skeleton_name  = it->first ;

		const dds_topic_descriptor_t* pRequestDesc = GetDesc(it->second.request_topic_name);
		if (!pRequestDesc) {
			//printf("CVIURpcServer::Init GetDesc(%s) NULL\n",
			//	it->second.request_topic_name.c_str());
			continue;
		}

		const dds_topic_descriptor_t* pReplyDesc = GetDesc(it->second.reply_topic_name);
		if (!pReplyDesc) {
			//printf("CRpcServer::Init GetDesc(%s) NULL\n",
			//	it->second.reply_topic_name.c_str());
			continue;
		}

		m_rps_viu[skeleton_name] = rp;


		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			it->second.reply_topic_name,
			pReplyDesc,
			&m_rps_viu[skeleton_name].reply,
            NULL,
			token_encap,
			config
		);

		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			it->second.request_topic_name,
			pRequestDesc,
			&OnRequestDataAvailable,
			NULL,
			&m_rps_viu[skeleton_name].reply,
			NULL,
			token_encap,{},
			config,
			(string *)&it->first
		);
	 	
	}
}

void CVIURpcServer::Reply( int32_t hashId, HandleRequest hr) {

	for (auto it =m_config.mcu_skeletons.server.viu_mcu.begin();it!=m_config.mcu_skeletons.server.viu_mcu.end();it++ ){
		if(it->second.hash_ids.find(hashId)== it->second.hash_ids.end() )
		{
			// printf("CRpcServer::Handle %s it->second.hash_ids.find(%d) failed\n",
			// 	it->first.c_str(), hashId);
			// return;
			continue;

		}
		else
		{
			string skeleton_name  = it->first ;
			ServiceInterface si;
			//printf("CVIURpcServer::Reply skeleton_name=%s, hashId=%d\n", skeleton_name.data(),hashId );
			si.serviceName = skeleton_name;
			si.hashId = hashId;
			m_hrs_viu[si] = hr;
		}
	}
}

void CVIURpcServer::OnRequestDataAvailable(int32_t reader, void* arg) {
	if(arg ==NULL)
		return;
	auto it = m_config.mcu_skeletons.server.viu_mcu.find(((string *)arg)->c_str());
	if (it == m_config.mcu_skeletons.server.viu_mcu.end()) {
		// printf("CVIURpcServer::OnRequestDataAvailable m_config.mcu_skeletons.server.viu_mcu.find  %s failed\n",
		// 	((string *)arg)->c_str());
		return;
	}

	auto itRp = m_rps_viu.find(((string *)arg)->c_str());
	if (itRp == m_rps_viu.end()) {
		// printf("CVIURpcServer::OnRequestDataAvailable m_rps_viu.find %s failed\n",
		// 	((string *)arg)->c_str());
		return;
	}

	const dds_topic_descriptor_t* pRequestDesc = GetDesc(it->second.request_topic_name);
	if (!pRequestDesc) {
		// printf("CVIURpcServer::OnRequestDataAvailable %s GetDesc(%s) NULL\n",
		// 	((string *)arg)->c_str(), it->second.request_topic_name.c_str());
		return;
	}

	const dds_topic_descriptor_t* pReplyDesc = GetDesc(it->second.reply_topic_name);
	if (!pReplyDesc) {
		// printf("CVIURpcServer::OnRequestDataAvailable %s GetDesc(%s) NULL\n",
		// 	((string *)arg)->c_str(), it->second.reply_topic_name.c_str());
		return;
	}

	dds_return_t rc;
	// printf("CRpcServer::OnRequestDataAvailable %s RPC server on data available!\n",((string *)arg)->c_str());
	void* samples[1];
	samples[0] = dds_alloc(pRequestDesc->m_size);
	dds_sample_info_t infos[1];
	rc = dds_take_next(reader, samples, infos);
	if (rc < 0)
	{
		// printf("CVIURpcServer::OnRequestDataAvailable   %s  dds_take_next failed!\n",
		// ((string *)arg)->c_str());

		dds_sample_free(samples[0], pRequestDesc, DDS_FREE_ALL);
		return ;
	}
	if (infos[0].valid_data)
	{
		void* request = samples[0];
		int32_t funID = *(int32_t*)((uint8_t*)request + GetOfs_RpcRequestData_d(pRequestDesc));

		if (it->second.hash_ids.find(funID) != it->second.hash_ids.end()) {
			DDSServer::execute(
				OnRequest,
				request,
				itRp->second.reply.writer,
				pRequestDesc,
				pReplyDesc,
				((string *)arg)->c_str(),
				funID);
		}
		else {
			//printf("else\n");
			DDSServer::execute(
				OnRequestDef,
				request,
				itRp->second.reply.writer,
				pRequestDesc,
				pReplyDesc);
		}
	}
	else
	{
		dds_sample_free(samples[0], pRequestDesc, DDS_FREE_ALL);
	}
}

void CVIURpcServer::OnRequest(
	void* request,
	dds_entity_t writer,
	const dds_topic_descriptor_t* requestDesc,
	const dds_topic_descriptor_t* replyDesc,
	string skeletonName,
	int32_t hashId) {
	ServiceInterface si;
	si.serviceName = skeletonName;
	si.hashId = hashId;

	auto it = m_hrs_viu.find(si);
	if (it == m_hrs_viu.end()) {
		//printf("CVIURpcServer::OnRequest m_hrs_viu.find(%s, %d) failed\n",
		//	skeletonName.c_str(), hashId);

		dds_sample_free(request, requestDesc, DDS_FREE_ALL);
		return;
	}

	HandleRequest hr = it->second;	
	if (hr) {
		void* reply_msg= dds_alloc(replyDesc->m_size);
		memcpy((uint8_t*)reply_msg + GetOfs_RpcReplyHeaderRelatedRequestId(hashId),
			(uint8_t*)request + GetOfs_RpcRequestHeaderRequestId(hashId),
			sizeof(DDS_SampleIdentity));
		*(int32_t*)((uint8_t*)reply_msg + GetOfs_RpcReplyData_d(replyDesc)) = hashId;
		

		funtransform itReq =get_transform(hashId); 
		if(itReq.is_found)
		{  
			void*   message_buf;
			size_t  requestSize;
			size_t  replaySize;
			DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;
	
			itReq.in_type2pb((uint8_t*)request + GetOfs_RpcRequestData_uUnknownOp(hashId), &message_buf , &requestSize);

			void* reply_data=NULL; //= (void*)malloc((replyDesc->m_size -GetOfs_RpcReplyData_uUnknownOp(hashId) ));

			hr(hashId,message_buf,requestSize, &reply_data,replaySize,errorCode);

			*(DDS_RPC_RemoteExceptionCode_t*)((uint8_t*)reply_msg + GetOfs_RpcReplyHeaderRemoteEx(hashId)) = errorCode;


			*(DDS_RPC_RemoteExceptionCode_t*)((uint8_t*)reply_msg + GetOfs_RpcReplyHeaderRemoteEx(hashId)) = errorCode;

			if(errorCode == DDS_RPC_REMOTE_EX_OK )
				itReq.out_pb2type((const void *)reply_data, replaySize, (uint8_t*)reply_msg + GetOfs_RpcReplyData_uUnknownOp(hashId));


			free(reply_data);
			if(message_buf != NULL){
				free(message_buf);
			}
			
			DDSUtil::send(writer, reply_msg);
		}
		else 
		{
			//printf("CVIURpcServer OnRequest , get_transform(%d)  faild  \n", hashId);
		}
		dds_sample_free(request, requestDesc, DDS_FREE_ALL);
		dds_sample_free(reply_msg, replyDesc, DDS_FREE_ALL);
	}
	else {
		//printf("CVIURpcServer::OnRequest (%s, %d) hr NULL\n",skeletonName.c_str(), hashId);
		dds_sample_free(request, requestDesc, DDS_FREE_ALL);
	}
}

void CVIURpcServer::OnRequestDef(
	void* request,
	dds_entity_t writer,
	const dds_topic_descriptor_t* requestDesc,
	const dds_topic_descriptor_t* replyDesc) {
	int32_t hashId = *(int32_t*)((uint8_t*)request + GetOfs_RpcRequestData_d(requestDesc));
	if (BussinessUtil::isEventType(hashId)) {
		return;
	}
	
	void* reply_msg = dds_alloc(replyDesc->m_size);
	memcpy((uint8_t*)reply_msg + GetOfs_RpcReplyHeaderRelatedRequestId(hashId),
		(uint8_t*)request + GetOfs_RpcRequestHeaderRequestId(hashId),
		sizeof(DDS_SampleIdentity));
	*(DDS_RPC_RemoteExceptionCode_t*)((uint8_t*)reply_msg+GetOfs_RpcReplyHeaderRemoteEx(hashId)) = DDS_RPC_REMOTE_METHOD_NOT_FOUND;
	DDSUtil::send(writer, reply_msg);
	dds_sample_free(reply_msg, replyDesc, DDS_FREE_ALL);
	dds_sample_free(request, requestDesc, DDS_FREE_ALL);
}

#endif




