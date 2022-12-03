#include "Arduino.h"
#include "WebServer.hpp"
#include "WebSockets.hpp"
#include "soc/rtc_wdt.h"

WebServer* server;
WebSockets* sockets;

void setupWifi(){
  WiFi.softAP("AdarRobot");

  IPAddress IP = WiFi.softAPIP();
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
              
      switch (type) {
        case WS_EVT_CONNECT:
          Serial.println("Client Connect!");
          break;
        case WS_EVT_DISCONNECT:
          Serial.println("Client Disconnect!");
          break;
        case WS_EVT_DATA:
          sockets->handleWebSocketMessage(arg, data, len);
          break;
        case WS_EVT_PONG:
          Serial.println("Client Pong!");
          break;
        case WS_EVT_ERROR:
          Serial.println("Client Error!");
          break;
    }
}

void setup(){
  rtc_wdt_protect_off();
  rtc_wdt_disable();
  Serial.begin(115200);
  setupWifi();
  server = new WebServer();
  sockets = new WebSockets("/ws", server->server, onEvent);
}

void loop() {
  sockets->getSocketServer()->cleanupClients();
  delay(200);
}

// #include "Arduino.h"

// void setup(){

// }

// void loop(){

// }