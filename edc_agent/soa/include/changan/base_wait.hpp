#ifndef BASE_WAIT_HPP
#define BASE_WAIT_HPP
#include "global_config.hpp"
#include "changan/common_data_types.h"
#include "Common.h"
#include "changan/dds_util.h"
class IBaseWait {
public:
void wait_for_pub_online(dds_entity_t writer){
	    uint32_t status = 0;
	    printf("=== [Publisher]  Waiting for a reader to be discovered ...\n");
	    fflush (stdout);
//		printf("@@@@@@@@@@writer = %d\n",writer);
	    dds_return_t rc = dds_set_status_mask(writer, DDS_PUBLICATION_MATCHED_STATUS);
	    if (rc != DDS_RETCODE_OK)
	    DDS_FATAL("dds_set_status_mask: %s\n", dds_strretcode(-rc));

	    while(!(status & DDS_PUBLICATION_MATCHED_STATUS))
	    {
            rc = dds_get_status_changes (writer, &status);
            if (rc != DDS_RETCODE_OK)
            DDS_FATAL("dds_get_status_changes: %s\n", dds_strretcode(-rc));

           
            dds_sleepfor (DDS_MSECS (20));
	    }
	}

	 void wait_for_sub_online(dds_entity_t reader){
	    uint32_t status = 0;
	    printf("=== [Publisher]  Waiting for a reader to be discovered ...\n");
	    fflush (stdout);
//		printf("@@@@@@@@@@@@@@@@writer = %d\n",reader);
	    dds_return_t rc = dds_set_status_mask(reader, DDS_SUBSCRIPTION_MATCHED_STATUS);
	    if (rc != DDS_RETCODE_OK)
	    DDS_FATAL("dds_set_status_mask: %s\n", dds_strretcode(-rc));

	    while(!(status & DDS_SUBSCRIPTION_MATCHED_STATUS))
	    {
            rc = dds_get_status_changes (reader, &status);
            if (rc != DDS_RETCODE_OK)
            DDS_FATAL("dds_get_status_changes: %s\n", dds_strretcode(-rc));

            
            dds_sleepfor (DDS_MSECS (20));
	    }
	}
	
private:
};

#endif 
