/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_APAInteract.h
  Source: Basc_APAInteract.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASC_APAINTERACT_H
#define DDSC_BASC_APAINTERACT_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
typedef struct carDrive_Basc_APAInteract_Get_AD_APACustSlot_In
{
  DDS_RPC_UnusedMember param;
} carDrive_Basc_APAInteract_Get_AD_APACustSlot_In;

#define carDrive_Basc_APAInteract_Get_AD_APACustSlot_Hash 246812676
typedef struct carDrive_Basc_APAInteract_Get_AD_APADynguidance_In
{
  DDS_RPC_UnusedMember param;
} carDrive_Basc_APAInteract_Get_AD_APADynguidance_In;

#define carDrive_Basc_APAInteract_Get_AD_APADynguidance_Hash 246812682
typedef struct carDrive_Basc_APAInteract_Get_AD_APADynrecommd_In
{
  DDS_RPC_UnusedMember param;
} carDrive_Basc_APAInteract_Get_AD_APADynrecommd_In;

#define carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Hash 246812688
typedef struct carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_In
{
  DDS_RPC_UnusedMember param;
} carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_In;

#define carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Hash 246812694
typedef struct carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_In
{
  struct EDC_APADrvrReqOnOffData EDC_APADrvrReqOnOffData;
  struct RequestInfo RequestInfo;
} carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_In;

#define carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Hash 246808601
typedef struct carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_In
{
  struct EDC_APADrvrReqSlotIDData EDC_APADrvrReqSlotIDData;
  struct RequestInfo RequestInfo;
} carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_In;

#define carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Hash 246808602
typedef struct carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_In
{
  struct EDC_APAParkInSelectData EDC_APAParkInSelectData;
  struct RequestInfo RequestInfo;
} carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_In;

#define carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Hash 246808603
typedef struct carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_In
{
  struct EDC_APADynamicOperateData EDC_APADynamicOperateData;
  struct RequestInfo RequestInfo;
} carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_In;

#define carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Hash 246808604
typedef struct carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_In
{
  struct EDC_APAParkOutSelectData EDC_APAParkOutSelectData;
  struct RequestInfo RequestInfo;
} carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_In;

#define carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Hash 246808605
typedef struct carDrive_Basc_APAInteract_RR_EDC_APACustSlot_In
{
  struct EDC_APACustSlotData EDC_APACustSlotData;
  struct RequestInfo RequestInfo;
} carDrive_Basc_APAInteract_RR_EDC_APACustSlot_In;

#define carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Hash 246808606
typedef struct carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_In
{
  struct EDC_RADSDrvrReqData EDC_RADSDrvrReqData;
  struct RequestInfo RequestInfo;
} carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_In;

#define carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Hash 246808607
#define carDrive_Basc_APAInteract_Ntf_AD_APACustSlot_Hash 246841347
#define carDrive_Basc_APAInteract_Ntf_AD_APADynguidance_Hash 246841353
#define carDrive_Basc_APAInteract_Ntf_AD_APADynrecommd_Hash 246841359
#define carDrive_Basc_APAInteract_Ntf_AD_APAFctnIndnMsg_Hash 246841365
typedef struct carDrive_Basc_APAInteract_Call
{
  int32_t _d;
  union
  {
    struct carDrive_Basc_APAInteract_Get_AD_APACustSlot_In Get_AD_APACustSlot;
    struct carDrive_Basc_APAInteract_Get_AD_APADynguidance_In Get_AD_APADynguidance;
    struct carDrive_Basc_APAInteract_Get_AD_APADynrecommd_In Get_AD_APADynrecommd;
    struct carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_In Get_AD_APAFctnIndnMsg;
    struct carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_In RR_EDC_APADrvrReqOnOff;
    struct carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_In RR_EDC_APADrvrReqSlotID;
    struct carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_In RR_EDC_APAParkInSelect;
    struct carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_In RR_EDC_APADynamicOperate;
    struct carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_In RR_EDC_APAParkOutSelect;
    struct carDrive_Basc_APAInteract_RR_EDC_APACustSlot_In RR_EDC_APACustSlot;
    struct carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_In RR_EDC_RADSDrvrReq;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_APAInteract_Call;

typedef struct carDrive_Basc_APAInteract_Ntf_Message
{
  int32_t _d;
  union
  {
    struct AD_APACustSlotData Basc_APAInteract_Ntf_AD_APACustSlot;
    struct AD_APADynguidanceData Basc_APAInteract_Ntf_AD_APADynguidance;
    struct AD_APADynrecommdData Basc_APAInteract_Ntf_AD_APADynrecommd;
    struct AD_APAFctnIndnMsgData Basc_APAInteract_Ntf_AD_APAFctnIndnMsg;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_APAInteract_Ntf_Message;

typedef struct carDrive_Basc_APAInteract_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carDrive_Basc_APAInteract_Ntf_Message data;
} carDrive_Basc_APAInteract_Ntf;

extern const dds_topic_descriptor_t carDrive_Basc_APAInteract_Ntf_desc;

#define carDrive_Basc_APAInteract_Ntf__alloc() \
((carDrive_Basc_APAInteract_Ntf*) dds_alloc (sizeof (carDrive_Basc_APAInteract_Ntf)));

#define carDrive_Basc_APAInteract_Ntf_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_APAInteract_Ntf_desc, (o))

typedef struct carDrive_Basc_APAInteract_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carDrive_Basc_APAInteract_Call data;
} carDrive_Basc_APAInteract_Request;

extern const dds_topic_descriptor_t carDrive_Basc_APAInteract_Request_desc;

#define carDrive_Basc_APAInteract_Request__alloc() \
((carDrive_Basc_APAInteract_Request*) dds_alloc (sizeof (carDrive_Basc_APAInteract_Request)));

#define carDrive_Basc_APAInteract_Request_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_APAInteract_Request_desc, (o))

typedef struct carDrive_Basc_APAInteract_Get_AD_APACustSlot_Out
{
  struct AD_APACustSlotData return_;
} carDrive_Basc_APAInteract_Get_AD_APACustSlot_Out;

typedef struct carDrive_Basc_APAInteract_Get_AD_APADynguidance_Out
{
  struct AD_APADynguidanceData return_;
} carDrive_Basc_APAInteract_Get_AD_APADynguidance_Out;

typedef struct carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Out
{
  struct AD_APADynrecommdData return_;
} carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Out;

typedef struct carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Out
{
  struct AD_APAFctnIndnMsgData return_;
} carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Out;

typedef struct carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Out
{
  uint8_t return_;
} carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Out;

typedef struct carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Out
{
  uint8_t return_;
} carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Out;

typedef struct carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Out
{
  uint8_t return_;
} carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Out;

typedef struct carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Out
{
  uint8_t return_;
} carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Out;

typedef struct carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Out
{
  uint8_t return_;
} carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Out;

typedef struct carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Out
{
  uint8_t return_;
} carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Out;

typedef struct carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Out
{
  uint8_t return_;
} carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Out;

typedef struct carDrive_Basc_APAInteract_Return
{
  int32_t _d;
  union
  {
    struct carDrive_Basc_APAInteract_Get_AD_APACustSlot_Out Get_AD_APACustSlot;
    struct carDrive_Basc_APAInteract_Get_AD_APADynguidance_Out Get_AD_APADynguidance;
    struct carDrive_Basc_APAInteract_Get_AD_APADynrecommd_Out Get_AD_APADynrecommd;
    struct carDrive_Basc_APAInteract_Get_AD_APAFctnIndnMsg_Out Get_AD_APAFctnIndnMsg;
    struct carDrive_Basc_APAInteract_RR_EDC_APADrvrReqOnOff_Out RR_EDC_APADrvrReqOnOff;
    struct carDrive_Basc_APAInteract_RR_EDC_APADrvrReqSlotID_Out RR_EDC_APADrvrReqSlotID;
    struct carDrive_Basc_APAInteract_RR_EDC_APAParkInSelect_Out RR_EDC_APAParkInSelect;
    struct carDrive_Basc_APAInteract_RR_EDC_APADynamicOperate_Out RR_EDC_APADynamicOperate;
    struct carDrive_Basc_APAInteract_RR_EDC_APAParkOutSelect_Out RR_EDC_APAParkOutSelect;
    struct carDrive_Basc_APAInteract_RR_EDC_APACustSlot_Out RR_EDC_APACustSlot;
    struct carDrive_Basc_APAInteract_RR_EDC_RADSDrvrReq_Out RR_EDC_RADSDrvrReq;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_APAInteract_Return;

typedef struct carDrive_Basc_APAInteract_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carDrive_Basc_APAInteract_Return data;
} carDrive_Basc_APAInteract_Reply;

extern const dds_topic_descriptor_t carDrive_Basc_APAInteract_Reply_desc;

#define carDrive_Basc_APAInteract_Reply__alloc() \
((carDrive_Basc_APAInteract_Reply*) dds_alloc (sizeof (carDrive_Basc_APAInteract_Reply)));

#define carDrive_Basc_APAInteract_Reply_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_APAInteract_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASC_APAINTERACT_H */