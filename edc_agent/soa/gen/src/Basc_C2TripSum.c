/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_C2TripSum.c
  Source: Basc_C2TripSum.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#include "Basc_C2TripSum.h"

#include "dds/dds.h"
#include "dds/ddsrt/sync.h"
#include <string.h>

static const uint32_t carDrive_Basc_C2TripSum_Ntf_ops [] =
{
  /* Basc_C2TripSum_Ntf */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_C2TripSum_Ntf, header), (3u << 16u) + 7u /* NotifyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_C2TripSum_Ntf, data), (3u << 16u) + 33u /* Basc_C2TripSum_Ntf_Message */,
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

  /* Basc_C2TripSum_Ntf_Message */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basc_C2TripSum_Ntf_Message, _d), 2u, (12u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 9 /* C2TripSum */, 221609985, offsetof (carDrive_Basc_C2TripSum_Ntf_Message, _u.Basc_C2TripSum_C2TripSummary), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basc_C2TripSum_Ntf_Message, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* C2TripSum */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2TripSum, ADS_TotalMiles),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2TripSum, ADS_NIDMiles),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_SafeFunTriTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_AEBTriTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_AESTriTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_ELKTriTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_ThroughRampTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_ThroughIntersectionTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_LaneChangeTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_TakeoverTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_ObsAvoidTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (C2TripSum, ADS_NIDLongestMiles),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, APA_UseTime),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, APA_SaveTime),
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (C2TripSum, C2_UserIDnumber),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (C2TripSum, ADS_ADSUseTime),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basc_C2TripSum_Ntf_desc =
{
  .m_size = sizeof (carDrive_Basc_C2TripSum_Ntf),
  .m_align = sizeof (char *),
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basc_C2TripSum_Ntf",
  .m_keys = NULL,
  .m_nops = 37,
  .m_ops = carDrive_Basc_C2TripSum_Ntf_ops,
  .m_meta = ""
};

static const uint32_t carDrive_Basc_C2TripSum_Request_ops [] =
{
  /* Basc_C2TripSum_Request */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_C2TripSum_Request, header), (3u << 16u) + 7u /* RequestHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_C2TripSum_Request, data), (3u << 16u) + 36u /* Basc_C2TripSum_Call */,
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

  /* Basc_C2TripSum_Call */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basc_C2TripSum_Call, _d), 1u, (8u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basc_C2TripSum_Call, _u.unknownOp), 0u,
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basc_C2TripSum_Request_desc =
{
  .m_size = sizeof (carDrive_Basc_C2TripSum_Request),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basc_C2TripSum_Request",
  .m_keys = NULL,
  .m_nops = 21,
  .m_ops = carDrive_Basc_C2TripSum_Request_ops,
  .m_meta = ""
};

static const uint32_t carDrive_Basc_C2TripSum_Reply_ops [] =
{
  /* Basc_C2TripSum_Reply */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_C2TripSum_Reply, header), (3u << 16u) + 7u /* ReplyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carDrive_Basc_C2TripSum_Reply, data), (3u << 16u) + 36u /* Basc_C2TripSum_Return */,
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

  /* Basc_C2TripSum_Return */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carDrive_Basc_C2TripSum_Return, _d), 1u, (8u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carDrive_Basc_C2TripSum_Return, _u.unknownOp), 0u,
  DDS_OP_RTS
};

const dds_topic_descriptor_t carDrive_Basc_C2TripSum_Reply_desc =
{
  .m_size = sizeof (carDrive_Basc_C2TripSum_Reply),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION | DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "carDrive::Basc_C2TripSum_Reply",
  .m_keys = NULL,
  .m_nops = 21,
  .m_ops = carDrive_Basc_C2TripSum_Reply_ops,
  .m_meta = ""
};
