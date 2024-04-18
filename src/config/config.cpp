#include "config.h"

void Configuration::initDefaultInstance() {
    Serial.println("Initializing default configuration");
    wifiSSID = (char*)malloc(16);
    wifiPassword = (char*)malloc(16);
    strcpy(wifiSSID, "Example");
    strcpy(wifiPassword, "password");
    deviceIP = 0x0A000003;  //10.0.0.3
    screen_illuminance = 0x00000200;
    serverIP = 0x0A000002;
    subnetMask = 0xFFFFFF00;
    gatewayIP = 0x0A000001;
    dnsIP = 0x0A000001;
    serverPort = 38383;
    networkID = (char*)malloc(4);
    deviceID = (char*)malloc(4);
    strcpy(networkID, "000");
    strcpy(deviceID, "A01");
    interface_type = 1;  // 0: CAN, 1: Wi-Fi, 2: LoRa
}

void Configuration::initFromEEPROM() {
    //EEPROM :
    // 0~15: wifiSSID
    // 16~31: wifiPassword
    // 32~35: serverIP
    // 36~39: subnetMask
    // 40~43: gatewayIP
    // 44~47: dnsIP
    // 48~51: serverPort
    // 52~55: networkID
    // 56~59: deviceID
    // 60: interface_type
    // 61-64: deviceIP
    // 65-68: screen_illuminance
    // 69-71: 0xFCFCFCFC -> to check if the EEPROM is initialized
    //check 69-71
    if (EEPROM.read(69) != 0xFC || EEPROM.read(70) != 0xFC || EEPROM.read(71) != 0xFC) {
        initDefaultInstance();
        saveToEEPROM();
        return;
    }
    Serial.println("Initializing configuration from EEPROM");

    wifiSSID = (char*)malloc(16);
    wifiPassword = (char*)malloc(16);
    networkID = (char*)malloc(4);
    deviceID = (char*)malloc(4);
    for (int i = 0; i < 16; i++) {
        wifiSSID[i] = EEPROM.read(i);
    }
    for (int i = 0; i < 16; i++) {
        wifiPassword[i] = EEPROM.read(i + 16);
    }
    serverIP = (EEPROM.read(32) << 24) | (EEPROM.read(33) << 16) | (EEPROM.read(34) << 8) | EEPROM.read(35);
    subnetMask = (EEPROM.read(36) << 24) | (EEPROM.read(37) << 16) | (EEPROM.read(38) << 8) | EEPROM.read(39);
    gatewayIP = (EEPROM.read(40) << 24) | (EEPROM.read(41) << 16) | (EEPROM.read(42) << 8) | EEPROM.read(43);
    dnsIP = (EEPROM.read(44) << 24) | (EEPROM.read(45) << 16) | (EEPROM.read(46) << 8) | EEPROM.read(47);
    serverPort = (EEPROM.read(48) << 24) | (EEPROM.read(49) << 16) | (EEPROM.read(50) << 8) | EEPROM.read(51);
    for (int i = 0; i < 4; i++) {
        networkID[i] = EEPROM.read(i + 52);
    }
    for (int i = 0; i < 4; i++) {
        deviceID[i] = EEPROM.read(i + 56);
    }
    interface_type = EEPROM.read(60);
    deviceIP = (EEPROM.read(61) << 24) | (EEPROM.read(62) << 16) | (EEPROM.read(63) << 8) | EEPROM.read(64);
    screen_illuminance = (EEPROM.read(65) << 24) | (EEPROM.read(66) << 16) | (EEPROM.read(67) << 8) | EEPROM.read(68);
}

void Configuration::saveToEEPROM() {
    for (int i = 0; i < 16; i++) {
        EEPROM.write(i, wifiSSID[i]);
    }
    for (int i = 0; i < 16; i++) {
        EEPROM.write(i + 16, wifiPassword[i]);
    }
    EEPROM.write(32, (serverIP >> 24) & 0xFF);
    EEPROM.write(33, (serverIP >> 16) & 0xFF);
    EEPROM.write(34, (serverIP >> 8) & 0xFF);
    EEPROM.write(35, serverIP & 0xFF);
    EEPROM.write(36, (subnetMask >> 24) & 0xFF);
    EEPROM.write(37, (subnetMask >> 16) & 0xFF);
    EEPROM.write(38, (subnetMask >> 8) & 0xFF);
    EEPROM.write(39, subnetMask & 0xFF);
    EEPROM.write(40, (gatewayIP >> 24) & 0xFF);
    EEPROM.write(41, (gatewayIP >> 16) & 0xFF);
    EEPROM.write(42, (gatewayIP >> 8) & 0xFF);
    EEPROM.write(43, gatewayIP & 0xFF);
    EEPROM.write(44, (dnsIP >> 24) & 0xFF);
    EEPROM.write(45, (dnsIP >> 16) & 0xFF);
    EEPROM.write(46, (dnsIP >> 8) & 0xFF);
    EEPROM.write(47, dnsIP & 0xFF);
    EEPROM.write(48, (serverPort >> 24) & 0xFF);
    EEPROM.write(49, (serverPort >> 16) & 0xFF);
    EEPROM.write(50, (serverPort >> 8) & 0xFF);
    EEPROM.write(51, serverPort & 0xFF);
    for (int i = 0; i < 4; i++) {
        EEPROM.write(i + 52, networkID[i]);
    }
    for (int i = 0; i < 4; i++) {
        EEPROM.write(i + 56, deviceID[i]);
    }
    EEPROM.write(60, interface_type);
    EEPROM.write(61, (deviceIP >> 24) & 0xFF);
    EEPROM.write(62, (deviceIP >> 16) & 0xFF);
    EEPROM.write(63, (deviceIP >> 8) & 0xFF);
    EEPROM.write(64, deviceIP & 0xFF);
    EEPROM.write(65, (screen_illuminance >> 24) & 0xFF);
    EEPROM.write(66, (screen_illuminance >> 16) & 0xFF);
    EEPROM.write(67, (screen_illuminance >> 8) & 0xFF);
    EEPROM.write(68, screen_illuminance & 0xFF);
    EEPROM.write(69, 0xFC);
    EEPROM.write(70, 0xFC);
    EEPROM.write(71, 0xFC);
    EEPROM.commit();
    Serial.println("Configuration saved to EEPROM");
}

void Configuration::saveDeviceIP(uint32_t ip) {
    deviceIP = ip;
    EEPROM.write(61, (deviceIP >> 24) & 0xFF);
    EEPROM.write(62, (deviceIP >> 16) & 0xFF);
    EEPROM.write(63, (deviceIP >> 8) & 0xFF);
    EEPROM.write(64, deviceIP & 0xFF);
    EEPROM.commit();
}

void Configuration::saveScreenIlluminance(uint32_t ill) {
    screen_illuminance = ill;
    EEPROM.write(65, (screen_illuminance >> 24) & 0xFF);
    EEPROM.write(66, (screen_illuminance >> 16) & 0xFF);
    EEPROM.write(67, (screen_illuminance >> 8) & 0xFF);
    EEPROM.write(68, screen_illuminance & 0xFF);
    EEPROM.commit();
}

void Configuration::saveWifiSSID(char* ssid) {
    strcpy(wifiSSID, ssid);
    for (int i = 0; i < 16; i++) {
        EEPROM.write(i, wifiSSID[i]);
    }
    EEPROM.commit();
}

void Configuration::saveWifiPassword(char* password) {
    strcpy(wifiPassword, password);
    for (int i = 0; i < 16; i++) {
        EEPROM.write(i + 16, wifiPassword[i]);
    }
    EEPROM.commit();
}

void Configuration::saveServerIP(uint32_t ip) {
    serverIP = ip;
    EEPROM.write(32, (serverIP >> 24) & 0xFF);
    EEPROM.write(33, (serverIP >> 16) & 0xFF);
    EEPROM.write(34, (serverIP >> 8) & 0xFF);
    EEPROM.write(35, serverIP & 0xFF);
    EEPROM.commit();
}

void Configuration::saveSubnetMask(uint32_t mask) {
    subnetMask = mask;
    EEPROM.write(36, (subnetMask >> 24) & 0xFF);
    EEPROM.write(37, (subnetMask >> 16) & 0xFF);
    EEPROM.write(38, (subnetMask >> 8) & 0xFF);
    EEPROM.write(39, subnetMask & 0xFF);
    EEPROM.commit();
}

void Configuration::saveGatewayIP(uint32_t ip) {
    gatewayIP = ip;
    EEPROM.write(40, (gatewayIP >> 24) & 0xFF);
    EEPROM.write(41, (gatewayIP >> 16) & 0xFF);
    EEPROM.write(42, (gatewayIP >> 8) & 0xFF);
    EEPROM.write(43, gatewayIP & 0xFF);
    EEPROM.commit();
}

void Configuration::saveDNSIP(uint32_t ip) {
    dnsIP = ip;
    EEPROM.write(44, (dnsIP >> 24) & 0xFF);
    EEPROM.write(45, (dnsIP >> 16) & 0xFF);
    EEPROM.write(46, (dnsIP >> 8) & 0xFF);
    EEPROM.write(47, dnsIP & 0xFF);
    EEPROM.commit();
}

void Configuration::saveServerPort(uint32_t port) {
    serverPort = port;
    EEPROM.write(48, (serverPort >> 24) & 0xFF);
    EEPROM.write(49, (serverPort >> 16) & 0xFF);
    EEPROM.write(50, (serverPort >> 8) & 0xFF);
    EEPROM.write(51, serverPort & 0xFF);
    EEPROM.commit();
}

void Configuration::saveNetworkID(char* id) {
    strcpy(networkID, id);
    for (int i = 0; i < 4; i++) {
        EEPROM.write(i + 52, networkID[i]);
    }
    EEPROM.commit();
}

void Configuration::saveDeviceID(char* id) {
    strcpy(deviceID, id);
    for (int i = 0; i < 4; i++) {
        EEPROM.write(i + 56, deviceID[i]);
    }
    EEPROM.commit();
}

void Configuration::saveInterfaceType(unsigned char type) {
    interface_type = type;
    EEPROM.write(60, interface_type);
    EEPROM.commit();
}