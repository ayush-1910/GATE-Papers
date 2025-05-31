#define __SFR_OFFFSET 0
#include <avr/io.h>

.global inc
.section .text

inc:
	ldi r16,0x01
	mov r25, r24
	eor r25, r16

	mov r23, r22
	eor r23, r16

	mov r21, r20
	eor r21, r16

	mov r19, r18
	eor r19, r16

	mov r26, r25
	andi r26, 0b00000001 ;A

	ldi r27, 0x00
	mov r27, r25
	and r27, r22
	mov r28, r24
	and r28, r23
	and r28, r19
	or r27, r28
	lsl r27
	andi r27, 0b00000010
	or r26, r27 ;B


	mov r27, r23
	and r27, r20
	mov r28, r25
	and r28, r20
	or r27, r28
	mov r28, r24
	and r28, r22
	and r28, r21
	or r27, r28
	lsl r27
	lsl r27
	andi r27, 0b00000100
	or r26, r27 ;C

	mov r27, r25
	and r27, r18
	mov r28, r24
	and r28, r22
	and r28, r20
	or r27, r28
	lsl r27
	lsl r27
	lsl r27
	andi r27, 0b00001000
	or r26, r27 ;D

	mov r24, r26
	lsl r24
	lsl r24
	ret
