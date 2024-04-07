#include "input.h"

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
}

void UI_GenericInput::handleBackspace() {
    if (this->fixedLength) return;
    if (this->editingIndex == 0) return;
    this->editingIndex--;
    this->currentEditing[this->editingIndex] = 0;
    this->handleUpdate(true);
}

void UI_GenericInput::handleLeft() {
    if (this->editingIndex == 0) return;
    this->editingIndex--;
    this->handleUpdate(true);
}

void UI_GenericInput::handleRight() {
    if (this->editingIndex == this->maxLength - 1) return;
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

UI_GenericInput GI_make_input(char* title, unsigned int parent, unsigned int& screen_in_display, char* dictionary, void (*handleSave)(char* result), int maxLength, char* initfrom, bool fixedLength) {
    UI_GenericInput input;

    input.currentEditing = (char*)malloc(maxLength + 1);
    memset(input.currentEditing, 0, maxLength + 1);
    strcpy(input.currentEditing, initfrom);

    input.scr = lv_obj_create(NULL);
    lv_obj_set_size(input.scr, 160, 128);

    static lv_style_t screen_style;
    lv_style_init(&screen_style);
    lv_style_set_bg_color(&screen_style, lv_color_black());
    lv_obj_add_style(input.scr, &screen_style, 0);

    static lv_style_t style_title;
    lv_style_init(&style_title);
    lv_style_set_text_color(&style_title, lv_color_white());
    lv_style_set_text_font(&style_title, &siyuan12);

    static lv_style_t style_plain;
    lv_style_init(&style_plain);
    lv_style_set_text_color(&style_plain, lv_color_white());
    lv_style_set_bg_color(&style_plain, lv_color_black());
    lv_style_set_text_font(&style_plain, &siyuan12);

    static lv_style_t style_selected;
    lv_style_init(&style_selected);
    lv_style_set_text_color(&style_selected, lv_color_black());
    lv_style_set_bg_color(&style_selected, lv_color_white());
    lv_style_set_text_font(&style_selected, &siyuan12);
    lv_style_set_bg_opa(&style_selected, LV_OPA_100);

    input.label_title = lv_label_create(input.scr);
    lv_label_set_text(input.label_title, title);
    lv_obj_align(input.label_title, LV_ALIGN_TOP_LEFT, 4, 4);
    lv_obj_add_style(input.label_title, &style_title, 0);

    input.label_editing = lv_label_create(input.scr);
    lv_label_set_text(input.label_editing, input.currentEditing);
    lv_obj_align(input.label_editing, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(input.label_editing, &style_plain, 0);
    lv_obj_add_style(input.label_editing, &style_selected, LV_PART_SELECTED);

    //enable LV_LABEL_TEXT_SELECTION
    lv_label_set_text_selection_start(input.label_editing, 0);
    lv_label_set_text_selection_end(input.label_editing, 1);

    input.parent = parent;
    input.screen_in_display = &screen_in_display;
    input.dictionary = dictionary;
    input.maxLength = maxLength;
    input.fixedLength = fixedLength;
    input.handleSave = handleSave;

    input.editingIndex = 0;

    return input;
}