#include <Arduino.h>
#include "pin_defs_dev.h"
#include <lvgl.h>
#include <TFT_eSPI.h>  // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include "screen/screen_port.h"
#include "ui/ui_all.h"
#include "network/wifi/wifi.h"

//High bit -> Low bit
//ROW0COL0(2^11) ROW0COL1 ROW0COL2
//...
//ROW3COL0 ROW3COL1 ROW3COL2(2^0)
unsigned int keys_last = 0, keys_now = 0, newly_pressed = 0, newly_released = 0;

unsigned int current_screen = 9999999;
unsigned int screen = 0;
unsigned int targeted_frame_time_us = 1000000 / 60;
unsigned int last_refresh_time_us = 0;

std::map<unsigned int, screen_co> screens;

const int key_rows[] = {KEY_R0_PIN, KEY_R1_PIN, KEY_R2_PIN, KEY_R3_PIN};
const int key_cols[] = {KEY_C0_PIN, KEY_C1_PIN, KEY_C2_PIN};

unsigned long cycle = 0;

ui_main_ui_entry *ui_main;

UI_GenericMenu ui_conmenu;

void my_printf(lv_log_level_t level, const char *file) {
    Serial.printf("level:%d, %s\n", level, file);
}
void setup() {
    Serial.begin(115200);
    lv_log_register_print_cb(my_printf);
    setup_screen();

    initWifiInstance("307", "306306306306", "192.168.5.9");

    static screen_co screen_main, screen_conmenu;

    ui_main = setup_ui_main_screen();
    screen_main.screen_obj = ui_main->objs->scr;
    screen_main.refresh_handle_t0 = NULL;
    screen_main.refresh_handle_t1 = ui_main_handle_update;
    screen_main.type = 1;
    screen_main.ui_obj_ptr = ui_main;
    screens[0] = screen_main;

    ui_conmenu = setup_ui_conmenu_screen(screen);
    screen_conmenu.screen_obj = ui_conmenu.scr;
    screen_conmenu.refresh_handle_t0 = ui_generic_menu_handle_update;
    screen_conmenu.refresh_handle_t1 = NULL;
    screen_conmenu.type = 0;
    screen_conmenu.ui_obj_ptr = &ui_conmenu;
    screens[1] = screen_conmenu;
}

void loop() {
    if (cycle % 300 == 0) {
        doWifiStuff(ui_main->args->signaldBm, ui_main->args->preview_device_id, ui_main->args->program_device_id, ui_main->args->signalState);
        if (strcmp(ui_main->args->program_device_id, ui_main->args->current_device_id) == 0) {
            ui_main->args->state = 2;
        } else if (strcmp(ui_main->args->preview_device_id, ui_main->args->current_device_id) == 0) {
            ui_main->args->state = 1;
        } else {
            ui_main->args->state = 0;
        }
        //ui_conmenu.selected = (ui_conmenu.selected + 1) % ui_conmenu.selection_count;
    }
    if (cycle % 5000 == 0) {
        //screen = !screen;
    }
    if (micros() < last_refresh_time_us || micros() - last_refresh_time_us >= targeted_frame_time_us) {
        if (micros() > last_refresh_time_us && micros() - last_refresh_time_us >= 10 * targeted_frame_time_us) {
            Serial.printf("Frame time exceeded: %d\n", micros() - last_refresh_time_us);
        }
        last_refresh_time_us = micros();
        refresh_screen();
    } else {
        delay(1);
    }
    cycle++;
}