/**@file      LogIf.h
* @brief      LogIf模块头文件
* @details    主要用于LogIf模块的全局变量定义、全局函数声明、宏定义、数据类型定义等
* @author     fengyu  202104396
* @date       2021-9-26
* @version    V1.0
* @copyright  Copyright (c) 2021 重庆长安汽车软件科技有限公司δ研究所控制软件平台室
**********************************************************************************
* @attention
* 硬件平台：  \n
* SDK版本： 
* @par 修改日志:
* <table>
* <tr><th>Date        <th>Version  <th>Author   <th>EmployeeID   <th>Description
* <tr><td>2021/09/26  <td>1.0      <td>fengyu   <td>202104396    <td>创建初始版本
* </table>
*
**********************************************************************************
*/
#ifndef _LOGIF_H_
#define _LOGIF_H_

#include "LogPrintf.h"

/*The user includes declaration*/


/*********************************************************************************
 *  GLOBAL CONSTANT MACROS(数据宏定义)
 ********************************************************************************/


/*********************************************************************************
 *  GLOBAL FUNCTION MACROS(函数宏定义)
 ********************************************************************************/


/*********************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES(变量类型定义)
 ********************************************************************************/

/*Enum data type define*/

typedef enum
{
	LogIf_SUCCESS = 0,   /*!< 0上报成功 */
	LogIf_FAILED,    /*!< 1上报失败 */
	LogIf_Others    /*!< 2其他错误 */
}LogIfUserDataTypeEnum;  /*!< 用户描述 */
/*Union data type define*/

typedef union
{
	struct
	{
		uint32 reserved0:28; /*!< bit: 0..27 Reserved */
		uint32 userbit0:1; /*!< bit: 28 用户描述 */
		uint32 userbit1:1; /*!< bit: 29 用户描述 */
		uint32 userbit2:1; /*!< bit: 30 用户描述 */
		uint32 userbit3:1; /*!< bit: 31 用户描述 */
	} B; /*!< Structure used for bit access */
	uint32 W; /*!< Type used for word access */
}LogIfUserDataTypeUnion;  /*!< 用户描述 */
/*Struct data type define*/

typedef struct
{
	LogIfUserDataTypeUnion UserData0;
	uint32 UserData1;
}LogIfUserDataTypeStruct;  /*!< 用户描述 */
/*typedef data type define*/

typedef  LogIfUserDataTypeStruct  LogIfUserDataTypeStruct_T;  /*!< 用户描述 */
/*********************************************************************************
 *  GLOBAL DATA PROTOTYPES
 ********************************************************************************/

extern LogIfUserDataTypeStruct gLogIfMyNum; /*!< 用户描述 */
/*********************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 ********************************************************************************/

/*The init function defination*/

extern void LogIf_Init(void);
/*To do the user function defination start*/
extern FUNC(void, XCP_CODE) LogIf_RxIndication
(
    PduIdType LogRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, XCP_APPL_CONST)PduInfoPtr
);
LogIfUserDataTypeEnum LogIf_UserFunction(uint8 para0, LogIfUserDataTypeStruct para1);
/* To do the user function defination end */
/*The main function defination*/

extern void LogIf_MainFunction(void);

#endif /* LOGIF_H */
/*********************************************************************************
  END OF FILE: LogIf.h
*********************************************************************************/
