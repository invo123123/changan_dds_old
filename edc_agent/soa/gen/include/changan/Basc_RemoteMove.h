/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_RemoteMove.h
  Source: Basc_RemoteMove.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASC_REMOTEMOVE_H
#define DDSC_BASC_REMOTEMOVE_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
typedef struct carCabin_Basc_RemoteMove_RR_ScreenCoordinate_In
{
  uint32_t Xapp;
  uint32_t Yapp;
} carCabin_Basc_RemoteMove_RR_ScreenCoordinate_In;

#define carCabin_Basc_RemoteMove_RR_ScreenCoordinate_Hash 222560257
typedef struct carCabin_Basc_RemoteMove_RR_FunSwitch_In
{
  uint8_t State;
  char * RoomId;
} carCabin_Basc_RemoteMove_RR_FunSwitch_In;

#define carCabin_Basc_RemoteMove_RR_FunSwitch_Hash 222560258
typedef struct carCabin_Basc_RemoteMove_Call
{
  int32_t _d;
  union
  {
    struct carCabin_Basc_RemoteMove_RR_ScreenCoordinate_In RR_ScreenCoordinate;
    struct carCabin_Basc_RemoteMove_RR_FunSwitch_In RR_FunSwitch;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_RemoteMove_Call;

typedef struct carCabin_Basc_RemoteMove_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carCabin_Basc_RemoteMove_Call data;
} carCabin_Basc_RemoteMove_Request;

extern const dds_topic_descriptor_t carCabin_Basc_RemoteMove_Request_desc;

#define carCabin_Basc_RemoteMove_Request__alloc() \
((carCabin_Basc_RemoteMove_Request*) dds_alloc (sizeof (carCabin_Basc_RemoteMove_Request)));

#define carCabin_Basc_RemoteMove_Request_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_RemoteMove_Request_desc, (o))

typedef struct carCabin_Basc_RemoteMove_RR_ScreenCoordinate_Out
{
  uint8_t return_;
} carCabin_Basc_RemoteMove_RR_ScreenCoordinate_Out;

typedef struct carCabin_Basc_RemoteMove_RR_FunSwitch_Out
{
  uint8_t return_;
} carCabin_Basc_RemoteMove_RR_FunSwitch_Out;

typedef struct carCabin_Basc_RemoteMove_Return
{
  int32_t _d;
  union
  {
    struct carCabin_Basc_RemoteMove_RR_ScreenCoordinate_Out RR_ScreenCoordinate;
    struct carCabin_Basc_RemoteMove_RR_FunSwitch_Out RR_FunSwitch;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carCabin_Basc_RemoteMove_Return;

typedef struct carCabin_Basc_RemoteMove_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carCabin_Basc_RemoteMove_Return data;
} carCabin_Basc_RemoteMove_Reply;

extern const dds_topic_descriptor_t carCabin_Basc_RemoteMove_Reply_desc;

#define carCabin_Basc_RemoteMove_Reply__alloc() \
((carCabin_Basc_RemoteMove_Reply*) dds_alloc (sizeof (carCabin_Basc_RemoteMove_Reply)));

#define carCabin_Basc_RemoteMove_Reply_free(d,o) \
dds_sample_free ((d), &carCabin_Basc_RemoteMove_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASC_REMOTEMOVE_H */
