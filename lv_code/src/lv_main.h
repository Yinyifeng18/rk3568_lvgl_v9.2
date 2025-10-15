/**
 * @file lv_modbus_tool.h
 * This file exists only to be compatible with Arduino's library structure
 */

#ifndef LV_MAIN_H
#define LV_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "../lv_code.h"


/*********************
 *      DEFINES
 *********************/

/*
 *  注意，这里要与 lv_conf.h 中 LV_FS_STDIO_LETTER 或 LV_FS_POSIX_LETTER 指定的盘符一致
 *  示例(Windows)： 假设 LETTER 设置为 'D'，之后路径可 "D:/100ask/"
 *  示例(Linux)：   直接设置 LETTER 设置为 'A'，之后路径可为 "A:/mnt/"
 */
#define ASSETS_PATH  "A:/userdata/aidemo/xiaozhi_linux_rk3568/xiaozhi/"   // 图片路径

#define PATH_PREFIX  "A:/userdata/aidemo/xiaozhi_linux_rk3568/xiaozhi/"    // 字体路径



/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

void lv_main(void);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LV_MAIN_H */
