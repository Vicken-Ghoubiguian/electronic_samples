/*
 * 
 * 
 */

#include <heltec.h>
#include <WiFi.h>

const char* ssid     = "Livebox-681C";
const char* password = "43E13C340F4222E66C12499CE7";

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
  // put your main code here, to run repeatedly:

  //
  if(WiFi.status() == WL_CONNECTED){

    //
    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "Connection to Wifi successful...");

    //
    WiFiClient httpClient = server.available();
    
    //
    if(httpClient){
      
      Heltec.display->drawString(10, 0, "New Client...MIRACLE...");
      Heltec.display->display();
      
    } else {
  
      Heltec.display->drawString(10, 0, "No clients...Snif...Snif...");
      Heltec.display->display();
    }
  
    //
    Heltec.display->clear();
    
  } else {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "Sorry, but not connected...");
  
    Heltec.display->display();
  }
}