/**
 * @file lv_code.h
 *
 */

#ifndef LV_CODE_H
#define LV_CODE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

#if defined(LV_100ASK_DEMO_CONF_PATH)
#define __LV_TO_STR_AUX(x) #x
#define __LV_TO_STR(x) __LV_TO_STR_AUX(x)
#include __LV_TO_STR(LV_100ASK_DEMO_CONF_PATH)
#undef __LV_TO_STR_AUX
#undef __LV_TO_STR
#endif


/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if LV_VERSION_CHECK(9, 2, 0) == 0
#warning "lv_code: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_CODE_H*/
