/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basic_APAFunctionReq.c
  Source: Basic_APAFunctionReq.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#include "Basic_APAFunctionReq.h"

#include "dds/dds.h"
#include "dds/ddsrt/sync.h"
#include <string.h>

static const uint32_t carDrive_Basic_APAFunctionReq_Ntf_ops [] =
{
  /* Basic_APAFunctionReq_Ntf */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_Ntf, header), (3u << 16u) + 7u /* NotifyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_Ntf, data), (3u << 16u) + 33u /* Basic_APAFunctionReq_Ntf_Message */,
  DDS_OP_RTS,

  /* NotifyHeader */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_NOTIFY_NotifyHeader, notifyId), (3u << 16u) + 4u /* SampleIdentity */,
  DDS_OP_RTS,

  /* SampleIdentity */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_SampleIdentity, writer_guid), (3u << 16u) + 7u /* GUID_t */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_SampleIdentity, sequence_number), (3u << 16u) + 17u /* SequenceNumber_t */,
  DDS_OP_RTS,

  /* GUID_t */
  DDS_OP_ADR | DDS_OP_TYPE_ARR | DDS_OP_SUBTYPE_1BY, offsetof (DDS_GUID_t, guidPrefix), 12u,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_GUID_t, entityId), (3u << 16u) + 4u /* EntityId_t */,
  DDS_OP_RTS,

  /* EntityId_t */
  DDS_OP_ADR | DDS_OP_TYPE_ARR | DDS_OP_SUBTYPE_1BY, offsetof (DDS_EntityId_t, entityKey), 3u,
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (DDS_EntityId_t, entityKind),
  DDS_OP_RTS,

  /* SequenceNumber_t */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (DDS_SequenceNumber_t, high),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (DDS_SequenceNumber_t, low),
  DDS_OP_RTS,

  /* Basic_APAFunctionReq_Ntf_Message */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basic_APAFunctionReq_Ntf_Message, _d), 2u, (12u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 9 /* APAFunctionRes */, 209747974, offsetof (carDrive_Basic_APAFunctionReq_Ntf_Message, _u.Basic_APAFunctionReq_Ntf_APAFunctionRes), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basic_APAFunctionReq_Ntf_Message, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* APAFunctionRes */
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (APAFunctionRes, APAFunction),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basic_APAFunctionReq_Ntf_desc =
{
  .m_size = sizeof (carDrive_Basic_APAFunctionReq_Ntf),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION | DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basic_APAFunctionReq_Ntf",
  .m_keys = NULL,
  .m_nops = 22,
  .m_ops = carDrive_Basic_APAFunctionReq_Ntf_ops,
  .m_meta = ""
};

static const uint32_t carDrive_Basic_APAFunctionReq_Request_ops [] =
{
  /* Basic_APAFunctionReq_Request */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_Request, header), (3u << 16u) + 7u /* RequestHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_Request, data), (3u << 16u) + 36u /* Basic_APAFunctionReq_Call */,
  DDS_OP_RTS,

  /* RequestHeader */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_RPC_RequestHeader, requestId), (3u << 16u) + 7u /* SampleIdentity */,
  DDS_OP_ADR | DDS_OP_TYPE_BST, offsetof (DDS_RPC_RequestHeader, instanceTitle), 256u,
  DDS_OP_RTS,

  /* SampleIdentity */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_SampleIdentity, writer_guid), (3u << 16u) + 7u /* GUID_t */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_SampleIdentity, sequence_number), (3u << 16u) + 17u /* SequenceNumber_t */,
  DDS_OP_RTS,

  /* GUID_t */
  DDS_OP_ADR | DDS_OP_TYPE_ARR | DDS_OP_SUBTYPE_1BY, offsetof (DDS_GUID_t, guidPrefix), 12u,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_GUID_t, entityId), (3u << 16u) + 4u /* EntityId_t */,
  DDS_OP_RTS,

  /* EntityId_t */
  DDS_OP_ADR | DDS_OP_TYPE_ARR | DDS_OP_SUBTYPE_1BY, offsetof (DDS_EntityId_t, entityKey), 3u,
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (DDS_EntityId_t, entityKind),
  DDS_OP_RTS,

  /* SequenceNumber_t */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (DDS_SequenceNumber_t, high),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (DDS_SequenceNumber_t, low),
  DDS_OP_RTS,

  /* Basic_APAFunctionReq_Call */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basic_APAFunctionReq_Call, _d), 3u, (16u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 13 /* Basic_APAFunctionReq_RR_APAFunctionReq_In */, 209715205, offsetof (carDrive_Basic_APAFunctionReq_Call, _u.RR_APAFunctionReq), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 16 /* Basic_APAFunctionReq_RR_APAControleReq_In */, 209715210, offsetof (carDrive_Basic_APAFunctionReq_Call, _u.RR_APAControleReq), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basic_APAFunctionReq_Call, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* Basic_APAFunctionReq_RR_APAFunctionReq_In */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_In, RR_APAFunctionReq), (3u << 16u) + 4u /* APAFunctionReq */,
  DDS_OP_RTS,

  /* APAFunctionReq */
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (APAFunctionReq, APAFunction),
  DDS_OP_RTS,

  /* Basic_APAFunctionReq_RR_APAControleReq_In */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_RR_APAControleReq_In, APAControlReq), (3u << 16u) + 4u /* APAControleReq */,
  DDS_OP_RTS,

  /* APAControleReq */
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (APAControleReq, APAControlEnable),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (APAControleReq, Heartbeat),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basic_APAFunctionReq_Request_desc =
{
  .m_size = sizeof (carDrive_Basic_APAFunctionReq_Request),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basic_APAFunctionReq_Request",
  .m_keys = NULL,
  .m_nops = 30,
  .m_ops = carDrive_Basic_APAFunctionReq_Request_ops,
  .m_meta = ""
};

static const uint32_t carDrive_Basic_APAFunctionReq_Reply_ops [] =
{
  /* Basic_APAFunctionReq_Reply */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_Reply, header), (3u << 16u) + 7u /* ReplyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_Reply, data), (3u << 16u) + 36u /* Basic_APAFunctionReq_Return */,
  DDS_OP_RTS,

  /* ReplyHeader */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_RPC_ReplyHeader, relatedRequestId), (3u << 16u) + 7u /* SampleIdentity */,
  DDS_OP_ADR | DDS_OP_TYPE_ENU | (2 << DDS_OP_FLAG_SZ_SHIFT), offsetof (DDS_RPC_ReplyHeader, remoteEx), 8u,
  DDS_OP_RTS,

  /* SampleIdentity */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_SampleIdentity, writer_guid), (3u << 16u) + 7u /* GUID_t */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_SampleIdentity, sequence_number), (3u << 16u) + 17u /* SequenceNumber_t */,
  DDS_OP_RTS,

  /* GUID_t */
  DDS_OP_ADR | DDS_OP_TYPE_ARR | DDS_OP_SUBTYPE_1BY, offsetof (DDS_GUID_t, guidPrefix), 12u,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (DDS_GUID_t, entityId), (3u << 16u) + 4u /* EntityId_t */,
  DDS_OP_RTS,

  /* EntityId_t */
  DDS_OP_ADR | DDS_OP_TYPE_ARR | DDS_OP_SUBTYPE_1BY, offsetof (DDS_EntityId_t, entityKey), 3u,
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (DDS_EntityId_t, entityKind),
  DDS_OP_RTS,

  /* SequenceNumber_t */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (DDS_SequenceNumber_t, high),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (DDS_SequenceNumber_t, low),
  DDS_OP_RTS,

  /* Basic_APAFunctionReq_Return */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basic_APAFunctionReq_Return, _d), 3u, (16u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 13 /* Basic_APAFunctionReq_RR_APAFunctionReq_Out */, 209715205, offsetof (carDrive_Basic_APAFunctionReq_Return, _u.RR_APAFunctionReq), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 16 /* Basic_APAFunctionReq_RR_APAControleReq_Out */, 209715210, offsetof (carDrive_Basic_APAFunctionReq_Return, _u.RR_APAControleReq), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basic_APAFunctionReq_Return, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* Basic_APAFunctionReq_RR_APAFunctionReq_Out */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_RR_APAFunctionReq_Out, return_), (3u << 16u) + 4u /* APAReqreply */,
  DDS_OP_RTS,

  /* APAReqreply */
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (APAReqreply, reply),
  DDS_OP_RTS,

  /* Basic_APAFunctionReq_RR_APAControleReq_Out */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_APAFunctionReq_RR_APAControleReq_Out, return_), (3u << 16u) + 65533u /* APAReqreply */,
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basic_APAFunctionReq_Reply_desc =
{
  .m_size = sizeof (carDrive_Basic_APAFunctionReq_Reply),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION | DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basic_APAFunctionReq_Reply",
  .m_keys = NULL,
  .m_nops = 27,
  .m_ops = carDrive_Basic_APAFunctionReq_Reply_ops,
  .m_meta = ""
};
