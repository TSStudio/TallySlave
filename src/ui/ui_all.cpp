#include "ui_all.h"

//0: Main, 1:ConMenu, 11:ConMenu-SelectInterface, 21:ConMenu-WifiSettings, 31:ConMenu-NetworkID

extern unsigned int current_screen;
extern unsigned int screen;
extern std::map<unsigned int, screen_co> screens;

void screen_co::refresh() {
    if (type == 0) {
        refresh_handle_t0((UI_GenericMenu*)ui_obj_ptr);
    } else if (type == 1) {
        refresh_handle_t1((ui_main_ui_entry*)ui_obj_ptr);
    }
}

void refresh_screen() {
    if (current_screen != screen) {
        lv_screen_load(screens[screen].screen_obj);
        current_screen = screen;
    }
    screens[screen].refresh();
    lv_task_handler();
}