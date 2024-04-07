#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <cstring>
#include <EEPROM.h>
#include <Arduino.h>

class Configuration {
public:
    char* wifiSSID;
    char* wifiPassword;
    uint32_t serverIP;
    uint32_t subnetMask;
    uint32_t gatewayIP;
    uint32_t dnsIP;  // NO
    uint32_t serverPort;
    char* networkID;
    char* deviceID;
    unsigned char interface_type;
    void initDefaultInstance();
    void initFromEEPROM();
    void saveToEEPROM();

    void saveWifiSSID(char* ssid);
    void saveWifiPassword(char* password);
    void saveServerIP(uint32_t ip);
    void saveSubnetMask(uint32_t mask);
    void saveGatewayIP(uint32_t ip);
    void saveDNSIP(uint32_t ip);
    void saveServerPort(uint32_t port);
    void saveNetworkID(char* id);
    void saveDeviceID(char* id);
    void saveInterfaceType(unsigned char type);
};

#endif