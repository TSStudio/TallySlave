#ifndef _IPVALIDATOR_H_
#define _IPVALIDATOR_H_

#include <Arduino.h>

struct IPValidatorResult {
    bool valid;
    uint32_t ip;
};

char* IPConstructor(uint32_t ip);
char* PortConstructor(uint32_t port);

IPValidatorResult IPValidator(char* ip);
IPValidatorResult SubnetMaskValidator(char* mask);

#endif