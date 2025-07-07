

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
int A=0, B=0, C=0, X=0, Y=0;

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
//	pinMode(2, OUTPUT);	

	pinMode(15, OUTPUT);	
	pinMode(16, OUTPUT);	
	pinMode(12, INPUT);	
	pinMode(13, INPUT);	
	pinMode(14, INPUT);	
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  	/*digitalWrite(2, HIGH);
	delay(100);
	digitalWrite(2, LOW);
	delay(100);*/
  
  A = digitalRead(14);
  B = digitalRead(13);
  C = digitalRead(12);
  X=((A || B || !C) && (A || !B || !C) && (!A || B || C) && (!A || !B || !C));

  Y=((!A && !B && !C) || (!A && B && !C) || (A && !B && C) || (A && B && !C));
  digitalWrite(15,X);
  digitalWrite(16,Y);

}


