#pragma once
#include "dds/dds.h"
#include <string>
#include <unordered_map>

using namespace std;

extern unordered_map<string, dds_topic_descriptor_t> topic_Desc_Map;
extern unordered_map<int32_t, uint32_t> request_Header_RequestId_Map;
extern unordered_map<int32_t, uint32_t> request_Header_SequenceNumber_Map;
extern unordered_map<int32_t, uint32_t> request_Data_Unknown_Map;
extern unordered_map<string, uint32_t> request_Data_D_Map;
extern unordered_map<string, uint32_t> reply_Data_D_Map;
extern unordered_map<int32_t, uint32_t> reply_Header_Low_Map;
extern unordered_map<int32_t, uint32_t> reply_Header_RemoteEx_Map;
extern unordered_map<int32_t, uint32_t> reply_Header_RequestId_Map;
extern unordered_map<int32_t, uint32_t> reply_Header_Unknown_Map;
extern unordered_map<string, uint32_t> event_Data_D_Map;
extern unordered_map<string, uint32_t> event_Data_U_Map;


const dds_topic_descriptor_t* GetDesc(const string& topic_name);

//uint32_t GetOfs_McuEventData();
uint32_t GetOfs_McuEventData_d(const dds_topic_descriptor_t* desc);
uint32_t GetOfs_McuEventData_u(const dds_topic_descriptor_t* desc);
//uint32_t GetOfs_McuEventData_uUnknownOp();

uint32_t GetOfs_RpcRequestHeaderRequestId(int32_t hashid);
uint32_t GetOfs_RpcRequestHeaderRequestIdSequenceNumber(int32_t hashid);
uint32_t GetOfs_RpcRequestData_uUnknownOp(int32_t hashid);
uint32_t GetOfs_RpcRequestData_d(const dds_topic_descriptor_t* desc);

uint32_t GetOfs_RpcReplyData_d(const dds_topic_descriptor_t* desc);
uint32_t GetOfs_RpcReplyHeaderLow(int32_t hashid);
uint32_t GetOfs_RpcReplyHeaderRemoteEx(int32_t hashid);
uint32_t GetOfs_RpcReplyHeaderRelatedRequestId(int32_t hashid);
uint32_t GetOfs_RpcReplyData_uUnknownOp(int32_t hashid);