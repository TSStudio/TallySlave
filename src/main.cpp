#include <Arduino.h>
#include "pin_defs_dev.h"
#include <lvgl.h>
#include <TFT_eSPI.h>  // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include "screen/screen_port.h"
#include "ui/ui_all.h"
#include "network/wifi/wifi.h"
#include "config/config.h"
#include "keys/keys.h"

unsigned int current_screen = 9999999;
unsigned int screen = 0;
unsigned int targeted_frame_time_us = 1000000 / 60;
unsigned int last_refresh_time_us = 0;

std::map<unsigned int, screen_co> screens;

Configuration config;

unsigned long cycle0 = 0, cycle1 = 0;

ui_main_ui_entry* ui_main;

UI_GenericMenu ui_conmenu;

TaskHandle_t obstructIOsTaskHandle, nonObstructIOsTaskHandle;

void obstructIOs(void* parameter) {
    Serial.print("ObstructIO running on core ");
    Serial.println(xPortGetCoreID());
    for (;;) {
        if (cycle0 % 3000 == 0) {
            doWifiStuff(ui_main->args->signaldBm, ui_main->args->preview_device_id, ui_main->args->program_device_id, ui_main->args->signalState, config.networkID);
            if (strcmp(ui_main->args->program_device_id, ui_main->args->current_device_id) == 0) {
                digitalWrite(LED_R_PIN, HIGH);
                digitalWrite(LED_G_PIN, LOW);
                ui_main->args->state = 2;
            } else if (strcmp(ui_main->args->preview_device_id, ui_main->args->current_device_id) == 0) {
                digitalWrite(LED_R_PIN, LOW);
                digitalWrite(LED_G_PIN, HIGH);
                ui_main->args->state = 1;
            } else {
                digitalWrite(LED_R_PIN, LOW);
                digitalWrite(LED_G_PIN, LOW);
                ui_main->args->state = 0;
            }
            //ui_conmenu.selected = (ui_conmenu.selected + 1) % ui_conmenu.selection_count;
        }
        cycle0++;
    }
}

void nonObstructIOs(void* parameter) {
    Serial.print("nonObstructIO running on core ");
    Serial.println(xPortGetCoreID());
    for (;;) {
        if (micros() < last_refresh_time_us || micros() - last_refresh_time_us >= targeted_frame_time_us) {
            if (micros() > last_refresh_time_us && micros() - last_refresh_time_us >= 10 * targeted_frame_time_us) {
                Serial.printf("Frame time exceeded: %d\n", micros() - last_refresh_time_us);
            }
            last_refresh_time_us = micros();
            refresh_screen();
        }
        do_key_stuff();
    }
}

void setup() {
    Serial.begin(115200);
    EEPROM.begin(72);
    config.initFromEEPROM();

    setup_screen();
    setup_keys();

    initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);

    static screen_co screen_main, screen_conmenu;

    ui_main = setup_ui_main_screen();
    screen_main.screen_obj = ui_main->objs->scr;
    screen_main.refresh_handle_t0 = NULL;
    screen_main.refresh_handle_t1 = ui_main_handle_update;
    screen_main.type = 1;
    screen_main.ui_obj_ptr = ui_main;
    screens[0] = screen_main;

    free(ui_main->args->current_device_id);
    ui_main->args->current_device_id = config.deviceID;

    ui_conmenu = setup_ui_conmenu_screen(screen);
    screen_conmenu.screen_obj = ui_conmenu.scr;
    screen_conmenu.refresh_handle_t0 = ui_generic_menu_handle_update;
    screen_conmenu.refresh_handle_t1 = NULL;
    screen_conmenu.type = 0;
    screen_conmenu.ui_obj_ptr = &ui_conmenu;
    screens[1] = screen_conmenu;

    init_builders();

    xTaskCreatePinnedToCore(
        obstructIOs,
        "ObstructIO",
        20000,
        NULL,
        1,
        &obstructIOsTaskHandle,
        0);
    delay(100);
    xTaskCreatePinnedToCore(
        nonObstructIOs,
        "NonObstructIO",
        5000,
        NULL,
        1,
        &nonObstructIOsTaskHandle,
        1);
}

void loop() {}