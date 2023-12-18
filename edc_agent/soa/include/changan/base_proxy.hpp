#ifndef BASE_PROXY_HPP
#define BASE_PROXY_HPP
#include "global_config.hpp"
class IBaseProxy {
public:
	virtual const std::string get_service_name()=0;
	virtual bool init(std::string config) = 0;
private:
};

#endif // !BASE_SERVICE_HPP
