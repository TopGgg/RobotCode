#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SDCard.hpp"
#include <WiFi.h>

#define MODEDIR "/DATA/MODE~1.WEB"

class WebServer{
public:
  AsyncWebServer* server;
  WebServer(){
    SDCard::begin();
    server = new AsyncWebServer(80);
    setupEndpoints();
    server->begin();
  }
  ~WebServer(){
    delete server;
  }
private:
  void setupEndpoints(){
    server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", SDCard::read("/WEB/INDEX~1.HTM").c_str());
    });
    server->on("/main.js", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", SDCard::read("/WEB/MAIN.JS").c_str());
    });
    server->on("/joy.min.js", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", SDCard::read("/WEB/JOYMIN~1.JS").c_str());
    });
    server->on("/getMode", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", SDCard::read(MODEDIR).c_str());
    });
    server->on("/switchMode", HTTP_GET, [](AsyncWebServerRequest *request){
      String mode = SDCard::read(MODEDIR);
      if(mode == "manual"){
        SDCard::deleteFile(MODEDIR);
        SDCard::write(MODEDIR, "autonomous");
      }else if(mode == "autonomous"){
        SDCard::deleteFile(MODEDIR);
        SDCard::write(MODEDIR, "manual");
      }else {
        //if there is an error, set manual mode.
        SDCard::deleteFile(MODEDIR);
        SDCard::write(MODEDIR, "manual");
      }

      request->send_P(200, "text/html", SDCard::read(MODEDIR).c_str());
    });

    // server->on("/camImg", HTTP_GET, [](AsyncWebServerRequest *request){
    //     auto frame = esp32cam::capture();

    //     request->send_P(200,"image/jpeg", frame->data(), frame->size());

    //     // request->setContentLength(frame->size());
    //     // request->send(200, "image/jpeg");
    //     // WiFiClient client = server->client();
    //     // frame->writeTo(client);
    // });
  }
};