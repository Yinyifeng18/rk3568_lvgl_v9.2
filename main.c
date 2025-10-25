#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "lv_code/lv_code.h"
#include "lv_code/src/lv_main.h"


// 添加必要的宏定义（请根据实际屏幕尺寸调整）
#define MY_DISP_HOR_RES    1280
#define MY_DISP_VER_RES    720
#define BYTE_PER_PIXEL     4  // ARGB8888



static pthread_mutex_t lvgl_mutex;
static const char *getenv_default(const char *name, const char *dflt)
{
    return getenv(name) ? : dflt;
}

#if LV_USE_LINUX_FBDEV
static void lv_linux_disp_init(void)
{
    const char *device = getenv_default("LV_LINUX_FBDEV_DEVICE", "/dev/fb0");
    lv_display_t * disp = lv_linux_fbdev_create();

    lv_linux_fbdev_set_file(disp, device);

    static uint8_t buf_2_1[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
    static uint8_t buf_2_2[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];

    lv_display_set_buffers(disp, buf_2_1, buf_2_2, sizeof(buf_2_1), LV_DISPLAY_RENDER_MODE_PARTIAL);
 
    lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);
}
#elif LV_USE_LINUX_DRM
static void lv_linux_disp_init(void)
{
    const char *device = getenv_default("LV_LINUX_DRM_CARD", "/dev/dri/card0");
    lv_display_t * disp = lv_linux_drm_create();

    lv_linux_drm_set_file(disp, device, -1);
}
#elif LV_USE_SDL
static void lv_linux_disp_init(void)
{
    const int width = atoi(getenv("LV_SDL_VIDEO_WIDTH") ? : "800");
    const int height = atoi(getenv("LV_SDL_VIDEO_HEIGHT") ? : "480");

    lv_sdl_window_create(width, height);
}
#else
#error Unsupported configuration
#endif

void lvgl_lock(void)
{
    pthread_mutex_lock(&lvgl_mutex);
}

void lvgl_unlock(void)
{
    pthread_mutex_unlock(&lvgl_mutex);
}

// 自定义触摸处理函数，适配硬件顺时针旋转但LVGL按逆时针处理的情况


int main(void)
{
    pthread_mutex_init(&lvgl_mutex, NULL);
    lv_init();

    /*Linux display device init*/
    lv_linux_disp_init();

    /*Create a Demo*/
    //lv_demo_widgets();
    // lv_demo_widgets_start_slideshow();

    // 创建自定义触摸输入设备
     lv_indev_t *indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event2");

 
    //lv_main();
    lv_demo_widgets();

    /*Handle LVGL tasks*/
    while(1) 
    {
        lvgl_lock();
        lv_timer_handler();
        lvgl_unlock();
        usleep(5000);
    }

    return 0;
}
