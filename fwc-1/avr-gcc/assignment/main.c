
#include <avr/io.h>

#include <util/delay.h>

#include <stdbool.h>




int main (void)

{

 bool Q1=0, Q2=0;
 bool J1, K1, J2, K2, T1, T2;

 DDRD = 0b00001100;
 while(1) {
 PORTD &= ~(0b00001100);
 PORTD |= (Q1<<2)|(Q2<<3);
 T1=Q1;
 T2=Q2;
 K1=(!Q1 || !Q2);
 J1=(Q1 || Q2);
 J2=(!Q1 || Q2);
 K2=(Q1 || !Q2);
 Q1=((J1&&!T1) || (!K1&&T1));
 Q2=((J2&&!T2) || (!K2&&T2));

 _delay_ms (2000);

 }
return 0;
}
