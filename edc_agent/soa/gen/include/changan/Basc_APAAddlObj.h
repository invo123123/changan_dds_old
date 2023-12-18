/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_APAAddlObj.h
  Source: Basc_APAAddlObj.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASC_APAADDLOBJ_H
#define DDSC_BASC_APAADDLOBJ_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
typedef struct carDrive_Basc_APAAddlObj_Get_AD_APAAddlObj_In
{
  DDS_RPC_UnusedMember param;
} carDrive_Basc_APAAddlObj_Get_AD_APAAddlObj_In;

#define carDrive_Basc_APAAddlObj_Get_AD_APAAddlObj_Hash 261099524
#define carDrive_Basc_APAAddlObj_Ntf_AD_APAAddlObj_Hash 261128195
typedef struct carDrive_Basc_APAAddlObj_Call
{
  int32_t _d;
  union
  {
    struct carDrive_Basc_APAAddlObj_Get_AD_APAAddlObj_In Get_AD_APAAddlObj;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_APAAddlObj_Call;

typedef struct carDrive_Basc_APAAddlObj_Ntf_Message
{
  int32_t _d;
  union
  {
    struct DDSData_Msg Basc_APAAddlObj_Ntf_AD_APAAddlObj;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_APAAddlObj_Ntf_Message;

typedef struct carDrive_Basc_APAAddlObj_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carDrive_Basc_APAAddlObj_Ntf_Message data;
} carDrive_Basc_APAAddlObj_Ntf;

extern const dds_topic_descriptor_t carDrive_Basc_APAAddlObj_Ntf_desc;

#define carDrive_Basc_APAAddlObj_Ntf__alloc() \
((carDrive_Basc_APAAddlObj_Ntf*) dds_alloc (sizeof (carDrive_Basc_APAAddlObj_Ntf)));

#define carDrive_Basc_APAAddlObj_Ntf_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_APAAddlObj_Ntf_desc, (o))

typedef struct carDrive_Basc_APAAddlObj_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carDrive_Basc_APAAddlObj_Call data;
} carDrive_Basc_APAAddlObj_Request;

extern const dds_topic_descriptor_t carDrive_Basc_APAAddlObj_Request_desc;

#define carDrive_Basc_APAAddlObj_Request__alloc() \
((carDrive_Basc_APAAddlObj_Request*) dds_alloc (sizeof (carDrive_Basc_APAAddlObj_Request)));

#define carDrive_Basc_APAAddlObj_Request_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_APAAddlObj_Request_desc, (o))

typedef struct carDrive_Basc_APAAddlObj_Get_AD_APAAddlObj_Out
{
  struct DDSData_Msg return_;
} carDrive_Basc_APAAddlObj_Get_AD_APAAddlObj_Out;

typedef struct carDrive_Basc_APAAddlObj_Return
{
  int32_t _d;
  union
  {
    struct carDrive_Basc_APAAddlObj_Get_AD_APAAddlObj_Out Get_AD_APAAddlObj;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_APAAddlObj_Return;

typedef struct carDrive_Basc_APAAddlObj_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carDrive_Basc_APAAddlObj_Return data;
} carDrive_Basc_APAAddlObj_Reply;

extern const dds_topic_descriptor_t carDrive_Basc_APAAddlObj_Reply_desc;

#define carDrive_Basc_APAAddlObj_Reply__alloc() \
((carDrive_Basc_APAAddlObj_Reply*) dds_alloc (sizeof (carDrive_Basc_APAAddlObj_Reply)));

#define carDrive_Basc_APAAddlObj_Reply_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_APAAddlObj_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASC_APAADDLOBJ_H */