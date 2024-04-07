#include "ui_all.h"

//0: Main, 1:ConMenu, 11:ConMenu-SelectInterface, 12:ConMenu-WifiSettings, 13:ConMenu-NetworkID

extern unsigned int current_screen;
extern unsigned int screen;
extern std::map<unsigned int, screen_co> screens;
std::map<unsigned int, void (*)()> screen_builders;
extern Configuration config;

void screen_co::refresh() {
    if (type == 0) {
        refresh_handle_t0((UI_GenericMenu*)ui_obj_ptr);
    } else if (type == 1) {
        refresh_handle_t1((ui_main_ui_entry*)ui_obj_ptr);
    } else if (type == 2) {
        refresh_handle_t2((UI_GenericInput*)ui_obj_ptr);
    }
}

void refresh_screen() {
    if (current_screen != screen) {
        Serial.printf("Changing screen to %d\n", screen);
        //check if screen is already built
        if (screens.find(screen) == screens.end()) {
            Serial.println("No screen found, going back");
            screen = current_screen;
            return;
        } else {
            Serial.println("Screen already built");
        }
        lv_screen_load(screens[screen].screen_obj);
        current_screen = screen;
    }
    screens[screen].refresh();
    lv_task_handler();
}

void init_builders() {
    //screen_builders[i]=[]{};
    // Ya need to provide a lambda function here
    // and finally push screen_co to screens
    screen_builders[12] = [] {
        Serial.println("Building screen 12");
        static char title[] = "Wifi Settings";
        static char selection1[] = "1";
        static char selection2[] = "2";
        static char selection3[] = "3";
        UI_GenericMenu_Selection* selections = GM_make_selections(3, GM_make_selection(selection1), GM_make_selection(selection2), GM_make_selection(selection3));
        static UI_GenericMenu menu = GM_make_menu(title, 1, screen, selections, 3);

        static screen_co screen_common;
        screen_common.screen_obj = menu.scr;
        screen_common.refresh_handle_t0 = ui_generic_menu_handle_update;
        screen_common.type = 0;
        screen_common.ui_obj_ptr = &menu;
        screens[12] = screen_common;
        Serial.println("Screen 12 built");
    };
    screen_builders[13] = [] {
        Serial.println("Building screen 13");
        static char title[] = "Network ID";
        static char dictionary[] = "1234567890";
        static UI_GenericInput input = GI_make_input(
            title, 1, screen, dictionary, [](char* result) {
                Serial.println("Saving");
                Serial.println(result);
                config.saveNetworkID(result);
            },
            3, config.networkID, true);

        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[13] = screen_common;
        Serial.println("Screen 13 built");
    };
}