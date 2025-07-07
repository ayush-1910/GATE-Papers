

//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "Ayush"  // Replace with your network credentials
#define STAPSK  "asdfghjkl"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
	pinMode(7, OUTPUT);	
	pinMode(8, OUTPUT);	
	pinMode(4, INPUT);	
	pinMode(5, INPUT);	
	pinMode(6, INPUT);	

}

void loop() {
  OTAloop();
  delay(10);
  bool A = digitalRead(4);
  bool B = digitalRead(5);
  bool C = digitalRead(6);
  bool X=((A || B || !C) && (A || !B || !C) && (!A || B || C) && (!A || !B || !C));
  bool Y=((!A && !B && !C) || (!A && B && !C) || (A && !B && C) || (A && B && !C));
  digitalWrite(7,X);
  digitalWrite(8,Y);

}
