#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

class WebSockets{
  private:
    AsyncWebSocket* ws;

  public:
  
    WebSockets(String wsPath, AsyncWebServer* server, AwsEventHandler handler){
      ws = new AsyncWebSocket(wsPath);
      ws->onEvent(handler);
      server->addHandler(ws);
    }

    ~WebSockets(){
      delete ws;
    }

    
    void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
      AwsFrameInfo *info = (AwsFrameInfo*)arg;

      Serial.println((char*)data);
    }   

    AsyncWebSocket* getSocketServer(){
      return ws;
    }

};
