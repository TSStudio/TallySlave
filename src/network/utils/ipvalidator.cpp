#include "ipvalidator.h"

char* IPConstructor(uint32_t ip) {
    char* result = (char*)malloc(16);
    sprintf(result, "%03d.%03d.%03d.%03d", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
    return result;
}

char* PortConstructor(uint32_t port) {
    char* result = (char*)malloc(6);
    sprintf(result, "%d", port);
    return result;
}

IPValidatorResult IPValidator(char* ip) {
    IPValidatorResult result;
    result.valid = true;
    result.ip = 0;
    int currentNum = 0;
    if (strlen(ip) < 7) {
        result.valid = false;
        return result;
    }
    int dotCount = 0;
    for (int i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') dotCount++;
        if (ip[i] != '.' && (ip[i] < '0' || ip[i] > '9')) {
            result.valid = false;
            return result;
        }
    }
    if (dotCount != 3) {
        result.valid = false;
        return result;
    }
    for (int i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            if (currentNum < 0 || currentNum > 255) {
                result.valid = false;
                return result;
            }
            result.ip = (result.ip << 8) | currentNum;
            currentNum = 0;
        } else {
            currentNum = currentNum * 10 + ip[i] - '0';
        }
    }
    if (currentNum < 0 || currentNum > 255) {
        result.valid = false;
        return result;
    }
    result.ip = (result.ip << 8) | currentNum;
    return result;
}

IPValidatorResult SubnetMaskValidator(char* mask) {
    IPValidatorResult result = IPValidator(mask);
    if (!result.valid) return result;
    uint32_t maskInt = result.ip;
    for (int i = 31; i >= 0; i--) {
        if ((maskInt >> i) & 1) {
            maskInt -= 1 << i;
        } else {
            if (maskInt != 0) {
                result.valid = false;
                return result;
            }
        }
    }
    return result;
}