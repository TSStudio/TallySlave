#include "input.h"
#include "../ui_all.h"

extern std::map<unsigned int, screen_co> screens;

void UI_GenericInput::handleUpdate(bool forceUpdate) {
    if (!forceUpdate) return;
    lv_label_set_text(this->label_editing, this->currentEditing);
    lv_label_set_text_selection_start(this->label_editing, this->editingIndex);
    lv_label_set_text_selection_end(this->label_editing, this->editingIndex + 1);
}

void ui_generic_input_handle_update(UI_GenericInput* input) {
    input->handleUpdate();
}

void UI_GenericInput::handleSaveInternal() {
    this->handleSave(this->currentEditing);
    *(this->screen_in_display) = this->parent;
    screens.erase(this->id);
    delete this;
}

void UI_GenericInput::handleBackspace() {
    if (this->fixedLength) return;
    if (this->editingIndex == 0) return;
    this->editingIndex--;
    for (int i = this->editingIndex; i < strlen(this->currentEditing); i++) {
        this->currentEditing[i] = this->currentEditing[i + 1];
    }
    this->handleUpdate(true);
}

void UI_GenericInput::handleLeft() {
    if (this->editingIndex == 0) return;
    this->editingIndex--;
    this->handleUpdate(true);
}

void UI_GenericInput::handleRight() {
    if (this->editingIndex == this->maxLength - 1) return;
    if (this->editingIndex == strlen(this->currentEditing)) return;
    this->editingIndex++;
    this->handleUpdate(true);
}

void UI_GenericInput::handleSelectionChange(int delta) {
    if (this->currentEditing[this->editingIndex] == 0) {
        this->currentEditing[this->editingIndex] = this->dictionary[0];
        this->currentEditing[this->editingIndex + 1] = 0;
    }
    //find current editing char in dictionary
    int currentCharInDict = -1;
    for (int i = 0; i < strlen(this->dictionary); i++) {
        if (this->currentEditing[this->editingIndex] == this->dictionary[i]) {
            currentCharInDict = i;
            break;
        }
    }
    Serial.printf("Current char in dict: %d\n", currentCharInDict);
    if (currentCharInDict == -1) return;
    currentCharInDict += delta;
    while (currentCharInDict < 0) currentCharInDict += strlen(this->dictionary);
    currentCharInDict %= strlen(this->dictionary);
    this->currentEditing[this->editingIndex] = this->dictionary[currentCharInDict];
    this->handleUpdate(true);
}

UI_GenericInput::UI_GenericInput(char* title, unsigned int _parent, unsigned int& _screen_in_display, char* _dictionary, void (*_handleSave)(char* result), int _maxLength, char* _initfrom, bool _fixedLength, unsigned int _id) {
    currentEditing = (char*)malloc(maxLength + 1);
    memset(currentEditing, 0, maxLength + 1);
    strcpy(currentEditing, _initfrom);

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

    style_plain = new lv_style_t();
    lv_style_init(style_plain);
    lv_style_set_text_color(style_plain, lv_color_white());
    lv_style_set_bg_color(style_plain, lv_color_black());
    lv_style_set_text_font(style_plain, &siyuan12);

    style_selected = new lv_style_t();
    lv_style_init(style_selected);
    lv_style_set_text_color(style_selected, lv_color_black());
    lv_style_set_bg_color(style_selected, lv_color_white());
    lv_style_set_text_font(style_selected, &siyuan12);
    lv_style_set_bg_opa(style_selected, LV_OPA_100);

    label_title = lv_label_create(scr);
    lv_label_set_text(label_title, title);
    lv_obj_align(label_title, LV_ALIGN_TOP_LEFT, 4, 4);
    lv_obj_add_style(label_title, style_title, 0);

    label_editing = lv_label_create(scr);
    lv_label_set_text(label_editing, currentEditing);
    lv_obj_align(label_editing, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(label_editing, style_plain, 0);
    lv_obj_add_style(label_editing, style_selected, LV_PART_SELECTED);

    //enable LV_LABEL_TEXT_SELECTION
    lv_label_set_text_selection_start(label_editing, 0);
    lv_label_set_text_selection_end(label_editing, 1);

    parent = _parent;
    screen_in_display = &_screen_in_display;
    dictionary = _dictionary;
    maxLength = _maxLength;
    fixedLength = _fixedLength;
    handleSave = _handleSave;
    id = _id;

    editingIndex = 0;
}

UI_GenericInput::~UI_GenericInput() {
    free(currentEditing);
    lv_obj_del(scr);
    delete screen_style;
    delete style_title;
    delete style_plain;
    delete style_selected;
    lv_obj_del(label_title);
    lv_obj_del(label_editing);
}