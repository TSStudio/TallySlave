#include "conmenu.h"

UI_GenericMenu setup_ui_conmenu_screen(unsigned int& screen_handle) {
    static char title[] = "Connection Menu";
    static char selection1[] = "Select Interface";
    static char selection2[] = "Wifi Settings";
    static char selection3[] = "Network ID";
    UI_GenericMenu_Selection* selections = GM_make_selections(4, GM_make_selection(selection1), GM_make_selection(selection2, false, 12), GM_make_selection(selection3));
    UI_GenericMenu menu = GM_make_menu(title, 0, screen_handle, selections, 3);
    return menu;
}