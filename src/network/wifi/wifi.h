#ifndef _NETWORK_WIFI_H_
#define _NETWORK_WIFI_H_

void initWifiInstance(char* ssid, char* password, char* server);
void doWifiStuff(int& rssi_to_write, char* PVW_to_write, char* PGM_to_write, int& signal_state, char* networkID);
void destroyWifiInstance();
#endif