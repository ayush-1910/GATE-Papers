#include<Arduino.h>
int A=0,B=0,C=0,D=0,Y;

void setup(){
Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
}

void loop(){
A=digitalRead(3);
B=digitalRead(4);
C=digitalRead(5);
D=digitalRead(6);
Y=D||(!D&&A&&!A&&((B&&!C)||(C&&!B)));
digitalWrite(2,Y);
Serial.print(Y);
}
