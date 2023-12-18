// #include "Config.h"
// #include "Event.h"
// #include "Rpc.h"
// #include "string_util.hpp"
// #include "Common.h"
// #include <functional>
// #include "Car_Control.h"


// #include "DDS_PB.h"

// using namespace std;

// void HandleInterface_mpu(int32_t hash, void *request, size_t requestSize, void **reply, size_t &replySize, DDS_RPC_RemoteExceptionCode_t &errorCode);
// void HandleInterface_viu(int32_t hash, void *request, size_t requestSize, void **reply, size_t &replySize, DDS_RPC_RemoteExceptionCode_t &errorCode);

int main()
{

// 	CConfig cfg;
// 	if (!cfg.Load("../json/dc2.json"))
// 	{
// 		return -2;
// 	}

// 	/****************Event******************/
// 	CEventPuber::SetConfig(cfg.GetConfig());
// 	CEventPuber::Init("../client.xml");

// 	/****************CMcuEvent******************/
// 	CMcuEventPuber::SetConfig(cfg.GetConfig());
// 	CMcuEventPuber::Init("../client.xml");

// 	// /****************RPC******************/
// 	CRpcServer::SetConfig(cfg.GetConfig());
// 	CRpcServer::Reply(186253327, HandleInterface_mpu);
// 	CRpcServer::Init();
// #ifdef viu_rpc_server_enable
// 	// just for debug
// 	CVIURpcServer::SetConfig(cfg.GetConfig());
// 	CVIURpcServer::Reply(135987215, HandleInterface_viu );
// 	CVIURpcServer::Init();
// #endif
// 	usleep(1000 * 1000);
// 	while (true)
// 	{
// #if 1
// 		printf("\n\n\n--------------------NTF  data send  ----------------------\n");

// 		// /*-----------MPU---------*/
// 		// void *buf=NULL;
// 		// Soa::PB_AD_APACustSlotData  data;
// 		// data.set_ad_apacustslotvld(11);
// 		// buf = malloc(data.ByteSizeLong());
// 		// data.SerializeToArray(buf, data.ByteSizeLong());

// 		// CEventPuber::Send(246841347, buf, data.ByteSizeLong());
// 		// free(buf);
// 		// buf=NULL;


// 		// /*-----------MPU  结构体数据的发送 ---------*/
// 		// struct AD_APACustSlotData  *buf2 =(struct AD_APACustSlotData *)malloc(sizeof(struct AD_APACustSlotData));
// 		// buf2->AD_APACustSlotVld=123;
// 		// CEventPuber::Send_idlc(246841347, buf2,sizeof(struct AD_APACustSlotData));




// 		string topicdata="111111111";
// 		struct DDSData_Msg  *buf3 =(struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
// 		buf3->timestamp=111;
// 		buf3->topic=(char *)malloc(topicdata.length());
// 		strcpy(buf3->topic,topicdata.data());


// 		int len = 10;
// 		uint8_t  *data3= (uint8_t  *)malloc(len);
// 		buf3->payload._length=len;
// 		buf3->payload._release =true;
// 		buf3->payload._buffer= data3;
// 		for (size_t i = 0; i < len; i++)
// 		{
// 			buf3->payload._buffer[i]=i;
// 		}
		
// 		CEventPuber::Send_idlc(225804291, buf3,sizeof(struct DDSData_Msg));


// #if 0

// 		/*-----------C2  MCU---------*/
// 		Soa::PB_DDSData_Msg  data1;
// 		data1.set_timestamp(222);
// 		buf = malloc(data1.ByteSizeLong());
// 		data1.SerializeToArray(buf, data1.ByteSizeLong());

// 		CMcuEventPuber::Send(1234567, buf, data1.ByteSizeLong());  
// 		free(buf);
// 		buf=NULL;


// 		/*-----------C2  MCU---------*/
// 		string topicdata="11111";
// 		DDSData_Msg *dataC2MCU= (DDSData_Msg *)dds_alloc(ProtoData_desc.m_size);;
// 		dataC2MCU->timestamp=222;
// 		dataC2MCU->topic=(char *)malloc(topicdata.length());
// 		strcpy(dataC2MCU->topic, topicdata.c_str());

// 		int data_size=10;
// 		dataC2MCU->payload._length = data_size;
// 		dataC2MCU->payload._release = true;
// 		dataC2MCU->payload._buffer = (uint8_t *)malloc(sizeof(uint8_t) * data_size);
		
// 		for(int i=0;i<data_size;++i){
// 			dataC2MCU->payload._buffer[i] = i;
// 		}
// 		CMcuEventPuber::Send_idlc(1234567, dataC2MCU,sizeof(DDSData_Msg));

// 	/*-----------VIU MCU---------*/
// 		//void *buf=NULL;
// 		Soa::PB_FogActCtrlInfo  data2;
// 		data2.set_le_reactctrlst(33);
// 		buf = malloc(data2.ByteSizeLong());
// 		data2.SerializeToArray(buf, data2.ByteSizeLong());

// 		CMcuEventPuber::Send(100565049, buf, data2.ByteSizeLong()); 

// 		//CMcuEventPuber::Send(100565055, buf, data2.ByteSizeLong()); 

// 		free(buf);
// 		buf=NULL;
// #endif
// #endif
// 		this_thread::sleep_for(chrono::seconds(3));
// 	}

// 	return 0;
// } 

 
// void HandleInterface_mpu(int32_t hash, void *request, size_t requestSize, void **reply, size_t &replySize, DDS_RPC_RemoteExceptionCode_t &errorCode)
// {

// 	Soa::PB_Basc_APAnotice_RR_APP_RMACntrlcomnd_In in;


// 	in.ParseFromArray(request, requestSize);
// 	auto req = in.mutable_requestinfo();
// 	printf("\n\n----------------MPU  RPC-reply-----------------------\n");
// 	printf("in.req.Request_ID=%d, in.req.Session_ID=%d\n ", req->request_id(), req->session_id());

// 	Soa::PB_Basc_APAnotice_RR_EDC_PopUpWindowOperate_Out resMsg;
// 	resMsg.clear_return_();
// 	auto resInfoMsg = resMsg.mutable_return_();  
// 	resInfoMsg->set_request_id(1111);
// 	resInfoMsg->set_session_id(2222);

// 	void *tempvalue=malloc(resMsg.ByteSizeLong());         
// 	resMsg.SerializeToArray(tempvalue, resMsg.ByteSizeLong());
// 	replySize = resMsg.ByteSizeLong();
// 	*reply = tempvalue;////////////
// 	errorCode = DDS_RPC_REMOTE_EX_OK;

// }


// void HandleInterface_viu(int32_t hash, void *request, size_t requestSize, void **reply, size_t &replySize, DDS_RPC_RemoteExceptionCode_t &errorCode)
// {

// 	Soa::PB_Car_Control_Cnr_PowerShiftSwt_RR_PwrShiftSwt_In  in ;

// 	in.ParseFromArray(request, requestSize);
// 	auto req = in.mutable_requestinfo();
// 	printf("\n\n----------------VIU  RPC-reply-----------------------\n");
// 	printf("in.req.Request_ID=%d, in.req.Session_ID=%d\n",req->request_id(), req->session_id());

// 	Soa::PB_Car_Control_Cnr_PowerShiftSwt_RR_PwrShiftSwt_Out resMsg;
// 	resMsg.clear_return_();
// 	auto resInfoMsg = resMsg.mutable_return_();  
// 	resInfoMsg->set_request_id(5555);
// 	resInfoMsg->set_session_id(6666);

// 	void *tempvalue=malloc(resMsg.ByteSizeLong());         
// 	resMsg.SerializeToArray(tempvalue, resMsg.ByteSizeLong());
// 	replySize = resMsg.ByteSizeLong();
// 	*reply = tempvalue;////////////
// 	errorCode = DDS_RPC_REMOTE_EX_OK;

}

