/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basic_APAFunctionReq.h
  Source: Basic_APAFunctionReq.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASIC_APAFUNCTIONREQ_H
#define DDSC_BASIC_APAFUNCTIONREQ_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
typedef struct carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_In
{
  struct APAFunctionReq RR_APAFunctionReq;
} carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_In;

#define carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Hash 209715205
typedef struct carDrive_Basic_APAFunctionReq_RR_APAControleReq_In
{
  struct APAControleReq APAControlReq;
} carDrive_Basic_APAFunctionReq_RR_APAControleReq_In;

#define carDrive_Basic_APAFunctionReq_RR_APAControleReq_Hash 209715210
#define carDrive_Basic_APAFunctionReq_Ntf_APAFunctionRes_Hash 209747974
typedef struct carDrive_Basic_APAFunctionReq_Call
{
  int32_t _d;
  union
  {
    struct carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_In RR_APAFunctionReq;
    struct carDrive_Basic_APAFunctionReq_RR_APAControleReq_In RR_APAControleReq;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basic_APAFunctionReq_Call;

typedef struct carDrive_Basic_APAFunctionReq_Ntf_Message
{
  int32_t _d;
  union
  {
    struct APAFunctionRes Basic_APAFunctionReq_Ntf_APAFunctionRes;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basic_APAFunctionReq_Ntf_Message;

typedef struct carDrive_Basic_APAFunctionReq_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carDrive_Basic_APAFunctionReq_Ntf_Message data;
} carDrive_Basic_APAFunctionReq_Ntf;

extern const dds_topic_descriptor_t carDrive_Basic_APAFunctionReq_Ntf_desc;

#define carDrive_Basic_APAFunctionReq_Ntf__alloc() \
((carDrive_Basic_APAFunctionReq_Ntf*) dds_alloc (sizeof (carDrive_Basic_APAFunctionReq_Ntf)));

#define carDrive_Basic_APAFunctionReq_Ntf_free(d,o) \
dds_sample_free ((d), &carDrive_Basic_APAFunctionReq_Ntf_desc, (o))

typedef struct carDrive_Basic_APAFunctionReq_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carDrive_Basic_APAFunctionReq_Call data;
} carDrive_Basic_APAFunctionReq_Request;

extern const dds_topic_descriptor_t carDrive_Basic_APAFunctionReq_Request_desc;

#define carDrive_Basic_APAFunctionReq_Request__alloc() \
((carDrive_Basic_APAFunctionReq_Request*) dds_alloc (sizeof (carDrive_Basic_APAFunctionReq_Request)));

#define carDrive_Basic_APAFunctionReq_Request_free(d,o) \
dds_sample_free ((d), &carDrive_Basic_APAFunctionReq_Request_desc, (o))

typedef struct carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Out
{
  struct APAReqreply return_;
} carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Out;

typedef struct carDrive_Basic_APAFunctionReq_RR_APAControleReq_Out
{
  struct APAReqreply return_;
} carDrive_Basic_APAFunctionReq_RR_APAControleReq_Out;

typedef struct carDrive_Basic_APAFunctionReq_Return
{
  int32_t _d;
  union
  {
    struct carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Out RR_APAFunctionReq;
    struct carDrive_Basic_APAFunctionReq_RR_APAControleReq_Out RR_APAControleReq;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basic_APAFunctionReq_Return;

typedef struct carDrive_Basic_APAFunctionReq_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carDrive_Basic_APAFunctionReq_Return data;
} carDrive_Basic_APAFunctionReq_Reply;

extern const dds_topic_descriptor_t carDrive_Basic_APAFunctionReq_Reply_desc;

#define carDrive_Basic_APAFunctionReq_Reply__alloc() \
((carDrive_Basic_APAFunctionReq_Reply*) dds_alloc (sizeof (carDrive_Basic_APAFunctionReq_Reply)));

#define carDrive_Basic_APAFunctionReq_Reply_free(d,o) \
dds_sample_free ((d), &carDrive_Basic_APAFunctionReq_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASIC_APAFUNCTIONREQ_H */
