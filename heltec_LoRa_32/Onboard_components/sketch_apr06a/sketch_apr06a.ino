/*
 * 
 * 
 */

#include <heltec.h>
#include <WiFi.h>

const char* ssid     = "Livebox-681C";
const char* password = "43E13C340F4222E66C12499CE7";

int connectionCount = 0; 

#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

WiFiServer server(80);

//
void setup() {

  // put your setup code here, to run once:
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

  //
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);

  //
  Heltec.display->clear();

  //
  WiFi.begin(ssid, password);

  //
  delay(10000);
}

//
void loop() {
  
  //
  if(WiFi.status() == WL_CONNECTED){

    //
    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 0, "Connection to Wifi successful...");

    //
    WiFiClient client = server.available();
    
    //
    if(client){
      
      connectionCount = connectionCount + 1;
    }

    //
    Heltec.display->drawString(0, 10, "Connection count: " + String(connectionCount));

    //
    Heltec.display->drawString(0, 20, "==============================");

    //
    Heltec.display->drawString(0, 30, "Local IP: " + WiFi.localIP().toString());
    Heltec.display->drawString(0, 40, "MAC: " + WiFi.macAddress());

    //
    Heltec.display->display();
  
    //
    Heltec.display->clear();
    
  } else {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 0, "Sorry, but not connected...");
  
    Heltec.display->display();

    //
    WiFi.begin(ssid, password);

    //
    delay(10000);

    //
    Heltec.display->clear();
  }
}
