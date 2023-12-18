/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basic_TrafficSign.c
  Source: Basic_TrafficSign.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#include "Basic_TrafficSign.h"

#include "dds/dds.h"
#include "dds/ddsrt/sync.h"
#include <string.h>

static const uint32_t carDrive_Basic_TrafficSign_Ntf_ops [] =
{
  /* Basic_TrafficSign_Ntf */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_TrafficSign_Ntf, header), (3u << 16u) + 7u /* NotifyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_TrafficSign_Ntf, data), (3u << 16u) + 33u /* Basic_TrafficSign_Ntf_Message */,
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

  /* Basic_TrafficSign_Ntf_Message */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basic_TrafficSign_Ntf_Message, _d), 2u, (12u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 9 /* DDSData_Msg */, 96370689, offsetof (carDrive_Basic_TrafficSign_Ntf_Message, _u.Basic_TrafficSign_Ntf_TrafficSign), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basic_TrafficSign_Ntf_Message, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* DDSData_Msg */
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (DDSData_Msg, topic),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (DDSData_Msg, timestamp),
  DDS_OP_ADR | DDS_OP_TYPE_SEQ | DDS_OP_SUBTYPE_1BY, offsetof (DDSData_Msg, payload),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basic_TrafficSign_Ntf_desc =
{
  .m_size = sizeof (carDrive_Basic_TrafficSign_Ntf),
  .m_align = 8u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basic_TrafficSign_Ntf",
  .m_keys = NULL,
  .m_nops = 24,
  .m_ops = carDrive_Basic_TrafficSign_Ntf_ops,
  .m_meta = ""
};

static const uint32_t carDrive_Basic_TrafficSign_Request_ops [] =
{
  /* Basic_TrafficSign_Request */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_TrafficSign_Request, header), (3u << 16u) + 7u /* RequestHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_TrafficSign_Request, data), (3u << 16u) + 36u /* Basic_TrafficSign_Call */,
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

  /* Basic_TrafficSign_Call */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basic_TrafficSign_Call, _d), 1u, (8u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basic_TrafficSign_Call, _u.unknownOp), 0u,
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basic_TrafficSign_Request_desc =
{
  .m_size = sizeof (carDrive_Basic_TrafficSign_Request),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basic_TrafficSign_Request",
  .m_keys = NULL,
  .m_nops = 21,
  .m_ops = carDrive_Basic_TrafficSign_Request_ops,
  .m_meta = ""
};

static const uint32_t carDrive_Basic_TrafficSign_Reply_ops [] =
{
  /* Basic_TrafficSign_Reply */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_TrafficSign_Reply, header), (3u << 16u) + 7u /* ReplyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basic_TrafficSign_Reply, data), (3u << 16u) + 36u /* Basic_TrafficSign_Return */,
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

  /* Basic_TrafficSign_Return */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basic_TrafficSign_Return, _d), 1u, (8u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basic_TrafficSign_Return, _u.unknownOp), 0u,
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basic_TrafficSign_Reply_desc =
{
  .m_size = sizeof (carDrive_Basic_TrafficSign_Reply),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION | DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basic_TrafficSign_Reply",
  .m_keys = NULL,
  .m_nops = 21,
  .m_ops = carDrive_Basic_TrafficSign_Reply_ops,
  .m_meta = ""
};

