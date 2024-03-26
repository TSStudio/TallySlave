#ifndef _SCREEN_PORT_H_
#define _SCREEN_PORT_H_
#include <lvgl.h>
#include <TFT_eSPI.h>  // Graphics and font library for ST7735 driver chip

#define screenWidth_ (uint16_t)160
#define screenHeight_ (uint16_t)128

void setup_screen();

void my_flush_cb(lv_display_t* display, const lv_area_t* area, uint8_t* px_map);

#endif