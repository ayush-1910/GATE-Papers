#include <Arduino.h>
//Declaring all variables as integers
int Z=2,Y=2,X=2,W=2;
int D,C,B,A;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int S, int R, int Q, int P)
{
  digitalWrite(2, P); //LSB
  digitalWrite(3, Q); 
  digitalWrite(4, R); 
  digitalWrite(5, S); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    Serial.begin(250000);
    delay(1000);
    Serial.println("Enter W");
    while(W!=0||W!=1){
	    W=Serial.parseInt();
	}
    Serial.println("Enter X");
	while(X!=0||X!=1){
		X=Serial.parseInt();
	}
    //while(Serial.available()) Serial.read();
     Serial.println("Enter Y");
     	while(Y!=0||Y!=1){
		Y=Serial.parseInt();
	}
    //while(Serial.available()) Serial.read();
     Serial.println("Enter Z");
     	while(Z!=0||Z!=1 ){
		Z=Serial.parseInt();
	}
    //while(Serial.available()) Serial.read();
    Serial.print(W);
    Serial.print(X);
    Serial.print(Y);
    Serial.print(Z);
}
// the loop function runs over and over again forever
void loop() {
  A=!W;
  B=(!X&&W&&!Z)||(X&&!W);
  C=(Y&&(!W||!X))||(W&&X&&!Y);
  D = (W&&X&&Y)||(!W&&Z);
  
disp_7447(D,C,B,A);  
}
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
