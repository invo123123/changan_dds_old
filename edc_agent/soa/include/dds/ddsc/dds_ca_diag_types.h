#ifndef __DDS_CA_DIAG_TYPED_H__
#define __DDS_CA_DIAG_TYPED_H__

#if defined (__cplusplus)
#define restrict
#endif
#include <stdint.h>
#include <sys/queue.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>

#include "dds/dds.h"
#include "dds/ddsi/q_entity.h"
#include "dds/ddsi/q_addrset.h"
//#include "dds__domain.h"

#if defined (__cplusplus)
extern "C" {
#endif
#define DDS_PROC_NAME_LEN               (64)
#define DDS_XML_LEN                     (10240)
#define DDS_ENTITY_XML_DATA_LEN         (1024)
#define DDS_RECV_THREADS_LEN            (6)      /**< may be 2 dom in one process */
#define DDS_RECV_THREADS_NAME_LEN       (32)
#define DDS_ENTITY_GUID_CHAR_LEN        (64)

#define PACKET_DELAY_AREA_MAX_COUNT     (10)

#define DDS_DIAG_RCV_BUF_MAX            (8192)
#define DDS_DIAG_SND_BUF_MAX            (8192)    /**< max length of socket send buffer */
#define DD_DIAG_SUBMSG_LEN_MAX          (DDS_DIAG_SND_BUF_MAX-sizeof(DDSDiagProtoHeader_t))
#define DDS_DIAG_SUBMSG_LEN_MAX         (0xffff)    /**< max length of diag protocal data */
#define DDS_PROTO_HEADER_LEN            (sizeof(DDSDiagProtoHeader_t)) 
#define DDS_PROTO_BUFF_LEN              (DDS_DIAG_SUBMSG_LEN_MAX+sizeof(DDSDiagProto_t)) 
#define DDS_VERSION_LEN                 (16)

#define DDS_DOMAIN_NUM_MAX              (4)

#define DDS_MAX_PPT_NUM_PER_DOM         (10)
#define DDS_MAX_RD_NUM_PER_PPT          (256)
#define DDS_MAX_WR_NUM_PER_PPT          (10)

#define MAX_CHILDREN_NUM                (1024)

#define DDS_TOPIC_NAME_LEN_MAX          (64)
#define DDS_TOPIC_TYPE_LEN_MAX          (64)
#define DDS_RECVING_DELAY_AREA_NUM      (3)
#define DDS_RECVING_DELAY_COUNT_NUM     (4)

#define DDS_FILE_PATH_MAX               (256)
#define DDS_XML_FILE_LEN_MAX            (500*1024)

#define DDS_COMMIT_ID_LEN               (64)
#define DDS_COMPILE_TIME_LEN            (64)
#define DDS_DOMAIN_LOG_PATH_NUM         (3)
#define DDS_LOG_PATH_LEN                (128)
#define DDS_RECV_THREAD_NUM             (3)
#define DDS_RECV_THREAD_NAME_LEN        (32)
#define DDS_PROXY_PARTICIPANT_NUM       (10)

#define DDS_USRDATA_LEN_MAX             (64)
#define DDS_SPDP_UNMACH_CNT_MAX         (10)
#define DDS_SEDP_UNMACH_CNT_MAX         (10)
#define DDS_INTERNAL_NAME_LEN_MAX       (64)
#define DDS_PARTITION_NAME_LEN_MAX      (16)

#define DDS_DIAG_UNMATCH_PPT_MAX        (100)
#define DDS_DIAG_UNMATCH_READER_MAX     (512)
#define DDS_DIAG_UNMATCH_WRITER_MAX     (512)
#define SOCK_PATH_LEN_MAX               (256u)
#define DDS_DIAG_CAPTURE_FILE_LEN       (128)

#define SWAP_UINT32(x) ((x & 0x000000ff) << 24) | ((x & 0x0000ff00) << 8) | ((x & 0x00ff0000) >> 8) | ((x & 0xff000000) >> 24)
#define SWAP_UINT16(x) ((((uint16_t)x) >> 8) | ((((uint16_t)x) << 8)))

enum enProtocolId
{
    enProtocolId_Start = 0,
    enProtocolId_ProcessInfo = 0x01,
    enProtocolId_XmlData = 0x02,
    enProtocolId_EntityXmlData = 0x03,
    enProtocolId_DomainEntities = 0x04,
    enProtocolId_OpenDdsLog = 0x05,
    enProtocolId_SetCountPacketHash = 0x06,
    enProtocolId_MonitorServiceMethodData = 0x07,
    enProtocolId_ServiceMethodData = 0x08,
    enProtocolId_ReceivingDelay = 0x09,
    enProtocolId_DdsGatewayInfo = 0x0A,
    enProtocolId_UnmachInfo = 0x0B,
	  enProtocolId_OperatorFlowStatistics = 0x0C,
    enProtocolId_DiagnoseSwitch = 0x0D,
    enProtocolId_PacketCapture = 0x0E,
    enProtocolId_Max,
};

typedef struct RecvThreadsInfo
{
    uint32_t thread_id;
    char thread_name[DDS_RECV_THREADS_NAME_LEN];
    uint64_t recv_packet_count;
    uint64_t recv_msg_bytes;
    uint64_t recv_buffer_bytes;
}RecvThreadsInfo_t;

typedef struct DomainRecvThreadsInfo
{
    uint32_t domain_id;                                          // domain id
    uint8_t recv_thread_count;                                   // recv thread count
    RecvThreadsInfo_t recv_threads_infos[DDS_RECV_THREAD_NUM];   // recv thread infos
}DomainRecvThreadsInfo_t;

// proto header
typedef struct DDSDiagProtoHeader
{  
    uint16_t data_frag;     /**< mark if the packet is split */
    uint32_t data_len;      /**< length of the returned protocal data */
    uint32_t pkg_indx;      /**< index of the split packet */
} DDSDiagProtoHeader_t;

typedef struct DDSDiagSubMsgHeader
{  
    uint16_t proto_id;      /**< indicate which protocal */
    uint32_t submsg_len;    /**< length of the submsg */
} DDSDiagSubMsgHeader_t;

typedef struct ThreadInfo
{
    uint32_t thread_id;
    char thread_name[DDS_RECV_THREAD_NAME_LEN];
    uint64_t recv_msg_bytes;
    uint64_t recv_buffer_bytes;
}RecvThreadInfo_t;

typedef struct DomainLogPath
{
  uint32_t domain_id;
  char log_path[DDS_LOG_PATH_LEN];
} DomainLogPath_t;

typedef struct ProcessInfo 
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint64_t time_stamp;
  uint32_t pid;
  char dds_version[DDS_VERSION_LEN];
  char proc_name[DDS_PROC_NAME_LEN];
  uint32_t identity_ip;
  char commit_id[DDS_COMMIT_ID_LEN];
  char compile_time[DDS_COMPILE_TIME_LEN];
  uint8_t domain_num;
  DomainRecvThreadsInfo_t domainRecvThreads[DDS_DOMAIN_NUM_MAX];
  uint8_t log_path_num;
  DomainLogPath_t log_path[DDS_DOMAIN_LOG_PATH_NUM];
}ProcessInfo_t;

typedef struct XmlInfo 
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  char xml_path[DDS_FILE_PATH_MAX];
  char xml_sting[DDS_XML_FILE_LEN_MAX];
}XmlInfo_t;

typedef struct CADiagnose_guid_prefix
{
  uint8_t s[12];
  uint32_t u[3];
} CADiagnose_guid_prefix_t;

typedef struct CADiagnose_entityid
{
  uint32_t u;
} CADiagnose_entityid_t;

// dds entity guid
typedef struct CADiagnose_guid
{
  CADiagnose_guid_prefix_t prefix;
  CADiagnose_entityid_t entityid;
} CADiagnose_guid_t;

typedef struct CADiagnose_net_info
{
  int32_t ip_num;
  uint8_t ip_addr[4][16];
  uint32_t port[4];
} CADiagnose_net_info_t;

typedef struct ca_dds_sequence_octet
{
  uint32_t _length;
  uint8_t *_buffer;
} ca_dds_sequence_octet_t;

typedef enum CADiagEntityType
{
  CADiagEntityType_DOM = 0X01,
  CADiagEntityType_PPT = 0X02,
  CADiagEntityType_RD = 0X03,
  CADiagEntityType_WR = 0X04,

  CADiagEntityType_PROXY_PPT = 0X05,
  CADiagEntityType_MATCHED_RD = 0X06,
  CADiagEntityType_MATCHED_WR = 0X07,
  CADiagEntityType_MAX
}CADiagEntityType_e;

typedef enum CADiagUnmatchType
{
  CADiagUnmatchType_SPDP = 0X01,
  CADiagUnmatchType_Writer = 0X02,
  CADiagUnmatchType_Reader = 0X03,
  CADiagUnmatchType_MAX,
}CADiagUnmatchType_e;

typedef struct CADiagnose_participant_info
{
  uint32_t domain_id;
  CADiagnose_guid_t pp_guid;
  ddsi_locator_t m_locator;
  char proc_name[DDS_PROC_NAME_LEN];
  char usrdata[DDS_USRDATA_LEN_MAX];
  uint32_t pid;
} CADiagnose_participant_info_t;

typedef struct CADiagnose_proxy_participant_info
{
  uint32_t domain_id;
  CADiagnose_guid_t pp_guid;
  CADiagnose_guid_t proxy_pp_guid;
  ddsi_locator_t m_locator;
  char proc_name[DDS_PROC_NAME_LEN];
  uint32_t pid;
  uint64_t spdp_time;
} CADiagnose_proxy_participant_info_t;

typedef struct CADiagnose_matched_rd_info
{
  CADiagnose_proxy_participant_info_t ppt_info;
  CADiagnose_guid_t wr_guid;
  CADiagnose_guid_t rd_guid;

  char topic_name[DDS_TOPIC_NAME_LEN_MAX];
  char topic_type[DDS_TOPIC_TYPE_LEN_MAX];
  uint64_t sedp_time;
} CADiagnose_matched_rd_info_t;

typedef struct CADiagnose_matched_wr_info
{
  CADiagnose_proxy_participant_info_t ppt_info;
  CADiagnose_guid_t rd_guid;
  CADiagnose_guid_t wr_guid;
  char topic_name[DDS_TOPIC_NAME_LEN_MAX];
  char topic_type[DDS_TOPIC_TYPE_LEN_MAX];
  uint64_t sedp_time;
} CADiagnose_matched_wr_info_t;

typedef struct CADiagnose_writer_info
{
  CADiagnose_participant_info_t ppt_info;
  CADiagnose_guid_t wr_guid;
  uint8_t reliable;

  uint64_t last_seq_number;
  uint64_t last_real_seq_num;
  uint32_t recv_ack_num;
  uint32_t recv_nack_num;

  char topic_name[DDS_TOPIC_NAME_LEN_MAX];
  char topic_type[DDS_TOPIC_TYPE_LEN_MAX];
  char partition[DDS_PARTITION_NAME_LEN_MAX];

  uint32_t matched_readers_num;
} CADiagnose_writer_info_t;

typedef struct CADiagnose_reader_info
{
  CADiagnose_participant_info_t ppt_info;
  CADiagnose_guid_t rd_guid;
  uint8_t reliable;

  char topic_name[DDS_TOPIC_NAME_LEN_MAX];
  char topic_type[DDS_TOPIC_TYPE_LEN_MAX];

  char partition[DDS_PARTITION_NAME_LEN_MAX];

  uint32_t recv_data_num;
  uint32_t make_sample_err_st;
  uint32_t sample_reject_err_st;

  uint32_t matched_writers_num;
} CADiagnose_reader_info_t;

typedef struct CADomainInfo_impl
{
  uint8_t domain_num;
  uint32_t dom_id[DDS_DOMAIN_NUM_MAX];
}CADomainInfo_impl_t;

typedef struct CADomainInfo
{
  uint8_t domain_num;
  uint8_t domain_id[DDS_DOMAIN_NUM_MAX];
}CADomainInfo_t;

typedef struct CADiagEntity_info
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  CADiagEntityType_e type;
  union 
  {
    CADomainInfo_t  dom_info;
    CADiagnose_participant_info_t  ppt_info;
    CADiagnose_reader_info_t reader_info;
    CADiagnose_writer_info_t writer_info;
    
    CADiagnose_proxy_participant_info_t proxy_ppt_info;
    CADiagnose_matched_rd_info_t matched_reader_info;
    CADiagnose_matched_wr_info_t matched_writer_info;
  }u;
}CADiagEntity_info_t;

typedef struct LogSnd 
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint32_t domain_id;
  uint32_t mask;
  uint8_t result;
}LogSnd_t;

typedef struct LogRcv 
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint32_t domain_id;
  uint32_t mask;
}LogRcv_t;

typedef struct CADomainInfosClient
{    
  int32_t domain_id;
  char participant_guid[DDS_ENTITY_GUID_CHAR_LEN];
  char writer_guid[DDS_ENTITY_GUID_CHAR_LEN];
  char reader_guid[DDS_ENTITY_GUID_CHAR_LEN];
  char topic_name[DDS_TOPIC_NAME_LEN_MAX];
}CADomainInfosClient_t;

typedef struct DDSDiagProto
{  
  DDSDiagProtoHeader_t proto_hdr;
  int8_t proto_data[];    /**< buffer must be malloc, usually we malloc DDS_DIAG_DATA_LEN_MAX*/
} DDSDiagProto_t;

// proto id 0x05 enProtocolId_OpenDdsLog
// client log open op

typedef struct st_log_open_op 
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint32_t domain_id;
  uint32_t log_mask;
}LogOpenOp;

// server log open result
typedef struct st_log_open_op_result
{
	DDSDiagSubMsgHeader_t smsg_hdr;
	uint32_t domain_id;
	uint32_t log_mask;
	int8_t result;
}LogOpenOpResult;

// proto id 0x06 enProtocolId_SetCountPacketHash
typedef struct st_set_count_packet_hash_client
{
  DDSDiagSubMsgHeader_t smsg_hdr;	
  uint8_t op;
  uint32_t hash_id;
}SetCountPacketHashClient;

typedef struct st_set_count_packet_hash_server
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint8_t op;
  uint32_t hash_id;
  int8_t result;
}SetCountPacketHashServer;

// proto id 0x07 enProtocolId_MonitorServiceMethodData
typedef struct st_monitor_service_method_data_client
{
  uint32_t hash_id;
}MonitorServiceMethodDataClient;

typedef struct st_monitor_server_method_data_server
{
  uint32_t hash_id;
  int8_t result;
}MonitorServerMethodDataServer;

// proto id 0x08 enProtocolId_ServiceMethodData
typedef struct st_service_method_data_server
{
  uint32_t hash_id;
  uint16_t data_len;
  char* data;
}ServiceMethodDataServer;

// entity xml info 0x03 protocol
typedef struct EntityXmlInfoClient
{
  uint32_t host_id;
  uint32_t app_id;
  uint32_t instance_id;
  uint32_t entity_id;
}EntityXmlInfoClient_t;

typedef struct EntityXmlInfoServer
{
  uint32_t host_id;
  uint32_t app_id;
  uint32_t instance_id;
  uint32_t entity_id;
  char xml_data[DDS_ENTITY_XML_DATA_LEN];
}EntityXmlInfoServer_t;

// proto id 0x09 enProtocolId_PacketDelayAreaCount
typedef struct st_packet_delay_area_client
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint8_t op;
  char diag_topicname[DDS_TOPIC_NAME_LEN_MAX];
  uint32_t area[3];
}PacketDelayAreaClient;

typedef struct st_packet_delay_area_server
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint8_t op;
  char diag_topicname[DDS_TOPIC_NAME_LEN_MAX];
  uint32_t area[3];  
  uint32_t recv_delay_statistics[DDS_RECVING_DELAY_COUNT_NUM];
  int8_t result;
}PacketDelayAreaServer;
// proto id 0x0A 
typedef struct DdsGatewayInfo
{

}DdsGatewayInfo_t;

typedef struct CaDiagUnmachSpdpInfo
{
  uint8_t unmatch_reason;
  uint32_t domain_id;
  CADiagnose_guid_t participant_guid;
  CADiagnose_guid_t proxy_participant_guid;
  int8_t usrdata[DDS_USRDATA_LEN_MAX];
  char internals[DDS_INTERNAL_NAME_LEN_MAX];
  char proc_name[DDS_PROC_NAME_LEN];
  ddsi_locator_t m_locator;
  uint32_t pid;
}CaDiagUnmachSpdpInfo_t;

typedef struct CaDiagUnmachReaderInfo
{
  uint8_t unmatch_reason;
  CADiagnose_proxy_participant_info_t ppt_info;
  CADiagnose_guid_t rd_guid;

  char topic_name[DDS_TOPIC_NAME_LEN_MAX];

}CaDiagUnmachReaderInfo_t;

typedef struct CaDiagUnmachWriterInfo
{
  uint8_t unmatch_reason;
  CADiagnose_proxy_participant_info_t ppt_info;
  CADiagnose_guid_t wr_guid;

  char topic_name[DDS_TOPIC_NAME_LEN_MAX];

}CaDiagUnmachWriterInfo_t;

typedef struct CADiagUnmatch_info
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  CADiagUnmatchType_e type;
  union 
  {
    CaDiagUnmachSpdpInfo_t  unmatch_participant_info;
    CaDiagUnmachReaderInfo_t  unmatch_reader_info;
    CaDiagUnmachWriterInfo_t  unmatch_writer_info;
  }u;
}CADiagUnmatch_info_t;

/* structure for tail queue link */
typedef struct CADiagUnmatch_infoElement
{
	STAILQ_ENTRY(CADiagUnmatch_infoElement) link;
	CADiagUnmatch_info_t unmatch_info;
}CADiagUnmatch_infoElement_t;

typedef struct DDSDiagEntity
{  
    bool            configured;                     /**< flag of if ca diag inited */
    ddsrt_mutex_t   m_unmatch_spdp_mutex;           /**< mutex used for unmatched spdp info */
    ddsrt_mutex_t   m_unmatch_sedp_mutex;           /**< mutex used for unmatched sedp info */
    uint32_t      unmatch_participant_num;
    uint32_t      unmatch_reader_num;
    uint32_t      unmatch_writer_num;
    STAILQ_HEAD(, CADiagUnmatch_infoElement) unmached_participants;
    STAILQ_HEAD(, CADiagUnmatch_infoElement) unmached_readers;
    STAILQ_HEAD(, CADiagUnmatch_infoElement) unmached_writers;
    char            sock_path[SOCK_PATH_LEN_MAX];   /**< unix socket path */
    ddsrt_socket_t  sock_fd;                        /**< socket file descriptor */
    struct sockaddr_un cli_sock_addr;
    socklen_t cli_sock_len;
    uint32_t        max_packet_len;
    ddsrt_pid_t     pid;                            /**< process id */
    char            proc_name[DDSRT_PROC_NAME_LEN]; /**< process name */
    ddsrt_thread_t  thread_id;                      /**< thread name */
    void            *thread_arg;                    /**< argument for the thread */
    ddsrt_threadattr_t thread_attr;                 /**< thread attr */
    uint8_t         diag_switch;                    /**< switch to open or close diagnose */
}DDSDiagEntity_t;

// proto id 0x0C enProtocolId_OperatorFlowStatistics
typedef struct st_operator_flow_statistics_client
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint8_t operator;
}OperatorFlowStatisticsClient_t;

typedef struct st_operator_flow_statistics_server
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  int64_t sending_flow;
  int64_t receiving_flow;
  uint64_t duration;
  uint8_t operator;
  int8_t result;
}OperatorFlowStatisticsServer_t;


// proto id 0x0D
typedef struct st_diag_set_switch_client
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint8_t operator;
}CaDiagSetSwitchClient_t;

typedef struct st_diag_set_swicth_server
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  uint8_t operator;
  int8_t result;
}CaDiagSetSwitchServer_t;

// proto enProtocolId_PacketCapture = 0x0E
typedef struct st_diag_packet_capture_client
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  char capture_file_path[DDS_DIAG_CAPTURE_FILE_LEN];
  uint32_t capture_line;
  uint32_t capture_timeout;   // in mill seconds
}CaDiagPacketCaptureClient_t; 

typedef struct st_diag_packet_capture_server
{
  DDSDiagSubMsgHeader_t smsg_hdr;
  int8_t result;
}CaDiagPacketCaptureServer_t; 

#endif

