#ifndef _UI_GENERIC_INPUT_H_
#define _UI_GENERIC_INPUT_H_
#include <lvgl.h>
#include <cstdio>
#include <map>
#include <Arduino.h>

struct UI_GenericInput {
    lv_obj_t *scr, *label_title, *label_editing;
    unsigned int parent;
    char* currentEditing;
    char* dictionary;
    unsigned int maxLength;
    bool fixedLength;
    unsigned int* screen_in_display;
    unsigned int editingIndex;
    void handleUpdate(bool forceUpdate = false);
    void handleSaveInternal();
    void (*handleSave)(char* result);
    void handleBackspace();
    void handleLeft();
    void handleRight();
    void handleSelectionChange(int delta = 0);
};
void ui_generic_input_handle_update(UI_GenericInput* input);
UI_GenericInput GI_make_input(char* title, unsigned int parent, unsigned int& screen_in_display, char* dictionary, void (*handleSave)(char* result), int maxLength, char* initfrom, bool fixedLength = false);
#endif