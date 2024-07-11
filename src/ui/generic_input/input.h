#ifndef _UI_GENERIC_INPUT_H_
#define _UI_GENERIC_INPUT_H_
#include <lvgl.h>
#include <cstdio>
#include <map>
#include <Arduino.h>

struct UI_GenericInput {
    lv_obj_t *scr, *label_title, *label_editing;
    lv_style_t *screen_style, *style_title, *style_plain, *style_selected;
    unsigned int id;
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

    UI_GenericInput(char* title, unsigned int _parent, unsigned int& _screen_in_display, char* _dictionary, void (*_handleSave)(char* result), int _maxLength, char* _initfrom, bool _fixedLength, unsigned int _id);

    ~UI_GenericInput();
};
void ui_generic_input_handle_update(UI_GenericInput* input);
#endif