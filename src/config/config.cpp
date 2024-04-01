#include "config.h"

void Configuration::initDefaultInstance() {
    wifiSSID = (char*)malloc(16);
    wifiPassword = (char*)malloc(16);
    strcpy(wifiSSID, "Example");
    strcpy(wifiPassword, "password");
    serverIP = 0x0A000002;
    subnetMask = 0xFFFFFF00;
    gatewayIP = 0x0A000001;
    dnsIP = 0x0A000001;
    serverPort = 38383;
    networkID = (char*)malloc(4);
    deviceID = (char*)malloc(4);
    strcpy(networkID, "000");
    strcpy(deviceID, "A01");
    interface_type = 1;  // 0: CAN, 1: WiFi, 2: LoRa
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
    // 61-63: 0xFCFCFCFC -> to check if the EEPROM is initialized
    //check 60-63
    if (EEPROM.read(61) != 0xFC || EEPROM.read(62) != 0xFC || EEPROM.read(63) != 0xFC) {
        initDefaultInstance();
        saveToEEPROM();
        return;
    }

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
}

void Configuration::saveToEEPROM() {
    EEPROM.begin(72);
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
    EEPROM.write(61, 0xFC);
    EEPROM.write(62, 0xFC);
    EEPROM.write(63, 0xFC);
    EEPROM.commit();
}