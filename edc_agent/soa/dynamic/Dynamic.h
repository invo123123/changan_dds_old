#pragma once
#include <map>
#include <string>
#include "Config.h"
#include "dds_util.h"

using namespace std;


template<typename T>
class CDynamic {
public:
	static void SetConfig(const config& config) {
		m_config = config;
	}

protected:
	static config m_config;

};
template<typename T> config CDynamic<T>::m_config;


template<typename T>
class CEventDynamic : public CDynamic<CEventDynamic<T>> {
protected:
	static map<string, dds_rpc_handle_t> m_drhs;
};

template<typename T> map<string, dds_rpc_handle_t> CEventDynamic<T>::m_drhs;   //event handle




template<typename T>
class CMcuEventDynamic : public CDynamic<CMcuEventDynamic<T>> {
protected:
	// static dds_rpc_handle_t c2_drh;
	// static dds_rpc_handle_t viu_drh;
	static map<string, dds_rpc_handle_t> c2_drh;
	static map<string, dds_rpc_handle_t> viu_drh;
};
template<typename T> map<string, dds_rpc_handle_t> CMcuEventDynamic<T>::c2_drh;   
template<typename T> map<string, dds_rpc_handle_t> CMcuEventDynamic<T>::viu_drh;  

// template<typename T> dds_rpc_handle_t CMcuEventDynamic<T>::c2_drh = { -1, -1, -1 };   //c2 MCU event handle
// template<typename T> dds_rpc_handle_t CMcuEventDynamic<T>::viu_drh = { -1, -1, -1 };   //viu MCU event handle

typedef struct rpc_param {
	
	dds_rpc_handle_t request;
	dds_rpc_handle_t reply;

	rpc_param() {
	 	request = { -1, -1, -1 };
	 	reply = { -1, -1, -1 };
	}
} rpc_param;

template<typename T>
class CRpcDynamic : public CDynamic<CRpcDynamic<T>> {
protected:
	static map<string, rpc_param> m_rps;
	static map<string, rpc_param> m_rps_viu;
};

template<typename T>  map<string, rpc_param> CRpcDynamic<T>::m_rps; //RPC handle
template<typename T>  map<string, rpc_param> CRpcDynamic<T>::m_rps_viu; //RPC handle



typedef struct ServiceInterface
{
	string serviceName;
	int32_t hashId;
} ServiceInterface;

typedef std::function<void(int32_t, void *,size_t, void**,size_t& ,DDS_RPC_RemoteExceptionCode_t &  )> HandleRequest;
