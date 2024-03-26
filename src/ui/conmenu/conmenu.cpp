#include "conmenu.h"

UI_GenericMenu setup_ui_conmenu_screen(unsigned int& screen_handle) {
    static char title[] = "Connection Menu";
    static char selection1[] = "S1";
    static char selection2[] = "S2";
    static char selection3[] = "S3";
    static char selection4[] = "S4";
    UI_GenericMenu_Selection* selections = GM_make_selections(4, GM_make_selection(selection1), GM_make_selection(selection2), GM_make_selection(selection3), GM_make_selection(selection4));
    UI_GenericMenu menu = GM_make_menu(title, 0, screen_handle, selections, 4);
    return menu;
}