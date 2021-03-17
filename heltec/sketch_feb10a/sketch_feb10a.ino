/* 
  Basic test program, send date at the BAND you seted.
  
  by Aaron.Lee from HelTec AutoMation, ChengDu, China
  成都惠利特自动化科技有限公司
  www.heltec.cn
  
  this project also realess in GitHub:
  https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series
*/

#include <heltec.h>
#include <WiFi.h>

#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

int counter = 0;

void setup() {
  
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);

  Heltec.display->clear();
}

void loop() {

  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->drawString(0, 10, WiFi.macAddress());

  Heltec.display->display();
  delay(60000);

  Heltec.display->clear();  
  
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->drawString(0, 10, "Sending a LoRa packet...");

  Heltec.display->display();
  delay(1000);                       // wait for a second
  
  Heltec.display->clear();
  
  LoRa.beginPacket();
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print("The Ragnarök awaits...");
  LoRa.print(counter);
  LoRa.endPacket();

  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->drawString(0, 10, (String)counter);

  Heltec.display->display();
  
  counter++;
  
  digitalWrite(25, HIGH);
  delay(1000);
  digitalWrite(25, LOW);
  delay(1000);

  Heltec.display->clear();
}
