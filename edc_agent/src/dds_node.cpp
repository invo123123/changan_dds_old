#include "dds_node.h"
#include <thread>
#include "dynamic/Event.h"
#include "dynamic/Rpc.h"
#include "live_msg_oem_soc_to_mcu_Types.h"
#include "live_msg_cx_mcu_to_edc_agent_Types.h"
#include "zros/nif_live_msg/consumer.h"

static int32_t getHashIdFromMap(const std::map<string, event> &mmap, const std::string str)
{
  for (const auto &itmap : mmap)
  {
    if (itmap.first == str)
    {
      return itmap.second.hash_id;
    }
  }

  return 0;
}

static std::string getTopicFromMap(const std::map<string, event> &mmap, const int32_t hashId)
{
  for (const auto &itmap : mmap)
  {
    if (itmap.second.hash_id == hashId)
    {
      return itmap.first;
    }
  }

  return std::string();
}

DDSNode::DDSNode(std::string name) : Node(name)
{
}

DDSNode::~DDSNode()
{
}

bool DDSNode::OnInit()
{
  //initLiveMsg();
  return true;
}

void DDSNode::OnExit()
{
}

bool DDSNode::startWork()
{
  // 读取配置文件
  CConfig cfg;
  if (!cfg.Load("dc2.json"))
  {
    return false;
  }
  
  if (!startWork_zm2dds_rpc(cfg.GetConfig()))
  {
    return false;
  }
#if 1
  if (!startWork_dds2zm_rpc(cfg.GetConfig()))
  {
    return false;
  }

  if (!startWork_dds2zm_event(cfg.GetConfig()))
  {
    return false;
  }

  if (!startWork_zm2dds_event(cfg.GetConfig()))
  {
    return false;
  }
#endif
  return true;
}
/*
void DDSNode::initLiveMsg()
{
  m_liveMsgConsumer = zros::nif_live_msg::Consumer::make_shared();
  ZASSERT(m_liveMsgConsumer);

  m_liveMsgConsumer->RegisterOnError(
      [this](const zros::core::pb::ErrorStack &error_stack) {
        ZDEBUG << "Got error: " << error_stack.DebugString() << "\n";
        ReportError(error_stack);
      });

  m_liveMsgConsumer->RegistorOnConnectStatusChanged([this](bool connected) {
    if (connected)
    {
      m_liveMsgConsumer->StartProvider();
    }
    else
    {
      m_liveMsgConsumer->StopProvider();
    }
  });

  m_liveMsgConsumer->ConnectProvider();
}

void DDSNode::sendToMcu(int id, void *data, int len)
{
  if (nullptr == m_liveMsgConsumer)
  {
    return;
  }

  LIVE_MSG_DATA_SIZE_MAX msg_buffer;
  LIVE_MSG *msg = &msg_buffer.header;
  live_msg_init(msg, id, data, len);
  live_msg_set_target(msg, LIVE_MSG_TARGET_MCU);
  m_liveMsgConsumer->SendMsg(msg);
}

void DDSNode::sendToMcuWithTimestamp(int id, void *data, int len)
{
  if (nullptr == m_liveMsgConsumer)
  {
    return;
  }

  LIVE_MSG_DATA_SIZE64 msg_buffer;
  LIVE_MSG *msg = &msg_buffer.header;
  live_msg_init_with_timestamp(msg, id, data, len, zros::base::GetSyncedTime());
  live_msg_set_target(msg, LIVE_MSG_TARGET_MCU);
  m_liveMsgConsumer->SendMsg(msg);
}
*/

