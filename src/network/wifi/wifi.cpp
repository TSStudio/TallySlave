#include <WiFi.h>
#define SERVICE_PORT 38383

unsigned int reconnect_retry;
unsigned int last_retry_time;

unsigned int reconnect_tcp_retry;

char* server_addr;

unsigned int last_measured_rssi_time;
int last_measured_rssi;

unsigned int last_heartbeat_time;

WiFiClient client;

void sendHeartbeat() {
    Serial.println("Sending heartbeat...");
    if (client.connected()) {
        client.write("HEARTBEAT", 9);
        client.flush();
    }
}

void initWifiInstance(char* ssid, char* password, char* server) {
    WiFi.setHostname("T-TALLY-PROTOTYPE");
    WiFi.begin(ssid, password);
    server_addr = server;
    reconnect_retry = 0;
    last_retry_time = millis();
    reconnect_tcp_retry = 0;
}

void doWifiStuff(int& rssi_to_write, char* PVW_to_write, char* PGM_to_write, int& signal_state) {
    if (WiFi.status() != WL_CONNECTED) {
        signal_state = 0;
    }
    if (!!client.connected()) {
        signal_state = 1;
    }
    if (WiFi.status() == WL_CONNECT_FAILED || WiFi.status() == WL_CONNECTION_LOST || WiFi.status() == WL_DISCONNECTED && (((millis() - last_retry_time > 10000 || millis() < last_retry_time) && reconnect_retry < 5) || reconnect_retry == 0)) {
        reconnect_retry++;
        last_retry_time = millis();
        Serial.println("Reconnecting to WiFi...");
        WiFi.reconnect();
        return;
    }
    if (WiFi.status() == WL_CONNECTED) {
        reconnect_retry = 0;
    }
    if (!client.connected() && (((millis() - last_retry_time > 10000 || millis() < last_retry_time) && reconnect_tcp_retry < 5) || reconnect_tcp_retry == 0)) {
        reconnect_tcp_retry++;
        last_retry_time = millis();
        Serial.println("Reconnecting to TCP server...");
        client.connect(server_addr, SERVICE_PORT);
        return;
    }
    if (client.connected()) {
        reconnect_tcp_retry = 0;
    }
    if (WiFi.status() != WL_CONNECTED) {
        return;
    }
    if (millis() - last_measured_rssi_time > 10000 || millis() < last_measured_rssi_time) {
        last_measured_rssi_time = millis();
        last_measured_rssi = WiFi.RSSI();
        rssi_to_write = last_measured_rssi;
        Serial.printf("RSSI: %d\n", last_measured_rssi);
    }
    if (!client.connected()) {
        return;
    }
    signal_state = 2;
    if (millis() - last_heartbeat_time > 10000 || millis() < last_heartbeat_time) {
        last_heartbeat_time = millis();
        sendHeartbeat();
    }
    size_t len = client.available();
    if (len == 0) {
        return;
    }
    char* buffer = (char*)malloc(len);
    while (client.available()) {
        client.readBytes(buffer, len);
    }
    Serial.printf("Received %d bytes\n", len);
    for (int i = 0; i < len; i++) {
        Serial.printf("%d ", buffer[i]);
    }
    int datas = 0;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == 2) {
            datas++;
        }
    }
    int* dataBegins = (int*)malloc(datas * sizeof(int));
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == 2) {
            dataBegins[j++] = i + 1;
        }
    }
    if (!datas) return;
    for (int k = 0; k < datas; ++k) {
        int dataBegin = dataBegins[k];
        if (len - dataBegin < 6) return;
        if (buffer[dataBegin] == 'P' && buffer[dataBegin + 1] == 'V' && buffer[dataBegin + 2] == 'W') {
            Serial.println("Reading PVW data...");
            for (int i = 0; i < 3; i++) {
                PVW_to_write[i] = buffer[dataBegin + 3 + i];
            }
        }
        if (buffer[dataBegin] == 'P' && buffer[dataBegin + 1] == 'G' && buffer[dataBegin + 2] == 'M') {
            Serial.println("Reading PGM data...");
            for (int i = 0; i < 3; i++) {
                PGM_to_write[i] = buffer[dataBegin + 3 + i];
            }
        }
    }
    free(dataBegins);
    free(buffer);
}

void destroyWifiInstance() {
    WiFi.disconnect(true, true);
}