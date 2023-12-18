#ifndef BASE_SKLETON_HPP
#define BASE_SKLETON_HPP
#include "global_config.hpp"
class IBaseSkeleton {
public:
	virtual const std::string get_service_name()=0;
	virtual bool init() = 0;
private:

};
#endif // !BASE_SERVICE_HPP
