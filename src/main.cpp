#include <Arduino.h>
#include "pin_defs_dev.h"
#include <lvgl.h>
#include <TFT_eSPI.h>  // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include "screen/screen_port.h"
#include "ui/ui_all.h"

//High bit -> Low bit
//ROW0COL0(2^11) ROW0COL1 ROW0COL2
//...
//ROW3COL0 ROW3COL1 ROW3COL2(2^0)
unsigned int keys_last = 0, keys_now = 0, newly_pressed = 0, newly_released = 0;

//0: Main, 1:ConMenu, 11:ConMenu-SelectInterface, 21:ConMenu-WifiSettings, 31:ConMenu-NetworkID
unsigned int screen = 0;

const int key_rows[] = {KEY_R0_PIN, KEY_R1_PIN, KEY_R2_PIN, KEY_R3_PIN};
const int key_cols[] = {KEY_C0_PIN, KEY_C1_PIN, KEY_C2_PIN};

unsigned long millisec = 0;

ui_main_ui_entry *ui_main;

void my_printf(lv_log_level_t level, const char *file) {
    Serial.printf("level:%d, %s\n", level, file);
}
void setup() {
    Serial.begin(115200);
    lv_log_register_print_cb(my_printf);
    setup_screen();
    ui_main = setup_ui_main_screen();
    lv_screen_load(ui_main->objs->scr);
}

void loop() {
    ui_main->handleUpdate();
    lv_task_handler();
    delay(5);
}

void scanAllKeys() {
    keys_now = 0;
    for (int i = 0; i < 4; i++) {
        digitalWrite(key_rows[i], HIGH);
        for (int j = 0; j < 3; j++) {
            keys_now = keys_now << 1;
            keys_now |= digitalRead(key_cols[j]);
        }
        digitalWrite(key_rows[i], LOW);
    }
    newly_pressed = (keys_now ^ keys_last) & keys_now;
    newly_released = (keys_now ^ keys_last) & keys_last;
}