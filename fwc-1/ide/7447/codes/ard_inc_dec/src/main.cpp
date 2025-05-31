#include <Arduino.h>

int A,B,C,D,W,X,Y,Z,a,b,c,d,e,f,g;

void setup(){
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}

void loop(){
W=digitalRead(2);
X=digitalRead(3);
Y=digitalRead(4);
Z=digitalRead(5);

/*A=!W;
B=(W&&!X&&!Z)||(X&&!W);
C=(Y&&!X)||(!W&&Y)||(W&&X&&!Y);
D=(!W&&Z)||(W&&X&&Y);*/

a=(!W&&!X&&!Y&&!Z)||(W&&X&&!Y&&!Z);
b=(!W&&!X&&Y&&!Z)||(W&&!X&&Y&&!Z);
c=(W&&!X&&!Y&&!Z);
d=(!W&&!X&&!Y&&!Z)||(W&&X&&!Y&&!Z)||(!W&&X&&Y&&!Z);
e=(!W&&!X&&!Y&&!Z)||(!W&&X&&!Y&&!Z)||(W&&X&&!Y&&!Z)||(!W&&!X&&Y&&!Z)||(!W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);
f=(!W&&!X&&!Y&&!Z)||(W&&!X&&!Y&&!Z)||(!W&&X&&!Y&&!Z)||(!W&&X&&Y&&!Z);
g=(!W&&!X&&!Y&&!Z)||(!W&&X&&Y&&!Z)||(W&&!Y&&!X&&Z);

digitalWrite(6,a);
digitalWrite(7,b);
digitalWrite(8,c);
digitalWrite(9,d);
digitalWrite(10,e);
digitalWrite(11,f);
digitalWrite(12,g);
}
