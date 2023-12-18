#pragma once
#include "cmqos.h"
#include <string>

qos_params* get_qos_params(string topic_name);
void release_all_qos_params();