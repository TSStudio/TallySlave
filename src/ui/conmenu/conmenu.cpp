#include "conmenu.h"

UI_GenericMenu setup_ui_conmenu_screen(unsigned int& screen_handle) {
    static char title[] = "Connection Menu";
    static char selection1[] = "Select Interface";
    static char selection2[] = "Wifi Settings";
    static char selection3[] = "Network ID";
    static char selection4[] = "Device ID";
    UI_GenericMenu_Selection* selections = GM_make_selections(4, GM_make_selection(selection1, false, 11), GM_make_selection(selection2, false, 12), GM_make_selection(selection3, false, 13), GM_make_selection(selection4, false, 14));
    UI_GenericMenu menu = GM_make_menu(title, 0, screen_handle, selections, 4);
    return menu;
}