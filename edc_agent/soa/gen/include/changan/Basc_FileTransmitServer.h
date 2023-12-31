/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_FileTransmitServer.h
  Source: Basc_FileTransmitServer.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#ifndef DDSC_BASC_FILETRANSMITSERVER_H
#define DDSC_BASC_FILETRANSMITSERVER_H

#include "rpc_types.h"

#include "Common.h"

#include "dds/ddsc/dds_public_impl.h"

#include "dds/dds.h"

#ifdef __cplusplus
extern "C" {
#endif

#define gVersion_soa_cm ("v2.0.3")
typedef struct carDrive_Basc_FileTransmitServer_RR_FileReq_In
{
  uint32_t fileType;
} carDrive_Basc_FileTransmitServer_RR_FileReq_In;

#define carDrive_Basc_FileTransmitServer_RR_FileReq_Hash 225771524
typedef struct carDrive_Basc_FileTransmitServer_RR_ReceivedFile_In
{
  uint32_t fileId;
  uint8_t received;
} carDrive_Basc_FileTransmitServer_RR_ReceivedFile_In;

#define carDrive_Basc_FileTransmitServer_RR_ReceivedFile_Hash 225771525
#define carDrive_Basc_FileTransmitServer_Ntf_FileTransmit_Hash 225804291
typedef struct carDrive_Basc_FileTransmitServer_Call
{
  int32_t _d;
  union
  {
    struct carDrive_Basc_FileTransmitServer_RR_FileReq_In RR_FileReq;
    struct carDrive_Basc_FileTransmitServer_RR_ReceivedFile_In RR_ReceivedFile;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_FileTransmitServer_Call;

typedef struct carDrive_Basc_FileTransmitServer_Ntf_Message
{
  int32_t _d;
  union
  {
    struct DDSData_Msg Basc_FileTransmitServer_Ntf_FileTransmit;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_FileTransmitServer_Ntf_Message;

typedef struct carDrive_Basc_FileTransmitServer_Ntf
{
  struct DDS_NOTIFY_NotifyHeader header;
  struct carDrive_Basc_FileTransmitServer_Ntf_Message data;
} carDrive_Basc_FileTransmitServer_Ntf;

extern const dds_topic_descriptor_t carDrive_Basc_FileTransmitServer_Ntf_desc;

#define carDrive_Basc_FileTransmitServer_Ntf__alloc() \
((carDrive_Basc_FileTransmitServer_Ntf*) dds_alloc (sizeof (carDrive_Basc_FileTransmitServer_Ntf)));

#define carDrive_Basc_FileTransmitServer_Ntf_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_FileTransmitServer_Ntf_desc, (o))

typedef struct carDrive_Basc_FileTransmitServer_Request
{
  struct DDS_RPC_RequestHeader header;
  struct carDrive_Basc_FileTransmitServer_Call data;
} carDrive_Basc_FileTransmitServer_Request;

extern const dds_topic_descriptor_t carDrive_Basc_FileTransmitServer_Request_desc;

#define carDrive_Basc_FileTransmitServer_Request__alloc() \
((carDrive_Basc_FileTransmitServer_Request*) dds_alloc (sizeof (carDrive_Basc_FileTransmitServer_Request)));

#define carDrive_Basc_FileTransmitServer_Request_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_FileTransmitServer_Request_desc, (o))

typedef struct carDrive_Basc_FileTransmitServer_RR_FileReq_Out
{
  struct FileEntity return_;
} carDrive_Basc_FileTransmitServer_RR_FileReq_Out;

typedef struct carDrive_Basc_FileTransmitServer_RR_ReceivedFile_Out
{
  uint8_t return_;
} carDrive_Basc_FileTransmitServer_RR_ReceivedFile_Out;

typedef struct carDrive_Basc_FileTransmitServer_Return
{
  int32_t _d;
  union
  {
    struct carDrive_Basc_FileTransmitServer_RR_FileReq_Out RR_FileReq;
    struct carDrive_Basc_FileTransmitServer_RR_ReceivedFile_Out RR_ReceivedFile;
    DDS_RPC_UnknownOperation unknownOp;
  } _u;
} carDrive_Basc_FileTransmitServer_Return;

typedef struct carDrive_Basc_FileTransmitServer_Reply
{
  struct DDS_RPC_ReplyHeader header;
  struct carDrive_Basc_FileTransmitServer_Return data;
} carDrive_Basc_FileTransmitServer_Reply;

extern const dds_topic_descriptor_t carDrive_Basc_FileTransmitServer_Reply_desc;

#define carDrive_Basc_FileTransmitServer_Reply__alloc() \
((carDrive_Basc_FileTransmitServer_Reply*) dds_alloc (sizeof (carDrive_Basc_FileTransmitServer_Reply)));

#define carDrive_Basc_FileTransmitServer_Reply_free(d,o) \
dds_sample_free ((d), &carDrive_Basc_FileTransmitServer_Reply_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_BASC_FILETRANSMITSERVER_H */
