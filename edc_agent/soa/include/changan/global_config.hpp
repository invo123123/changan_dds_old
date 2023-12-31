/****************************************************************
  Generated by ChangAn Code Generator,Do Not Modify
  Generate Time: 2023-12-11 18:07:59
*****************************************************************/
#ifndef GLOBAL_CONFIG_HPP
#define GLOBAL_CONFIG_HPP
#include <string>

const constexpr size_t DDS_DOMAIN_ID = 0;
const constexpr size_t VIU_DDS_DOMAIN_ID = 0;

const constexpr size_t DEFAULT_TIMEOUT = 5000; // milliseconds

const constexpr size_t DEFAULT_SERVER_THREAD_NUM = 4;

const constexpr size_t DEFAULT_CLIENT_THREAD_NUM = 4;

const constexpr size_t CHAR_SIZE = sizeof(char);


#define  DDSDATA_MSG_HASH        1234567


#define  C2_MCU  "c2_mcu"
#define  VIU_MCU "viu_mcu"

/******************rpc  token*********************/
#define  MPU_TOKEN_NAME  "PROXY_TOKEN"    /*mpu*/
#define  MPU_CHECK_TOKEN "PROXY_TOKEN"

#define  MCU_TOKEN_NAME  "DIRECT_MCU_TOKEN"  /*viu*/
#define  MCU_CHECK_TOKEN "LOCAL_MCU_TOKEN,DIRECT_MCU_TOKEN"


#define MAX_USERDATA_LEN   1024
#define MAX_TOPICDATA_LEN  1024



#define RPC_SERVER_PARTITIONS       "rpc"
#define RPC_CLIENT_PARTITIONS       "*rpc"
#define NOTIFY_SENDER_PARTITIONS    "*ntf"
#define NOTIFY_RECEIVER_PARTITIONS  "ntf"

//const uint8_t client_service_id_array[1024] = {0};
//const uint8_t server_service_id_array[1024] = {0};
//#define   CLIENT_SERVICE_ID_ARRAY_MAX  (sizeof(client_service_id_array)/sizeof(uint8_t))
//#define   SERVER_SERVICE_ID_ARRAY_MAX  (sizeof(server_service_id_array)/sizeof(uint8_t))

#endif // !GLOBAL_CONFIG_HPP

