#include "dds_node.h"
#include <thread>
#include "dynamic/Event.h"
#include "dynamic/Rpc.h"
#include "live_msg_oem_soc_to_mcu_Types.h"
#include "live_msg_cx_mcu_to_edc_agent_Types.h"
#include "zros/live_msgs/live_msg.h"



#define DEST_DDS     0
#define DEST_SOC     1
#define DEST_MCU     2
#define DEST_MCU_SOC 3
#define DEST_NULL    4

#define LIVE_MSG_CATEGORY_INVAILD    0xFFFFFFFF

typedef struct 
{
  int hashid;
  int src;
  int dest;
  uint32_t category;
  string topic;
}rpc_msg_map_t;


static rpc_msg_map_t rpc_msg_map[] =
{

  /*****************************************************************DDS2MCU RPC*****************************************************************/
    {carDrive_Basc_ADASvoiceCtr_RR_HU_LaneChangeReq_Hash             , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_LANECHANGGEREQ, ""},
    {carDrive_Basc_ADASvoiceCtr_RR_HU_VC_ACCactive_Hash              , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_VC_ACCACTIVE, ""},
    {carDrive_Basc_ADASvoiceCtr_RR_HU_VC_CruiseSetDistance_Hash      , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_VC_CRUISESETDISTANCE, ""},
    {carDrive_Basc_ADASvoiceCtr_RR_HU_VC_CruiseSetSpeed_Hash         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_VC_CRUISESETSPEED, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_CSLAEnable_Hash               , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_CSLAENABLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_CSLmode_Hash                  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_CSLMODE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash               , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_CURISEMODE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_Hash  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_OVERSPEEDSOUNDWARENABLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_UDLCEnable_Hash               , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_UDLCENABLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_Hash           , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_AUTODRIVESTYLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_ADACCStyle_Hash               , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_ADACCSTYLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_ADStartStyle_Hash             , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_ADSTARTSTYLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_Hash             , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_ADCURVESTYLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_Hash , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_VEHICLESTARTREMINDENABLE, ""},
    // {carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash               , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HUSET_CURISEMODE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_RCWEnable_Hash                , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_RCWENABLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_SEAMode_Hash                  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_SEAMODE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_Hash            , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_BSDLCASETTING, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_Hash         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_BSDLCAREMINDMODE, ""},
    {carDrive_Basc_ADASSecureSet_RR_HU_RedLightRemindEnable_Hash     , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_REDLIGHTREMINDENABLE, ""},
    {carDrive_Basc_ADASSecureSet_RR_HU_ForwardColliAstType_Hash      , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_FORWARDCOLLIASTTYPE, ""},
    {carDrive_Basc_ADASSecureSet_RR_HU_ForwardColliAstSenStyle_Hash  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_FORWARDCOLLIASTSENSTYLE, ""},
    {carDrive_Basc_ADASSecureSet_RR_HU_RearColliAstType_Hash         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_REARCOLLIASTTYPE, ""},
    {carDrive_Basc_ADASSecureSet_RR_HU_LASModeSelection_Hash         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_LASMODESELECTION, ""},
    {carDrive_Basc_ADASSecureSet_RR_HU_LASWarningModeSelection_Hash  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_LASWARNINGMODESELECTION, ""},
    {carDrive_Basc_ADASSecureSet_RR_HU_CESEnable_Hash                , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_CESENABLE, ""},
    {carDrive_Basc_ADASSecureSet_RR_HU_ELKEnable_Hash                , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_ELKENABLE, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_SEAOnOff_Hash                 , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_SEAONOFF, ""},
    {carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCAOnOff_Hash              , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_RR_HU_BSDLCAONOFF, ""},

  /*****************************************************************MCU2DDSRPC*****************************************************************/
    {carControl_Car_Control_Enh_TurnLi_RR_TurnON_Hash                 , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_RR_TURNON, ""},
    {carControl_Car_Control_Enh_TurnLi_RR_TurnOFF_Hash                , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_RR_TURNOFF, ""},
    {carControl_Car_Control_Cnr_HdLampCtrl_RR_CombHdLampCtrl_Hash     , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_RR_COMBHDLAMPCTRL, ""},
    {carControl_Car_Control_Cnr_FrntWiperCtrl_RR_WiperCtrl_Hash       , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_RR_WIPERCTRL, ""},

  /*****************************************************************DDS2SOCRPC*****************************************************************/
    {carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash            , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "EDC_APADrvrReqOnOff_Topic"},
    {carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash           , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "EDC_APADrvrReqSlotID_Topic"},
    {carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash            , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "EDC_APAParkInSelect_Topic"},
    {carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash          , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "EDC_APADynamicOperate_Topic"},
    {carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash           , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "EDC_APAParkOutSelect_Topic"},
    {carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash                , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "EDC_RADSDrvrReq_Topic"},
    {carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Hash             , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "EDC_APAFunctionReq_Topic"},
    {carDrive_Basic_APAFunctionReq_RR_APAControleReq_Hash             , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "EDC_APAControleReq_Topic"},

  /* ------------------------------------------------------- SOC-->DDS RPC ------------------------------------------------------- */
  {carControl_Car_Control_Cnr_BleRpaCtl_RR_BleRpaCtl_Hash             , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "BLERpaCmdRsp_Topic"},
  {carControl_Car_Control_Enh_TurnLi_RR_TurnON_Hash                   , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "RR_TurnON_Topic"},
  {carControl_Car_Control_Enh_TurnLi_RR_TurnOFF_Hash                  , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "RR_TurnOFF_Topic"},

};


static int getEventDestFromHashID(int hashid)
{
    for (int i = 0; i < sizeof(rpc_msg_map) /sizeof(rpc_msg_map_t); i++)
    {
      if (hashid == rpc_msg_map[i].hashid)
      {
        return rpc_msg_map[i].dest;
      }
    }
  return DEST_NULL;
}

static string getTopicFromHashID(int hashid)
{
    for (int i = 0; i < sizeof(rpc_msg_map) /sizeof(rpc_msg_map_t); i++)
    {
      if (hashid == rpc_msg_map[i].hashid)
      {
        return rpc_msg_map[i].topic;
      }
    }
  return "";
}

static int getLiveMsgCategoryFromHashID(int hashid)
{
    for (int i = 0; i < sizeof(rpc_msg_map) /sizeof(rpc_msg_map_t); i++)
    {
      if (hashid == rpc_msg_map[i].hashid)
      {
        return rpc_msg_map[i].category;
      }
    }
  return -1;
}


static int getHashIDFromTopic(string topic)
{

    for (int i = 0; i < sizeof(rpc_msg_map) /sizeof(rpc_msg_map_t); i++)
    {
        if (topic == rpc_msg_map[i].topic)
        {
        return rpc_msg_map[i].hashid;
        }
    }

  return -1;
}

static int getHashIDFromLiveMsgCategory(int category)
{
    for (int i = 0; i < sizeof(rpc_msg_map) /sizeof(rpc_msg_map_t); i++)
    {
      if (category == rpc_msg_map[i].category)
      {
        return rpc_msg_map[i].hashid;
      }
    }

  return -1;
}

/* -------------------------------------------------------------------------------
 * process_soc2dds_rpc
 * -------------------------------------------------------------------------------*/
void DDSNode:: process_soc2dds_rpc(const std::string &topic, const zros::core::PlainBufMessage &msg)
{
  INF("process_soc2dds_rpc: topic[%s] received!\n", topic.c_str());
  if (topic == "BLERpaCmdRsp_Topic")
  {
    int32_t hashID = getHashIDFromTopic(topic);
    INF("process_soc2dds_rpc: topic[%s] hashid[%d] received!\n", topic.c_str(), hashID);

    void *replybuf = nullptr;
    size_t replySize = 0;
    DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;

    if (!msg.GetData())
    {
      ERR("process_soc2dds_rpc: msg is null!\n");
    }
    else
    {
      DBG("process_soc2dds_rpc: msg sizeof(%d)!\n", msg.GetSize());
    }

    Soa::PB_BLERpaCmdRsp pb_data;
    pb_data.ParseFromArray(msg.GetData(), msg.GetSize());
    Soa::PB_Car_Control_Cnr_BleRpaCtl_RR_BleRpaCtl_In in;
    //in.ParseFromArray(msg.GetData(), msg.GetSize());

/**************************************************************************/
    DBG("BLERpaCmdRsp_Topic:[blerpacmdrspdata] [%u %u %u %u %u]\n",
      pb_data.blerpacmdrspdata(0),
      pb_data.blerpacmdrspdata(1),
      pb_data.blerpacmdrspdata(2),
      pb_data.blerpacmdrspdata(3),
      pb_data.blerpacmdrspdata(4));

      ZINFO << "BLERpaCmdRsp_Topic:[blerpacmdrspdata] [";
      ZINFO << pb_data.blerpacmdrspdata(0) <<  " ";
      ZINFO << pb_data.blerpacmdrspdata(1) <<  " ";
      ZINFO << pb_data.blerpacmdrspdata(2) <<  " ";
      ZINFO << pb_data.blerpacmdrspdata(3) <<  " ";
      ZINFO << pb_data.blerpacmdrspdata(4) <<  "]" << std::endl;
/**************************************************************************/   

    DBG("process_soc2dds_rpc: test====1111!\n");
    in.mutable_blerpacmdrsp()->CopyFrom(pb_data);
    in.mutable_requestinfo()->set_request_id(0x80000003);
    in.mutable_requestinfo()->set_session_id(1);
    DBG("process_soc2dds_rpc: test====2222!\n");

    void *req = malloc(in.ByteSizeLong());
    in.SerializeToArray(req, in.ByteSizeLong());

/**************************************************************************/
  // Soa::PB_Car_Control_Cnr_BleRpaCtl_RR_BleRpaCtl_In* message=new (Soa::PB_Car_Control_Cnr_BleRpaCtl_RR_BleRpaCtl_In);
	// message->ParseFromArray(req, in.ByteSizeLong());

  // Soa::PB_Car_Control_Cnr_BleRpaCtl_RR_BleRpaCtl_In* val = (Soa::PB_Car_Control_Cnr_BleRpaCtl_RR_BleRpaCtl_In*) message;
	// carControl_Car_Control_Cnr_BleRpaCtl_RR_BleRpaCtl_In ret;

  // convert_to_struct_BLERpaCmdRsp(&val->blerpacmdrsp(), &ret.BLERpaCmdRsp);
  // convert_to_struct_RequestInfo(&val->requestinfo(), &ret.RequestInfo);

  // INF("BLERpaCmdRsp_Topic: %u %u %u %u %u\n",
  //     ret.BLERpaCmdRsp.BLERpaCmdRspData[0],
  //     ret.BLERpaCmdRsp.BLERpaCmdRspData[1],
  //     ret.BLERpaCmdRsp.BLERpaCmdRspData[2],
  //     ret.BLERpaCmdRsp.BLERpaCmdRspData[3], 
  //     ret.BLERpaCmdRsp.BLERpaCmdRspData[4]);

	// delete(message);
/**************************************************************************/

    TIMER_COUNT_BEGIN(ble_req);
    CVIURpcClient::Request(hashID, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    TIMER_COUNT_END(process_soc2dds_rpc:ble_req, 1, ble_req);

    //CRpcClient::Request(hashID, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    free(req);
  }
  if (topic == "RR_TurnON_Topic")
  {
    int32_t hashID = getHashIDFromTopic(topic);
    INF("process_soc2dds_rpc: topic[%s] hashid[%d] received!\n", topic.c_str(), hashID);

    void *replybuf = nullptr;
    size_t replySize = 0;
    DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;

    Soa::PB_TurnLiCtrlCmd pb_data;
    pb_data.ParseFromArray(msg.GetData(), msg.GetSize());

/**************************************************************************/
    DBG("RR_TurnON_Topic:[pb_data]: data[%u %u %u %u %u %u %u] \n",
          pb_data.turnlictrlposn(),
          pb_data.turnlioffdurn(),
          pb_data.turnliondurn(),
          pb_data.turnlipri(),
          pb_data.turnlicnt(),
          pb_data.turnlirecover(),
          pb_data.flowingefc());

    // TurnLiCtrlCmd lictrl_tmp;
    // convert_to_struct_TurnLiCtrlCmd(&lictrl_tmp, &pb_data);
    // INF("RR_TurnON_Topic:[lictrl] pos[%d] off[%d] on[%d] pri[%d] cnt[%d] efc[%d]\n",
    //       lictrl_tmp.TurnLiCtrlPosn,
    //       lictrl_tmp.TurnLiOffDurn,
    //       lictrl_tmp.TurnLiOnDurn,
    //       lictrl_tmp.TurnLiPRI,
    //       lictrl_tmp.TurnLiCnt,
    //       lictrl_tmp.TurnLiRecover,
    //       lictrl_tmp.FlowingEfc);
/**************************************************************************/

    Soa::PB_Car_Control_Enh_TurnLi_RR_TurnON_In in;
    in.mutable_turnlictrlcmd()->CopyFrom(pb_data);
    in.mutable_requestinfo()->set_request_id(0x80000001);
    in.mutable_requestinfo()->set_session_id(1);
    //in.ParseFromArray(msg.GetData(), msg.GetSize());

    void *req = malloc(in.ByteSizeLong());
    in.SerializeToArray(req, in.ByteSizeLong());

/**************************************************************************/
  // Soa::PB_Car_Control_Enh_TurnLi_RR_TurnON_In* message=new (Soa::PB_Car_Control_Enh_TurnLi_RR_TurnON_In);
	// message->ParseFromArray(req, in.ByteSizeLong());

  // Soa::PB_Car_Control_Enh_TurnLi_RR_TurnON_In* val = (Soa::PB_Car_Control_Enh_TurnLi_RR_TurnON_In*) message;
	// carControl_Car_Control_Enh_TurnLi_RR_TurnON_In ret;

  // convert_to_struct_TurnLiCtrlCmd(&val->turnlictrlcmd(), &ret.TurnLiCtrlCmd);
  // convert_to_struct_RequestInfo(&val->requestinfo(), &ret.RequestInfo);

  // INF("RR_TurnON_Topic: pos[%d] off[%d] on[%d] pri[%d] cnt[%d] efc[%d]\n",
  //     ret.TurnLiCtrlCmd.TurnLiCtrlPosn,
  //     ret.TurnLiCtrlCmd.TurnLiOffDurn,
  //     ret.TurnLiCtrlCmd.TurnLiOnDurn,
  //     ret.TurnLiCtrlCmd.TurnLiPRI,
  //     ret.TurnLiCtrlCmd.TurnLiCnt,
  //     ret.TurnLiCtrlCmd.TurnLiRecover,
  //     ret.TurnLiCtrlCmd.FlowingEfc);

  // INF("RR_TurnON_Topic: req_id[%x] ses_id[%x]\n",
  //     ret.RequestInfo.Request_ID, ret.RequestInfo.Session_ID);

	// delete(message);
/**************************************************************************/

    TIMER_COUNT_BEGIN(rr_turnon);
    CVIURpcClient::Request(hashID, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    TIMER_COUNT_END(process_soc2dds_rpc:rr_turnon, 1, rr_turnon);
    //CRpcClient::Request(hashID, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    free(req);
  }
  if (topic == "RR_TurnOFF_Topic")
  {
    int32_t hashID = getHashIDFromTopic(topic);
    INF("process_soc2dds_rpc: topic[%s] hashid[%d] received!\n", topic.c_str(), hashID);

    void *replybuf = nullptr;
    size_t replySize = 0;
    DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;

    Soa::PB_TurnLiCtrlCmd pb_data ;
    pb_data.ParseFromArray(msg.GetData(), msg.GetSize());

/**************************************************************************/
    DBG("RR_TurnOFF_Topic:[pb_data]: data[%u %u %u %u %u %u %u] \n",
          pb_data.turnlictrlposn(),
          pb_data.turnlioffdurn(),
          pb_data.turnliondurn(),
          pb_data.turnlipri(),
          pb_data.turnlicnt(),
          pb_data.turnlirecover(),
          pb_data.flowingefc());

    // TurnLiCtrlCmd lictrl_tmp;
    // convert_to_struct_TurnLiCtrlCmd(&lictrl_tmp, &pb_data);
    // INF("RR_TurnOFF_Topic: pos[%d] off[%d] on[%d] pri[%d] cnt[%d] efc[%d]\n",
    //       lictrl_tmp.TurnLiCtrlPosn,
    //       lictrl_tmp.TurnLiOffDurn,
    //       lictrl_tmp.TurnLiOnDurn,
    //       lictrl_tmp.TurnLiPRI,
    //       lictrl_tmp.TurnLiCnt,
    //       lictrl_tmp.TurnLiRecover,
    //       lictrl_tmp.FlowingEfc);
/**************************************************************************/

    Soa::PB_Car_Control_Enh_TurnLi_RR_TurnOFF_In in;
    in.mutable_turnlictrlcmd()->CopyFrom(pb_data);
    in.mutable_requestinfo()->set_request_id(0x80000002);
    in.mutable_requestinfo()->set_session_id(1);
    //in.ParseFromArray(msg.GetData(), msg.GetSize());

    void *req = malloc(in.ByteSizeLong());
    in.SerializeToArray(req, in.ByteSizeLong());

/**************************************************************************/
  // Soa::PB_Car_Control_Enh_TurnLi_RR_TurnOFF_In* message=new (Soa::PB_Car_Control_Enh_TurnLi_RR_TurnOFF_In);
	// message->ParseFromArray(req, in.ByteSizeLong());

  // Soa::PB_Car_Control_Enh_TurnLi_RR_TurnOFF_In* val = (Soa::PB_Car_Control_Enh_TurnLi_RR_TurnOFF_In*) message;
	// carControl_Car_Control_Enh_TurnLi_RR_TurnOFF_In ret;

  // convert_to_struct_TurnLiCtrlCmd(&val->turnlictrlcmd(), &ret.TurnLiCtrlCmd);
  // convert_to_struct_RequestInfo(&val->requestinfo(), &ret.RequestInfo);

  // INF("RR_TurnOFF_Topic: pos[%d] off[%d] on[%d] pri[%d] cnt[%d] efc[%d]\n",
  //     ret.TurnLiCtrlCmd.TurnLiCtrlPosn,
  //     ret.TurnLiCtrlCmd.TurnLiOffDurn,
  //     ret.TurnLiCtrlCmd.TurnLiOnDurn,
  //     ret.TurnLiCtrlCmd.TurnLiPRI,
  //     ret.TurnLiCtrlCmd.TurnLiCnt,
  //     ret.TurnLiCtrlCmd.TurnLiRecover,
  //     ret.TurnLiCtrlCmd.FlowingEfc);

  // INF("RR_TurnOFF_Topic: req_id[%x] ses_id[%x]\n",
  //     ret.RequestInfo.Request_ID, ret.RequestInfo.Session_ID);

	// delete(message);
/**************************************************************************/

    TIMER_COUNT_BEGIN(rr_turnoff);
    CVIURpcClient::Request(hashID, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    TIMER_COUNT_END(process_soc2dds_rpc:rr_turnoff, 1, rr_turnoff);
    //CRpcClient::Request(hashID, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    free(req);
  }

/* 例子 */
#if 0
  int32_t hashID = getHashIDFromTopic(topic);
  int32_t bufSize = msg.GetSize();
  void *buf = (void *)malloc(bufSize);
  memcpy(buf, msg.GetData(), bufSize);
  CRpcClient::Request(hashID, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
  free(buf);
  std::cout  << "soc2dds_event  hashID :" << hashID << " sent!" << std::endl;
#endif
}

void DDSNode:: process_mcu2dds_rpc(const std::string &topic, const zros::core::PlainBufMessage &msg)
{  
  struct LIVE_MSG *live_msg = (struct LIVE_MSG *)(msg.GetData());
  if (!live_msg)
  {
    ERR("mcu_live_msg_process category is NULL");
    return;
  }
  int category =  live_msg->id;
 switch (category)
 {
  case LIVE_MSG_DDS_RR_TURNON:
  {
    /*TurnLiCtrlCmd*/
    if (0xff == live_msg->data[0])
    {
      DBG("LIVE_MSG_DDS_RR_TURNON %d \n",live_msg->data[0]);
      break;
    }
    void *replybuf = nullptr;
    size_t replySize = 0;
    DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;	
    Soa::PB_TurnLiCtrlCmd pb_data ;
    convert_to_pb_TurnLiCtrlCmd(live_msg->data, &pb_data);
    Soa::PB_Car_Control_Enh_TurnLi_RR_TurnON_In in;
    in.mutable_turnlictrlcmd()->CopyFrom(pb_data);
    void *req = malloc(in.ByteSizeLong());
    in.SerializeToArray(req, in.ByteSizeLong());
    CVIURpcClient::Request(carControl_Car_Control_Enh_TurnLi_RR_TurnON_Hash, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    free(req);
    break;
  }
  case LIVE_MSG_DDS_RR_TURNOFF:
  {
    /*TurnLiCtrlCmd*/
    if (0xff == live_msg->data[0])
    {
      DBG("LIVE_MSG_DDS_RR_TURNOFF %d \n",live_msg->data[0]);
      break;
    }
    void *replybuf = nullptr;
    size_t replySize = 0;
    DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;	
    Soa::PB_TurnLiCtrlCmd pb_data ;
    convert_to_pb_TurnLiCtrlCmd(live_msg->data, &pb_data);
    Soa::PB_Car_Control_Enh_TurnLi_RR_TurnOFF_In in;
    in.mutable_turnlictrlcmd()->CopyFrom(pb_data);
    void *req = malloc(in.ByteSizeLong());
    in.SerializeToArray(req, in.ByteSizeLong());
    CVIURpcClient::Request(carControl_Car_Control_Enh_TurnLi_RR_TurnOFF_Hash, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    free(req);
    break;
  }
  case LIVE_MSG_DDS_RR_COMBHDLAMPCTRL:
  {
    //DBG("LIVE_MSG_DDS_RR_COMBHDLAMPCTRL %d \n",live_msg->data[0]);
    void *replybuf = nullptr;
    size_t replySize = 0;
    DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;	
    Soa::PB_TurnLiCtrlCmd pb_data ;
    convert_to_pb_TurnLiCtrlCmd(live_msg->data, &pb_data);
    Soa::PB_Car_Control_Cnr_HdLampCtrl_RR_CombHdLampCtrl_In in;
    in.set_combhdlampreq(live_msg->data[0]);
    void *req = malloc(in.ByteSizeLong());
    in.SerializeToArray(req, in.ByteSizeLong());
    CRpcClient::Request(carControl_Car_Control_Cnr_HdLampCtrl_RR_CombHdLampCtrl_Hash, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    free(req);
    break;
  }
  case LIVE_MSG_DDS_RR_WIPERCTRL:
  {
    //DBG("LIVE_MSG_DDS_RR_WIPERCTRL\n",);
    void *replybuf = nullptr;
    size_t replySize = 0;
    DDS_RPC_RemoteExceptionCode_t errorCode = DDS_RPC_REMOTE_EX_OK;	
    Soa::PB_TurnLiCtrlCmd pb_data ;
    convert_to_pb_TurnLiCtrlCmd(live_msg->data, &pb_data);
    Soa::PB_Car_Control_Enh_TurnLi_RR_TurnOFF_In in;
    in.mutable_turnlictrlcmd()->CopyFrom(pb_data);
    void *req = malloc(in.ByteSizeLong());
    in.SerializeToArray(req, in.ByteSizeLong());
    CRpcClient::Request(carControl_Car_Control_Cnr_FrntWiperCtrl_RR_WiperCtrl_Hash, req, in.ByteSizeLong(), &replybuf, replySize, errorCode);
    free(req);
    break;
  }
  break;
 }
}

void DDSNode::process_dds2soc_rpc(int32_t hash, void *request,size_t requestSize, void **reply,size_t &replySize,DDS_RPC_RemoteExceptionCode_t &errorCode)
{
  switch(hash)
  {
    case carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash:
    {
      Soa::PB_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_In in;
      Soa::PB_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Out out;
      in.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash recvd : edc_apadrvrreqonoff %d \n", in.edc_apadrvrreqonoffdata().edc_apadrvrreqonoff());
      
      void *buf = malloc(in.edc_apadrvrreqonoffdata().ByteSizeLong());
      in.edc_apadrvrreqonoffdata().SerializeToArray(buf, in.edc_apadrvrreqonoffdata().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.edc_apadrvrreqonoffdata().ByteSizeLong());
      this->publish(msg, "EDC_APADrvrReqOnOff_Topic");
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
case carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash:
    {
      Soa::PB_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_In in;
      Soa::PB_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Out out;
      in.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash recvd : edc_apadrvrreqslotid %d \n", in.edc_apadrvrreqslotiddata().edc_apadrvrreqslotid());
    
      void *buf = malloc(in.edc_apadrvrreqslotiddata().ByteSizeLong());
      in.edc_apadrvrreqslotiddata().SerializeToArray(buf, in.edc_apadrvrreqslotiddata().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.edc_apadrvrreqslotiddata().ByteSizeLong());
      this->publish(msg, "EDC_APADrvrReqSlotID_Topic");

      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }

    case carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash:
    {
      Soa::PB_Basc_APAInteract_RR_EDC_APAParkInSelect_In in;
      Soa::PB_Basc_APAInteract_RR_EDC_APAParkInSelect_Out out;
      in.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash recvd : edc_apaparkinselect %d \n", in.edc_apaparkinselectdata().edc_apaparkinselect());
      void *buf = malloc(in.edc_apaparkinselectdata().ByteSizeLong());
      in.edc_apaparkinselectdata().SerializeToArray(buf, in.edc_apaparkinselectdata().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.edc_apaparkinselectdata().ByteSizeLong());
      this->publish(msg, "EDC_APAParkInSelect_Topic");
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash:
    {
      Soa::PB_Basc_APAInteract_RR_EDC_APADynamicOperate_In in;
      Soa::PB_Basc_APAInteract_RR_EDC_APADynamicOperate_Out out;
      in.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash recvd : edc_apadynamicoperate %d \n", in.edc_apadynamicoperatedata().edc_apadynamicoperate());
      void *buf = malloc(in.edc_apadynamicoperatedata().ByteSizeLong());
      in.edc_apadynamicoperatedata().SerializeToArray(buf, in.edc_apadynamicoperatedata().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.edc_apadynamicoperatedata().ByteSizeLong());
      this->publish(msg, "EDC_APADynamicOperate_Topic");
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash:
    {
      Soa::PB_Basc_APAInteract_RR_EDC_APAParkOutSelect_In in;
      Soa::PB_Basc_APAInteract_RR_EDC_APAParkOutSelect_Out out;
      in.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash recvd : edc_apaparkoutselect %d \n", in.edc_apaparkoutselectdata().edc_apaparkoutselect());
      void *buf = malloc(in.edc_apaparkoutselectdata().ByteSizeLong());
      in.edc_apaparkoutselectdata().SerializeToArray(buf, in.edc_apaparkoutselectdata().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.edc_apaparkoutselectdata().ByteSizeLong());
      this->publish(msg, "EDC_APAParkOutSelect_Topic");
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash:
    {
      Soa::PB_Basc_APAInteract_RR_EDC_RADSDrvrReq_In in;
      Soa::PB_Basc_APAInteract_RR_EDC_RADSDrvrReq_Out out;

      in.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash recvd : edc_radsdrvrreq %d \n", in.edc_radsdrvrreqdata().edc_radsdrvrreq());
      void *buf = malloc(in.edc_radsdrvrreqdata().ByteSizeLong());
      in.edc_radsdrvrreqdata().SerializeToArray(buf, in.edc_radsdrvrreqdata().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.edc_radsdrvrreqdata().ByteSizeLong());
      this->publish(msg, "EDC_RADSDrvrReq_Topic");
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Hash:
    {
      Soa::PB_Basic_APAFunctionReq_RR_APAFunctionReq_In in;
      Soa::PB_Basic_APAFunctionReq_RR_APAFunctionReq_Out out;

      /* 解析输入数据 */
      in.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Hash\n");
      
      /* soc内部通讯发送 */
      void *buf = malloc(in.rr_apafunctionreq().ByteSizeLong());
      in.rr_apafunctionreq().SerializeToArray(buf, in.rr_apafunctionreq().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.rr_apafunctionreq().ByteSizeLong());
      this->publish(msg, "EDC_APAFunctionReq_Topic");
      
      /* 返回响应信号 */
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basic_APAFunctionReq_RR_APAControleReq_Hash:
    {
      Soa::PB_Basic_APAFunctionReq_RR_APAControleReq_In in;
      Soa::PB_Basic_APAFunctionReq_RR_APAControleReq_Out out;

      /* 解析输入数据 */
      in.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basic_APAFunctionReq_RR_APAControleReq_Hash\n");
      
      /* soc内部通讯发送 */
      void *buf = malloc(in.apacontrolreq().ByteSizeLong());
      in.apacontrolreq().SerializeToArray(buf, in.apacontrolreq().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.apacontrolreq().ByteSizeLong());
      this->publish(msg, "EDC_APAControleReq_Topic");
      
      /* 返回响应信号 */
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    #if 0
    case carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Hash:
    {
      break;
    }

    case carDrive_Basc_ADASCruiseSet_RR_HU_LaneChangeFrequency_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_LaneChangeFrequency_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_LaneChangeFrequency_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_lanechangefrequency().ByteSizeLong());
      in.huset_lanechangefrequency().SerializeToArray(buf, in.huset_lanechangefrequency().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_lanechangefrequency().ByteSizeLong());
      this->publish(msg, "HUset_LaneChangeFrequency");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_LaneChangeFrequency_Hash recvd : hu_lanechangefrequency %d \n", in.huset_lanechangefrequency().hu_lanechangefrequency());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      free(buf);
      errorCode = DDS_RPC_REMOTE_EX_OK ;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_UDLCEnable_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_UDLCEnable_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_UDLCEnable_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_udlcenable().ByteSizeLong());
      in.huset_udlcenable().SerializeToArray(buf, in.huset_udlcenable().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_udlcenable().ByteSizeLong());
      this->publish(msg, "HUset_UDLCEnable");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_UDLCEnable_Hash recvd : hu_udlcenable %d \n", in.huset_udlcenable().hu_udlcenable());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_NIDAudioWarStyle_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_NIDAudioWarStyle_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_NIDAudioWarStyle_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_nidaudiowarstyle().ByteSizeLong());
      in.huset_nidaudiowarstyle().SerializeToArray(buf, in.huset_nidaudiowarstyle().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_nidaudiowarstyle().ByteSizeLong());
      this->publish(msg, "HUset_NIDAudioWarStyle");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_NIDAudioWarStyle_Hash recvd : HUset_NIDAudioWarStyle %d \n", in.huset_nidaudiowarstyle().hu_nidaudiowarstyle());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_CSLAEnable_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLAEnable_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLAEnable_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_cslaenable().ByteSizeLong());
      in.huset_cslaenable().SerializeToArray(buf, in.huset_cslaenable().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_cslaenable().ByteSizeLong());
      this->publish(msg, "HUset_CSLAEnable");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_CSLAEnable_Hash recvd : HUset_CSLAEnable %d \n", in.huset_cslaenable().hu_cslaenable());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_CSLmode_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLmode_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLmode_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_cslmode().ByteSizeLong());
      in.huset_cslmode().SerializeToArray(buf, in.huset_cslmode().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_cslmode().ByteSizeLong());
      this->publish(msg, "HUset_CSLmode");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_CSLmode_Hash recvd : HUset_CSLmode %d \n", in.huset_cslmode().hu_cslmode());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_overspeedsoundwarenable().ByteSizeLong());
      in.huset_overspeedsoundwarenable().SerializeToArray(buf, in.huset_overspeedsoundwarenable().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_overspeedsoundwarenable().ByteSizeLong());
      this->publish(msg, "HUset_OverspeedSoundWarEnable");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_Hash recvd : HUset_OverspeedSoundWarEnable %d \n", in.huset_overspeedsoundwarenable().hu_overspeedsoundwarenable());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_CSLWarnOffsetTp_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLWarnOffsetTp_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLWarnOffsetTp_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_cslwarnoffsettp().ByteSizeLong());
      in.huset_cslwarnoffsettp().SerializeToArray(buf, in.huset_cslwarnoffsettp().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_cslwarnoffsettp().ByteSizeLong());
      this->publish(msg, "HUset_CSLWarnOffsetTp");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_CSLWarnOffsetTp_Hash recvd : HUset_CSLWarnOffsetTp %d \n", in.huset_cslwarnoffsettp().hu_cslwarnoffsettp());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_AbsOverSpdWarnOffset_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_AbsOverSpdWarnOffset_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_AbsOverSpdWarnOffset_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_absoverspdwarnoffset().ByteSizeLong());
      in.huset_absoverspdwarnoffset().SerializeToArray(buf, in.huset_absoverspdwarnoffset().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_absoverspdwarnoffset().ByteSizeLong());
      this->publish(msg, "HUset_AbsOverSpdWarnOffset");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_AbsOverSpdWarnOffset_Hash recvd : HUset_AbsOverSpdWarnOffset %d \n", in.huset_absoverspdwarnoffset().hu_absoverspdwarnoffset());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_RelOverSpdWarnOffset_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_RelOverSpdWarnOffset_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_RelOverSpdWarnOffset_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_reloverspdwarnoffset().ByteSizeLong());
      in.huset_reloverspdwarnoffset().SerializeToArray(buf, in.huset_reloverspdwarnoffset().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_reloverspdwarnoffset().ByteSizeLong());
      this->publish(msg, "HUset_RelOverSpdWarnOffset");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_RelOverSpdWarnOffset_Hash recvd : HUset_RelOverSpdWarnOffset %d \n", in.huset_reloverspdwarnoffset().hu_reloverspdwarnoffset());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_autodrivestyle().ByteSizeLong());
      in.huset_autodrivestyle().SerializeToArray(buf, in.huset_autodrivestyle().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_autodrivestyle().ByteSizeLong());
      this->publish(msg, "HUset_AutoDriveStyle");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_Hash recvd : HUset_AutoDriveStyle %d \n", in.huset_autodrivestyle().hu_autodrivestyle());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_ADACCStyle_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_ADACCStyle_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_ADACCStyle_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_adaccstyle().ByteSizeLong());
      in.huset_adaccstyle().SerializeToArray(buf, in.huset_adaccstyle().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_adaccstyle().ByteSizeLong());
      this->publish(msg, "HUset_ADACCStyle");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_ADACCStyle_Hash recvd : HUset_ADACCStyle %d \n", in.huset_adaccstyle().hu_adaccstyle());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_ADStartStyle_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_ADStartStyle_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_ADStartStyle_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_adstartstyle().ByteSizeLong());
      in.huset_adstartstyle().SerializeToArray(buf, in.huset_adstartstyle().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_adstartstyle().ByteSizeLong());
      this->publish(msg, "HUset_ADStartStyle");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_ADStartStyle_Hash recvd : HUset_ADStartStyle %d \n", in.huset_adstartstyle().hu_adstartstyle());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_adcurvestyle().ByteSizeLong());
      in.huset_adcurvestyle().SerializeToArray(buf, in.huset_adcurvestyle().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_adcurvestyle().ByteSizeLong());
      this->publish(msg, "HUset_ADCurveStyle");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_Hash recvd : HUset_ADCurveStyle %d \n", in.huset_adcurvestyle().hu_adcurvestyle());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_ADLanechangeStyle_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_ADLanechangeStyle_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_ADLanechangeStyle_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_adlanechangestyle().ByteSizeLong());
      in.huset_adlanechangestyle().SerializeToArray(buf, in.huset_adlanechangestyle().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_adlanechangestyle().ByteSizeLong());
      this->publish(msg, "HUset_ADLanechangeStyle");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_ADLanechangeStyle_Hash recvd : HUset_ADLanechangeStyle %d \n", in.huset_adlanechangestyle().hu_adlanechangestyle());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    } 
    case carDrive_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_vehiclestartremindenable().ByteSizeLong());
      in.huset_vehiclestartremindenable().SerializeToArray(buf, in.huset_vehiclestartremindenable().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_vehiclestartremindenable().ByteSizeLong());
      this->publish(msg, "HUset_VehicleStartRemindEnable");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_Hash recvd : HUset_VehicleStartRemindEnable %d \n", in.huset_vehiclestartremindenable().hu_vehiclestartremindenable());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_RR_HU_RCWEnable_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_RCWEnable_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_RCWEnable_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_rcwenable().ByteSizeLong());
      in.huset_rcwenable().SerializeToArray(buf, in.huset_rcwenable().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_rcwenable().ByteSizeLong());
      this->publish(msg, "HUset_RCWEnable");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_RCWEnable_Hash recvd : HUset_RCWEnable %d \n", in.huset_rcwenable().hu_rcwenable());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }     
    case carDrive_Basc_ADASCruiseSet_RR_HU_SEAMode_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_SEAMode_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_SEAMode_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_seamode().ByteSizeLong());
      in.huset_seamode().SerializeToArray(buf, in.huset_seamode().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_seamode().ByteSizeLong());
      this->publish(msg, "HUset_SEAMode");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_SEAMode_Hash recvd : HUset_SEAMode %d \n", in.huset_seamode().hu_seamode());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }               
    case carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_bsdlcasetting().ByteSizeLong());
      in.huset_bsdlcasetting().SerializeToArray(buf, in.huset_bsdlcasetting().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_bsdlcasetting().ByteSizeLong());
      this->publish(msg, "HUset_BSDLCASetting");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_Hash recvd : HUset_BSDLCASetting %d \n", in.huset_bsdlcasetting().hu_bsdlcasetting());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }    
    case carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_bsdlcaremindmode().ByteSizeLong());
      in.huset_bsdlcaremindmode().SerializeToArray(buf, in.huset_bsdlcaremindmode().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_bsdlcaremindmode().ByteSizeLong());
      this->publish(msg, "HUset_BSDLCARemindmode");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_Hash recvd : HUset_BSDLCARemindmode %d \n", in.huset_bsdlcaremindmode().hu_bsdlcaremindmode());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    } 
    case carDrive_Basc_ADASCruiseSet_RR_HU_IACCFamlrRdModSwt_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_IACCFamlrRdModSwt_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_IACCFamlrRdModSwt_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_iaccfamlrrdmodswt().ByteSizeLong());
      in.huset_iaccfamlrrdmodswt().SerializeToArray(buf, in.huset_iaccfamlrrdmodswt().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_iaccfamlrrdmodswt().ByteSizeLong());
      this->publish(msg, "HUset_IACCFamlrRdModSwt");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_IACCFamlrRdModSwt_Hash recvd : HUset_IACCFamlrRdModSwt %d \n", in.huset_iaccfamlrrdmodswt().hu_iaccfamlrrdmodswt());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    } 
    case carDrive_Basc_ADASCruiseSet_RR_HU_IDAEnable_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_IDAEnable_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_IDAEnable_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_idaenable().ByteSizeLong());
      in.huset_idaenable().SerializeToArray(buf, in.huset_idaenable().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_idaenable().ByteSizeLong());
      this->publish(msg, "HUset_IDAEnable");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_IDAEnable_Hash recvd : HUset_IDAEnable %d \n", in.huset_idaenable().hu_idaenable());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    } 
    case carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_RR_HU_CuriseMode_In in;
      Soa::PB_Basc_ADASCruiseSet_RR_HU_CuriseMode_Out out;
      in.ParseFromArray(request, requestSize);
      void *buf = malloc(in.huset_curisemode().ByteSizeLong());
      in.huset_curisemode().SerializeToArray(buf, in.huset_curisemode().ByteSizeLong());
      zros::core::PlainBufMessage msg(buf, in.huset_curisemode().ByteSizeLong());
      this->publish(msg, "HUset_CuriseMode");     
      INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash recvd : HUset_CuriseMode %d \n", in.huset_curisemode().hu_curisemode());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    }
    case carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash:
    {
      Soa::PB_Basc_ADASCruiseSet_Get_ADASCruiseSet_In in;
      Soa::PB_Basc_ADASCruiseSet_Get_ADASCruiseSet_Out out;
      void *buf = malloc(in.ByteSizeLong());
      in.SerializeToArray(buf, in.ByteSizeLong());
      out.ParseFromArray(request, requestSize);
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_CuriseMode %d \n", out.mutable_return_()->ad_curisemode());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_IDAEnableStatus %d \n", out.mutable_return_()->ad_idaenablestatus());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_IDAstatus %d \n", out.mutable_return_()->ad_idastatus());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_LaneChangeFrequency %d \n", out.mutable_return_()->ad_lanechangefrequency());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_UDLCEnableStatus %d \n", out.mutable_return_()->ad_udlcenablestatus());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_NIDAudioWarStyle %d \n", out.mutable_return_()->ad_nidaudiowarstyle());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_CSLAEnableStatus %d \n", out.mutable_return_()->ad_cslaenablestatus());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_CSLmodeStatus %d \n", out.mutable_return_()->ad_cslmodestatus());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_OverspeedSoundWarningEnSt %d \n", out.mutable_return_()->ad_overspeedsoundwarningenst());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_CSLWarnOffsetTp %d \n", out.mutable_return_()->ad_cslwarnoffsettp());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_AbsOverSpdWarnOffset %d \n", out.mutable_return_()->ad_absoverspdwarnoffset());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_RelOverSpdWarnOffset %d \n", out.mutable_return_()->ad_reloverspdwarnoffset());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_AutoDriveStyle %d \n", out.mutable_return_()->ad_autodrivestyle());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_ADACCStyle %d \n", out.mutable_return_()->ad_adaccstyle());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_ADStartStyle %d \n", out.mutable_return_()->ad_adstartstyle());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_ADCurveStyle %d \n", out.mutable_return_()->ad_adcurvestyle());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_ADLanechangeStyle %d \n", out.mutable_return_()->ad_adlanechangestyle());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_VehicleStartRemindEnable %d \n", out.mutable_return_()->ad_vehiclestartremindenable());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_RCWEnableStatus %d \n", out.mutable_return_()->ad_rcwenablestatus());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_SEAModeStatus %d \n", out.mutable_return_()->ad_seamodestatus());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_BSDLCASetting %d \n", out.mutable_return_()->ad_bsdlcasetting());
      INF("RPC carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash recvd : AD_BSDLCARemindmode %d \n", out.mutable_return_()->ad_bsdlcaremindmode());
      replySize = out.ByteSizeLong();
      *reply = malloc(replySize);
      out.SerializeToArray(*reply, out.ByteSizeLong());
      errorCode = DDS_RPC_REMOTE_EX_OK;
      free(buf);
      break;
    } 
    // case carDrive_Basc_ADASvoiceCtr_RR_HU_VC_ACCactive_Hash:
    // {
    //   Soa::PB_Basc_ADASvoiceCtr_RR_HU_VC_ACCactive_In in;
    //   Soa::PB_Basc_ADASvoiceCtr_RR_HU_VC_ACCactive_Out out;
    //   in.ParseFromArray(request, requestSize);
    //   void *buf = malloc(in.huset_vc_accactive().ByteSizeLong());
    //   in.huset_vc_accactive().SerializeToArray(buf, in.huset_vc_accactive().ByteSizeLong());
    //   zros::core::PlainBufMessage msg(buf, in.huset_vc_accactive().ByteSizeLong());
    //   this->publish(msg, "HUset_VC_ACCactive");     
    //   INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash recvd : HUset_VC_ACCactive %d \n", in.huset_vc_accactive().hu_vc_accactive());
    //   this->publish(msg, "HU_VC_CruiseSetDistance");     
    //   INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash recvd : HU_VC_CruiseSetDistance %d \n", in.huset_vc_accactive().hu_vc_cruisesetdistance());     
    //   this->publish(msg, "HU_VC_CruiseSetSpeed");     
    //   INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash recvd : HU_VC_CruiseSetSpeed %d \n", in.huset_vc_accactive().hu_vc_cruisesetspeed());
    //   this->publish(msg, "HU_LaneChangeReq");     
    //   INF("RPC carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash recvd : hu_lanechangereq %d \n", in.huset_vc_accactive().hu_lanechangereq());      
    //   out.mutable_return_()->set_request_id(1);
    //   replySize = out.ByteSizeLong();
    //   *reply = malloc(replySize);
    //   out.SerializeToArray(*reply, out.ByteSizeLong());
    //   errorCode = DDS_RPC_REMOTE_EX_OK;
    //   break;
    // }

    

    // case carDrive_Basc_ADASCruiseSet_Get_ADASCruiseSet_Hash:
    // {
    //   Soa::PB_Basc_ADASCruiseSet_Get_ADASCruiseSet_In in;
    //   Soa::PB_Basc_ADASCruiseSet_Get_ADASCruiseSet_Out out;
    //   out.mutable_return_()->set_ad_curisemode(1);
    //   replySize = out.ByteSizeLong();
    //   *reply = malloc(replySize);
    //   out.SerializeToArray(*reply, out.ByteSizeLong());
    //   errorCode = DDS_RPC_REMOTE_EX_OK;
    //   break;
    // }
#endif
    default :
    {
      ERR("No HashId %d \n", hash);
      *reply = malloc(1024);

      errorCode = DDS_RPC_REMOTE_EX_UNSUPPORTED ;
      break;
    }
  }
}

void DDSNode:: process_dds2mcu_rpc(int32_t hash, void *request,size_t requestSize, void **reply,size_t &replySize,DDS_RPC_RemoteExceptionCode_t &errorCode)
{
  int category = getLiveMsgCategoryFromHashID(hash);
  
  if (category > -1)
  {
    DBG("process_dds2mcu_rpc: cate[%d] recive.\n", category);
    switch (hash)
    {
      case carDrive_Basc_ADASvoiceCtr_RR_HU_LaneChangeReq_Hash:
      {
        Soa::PB_Basc_ADASvoiceCtr_RR_HU_LaneChangeReq_In in;
        Soa::PB_Basc_ADASvoiceCtr_RR_HU_LaneChangeReq_Out out;
        in.ParseFromArray(request, requestSize);
        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_LaneChangeReq data;
        Soa::PB_HUset_LaneChangeReq pd_data = in.huset_lanechangereq();
        convert_to_struct_HUset_LaneChangeReq(&pd_data, &data);
        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));
      }
      case carDrive_Basc_ADASvoiceCtr_RR_HU_VC_ACCactive_Hash              :
      {
        Soa::PB_Basc_ADASvoiceCtr_RR_HU_VC_ACCactive_In in;
        Soa::PB_Basc_ADASvoiceCtr_RR_HU_VC_ACCactive_Out out;
        in.ParseFromArray(request, requestSize);
        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_VC_ACCactive data;
        Soa::PB_HUset_VC_ACCactive pd_data = in.huset_vc_accactive();
        convert_to_struct_HUset_VC_ACCactive(&pd_data, &data);
        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASvoiceCtr_RR_HU_VC_CruiseSetDistance_Hash      :
      {
        Soa::PB_Basc_ADASvoiceCtr_RR_HU_VC_CruiseSetDistance_In in;
        Soa::PB_Basc_ADASvoiceCtr_RR_HU_VC_CruiseSetDistance_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_VC_CruiseSetDistance data;
        Soa::PB_HUset_VC_CruiseSetDistance pd_data = in.huset_vc_cruisesetdistance();
        convert_to_struct_HUset_VC_CruiseSetDistance(&pd_data, &data);
        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASvoiceCtr_RR_HU_VC_CruiseSetSpeed_Hash         :
      {
        Soa::PB_Basc_ADASvoiceCtr_RR_HU_VC_CruiseSetSpeed_In in;
        Soa::PB_Basc_ADASvoiceCtr_RR_HU_VC_CruiseSetSpeed_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_VC_CruiseSetSpeed data;
        Soa::PB_HUset_VC_CruiseSetSpeed pd_data = in.huset_vc_cruisesetspeed();
        convert_to_struct_HUset_VC_CruiseSetSpeed(&pd_data, &data);
        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_CSLAEnable_Hash               :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLAEnable_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLAEnable_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_CSLAEnable data;
        Soa::PB_HUset_CSLAEnable pd_data = in.huset_cslaenable();
        convert_to_struct_HUset_CSLAEnable(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_CSLAEnable_Hash: cate[%d:%d]\n",
            category, data.HU_CSLAEnable);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_CSLmode_Hash                  :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLmode_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_CSLmode_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_CSLmode data;
        Soa::PB_HUset_CSLmode pd_data = in.huset_cslmode();
        convert_to_struct_HUset_CSLmode(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_CSLmode_Hash: cate[%d:%d]\n",
            category, data.HU_CSLmode);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash               :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_CuriseMode_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_CuriseMode_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_CuriseMode data;
        Soa::PB_HUset_CuriseMode pd_data = in.huset_curisemode();
        convert_to_struct_HUset_CuriseMode(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_CuriseMode_Hash: cate[%d:%d]\n",
            category, data.HU_CuriseMode);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_Hash  :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_OverspeedSoundWarEnable data;
        Soa::PB_HUset_OverspeedSoundWarEnable pd_data = in.huset_overspeedsoundwarenable();
        convert_to_struct_HUset_OverspeedSoundWarEnable(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_OverspeedSoundWarEnable_Hash: cate[%d:%d]\n",
            category, data.HU_OverspeedSoundWarEnable);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_UDLCEnable_Hash               :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_UDLCEnable_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_UDLCEnable_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_UDLCEnable data;
        Soa::PB_HUset_UDLCEnable pd_data = in.huset_udlcenable();
        convert_to_struct_HUset_UDLCEnable(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_UDLCEnable_Hash: cate[%d:%d]\n",
            category, data.HU_UDLCEnable);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_Hash           :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_AutoDriveStyle data;
        Soa::PB_HUset_AutoDriveStyle pd_data = in.huset_autodrivestyle();
        convert_to_struct_HUset_AutoDriveStyle(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_AutoDriveStyle_Hash: cate[%d:%d]\n",
            category, data.HU_AutoDriveStyle);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_ADACCStyle_Hash               :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_ADACCStyle_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_ADACCStyle_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_ADACCStyle data;
        Soa::PB_HUset_ADACCStyle pd_data = in.huset_adaccstyle();
        convert_to_struct_HUset_ADACCStyle(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_ADACCStyle_Hash: cate[%d:%d]\n",
            category, data.HU_ADACCStyle);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_Hash             :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_ADCurveStyle data;
        Soa::PB_HUset_ADCurveStyle pd_data = in.huset_adcurvestyle();
        convert_to_struct_HUset_ADCurveStyle(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_ADCurveStyle_Hash: cate[%d:%d]\n",
            category, data.HU_ADCurveStyle);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_ADStartStyle_Hash             :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_ADStartStyle_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_ADStartStyle_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_ADStartStyle data;
        Soa::PB_HUset_ADStartStyle pd_data = in.huset_adstartstyle();
        convert_to_struct_HUset_ADStartStyle(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_ADStartStyle_Hash: cate[%d:%d]\n",
            category, data.HU_ADStartStyle);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_Hash :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_VehicleStartRemindEnable data;
        Soa::PB_HUset_VehicleStartRemindEnable pd_data = in.huset_vehiclestartremindenable();
        convert_to_struct_HUset_VehicleStartRemindEnable(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_VehicleStartRemindEnable_Hash: cate[%d:%d]\n",
            category, data.HU_VehicleStartRemindEnable);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_RCWEnable_Hash                :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_RCWEnable_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_RCWEnable_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_RCWEnable data;
        Soa::PB_HUset_RCWEnable pd_data = in.huset_rcwenable();
        convert_to_struct_HUset_RCWEnable(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_RCWEnable_Hash: cate[%d:%d]\n",
            category, data.HU_RCWEnable);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_SEAMode_Hash                  :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_SEAMode_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_SEAMode_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_SEAMode data;
        Soa::PB_HUset_SEAMode pd_data = in.huset_seamode();
        convert_to_struct_HUset_SEAMode(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_SEAMode_Hash: cate[%d:%d]\n",
            category, data.HU_SEAMode);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_Hash            :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_BSDLCASetting data;
        Soa::PB_HUset_BSDLCASetting pd_data = in.huset_bsdlcasetting();
        convert_to_struct_HUset_BSDLCASetting(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCASetting_Hash: cate[%d:%d]\n",
            category, data.HU_BSDLCASetting);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_Hash         :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_BSDLCARemindmode data;
        Soa::PB_HUset_BSDLCARemindmode pd_data = in.huset_bsdlcaremindmode();
        convert_to_struct_HUset_BSDLCARemindmode(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCARemindmode_Hash: cate[%d:%d]\n",
            category, data.HU_BSDLCARemindmode);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));
        break;
      }  
      case carDrive_Basc_ADASSecureSet_RR_HU_RedLightRemindEnable_Hash     :
      {
        Soa::PB_Basc_ADASSecureSet_RR_HU_RedLightRemindEnable_In in;
        Soa::PB_Basc_ADASSecureSet_RR_HU_RedLightRemindEnable_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_RedLightRemindEnable data;
        Soa::PB_HUset_RedLightRemindEnable pd_data = in.huset_redlightremindenable();
        convert_to_struct_HUset_RedLightRemindEnable(&pd_data, &data);
        INF("carDrive_Basc_ADASSecureSet_RR_HU_RedLightRemindEnable_Hash: cate[%d:%d]\n",
            category, data.HU_RedLightRemindEnable);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASSecureSet_RR_HU_ForwardColliAstType_Hash      :
      {
        Soa::PB_Basc_ADASSecureSet_RR_HU_ForwardColliAstType_In in;
        Soa::PB_Basc_ADASSecureSet_RR_HU_ForwardColliAstType_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_ForwardColliAstType data;
        Soa::PB_HUset_ForwardColliAstType pd_data = in.huset_forwardcolliasttype();
        convert_to_struct_HUset_ForwardColliAstType(&pd_data, &data);
        INF("carDrive_Basc_ADASSecureSet_RR_HU_ForwardColliAstType_Hash: cate[%d:%d]\n",
            category, data.HU_ForwardColliAstType);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASSecureSet_RR_HU_ForwardColliAstSenStyle_Hash  :
      {
        Soa::PB_Basc_ADASSecureSet_RR_HU_ForwardColliAstSenStyle_In in;
        Soa::PB_Basc_ADASSecureSet_RR_HU_ForwardColliAstSenStyle_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_ForwardColliAstSenStyle data;
        Soa::PB_HUset_ForwardColliAstSenStyle pd_data = in.huset_forwardcolliastsenstyle();
        convert_to_struct_HUset_ForwardColliAstSenStyle(&pd_data, &data);
        INF("carDrive_Basc_ADASSecureSet_RR_HU_ForwardColliAstSenStyle_Hash: cate[%d:%d]\n",
            category, data.HU_ForwardColliAstSenStyle);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASSecureSet_RR_HU_RearColliAstType_Hash         :
      {
        Soa::PB_Basc_ADASSecureSet_RR_HU_RearColliAstType_In in;
        Soa::PB_Basc_ADASSecureSet_RR_HU_RearColliAstType_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_RearColliAstType data;
        Soa::PB_HUset_RearColliAstType pd_data = in.huset_rearcolliasttype();
        convert_to_struct_HUset_RearColliAstType(&pd_data, &data);
        INF("carDrive_Basc_ADASSecureSet_RR_HU_RearColliAstType_Hash: cate[%d:%d]\n",
            category, data.HU_RearColliAstType);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASSecureSet_RR_HU_LASModeSelection_Hash         :
      {
        Soa::PB_Basc_ADASSecureSet_RR_HU_LASModeSelection_In in;
        Soa::PB_Basc_ADASSecureSet_RR_HU_LASModeSelection_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_LASModeSelection data;
        Soa::PB_HUset_LASModeSelection pd_data = in.huset_lasmodeselection();
        convert_to_struct_HUset_LASModeSelection(&pd_data, &data);
        INF("carDrive_Basc_ADASSecureSet_RR_HU_LASModeSelection_Hash: cate[%d:%d]\n",
            category, data.HU_LASModeSelection);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASSecureSet_RR_HU_LASWarningModeSelection_Hash  :
      {
        Soa::PB_Basc_ADASSecureSet_RR_HU_LASWarningModeSelection_In in;
        Soa::PB_Basc_ADASSecureSet_RR_HU_LASWarningModeSelection_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_LASWarningModeSelection data;
        Soa::PB_HUset_LASWarningModeSelection pd_data = in.huset_laswarningmodeselection();
        convert_to_struct_HUset_LASWarningModeSelection(&pd_data, &data);
        INF("carDrive_Basc_ADASSecureSet_RR_HU_LASWarningModeSelection_Hash: cate[%d:%d]\n",
            category, data.HU_LASWarningModeSelection);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASSecureSet_RR_HU_CESEnable_Hash                :
      {
        Soa::PB_Basc_ADASSecureSet_RR_HU_CESEnable_In in;
        Soa::PB_Basc_ADASSecureSet_RR_HU_CESEnable_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_CESEnable data;
        Soa::PB_HUset_CESEnable pd_data = in.huset_cesenable();
        convert_to_struct_HUset_CESEnable(&pd_data, &data);
        INF("carDrive_Basc_ADASSecureSet_RR_HU_CESEnable_Hash: cate[%d:%d]\n",
            category, data.HU_CESEnable);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASSecureSet_RR_HU_ELKEnable_Hash                :
      {
        Soa::PB_Basc_ADASSecureSet_RR_HU_ELKEnable_In in;
        Soa::PB_Basc_ADASSecureSet_RR_HU_ELKEnable_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_ELKEnable data;
        Soa::PB_HUset_ELKEnable pd_data = in.huset_elkenable();
        convert_to_struct_HUset_ELKEnable(&pd_data, &data);
        INF("carDrive_Basc_ADASSecureSet_RR_HU_ELKEnable_Hash: cate[%d:%d]\n",
            category, data.HU_ELKEnable);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_SEAOnOff_Hash                :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_SEAOnOff_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_SEAOnOff_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_SEAOnOff data;
        Soa::PB_HUset_SEAOnOff pd_data = in.huset_seaonoff();
        convert_to_struct_HUset_SEAOnOff(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_SEAOnOff_Hash: cate[%d:%d]\n",
            category, data.HU_SEAOnOff);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      case carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCAOnOff_Hash                :
      {
        Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCAOnOff_In in;
        Soa::PB_Basc_ADASCruiseSet_RR_HU_BSDLCAOnOff_Out out;
        in.ParseFromArray(request, requestSize);

        replySize = out.ByteSizeLong();
        *reply = malloc(replySize);
        out.SerializeToArray(*reply, out.ByteSizeLong());
        errorCode = DDS_RPC_REMOTE_EX_OK;

        HUset_BSDLCAOnOff data;
        Soa::PB_HUset_BSDLCAOnOff pd_data = in.huset_bsdlcaonoff();
        convert_to_struct_HUset_BSDLCAOnOff(&pd_data, &data);
        INF("carDrive_Basc_ADASCruiseSet_RR_HU_BSDLCAOnOff_Hash: cate[%d:%d]\n",
            category, data.HU_BSDLCAOnOff);

        struct LIVE_MSG_DATA_SIZE16 msg;
        live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
        live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
        live_msg_send(&msg.header);
        // sendToMcuWithTimestamp(category, &data, sizeof(data));

        break;
      }
      default:
      break;
    }
  }
} 

bool DDSNode::startWork_dds2zm_rpc(const config &mConfig)
{
  CRpcServer::SetConfig(mConfig);
  std::string  str_dst = "null";
  std::function<void(int32_t, void *, size_t, void **, size_t &, DDS_RPC_RemoteExceptionCode_t &)>
  rpc_func_soc = [this](int32_t hash_id, void *request, size_t requestsize, void **reply, size_t &replysize,
                    DDS_RPC_RemoteExceptionCode_t error_code) {
    process_dds2soc_rpc( hash_id, request, requestsize, reply, replysize, error_code);
    };
  std::function<void(int32_t, void *, size_t, void **, size_t &, DDS_RPC_RemoteExceptionCode_t &)>
  rpc_func_mcu = [this](int32_t hash_id, void *request, size_t requestsize, void **reply, size_t &replysize,
                    DDS_RPC_RemoteExceptionCode_t error_code) {
    process_dds2mcu_rpc( hash_id, request, requestsize, reply, replysize, error_code);
    };
    for (const auto &itmap : mConfig.skeletons.server)
    {
      for(const auto &it : itmap.second.hash_ids)
      {
        int dst = getEventDestFromHashID(it);
        if (dst == DEST_SOC)
        {
            CRpcServer::Reply(it, rpc_func_soc);
            str_dst = "soc";
        }
        else if(DEST_MCU == dst)
        {
            CRpcServer::Reply(it, rpc_func_mcu);
            str_dst = "mcu";
        }
        else
        {
          str_dst = "null";
        }
        INF("dds2zm_rpc server HashID %d Reply! DEST: %s \n",it, str_dst.c_str());
      }
    }


  CRpcServer::Init();

  return true;
}

bool DDSNode::startWork_zm2dds_rpc(const config &mConfig)
{
  CRpcClient::SetConfig(mConfig);
  CRpcClient::Init();
  CVIURpcClient::SetConfig(mConfig);
  CVIURpcClient::Init();
    for (int i = 0; i < sizeof(rpc_msg_map) /sizeof(rpc_msg_map_t); i++)
    {
        if (DEST_SOC == rpc_msg_map[i].src && DEST_DDS == rpc_msg_map[i].dest)
        {
            zros::core::Subscriber<zros::core::PlainBufMessage>::SharedPtr subPtr =
            zros::core::Transport::Instance()->CreateSubscriber<zros::core::PlainBufMessage>(rpc_msg_map[i].topic, zros::core::TOPIC_MESSAGE);
            if (nullptr == subPtr)
            {
                return false;
            }
            subPtr->RegisterCallback([this, mConfig](const std::string &topic, const zros::core::PlainBufMessage &msg) 
            {
                process_soc2dds_rpc(topic, msg);
            });
            if (!subPtr->Start())
            {
                return false;
            }
            m_subscriberVec.push_back(subPtr);
            INF("soc2dds_rpc topic : %s Subscriber! \n", rpc_msg_map[i].topic.c_str());
        }
    }
      zros::core::Subscriber<zros::core::PlainBufMessage>::SharedPtr subPtr = 
      zros::core::Transport::Instance()->CreateSubscriber<zros::core::PlainBufMessage>(live_msg_category_name(LIVE_MSG_CATEGORY_CA_MCU_TO_EDC_AGENT));
      string  t = live_msg_category_name(LIVE_MSG_CATEGORY_CA_MCU_TO_EDC_AGENT);
      if (subPtr == nullptr)
      {
          return false;
      }

      subPtr->RegisterCallback([this, mConfig](const std::string &topic, const zros::core::PlainBufMessage &msg) 
      {
          process_mcu2dds_rpc(topic, msg);
      });
      if (!subPtr->Start())
      {
          return false;
      }
      m_live_msg_subscriberVec.push_back(subPtr);
      INF("mcu2dds_rpc live msg %s Subscriber! \n",  t.c_str() );
  return true;
}

