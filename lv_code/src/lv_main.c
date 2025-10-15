
/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

#include "lv_main.h"

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/



/**********************
 *  STATIC PROTOTYPES
 **********************/
static void init_freetype(void);
static void deinit_freetype(void);

static void init_style(void);


/**********************
 *  STATIC VARIABLES
 **********************/

static lv_style_t g_style_chat_font;
static lv_style_t g_style_state_font;

static lv_font_t * gp_chat_font_freetype;
static lv_font_t * gp_state_font_freetype;

extern void lvgl_lock(void);

extern void lvgl_unlock(void);

/**********************
 *      MACROS
 **********************/


/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_main(void)
{
    /* init */
    lv_fs_stdio_init();	

    init_freetype();
    init_style();

   
}


/**********************
 *   STATIC FUNCTIONS
 **********************/
static void lv_main_deinit(void)
{
    deinit_freetype();

    lv_deinit();
}



static void init_freetype(void)
{
    /*Create a font*/
    gp_chat_font_freetype = lv_freetype_font_create(PATH_PREFIX "HarmonyOS_Sans_SC_Regular.ttf",
                                                    LV_FREETYPE_FONT_RENDER_MODE_BITMAP,
                                                    26,
                                                    LV_FREETYPE_FONT_STYLE_NORMAL);
                                                    
    gp_state_font_freetype = lv_freetype_font_create(PATH_PREFIX "HarmonyOS_Sans_SC_Regular.ttf",
                                                    LV_FREETYPE_FONT_RENDER_MODE_BITMAP,
                                                    20,
                                                    LV_FREETYPE_FONT_STYLE_NORMAL);

    if((!gp_chat_font_freetype) || (!gp_state_font_freetype)) {
        LV_LOG_ERROR("freetype font create failed.");
        exit(-1);
    }
}

static void deinit_freetype(void)
{
    lv_freetype_font_delete(gp_chat_font_freetype);
    lv_freetype_font_delete(gp_state_font_freetype);
}


static void init_style(void)
{
    /*Create style with the new font*/;
    lv_style_init(&g_style_chat_font);
    lv_style_set_text_font(&g_style_chat_font, gp_chat_font_freetype);
    lv_style_set_text_align(&g_style_chat_font, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&g_style_state_font);
    lv_style_set_text_font(&g_style_state_font, gp_state_font_freetype);
    lv_style_set_text_align(&g_style_state_font, LV_TEXT_ALIGN_CENTER);
}




