// #include "Config.h"
// #include "Event.h"
// #include "Rpc.h"
// #include "string_util.hpp"
// #include "Common.h"
// #include "Car_Control.h"
// #include "Car_Control.pb.h"


// void handleMcuEvent(int32_t hash, void *event ,int32_t size);
// void handleEvent(int32_t hash, void *event ,int32_t size);
// void handleViuEvent(int32_t hash, void *event ,int32_t size);

// bool TestDynamicCall_Skeleton_Interface(void);
// bool TestDynamicCall_Skeleton_Interface_VIU(void);

int main()
{
// 	CConfig cfg;
// 	if (!cfg.Load("../json/dc2.json"))
// 	{
// 		return -2;
// 	}

// 	/****************Event******************/
// 	CEventSuber::SetConfig(cfg.GetConfig());
// 	CEventSuber::Recv(246841347, handleEvent);
// 	CEventSuber::Recv(225804291, handleEvent);
// 	CEventSuber::Init("../client.xml");

// 	/****************CMcuEvent******************/
// 	CMcuEventSuber::SetConfig(cfg.GetConfig());
// 	CMcuEventSuber::Recv(1234567, handleMcuEvent);
// 	CMcuEventSuber::Recv(100565049, handleViuEvent);
	
// 	CMcuEventSuber::Init("../client.xml");


// 	/****************RPC******************/ 
// 	CRpcClient::SetConfig(cfg.GetConfig()); 
// 	CRpcClient::Init();

// 	/****************VIU RPC******************/
// 	CVIURpcClient::SetConfig(cfg.GetConfig());
// 	CVIURpcClient::Init();


// 	this_thread::sleep_for(chrono::seconds(1));

	
// 	while (true)
// 	{
		
// 		//RPC 
// 		TestDynamicCall_Skeleton_Interface();
// 		TestDynamicCall_Skeleton_Interface_VIU();
// 		usleep(3*1000*1000);
		
// 	}
	
// 	return 0;
// }

// void handleEvent(int32_t hash, void *event,int32_t size)
// {
// 	printf("\n\n\n-------------------MPU  NTF   data RESEVED  hash(%d) ----------------------\n",hash);

// 	if (!event)
// 	{
// 		printf("handleEventDInfo1 event NULL\n");
// 		return;
// 	}

// 	//throw runtime_error("commit on ThreadPool is stopped.");

// 	Soa::PB_AD_APACustSlotData  message;
// 	message.ParseFromArray(event, size);

// }


// void handleViuEvent(int32_t hash, void *event,int32_t size)
// {
// 	printf("\n\n\n-------------------VIU  NTF   data RESEVED  hash(%d) ----------------------\n",hash);

// 	if (!event)
// 	{
// 		printf("handleEventDInfo1 event NULL\n");
// 		return;
// 	}


// 	Soa::PB_AD_APACustSlotData  message;
// 	message.ParseFromArray(event, size);

// }


// void handleMcuEvent(int32_t hash, void *event,int32_t size)
// {
// 	printf("\n\n\n-------------------MCU  NTF   data RESEVED  hash(%d) ----------------------\n",hash);

// 	if (!event)
// 	{
// 		printf("handleEventDInfo1 event NULL\n");
// 		return;
// 	}


// 	Soa::PB_DDSData_Msg  message;
// 	message.ParseFromArray(event, size);

// }





// bool TestDynamicCall_Skeleton_Interface()
// {
	
// 	printf("\n\n\n--------------------MPU RPC  data send   ---------------------\n");
	

// 	Soa::PB_Basc_APAnotice_RR_APP_RMACntrlcomnd_In  in;



// 	Soa::PB_RequestInfo* requestinfo= in.mutable_requestinfo();
// 	requestinfo->set_request_id(11);
// 	requestinfo->set_session_id(22);
	

// 	Soa::PB_RMAset_APP_MainScreenOperate* Operate = in.mutable_rmaset_app_mainscreenoperate();
// 	Operate->set_rma_app_mainscreenoperate(33);

// 	void *req = malloc(in.ByteSize());
// 	in.SerializeToArray(req, in.ByteSize());
	

// 	size_t reply_size = 0;
// 	void *reply_buf = NULL;
// 	DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;


// 	CRpcClient::Request(186253327, req, in.ByteSize(), &reply_buf, reply_size, errorCode);
// 	free(req);

// 	printf("errorCode=%d\n", errorCode);
// 	if (errorCode == DDS_RPC_REMOTE_EX_OK) 
// 	{
		

// 		Soa::PB_Basc_APAnotice_RR_EDC_PopUpWindowOperate_Out  replytem;
		
// 		replytem.ParseFromArray(reply_buf, reply_size);

// 		auto temp_0 = replytem.mutable_return_();
// 		printf(" request_id=%d,session_id=%d, \n", \ 
// 		temp_0->request_id(),
// 		temp_0->session_id());
// 	}
// 	if (reply_buf != NULL)
// 	{
// 		free(reply_buf);
// 	}
// 	return true;
// }



// bool TestDynamicCall_Skeleton_Interface_VIU()
// {
// 	printf("\n\n\n--------------------VIU RPC  data send ----------------------\n");

// 	Soa::PB_Car_Control_Cnr_PowerShiftSwt_RR_PwrShiftSwt_In   in;



// 	Soa::PB_RequestInfo* requestinfo= in.mutable_requestinfo();
// 	requestinfo->set_request_id(55);
// 	requestinfo->set_session_id(66);
	
// 	void *req = malloc(in.ByteSize());
// 	in.SerializeToArray(req, in.ByteSize());
	

// 	size_t reply_size = 0;
// 	void *reply_buf = NULL;
// 	DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;


// 	CVIURpcClient::Request(135987215, req, in.ByteSize(), &reply_buf, reply_size, errorCode);
// 	free(req);

// 	printf("  VIU RPC   errorCode=%d\n", errorCode);
// 	if (errorCode == DDS_RPC_REMOTE_EX_OK) 
// 	{
		

// 		Soa::PB_Basc_APAnotice_RR_EDC_PopUpWindowOperate_Out  replytem;
		
// 		replytem.ParseFromArray(reply_buf, reply_size);

// 		auto temp_0 = replytem.mutable_return_();
// 		printf(" request_id=%d,session_id=%d, \n", \ 
// 		temp_0->request_id(),
// 		temp_0->session_id());
// 	}
// 	if (reply_buf != NULL)
// 	{
// 		free(reply_buf);
// 	}
// 	return true;
 }
