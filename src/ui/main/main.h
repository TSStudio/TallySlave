#ifndef _UI_MAIN_H_
#define _UI_MAIN_H_
#include <lvgl.h>
#include <cstdio>
struct ui_main_objs {
    lv_obj_t *scr, *label_Voltage, *label_SignaldBm, *label_SignalType, *label_CurrentDeviceID, *label_PreviewDeviceID, *label_PreviewDeviceText, *label_ProgramDeviceID, *label_ProgramDeviceText, *label_currentState, *label_wifi;
    lv_style_t *style_currentID, *style_wifi;
};
struct ui_main_args {
    float voltage;
    char* current_device_id;
    char* preview_device_id;
    char* program_device_id;
    int signaldBm;
    int signalType;   //0: CAN, 1: WiFi, 2:LoRa
    int signalState;  //(WiFi Only)0: Not connected, 1: Connected But No Server 2: Connected And Server
    int state;        //0: None, 1: Preview, 2: Program
    void init();
    char* getSignalTypeString();
    lv_color_t getSignalTypeColor();
};

struct ui_main_ui_entry {
    ui_main_args* args;
    ui_main_args* lastdrew_args;
    ui_main_objs* objs;
    void handleUpdate();
};

void ui_main_handle_update(ui_main_ui_entry* ui_entry);
ui_main_ui_entry* setup_ui_main_screen();

#endif