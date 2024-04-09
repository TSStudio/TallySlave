#include "ui_all.h"

//0: Main, 1:ConMenu, 11:ConMenu-SelectInterface, 12:ConMenu-WifiSettings, 13:ConMenu-NetworkID

extern unsigned int current_screen;
extern unsigned int screen;
extern std::map<unsigned int, screen_co> screens;
std::map<unsigned int, void (*)()> screen_builders;
extern Configuration config;

void screen_co::refresh() {
    if (type == 0) {
        refresh_handle_t0((UI_GenericMenu*)ui_obj_ptr);
    } else if (type == 1) {
        refresh_handle_t1((ui_main_ui_entry*)ui_obj_ptr);
    } else if (type == 2) {
        refresh_handle_t2((UI_GenericInput*)ui_obj_ptr);
    }
}

void refresh_screen() {
    if (current_screen != screen) {
        Serial.printf("Changing screen to %d\n", screen);
        //check if screen is already built
        if (screens.find(screen) == screens.end()) {
            Serial.println("No screen found, going back");
            screen = current_screen;
            return;
        } else {
            Serial.println("Screen already built");
        }
        lv_screen_load(screens[screen].screen_obj);
        current_screen = screen;
    }
    screens[screen].refresh();
    lv_task_handler();
}

void init_builders() {
    //screen_builders[i]=[]{};
    // Ya need to provide a lambda function here
    // and finally push screen_co to screens
    screen_builders[11] = [] {
        static char title[] = "Select Interface";
        static char selection1[] = "CAN";
        static char selection2[] = "LoRa";
        static char selection3[] = "WiFi";
        UI_GenericMenu_Selection* selections = GM_make_selections(3, GM_make_selection(selection1, false, 0, [](UI_GenericMenu& menu) {
                                                                      for (int i = 0; i < 3; i++) {
                                                                          menu.selections[i].isUsing = false;
                                                                      }
                                                                      menu.selections[0].isUsing = true;
                                                                      menu.handleUpdate(true);
                                                                  }),
                                                                  GM_make_selection(selection2, false, 0, [](UI_GenericMenu& menu) {}), GM_make_selection(selection3, false, 0, [](UI_GenericMenu& menu) {}));  //TODO callback function
        static UI_GenericMenu menu = GM_make_menu(title, 1, screen, selections, 3);
        static screen_co screen_common;
        screen_common.screen_obj = menu.scr;
        screen_common.refresh_handle_t0 = ui_generic_menu_handle_update;
        screen_common.type = 0;
        screen_common.ui_obj_ptr = &menu;
        screens[11] = screen_common;
    };
    screen_builders[12] = [] {
        static char title[] = "Wifi Settings";
        static char selection1[] = "Authentication";
        static char selection2[] = "Server";
        static char selection3[] = "Toggle DHCP";
        static char selection4[] = "IP Manual Settings";
        UI_GenericMenu_Selection* selections = GM_make_selections(4, GM_make_selection(selection1, false, 121), GM_make_selection(selection2, false, 122), GM_make_selection(selection3, false, 123), GM_make_selection(selection4, false, 124));
        static UI_GenericMenu menu = GM_make_menu(title, 1, screen, selections, 4);

        static screen_co screen_common;
        screen_common.screen_obj = menu.scr;
        screen_common.refresh_handle_t0 = ui_generic_menu_handle_update;
        screen_common.type = 0;
        screen_common.ui_obj_ptr = &menu;
        screens[12] = screen_common;
    };
    screen_builders[121] = [] {
        static char title[] = "Authentication";
        static char selection1[] = "SSID";
        static char selection2[] = "Passcode";
        UI_GenericMenu_Selection* selections = GM_make_selections(2, GM_make_selection(selection1, false, 1211), GM_make_selection(selection2, false, 1212));
        static UI_GenericMenu menu = GM_make_menu(title, 12, screen, selections, 2);

        static screen_co screen_common;
        screen_common.screen_obj = menu.scr;
        screen_common.refresh_handle_t0 = ui_generic_menu_handle_update;
        screen_common.type = 0;
        screen_common.ui_obj_ptr = &menu;
        screens[121] = screen_common;
    };
    screen_builders[1211] = [] {
        static char title[] = "SSID";
        static char dictionary[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_.";
        static UI_GenericInput input = GI_make_input(
            title, 121, screen, dictionary, [](char* result) {
                Serial.println("Saving");
                Serial.println(result);
                config.saveWifiSSID(result);
                do_wifi_cleanup();
                initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);
            },
            15, config.wifiSSID, false);
        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[1211] = screen_common;
    };
    screen_builders[1212] = [] {
        static char title[] = "Passcode";
        static char dictionary[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        static UI_GenericInput input = GI_make_input(
            title, 121, screen, dictionary, [](char* result) {
                Serial.println("Saving");
                Serial.println(result);
                config.saveWifiPassword(result);
                do_wifi_cleanup();
                initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);
            },
            15, config.wifiPassword, false);
        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[1212] = screen_common;
    };
    screen_builders[122] = [] {
        static char title[] = "Server";
        static char selection1[] = "Server IP";
        static char selection2[] = "Server Port";
        UI_GenericMenu_Selection* selections = GM_make_selections(2, GM_make_selection(selection1, false, 1221), GM_make_selection(selection2, false, 1222));
        static UI_GenericMenu menu = GM_make_menu(title, 12, screen, selections, 2);

        static screen_co screen_common;
        screen_common.screen_obj = menu.scr;
        screen_common.refresh_handle_t0 = ui_generic_menu_handle_update;
        screen_common.type = 0;
        screen_common.ui_obj_ptr = &menu;
        screens[122] = screen_common;
    };
    screen_builders[1221] = [] {
        static char title[] = "Server IP";
        static char dictionary[] = "1234567890.";
        char* ip_r = IPConstructor(config.serverIP);
        static UI_GenericInput input = GI_make_input(
            title, 122, screen, dictionary, [](char* result) {
                IPValidatorResult ipResult = IPValidator(result);
                Serial.println("Saving");
                if (!ipResult.valid) {
                    Serial.println("Invalid IP");
                    return;
                }
                Serial.println(ipResult.ip);
                config.saveServerIP(ipResult.ip);
                do_wifi_cleanup();
                initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);
            },
            15, ip_r, false);
        free(ip_r);
        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[1221] = screen_common;
    };
    screen_builders[1222] = [] {
        static char title[] = "Server Port";
        static char dictionary[] = "1234567890";
        char* ip_r = PortConstructor(config.serverPort);
        static UI_GenericInput input = GI_make_input(
            title, 122, screen, dictionary, [](char* result) {
                //trans result to number
                uint32_t port = 0;
                for (int i = 0; i < strlen(result); i++) {
                    port = port * 10 + result[i] - '0';
                }
                if (port > 65535) {
                    Serial.println("Invalid Port");
                    return;
                }
                Serial.println("Saving");
                Serial.println(port);
                config.saveServerPort(port);
                do_wifi_cleanup();
                initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);
            },
            5, ip_r, false);
        free(ip_r);
        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[1222] = screen_common;
    };
    screen_builders[124] = [] {
        static char title[] = "IP Manual Set";
        static char selection1[] = "IP Address";
        static char selection2[] = "Subnet Mask";
        static char selection3[] = "Gateway(Router)";
        static char selection4[] = "DNS Server";
        UI_GenericMenu_Selection* selections = GM_make_selections(4, GM_make_selection(selection1, false, 1241), GM_make_selection(selection2, false, 1242), GM_make_selection(selection3, false, 1243), GM_make_selection(selection4, false, 1244));
        static UI_GenericMenu menu = GM_make_menu(title, 12, screen, selections, 4);

        static screen_co screen_common;
        screen_common.screen_obj = menu.scr;
        screen_common.refresh_handle_t0 = ui_generic_menu_handle_update;
        screen_common.type = 0;
        screen_common.ui_obj_ptr = &menu;
        screens[124] = screen_common;
    };
    screen_builders[1241] = [] {
        static char title[] = "IP Address";
        static char dictionary[] = "1234567890.";
        char* ip_r = IPConstructor(config.serverIP);
        static UI_GenericInput input = GI_make_input(
            title, 124, screen, dictionary, [](char* result) {
                IPValidatorResult ipResult = IPValidator(result);
                Serial.println("Saving");
                if (!ipResult.valid) {
                    Serial.println("Invalid IP");
                    return;
                }
                Serial.println(ipResult.ip);
                config.saveDeviceIP(ipResult.ip);
                do_wifi_cleanup();
                initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);
            },
            15, ip_r, false);
        free(ip_r);
        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[1241] = screen_common;
    };
    screen_builders[1242] = [] {
        static char title[] = "Subnet Mask";
        static char dictionary[] = "1234567890.";
        char* ip_r = IPConstructor(config.serverIP);
        static UI_GenericInput input = GI_make_input(
            title, 124, screen, dictionary, [](char* result) {
                IPValidatorResult ipResult = SubnetMaskValidator(result);
                Serial.println("Saving");
                if (!ipResult.valid) {
                    Serial.println("Invalid Subnet Mask");
                    return;
                }
                Serial.println(ipResult.ip);
                config.saveSubnetMask(ipResult.ip);
                do_wifi_cleanup();
                initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);
            },
            15, ip_r, false);
        free(ip_r);
        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[1242] = screen_common;
    };
    screen_builders[1243] = [] {
        static char title[] = "Gateway";
        static char dictionary[] = "1234567890.";
        char* ip_r = IPConstructor(config.serverIP);
        static UI_GenericInput input = GI_make_input(
            title, 124, screen, dictionary, [](char* result) {
                IPValidatorResult ipResult = IPValidator(result);
                Serial.println("Saving");
                if (!ipResult.valid) {
                    Serial.println("Invalid IP");
                    return;
                }
                Serial.println(ipResult.ip);
                config.saveGatewayIP(ipResult.ip);
                do_wifi_cleanup();
                initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);
            },
            15, ip_r, false);
        free(ip_r);
        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[1243] = screen_common;
    };
    screen_builders[1244] = [] {
        static char title[] = "DNS Server";
        static char dictionary[] = "1234567890.";
        char* ip_r = IPConstructor(config.serverIP);
        static UI_GenericInput input = GI_make_input(
            title, 124, screen, dictionary, [](char* result) {
                IPValidatorResult ipResult = IPValidator(result);
                Serial.println("Saving");
                if (!ipResult.valid) {
                    Serial.println("Invalid IP");
                    return;
                }
                Serial.println(ipResult.ip);
                config.saveDNSIP(ipResult.ip);
                do_wifi_cleanup();
                initWifiInstance(config.wifiSSID, config.wifiPassword, config.serverIP);
            },
            15, ip_r, false);
        free(ip_r);
        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[1244] = screen_common;
    };
    screen_builders[13] = [] {
        static char title[] = "Network ID";
        static char dictionary[] = "1234567890";
        static UI_GenericInput input = GI_make_input(
            title, 1, screen, dictionary, [](char* result) {
                Serial.println("Saving");
                Serial.println(result);
                config.saveNetworkID(result);
            },
            3, config.networkID, true);

        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[13] = screen_common;
    };
    screen_builders[14] = [] {
        static char title[] = "Device ID";
        static char dictionary[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        static UI_GenericInput input = GI_make_input(
            title, 1, screen, dictionary, [](char* result) {
                Serial.println("Saving");
                Serial.println(result);
                config.saveDeviceID(result);
            },
            3, config.deviceID, true);

        static screen_co screen_common;
        screen_common.screen_obj = input.scr;
        screen_common.refresh_handle_t2 = ui_generic_input_handle_update;
        screen_common.type = 2;
        screen_common.ui_obj_ptr = &input;
        screens[14] = screen_common;
    };
}