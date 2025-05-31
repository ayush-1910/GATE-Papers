.include "/root/m328Pdef.inc"

ldi r16, 0b00100001
out DDRB, r16

ldi r16, 0b11110011
out DDRD, r16

ldi r16, 0
out SREG, r16
ldi r16, high(RAMEND)
out SPH, r16
ldi r16, low(RAMEND)
out SPL, r16

ldi r18, 0b00000000
ldi r19, 0b00100000

Loop:

in r16, PIND
andi r16, 0b00001100

mov r17, r16
andi r16, 0b00000100
lsr r16
lsr r16
andi r17, 0b00001000
lsr r17
lsr r17
lsr r17
eor r16, r17
andi r16, 0b00000001

eor r18, r19
or r16, r18
out PORTB, r16
call PAUSE
rjmp Loop

PAUSE:
push r20
push r21
push r22

ldi r20,0x50
ldi r21, 0x00
ldi r22, 0x00

w:
dec r22
brne w
dec r21
brne w
dec r20
brne w
pop r22
pop r21
pop r20
ret
