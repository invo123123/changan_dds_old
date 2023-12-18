#include "changan/string_util.hpp"

void StringUtil::string_copy(char*& dst,const char* src) {
	if (!src) {
		return;
	}
	dst = (char*)malloc(CHAR_SIZE * (strlen(src) + 1));
	strcpy(dst, src);
}

void StringUtil::string_array_copy(char* dst[], char* const src[], size_t len) {
	for (size_t i = 0; i < len; ++i) {
		if (!src[i]) {
			continue;
		}
		dst[i] = (char*)malloc(CHAR_SIZE * (strlen(src[i]) + 1));
		strcpy(dst[i], src[i]);
	}
}

std::string StringUtil::uint8_to_hex_string(const uint8_t *input, const size_t datasize) {
	std::ostringstream ret;
	for (size_t i = 0; i < datasize; ++i)
		ret << std::hex << std::setfill('0') << std::setw(2) << std::nouppercase
			<< (int)input[i];
	return ret.str();
}