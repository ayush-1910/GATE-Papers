//Code by GVV Sharma
//April 24, 2022
//https://www.gnu.org/licenses/gpl-3.0.en.html
//
#include <Arduino.h>


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT);
 // pinMode(14, OUTPUT);
  //pinMode(15, OUTPUT);
//  pinMode(9,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage leve
delay(2000);
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage leve

delay(2000);

}
