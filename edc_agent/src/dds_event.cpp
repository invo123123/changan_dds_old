#include "dds_node.h"
#include <thread>
#include "dynamic/Event.h"
#include "dynamic/Rpc.h"
#include "live_msg_oem_soc_to_mcu_Types.h"
#include "live_msg_cx_mcu_to_edc_agent_Types.h"
#include "zros/live_msgs/live_msg.h"
#include "hmi_basic_statefusion.pb.h"
#include "hmi_basic_smartdrivingtips.pb.h"
#include "hmi_basic_convoyfun.pb.h"
#include "hmi_basic_trafficlightscene.pb.h"
#include "hmi_basic_trafficsign.pb.h"
//#include "hmi_basic_maproadscene.pb.h"
#include "hmi.h"
#include "DDS_PB.h"


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
}event_msg_map_t;


static event_msg_map_t event_msg_map[] = 
{

  /*********************************************************SOC2DDS EVENT*****************************************************************/
  {carDrive_Basc_APAFctnSta_Ntf_AD_APAFctnSta_Hash                          , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "Basc_APAFctnSta_skeleton_Ntf_AD_APAFctnSta"},
  {carDrive_Basc_APAInteract_Ntf_AD_APADynrecommd_Hash                      , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "Basc_APAInteract_skeleton_Ntf_AD_APADynrecommd"},
  {carDrive_Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_Hash                     , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "Basc_APAInteract_skeleton_Ntf_AD_APAFctnIndnMsg"},
  {carDrive_Basc_Objfusion32_Ntf_Objfusion32_Hash                           , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "hmi_interface____HmiInterface__BasicObjfusion32"},
  {carDrive_Basc_Slotscene_Ntf_Slotscene_Hash                               , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "hmi_interface____HmiInterface__C22EDCSlotInfos"},
  {carDrive_Basic_RoadScene_Ntf_MapRoadScene_Hash                           , DEST_SOC, DEST_DDS, LIVE_MSG_CATEGORY_INVAILD, "hmi_interface____HmiInterface__BasicMapRoadScene"},
  
  /* ------------------------------------------------------- MCU-->DDS EVENT ------------------------------------------------------- */
  {carDrive_Basic_StateFusion_Ntf_Status_Hash                               , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_STATUS, ""},
  {carDrive_Basic_SmartDrivingTips_Ntf_SmartDriveTips_Hash                  , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_SMARTDRIVETIPS, ""},
  {carDrive_Basic_ConvoyFun_NTF_ConvoyFun_Hash                              , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_CONVOYFUN, ""},
  // {carDrive_Basic_TrafficSign_Ntf_TrafficSign_Hash                          , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_TRAFFICSING, ""},
  // {carDrive_Basc_Objfusion32_Ntf_Objfusion32_Hash                        , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_OBJFUSION32, ""},
  {carDrive_Basic_TrafficLightScene_Ntf_TrafficLight_Hash                   , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_TRAFFICSIGN, ""},
  {carDrive_Basc_ADASScore_Ntf_C2_ADASScore_Hash                            , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_C2_ADASSCORE, ""},
  {carDrive_Basc_C2TripSum_C2TripSummary_Hash                               , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_C2TRIPSUMMARY, ""},
  {carDrive_Basc_AutoTurnView_NTF_AutoTurnView_Hash                         , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_AUTOTURNVIEW, ""},
  {carDrive_Basc_ADASCruiseSet_Ntf_ADASCruiseSet_Hash                       , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_ADASCRUISESET, ""},
  {carDrive_Basc_ADASCruiseSet_Ntf_C2_IACCFamlrRdModSwtFb_Hash              , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_C2_IACCFAMLRRDMODSWTFB, ""},
  {carDrive_Basc_ADASCruiseSet_Ntf_AD_NIDSelfLrngFb_Hash                    , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_AD_NIDSELFLRNGFB, ""},
  {carDrive_Basc_ADASCruiseSet_Ntf_AD_BSDLCAOnOffSet_Hash                   , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_AD_BSDLCAONOFFSET, ""},
  {carDrive_Basc_ADASCruiseSet_Ntf_AD_SEAOnOffSts_Hash                      , DEST_MCU, DEST_DDS, LIVE_MSG_DDS_NTF_AD_SEAONOFFSTS, ""},

  /**********************************************************DDS2MCU EVENT*****************************************************************/
  {carControl_Car_Control_Basc_LogicStLock_Ntf_LocStAll_Hash                , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_LOCSTALL, ""},
  {carControl_Car_Control_Basc_PhysicsStDoor_Ntf_PhyStAll_Hash              , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_PHYSTALL, ""},
  {carControl_Car_Control_Basc_TailGateSts_Ntf_TailGateSysSt_Hash           , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_TAILGATESYSST, ""},
  {carControl_Car_Control_Basc_PhysicsStFrtGate_Ntf_PhySt_Hash              , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_PHYST, ""},
  {carControl_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_TurnLiSwtReqInfo_Hash   , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_TURNLISWTREQINFO, ""},
  {carControl_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo_Hash   , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_HDLAMPSWTREQINFO, ""},
  {carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_FogInfo_Hash           , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_FOGINFO, ""},
  {carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo_Hash        , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_HIBEAMINFO, ""},
  {carControl_Car_Control_Sys_TurnLiHzrdSwt_Ntf_SrvOperInfo_Hash            , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_SRVOPERINFO, ""},
  {carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_BrkLiFltInfo_Hash          , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_BRKLIFLTINFO, ""},
  {carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo_Hash         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_BRKLIINFO, ""},
  {carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_HiBeamFltInfo_Hash         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_HIBEAMFLTINFO, ""},
  {carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_LoBeamFltInfo_Hash         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_LOBEAMFLTINFO, ""},
  {carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_TurnLiFltInfo_Hash         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_TURNLIFLTINFO, ""}, 
  {carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo_Hash        , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_LOBEAMINFO, ""}, 
  {carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo_Hash        , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_POSNLIINFO, ""},     
  {carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo_Hash        , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_TURNLIINFO, ""},  
  {carControl_Car_Control_Basc_RLSSts_Ntf_WiperRLSSts_Hash                  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_WIPERRLSSTS, ""},  
  {carControl_Car_Control_Basc_FrntWiperStsInfo_Ntf_WiperStsInfo_Hash       , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_WIPERSTSINFO, ""},
  {carControl_Car_Control_Basc_LiSnsrInfo_Ntf_LiSnsrMod_Hash                , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_LISNSRMOD, ""},  
  {carControl_Car_Control_Basc_DrSeatInfo_Ntf_SeatSts_Hash                  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_SEATSTS, ""},
  {carCabin_Basc_DMSTransferData_Ntf_SendProtoData_Hash                     , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_SENDPROTODATA, ""},
  {carControl_Car_Control_Basc_MFSSwtInfo_Ntf_SwtInfo_Hash                  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_SWTINFO, ""},
  {carControl_Car_Control_Basc_PhysicsStWin_Ntf_PosWinAll_Hash              , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_POSWINALL, ""}, 
  {carControl_Car_Control_Cnr_BleRpaCtl_Ntf_BleRpaCtl_Hash                  , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_BLERPACTL, ""},   
  {carCabin_Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal_Hash                 , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_ADAS_MAPNAVIGATIONSIGNAL, ""},  
  {carCabin_Basc_AdasInfo_Ntf_ADAS_MapCommonSignal_Hash                     , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_ADAS_MAPCOMMONSIGNAL, ""},  
  {carCabin_Basc_GpsData_Evt_GpsData_Hash                                   , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_EVT_GPSDATA, ""},    
  //{carCabin_Basc_ActSenMode_Ntf_ActSenMoSwitSt_Hash                         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_ACTSENMOSWITST, ""},  
  {carCabin_Basc_ActSenMode_Ntf_ActCampSwitSet_Hash                         , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_ACTCAMPSWITSET, ""},  
  {carControl_Car_Control_Basc_ViuGearShiftPosnInfo_Ntf_ViuGearShiftPosnInfo_Hash   , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_VIUGEARSHIFTPOSN, ""},
  //{0                                                                        , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_LANELEDFLTSTS, ""},   
  {carCabin_Basc_ActSenMode_Ntf_ActSenFunEn_Hash                          , DEST_DDS, DEST_MCU, LIVE_MSG_DDS_NTF_ACTSENMOSWITST, ""},

  /* ------------------------------------------------------- DDS-->SOC EVENT ------------------------------------------------------- */
  // {carControl_Car_Control_Cnr_BleRpaCtl_Ntf_BleRpaCtl_Hash                  , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "VIU_RPAApp_Topic"},
  {carControl_Car_Control_Basc_BLEPhyKeySer_Ntf_BLEPhyKeyInfo_Hash          , DEST_DDS, DEST_SOC, LIVE_MSG_CATEGORY_INVAILD, "VIU_RPAKey_Topic"},

};


static int getEventDestFromHashID(int32_t hashid)
{
    for (int i = 0; i < sizeof(event_msg_map) /sizeof(event_msg_map_t); i++)
    {
      if (hashid == event_msg_map[i].hashid)
      {
        return event_msg_map[i].dest;
      }
    }
  return DEST_NULL;
}

static string getTopicFromHashID(int32_t hashid)
{
    for (int i = 0; i < sizeof(event_msg_map) /sizeof(event_msg_map_t); i++)
    {
      if (hashid == event_msg_map[i].hashid)
      {
        return event_msg_map[i].topic;
      }
    }
  return "";
}

static int getLiveMsgCategoryFromHashID(int32_t hashid)
{
  for (int i = 0; i < sizeof(event_msg_map) /sizeof(event_msg_map_t); i++)
  {
    if (hashid == event_msg_map[i].hashid)
    {
      return event_msg_map[i].category;
    }
  }
  return -1;
}


static int getHashIDFromTopic(string topic)
{
    for (int i = 0; i < sizeof(event_msg_map) /sizeof(event_msg_map_t); i++)
    {
      if (topic == event_msg_map[i].topic)
      {
        return event_msg_map[i].hashid;
      }
    }

  return -1;
}

static int getHashIDFromLiveMsgCategory(int category)
{
    for (int i = 0; i < sizeof(event_msg_map) /sizeof(event_msg_map_t); i++)
    {
      if (category == event_msg_map[i].category)
      {
        return event_msg_map[i].hashid;
      }
    }

  return -1;
}

void DDSNode:: process_dds2soc_event(int32_t hashID, void *buf, int32_t bufSize)
{
  zros::core::PlainBufMessage msg(buf, bufSize);
  std::string topic = getTopicFromHashID(hashID);
  this->publish(msg, topic);
  INF("process_dds2soc_event hashID %d reserved to soc topic %s \n", hashID, topic.c_str());
}

void DDSNode:: process_dds2mcu_event(int32_t hashID, void *buf, int32_t bufSize)
{
  int category = getLiveMsgCategoryFromHashID(hashID);

  #if 1
  if (category > -1)
  {
    INF("process_dds2mcu_event hashID %d reserved to mcu category %d ----1111\n", hashID, category);
    switch (hashID)
    {
    case carControl_Car_Control_Basc_LogicStLock_Ntf_LocStAll_Hash                      : 
    {
      LockStAll_Struct data;
      memcpy(data.LockStAll, buf, 4);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("LockStAll: %d  %d %d %d\n", data.LockStAll[0],data.LockStAll[1],data.LockStAll[2],data.LockStAll[3]);
      break;
    }
    case carControl_Car_Control_Basc_PhysicsStDoor_Ntf_PhyStAll_Hash                    : 
    {
      ObjStTypeDoorAll_Struct data;
      memcpy(data.ObjStTypeDoorAll, buf, 4);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("ObjStTypeDoorAll: %d %d %d %d \n",data.ObjStTypeDoorAll[0],data.ObjStTypeDoorAll[1],data.ObjStTypeDoorAll[2],data.ObjStTypeDoorAll[3]);
      break;
    }
    case carControl_Car_Control_Basc_TailGateSts_Ntf_TailGateSysSt_Hash                 :
    {
      uint8_t data;
      memcpy(&data, buf, 1);
      struct LIVE_MSG_DATA_SIZE32 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("carControl_Car_Control_Basc_TailGateSts_Ntf_TailGateSysSt_Hash uint8_t : %d  \n",data);
      break;
    }
    case carControl_Car_Control_Basc_PhysicsStFrtGate_Ntf_PhySt_Hash                    : 
    {
      ObjStTypeDoorAll_Struct data;
      memcpy(data.ObjStTypeDoorAll, buf, 4);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("carControl_Car_Control_Basc_PhysicsStFrtGate_Ntf_PhySt_Hash uint8_t %d \n", data.ObjStTypeDoorAll[0]);
      break;
    }
    case carControl_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_TurnLiSwtReqInfo_Hash         :
    {
      TurnLiKeySwtSt data;
      Soa::PB_TurnLiKeySwtSt pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_TurnLiKeySwtSt(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break; 
    }
    case carControl_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo_Hash         : 
    {
      uint8_t data;
      memcpy(&data, buf, 1);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("carControl_Car_Control_Basc_ExtrLiSwtReqInfo_Ntf_HdLampSwtReqInfo_Hash uint8_t %d \n", data);
      break;
    }
    case carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_FogInfo_Hash                 : 
    {
      FogActCtrlInfo data;

      Soa::PB_FogActCtrlInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_FogActCtrlInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    } 
    case carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_HiBeamInfo_Hash              :
    {
      HiBeamActCtrlInfo data;
      Soa::PB_HiBeamActCtrlInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_HiBeamActCtrlInfo(&pb_data, &data); 
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }      
    case carControl_Car_Control_Sys_TurnLiHzrdSwt_Ntf_SrvOperInfo_Hash                   : 
    {
      OperationInfo data;
      Soa::PB_OperationInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_OperationInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    } 
    case carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_BrkLiFltInfo_Hash                : 
    {
      BrkLiFltInfo data;
      Soa::PB_BrkLiFltInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_BrkLiFltInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }
    case carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_BrkLiInfo_Hash               : 
    {
      BrkLiActCtrlInfo data;
      Soa::PB_BrkLiActCtrlInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);

      convert_to_struct_BrkLiActCtrlInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }
    case carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_HiBeamFltInfo_Hash               : 
    {
      HiBeamFltInfo data;
      Soa::PB_HiBeamFltInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_HiBeamFltInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    } 
    case carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_LoBeamFltInfo_Hash               :
    {
      LoBeamFltInfo data;
      Soa::PB_LoBeamFltInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_LoBeamFltInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }     
    case carControl_Car_Control_Basc_ExtrLiFltInfo_Ntf_TurnLiFltInfo_Hash               : 
    {
      TurnLiFltInfo data;
      Soa::PB_TurnLiFltInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_TurnLiFltInfo(&pb_data, &data);     
      struct LIVE_MSG_DATA_SIZE32 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }   
    case carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_LoBeamInfo_Hash              : 
    {
      LoBeamActCtrlInfo data;
      Soa::PB_LoBeamActCtrlInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_LoBeamActCtrlInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }  
    case carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_PosnLiInfo_Hash              : 
     {
      PosnLiActCtrlInfo data;
      Soa::PB_PosnLiActCtrlInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_PosnLiActCtrlInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }
    case carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo_Hash              : 
    {
      TurnLiActCtrlInfo data;
      Soa::PB_TurnLiActCtrlInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_TurnLiActCtrlInfo(&pb_data, &data);
      INF("carControl_Car_Control_Basc_ExtrLiActCtrlInfo_Ntf_TurnLiInfo_Hash: [%d %d %d %d] [%d %d %d %d] \n",
          pb_data.fl_actctrlst(),
          pb_data.fr_actctrlst(),
          pb_data.rl_actctrlst(),
          pb_data.rr_actctrlst(),
          data.FL_ActCtrlSt,
          data.FR_ActCtrlSt,
          data.RL_ActCtrlSt,
          data.RR_ActCtrlSt);

      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }  
    case carControl_Car_Control_Basc_RLSSts_Ntf_WiperRLSSts_Hash                        : 
    {
      RLSSts data;
      Soa::PB_RLSSts pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_RLSSts(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }
    case carControl_Car_Control_Basc_FrntWiperStsInfo_Ntf_WiperStsInfo_Hash             : 
    {
      FWiperStsInfo data;
      Soa::PB_FWiperStsInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_FWiperStsInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE32 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }
    case carControl_Car_Control_Basc_LiSnsrInfo_Ntf_LiSnsrMod_Hash                      : 
    {
      uint8_t data;
      memcpy(&data, buf, 1);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("carControl_Car_Control_Basc_LiSnsrInfo_Ntf_LiSnsrMod_Hash uint8_t %d \n", data );
      break;
    }
    case carControl_Car_Control_Basc_DrSeatInfo_Ntf_SeatSts_Hash                                    :
    {
      DrSeatSts data;
      Soa::PB_DrSeatSts pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_DrSeatSts(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE32 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }
    case carCabin_Basc_DMSTransferData_Ntf_SendProtoData_Hash                           : 
    {
      DDSData_Msg data;
      Soa::PB_DDSData_Msg pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_DDSData_Msg(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE64 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("carCabin_Basc_DMSTransferData_Ntf_SendProtoData_Hash \n");
      INF("--------------------- \n");      
      INF("--------------------- \n");      
      printf("Length: %u\n", data.payload._length);      
      printf("Data: ");      
      for (uint32_t i = 0; i < data.payload._length; ++i) 
      {          
        printf("%u ", data.payload._buffer[i]);      
      }      
      printf("\n");      
      INF("--------------------- \n");      
      INF("--------------------- \n");  
      break;
    }
    case carControl_Car_Control_Basc_MFSSwtInfo_Ntf_SwtInfo_Hash                        : 
    {
      MFSSwtInfo data;
      Soa::PB_MFSSwtInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_MFSSwtInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE64 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("MFSSwtLL : %d \n", data.MFSSwtLL);
      break;
    }
    case carControl_Car_Control_Basc_PhysicsStWin_Ntf_PosWinAll_Hash                    : 
    {
      ObjStTypeCurPosVITAll_Struct data;
      memcpy(&data, buf, 4);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("carControl_Car_Control_Basc_PhysicsStWin_Ntf_PosWinAll_Hash uint8_t : %d  \n",data);
     
      break;
    }  
    /* 同时包含dds-->soc/mcu, 订阅后分别发送 */
    case carControl_Car_Control_Cnr_BleRpaCtl_Ntf_BleRpaCtl_Hash                        : 
    {
      INF("process_dds2mcu_event: hashID[%d] category[%d], combin soc/mcu \n", hashID, category);
      zros::core::PlainBufMessage msg_soc(buf, bufSize);

      BLERpaCmdReq data;
      Soa::PB_BLERpaCmdReq pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_BLERpaCmdReq(&pb_data, &data);

      /* dds->mcu发送 */
      struct LIVE_MSG_DATA_SIZE64 msg_mcu;
      live_msg_init_with_timestamp(&msg_mcu.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg_mcu.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg_mcu.header);

      /* dds->soc发送 */
      this->publish(msg_soc, "VIU_RPAApp_Topic");
      DBG("KeyIndex : %d \n",data.KeyIndex);
      break;
    }
    case carCabin_Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal_Hash                       : 
    {
      ADAS_MapNavigationSignal data;
      Soa::PB_ADAS_MapNavigationSignal pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_ADAS_MapNavigationSignal(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE512 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }    
    case carCabin_Basc_AdasInfo_Ntf_ADAS_MapCommonSignal_Hash                           : 
    {
      ADAS_MapCommonSignal data;
      Soa::PB_ADAS_MapCommonSignal pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_ADAS_MapCommonSignal(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }    
    case carCabin_Basc_GpsData_Evt_GpsData_Hash                                         :
    {
      GpsDatas data;
      Soa::PB_GpsDatas pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_GpsDatas(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE32 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    } 
    case carCabin_Basc_ActSenMode_Ntf_ActSenMoSwitSt_Hash                               : 
    {
      uint8_t data;
      memcpy(&data, buf, 1);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }
    case carCabin_Basc_ActSenMode_Ntf_ActCampSwitSet_Hash                               : 
    {
      uint8_t data;
      memcpy(&data, buf, 1);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      break;
    }
    case carControl_Car_Control_Basc_ViuGearShiftPosnInfo_Ntf_ViuGearShiftPosnInfo_Hash :
    {
      ViuGearShiftPosnInfo data;
      Soa::PB_ViuGearShiftPosnInfo pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_ViuGearShiftPosnInfo(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data, sizeof(data), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      // sendToMcuWithTimestamp(category, &data, sizeof(data));
      INF("ViuGearShiftPosn : %d \n",data.ViuGearShiftPosn);
      break;
    }
    case carCabin_Basc_ActSenMode_Ntf_ActSenFunEn_Hash :
    {
      FunEnEvt data;
      Soa::PB_FunEnEvt pb_data;
      pb_data.ParseFromArray(buf, bufSize);
      convert_to_struct_FunEnEvt(&pb_data, &data);
      struct LIVE_MSG_DATA_SIZE16 msg;
      live_msg_init_with_timestamp(&msg.header, category, &data.FunEnTyp, sizeof(data.FunEnTyp), zros::base::GetSyncedTime());
      live_msg_set_target(&msg.header, LIVE_MSG_TARGET_MCU);
      live_msg_send(&msg.header);
      INF("Ntf_ActSenFunEn : %d \n",data.FunEnTyp);
      break;
    }
    default:
        break;
    }
  }
  #endif

}

void DDSNode:: process_soc2dds_event(const std::string &topic, const zros::core::PlainBufMessage &msg)
{
#if 1
  DBG("soc2dds_event topic %s reserved \n", topic.c_str());
  if (topic == "hmi_interface____HmiInterface__C22EDCSlotInfos")
  {
    // DDSData_Msg ddsMsg;
    // void *send_ptr = nullptr;
    // size_t  send_size = 0;
    // ddsMsg.topic = "hmi_interface____HmiInterface__C22EDCSlotInfos";
    // ddsMsg.timestamp = zros::base::GetSyncedTime();
    // ddsMsg.payload._buffer = (uint8_t *)msg.GetData();
    // ddsMsg.payload._length = msg.GetSize();
    // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);

    int32_t hashID = getHashIDFromTopic(topic);
    // CEventPuber::Send(hashID, send_ptr, send_size);
    // free(send_ptr);

    string topicdata="hmi_interface____HmiInterface__C22EDCSlotInfos";
		struct DDSData_Msg *dataC2MCU= (struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
		dataC2MCU->timestamp=zros::base::GetSyncedTime();
		dataC2MCU->topic=(char *)malloc(topicdata.length());
		strcpy(dataC2MCU->topic, topicdata.c_str());
		dataC2MCU->payload._length =  msg.GetSize();
		dataC2MCU->payload._release = true;
    dataC2MCU->payload._buffer =(uint8_t *)malloc(msg.GetSize());
    memcpy(dataC2MCU->payload._buffer, msg.GetData(),msg.GetSize());
		CEventPuber::Send_idlc(hashID, dataC2MCU,sizeof(struct DDSData_Msg));

  }
  else if(topic == "hmi_interface____HmiInterface__BasicObjfusion32")
  {
    // DDSData_Msg ddsMsg;
    // void *send_ptr = nullptr;
    // size_t  send_size = 0;
    // ddsMsg.topic = "hmi_interface____HmiInterface__BasicObjfusion32";
    // ddsMsg.timestamp = zros::base::GetSyncedTime();
    // ddsMsg.payload._buffer = (uint8_t *)msg.GetData();
    // ddsMsg.payload._length = msg.GetSize();
    // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);
    int32_t hashID = getHashIDFromTopic(topic);
    // CEventPuber::Send(hashID, send_ptr, send_size);
    // free(send_ptr);
    string topicdata="hmi_interface____HmiInterface__BasicObjfusion32";
		struct DDSData_Msg *dataC2MCU= (struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
		dataC2MCU->timestamp=zros::base::GetSyncedTime();
		dataC2MCU->topic=(char *)malloc(topicdata.length());
		strcpy(dataC2MCU->topic, topicdata.c_str());
		dataC2MCU->payload._length =  msg.GetSize();
		dataC2MCU->payload._release = true;
    dataC2MCU->payload._buffer =(uint8_t *)malloc(msg.GetSize());
    memcpy(dataC2MCU->payload._buffer, msg.GetData(),msg.GetSize());
		CEventPuber::Send_idlc(hashID, dataC2MCU,sizeof(struct DDSData_Msg));
  }
  else if(topic == "hmi_interface____HmiInterface__BasicMapRoadScene")
  {
    // DDSData_Msg ddsMsg;
    // void *send_ptr = nullptr;
    // size_t  send_size = 0;
    // ddsMsg.topic = "hmi_interface____HmiInterface__BasicMapRoadScene";
    // ddsMsg.timestamp = zros::base::GetSyncedTime();
    // ddsMsg.payload._buffer = (uint8_t *)msg.GetData();

///////////////////////////////////////////////////////////
// HmiInterface::BasicMapRoadScene scenePb;
// scenePb.ParseFromArray(msg.GetData(), msg.GetSize());
//std::cout << "mutable_maproadscene:" <<scenePb.maproadscene().lane_status().laneleft_status() << std::endl;
//std::cout << "mutable_maproadscene:" <<scenePb.maproadscene().lane_status().laneright_status() << std::endl;
//std::cout << "mutable_maproadscene:" <<scenePb.maproadscene().tunneldata().tunneldis_m() << std::endl;

    // for (auto line : scenePb.maproadscene().line_point_info())
    // {
    //   //  std::cout << "lane_id:" << line.lane_id() << ", lane_color:" << line.lane_color() << std::endl;
    // }

////////////////////////////////////////////////////////////

    // ddsMsg.payload._length = msg.GetSize();
    // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);
    int32_t hashID = getHashIDFromTopic(topic);
    // CEventPuber::Send(hashID, send_ptr, send_size);
    // free(send_ptr);

        string topicdata="hmi_interface____HmiInterface__BasicMapRoadScene";
		struct DDSData_Msg *dataC2MCU= (struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
		dataC2MCU->timestamp=zros::base::GetSyncedTime();
		dataC2MCU->topic=(char *)malloc(topicdata.length());
		strcpy(dataC2MCU->topic, topicdata.c_str());
		dataC2MCU->payload._length =  msg.GetSize();
		dataC2MCU->payload._release = true;
    dataC2MCU->payload._buffer =(uint8_t *)malloc(msg.GetSize());
    memcpy(dataC2MCU->payload._buffer, msg.GetData(),msg.GetSize());
		CEventPuber::Send_idlc(hashID, dataC2MCU,sizeof(struct DDSData_Msg));
  }
  else
  {
    int32_t hashID = getHashIDFromTopic(topic);
    int32_t bufSize = msg.GetSize();
    void *buf = (void *)malloc(bufSize);
    memcpy(buf, msg.GetData(), bufSize);
    CEventPuber::Send(hashID, buf, bufSize);
    free(buf);
  }
#endif
}

void DDSNode:: process_mcu2dds_event(const std::string &topic, const zros::core::PlainBufMessage &msg)
{
#if 1
  struct LIVE_MSG *live_msg = (struct LIVE_MSG *)(msg.GetData());
  if (!live_msg)
  {
    ERR("mcu_live_msg_process category is NULL");
    return;
  }
  int category =  live_msg->id;
  switch (category)
  {
    case LIVE_MSG_DDS_NTF_STATUS:
    {
      DBG("live msg hmi_interface____HmiInterface__BasicStateFusion \n");
      Statefusion *data = (Statefusion *)live_msg->data;
      HmiInterface::BasicStateFusion pb;
      pb.mutable_status_fusion()->mutable_autolightstatus()->set_las_hmastatus(data->autolightstatus.las_hmastatus);
      pb.mutable_status_fusion()->mutable_gatewaystatus()->set_w_adssecocverifyfailureflag(data->gatewaystatus.w_adssecocverifyfailureflag);
      pb.mutable_status_fusion()->mutable_sensorstatus()->set_acc_fradarfailurestatus(data->sensorstatus.acc_fradarfailurestatus);
      pb.mutable_status_fusion()->mutable_sensorstatus()->set_acc_fradarcalibrationstatus(data->sensorstatus.acc_fradarcalibrationstatus);
      pb.mutable_status_fusion()->mutable_sensorstatus()->set_las_frontcamerafailurestatus(data->sensorstatus.las_frontcamerafailurestatus);
      pb.mutable_status_fusion()->mutable_sensorstatus()->set_las_frontcameracalibrationstatus(data->sensorstatus.las_frontcameracalibrationstatus);
      pb.mutable_status_fusion()->mutable_sensorstatus()->set_ads_flc_systemstatus(data->sensorstatus.ads_flc_systemstatus);
      pb.mutable_status_fusion()->mutable_sensorstatus()->set_ads_frc_systemstatus(data->sensorstatus.ads_frc_systemstatus);
      pb.mutable_status_fusion()->mutable_sensorstatus()->set_lcdal_systemstatus(data->sensorstatus.lcdal_systemstatus);
      pb.mutable_status_fusion()->mutable_sensorstatus()->set_lcdar_systemstatus(data->sensorstatus.lcdar_systemstatus);
      pb.mutable_status_fusion()->mutable_lrbsdstatus()->set_lcdar_left_bsd_lcaalert(data->lrbsdstatus.lcdar_left_bsd_lcaalert);
      pb.mutable_status_fusion()->mutable_lrbsdstatus()->set_lcdar_bsd_lcaalert(data->lrbsdstatus.lcdar_bsd_lcaalert);
      pb.mutable_status_fusion()->mutable_accdislevel()->set_acc_distancelevel(data->accdislevel.acc_distancelevel);
      pb.mutable_status_fusion()->mutable_takeovereyewarning()->set_ad_handsonreq(data->takeovereyewarning.ad_handsonreq);
      pb.mutable_status_fusion()->mutable_takeovereyewarning()->set_ad_safetynotice(data->takeovereyewarning.ad_safetynotice);
      pb.mutable_status_fusion()->mutable_takeovereyewarning()->set_ad_lngtakeoverreq(data->takeovereyewarning.ad_lngtakeoverreq);
      pb.mutable_status_fusion()->mutable_takeovereyewarning()->set_ad_dynamicwarninglevel(data->takeovereyewarning.ad_dynamicwarninglevel);
      pb.mutable_status_fusion()->mutable_takeovereyewarning()->set_ad_lattakeoverreq(data->takeovereyewarning.ad_lattakeoverreq);
      pb.mutable_status_fusion()->mutable_takeovereyewarning()->set_ads_eomwarnning(data->takeovereyewarning.ads_eomwarnning);
      pb.mutable_status_fusion()->mutable_acciaccnidstatus()->set_ad_accmode(data->acciaccnidstatus.ad_accmode);
      pb.mutable_status_fusion()->mutable_acciaccnidstatus()->set_ad_iacchwamode(data->acciaccnidstatus.ad_iacchwamode);
      pb.mutable_status_fusion()->mutable_acciaccnidstatus()->set_ad_ndastatus(data->acciaccnidstatus.ad_ndastatus);
      pb.mutable_status_fusion()->mutable_acciaccnidstatus()->set_ad_tjpstatus(data->acciaccnidstatus.ad_tjpstatus);
      void *pb_buff = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(pb_buff, pb.ByteSizeLong());

    INF("LIVE_MSG_DDS_NTF_STATUS: ad_accmode[%d] ad_iacchwamode[%d]\n",
        data->acciaccnidstatus.ad_accmode,
        data->acciaccnidstatus.ad_iacchwamode);


   string topicdata="hmi_interface____HmiInterface__BasicStateFusion";
		struct DDSData_Msg *dataC2MCU= (struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
		dataC2MCU->timestamp=zros::base::GetSyncedTime();
		dataC2MCU->topic=(char *)malloc(topicdata.length());
		strcpy(dataC2MCU->topic, topicdata.c_str());
		dataC2MCU->payload._length =  pb.ByteSizeLong();
		dataC2MCU->payload._release = true;
    dataC2MCU->payload._buffer =(uint8_t *)malloc(pb.ByteSizeLong());
    memcpy(dataC2MCU->payload._buffer, pb_buff,pb.ByteSizeLong());
		CEventPuber::Send_idlc(carDrive_Basic_StateFusion_Ntf_Status_Hash, dataC2MCU,sizeof(struct DDSData_Msg));
    free(pb_buff);

      // DDSData_Msg ddsMsg;
      // void *send_ptr = nullptr;
      // size_t  send_size = 0;
      // ddsMsg.topic = "hmi_interface____HmiInterface__BasicStateFusion";
      // ddsMsg.timestamp = zros::base::GetSyncedTime();
      // ddsMsg.payload._buffer = (uint8_t *)pb_buff;
      // ddsMsg.payload._length = pb.ByteSizeLong();
      // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);

      // CEventPuber::Send(carDrive_Basic_StateFusion_Ntf_Status_Hash, send_ptr, send_size);
      // free(send_ptr);
      // free(pb_buff);
      break;
    }
 
    case LIVE_MSG_DDS_NTF_SMARTDRIVETIPS:
    {
      DBG("live msg hmi_interface____HmiInterface__BasicSmartDrivingTips %d \n", live_msg->data[0]);
      SmartDrivingTips *data = (SmartDrivingTips *)live_msg->data;
      HmiInterface::BasicSmartDrivingTips pb;
      pb.mutable_smartdrivetips()->mutable_acc_fun()->set_acc_setspeed(data->acc_fun.acc_setspeed);
      pb.mutable_smartdrivetips()->mutable_acc_fun()->set_acc_timegapset(data->acc_fun.acc_timegapset);
      pb.mutable_smartdrivetips()->mutable_acc_fun()->set_acc_vehiclestartremindsts(data->acc_fun.acc_vehiclestartremindsts);
      pb.mutable_smartdrivetips()->mutable_udlc_fun()->set_ads_pathshow_status(data->udlc_fun.ads_pathshow_status);
      pb.mutable_smartdrivetips()->mutable_udlc_fun()->set_ads_totargetlatdistance(data->udlc_fun.ads_totargetlatdistance);

      pb.mutable_smartdrivetips()->mutable_nid_fun()->set_ads_ndatextinfo(data->nid_fun.ads_ndatextinfo);
      pb.mutable_smartdrivetips()->mutable_nid_fun()->set_ads_ndafenceterminaldis(data->nid_fun.ads_ndafenceterminaldis);
      pb.mutable_smartdrivetips()->mutable_nid_fun()->set_ads_oastatus(data->nid_fun.ads_oastatus);
      pb.mutable_smartdrivetips()->mutable_nid_fun()->set_ads_oadirection(data->nid_fun.ads_oadirection);
      pb.mutable_smartdrivetips()->mutable_nid_fun()->set_ads_oalatdistance(data->nid_fun.ads_oalatdistance);
      pb.mutable_smartdrivetips()->mutable_nid_fun()->set_ads_oalngdistance(data->nid_fun.ads_oalngdistance);

      pb.mutable_smartdrivetips()->mutable_recommend_fun()->set_ads_newrecommend(data->recommend_fun.ads_newrecommend);
      pb.mutable_smartdrivetips()->mutable_tjp_fun()->set_ads_tjptextinfo(data->tjp_fun.ads_tjptextinfo);
      pb.mutable_smartdrivetips()->mutable_adc_funtips()->set_acc_adcnotice(data->adc_funtips.acc_adcnotice);
      pb.mutable_smartdrivetips()->mutable_cna_fun()->set_ads_cnatextinfo(data->cna_fun.ads_cnatextinfo);

      pb.mutable_smartdrivetips()->mutable_speedlimit_fun()->set_las_tsrhostspdlimit(data->speedlimit_fun.las_tsrhostspdlimit);
      pb.mutable_smartdrivetips()->mutable_speedlimit_fun()->set_las_overspeedvisualwarning(data->speedlimit_fun.las_overspeedvisualwarning);
      pb.mutable_smartdrivetips()->mutable_speedlimit_fun()->set_las_overspeedsoundwarning(data->speedlimit_fun.las_overspeedsoundwarning);
      pb.mutable_smartdrivetips()->mutable_speedlimit_fun()->set_acc_cslsetreq(data->speedlimit_fun.acc_cslsetreq);
      pb.mutable_smartdrivetips()->mutable_speedlimit_fun()->set_ads_spdlimitedstatus(data->speedlimit_fun.ads_spdlimitedstatus);
      pb.mutable_smartdrivetips()->mutable_speedlimit_fun()->set_ads_spdlmttype(data->speedlimit_fun.ads_spdlmttype);
      pb.mutable_smartdrivetips()->mutable_speedlimit_fun()->set_ads_tsrhostnextspdlimit(data->speedlimit_fun.ads_tsrhostnextspdlimit);
      pb.mutable_smartdrivetips()->mutable_speedlimit_fun()->set_ads_tsrhostnextspdlimitdist(data->speedlimit_fun.ads_tsrhostnextspdlimitdist);

      pb.mutable_smartdrivetips()->set_ads_latprohibitcountdown(data->ads_latprohibitcountdown);
      pb.mutable_smartdrivetips()->set_ads_sbuncountdown(data->ads_sbuncountdown);

      void *pb_buff = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(pb_buff, pb.ByteSizeLong());

      // if (data->adc_funtips.acc_adcnotice != 0)
      // {
        INF("LIVE_MSG_DDS_NTF_SMARTDRIVETIPS: adcnotice[%d]\n", data->adc_funtips.acc_adcnotice);
      // }
      // if (data->udlc_fun.ads_pathshow_status != 0)
      // {
        INF("LIVE_MSG_DDS_NTF_SMARTDRIVETIPS: pathshow[%d] totarget[%f]\n",
            data->udlc_fun.ads_pathshow_status,
            data->udlc_fun.ads_totargetlatdistance);
      // }

     string topicdata="hmi_interface____HmiInterface__BasicSmartDrivingTips";
		struct DDSData_Msg *dataC2MCU= (struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
		dataC2MCU->timestamp=zros::base::GetSyncedTime();
		dataC2MCU->topic=(char *)malloc(topicdata.length());
		strcpy(dataC2MCU->topic, topicdata.c_str());
		dataC2MCU->payload._length =  pb.ByteSizeLong();
		dataC2MCU->payload._release = true;
    dataC2MCU->payload._buffer =(uint8_t *)malloc(pb.ByteSizeLong());
    memcpy(dataC2MCU->payload._buffer, pb_buff,pb.ByteSizeLong());
		CEventPuber::Send_idlc(carDrive_Basic_SmartDrivingTips_Ntf_SmartDriveTips_Hash, dataC2MCU,sizeof(struct DDSData_Msg));
    free(pb_buff);

      // DDSData_Msg ddsMsg;
      // void *send_ptr = nullptr;
      // size_t  send_size = 0;
      // ddsMsg.topic = "hmi_interface____HmiInterface__BasicSmartDrivingTips";
      // ddsMsg.timestamp = zros::base::GetSyncedTime();
      // ddsMsg.payload._buffer = (uint8_t *)pb_buff;
      // ddsMsg.payload._length = pb.ByteSizeLong();
      // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);
      // CEventPuber::Send(carDrive_Basic_SmartDrivingTips_Ntf_SmartDriveTips_Hash, send_ptr, send_size);
      // free(send_ptr);
      // free(pb_buff);
      break;
    }    
    // case LIVE_MSG_DDS_NTF_TRAFFICSING:
    // {
    //   DBG("live msg hmi_interface____HmiInterface__BasicTrafficSign \n");
    //   TrafficSign *data = (TrafficSign *)live_msg->data;
    //   HmiInterface::BasicTrafficSign pb;
    //   pb.mutable_trafficsign()->set_warningsign(data->warningsign);
    //   pb.mutable_trafficsign()->set_prohibitionsign(data->prohibitionsign);
    //   pb.mutable_trafficsign()->set_mandatorysign(data->mandatorysign);
    //   // pb.mutable_trafficsign()->set_lanearrowdata(1);

    //   void *pb_buff = malloc(pb.ByteSizeLong());
    //   pb.SerializeToArray(pb_buff, pb.ByteSizeLong());

    //  string topicdata="hmi_interface____HmiInterface__BasicTrafficSign";
		// struct DDSData_Msg *dataC2MCU= (struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
		// dataC2MCU->timestamp=zros::base::GetSyncedTime();
		// dataC2MCU->topic=(char *)malloc(topicdata.length());
		// strcpy(dataC2MCU->topic, topicdata.c_str());
		// dataC2MCU->payload._length =  pb.ByteSizeLong();
		// dataC2MCU->payload._release = true;
    // dataC2MCU->payload._buffer =(uint8_t *)malloc(pb.ByteSizeLong());
    // memcpy(dataC2MCU->payload._buffer, pb_buff,pb.ByteSizeLong());
		// CEventPuber::Send_idlc(carDrive_Basic_TrafficSign_Ntf_TrafficSign_Hash, dataC2MCU,sizeof(struct DDSData_Msg));
    // free(pb_buff);


    //   // DDSData_Msg ddsMsg;
    //   // void *send_ptr = nullptr;
    //   // size_t  send_size = 0;
    //   // ddsMsg.topic = "hmi_interface____HmiInterface__BasicTrafficSign";
    //   // ddsMsg.timestamp = zros::base::GetSyncedTime();
    //   // ddsMsg.payload._buffer = (uint8_t *)pb_buff;
    //   // ddsMsg.payload._length = pb.ByteSizeLong();
    //   // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);
    //   // CEventPuber::Send(carDrive_Basic_TrafficSign_Ntf_TrafficSign_Hash, send_ptr, send_size);
    //   // free(send_ptr);
    //   // free(pb_buff);
    //   break;
    // }

    // case LIVE_MSG_DDS_NTF_OBJFUSION32:
    // {
    //   // static int obj32_cnt = 0;
    //   // INF("process_mcu2dds_event: LIVE_MSG_DDS_NTF_OBJFUSION32(%d)\n", ++obj32_cnt);
    //   break;
    // }
    #if 0
    case LIVE_MSG_DDS_NTF_CONVOYFUN:
    {
      // INF("live msg hmi_interface____HmiInterface__BasicConv  oyFunInfo \n");
      ConvoyFun *data = (ConvoyFun *)live_msg->data;
      HmiInterface::BasicConvoyFunInfo pb;
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_bsdlca_leftalert(data->lcda_fun.ad_bsdlca_leftalert);
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_rctaleftalert(data->lcda_fun.ad_rctaleftalert);
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_sealeftalert(data->lcda_fun.ad_sealeftalert);
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_dowleftalert(data->lcda_fun.ad_dowleftalert);
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_rcwalert(data->lcda_fun.ad_rcwalert);
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_bsdlca_rightalert(data->lcda_fun.ad_bsdlca_rightalert);
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_rctarightalert(data->lcda_fun.ad_rctarightalert);
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_searightalert(data->lcda_fun.ad_searightalert);
      pb.mutable_convoy_fun_info()->mutable_lcdafun()->set_ad_dowrightalert(data->lcda_fun.ad_dowrightalert);

      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_aebstatus(data->fcwaebeds.ad_aebstatus);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_rebstatus(data->fcwaebeds.ad_rebstatus);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_fcwlatentwarning(data->fcwaebeds.ad_fcwlatentwarning);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_fcwactive(data->fcwaebeds.ad_fcwactive);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_rewalert(data->fcwaebeds.ad_rewalert);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_fctbactive(data->fcwaebeds.ad_fctbactive);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_rctbactive(data->fcwaebeds.ad_rctbactive);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_fctaleftalert(data->fcwaebeds.ad_fctaleftalert);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_fctarightalert(data->fcwaebeds.ad_fctarightalert);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_aebactive(data->fcwaebeds.ad_aebactive);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_runredlightwarning(data->fcwaebeds.ad_runredlightwarning);
      pb.mutable_convoy_fun_info()->mutable_fcwaebeds()->set_ad_aesactive(data->fcwaebeds.ad_aesactive);

      pb.mutable_convoy_fun_info()->mutable_ldwlkaelk()->set_ad_ldwstatus(data->ldwlkaelk.ad_ldwstatus);
      pb.mutable_convoy_fun_info()->mutable_ldwlkaelk()->set_ad_lkastatus(data->ldwlkaelk.ad_lkastatus);
      pb.mutable_convoy_fun_info()->mutable_ldwlkaelk()->set_ad_voiceinfo(data->ldwlkaelk.ad_voiceinfo);
      pb.mutable_convoy_fun_info()->mutable_ldwlkaelk()->set_ad_elkmode(data->ldwlkaelk.ad_elkmode);
      pb.mutable_convoy_fun_info()->mutable_ldwlkaelk()->set_ad_elkleftinterventionmode(data->ldwlkaelk.ad_elkleftinterventionmode);
      pb.mutable_convoy_fun_info()->mutable_ldwlkaelk()->set_ad_elkrightinterventionmode(data->ldwlkaelk.ad_elkrightinterventionmode);
      pb.mutable_convoy_fun_info()->mutable_ldwlkaelk()->set_ad_ldwinhaitwarning(data->ldwlkaelk.ad_ldwinhaitwarning);
      pb.mutable_convoy_fun_info()->mutable_ldwlkaelk()->set_ad_lkainhaitwarning(data->ldwlkaelk.ad_lkainhaitwarning);
      
      void *pb_buff = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(pb_buff, pb.ByteSizeLong());

    string topicdata="hmi_interface____HmiInterface__BasicConvoyFunInfo";
		struct DDSData_Msg *dataC2MCU= (struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
		dataC2MCU->timestamp=zros::base::GetSyncedTime();
		dataC2MCU->topic=(char *)malloc(topicdata.length());
		strcpy(dataC2MCU->topic, topicdata.c_str());
		dataC2MCU->payload._length =  pb.ByteSizeLong();
		dataC2MCU->payload._release = true;
    dataC2MCU->payload._buffer =(uint8_t *)malloc(pb.ByteSizeLong());
    memcpy(dataC2MCU->payload._buffer, pb_buff,pb.ByteSizeLong());
		CEventPuber::Send_idlc(carDrive_Basic_ConvoyFun_NTF_ConvoyFun_Hash, dataC2MCU,sizeof(struct DDSData_Msg));
    free(pb_buff);


      // DDSData_Msg ddsMsg;
      // void *send_ptr = nullptr;
      // size_t  send_size = 0;
      // ddsMsg.topic = "hmi_interface____HmiInterface__BasicConvoyFunInfo";
      // ddsMsg.timestamp = zros::base::GetSyncedTime();
      // ddsMsg.payload._buffer = (uint8_t *)pb_buff;
      // ddsMsg.payload._length = pb.ByteSizeLong();
      // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);
      // CEventPuber::Send(carDrive_Basic_ConvoyFun_NTF_ConvoyFun_Hash, send_ptr, send_size);
      // free(send_ptr);
      // free(pb_buff);
      break;
    }
  #endif
    case LIVE_MSG_DDS_NTF_TRAFFICSIGN :
    {
      DBG("live msg hmi_interface____HmiInterface__BasicTrafficLightScene \n");
      TrafficLightScene *data = (TrafficLightScene *)live_msg->data;
      HmiInterface::BasicTrafficLightScene pb;
      pb.mutable_trafficlight()->mutable_lefttrcdata()->set_leftlightsituation(data->lefttrcdata.leftlightsituation);
      pb.mutable_trafficlight()->mutable_lefttrcdata()->set_leftlightcolor(data->lefttrcdata.leftlightcolor);
      pb.mutable_trafficlight()->mutable_lefttrcdata()->set_leftlighttype(data->lefttrcdata.leftlighttype);
      pb.mutable_trafficlight()->mutable_lefttrcdata()->set_leftlightstatus(data->lefttrcdata.leftlightstatus);
      pb.mutable_trafficlight()->mutable_lefttrcdata()->set_leftlightdirection(data->lefttrcdata.leftlightdirection);

      pb.mutable_trafficlight()->mutable_righttrcdata()->set_rightlightsituation(data->righttrcdata.rightlightsituation);
      pb.mutable_trafficlight()->mutable_righttrcdata()->set_rightlightcolour(data->righttrcdata.rightlightcolour);
      pb.mutable_trafficlight()->mutable_righttrcdata()->set_rightlighttype(data->righttrcdata.rightlighttype);
      pb.mutable_trafficlight()->mutable_righttrcdata()->set_rightlightstatus(data->righttrcdata.rightlightstatus);
      pb.mutable_trafficlight()->mutable_righttrcdata()->set_rightlightdirection(data->righttrcdata.rightlightdirection);

      pb.mutable_trafficlight()->mutable_hosttrcdata()->set_hostlightsituation(data->hosttrcdata.hostlightsituation);
      pb.mutable_trafficlight()->mutable_hosttrcdata()->set_hostlightcolour(data->hosttrcdata.hostlightcolour);
      pb.mutable_trafficlight()->mutable_hosttrcdata()->set_hostlighttype(data->hosttrcdata.hostlighttype);
      pb.mutable_trafficlight()->mutable_hosttrcdata()->set_hostlightstatus(data->hosttrcdata.hostlightstatus);
      pb.mutable_trafficlight()->mutable_hosttrcdata()->set_hostlightdirection(data->hosttrcdata.hostlightdirection);
      pb.mutable_trafficlight()->mutable_hosttrcdata()->set_hostlightwarninglevel(data->hosttrcdata.hostlightwarninglevel);

      pb.mutable_trafficlight()->mutable_roadsigndata()->set_leftsigntype(data->roadsigndata.leftsigntype);
      pb.mutable_trafficlight()->mutable_roadsigndata()->set_leftsignlngrange(data->roadsigndata.leftsignlngrange);
      pb.mutable_trafficlight()->mutable_roadsigndata()->set_hostsigntype(data->roadsigndata.hostsigntype);
      pb.mutable_trafficlight()->mutable_roadsigndata()->set_hostsignlngrange(data->roadsigndata.hostsignlngrange);
      pb.mutable_trafficlight()->mutable_roadsigndata()->set_rightsigntype(data->roadsigndata.rightsigntype);
      pb.mutable_trafficlight()->mutable_roadsigndata()->set_leftsigntype(data->roadsigndata.leftsigntype);

      pb.mutable_trafficlight()->mutable_crossworkdata()->set_crossworklngrange(data->crossworklngrange);
      pb.mutable_trafficlight()->mutable_stoplinedata()->set_stoplinelngrange(data->stoplinelngrange);
      pb.mutable_trafficlight()->mutable_yellowglinedata()->set_yellowglinerange(data->yellowglinerange);

      void *pb_buff = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(pb_buff, pb.ByteSizeLong());

    string topicdata="hmi_interface____HmiInterface__BasicTrafficLightScene";
		struct DDSData_Msg *dataC2MCU= (struct DDSData_Msg *)malloc(sizeof(struct DDSData_Msg));
		dataC2MCU->timestamp=zros::base::GetSyncedTime();
		dataC2MCU->topic=(char *)malloc(topicdata.length());
		strcpy(dataC2MCU->topic, topicdata.c_str());
		dataC2MCU->payload._length =  pb.ByteSizeLong();
		dataC2MCU->payload._release = true;
    dataC2MCU->payload._buffer =(uint8_t *)malloc(pb.ByteSizeLong());
    memcpy(dataC2MCU->payload._buffer, pb_buff,pb.ByteSizeLong());
		CEventPuber::Send_idlc(carDrive_Basic_TrafficLightScene_Ntf_TrafficLight_Hash, dataC2MCU,sizeof(struct DDSData_Msg));
    free(pb_buff);


      // DDSData_Msg ddsMsg;
      // void *send_ptr = nullptr;
      // size_t  send_size = 0;
      // ddsMsg.topic = "hmi_interface____HmiInterface__BasicTrafficLightScene";
      // ddsMsg.timestamp = zros::base::GetSyncedTime();
      // ddsMsg.payload._buffer = (uint8_t *)pb_buff;
      // ddsMsg.payload._length = pb.ByteSizeLong();
      // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);
      // CEventPuber::Send(carDrive_Basic_TrafficLightScene_Ntf_TrafficLight_Hash, send_ptr, send_size);
      // free(send_ptr);
      // free(pb_buff);
      break;
    }

    case LIVE_MSG_DDS_NTF_C2_ADASSCORE:
    {
      /*C2_ADASScore*/
      DBG("live msg LIVE_MSG_DDS_NTF_C2_ADASSCORE \n");
      Soa::PB_C2_ADASScore pb;
      convert_to_pb_C2_ADASScore(live_msg->data, &pb);
      void* buf = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(buf, pb.ByteSizeLong());
      CEventPuber::Send(carDrive_Basc_ADASScore_Ntf_C2_ADASScore_Hash, buf, pb.ByteSizeLong());
      free(buf);
      break;
    }
    case LIVE_MSG_DDS_C2TRIPSUMMARY:
    { 
      DBG("live msg LIVE_MSG_DDS_C2TRIPSUMMARY \n");
      Soa::PB_C2TripSum pb;
      convert_to_pb_C2TripSum(live_msg->data, &pb);
      void* buf = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(buf, pb.ByteSizeLong());
      CEventPuber::Send(carDrive_Basc_C2TripSum_C2TripSummary_Hash, buf, pb.ByteSizeLong());
      free(buf);
      break;
    }
    case LIVE_MSG_DDS_NTF_AUTOTURNVIEW:
    {
       /*DDSData_Msg*/
        // HmiInterface::BasicTrafficLightScene pb;

        // void *pb_buff = malloc(pb.ByteSizeLong());
        // pb.SerializeToArray(pb_buff, pb.ByteSizeLong());

        // DDSData_Msg ddsMsg;
        // void *send_ptr = nullptr;
        // size_t  send_size = 0;
        // ddsMsg.topic = "hmi_interface____HmiInterface__AutoTurnViewData";
        // ddsMsg.timestamp = zros::base::GetSyncedTime();
        // ddsMsg.payload._buffer = (uint8_t *)pb_buff;
        // ddsMsg.payload._length = pb.ByteSizeLong();
        // convert_to_pb_DDSData_Msg_2(&ddsMsg, &send_ptr, &send_size);
        // CEventPuber::Send(carDrive_Basc_AutoTurnView_NTF_AutoTurnView_Hash, send_ptr, send_size);
        // free(send_ptr);
        // free(pb_buff);
        break;
    }
    case LIVE_MSG_DDS_NTF_ADASCRUISESET:
    {
      Soa::PB_ADASCruiseSet pb;
      convert_to_pb_ADASCruiseSet(live_msg->data, &pb);

      INF("live msg LIVE_MSG_DDS_NTF_ADASCRUISESET:      \
           mode[%d] IDAE[%d] IDAS[%d] lane[%d] udlc[%d]  \
           csla[%d] cslm[%d] over[%d] cslw[%d]  abs[%d]  \
           rel[%d]  auto[%d] adacc[%d] adl[%d] veh[%d]   \
           rcw[%d] sea[%d] bsds[%d] bsdr[%d]\n",
          ((ADASCruiseSet*)live_msg->data)->AD_CuriseMode,
          ((ADASCruiseSet*)live_msg->data)->AD_IDAEnableStatus,
          ((ADASCruiseSet*)live_msg->data)->AD_IDAstatus,
          ((ADASCruiseSet*)live_msg->data)->AD_LaneChangeFrequency,
          ((ADASCruiseSet*)live_msg->data)->AD_UDLCEnableStatus,
          ((ADASCruiseSet*)live_msg->data)->AD_CSLAEnableStatus,
          ((ADASCruiseSet*)live_msg->data)->AD_CSLmodeStatus,
          ((ADASCruiseSet*)live_msg->data)->AD_OverspeedSoundWarningEnSt,
          ((ADASCruiseSet*)live_msg->data)->AD_CSLWarnOffsetTp,
          ((ADASCruiseSet*)live_msg->data)->AD_AbsOverSpdWarnOffset,
          ((ADASCruiseSet*)live_msg->data)->AD_RelOverSpdWarnOffset,
          ((ADASCruiseSet*)live_msg->data)->AD_AutoDriveStyle,
          ((ADASCruiseSet*)live_msg->data)->AD_ADACCStyle,
          ((ADASCruiseSet*)live_msg->data)->AD_ADLanechangeStyle,
          ((ADASCruiseSet*)live_msg->data)->AD_VehicleStartRemindEnable,
          ((ADASCruiseSet*)live_msg->data)->AD_RCWEnableStatus,
          ((ADASCruiseSet*)live_msg->data)->AD_SEAModeStatus,
          ((ADASCruiseSet*)live_msg->data)->AD_BSDLCASetting,
          ((ADASCruiseSet*)live_msg->data)->AD_BSDLCARemindmode);

      void* buf = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(buf, pb.ByteSizeLong());
      CEventPuber::Send(carDrive_Basc_ADASCruiseSet_Ntf_ADASCruiseSet_Hash, buf, pb.ByteSizeLong());
      free(buf);
      break;
    }
    case LIVE_MSG_DDS_NTF_C2_IACCFAMLRRDMODSWTFB:
    {
      Soa::PB_C2_IACCFamlrRdModSwtFbSet pb;
      convert_to_pb_C2_IACCFamlrRdModSwtFbSet(live_msg->data, &pb);
      DBG("live msg LIVE_MSG_DDS_NTF_C2_IACCFAMLRRDMODSWTFB: mode[%d] \n", ((C2_IACCFamlrRdModSwtFbSet*)live_msg->data)->C2_IACCFamlrRdModSwtFb);
      void* buf = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(buf, pb.ByteSizeLong());
      CEventPuber::Send(carDrive_Basc_ADASCruiseSet_Ntf_C2_IACCFamlrRdModSwtFb_Hash, buf, pb.ByteSizeLong());
      free(buf);
      break;
    }
    case LIVE_MSG_DDS_NTF_AD_NIDSELFLRNGFB:
    {
      Soa::PB_AD_NIDSelfLrngFbset pb;
      convert_to_pb_AD_NIDSelfLrngFbset(live_msg->data, &pb);
      DBG("live msg LIVE_MSG_DDS_NTF_AD_NIDSELFLRNGFB: mode[%d] \n", ((AD_NIDSelfLrngFbset*)live_msg->data)->AD_NIDSelfLrngFb);
      void* buf = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(buf, pb.ByteSizeLong());
      CEventPuber::Send(carDrive_Basc_ADASCruiseSet_Ntf_AD_NIDSelfLrngFb_Hash, buf, pb.ByteSizeLong());
      free(buf);
      break;
    }
    case LIVE_MSG_DDS_NTF_AD_BSDLCAONOFFSET:
    {
      Soa::PB_AD_BSDLCAOnOffSet pb;
      convert_to_pb_AD_BSDLCAOnOffSet(live_msg->data, &pb);
      DBG("live msg LIVE_MSG_DDS_NTF_AD_BSDLCAONOFFSET: mode[%d] \n", ((AD_BSDLCAOnOffSet*)live_msg->data)->AD_BSDLCAOnOff);
      void* buf = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(buf, pb.ByteSizeLong());
      CEventPuber::Send(carDrive_Basc_ADASCruiseSet_Ntf_AD_BSDLCAOnOffSet_Hash, buf, pb.ByteSizeLong());
      free(buf);
      break;
    }
    case LIVE_MSG_DDS_NTF_AD_SEAONOFFSTS:
    {
      Soa::PB_AD_SEAOnOffStsSet pb;
      convert_to_pb_AD_SEAOnOffStsSet(live_msg->data, &pb);
      DBG("live msg LIVE_MSG_DDS_NTF_AD_SEAONOFFSTS: mode[%d] \n", ((AD_SEAOnOffStsSet*)live_msg->data)->AD_SEAOnOffSts);
      void* buf = malloc(pb.ByteSizeLong());
      pb.SerializeToArray(buf, pb.ByteSizeLong());
      CEventPuber::Send(carDrive_Basc_ADASCruiseSet_Ntf_AD_SEAOnOffSts_Hash, buf, pb.ByteSizeLong());
      free(buf);
      break;
    }
    default :
    {
      break;
    }
  }
#endif
}   


bool DDSNode::startWork_dds2zm_event(const config &mConfig)
{
  CEventSuber::SetConfig(mConfig);
  CMcuEventSuber::SetConfig(mConfig);
  std::function<void(int32_t, void *, int32_t)> func_soc =
      [this](int32_t hashID, void *buf, int32_t bufSize) {
        process_dds2soc_event(hashID, buf, bufSize);
      };

  std::function<void(int32_t, void *, int32_t)> func_mcu =
      [this](int32_t hashID, void *buf, int32_t bufSize) {
        process_dds2mcu_event(hashID, buf, bufSize);
      };
  std::string  str_dst = "null";
  for (const auto &itmap : mConfig.events.client)
  {
    int dst = getEventDestFromHashID(itmap.second.hash_id);
    if (DEST_SOC == dst)
    {
      CEventSuber::Recv(itmap.second.hash_id, func_soc);
      str_dst = "soc";
    }
    else if (DEST_MCU == dst)
    {
      CEventSuber::Recv(itmap.second.hash_id, func_mcu);
      str_dst = "mcu";
    } 
    else
    {
      str_dst = "null";
    }
    INF("dds2zm_event  server HashID : %d  Subscriber! DEST: %s \n",itmap.second.hash_id, str_dst.c_str());
  }

  for(const auto &itset :mConfig.mcu_events.client.viu_mcu.viu_fl.hash_ids)
  {
    int dst = getEventDestFromHashID(itset);
    if (DEST_SOC == dst)
    {
      CMcuEventSuber::Recv(itset, func_soc);
      str_dst = "soc";
    }
    else if (DEST_MCU == dst)
    {
      CMcuEventSuber::Recv(itset, func_mcu);
      str_dst = "mcu";
    } 
    else
    {
      str_dst = "null";
    }
    INF("dds2zm_event  viu fl HashID : %d  Subscriber! DEST: %s \n",itset, str_dst.c_str());
  }

  for(const auto &itset :mConfig.mcu_events.client.viu_mcu.viu_fr.hash_ids)
  {
    int dst = getEventDestFromHashID(itset);
    if (DEST_SOC == dst)
    {
      CMcuEventSuber::Recv(itset, func_soc);
      str_dst = "soc";
    }
    else if (DEST_MCU == dst)
    {
      CMcuEventSuber::Recv(itset, func_mcu);
      str_dst = "mcu";
    } 
    else
    {
      str_dst = "null";
    }
    INF("dds2zm_event  viu fr HashID : %d  Subscriber! DEST: %s \n",itset, str_dst.c_str());
  }

  for(const auto &itset :mConfig.mcu_events.client.viu_mcu.viu_r.hash_ids)
  {
    int dst = getEventDestFromHashID(itset);
    if (DEST_SOC == dst)
    {
      CMcuEventSuber::Recv(itset, func_soc);
      str_dst = "soc";
    }
    else if (DEST_MCU == dst)
    {
      CMcuEventSuber::Recv(itset, func_mcu);
      str_dst = "mcu";
    } 
    else
    {
      str_dst = "null";
    }
    INF("dds2zm_event  viu r HashID : %d  Subscriber! DEST: %s \n",itset, str_dst.c_str());
  }
  CEventSuber::Init();
  CMcuEventSuber::Init();
  return true;
}
bool DDSNode::startWork_zm2dds_event(const config &mConfig)
{
  /****************************************MCU*****************************************/
  CEventPuber::SetConfig(mConfig);
  CEventPuber::Init();

  CMcuEventPuber::SetConfig(mConfig);
  CMcuEventPuber::Init();

  zros::core::Subscriber<zros::core::PlainBufMessage>::SharedPtr subPtr = 
  zros::core::Transport::Instance()->CreateSubscriber<zros::core::PlainBufMessage>(live_msg_category_name(LIVE_MSG_CATEGORY_CA_MCU_TO_EDC_AGENT));
  string t = live_msg_category_name(LIVE_MSG_CATEGORY_CA_MCU_TO_EDC_AGENT);

  if (subPtr == nullptr)
  {
  return false;
  }

  subPtr->RegisterCallback([this, mConfig](const std::string &topic, const zros::core::PlainBufMessage &msg) 
  {
    process_mcu2dds_event(topic, msg);
  });
  if (!subPtr->Start())
  {
    return false;
  }
  m_live_msg_subscriberVec.push_back(subPtr);
  INF("mcu2dds_event  live msg category %s Subscriber!\n", t.c_str());

  for (int i = 0; i < sizeof(event_msg_map) /sizeof(event_msg_map_t); i++)
  {
    
    if(DEST_SOC == event_msg_map[i].src && DEST_DDS == event_msg_map[i].dest)
    {
      zros::core::Subscriber<zros::core::PlainBufMessage>::SharedPtr subPtr =
        zros::core::Transport::Instance()->CreateSubscriber<zros::core::PlainBufMessage>(event_msg_map[i].topic, zros::core::TOPIC_MESSAGE);
      if (nullptr == subPtr)
      {
        return false;
      }

      subPtr->RegisterCallback([this, mConfig](const std::string &topic, const zros::core::PlainBufMessage &msg) 
      {
        process_soc2dds_event(topic, msg);
      });
      if (!subPtr->Start())
      {
        return false;
      }
      m_subscriberVec.push_back(subPtr);
      INF("soc2dds_event topic: %s Subscriber! \n",event_msg_map[i].topic.c_str());
    }

  }
  return true;
}


