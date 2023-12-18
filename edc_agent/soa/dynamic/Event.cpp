#include "Event.h"
#include "global_config.hpp"
#include "Common.h"
#include "adapter.h"
#include "dds_client.hpp"

#include "Config.h"
#include "dds/ddsi/ddsi_serdata_default.h"

#include"DDS_PB.h"


using namespace com::changan::rpc_service;

bool _is_safety(int hashid)
{
	bool ret = false;
	static int safe_hashid[] = 
	{
		carControl_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_TurnLiSwtReqInfo_Hash,
		carControl_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo_Hash,  
		carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo_Hash,        
		carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_BrkLiFltInfo_Hash,        
		carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo_Hash,
		carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_HiBeamFltInfo_Hash,
		carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_LoBeamFltInfo_Hash,
		carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_TurnLiFltInfo_Hash, 
		carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo_Hash, 
		carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo_Hash ,     
		carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo_Hash,  
		carControl_Car_Control_Basc_RLSSts_Ntf_WiperRLSSts_Hash,  
		carControl_Car_Control_Basc_FrntWiperStsInfo_Ntf_WiperStsInfo_Hash,
	};
    for (int i = 0; i < sizeof(safe_hashid) /sizeof(int); i++)	
	{
		if (hashid == safe_hashid[i])
		{
			ret = true;
			break;
		}
	}
	return ret;
}

map<string, on_notify> CEventSuber::m_notifys;

dds_rpc_handle_t  Domainid0_handle= { -1, -1, -1 };  
dds_rpc_handle_t  Domainid1_handle= { -1, -1, -1 };  
dds_rpc_handle_t  Domainid2_handle= { -1, -1, -1 }; 


void CEventSuber::Init(std::string config) {

	dds_rpc_handle_t *drh = &Domainid0_handle;

	for (auto it =m_config.events.client.begin();it!=m_config.events.client.end();it++ ){

		string topicName  = it->first ;

		const dds_topic_descriptor_t* pDesc = GetDesc(topicName);
		if (!pDesc) {
			//printf("CEventSuber::Init GetDesc(%s) NULL\n",
			//	topicName.c_str());
			continue;
		}

		DDSUtil::event_sub_init(DDS_DOMAIN_ID,
			topicName,
		    pDesc,
			&OnEventDataAvailable,
			NULL,
			drh,
			NULL,{PROXY_TOKEN, PROXY_TOKEN, ""},{},config,
			(string *)&(it->first) );

			m_drhs[topicName] = *drh;
	}
}

void CEventSuber::Recv(int32_t hashid, on_notify on) {
	auto it =m_config.events.client.begin();
	for (; it!=m_config.events.client.end();it++ )
	{
		if(it->second.hash_id == hashid)
		{
			m_notifys[it->first] = on;
			return;
		}
	}
	if (it==m_config.events.client.end())
	{
		//printf("CEventSuber::Recv m_config.events.find(%d) failed\n",hashid);
		return;
	}
}

void CEventSuber::OnEventDataAvailable(int32_t reader, void* arg) {

	if(arg ==NULL)
		return;




	if (m_drhs.find(((string *)arg)->c_str()) == m_drhs.end()) {
		//printf("CEventSuber::OnEventDataAvailable m_drhs.find %s failed\n",((string *)arg)->c_str());
		return;
	}

	auto it = m_notifys.find(((string *)arg)->c_str());
	if (it == m_notifys.end()) {
		//printf("CEventSuber::OnEventDataAvailable m_notifys.find %s failed\n",((string *)arg)->c_str());
		return;
	}

	if (!it->second) {
		//printf("CEventSuber::OnEventDataAvailable %s on_notify_fn NULL\n",((string *)arg)->c_str());
		return;
	}

	const dds_topic_descriptor_t* pDesc = GetDesc(((string *)arg)->c_str());
	if (!pDesc) {
		//printf("CEventSuber::OnEventDataAvailable GetDesc %s NULL\n",((string *)arg)->c_str());
		return;
	}

	dds_return_t rc;
	void* samples[1];
	samples[0] = dds_alloc(pDesc->m_size);

	dds_sample_info_t infos[1];
	rc = dds_take_next(reader, samples, infos);
	if (rc < 0) {
		//printf("CEventSuber::OnEventDataAvailable dds_take_next failed!\n");
		dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
		return;
	}

	if (infos[0].valid_data) {
		int32_t hashId = *(int32_t*)((uint8_t*)samples[0]+ GetOfs_McuEventData_d(pDesc));

		//printf("pDesc->m_size = %d ,GetOfs_McuEventData_d(pDesc) =%d ,hashId=%d \n",pDesc->m_size,GetOfs_McuEventData_d(pDesc),hashId);


		DDSClient::execute([hashId](on_notify on, void* pd, const dds_topic_descriptor_t* desc) 
		{

			funtransform_ntf type2pbData =get_transform_ntf(hashId);

			if(!type2pbData.is_found)
			{ 
				//printf("CEventSuber::OnEventDataAvailable::get_transform_ntf(%d)  false  ! \n",hashId);
				if (_is_safety(hashId))
				{
					on(hashId, ((uint8_t *)pd + GetOfs_McuEventData_u(desc)) + 4, 0);
				}
				else
				{
					on(hashId, ((uint8_t *)pd + GetOfs_McuEventData_u(desc)), 0);
				}
			}
			else
			{
				size_t pbSize=0;
				void* message_buf=NULL;
				if (_is_safety(hashId))
				{
					type2pbData.ntf_type2pb((const void *)((uint8_t *)pd + GetOfs_McuEventData_u(desc)) + 4, &message_buf ,&pbSize);
				}
				else
				{
					type2pbData.ntf_type2pb((const void *)((uint8_t *)pd + GetOfs_McuEventData_u(desc)), &message_buf ,&pbSize);
				}
				printf("CEventSuber::OnEventDataAvailable::get_transform_ntf(%d) !!! \n",hashId);
				on(hashId,message_buf,pbSize);
				free(message_buf);
			}
			dds_sample_free(pd, desc, DDS_FREE_ALL);
		}, it->second, samples[0], pDesc);

		return;
	}
	else
	{
		dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
	}
}


/////////////////////////////////////////////////////////////////////


void CEventPuber::Init(string config) {

	dds_rpc_handle_t *drh = &Domainid0_handle;

	for (auto it =m_config.events.server.begin();it!=m_config.events.server.end();it++ ){

		string topicName  = it->first ;

		const dds_topic_descriptor_t* pDesc = GetDesc(topicName);
		if (!pDesc) {
			printf("CEventPuber::Init GetDesc(%s) NULL\n",
				topicName.c_str());
			continue;
		}
	
		// DDSUtil::event_pub_init(DDS_DOMAIN_ID,
		// 	topicName,
		// 	pDesc,
		// 	drh,
		// 	NULL, 
		// 	config,
		// 	(char*)MPU_TOKEN_NAME,
		// 	NULL);

		DDSUtil::event_pub_init(DDS_DOMAIN_ID,
			topicName, 
			pDesc, 
			drh,
			NULL, 
			{PROXY_TOKEN, PROXY_TOKEN, ""}, 
			config);

		m_drhs[topicName] = *drh;
	}
}


void CEventPuber::Send(int32_t hashId, void* data,int32_t datasize) {

	auto it_m =m_config.events.server.begin();
	string topicName ;
	for (;it_m!=m_config.events.server.end();it_m++ )
	{
		if(it_m->second.hash_id == hashId)
		{
			topicName = it_m->first;
			break;
		}
	}

	if (it_m == m_config.events.server.end()) {
		// printf("CEventPuber::Send m_config.events.hash_id find  %d  failed\n",hashId);
		return;
	}


   // get  Event  handle
	auto it = m_drhs.find(topicName);
	if (it == m_drhs.end()) {
		// printf("CEventPuber::Send m_drhs.find %s failed\n",
		// 	topicName.c_str());
		return;
	}
	funtransform_ntf pb2typeData =get_transform_ntf(hashId);
	if(pb2typeData.is_found)
	{
		const dds_topic_descriptor_t* pDesc = GetDesc(topicName); 

		// printf("CEventPuber::Send  hash id =%d ,topic name=  %s \n",hashId,topicName.c_str());

		void* send_msg= dds_alloc(pDesc->m_size );
	
		*(int32_t*)((uint8_t*)send_msg + GetOfs_McuEventData_d(pDesc)) = hashId;

		pb2typeData.ntf_pb2type(data,datasize,(uint8_t *)send_msg + GetOfs_McuEventData_u(pDesc) );

		dds_write(it->second.writer, send_msg);

		dds_sample_free(send_msg, pDesc, DDS_FREE_ALL);

		return ;
	}
	// printf("CEventSuber::Send::get_transform_ntf   failed ! \n");
}


void CEventPuber::Send_idlc(int32_t hashId, void* data,int32_t datasize) {

	auto it_m =m_config.events.server.begin();
	string topicName ;
	for (;it_m!=m_config.events.server.end();it_m++ )
	{
		if(it_m->second.hash_id == hashId)
		{
			topicName = it_m->first;
			break;
		}
	}

	if (it_m == m_config.events.server.end()) {
		// printf("CEventPuber::Send m_config.events.hash_id find  %d  failed\n",hashId);
		return;
	}


   // get  Event  handle
	auto it = m_drhs.find(topicName);
	if (it == m_drhs.end()) {
		// printf("CEventPuber::Send m_drhs.find %s failed\n",
		// 	topicName.c_str());
		return;
	}

	{
		const dds_topic_descriptor_t* pDesc = GetDesc(topicName); 

		// printf("CEventPuber::Send  hash id =%d ,topic name=  %s \n",hashId,topicName.c_str());

		void* send_msg= dds_alloc(pDesc->m_size );

		*(int32_t*)((uint8_t*)send_msg + GetOfs_McuEventData_d(pDesc)) = hashId;

		//pb2typeData.ntf_pb2type(data,datasize,(uint8_t *)send_msg + GetOfs_McuEventData_u(pDesc) );
		memcpy((uint8_t *)send_msg + GetOfs_McuEventData_u(pDesc) ,data,datasize);

		
		dds_write(it->second.writer, send_msg);
	

		dds_sample_free(send_msg, pDesc, DDS_FREE_ALL);
	}

	return ;

}



/////////////////////////////////////////////////////////////////////


map<int32_t, on_notify> CMcuEventSuber::m_notifys;



bool CMcuEventSuber::dds_topic_filter (const void *vsample, void *arg)
{
    
    const carControl_Car_Control_Ntf * sample = (carControl_Car_Control_Ntf *)vsample;
    bool ret = false;
    
    if (!sample)
        return false;
    

    if (m_notifys.find(sample->data._d) ==m_notifys.end())
	{
		printf("CMcuEventSuber::dds_topic_filter  hash(%d) not find !!!!  \n",sample->data._d);
		return false;
	}
		
	printf("CMcuEventSuber::dds_topic_filter  hash(%d)  OK !!!!  \n",sample->data._d);
    return true;
}


bool CMcuEventSuber::topic_filter_special_callback (const void * serdata_sample)
{
  bool ret = true;

  struct ddsi_serdata_default *serdata = (struct ddsi_serdata_default *)serdata_sample;
  int32_t hashid ;
  int32_t id_ops = 24; /* writer_guid(16B) + sequence_number(8B) */
  //int32_t id_ops = 16; /* writer_guid(16B) + sequence_number(8B) */

  hashid = ( ((serdata->data[id_ops+0]&0xff))    |  ((serdata->data[id_ops+1]&0xff)<<8)| \
  			 ((serdata->data[id_ops+2]&0xff)<<16)|  ((serdata->data[id_ops+3]&0xff)<<24));
  
  /* filter by service id */
 // ddsrt_mutex_lock(&g_notify_structure[0].service_tree_mutex);
  if (m_notifys.find(hashid) ==m_notifys.end())
  {
    ret = false;
    //printf("\n CMcuEventSuber::topic_filter_special_callback (hashid = %d)  not find !!!!\n",  hashid);
  }
  else
  {
    printf("\n CMcuEventSuber::topic_filter_special_callback (hashid = %d)  OK   !!!!\n",  hashid);
  }
 // ddsrt_mutex_unlock(&g_notify_structure[0].service_tree_mutex);
  return ret;
}




void CMcuEventSuber::Init(std::string config) {
#ifdef VIU_NTF
	Init_wtich_mcu( m_config.mcu_events.client.viu_mcu.viu_fl.topic_name, VIU_MCU,config) ;
	Init_wtich_mcu( m_config.mcu_events.client.viu_mcu.viu_fr.topic_name, VIU_MCU,config) ;
	Init_wtich_mcu( m_config.mcu_events.client.viu_mcu.viu_r.topic_name, VIU_MCU,config)  ;
#endif
	Init_wtich_mcu( m_config.mcu_events.client.c2_mcu.topic_name, C2_MCU,config) ;
}


void CMcuEventSuber::Init_wtich_mcu( string &topicName,string mcu ,std::string config) {

	const dds_topic_descriptor_t* pDesc = GetDesc(topicName);
	if (!pDesc) {
			printf("CMcuEventSuber::Init GetDesc(%s) NULL\n",topicName.c_str());
			return;
	}
	
	// uint32_t domainID =0;
	// const uint8_t *service_id=NULL;
	// size_t  service_id_max=0;
	// dds_rpc_handle_t* handle =NULL;

	// TokenEncapsulation token_encap;
	uint32_t domainID =0;

	ServiceIdEncapsulation  service_id_encap;

	dds_rpc_handle_t* handle =NULL;

	TokenEncapsulation token_encap;

	dds_topic_filter_arg_fn topic_filter =NULL;
	//dds_topic_filter_sample_fn

	if(mcu == C2_MCU)
	{
		domainID = m_config.mcu_events.client.c2_mcu.domainID;

		service_id_encap.service_num=0;
		service_id_encap.service_ids=NULL;
		handle  = &Domainid2_handle;
		token_encap= {DIRECT_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "ntf"};
	}
	else if(mcu== VIU_MCU)
	{
#ifdef SOA_PROXY
			domainID = 0;
			service_id_encap.service_num=(sizeof(client_service_id_array)/sizeof(uint8_t));
			service_id_encap.service_ids=client_service_id_array;
			handle  = &Domainid0_handle;
			token_encap= {PROXY_TOKEN, PROXY_TOKEN, "ntf"};
#else//小域控直连（无SOA_Proxy）
			domainID= 1;
			topic_filter =  (dds_topic_filter_arg_fn )topic_filter_special_callback;
			//topic_filter =dds_topic_filter;
			service_id_encap.service_num=0;
			service_id_encap.service_ids=NULL;
			handle  = &Domainid1_handle;
			token_encap= {DIRECT_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "ntf"};
#endif
	}
	else
	{
		printf("CMcuEventSuber:: %s  is invalid !!!\n",topicName.c_str());
		return;
	}

	DDSUtil::event_sub_init(domainID,
			topicName,
		    pDesc,
			OnEventDataAvailable,
			topic_filter,
			handle,
			NULL,
			token_encap,service_id_encap,config,
			&topicName
			);

	//printf("\n\n\n\n   topicName->c_str(%s) \n",topicName->c_str());

	if(mcu== C2_MCU)
		c2_drh[topicName]  = *handle;
	else if(mcu == VIU_MCU)
		viu_drh[topicName] = *handle;
	
}

void CMcuEventSuber::Recv(int32_t hashId, on_notify on) {

	m_notifys[hashId] = on;
}

void CMcuEventSuber::OnEventDataAvailable(int32_t reader, void* arg) {

	printf("CMcuEventSuber::OnEventDataAvailable arg   %s  \n",(char *)arg);

	const dds_topic_descriptor_t* pDesc = GetDesc(*(string *)arg);

	if (!pDesc) {
		// printf("CMcuEventSuber::OnEventDataAvailable GetDesc %s NULL\n",((string *)arg)->c_str());
		return;
	}

	dds_return_t rc;
	void* samples[1];
	samples[0] = dds_alloc(pDesc->m_size);
	dds_sample_info_t infos[1];
	rc = dds_take_next(reader, samples, infos);
	if (rc < 0) {
		//printf("CMcuEventSuber::OnEventDataAvailable dds_take_next failed!\n");
		dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
		return;
	}
	if (infos[0].valid_data) {
		void* ntf = samples[0];
		int32_t hashId=0;

		//printf("CMcuEventSuber::OnEventDataAvailable arg   %s  \n\n",((string *)arg)->c_str());

		if (!strcmp(((string *)arg)->c_str(),m_config.mcu_events.client.c2_mcu.topic_name.c_str() )) 
		{
			hashId = DDSDATA_MSG_HASH;
		}
		else
		{
			hashId = *(int32_t*)((uint8_t*)ntf + GetOfs_McuEventData_d(pDesc));
		}
		auto it = m_notifys.find(hashId);
		if (it == m_notifys.end()) {
			dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
			return;
		}

		on_notify cb = it->second;

		if (!cb) {
			dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);
			return;
		}
		DDSClient::execute([hashId](on_notify on, void* pd, const dds_topic_descriptor_t* desc) {
			funtransform_ntf type2pbData =get_transform_ntf(hashId);
			if(type2pbData.is_found)
			{ 
				size_t pbSize=0;
				void* message_buf=NULL;

				if(hashId == DDSDATA_MSG_HASH)
				{
					type2pbData.ntf_type2pb((const void *)((uint8_t *)pd ), &message_buf ,&pbSize);
					
				}
				else
				{
					if (_is_safety(hashId))
					{
						type2pbData.ntf_type2pb((const void *)((uint8_t *)pd + GetOfs_McuEventData_u(desc)) + 4, &message_buf ,&pbSize);

					}
					else
					{
						type2pbData.ntf_type2pb((const void *)((uint8_t *)pd + GetOfs_McuEventData_u(desc)), &message_buf ,&pbSize);
					}
				}
				on(hashId,message_buf,pbSize);
				free(message_buf);
			}
			else
			{
				if(_is_safety(hashId))
				{
					on(hashId,((uint8_t *)pd + GetOfs_McuEventData_u(desc)) + 4,0);
				}
				else
				{
					on(hashId,((uint8_t *)pd + GetOfs_McuEventData_u(desc)),0);
				}
			}
			
			dds_sample_free(pd, desc, DDS_FREE_ALL);
		}, cb, samples[0], pDesc);
	}
	else
	{
		dds_sample_free(samples[0], pDesc, DDS_FREE_ALL);//yehuan insert
	}
}


/////////////////////////////////////////////////////////////////////
void CMcuEventPuber::Init_wtich_mcu(string topicName,string mcu,string config) {

 	const dds_topic_descriptor_t* pDesc = GetDesc(topicName);

	if (!pDesc) {
	//printf("CMcuEventPuber::Init GetDesc(%s) NULL\n",
	//	topicName.c_str());
	return;
	}

	uint32_t domainID =0;
	dds_rpc_handle_t* handle =NULL;
	//char * token_name = (char*)MCU_TOKEN_NAME;

	TokenEncapsulation token_encap;
	if(mcu== C2_MCU)
	{
		domainID =m_config.mcu_events.server.c2_mcu.domainID;
		handle  = &Domainid2_handle;
		token_encap= {LOCAL_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "*ntf"};
	}
	else if(mcu == VIU_MCU)
	{
		domainID =m_config.mcu_events.server.viu_mcu.domainID;
#ifdef SOA_PROXY
			domainID =0 ;
			handle  = &Domainid0_handle;
			token_encap= {PROXY_TOKEN, PROXY_TOKEN, "*ntf"};
#else//小域控直连（无SOA_Proxy）
			domainID =1 ;
			handle  = &Domainid1_handle;
			token_encap= {DIRECT_VIU_TOKEN, DIRECT_AND_LOCAL_VIU_TOKEN, "*ntf"};
#endif	
	}
	else
	{
		//printf("CMcuEventPuber:: %s  is invalid !!!\n",topicName.c_str());
		return;
	}

	DDSUtil::event_pub_init(domainID,
		 topicName, 
		 pDesc, 
		 handle,
		 NULL, 
		 token_encap, 
		 config);
	

	if(mcu== C2_MCU)
		c2_drh[topicName]  = *handle;
	else if(mcu == VIU_MCU)
		viu_drh[topicName] = *handle;

	//printf("/n CMcuEventPuber::topicName(%s ) haandle (%d)  !!! \n",topicName.c_str(),c2_drh[topicName].writer);

}

void CMcuEventPuber::Init(std::string config) {
#ifdef VIU_NTF
	Init_wtich_mcu( m_config.mcu_events.server.viu_mcu.viu_fl.topic_name, VIU_MCU,config) ;
	Init_wtich_mcu( m_config.mcu_events.server.viu_mcu.viu_fr.topic_name, VIU_MCU,config) ;
	Init_wtich_mcu( m_config.mcu_events.server.viu_mcu.viu_r.topic_name, VIU_MCU,config)  ;
#endif
	Init_wtich_mcu( m_config.mcu_events.server.c2_mcu.topic_name, C2_MCU,config) ;

}

void CMcuEventPuber::Send(int32_t hashId, void* data,int32_t datasize) {

	string topicName;

	dds_rpc_handle_t handle;

	if (hashId == DDSDATA_MSG_HASH)
	{

		topicName =  m_config.mcu_events.server.c2_mcu.topic_name;
	

		handle = c2_drh[topicName];

		//printf("-------------C2 send(%s)  ---------------\n",topicName.c_str());
	}
	else if(m_config.mcu_events.server.c2_mcu.hash_ids.find(hashId) != m_config.mcu_events.server.c2_mcu.hash_ids.end())
	{
		topicName = m_config.mcu_events.server.c2_mcu.topic_name;
		handle = c2_drh[topicName];
		//printf("-------------C2 send(%s),handle(%d)---------------\n",topicName.c_str(),handle.writer);
	}
	else
	{
		if (m_config.mcu_events.server.viu_mcu.viu_fl.hash_ids.find(hashId) != m_config.mcu_events.server.viu_mcu.viu_fl.hash_ids.end())
		{
			topicName = m_config.mcu_events.server.viu_mcu.viu_fl.topic_name;
			//printf("-------------VIU fl ---------------\n");
		}
		else if (m_config.mcu_events.server.viu_mcu.viu_fr.hash_ids.find(hashId) != m_config.mcu_events.server.viu_mcu.viu_fr.hash_ids.end())
		{
			topicName = m_config.mcu_events.server.viu_mcu.viu_fr.topic_name;
			//printf("-------------VIU fr---------------\n");
		}
		else if (m_config.mcu_events.server.viu_mcu.viu_r.hash_ids.find(hashId) != m_config.mcu_events.server.viu_mcu.viu_r.hash_ids.end())
		{
			topicName = m_config.mcu_events.server.viu_mcu.viu_r.topic_name;
			//printf("-------------VIU r ---------------\n");
		}
		else
		{
			printf("-------------VIU  Send  faild  hashId(%d) not find  ---------------\n",hashId);
			return ;
		}
		handle = viu_drh[topicName];
	}
	
	const dds_topic_descriptor_t* pDesc = GetDesc(topicName);
	if (!pDesc) {
		 //printf("CMcuEventPuber::Send GetDesc(%s) NULL\n",topicName.c_str());
		return;
	}

	funtransform_ntf pb2typeData =get_transform_ntf(hashId);
	
	if(pb2typeData.is_found)
	{ 

		if(hashId == DDSDATA_MSG_HASH)
		{
			void* notify = dds_alloc(pDesc->m_size);

			pb2typeData.ntf_pb2type(data,datasize,(uint8_t *)notify );

			dds_write(handle.writer, notify);

			dds_sample_free(notify, pDesc, DDS_FREE_ALL);
		}
		else
		{
			void* notify = dds_alloc(pDesc->m_size);

			*(int32_t*)((uint8_t*)notify + GetOfs_McuEventData_d(pDesc)) = hashId;

			pb2typeData.ntf_pb2type(data,datasize,(uint8_t *)notify + GetOfs_McuEventData_u(pDesc) );
			dds_write(handle.writer, notify);
			
			dds_sample_free(notify, pDesc, DDS_FREE_ALL);
		}
		return;
	}
	 //printf("CMcuEventPuber::Send::get_transform_ntf   failed ! \n");

}



void CMcuEventPuber::Send_idlc(int32_t hashId, void* data,int32_t datasize) {

	string topicName;

	dds_rpc_handle_t handle;

	if (hashId == DDSDATA_MSG_HASH)
	{
		topicName =  m_config.mcu_events.server.c2_mcu.topic_name;
	
		handle = c2_drh[topicName];
	}
	else if(m_config.mcu_events.server.c2_mcu.hash_ids.find(hashId) != m_config.mcu_events.server.c2_mcu.hash_ids.end())
	{
		topicName = m_config.mcu_events.server.c2_mcu.topic_name;
		handle = c2_drh[topicName];
		//printf("-------------C2 send(%s),handle(%d)---------------\n",topicName.c_str(),handle.writer);
	}
	else
	{
		if (m_config.mcu_events.server.viu_mcu.viu_fl.hash_ids.find(hashId) != m_config.mcu_events.server.viu_mcu.viu_fl.hash_ids.end())
		{
			topicName = m_config.mcu_events.server.viu_mcu.viu_fl.topic_name;
			//printf("-------------VIU fl ---------------\n");
		}
		else if (m_config.mcu_events.server.viu_mcu.viu_fr.hash_ids.find(hashId) != m_config.mcu_events.server.viu_mcu.viu_fr.hash_ids.end())
		{
			topicName = m_config.mcu_events.server.viu_mcu.viu_fr.topic_name;
			//printf("-------------VIU fr---------------\n");
		}
		else if (m_config.mcu_events.server.viu_mcu.viu_r.hash_ids.find(hashId) != m_config.mcu_events.server.viu_mcu.viu_r.hash_ids.end())
		{
			topicName = m_config.mcu_events.server.viu_mcu.viu_r.topic_name;
			//printf("-------------VIU r ---------------\n");
		}
		else
		{
			printf("-------------VIU  Send  faild  hashId(%d) not find  ---------------\n",hashId);
			return ;
		}
		handle = viu_drh[topicName];
	}
	
	const dds_topic_descriptor_t* pDesc = GetDesc(topicName);
	if (!pDesc) {
		 //printf("CMcuEventPuber::Send GetDesc(%s) NULL\n",topicName.c_str());
		return;
	}


	if(hashId == DDSDATA_MSG_HASH)
	{
		dds_write(handle.writer, data);

		dds_sample_free(data, pDesc, DDS_FREE_ALL); 

		return;
	}
	else
	{
		void* notify = dds_alloc(pDesc->m_size);

		*(int32_t*)((uint8_t*)notify + GetOfs_McuEventData_d(pDesc)) = hashId;

		memcpy((uint8_t *)notify + GetOfs_McuEventData_u(pDesc) ,data,datasize);

		dds_write(handle.writer, notify);
		
		dds_sample_free(notify, pDesc, DDS_FREE_ALL);
	}

}
