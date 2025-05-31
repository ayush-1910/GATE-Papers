#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>

extern uint8_t inc(uint8_t,uint8_t,uint8_t,uint8_t);

int main(void) {
bool W,X,Y,Z;
DDRD=0b00111100;
DDRB=0b00100000;
PORTB=0b00001111;

while(1) {
PORTB=((1<<PB5));
_delay_ms(200L);

W=(PINB & (1<<PINB0))==(1<<PINB0);
X=(PINB & (1<<PINB1))==(1<<PINB1);
Y=(PINB & (1<<PINB2))==(1<<PINB2);
Z=(PINB & (1<<PINB3))==(1<<PINB3);

uint8_t Out=inc(W,X,Y,Z);
PORTD=Out;

PORTB=((0<<PB5));
_delay_ms(200L);
}
return 0;
}
