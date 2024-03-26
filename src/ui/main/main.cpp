#include "main.h"

void ui_main_args::init() {
    voltage = 0.0;
    current_device_id = "A01";
    preview_device_id = "B01";
    program_device_id = "A02";
    signaldBm = -10;
    signalType = 1;
    signalState = 2;
    state = 2;
}
char* ui_main_args::getSignalTypeString() {
    switch (this->signalType) {
        case 0:
            return "CAN";
        case 1:
            return "WiFi";
        case 2:
            return "LoRa";
        default:
            return "N/A";
    }
}
lv_color_t ui_main_args::getSignalTypeColor() {
    if (this->signalType != 1) {
        return lv_color_black();
    }
    if (this->signalState == 0) {
        return lv_color_black();
    }
    if (this->signalState == 1) {
        return lv_color_make(0xcc, 0x00, 0xff);
    }
    if (this->signaldBm < -80) {
        return lv_color_make(0xff, 0x00, 0x00);
    }
    if (this->signaldBm < -65) {
        return lv_color_make(0xff, 0xff, 0x00);
    }
    return lv_color_make(0x00, 0xcc, 0x00);
}

void ui_main_handle_update(ui_main_ui_entry* ui_entry) {
    ui_entry->handleUpdate();
}

void ui_main_ui_entry::handleUpdate() {
    if (memcmp(this->args, this->lastdrew_args, sizeof(ui_main_args)) == 0) {
        return;
    }
    char voltage[10];
    sprintf(voltage, "DC %.1fV", this->args->voltage);
    lv_label_set_text(this->objs->label_Voltage, voltage);
    if (this->args->signalType != 0) {
        char signaldBm[10];
        sprintf(signaldBm, "%ddBm", this->args->signaldBm);
        lv_label_set_text(this->objs->label_SignaldBm, signaldBm);
    } else {
        lv_label_set_text(this->objs->label_SignaldBm, "");
    }
    lv_label_set_text(this->objs->label_SignalType, this->args->getSignalTypeString());
    lv_label_set_text(this->objs->label_CurrentDeviceID, this->args->current_device_id);
    lv_label_set_text(this->objs->label_PreviewDeviceID, this->args->preview_device_id);
    lv_label_set_text(this->objs->label_ProgramDeviceID, this->args->program_device_id);
    if (this->args->state == 0) {
        lv_style_set_bg_color(this->objs->style_currentID, lv_color_black());
        lv_label_set_text(this->objs->label_currentState, "");
    } else if (this->args->state == 1) {
        lv_style_set_bg_color(this->objs->style_currentID, lv_color_make(0x00, 0x99, 0x00));
        lv_label_set_text(this->objs->label_currentState, "PREVIEW");
    } else {
        lv_style_set_bg_color(this->objs->style_currentID, lv_color_make(0xff, 0x00, 0x00));
        lv_label_set_text(this->objs->label_currentState, "PROGRAM");
    }
    lv_style_set_text_color(this->objs->style_wifi, this->args->getSignalTypeColor());
    memcpy(this->lastdrew_args, this->args, sizeof(ui_main_args));
}

ui_main_ui_entry* setup_ui_main_screen() {
    ui_main_ui_entry* ui_entry = new ui_main_ui_entry;
    ui_entry->args = new ui_main_args;
    ui_entry->lastdrew_args = new ui_main_args;
    ui_entry->args->init();
    ui_entry->objs = new ui_main_objs;
    ui_entry->objs->scr = lv_obj_create(NULL);
    lv_obj_set_size(ui_entry->objs->scr, 160, 128);

    static lv_style_t screen_style;
    lv_style_init(&screen_style);
    lv_style_set_bg_color(&screen_style, lv_color_black());
    lv_obj_add_style(ui_entry->objs->scr, &screen_style, 0);

    static lv_style_t style_plain;
    lv_style_init(&style_plain);
    lv_style_set_text_color(&style_plain, lv_color_white());
    lv_style_set_text_font(&style_plain, &siyuan12);

    static lv_style_t style_wifi;
    lv_style_init(&style_wifi);
    lv_style_set_text_color(&style_wifi, lv_color_white());
    lv_style_set_text_font(&style_wifi, &lv_font_montserrat_12);
    ui_entry->objs->style_wifi = &style_wifi;

    static lv_style_t style_currentID;
    lv_style_init(&style_currentID);
    lv_style_set_text_color(&style_currentID, lv_color_white());
    lv_style_set_bg_color(&style_currentID, lv_color_make(0x00, 0x99, 0x00));
    lv_style_set_pad_top(&style_currentID, 6);
    lv_style_set_pad_bottom(&style_currentID, -13);
    lv_style_set_pad_left(&style_currentID, 3);
    lv_style_set_pad_right(&style_currentID, 3);
    lv_style_set_bg_opa(&style_currentID, LV_OPA_100);
    lv_style_set_text_font(&style_currentID, &siyuan72);
    ui_entry->objs->style_currentID = &style_currentID;

    static lv_style_t style_PVW;
    lv_style_init(&style_PVW);
    lv_style_set_text_color(&style_PVW, lv_color_make(0x00, 0x99, 0x00));
    lv_style_set_bg_color(&style_PVW, lv_color_white());
    lv_style_set_pad_all(&style_PVW, 3);
    lv_style_set_bg_opa(&style_PVW, LV_OPA_100);
    lv_style_set_text_font(&style_PVW, &siyuan12);

    static lv_style_t style_PGM;
    lv_style_init(&style_PGM);
    lv_style_set_text_color(&style_PGM, lv_color_make(0xff, 0x00, 0x00));
    lv_style_set_bg_color(&style_PGM, lv_color_white());
    lv_style_set_pad_all(&style_PGM, 3);
    lv_style_set_bg_opa(&style_PGM, LV_OPA_100);
    lv_style_set_text_font(&style_PGM, &siyuan12);

    ui_entry->objs->label_Voltage = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_Voltage, &style_plain, 0);
    lv_label_set_text(ui_entry->objs->label_Voltage, "DC");
    lv_obj_align(ui_entry->objs->label_Voltage, LV_ALIGN_TOP_LEFT, 4, 4);

    ui_entry->objs->label_SignaldBm = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_SignaldBm, &style_plain, 0);
    lv_label_set_text(ui_entry->objs->label_SignaldBm, "0dBm");
    lv_obj_align(ui_entry->objs->label_SignaldBm, LV_ALIGN_TOP_LEFT, 58, 4);

    ui_entry->objs->label_wifi = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_wifi, &style_wifi, 0);
    lv_label_set_text(ui_entry->objs->label_wifi, LV_SYMBOL_WIFI);
    lv_obj_align(ui_entry->objs->label_wifi, LV_ALIGN_TOP_LEFT, 116, 4);

    ui_entry->objs->label_SignalType = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_SignalType, &style_plain, 0);
    lv_label_set_text(ui_entry->objs->label_SignalType, "CAN");
    lv_obj_align(ui_entry->objs->label_SignalType, LV_ALIGN_TOP_RIGHT, -4, 4);

    ui_entry->objs->label_CurrentDeviceID = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_CurrentDeviceID, &style_currentID, 0);
    lv_label_set_text(ui_entry->objs->label_CurrentDeviceID, "A01");
    lv_obj_align(ui_entry->objs->label_CurrentDeviceID, LV_ALIGN_CENTER, 0, 1);

    ui_entry->objs->label_currentState = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_currentState, &style_plain, 0);
    lv_label_set_text(ui_entry->objs->label_currentState, "");
    lv_obj_align(ui_entry->objs->label_currentState, LV_ALIGN_CENTER, 0, -30);

    ui_entry->objs->label_PreviewDeviceText = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_PreviewDeviceText, &style_plain, 0);
    lv_label_set_text(ui_entry->objs->label_PreviewDeviceText, "PVW");
    lv_obj_align(ui_entry->objs->label_PreviewDeviceText, LV_ALIGN_TOP_LEFT, 8, 108);

    ui_entry->objs->label_PreviewDeviceID = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_PreviewDeviceID, &style_PVW, 0);
    lv_label_set_text(ui_entry->objs->label_PreviewDeviceID, "B01");
    lv_obj_align(ui_entry->objs->label_PreviewDeviceID, LV_ALIGN_TOP_LEFT, 36, 105);

    ui_entry->objs->label_ProgramDeviceText = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_ProgramDeviceText, &style_plain, 0);
    lv_label_set_text(ui_entry->objs->label_ProgramDeviceText, "PGM");
    lv_obj_align(ui_entry->objs->label_ProgramDeviceText, LV_ALIGN_TOP_LEFT, 96, 108);

    ui_entry->objs->label_ProgramDeviceID = lv_label_create(ui_entry->objs->scr);
    lv_obj_add_style(ui_entry->objs->label_ProgramDeviceID, &style_PGM, 0);
    lv_label_set_text(ui_entry->objs->label_ProgramDeviceID, "A02");
    lv_obj_align(ui_entry->objs->label_ProgramDeviceID, LV_ALIGN_TOP_LEFT, 124, 105);

    return ui_entry;
}
