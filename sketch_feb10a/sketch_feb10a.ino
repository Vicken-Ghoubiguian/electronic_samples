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
  
  //WIFI Kit series V1 not support Vext control
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
  
  // send packet
  LoRa.beginPacket();
/*
* LoRa.setTxPower(txPower,RFOUT_pin);
* txPower -- 0 ~ 20
* RFOUT_pin could be RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
*   - RF_PACONFIG_PASELECT_PABOOST -- LoRa single output via PABOOST, maximum output 20dBm
*   - RF_PACONFIG_PASELECT_RFO     -- LoRa single output via RFO_HF / RFO_LF, maximum output 14dBm
*/
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print("The Ragnarök awaits...");
  LoRa.print(counter);
  LoRa.endPacket();

  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->drawString(0, 10, (String)counter);

  Heltec.display->display();
  
  counter++;
  
  digitalWrite(25, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  Heltec.display->clear();
}
