#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <cstring>
#include <EEPROM.h>

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
    void destroyInstance();
};

#endif