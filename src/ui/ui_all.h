#ifndef UI_ALL_H
#define UI_ALL_H

#include "main/main.h"
#include "generic_menu/menu.h"
#include "generic_input/input.h"
#include <Arduino.h>
#include "../config/config.h"
#include "../network/utils/ipvalidator.h"
#include "../network/wifi/wifi.h"

#include "conmenu/conmenu.h"
#include <map>

//0: Main, 1:ConMenu, 11:ConMenu-SelectInterface, 21:ConMenu-WifiSettings, 31:ConMenu-NetworkID

struct screen_co {
    lv_obj_t* screen_obj;
    void (*keydown_handle)(uint8_t key);
    void (*refresh_handle_t0)(UI_GenericMenu* menu);
    void (*refresh_handle_t1)(ui_main_ui_entry* ui_main);
    void (*refresh_handle_t2)(UI_GenericInput* input);
    unsigned int type;
    void refresh();
    void* ui_obj_ptr;
};

void refresh_screen();
void init_builders();

#endif