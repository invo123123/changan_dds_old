/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_AutoTurnView.h
  Source: Basc_AutoTurnView.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASC_AUTOTURNVIEW_H
#define DDSC_BASC_AUTOTURNVIEW_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
#define carDrive_Basc_AutoTurnView_NTF_AutoTurnView_Hash 257064961
typedef struct carDrive_Basc_AutoTurnView_Call
{
  int32_t _d;
  union
  {
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_AutoTurnView_Call;

typedef struct carDrive_Basc_AutoTurnView_Ntf_Message
{
  int32_t _d;
  union
  {
    struct DDSData_Msg Basc_AutoTurnView_NTF_AutoTurnView;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_AutoTurnView_Ntf_Message;

typedef struct carDrive_Basc_AutoTurnView_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carDrive_Basc_AutoTurnView_Ntf_Message data;
} carDrive_Basc_AutoTurnView_Ntf;

extern const dds_topic_descriptor_t carDrive_Basc_AutoTurnView_Ntf_desc;

#define carDrive_Basc_AutoTurnView_Ntf__alloc() \
((carDrive_Basc_AutoTurnView_Ntf*) dds_alloc (sizeof (carDrive_Basc_AutoTurnView_Ntf)));

#define carDrive_Basc_AutoTurnView_Ntf_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_AutoTurnView_Ntf_desc, (o))

typedef struct carDrive_Basc_AutoTurnView_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carDrive_Basc_AutoTurnView_Call data;
} carDrive_Basc_AutoTurnView_Request;

extern const dds_topic_descriptor_t carDrive_Basc_AutoTurnView_Request_desc;

#define carDrive_Basc_AutoTurnView_Request__alloc() \
((carDrive_Basc_AutoTurnView_Request*) dds_alloc (sizeof (carDrive_Basc_AutoTurnView_Request)));

#define carDrive_Basc_AutoTurnView_Request_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_AutoTurnView_Request_desc, (o))

typedef struct carDrive_Basc_AutoTurnView_Return
{
  int32_t _d;
  union
  {
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_AutoTurnView_Return;

typedef struct carDrive_Basc_AutoTurnView_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carDrive_Basc_AutoTurnView_Return data;
} carDrive_Basc_AutoTurnView_Reply;

extern const dds_topic_descriptor_t carDrive_Basc_AutoTurnView_Reply_desc;

#define carDrive_Basc_AutoTurnView_Reply__alloc() \
((carDrive_Basc_AutoTurnView_Reply*) dds_alloc (sizeof (carDrive_Basc_AutoTurnView_Reply)));

#define carDrive_Basc_AutoTurnView_Reply_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_AutoTurnView_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASC_AUTOTURNVIEW_H */
