#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <cstring>
#include <EEPROM.h>

class Configuration {
public:
    char* wifiSSID;
    char* wifiPassword;
    unsigned int serverIP;
    unsigned int subnetMask;
    unsigned int gatewayIP;
    unsigned int dnsIP;  // NO
    unsigned int serverPort;
    char* networkID;
    char* deviceID;
    unsigned char interface_type;
    void initDefaultInstance();
    void initFromEEPROM();
    void saveToEEPROM();
    void destroyInstance();
};

#endif