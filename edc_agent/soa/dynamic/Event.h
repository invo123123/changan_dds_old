#pragma once
#include "Dynamic.h"
#include <vector>
#include "struct_protobuf_convert.hpp" 

//typedef void (*on_notify) (void* event);

typedef std::function<void(int32_t, void*,int32_t)> on_notify;

/***********************************CEventSuber**********************************/
class CEventSuber : public CEventDynamic<CEventSuber> {
public:
	static void Init(std::string config="");
	static void Recv(int32_t hashId, on_notify on);

private:
	static void OnEventDataAvailable(int32_t reader, void* arg);

private:
	static map<string, on_notify> m_notifys;
};
/***********************************CEventPuber**********************************/
class CEventPuber :public CEventDynamic<CEventPuber>  {
public:
	static void Init(std::string config="");
	static void Send(int32_t hashId, void* data,int32_t datasize);
	static void Send_idlc(int32_t hashId, void* data,int32_t datasize);
};
/***********************************CMcuEventSuber**********************************/
class CMcuEventSuber :public CMcuEventDynamic<CMcuEventSuber>  {
public:
	static void Init(std::string config="");
	static void Recv(int32_t hashId, on_notify on);

private:
	static bool dds_topic_filter (const void *vsample, void *arg);
	static bool topic_filter_special_callback (const void * serdata_sample);

	static void OnEventDataAvailable(int32_t reader, void* arg);
	static void Init_wtich_mcu( string &topicName,string mcu,std::string config="" ) ;

private:
	static map<int32_t, on_notify> m_notifys;

};
/***********************************CMcuEventPuber**********************************/
class CMcuEventPuber :public CMcuEventDynamic<CMcuEventPuber> {
public:
	static void Init(std::string config="");
	static void Send(int32_t hashId, void* data,int32_t datasize);
	static void Send_idlc(int32_t hashId, void* data,int32_t datasize);

private:	
	static void Init_wtich_mcu(string topicName,string mcu,std::string config="" ) ;

};