.include "/root/m328Pdef.inc"
	
	ldi r16, 0b00111100
	out DDRD, r16

	ldi r16, 0b11110000
	out DDRB, r16

Loop:
	ldi r16, 0b11111111
	out PORTB, r16
	in r16, PINB

	mov r17, r16
	andi r17, 0x01 ;W

	mov r18, r16
	andi r18, 0x02 
	lsr r18 ;X

	mov r19, r16
	andi r19, 0x04
	lsr r19
	lsr r19 ;Y

	mov r20, r16
	andi r20, 0x08
	lsr r20
	lsr r20
	lsr r20 ;Z

	mov r21, r17
	com r21
	andi r21, 0x01 ;!W


	mov r22, r18
	com r22
	andi r22, 0x01 ;!X

	mov r23, r19
	com r23
	andi r23, 0x01 ;!Y

	mov r24, r20
	com r24
	andi r24, 0x01 ;!Z

	ldi r25, 0x00
	or r25, r21  ;A

	ldi r26, 0x00
	mov r26, r17
	and r26, r22
	and r26, r24
	ldi r27, 0x00
	mov r27, r21
	and r27, r18
	or r26, r27
	lsl r26
	or r25, r26  ;B

	ldi r26, 0x00
	mov r26, r17
	and r26, r18
	and r26, r23
	ldi r27, 0x00
	mov r27, r22
	and r27, r19
	or r26, r27
	ldi r27, 0x00
	mov r27, r21
	and r27, r19
	or r26, r27
	lsl r26
	lsl r26
	or r25, r26  ;C

	ldi r26, 0x00
	mov r26, r17
	and r26, r18
	and r26, r19
	ldi r27, 0x00
	mov r27, r21
	and  r27, r20
	or r26, r27
	lsl r26
	lsl r26
	lsl r26
	or r25, r26  ;D

	lsl r25
	lsl r25
	out PORTD, r25

	rjmp loop
