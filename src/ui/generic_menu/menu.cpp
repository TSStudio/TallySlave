#include "menu.h"
#include "../ui_all.h"

extern std::map<unsigned int, void (*)()> screen_builders;
extern std::map<unsigned int, screen_co> screens;

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
        *(this->screen_in_display) = this->selections[this->selected].clickScreen;
    }
}

void UI_GenericMenu::handleBack() {
    *(this->screen_in_display) = this->parent;
    Serial.println("Erasing");
    screens.erase(this->id);
    Serial.println("Deleting");
    delete this;  //?????
}

UI_GenericMenu::UI_GenericMenu(char* title, unsigned int _parent, unsigned int& _screen_in_display, UI_GenericMenu_Selection* _selections, unsigned int _selection_count, unsigned int _id) {
    id = _id;
    scr = lv_obj_create(NULL);
    lv_obj_set_size(scr, 160, 128);

    screen_style = new lv_style_t();
    lv_style_init(screen_style);
    lv_style_set_bg_color(screen_style, lv_color_black());
    lv_obj_add_style(scr, screen_style, 0);

    style_title = new lv_style_t();
    lv_style_init(style_title);
    lv_style_set_text_color(style_title, lv_color_white());
    lv_style_set_text_font(style_title, &siyuan12);
    lv_style_set_border_color(style_title, lv_color_white());
    lv_style_set_border_side(style_title, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_border_width(style_title, 1);

    style_plain = new lv_style_t();
    lv_style_init(style_plain);
    lv_style_set_text_color(style_plain, lv_color_white());
    lv_style_set_bg_color(style_plain, lv_color_black());
    lv_style_set_text_font(style_plain, &siyuan12);
    lv_style_set_pad_top(style_plain, 2);
    lv_style_set_pad_bottom(style_plain, 2);
    lv_style_set_pad_left(style_plain, 2);
    lv_style_set_width(style_plain, 152);

    style_selected = new lv_style_t();
    lv_style_init(style_selected);
    lv_style_set_text_color(style_selected, lv_color_black());
    lv_style_set_bg_color(style_selected, lv_color_white());
    lv_style_set_bg_opa(style_selected, LV_OPA_100);
    lv_style_set_text_font(style_selected, &siyuan12);
    lv_style_set_pad_top(style_selected, 2);
    lv_style_set_pad_bottom(style_selected, 2);
    lv_style_set_pad_left(style_selected, 2);
    lv_style_set_width(style_selected, 152);

    style_using = new lv_style_t();
    lv_style_init(style_using);
    lv_style_set_text_color(style_using, lv_color_black());
    lv_style_set_bg_color(style_using, lv_color_make(0xff, 0x00, 0x00));
    lv_style_set_bg_opa(style_using, LV_OPA_100);
    lv_style_set_text_font(style_using, &siyuan12);
    lv_style_set_pad_top(style_using, 2);
    lv_style_set_pad_bottom(style_using, 2);
    lv_style_set_pad_left(style_using, 2);
    lv_style_set_width(style_using, 152);

    style_using_selected = new lv_style_t();
    lv_style_init(style_using_selected);
    lv_style_set_text_color(style_using_selected, lv_color_black());
    lv_style_set_bg_color(style_using_selected, lv_color_make(0xff, 0x88, 0x88));
    lv_style_set_bg_opa(style_using_selected, LV_OPA_100);
    lv_style_set_text_font(style_using_selected, &siyuan12);
    lv_style_set_pad_top(style_using_selected, 2);
    lv_style_set_pad_bottom(style_using_selected, 2);
    lv_style_set_pad_left(style_using_selected, 2);
    lv_style_set_width(style_using_selected, 152);

    label_title = lv_label_create(scr);
    lv_label_set_text(label_title, title);
    lv_obj_align(label_title, LV_ALIGN_TOP_LEFT, 4, 4);
    lv_obj_add_style(label_title, style_title, 0);

    if (_selection_count == 0) {
        labels_selection = NULL;
    } else {
        labels_selection = (lv_obj_t**)malloc(sizeof(lv_obj_t*) * _selection_count);
    }

    for (unsigned int i = 0; i < _selection_count; i++) {
        labels_selection[i] = lv_label_create(scr);
        lv_label_set_text(labels_selection[i], _selections[i].text);
        lv_obj_align(labels_selection[i], LV_ALIGN_TOP_LEFT, 4, 4 + 18 * (i + 1));
        if (i == 0)
            lv_obj_add_style(labels_selection[i], style_selected, 0);
        else
            lv_obj_add_style(labels_selection[i], style_plain, 0);
    }
    selections = _selections;
    selection_count = _selection_count;
    parent = _parent;
    screen_in_display = &_screen_in_display;
    selected = 0;
    selected_prev = 0;
}

UI_GenericMenu::~UI_GenericMenu() {
    delete screen_style;
    delete style_title;
    delete style_plain;
    delete style_selected;
    delete style_using;
    delete style_using_selected;
    lv_obj_del(label_title);
    for (int i = 0; i < selection_count; ++i) {
        lv_obj_del(labels_selection[i]);
    }
    free(labels_selection);
    lv_obj_del(scr);
}