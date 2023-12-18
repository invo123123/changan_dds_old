#ifndef DDS_NODE_H
#define DDS_NODE_H

#include "zros/core/node.h"
#include "zros/core/transport.h"
#include "zros/base/process_info.h"
//#include "zros/nif_live_msg/consumer.h"
#include "zros/live_msgs/live_msg_framework.h"
#include "zros/live_msg_transport/live_msg_transport.h"
#include "dynamic/Config.h"
#include "rpc_types.h"
#include "edc_timer.h"
#include "log.h"

class DDSNode : public zros::core::Node
{
public:
  DDSNode(std::string name = zros::base::GetProcessName());
  virtual ~DDSNode();

  bool OnInit() override;
  void OnExit() override;

  bool startWork();

private:
  template <typename T>
  void publish(const T &msgStruct, const std::string &topicName)
  {
    if (m_pubTopicMap.find(topicName) != m_pubTopicMap.end())
    {
      typename zros::core::Publisher<T>::SharedPtr pubPtr =
          std::static_pointer_cast<zros::core::Publisher<T>>(m_pubTopicMap[topicName]);

      pubPtr->Publish(msgStruct);
    }
    else
    {
      typename zros::core::Publisher<T>::SharedPtr pubPtr =
          zros::core::Transport::Instance()->CreatePublisher<T>(topicName, zros::core::TOPIC_MESSAGE);
      ZASSERT(pubPtr);

      pubPtr->Publish(msgStruct);
      m_pubTopicMap.insert(std::make_pair(topicName, pubPtr));
    }
  }

  void process_dds2soc_event(int32_t hashID, void *buf, int32_t bufSize);
  void process_dds2mcu_event(int32_t hashID, void *buf, int32_t bufSize);
  void process_soc2dds_event(const std::string &topic, const zros::core::PlainBufMessage &msg);
  void process_mcu2dds_event(const std::string &topic, const zros::core::PlainBufMessage &msg);
  // 接收内部消息，dds转发到外部
  bool startWork_zm2dds_event(const config &mConfig);
  // 接收外部dds消息，转发给内部
  bool startWork_dds2zm_event(const config &mConfig);


  void process_soc2dds_rpc(const std::string &topic, const zros::core::PlainBufMessage &msg);
  void process_mcu2dds_rpc(const std::string &topic, const zros::core::PlainBufMessage &msg);
  void process_dds2soc_rpc(int32_t hash, void *request,size_t requestSize, void **reply,size_t &replySize,DDS_RPC_RemoteExceptionCode_t &errorCode);
  void process_dds2mcu_rpc(int32_t hash, void *request,size_t requestSize, void **reply,size_t &replySize,DDS_RPC_RemoteExceptionCode_t &errorCode);

  // 接收内部请求，dds转发到外部
  bool startWork_zm2dds_rpc(const config &mConfig);
  // 接收dds外部请求,转发给内部
  bool startWork_dds2zm_rpc(const config &mConfig);

  //void initLiveMsg();
  //void sendToMcu(int id, void *data, int len);
  //void sendToMcuWithTimestamp(int id, void *data, int len);


private:
  std::unordered_map<std::string, std::shared_ptr<void>> m_pubTopicMap;

  std::vector<zros::core::Subscriber<zros::core::PlainBufMessage>::SharedPtr> m_subscriberVec;

  std::vector<zros::core::Subscriber<zros::core::PlainBufMessage>::SharedPtr> m_live_msg_subscriberVec;

  size_t m_count {0};

  //zros::nif_live_msg::Consumer::SharedPtr m_liveMsgConsumer;

};







#endif // DDS_NODE_H