#include "keys.h"

extern unsigned int current_screen;
extern unsigned int screen;
extern std::map<unsigned int, screen_co> screens;

const int freq = 32768;
const int ledChannel = 0;
const int resolution = 10;

int ledLevel = 512;

bool last_key_enc_a_pressed = false;
bool key_enc_a_pressed = false;
bool key_enc_b_pressed = false;
bool last_key_1 = false, last_key_2 = false, last_key_3 = false, last_key_4 = false;
bool key_1 = false, key_2 = false, key_3 = false, key_4 = false;

void key_1_down() {
    Serial.println("Key 1 down");
    Serial.printf("Current screen: %d\n", current_screen);
    if (current_screen == 0) {
        Serial.println("Making screen 1");
        screen = 1;
    } else if (current_screen == 1) {
        Serial.println("Making screen 0");
        screen = 0;
    } else {
        if (screens[current_screen].type == 0)
            ((UI_GenericMenu*)(screens[current_screen].ui_obj_ptr))->handleBack();
        if (screens[current_screen].type == 2)
            ((UI_GenericInput*)(screens[current_screen].ui_obj_ptr))->handleSaveInternal();
        screens.erase(current_screen);
    }
}
void key_2_down() {
    Serial.println("Key 2 down");
    if (screens[current_screen].type == 2)
        ((UI_GenericInput*)(screens[current_screen].ui_obj_ptr))->handleBackspace();
}
void key_3_down() {
    Serial.println("Key 3 down");
    if (screens[current_screen].type == 2)
        ((UI_GenericInput*)(screens[current_screen].ui_obj_ptr))->handleLeft();
}
void key_4_down() {
    Serial.println("Key 4 down");
    if (current_screen != 0) {
        if (screens[current_screen].type == 0)
            ((UI_GenericMenu*)(screens[current_screen].ui_obj_ptr))->handleClick();
        if (screens[current_screen].type == 2)
            ((UI_GenericInput*)(screens[current_screen].ui_obj_ptr))->handleRight();
    }
}

unsigned led_light_oetf(unsigned x) {
    //from 0-1023 to 0-1023
    return x * x / 1023;
}

void key_enc_clockwise() {
    Serial.println("Clockwise");
    if (current_screen != 0) {
        if (screens[current_screen].type == 0)
            ((UI_GenericMenu*)(screens[current_screen].ui_obj_ptr))->handleSelectionChange(1);
        if (screens[current_screen].type == 2)
            ((UI_GenericInput*)(screens[current_screen].ui_obj_ptr))->handleSelectionChange(1);
    } else {
        ledLevel = min(ledLevel + 50, 1023);
        ledcWrite(ledChannel, led_light_oetf(ledLevel));
    }
}

void key_enc_counter_clockwise() {
    Serial.println("Counter-clockwise");
    if (current_screen != 0) {
        if (screens[current_screen].type == 0)
            ((UI_GenericMenu*)(screens[current_screen].ui_obj_ptr))->handleSelectionChange(-1);
        if (screens[current_screen].type == 2)
            ((UI_GenericInput*)(screens[current_screen].ui_obj_ptr))->handleSelectionChange(-1);
    } else {
        ledLevel = max(ledLevel - 50, 0);
        ledcWrite(ledChannel, led_light_oetf(ledLevel));
    }
}

void setup_keys() {
    ledcSetup(ledChannel, freq, resolution);
    ledcAttachPin(SCREEN_SPI_BLK_PIN, ledChannel);
    pinMode(KEY_BT_1_PIN, INPUT_PULLUP);
    pinMode(KEY_BT_2_PIN, INPUT_PULLUP);
    pinMode(KEY_BT_3_PIN, INPUT_PULLUP);
    pinMode(KEY_BT_4_PIN, INPUT_PULLUP);
    pinMode(KEY_ENC_A_PIN, INPUT);
    pinMode(KEY_ENC_B_PIN, INPUT);
    pinMode(LED_R_PIN, OUTPUT);
    pinMode(LED_G_PIN, OUTPUT);
    pinMode(LED_B_PIN, OUTPUT);
    digitalWrite(LED_R_PIN, LOW);
    digitalWrite(LED_G_PIN, LOW);
    digitalWrite(LED_B_PIN, LOW);
    ledcWrite(ledChannel, led_light_oetf(ledLevel));
}

void do_key_stuff() {
    key_enc_a_pressed = digitalRead(KEY_ENC_A_PIN) == LOW;
    key_enc_b_pressed = digitalRead(KEY_ENC_B_PIN) == LOW;
    key_1 = digitalRead(KEY_BT_1_PIN) == LOW;
    key_2 = digitalRead(KEY_BT_2_PIN) == LOW;
    key_3 = digitalRead(KEY_BT_3_PIN) == LOW;
    key_4 = digitalRead(KEY_BT_4_PIN) == LOW;

    if (key_enc_a_pressed != last_key_enc_a_pressed) {
        if (key_enc_a_pressed) {
            if (key_enc_b_pressed) {
                key_enc_counter_clockwise();
            } else {
                key_enc_clockwise();
            }
        } else {
            if (key_enc_b_pressed) {
                key_enc_clockwise();
            } else {
                key_enc_counter_clockwise();
            }
        }
        last_key_enc_a_pressed = key_enc_a_pressed;
    }
    if (key_1 != last_key_1) {
        if (key_1) {
            key_1_down();
        }
        last_key_1 = key_1;
    }
    if (key_2 != last_key_2) {
        if (key_2) {
            key_2_down();
        }
        last_key_2 = key_2;
    }
    if (key_3 != last_key_3) {
        if (key_3) {
            key_3_down();
        }
        last_key_3 = key_3;
    }
    if (key_4 != last_key_4) {
        if (key_4) {
            key_4_down();
        }
        last_key_4 = key_4;
    }
}