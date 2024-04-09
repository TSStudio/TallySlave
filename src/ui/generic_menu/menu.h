#ifndef _UI_GENERIC_MENU_H_
#define _UI_GENERIC_MENU_H_
#include <lvgl.h>
#include <cstdio>
#include <map>
#include <Arduino.h>

typedef void (*UI_Selection_Callback)(UI_GenericMenu&);
struct UI_GenericMenu_Selection {
    char* text;
    bool isUsing;
    int clickScreen;
    UI_Selection_Callback callback;
};

UI_GenericMenu_Selection GM_make_selection(char* text, bool isUsing = false, int clickScreen = 0, UI_Selection_Callback callback = NULL);
UI_GenericMenu_Selection* GM_make_selections(unsigned int count, ...);

/**
 * Back will destroy data, and change screen back to parent
*/

struct UI_GenericMenu {
    lv_obj_t *scr, *label_title;
    lv_obj_t** labels_selection;
    UI_GenericMenu_Selection* selections;
    lv_style_t* style_plain;
    lv_style_t* style_selected;
    lv_style_t* style_using;
    lv_style_t* style_using_selected;
    unsigned int selection_count;
    unsigned int parent;
    unsigned int* screen_in_display;  //this is for changing screen
    unsigned int selected;
    unsigned int selected_prev;
    void handleUpdate(bool forceUpdate = false);
    void handleClick();
    void handleBack();
    void handleSelectionChange(int delta = 0);
};
void ui_generic_menu_handle_update(UI_GenericMenu* menu);
UI_GenericMenu GM_make_menu(char* title, unsigned int parent, unsigned int& screen_in_display, UI_GenericMenu_Selection* selections, unsigned int selection_count);
#endif