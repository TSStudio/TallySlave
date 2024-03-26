#ifndef _UI_GENERIC_MENU_H_
#define _UI_GENERIC_MENU_H_
#include <lvgl.h>
#include <cstdio>
struct UI_GenericMenu_Selection {
    char* text;
    bool enterable;
    bool isUsing;
};
UI_GenericMenu_Selection GM_make_selection(char* text, void (*callback)());

/**
 * Back will destroy data, and change screen back to parent
*/

struct UI_GenericMenu {
    lv_obj_t *scr, *label_title;
    lv_obj_t** labels_selection;
    UI_GenericMenu_Selection* selections;
    unsigned int selection_count;
    unsigned int parent;
    unsigned int* screen_in_display;  //this is for changing screen
    unsigned int selected;
    unsigned int selected_prev;
    void handleUpdate(bool forceUpdate = false);
};

#endif