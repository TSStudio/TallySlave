#include "screen_port.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

lv_display_t* display;

static uint16_t buf[screenWidth_ * screenHeight_ / 10];

void my_flush_cb(lv_display_t* display, const lv_area_t* area, uint8_t* px_map) {
    uint16_t* buf16 = (uint16_t*)px_map;
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t*)buf16, w * h, true);
    tft.endWrite();
    lv_disp_flush_ready(display);
}

void setup_screen(void) {
    tft.begin();
    tft.setRotation(1);
    lv_init();
    lv_tick_set_cb((unsigned int (*)())millis);
    display = lv_display_create(screenWidth_, screenHeight_);
    lv_display_set_flush_cb(display, my_flush_cb);
    lv_display_set_buffers(display, buf, NULL, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_resolution(display, screenWidth_, screenHeight_);
}