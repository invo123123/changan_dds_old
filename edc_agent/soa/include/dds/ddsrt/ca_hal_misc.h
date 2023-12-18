/**@file  hal_misc.h
 * * @brief       MISC接口抽象头文件
 * * @details     MISC接口抽象API定义
 * * @author      zhangtao 
 * * @date        2022-10-24
 * * @version     V1.0
 * * @copyright    Copyright (c) 2018-2021  长安软件科技有限公司
 * */
#ifndef __HAL_MISC__
#define __HAL_MISC__
#ifdef __cplusplus
extern "C"
{
#endif

enum {
	HAL_CHIP_VISION_MASTER = 0,
	HAL_CHIP_VISION_SLAVE,
	HAL_CHIP_FUSION,
};
    
typedef enum HAL_BOARD_TYPE{
     HAL_BOARD_DOUBLE = 0,  /*双orin*/
     HAL_BOARD_SINGLE_A = 1, /*单orin A样板*/
     HAL_BOARD_SINGLE_B = 2, /*单orin B样板*/
     HAL_BOARD_MAX,
}HAL_ORINBOARD_TYPE_E;


int  Hal_GetBoardType(int *pOrinType);

int Hal_GetChipDevId();

/** @defgroup MISC接口抽象APIs
 * @{
 */

/**
 * @brief  获取时间接口
 * 
 * @param[in]  timestamp    时间戳
 * @note
 * @return 执行结果
 * @retval 返回时间
 */
int Hal_GetTsnTimeStampUs(unsigned long *timestamp);
#ifdef __cplusplus
}
#endif
#endif

/**@}*/
