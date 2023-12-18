/****************************************************************

  Generated by Autocore DDS IDL to C Translator
  File name: Basc_AdasInfo.c
  Source: Basc_AdasInfo.idl
  AutoCore DDS: V1.6.5

*****************************************************************/
#include "Basc_AdasInfo.h"

#include "dds/dds.h"
#include "dds/ddsrt/sync.h"
#include <string.h>

static const uint32_t carCabin_Basc_AdasInfo_Ntf_ops [] =
{
  /* Basc_AdasInfo_Ntf */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_AdasInfo_Ntf, header), (3u << 16u) + 7u /* NotifyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_AdasInfo_Ntf, data), (3u << 16u) + 33u /* Basc_AdasInfo_Ntf_Message */,
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

  /* Basc_AdasInfo_Ntf_Message */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carCabin_Basc_AdasInfo_Ntf_Message, _d), 4u, (20u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 17 /* ADAS_MapCommonSignal */, 180060161, offsetof (carCabin_Basc_AdasInfo_Ntf_Message, _u.Basc_AdasInfo_Ntf_ADAS_MapCommonSignal), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 26 /* ADAS_MapNavigationSignal */, 180060162, offsetof (carCabin_Basc_AdasInfo_Ntf_Message, _u.Basc_AdasInfo_Ntf_ADAS_MapNavigationSignal), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_STU | 181 /* ADAS_MapTrafficSign */, 180060163, offsetof (carCabin_Basc_AdasInfo_Ntf_Message, _u.Basc_AdasInfo_Ntf_AdasMapTrafficSign), 0u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carCabin_Basc_AdasInfo_Ntf_Message, _u.unknownOp), 0u,
  DDS_OP_RTS,

  /* ADAS_MapCommonSignal */
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapCommonSignal, MapDataUpdateStatus),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapCommonSignal, NavStatus),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapCommonSignal, NavGuiganceStatus),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapCommonSignal, MapMatchStatus),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapCommonSignal, NavCountryCode),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapCommonSignal, NavSpeedLimitUnits),
  DDS_OP_RTS,

  /* ADAS_MapNavigationSignal */
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, CurveDistance),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, EnterCurveInfo),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RampDistance),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, EnterRampInfo),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, RampInfo),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, RampSide),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, NavCurrentRoadType),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, ForwardRoadType),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, LaneCnt),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, NavSpeedLimitType),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, NavSpeedLimit),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SpeedLimitDistance),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, EnterTunnelInfo),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, TunnelDistance),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, TunnelLength),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, EnterSlopeInfo),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeDistance),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, FallingRockInfo),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, FallingRockDis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, TollInfo),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, TollDis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, Construction_Info),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, Construction_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, TrafficAccident_Info),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, TrafficAccident_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, BranchInfo),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, Branch_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, NumchangeOfLanes_Dist),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, Lane_Changtype),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, Road_TrafficFlow),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_10m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_20m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_30m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_40m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_50m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_60m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_70m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_80m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_90m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_100m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvatureFar),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_300m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_400m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, RoadCurvature_600m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradient),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradientFar),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradient_300m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradient_10m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradient_20m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradient_30m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradient_40m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradient_50m),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, SlopeGradient_100m),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, IntervalVelocityInfo),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, IntervalVelocityDis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, AccidentProne),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, AccidentProneDistance),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, LaneConfluence),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, LaneConfluenceDis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, BridgeInfo),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, BridgeDis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, WeatherType),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, ServiceRoad),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, ServiceRoadDis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, LaneType_ID1),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, LaneType_ID2),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, LaneType_ID3),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, LaneType_ID4),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, LaneType_ID5),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, LaneType_ID6),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, EHRHeartFlag),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, EHPHeartFlag),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, ADAS_Posn_Pathldx),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, ADAS_Posn_Offset),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, Byroad),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, Long_Ramp_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapNavigationSignal, Long_Ramp_Side),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapNavigationSignal, Llong_Tunnel_Len),
  DDS_OP_RTS,

  /* ADAS_MapTrafficSign */
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Warning_ReverseCurve),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Warning_ContinuousDetours),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Warning_Pedestrian),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Warning_Slip),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Warning_Tunnel),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Warning_Slow),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Warning_RoadWorks),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_DriveInto),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_MotorVehicles),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_TurnRight),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Straight),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Uturn),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Overtake),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_VehicleParking),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_VehParkLongTime),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_SpeedLimit),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_StopToGiveWay),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Enter),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Honking),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Prohibitory_GiveWayToOncoming),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Indication_OneWay),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Indication_Walk),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Indication_MainRoadPriority),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Indication_PedestrianCrossing),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (ADAS_MapTrafficSign, Indication_BusLane),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Warning_ReverseCurve_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Warning_ContinuousDetours_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Warning_Pedestrian_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Warning_Slip_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Warning_Tunnel_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Warning_Slow_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Warning_RoadWorks_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_DriveInto_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_MotorVehicles_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_TurnRight_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Straight_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Uturn_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Overtake_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_VehPark_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_VehParkLongT_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_SpeedLimit_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_StopToGiveWay_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Enter_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_Honking_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Prohibitory_GiveWayOncom_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Indication_OneWay_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Indication_Walk_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Indication_MainRoadPri_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Indication_PedestrianCro_Dis),
  DDS_OP_ADR | DDS_OP_TYPE_2BY, offsetof (ADAS_MapTrafficSign, Indication_BusLane_Dis),
  DDS_OP_RTS
};

const dds_topic_descriptor_t carCabin_Basc_AdasInfo_Ntf_desc =
{
  .m_size = sizeof (carCabin_Basc_AdasInfo_Ntf),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION | DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "carCabin::Basc_AdasInfo_Ntf",
  .m_keys = NULL,
  .m_nops = 158,
  .m_ops = carCabin_Basc_AdasInfo_Ntf_ops,
  .m_meta = ""
};

static const uint32_t carCabin_Basc_AdasInfo_Request_ops [] =
{
  /* Basc_AdasInfo_Request */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_AdasInfo_Request, header), (3u << 16u) + 7u /* RequestHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_AdasInfo_Request, data), (3u << 16u) + 36u /* Basc_AdasInfo_Call */,
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

  /* Basc_AdasInfo_Call */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carCabin_Basc_AdasInfo_Call, _d), 1u, (8u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carCabin_Basc_AdasInfo_Call, _u.unknownOp), 0u,
  DDS_OP_RTS
};

const dds_topic_descriptor_t carCabin_Basc_AdasInfo_Request_desc =
{
  .m_size = sizeof (carCabin_Basc_AdasInfo_Request),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION,
  .m_nkeys = 0u,
  .m_typename = "carCabin::Basc_AdasInfo_Request",
  .m_keys = NULL,
  .m_nops = 21,
  .m_ops = carCabin_Basc_AdasInfo_Request_ops,
  .m_meta = ""
};

static const uint32_t carCabin_Basc_AdasInfo_Reply_ops [] =
{
  /* Basc_AdasInfo_Reply */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_AdasInfo_Reply, header), (3u << 16u) + 7u /* ReplyHeader */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (carCabin_Basc_AdasInfo_Reply, data), (3u << 16u) + 36u /* Basc_AdasInfo_Return */,
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

  /* Basc_AdasInfo_Return */
  DDS_OP_ADR | DDS_OP_FLAG_MU | DDS_OP_TYPE_UNI | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_DEF | DDS_OP_FLAG_SGN, offsetof (carCabin_Basc_AdasInfo_Return, _d), 1u, (8u << 16u) + 4u,
  DDS_OP_JEQ4 | DDS_OP_TYPE_1BY, 0, offsetof (carCabin_Basc_AdasInfo_Return, _u.unknownOp), 0u,
  DDS_OP_RTS
};

const dds_topic_descriptor_t carCabin_Basc_AdasInfo_Reply_desc =
{
  .m_size = sizeof (carCabin_Basc_AdasInfo_Reply),
  .m_align = 4u,
  .m_flagset = DDS_TOPIC_NO_OPTIMIZE | DDS_TOPIC_CONTAINS_UNION | DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "carCabin::Basc_AdasInfo_Reply",
  .m_keys = NULL,
  .m_nops = 21,
  .m_ops = carCabin_Basc_AdasInfo_Reply_ops,
  .m_meta = ""
};
