#include "dds_node.h"
#include <iostream>

#define EDC_AGENT_VERSION  "V1.2.0"
#define SIGNAL_MAP_TABLE_VERSION "V1.7.0"
#define SOA_CONFIG_VERSION "R11"
int main(int, char **)
{
  DDSNode node("EDC_Agent");
  std::cout << "EDC_Agent Version "<< EDC_AGENT_VERSION << " Signal Map Table Version " << SIGNAL_MAP_TABLE_VERSION << " SOA Config Version" << SOA_CONFIG_VERSION << std::endl;
  if (!node.startWork())
  {
    std::cout << "***************StartWork error!***************" << std::endl;
  }
  node.Loop();

  return 0;
}