#include <heltec.h>
#include <WiFi.h>

const char* ssid     = "Livebox-681C";
const char* password = "43E13C340F4222E66C12499CE7";

#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

void setup() {
  
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);

  Heltec.display->clear();

  WiFi.begin(ssid, password);

  delay(10000);

  if(WiFi.status() == WL_CONNECTED) {

    while(true) {
      
      Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
      Heltec.display->setFont(ArialMT_Plain_10);
      Heltec.display->drawString(0, 10, "Connection to Wifi successful...");
      Heltec.display->display();

      delay(5000);
      Heltec.display->clear();
      
      Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
      Heltec.display->setFont(ArialMT_Plain_10);
      Heltec.display->drawString(0, 10, "MAC: " + WiFi.macAddress());
      Heltec.display->display();

      delay(5000);
      Heltec.display->clear();

      Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
      Heltec.display->setFont(ArialMT_Plain_10);
      Heltec.display->drawString(0, 10, "Local IP: " + WiFi.localIP().toString());
      Heltec.display->display();

      delay(5000);
      Heltec.display->clear();

      Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
      Heltec.display->setFont(ArialMT_Plain_10);
      Heltec.display->drawString(0, 10, "Subnet mask: " + WiFi.subnetMask().toString());
      Heltec.display->display();

      delay(5000);
      Heltec.display->clear();

      Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
      Heltec.display->setFont(ArialMT_Plain_10);
      Heltec.display->drawString(0, 10, "Gateway IP: " + WiFi.gatewayIP().toString());
      Heltec.display->display();

      delay(5000);
      Heltec.display->clear();
    }
    
  } else if(WiFi.status() == WL_NO_SHIELD) {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "No shield available for Wifi connection...");

    Heltec.display->display();
    
  } else if(WiFi.status() == WL_CONNECT_FAILED) {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "Connection to Wifi failed...");

    Heltec.display->display();

  } else if(WiFi.status() == WL_NO_SSID_AVAIL) {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "No Wifi network available...");

    Heltec.display->display();
    
  } else if(WiFi.status() == WL_SCAN_COMPLETED) {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "Scan of all Wifi networks completed...");

    Heltec.display->display();
    
  } else if(WiFi.status() == WL_CONNECTION_LOST) {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "Wifi connection lost...");

    Heltec.display->display();
    
  } else if(WiFi.status() == WL_DISCONNECTED) {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "Wifi connection disconnected...");

    Heltec.display->display();
    
  } else {

    Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
    Heltec.display->setFont(ArialMT_Plain_10);
    Heltec.display->drawString(0, 10, "Sending a LoRa packet...");

    Heltec.display->display();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
