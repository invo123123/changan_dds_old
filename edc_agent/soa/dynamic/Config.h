#pragma once
#include "json.hpp"
#include <set>

using namespace std;
using json = nlohmann::json;

//#define viu_rpc_server_enable 

//#define  SOA_PROXY    //锟斤拷VIU通锟斤拷锟斤拷锟斤拷转锟斤拷 / 直锟斤拷
#define  VIU_NTF    //使锟斤拷锟斤拷VIU通讯锟斤拷NTF锟侥凤拷锟斤拷  (默锟较诧拷使锟斤拷)

typedef struct event {
	int32_t hash_id;
	string topic_desc;
} event;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(event, hash_id, topic_desc);

typedef struct events_clien_server {
	map<string, event>			 client;
	map<string, event>			 server;
} event_clien_server;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(events_clien_server, client, server);



typedef struct skeleton {
	string request_topic_name;
	string reply_topic_name;
	string request_topic_desc;
	string reply_topic_desc;
	set<int32_t> hash_ids;
} skeleton;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(skeleton, request_topic_name, reply_topic_name, request_topic_desc, reply_topic_desc, hash_ids);




typedef struct _c2_mcu_event {
	int32_t domainID;
	string topic_name;
	set<int32_t> hash_ids;
	string topic_desc;
} _c2_mcu_event;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(_c2_mcu_event, domainID, topic_name, hash_ids, topic_desc);


typedef struct _viu_mcu_event {
	string topic_name;
	set<int32_t> hash_ids;
	string topic_desc;
} _viu_mcu_event;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(_viu_mcu_event,topic_name, hash_ids, topic_desc);



typedef struct _viu_mcu_events {
	int32_t domainID;
	_viu_mcu_event viu_fl;
	_viu_mcu_event viu_fr;
	_viu_mcu_event viu_r;
} _viu_mcu_events;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(_viu_mcu_events, domainID, viu_fl, viu_fr, viu_r);



// typedef struct _viu_mcu_skeletons {
// 	skeleton viu_fl;
// 	skeleton viu_fr;
// 	skeleton viu_r;
// } _viu_mcu_skeletons;
// NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(_viu_mcu_skeletons, viu_fl, viu_fr, viu_r);



typedef struct mcu_events {
	_c2_mcu_event    c2_mcu;
	_viu_mcu_events  viu_mcu;
} mcu_events;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE( mcu_events, c2_mcu , viu_mcu);



typedef struct mcu_skeletons {
	map<string, skeleton>   viu_mcu;
} mcu_skeletons;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE( mcu_skeletons,viu_mcu);



typedef struct mcu_events_clien_server {
	mcu_events      client;
	mcu_events      server;
} mcu_events_clien_server;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(mcu_events_clien_server, client, server);



#ifdef viu_rpc_server_enable
typedef struct mcu_skeletons_clien_server {
	mcu_skeletons      client;
	mcu_skeletons      server;
} mcu_skeletons_clien_server;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(mcu_skeletons_clien_server, client,server);
#else
typedef struct mcu_skeletons_clien_server {
	mcu_skeletons      client;
	//mcu_skeletons      server;
} mcu_skeletons_clien_server;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(mcu_skeletons_clien_server, client);
#endif



typedef struct rpc_clien_server {
	map<string, skeleton>      client;
	map<string, skeleton>      server;
} rpc_clien_server;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(rpc_clien_server, client, server);



typedef struct config {
	events_clien_server			  events;
	mcu_events_clien_server       mcu_events;
	rpc_clien_server		      skeletons;
	mcu_skeletons_clien_server    mcu_skeletons;
} config;
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(config, events, mcu_events,skeletons,mcu_skeletons);



class CConfig {
public:
	bool Load(const char* lpFile);
	const config& GetConfig();

private:
	config m_config;
};



