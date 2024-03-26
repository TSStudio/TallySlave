#include "menu.h"

UI_GenericMenu_Selection GM_make_selection(char* text, bool enterable, bool isUsing = false) {
    UI_GenericMenu_Selection selection;
    selection.text = text;
    selection.enterable = enterable;
    selection.isUsing = isUsing;
    return selection;
}

UI_GenericMenu_Selection GM_make_selection(char* text) {
    return GM_make_selection(text, true, false);
}

UI_GenericMenu_Selection* GM_make_selections(unsigned int count, ...) {
    UI_GenericMenu_Selection* selections = (UI_GenericMenu_Selection*)malloc(sizeof(UI_GenericMenu_Selection) * count);
    va_list args;
    va_start(args, count);
    for (unsigned int i = 0; i < count; i++) {
        selections[i] = va_arg(args, UI_GenericMenu_Selection);
    }
    va_end(args);
    return selections;
}

void UI_GenericMenu::handleUpdate(bool forceUpdate = false) {
    if (this->selected_prev == this->selected) return;

    this->selected_prev = this->selected;
}

UI_GenericMenu GM_make_menu(char* title, unsigned int parent, unsigned int* screen_in_display, UI_GenericMenu_Selection* selections, unsigned int selection_count) {
    UI_GenericMenu menu;
    menu.scr = lv_obj_create(NULL);
    lv_obj_set_size(menu.scr, 160, 128);

    menu.label_title = lv_label_create(menu.scr);
    lv_label_set_text(menu.label_title, title);
    lv_obj_align(menu.label_title, LV_ALIGN_TOP_LEFT, 4, 4);

    menu.labels_selection = (lv_obj_t**)malloc(sizeof(lv_obj_t*) * selection_count);
    for (unsigned int i = 0; i < selection_count; i++) {
        menu.labels_selection[i] = lv_label_create(menu.scr);
        lv_label_set_text(menu.labels_selection[i], selections[i].text);
        //lv_obj_align(menu.labels_selection[i], NULL, LV_ALIGN_CENTER, 0, 0);
    }
    menu.selections = selections;
    menu.selection_count = selection_count;
    menu.parent = parent;
    menu.screen_in_display = screen_in_display;
    menu.selected = 0;
    return menu;
}