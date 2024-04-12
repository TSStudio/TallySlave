#include "menu.h"

extern std::map<unsigned int, void (*)()> screen_builders;

UI_GenericMenu_Selection GM_make_selection(char* text, bool isUsing, int clickScreen, UI_Selection_Callback callback) {
    UI_GenericMenu_Selection selection;
    selection.text = text;
    selection.isUsing = isUsing;
    selection.clickScreen = clickScreen;
    selection.callback = callback;
    return selection;
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

void ui_generic_menu_handle_update(UI_GenericMenu* menu) {
    menu->handleUpdate();
}

void UI_GenericMenu::handleUpdate(bool forceUpdate) {
    if (this->selected_prev == this->selected && !forceUpdate) return;
    for (unsigned int i = 0; i < this->selection_count; i++) {
        if (i == this->selected) {
            lv_obj_remove_style(this->labels_selection[i], this->style_plain, 0);
            lv_obj_remove_style(this->labels_selection[i], this->style_using, 0);
            if (this->selections[i].isUsing) {
                lv_obj_add_style(this->labels_selection[i], this->style_using_selected, 0);
            } else {
                lv_obj_add_style(this->labels_selection[i], this->style_selected, 0);
            }
        } else {
            lv_obj_remove_style(this->labels_selection[i], this->style_selected, 0);
            lv_obj_remove_style(this->labels_selection[i], this->style_using_selected, 0);
            if (this->selections[i].isUsing) {
                lv_obj_add_style(this->labels_selection[i], this->style_using, 0);
            } else {
                lv_obj_add_style(this->labels_selection[i], this->style_plain, 0);
            }
        }
    }
    this->selected_prev = this->selected;
}

void UI_GenericMenu::handleSelectionChange(int delta) {
    //if (this->selected < 0) this->selected = this->selection_count - 1;
    if (delta < 0 && (this->selected < (-delta))) {
        this->selected = this->selection_count - 1;
        return;
    }
    this->selected += delta;
    if (this->selected >= this->selection_count) this->selected = 0;
}

void UI_GenericMenu::handleClick() {
    if (this->selections[this->selected].clickScreen == 0) {
        if (this->selections[this->selected].callback != NULL)
            this->selections[this->selected].callback(this);

    } else {
        screen_builders[this->selections[this->selected].clickScreen]();
        *(this->screen_in_display) = this->selections[this->selected].clickScreen;
    }
}

void UI_GenericMenu::handleBack() {
    *(this->screen_in_display) = this->parent;
}

UI_GenericMenu GM_make_menu(char* title, unsigned int parent, unsigned int& screen_in_display, UI_GenericMenu_Selection* selections, unsigned int selection_count) {
    UI_GenericMenu menu;
    menu.scr = lv_obj_create(NULL);
    lv_obj_set_size(menu.scr, 160, 128);

    static lv_style_t screen_style;
    lv_style_init(&screen_style);
    lv_style_set_bg_color(&screen_style, lv_color_black());
    lv_obj_add_style(menu.scr, &screen_style, 0);

    static lv_style_t style_title;
    lv_style_init(&style_title);
    lv_style_set_text_color(&style_title, lv_color_white());
    lv_style_set_text_font(&style_title, &siyuan12);

    static lv_style_t style_plain;
    lv_style_init(&style_plain);
    lv_style_set_text_color(&style_plain, lv_color_white());
    lv_style_set_bg_color(&style_plain, lv_color_black());
    lv_style_set_text_font(&style_plain, &siyuan12);
    lv_style_set_pad_top(&style_plain, 2);
    lv_style_set_pad_bottom(&style_plain, 2);
    lv_style_set_pad_left(&style_plain, 2);
    lv_style_set_width(&style_plain, 152);
    menu.style_plain = &style_plain;

    static lv_style_t style_selected;
    lv_style_init(&style_selected);
    lv_style_set_text_color(&style_selected, lv_color_black());
    lv_style_set_bg_color(&style_selected, lv_color_white());
    lv_style_set_bg_opa(&style_selected, LV_OPA_100);
    lv_style_set_text_font(&style_selected, &siyuan12);
    lv_style_set_pad_top(&style_selected, 2);
    lv_style_set_pad_bottom(&style_selected, 2);
    lv_style_set_pad_left(&style_selected, 2);
    lv_style_set_width(&style_selected, 152);
    menu.style_selected = &style_selected;

    static lv_style_t style_using;
    lv_style_init(&style_using);
    lv_style_set_text_color(&style_using, lv_color_black());
    lv_style_set_bg_color(&style_using, lv_color_make(0xff, 0x00, 0x00));
    lv_style_set_bg_opa(&style_using, LV_OPA_100);
    lv_style_set_text_font(&style_using, &siyuan12);
    lv_style_set_pad_top(&style_using, 2);
    lv_style_set_pad_bottom(&style_using, 2);
    lv_style_set_pad_left(&style_using, 2);
    lv_style_set_width(&style_using, 152);
    menu.style_using = &style_using;

    static lv_style_t style_using_selected;
    lv_style_init(&style_using_selected);
    lv_style_set_text_color(&style_using_selected, lv_color_black());
    lv_style_set_bg_color(&style_using_selected, lv_color_make(0xff, 0x88, 0x88));
    lv_style_set_bg_opa(&style_using_selected, LV_OPA_100);
    lv_style_set_text_font(&style_using_selected, &siyuan12);
    lv_style_set_pad_top(&style_using_selected, 2);
    lv_style_set_pad_bottom(&style_using_selected, 2);
    lv_style_set_pad_left(&style_using_selected, 2);
    lv_style_set_width(&style_using_selected, 152);
    menu.style_using_selected = &style_using_selected;

    menu.label_title = lv_label_create(menu.scr);
    lv_label_set_text(menu.label_title, title);
    lv_obj_align(menu.label_title, LV_ALIGN_TOP_LEFT, 4, 4);
    lv_obj_add_style(menu.label_title, &style_title, 0);

    if (selection_count == 0) {
        menu.labels_selection = NULL;
    } else {
        menu.labels_selection = (lv_obj_t**)malloc(sizeof(lv_obj_t*) * selection_count);
    }

    for (unsigned int i = 0; i < selection_count; i++) {
        menu.labels_selection[i] = lv_label_create(menu.scr);
        lv_label_set_text(menu.labels_selection[i], selections[i].text);
        lv_obj_align(menu.labels_selection[i], LV_ALIGN_TOP_LEFT, 4, 4 + 18 * (i + 1));
        if (i == 0)
            lv_obj_add_style(menu.labels_selection[i], &style_selected, 0);
        else
            lv_obj_add_style(menu.labels_selection[i], &style_plain, 0);
    }
    menu.selections = selections;
    menu.selection_count = selection_count;
    menu.parent = parent;
    menu.screen_in_display = &screen_in_display;
    menu.selected = 0;
    menu.selected_prev = 0;
    return menu;
}