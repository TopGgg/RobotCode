#include "FS.h"
#include "SD_MMC.h"

class SDCard{
public:
  static void begin() {
  
    if (!SD_MMC.begin()) {
      //TODO: Notify the use about the error
      return;
    }
    uint8_t cardType = SD_MMC.cardType();
    if (cardType == CARD_NONE) {
      //TODO: Notify the use about the error
      return;
    }
  
  }

  static void write(String path, String content){
    fs::FS &fs = SD_MMC;
    File file = fs.open(path.c_str(), FILE_WRITE);
    if (!file) {
      //TODO: Notify the use about the error
    }
    else {
      file.print(content);
    }
    // Close the file
    file.close(); 
  }

  static void deleteFile(String path){
    fs::FS &fs = SD_MMC;
    fs.remove(path);
  }

  static String read(String path){
    fs::FS &fs = SD_MMC; 
    File file = fs.open(path);

    String buffer = "";
 
    if(!file){
        return "Error!";
    }
 
 
    while(file.available()){
 
      buffer += file.readString();
    }
 
    file.close();
    return buffer;
  }


private:
  SDCard();

};