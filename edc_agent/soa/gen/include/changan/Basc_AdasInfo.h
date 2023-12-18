/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_AdasInfo.h
  Source: Basc_AdasInfo.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASC_ADASINFO_H
#define DDSC_BASC_ADASINFO_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
#define carCabin_Basc_AdasInfo_Ntf_ADAS_MapCommonSignal_Hash 180060161
#define carCabin_Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal_Hash 180060162
#define carCabin_Basc_AdasInfo_Ntf_AdasMapTrafficSign_Hash 180060163
typedef struct carCabin_Basc_AdasInfo_Call
{
  int32_t _d;
  union
  {
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_AdasInfo_Call;

typedef struct carCabin_Basc_AdasInfo_Ntf_Message
{
  int32_t _d;
  union
  {
    struct ADAS_MapCommonSignal Basc_AdasInfo_Ntf_ADAS_MapCommonSignal;
    struct ADAS_MapNavigationSignal Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal;
    struct ADAS_MapTrafficSign Basc_AdasInfo_Ntf_AdasMapTrafficSign;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_AdasInfo_Ntf_Message;

typedef struct carCabin_Basc_AdasInfo_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carCabin_Basc_AdasInfo_Ntf_Message data;
} carCabin_Basc_AdasInfo_Ntf;

extern const dds_topic_descriptor_t carCabin_Basc_AdasInfo_Ntf_desc;

#define carCabin_Basc_AdasInfo_Ntf__alloc() \
((carCabin_Basc_AdasInfo_Ntf*) dds_alloc (sizeof (carCabin_Basc_AdasInfo_Ntf)));

#define carCabin_Basc_AdasInfo_Ntf_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_AdasInfo_Ntf_desc, (o))

typedef struct carCabin_Basc_AdasInfo_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carCabin_Basc_AdasInfo_Call data;
} carCabin_Basc_AdasInfo_Request;

extern const dds_topic_descriptor_t carCabin_Basc_AdasInfo_Request_desc;

#define carCabin_Basc_AdasInfo_Request__alloc() \
((carCabin_Basc_AdasInfo_Request*) dds_alloc (sizeof (carCabin_Basc_AdasInfo_Request)));

#define carCabin_Basc_AdasInfo_Request_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_AdasInfo_Request_desc, (o))

typedef struct carCabin_Basc_AdasInfo_Return
{
  int32_t _d;
  union
  {
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_AdasInfo_Return;

typedef struct carCabin_Basc_AdasInfo_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carCabin_Basc_AdasInfo_Return data;
} carCabin_Basc_AdasInfo_Reply;

extern const dds_topic_descriptor_t carCabin_Basc_AdasInfo_Reply_desc;

#define carCabin_Basc_AdasInfo_Reply__alloc() \
((carCabin_Basc_AdasInfo_Reply*) dds_alloc (sizeof (carCabin_Basc_AdasInfo_Reply)));

#define carCabin_Basc_AdasInfo_Reply_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_AdasInfo_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASC_ADASINFO_H */
