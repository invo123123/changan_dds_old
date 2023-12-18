#include "Config.h"
#include <fstream>

bool CConfig::Load(const char* lpFile) {
	json js;
	ifstream ifs(lpFile);
	if (!ifs) {
		printf("CConfig::Load ifstream %s failed\n", lpFile);
		return false;
	}

	try {
		ifs >> js;
		m_config = js.get<config>();
	}
	catch (nlohmann::detail::exception& ex) {
		printf("CConfig::Load catch nlohmann exception %s\n", ex.what());
		return false;
	}
	catch (...) {
		printf("CConfig::Load catch undefined exception\n");
		return false;
		
	}

	return true; 
}

const config& CConfig::GetConfig() {
	return (const config&)m_config;
}    






