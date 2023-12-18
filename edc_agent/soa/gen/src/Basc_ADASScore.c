/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_ADASScore.c
  Source: Basc_ADASScore.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#include "Basc_ADASScore.h"

#include "dds/dds.h"
#include "dds/ddsrt/sync.h"
#include <string.h>

static const uint32_t carDrive_Basc_ADASScore_Ntf_ops [] =
{
  /* Basc_ADASScore_Ntf */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_ADASScore_Ntf, header), (3u << 16u) + 7u /* NotifyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_ADASScore_Ntf, data), (3u << 16u) + 33u /* Basc_ADASScore_Ntf_Message */,
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

  /* Basc_ADASScore_Ntf_Message */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basc_ADASScore_Ntf_Message, _d), 2u, (12u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 9 /* C2_ADASScore */, 222068737, offsetof (carDrive_Basc_ADASScore_Ntf_Message, _u.Basc_ADASScore_Ntf_C2_ADASScore), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basc_ADASScore_Ntf_Message, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* C2_ADASScore */
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (C2_ADASScore, C2_AutoDrivinScoreReason),
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (C2_ADASScore, C2_UserIDnumber),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (C2_ADASScore, C2_AutoDrivingScore),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2_ADASScore, C2_IACCTrip),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2_ADASScore, C2_NIDHighspeedTrip),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2_ADASScore, C2_NIDCityTrip),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2_ADASScore, C2_AutoDrivingScoreThisTrip),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basc_ADASScore_Ntf_desc =
{
  .m_size = sizeof (carDrive_Basc_ADASScore_Ntf),
  .m_align = sizeof (char *),
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basc_ADASScore_Ntf",
  .m_keys = NULL,
  .m_nops = 28,
  .m_ops = carDrive_Basc_ADASScore_Ntf_ops,
  .m_meta = ""
};

static const uint32_t carDrive_Basc_ADASScore_Request_ops [] =
{
  /* Basc_ADASScore_Request */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_ADASScore_Request, header), (3u << 16u) + 7u /* RequestHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_ADASScore_Request, data), (3u << 16u) + 36u /* Basc_ADASScore_Call */,
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

  /* Basc_ADASScore_Call */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basc_ADASScore_Call, _d), 2u, (12u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 9 /* Basc_ADASScore_Get_C2_GetADASScore_In */, 222040066, offsetof (carDrive_Basc_ADASScore_Call, _u.Get_C2_GetADASScore), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basc_ADASScore_Call, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* Basc_ADASScore_Get_C2_GetADASScore_In */
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (carDrive_Basc_ADASScore_Get_C2_GetADASScore_In, param),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basc_ADASScore_Request_desc =
{
  .m_size = sizeof (carDrive_Basc_ADASScore_Request),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basc_ADASScore_Request",
  .m_keys = NULL,
  .m_nops = 23,
  .m_ops = carDrive_Basc_ADASScore_Request_ops,
  .m_meta = ""
};

static const uint32_t carDrive_Basc_ADASScore_Reply_ops [] =
{
  /* Basc_ADASScore_Reply */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_ADASScore_Reply, header), (3u << 16u) + 7u /* ReplyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_ADASScore_Reply, data), (3u << 16u) + 36u /* Basc_ADASScore_Return */,
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

  /* Basc_ADASScore_Return */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basc_ADASScore_Return, _d), 2u, (12u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 9 /* Basc_ADASScore_Get_C2_GetADASScore_Out */, 222040066, offsetof (carDrive_Basc_ADASScore_Return, _u.Get_C2_GetADASScore), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basc_ADASScore_Return, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* Basc_ADASScore_Get_C2_GetADASScore_Out */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_ADASScore_Get_C2_GetADASScore_Out, return_), (3u << 16u) + 4u /* C2_GetADASScore */,
  DDS_OP_RTS,

  /* C2_GetADASScore */
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (C2_GetADASScore, C2_UserIDnumber),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (C2_GetADASScore, C2_AutoDrivingScore),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2_GetADASScore, C2_IACCTrip),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2_GetADASScore, C2_NIDHighspeedTrip),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2_GetADASScore, C2_NIDCityTrip),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basc_ADASScore_Reply_desc =
{
  .m_size = sizeof (carDrive_Basc_ADASScore_Reply),
  .m_align = sizeof (char *),
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basc_ADASScore_Reply",
  .m_keys = NULL,
  .m_nops = 29,
  .m_ops = carDrive_Basc_ADASScore_Reply_ops,
  .m_meta = ""
};
