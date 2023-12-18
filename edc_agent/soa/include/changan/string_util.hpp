#ifndef CHANGAN_STRING_UTIL_HPP
#define CHANGAN_STRING_UTIL_HPP
#include <string.h>
#include <malloc.h>
#include "global_config.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>
class StringUtil
{
private:
	/* data */
public:
	static void string_copy(char*& dst,const char* src);
	static void string_array_copy(char* dst[], char* const src[], size_t len);
	static std::string uint8_to_hex_string(const uint8_t *input, const size_t datasize);
};

#endif