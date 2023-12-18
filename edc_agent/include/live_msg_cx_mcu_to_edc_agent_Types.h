/***************************************************************************
 *                                                                         *
 *       chongqing changa Technology Co. Ltd.                               *
 *                                                                         *
 *    Copyright (c) 2018 by chongqing changa Technology Co. Ltd.            *
 *    All rights reserved.                                                 *
 *                                                                         *
 *    This Software is protected by People's Republic of China copyright   *
 *    laws and international treaties.  You may not reverse engineer,      *
 *    decompile or disassemble this Software.                              *
 *                                                                         *
 *    WARNING:                                                             *
 *    This Software contains chongqing changa Technology Co. Ltd.'s         *
 *    confidential and proprietary information. UNAUTHORIZED COPYING,      *
 *    USE, DISTRIBUTION, PUBLICATION, TRANSFER, SALE, RENTAL OR DISCLOSURE *
 *    IS PROHIBITED AND MAY RESULT IN SERIOUS LEGAL CONSEQUENCES.  Do not  *
 *    copy this Software without chongqing changa Technology Co. Ltd.'s     *
 *    express written permission.   Use of any portion of the contents of  *
 *    this Software is subject to and restricted by your written agreement *
 *    with chongqing changa Technology Co. Ltd.                             *
 *                                                                         *
 ***************************************************************************/
#ifndef LIVE_MESSAGE_CX_TO_EDC_AGENT_TYPES_H_
#define LIVE_MESSAGE_CX_TO_EDC_AGENT_TYPES_H_

#define LIVE_MSG_CATEGORY_BITS  8
#define LIVE_MSG_CATEGORY_SHIFT (sizeof(unsigned short) * 8 - (LIVE_MSG_CATEGORY_BITS))
#define LIVE_MSG_CATEGORY_START(category)   ((category) <<  LIVE_MSG_CATEGORY_SHIFT)

#define LIVE_MSG_CATEGORY_CA_MCU_TO_EDC_AGENT 33

/*
  Define the CX specific live msg (mcu sned, soc receive) here.
  These msgs only be used by MCU and customized node (such as UI application).
  !!!!! DO NOT use these msg in any other modules !!!!
*/

#define MCU_TO_EDC_AGENT_ID_START       (0x10)

enum {
	LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START      = LIVE_MSG_CATEGORY_START(LIVE_MSG_CATEGORY_CA_MCU_TO_EDC_AGENT) + MCU_TO_EDC_AGENT_ID_START,
	LIVE_MSG_DDS_NTF_STATUS = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 1,
	LIVE_MSG_DDS_NTF_SMARTDRIVETIPS = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 2,
	LIVE_MSG_DDS_NTF_CONVOYFUN = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 3,
	LIVE_MSG_DDS_NTF_TRAFFICSIGN = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 4,
	LIVE_MSG_DDS_NTF_TRAFFICLIGHT = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 5,
	LIVE_MSG_DDS_NTF_C2_ADASSCORE = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 6,
	LIVE_MSG_DDS_C2TRIPSUMMARY = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 7,
	LIVE_MSG_DDS_NTF_AUTOTURNVIEW = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 8,
	LIVE_MSG_DDS_RR_TURNON = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 9,
	LIVE_MSG_DDS_RR_TURNOFF = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 10,
	LIVE_MSG_DDS_RR_COMBHDLAMPCTRL = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 11,
	LIVE_MSG_DDS_RR_WIPERCTRL = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 12,
	LIVE_MSG_DDS_NTF_ADASCRUISESET = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 13,
	LIVE_MSG_DDS_NTF_C2_IACCFAMLRRDMODSWTFB = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 14,
	LIVE_MSG_DDS_NTF_AD_NIDSELFLRNGFB = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 15,
	LIVE_MSG_DDS_NTF_AD_BSDLCAONOFFSET = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 16,
	LIVE_MSG_DDS_NTF_AD_SEAONOFFSTS = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 17,
	LIVE_MSG_DDS_NTF_ADASSECURESET = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 18,
	LIVE_MSG_DDS_NTF_AD_REDLIGHTREMINDENABLE = LIVE_MSG_CX_MCU_TO_EDC_AGENT_ID_START + 19
};


#endif  /* LIVE_MESSAGE_CX_TO_EDC_AGENT_TYPES_H_ */
