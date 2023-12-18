/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_SDMap.h
  Source: Basc_SDMap.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASC_SDMAP_H
#define DDSC_BASC_SDMAP_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
typedef struct carCabin_Basc_SDMap_Get_NaviStatus_In
{
  DDS_RPC_UnusedMember param;
} carCabin_Basc_SDMap_Get_NaviStatus_In;

#define carCabin_Basc_SDMap_Get_NaviStatus_Hash 172756998
typedef struct carCabin_Basc_SDMap_Get_LNavResidualDis_In
{
  DDS_RPC_UnusedMember param;
} carCabin_Basc_SDMap_Get_LNavResidualDis_In;

#define carCabin_Basc_SDMap_Get_LNavResidualDis_Hash 172757001
typedef struct carCabin_Basc_SDMap_RR_NaviToDestination_In
{
  struct Destination destination;
} carCabin_Basc_SDMap_RR_NaviToDestination_In;

#define carCabin_Basc_SDMap_RR_NaviToDestination_Hash 172752911
#define carCabin_Basc_SDMap_Ntf_MapSDPath_Hash 172785666
#define carCabin_Basc_SDMap_Ntf_NaviStatus_Hash 172785669
#define carCabin_Basc_SDMap_Ntf_LNavResidualDis_Hash 172785678
typedef struct carCabin_Basc_SDMap_Call
{
  int32_t _d;
  union
  {
    struct carCabin_Basc_SDMap_Get_NaviStatus_In Get_NaviStatus;
    struct carCabin_Basc_SDMap_Get_LNavResidualDis_In Get_LNavResidualDis;
    struct carCabin_Basc_SDMap_RR_NaviToDestination_In RR_NaviToDestination;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_SDMap_Call;

typedef struct carCabin_Basc_SDMap_Ntf_Message
{
  int32_t _d;
  union
  {
    struct DDSData_Msg Basc_SDMap_Ntf_MapSDPath;
    int8_t Basc_SDMap_Ntf_NaviStatus;
    uint64_t Basc_SDMap_Ntf_LNavResidualDis;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_SDMap_Ntf_Message;

typedef struct carCabin_Basc_SDMap_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carCabin_Basc_SDMap_Ntf_Message data;
} carCabin_Basc_SDMap_Ntf;

extern const dds_topic_descriptor_t carCabin_Basc_SDMap_Ntf_desc;

#define carCabin_Basc_SDMap_Ntf__alloc() \
((carCabin_Basc_SDMap_Ntf*) dds_alloc (sizeof (carCabin_Basc_SDMap_Ntf)));

#define carCabin_Basc_SDMap_Ntf_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_SDMap_Ntf_desc, (o))

typedef struct carCabin_Basc_SDMap_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carCabin_Basc_SDMap_Call data;
} carCabin_Basc_SDMap_Request;

extern const dds_topic_descriptor_t carCabin_Basc_SDMap_Request_desc;

#define carCabin_Basc_SDMap_Request__alloc() \
((carCabin_Basc_SDMap_Request*) dds_alloc (sizeof (carCabin_Basc_SDMap_Request)));

#define carCabin_Basc_SDMap_Request_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_SDMap_Request_desc, (o))

typedef struct carCabin_Basc_SDMap_Get_NaviStatus_Out
{
  int8_t return_;
} carCabin_Basc_SDMap_Get_NaviStatus_Out;

typedef struct carCabin_Basc_SDMap_Get_LNavResidualDis_Out
{
  uint64_t return_;
} carCabin_Basc_SDMap_Get_LNavResidualDis_Out;

typedef struct carCabin_Basc_SDMap_RR_NaviToDestination_Out
{
  int32_t return_;
} carCabin_Basc_SDMap_RR_NaviToDestination_Out;

typedef struct carCabin_Basc_SDMap_Return
{
  int32_t _d;
  union
  {
    struct carCabin_Basc_SDMap_Get_NaviStatus_Out Get_NaviStatus;
    struct carCabin_Basc_SDMap_Get_LNavResidualDis_Out Get_LNavResidualDis;
    struct carCabin_Basc_SDMap_RR_NaviToDestination_Out RR_NaviToDestination;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_SDMap_Return;

typedef struct carCabin_Basc_SDMap_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carCabin_Basc_SDMap_Return data;
} carCabin_Basc_SDMap_Reply;

extern const dds_topic_descriptor_t carCabin_Basc_SDMap_Reply_desc;

#define carCabin_Basc_SDMap_Reply__alloc() \
((carCabin_Basc_SDMap_Reply*) dds_alloc (sizeof (carCabin_Basc_SDMap_Reply)));

#define carCabin_Basc_SDMap_Reply_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_SDMap_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASC_SDMAP_H */