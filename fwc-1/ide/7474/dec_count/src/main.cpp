#include<Arduino.h>

int a,b,c,d,A,B,C,D;

void setup(){
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(LED_BUILTIN,OUTPUT);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(LED_BUILTIN,LOW);
delay(1000);
}

void loop(){
if (digitalRead(LED_BUILTIN)==0){
digitalWrite(LED_BUILTIN,HIGH);}
else{
digitalWrite(LED_BUILTIN,LOW);}

//digitalWrite(LED_BUILTIN,HIGH);
delay(1000);

a=digitalRead(6);
b=digitalRead(7);
c=digitalRead(8);
d=digitalRead(9);
//digitalWrite(LED_BUILTIN,LOW);

A=!a;
B=(a&&!b&&!d)||(!a&&b);
C=(!b&&c)||(!a&&c)||(a&&b&&!c);
D=(!a&&d)||(a&&b&&c);

digitalWrite(2,A);
digitalWrite(3,B);
digitalWrite(4,C);
digitalWrite(5,D);

delay(1000);
}
