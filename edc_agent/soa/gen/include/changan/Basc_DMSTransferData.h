/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_DMSTransferData.h
  Source: Basc_DMSTransferData.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASC_DMSTRANSFERDATA_H
#define DDSC_BASC_DMSTRANSFERDATA_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
#define carCabin_Basc_DMSTransferData_Ntf_SendProtoData_Hash 213942275
typedef struct carCabin_Basc_DMSTransferData_Call
{
  int32_t _d;
  union
  {
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_DMSTransferData_Call;

typedef struct carCabin_Basc_DMSTransferData_Ntf_Message
{
  int32_t _d;
  union
  {
    struct DDSData_Msg Basc_DMSTransferData_Ntf_SendProtoData;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_DMSTransferData_Ntf_Message;

typedef struct carCabin_Basc_DMSTransferData_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carCabin_Basc_DMSTransferData_Ntf_Message data;
} carCabin_Basc_DMSTransferData_Ntf;

extern const dds_topic_descriptor_t carCabin_Basc_DMSTransferData_Ntf_desc;

#define carCabin_Basc_DMSTransferData_Ntf__alloc() \
((carCabin_Basc_DMSTransferData_Ntf*) dds_alloc (sizeof (carCabin_Basc_DMSTransferData_Ntf)));

#define carCabin_Basc_DMSTransferData_Ntf_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_DMSTransferData_Ntf_desc, (o))

typedef struct carCabin_Basc_DMSTransferData_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carCabin_Basc_DMSTransferData_Call data;
} carCabin_Basc_DMSTransferData_Request;

extern const dds_topic_descriptor_t carCabin_Basc_DMSTransferData_Request_desc;

#define carCabin_Basc_DMSTransferData_Request__alloc() \
((carCabin_Basc_DMSTransferData_Request*) dds_alloc (sizeof (carCabin_Basc_DMSTransferData_Request)));

#define carCabin_Basc_DMSTransferData_Request_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_DMSTransferData_Request_desc, (o))

typedef struct carCabin_Basc_DMSTransferData_Return
{
  int32_t _d;
  union
  {
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_DMSTransferData_Return;

typedef struct carCabin_Basc_DMSTransferData_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carCabin_Basc_DMSTransferData_Return data;
} carCabin_Basc_DMSTransferData_Reply;

extern const dds_topic_descriptor_t carCabin_Basc_DMSTransferData_Reply_desc;

#define carCabin_Basc_DMSTransferData_Reply__alloc() \
((carCabin_Basc_DMSTransferData_Reply*) dds_alloc (sizeof (carCabin_Basc_DMSTransferData_Reply)));

#define carCabin_Basc_DMSTransferData_Reply_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_DMSTransferData_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASC_DMSTRANSFERDATA_H */
