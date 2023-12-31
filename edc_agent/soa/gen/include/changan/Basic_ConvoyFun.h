/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basic_ConvoyFun.h
  Source: Basic_ConvoyFun.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASIC_CONVOYFUN_H
#define DDSC_BASIC_CONVOYFUN_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
#define carDrive_Basic_ConvoyFun_NTF_ConvoyFun_Hash 210075650
typedef struct carDrive_Basic_ConvoyFun_Call
{
  int32_t _d;
  union
  {
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basic_ConvoyFun_Call;

typedef struct carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg
{
  uint16_t crc;
  uint16_t counter;
  struct DDSData_Msg message;
} carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg;

typedef struct carDrive_Basic_ConvoyFun_Ntf_Message
{
  int32_t _d;
  union
  {
    struct carDrive_Secure_Basic_ConvoyFun_NTF_ConvoyFun_DDSData_Msg Basic_ConvoyFun_NTF_ConvoyFun;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basic_ConvoyFun_Ntf_Message;

typedef struct carDrive_Basic_ConvoyFun_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carDrive_Basic_ConvoyFun_Ntf_Message data;
} carDrive_Basic_ConvoyFun_Ntf;

extern const dds_topic_descriptor_t carDrive_Basic_ConvoyFun_Ntf_desc;

#define carDrive_Basic_ConvoyFun_Ntf__alloc() \
((carDrive_Basic_ConvoyFun_Ntf*) dds_alloc (sizeof (carDrive_Basic_ConvoyFun_Ntf)));

#define carDrive_Basic_ConvoyFun_Ntf_free(d,o) \
dds_sample_free ((d), &carDrive_Basic_ConvoyFun_Ntf_desc, (o))

typedef struct carDrive_Basic_ConvoyFun_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carDrive_Basic_ConvoyFun_Call data;
} carDrive_Basic_ConvoyFun_Request;

extern const dds_topic_descriptor_t carDrive_Basic_ConvoyFun_Request_desc;

#define carDrive_Basic_ConvoyFun_Request__alloc() \
((carDrive_Basic_ConvoyFun_Request*) dds_alloc (sizeof (carDrive_Basic_ConvoyFun_Request)));

#define carDrive_Basic_ConvoyFun_Request_free(d,o) \
dds_sample_free ((d), &carDrive_Basic_ConvoyFun_Request_desc, (o))

typedef struct carDrive_Basic_ConvoyFun_Return
{
  int32_t _d;
  union
  {
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basic_ConvoyFun_Return;

typedef struct carDrive_Basic_ConvoyFun_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carDrive_Basic_ConvoyFun_Return data;
} carDrive_Basic_ConvoyFun_Reply;

extern const dds_topic_descriptor_t carDrive_Basic_ConvoyFun_Reply_desc;

#define carDrive_Basic_ConvoyFun_Reply__alloc() \
((carDrive_Basic_ConvoyFun_Reply*) dds_alloc (sizeof (carDrive_Basic_ConvoyFun_Reply)));

#define carDrive_Basic_ConvoyFun_Reply_free(d,o) \
dds_sample_free ((d), &carDrive_Basic_ConvoyFun_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASIC_CONVOYFUN_H */
