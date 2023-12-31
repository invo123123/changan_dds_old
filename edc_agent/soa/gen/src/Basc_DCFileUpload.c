/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_DCFileUpload.c
  Source: Basc_DCFileUpload.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#include "Basc_DCFileUpload.h"

#include "dds/dds.h"
#include "dds/ddsrt/sync.h"
#include <string.h>

static const uint32_t carCabin_Basc_DCFileUpload_Request_ops [] =
{
  /* Basc_DCFileUpload_Request */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_DCFileUpload_Request, header), (3u << 16u) + 7u /* RequestHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_DCFileUpload_Request, data), (3u << 16u) + 36u /* Basc_DCFileUpload_Call */,
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

  /* Basc_DCFileUpload_Call */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carCabin_Basc_DCFileUpload_Call, _d), 2u, (12u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 9 /* Basc_DCFileUpload_Ntf_UploadFile_In */, 183959553, offsetof (carCabin_Basc_DCFileUpload_Call, _u.Ntf_UploadFile), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carCabin_Basc_DCFileUpload_Call, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* Basc_DCFileUpload_Ntf_UploadFile_In */
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (carCabin_Basc_DCFileUpload_Ntf_UploadFile_In, taskId),
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (carCabin_Basc_DCFileUpload_Ntf_UploadFile_In, eventCode),
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (carCabin_Basc_DCFileUpload_Ntf_UploadFile_In, files),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carCabin_Basc_DCFileUpload_Request_desc =
{
  .m_size = sizeof (carCabin_Basc_DCFileUpload_Request),
  .m_align = sizeof (char *),
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carCabin::Basc_DCFileUpload_Request",
  .m_keys = NULL,
  .m_nops = 25,
  .m_ops = carCabin_Basc_DCFileUpload_Request_ops,
  .m_meta = ""
};

static const uint32_t carCabin_Basc_DCFileUpload_Reply_ops [] =
{
  /* Basc_DCFileUpload_Reply */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_DCFileUpload_Reply, header), (3u << 16u) + 7u /* ReplyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_DCFileUpload_Reply, data), (3u << 16u) + 36u /* Basc_DCFileUpload_Return */,
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

  /* Basc_DCFileUpload_Return */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carCabin_Basc_DCFileUpload_Return, _d), 2u, (12u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 9 /* Basc_DCFileUpload_Ntf_UploadFile_Out */, 183959553, offsetof (carCabin_Basc_DCFileUpload_Return, _u.Ntf_UploadFile), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carCabin_Basc_DCFileUpload_Return, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* Basc_DCFileUpload_Ntf_UploadFile_Out */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_DCFileUpload_Ntf_UploadFile_Out, return_), (3u << 16u) + 4u /* ReturnCode */,
  DDS_OP_RTS,

  /* ReturnCode */
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ReturnCode, code),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carCabin_Basc_DCFileUpload_Reply_desc =
{
  .m_size = sizeof (carCabin_Basc_DCFileUpload_Reply),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION | DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "carCabin::Basc_DCFileUpload_Reply",
  .m_keys = NULL,
  .m_nops = 25,
  .m_ops = carCabin_Basc_DCFileUpload_Reply_ops,
  .m_meta = ""
};

