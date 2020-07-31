#include <config.h>


//zmienne
.extern sTime

#ifndef disable_secondProgram
	.extern sDelay
	.extern ProgramCounter
#endif

#ifndef disable_volume
	.extern sVolume
#endif

#ifdef enable_motor
	.extern sMotorA
	#if channel == 2
		.extern sMotorB
	#endif
#endif



.global synthSetup
synthSetup:
ldi r25, 131
out 0x23, r25//GTCCR
#ifdef timer0
	ldi r25, 1
	out 0x25, r25//TCCR0B
	ldi r25, 163
	out 0x24, r25//TCCR0A
	clr r25
	out 0x26, r25//TCNT0
#endif
#ifdef timer1
	ldi r25, 9
	sts 0x81, r25//TCCR1B
	ldi r25, 161
	sts 0x80, r25//TCCR1A
	clr r25
	sts 0x85, r25//TCNT1H
	sts 0x84, r25//TCNT1L
#endif
#ifdef timer2
	ldi r25, 1
	sts 0xB1, r25//TCCR2B
	ldi r25, 163
	sts 0xB0, r25//TCCR2A
	clr r25
	sts 0xB2, r25//TCNT2
#endif
clr r25
out 0x23, r25//GTCCR
//DDRD
#ifdef sPin2
	sbi 0x0A, 2
#endif
#ifdef sPin3
	sbi 0x0A, 3
#endif
#ifdef sPin4
	sbi 0x0A, 4
#endif
#ifdef sPin5
	sbi 0x0A, 5
#endif
#ifdef sPin6
	sbi 0x0A, 6
#endif
#ifdef sPin7
	sbi 0x0A, 7
#endif
//DDRB
#ifdef sPin8
	sbi 0x04, 0
#endif
#ifdef sPin9
	sbi 0x04, 1
#endif
#ifdef sPin10
	sbi 0x04, 2
#endif
#ifdef sPin11
	sbi 0x04, 3
#endif
#ifdef sPin12
	sbi 0x04, 4
#endif
#ifdef sPin13
	sbi 0x04, 5
#endif
#ifndef disable_volume	
	ser r25
	sts (sVolume), 25
#endif
#ifdef enable_ADC
	lds r25, 0x7C//ADMUX
	andi r25, 0x1F
	ori r25, 0x60
	sts 0x7C, r25//ADMUX
	ldi r25, 0xF3
	sts 0x7A, r25//ADCSRA
#endif
rcall reset
rcall play
ret



//ewentualnie zapisaæ pc przez stos mikrkontrolera
#ifndef disable_secondProgram
	.extern secondprogram
	setPC:
	ldi r25, lo8(pm(secondprogram))
	sts (ProgramCounter), r25
	ldi r25, hi8(pm(secondprogram))
	sts (ProgramCounter+1), r25
	ret
#endif



.global reset
reset:
ser r25
sts (sTime), r25
#ifndef disable_secondProgram
	sts (sTime+1), r25
	sts (sTime+2), r25
	sts (sTime+3), r25
	sts (sDelay), r25
	sts (sDelay+1), r25
	sts (sDelay+2), r25
	sts (sDelay+3), r25
	rcall setPC
#endif
ret



.global stop
stop:
rcall pause
rcall reset
ret



.global play
play:
asm_LTI_25
ori r25, 1
asm_STI_25
ret



.global pause
pause:
asm_LTI_25
andi r25, 254
asm_STI_25
#ifdef enable_motor
	lds r24, (sMotorA)
#else
	clr r24
#endif
rcall setA
#if channel == 2
	#ifdef enable_motor
		lds r24, (sMotorB)
	#endif
	rcall setB
#endif
ret



#ifdef enable_motor
	.global motorA
	motorA:
	//bst r25, 7
	//bld r24, 7
	sts (sMotorA), r24
	asm_LTI_25
	sbrs r25, 0
	rcall setA
	ret

	#if channel == 2
		.global motorB
		motorB:
		//bst r25, 7
		//bld r24, 7
		sts (sMotorB), r24
		asm_LTI_25
		sbrs r25, 0
		rcall setB
		ret	
	#endif
#endif



setA:
#if mode == 1
	subi r24, 128
	asm_PWM1_24
#endif
#if mode == 2
	sbrs r24, 7
	rjmp pinPlusA
	com r24
	lsl r24
	asm_PWM1_24
	asm_Cpin1
	asm_Spin2
	ret
	pinPlusA:
	cpi r24, 0
	breq pinZeroA
	lsl r24
	asm_PWM1_24
	asm_Cpin2
	asm_Spin1
	ret
	pinZeroA:
	asm_PWM1_24
	asm_Cpin1
	asm_Cpin2
#endif
#if mode == 3
	sbrs r24, 7
	rjmp pinPlusA
	com r24
	lsl r24
	asm_PWM2_24
	clr r24
	asm_PWM1_24
	ret
	pinPlusA:
	lsl r24
	asm_PWM1_24
	clr r24
	asm_PWM2_24
#endif
ret



#if channel == 2
	setB:
	#if mode == 1
		subi r24, 128
		asm_PWM2_24
	#endif
	#if mode == 2
		sbrs r24, 7
		rjmp pinPlusB
		com r24
		lsl r24
		asm_PWM2_24
		asm_Cpin3
		asm_Spin4
		ret
		pinPlusB:
		cpi r24, 0
		breq pinZeroB
		lsl r24
		asm_PWM2_24
		asm_Cpin4
		asm_Spin3
		ret
		pinZeroB:
		asm_PWM2_24
		asm_Cpin3
		asm_Cpin4
	#endif
	#if mode == 3
		sbrs r24, 7
		rjmp pinPlusB
		com r24
		lsl r24
		asm_PWM4_24
		clr r24
		asm_PWM3_24
		ret
		pinPlusB:
		lsl r24
		asm_PWM3_24
		clr r24
		asm_PWM4_24
	#endif
	ret
#endif



#ifndef disable_volume
	.global volume
	volume:
	sts (sVolume), r24
	ret
#endif



.global ADCchannel
ADCchannel:
andi r24, 0x1F
lds r25, 0x7C//ADMUX
andi r25, 0xE0
or r25, r24
sts 0x7C, r25//ADMUX
ret



.global get_ci
get_ci:
#ifdef disable_secondProgram
	lds r24, (sTime)
	ret
#else
	push r21
	in r21, 0x3F//SREG
	cli
	lds r25, (sTime+3)
	lds r24, (sTime+2)
	lds r23, (sTime+1)
	lds r22, (sTime)
	out 0x3F, r21//SREG
	pop r21
	ret

	.global delay_ci
	delay_ci:
	cli
	lds r21, (sTime)
	add r22, r21
	lds r21, (sTime+1)
	adc r23, r21
	lds r21, (sTime+2)
	adc r24, r21
	lds r21, (sTime+3)
	adc r25, r21
	sts (sDelay+3), r25
	sts (sDelay+2), r24
	sts (sDelay+1), r23
	sts (sDelay), r22
	pop r25
	sts (ProgramCounter+1), r25
	pop r25
	sts (ProgramCounter), r25
	sei
	#ifndef enable_quickProgramChange
		pop r0
		pop r1
		pop r2
		pop r3
		pop r4
		pop r5
		pop r6
		pop r7
		pop r8
		pop r9
		pop r10
		pop r11
		pop r12
		pop r13
		pop r14
		pop r15
		pop r16
		pop r17
		pop r18
		pop r19
		pop r20
		pop r26
		pop r27
		pop r28
		pop r29
		pop r30
		pop r31
	#endif
	pop r21
	pop r22
	pop r23
	pop r24
	pop r25
	out 0x3F, r25//SREG
	pop r25
	reti
#endif



//funkcje fal
#ifndef lowProgramMemory
	#if polyphony > 0
		.extern w01
		.global wave01_volume
		wave01_volume:
		sts (w01+4), r24
		ret

		.global wave01_phase
		wave01_phase:
		sts (w01+1), r25
		sts (w01), r24
		ret

		.global wave01_frequency
		wave01_frequency:
		sts (w01+3), r25
		sts (w01+2), r24
		ret
	#endif


	#if polyphony > 1
		.extern w02
		.global wave02_volume
		wave02_volume:
		sts (w02+4), r24
		ret

		.global wave02_phase
		wave02_phase:
		sts (w02+1), r25
		sts (w02), r24
		ret

		.global wave02_frequency
		wave02_frequency:
		sts (w02+3), r25
		sts (w02+2), r24
		ret
	#endif


	#if polyphony > 2
		.extern w03
		.global wave03_volume
		wave03_volume:
		sts (w03+4), r24
		ret

		.global wave03_phase
		wave03_phase:
		sts (w03+1), r25
		sts (w03), r24
		ret

		.global wave03_frequency
		wave03_frequency:
		sts (w03+3), r25
		sts (w03+2), r24
		ret
	#endif


	#if polyphony > 3
		.extern w04
		.global wave04_volume
		wave04_volume:
		sts (w04+4), r24
		ret

		.global wave04_phase
		wave04_phase:
		sts (w04+1), r25
		sts (w04), r24
		ret

		.global wave04_frequency
		wave04_frequency:
		sts (w04+3), r25
		sts (w04+2), r24
		ret
	#endif


	#if polyphony > 4
		.extern w05
		.global wave05_volume
		wave05_volume:
		sts (w05+4), r24
		ret

		.global wave05_phase
		wave05_phase:
		sts (w05+1), r25
		sts (w05), r24
		ret

		.global wave05_frequency
		wave05_frequency:
		sts (w05+3), r25
		sts (w05+2), r24
		ret
	#endif


	#if polyphony > 5
		.extern w06
		.global wave06_volume
		wave06_volume:
		sts (w06+4), r24
		ret

		.global wave06_phase
		wave06_phase:
		sts (w06+1), r25
		sts (w06), r24
		ret

		.global wave06_frequency
		wave06_frequency:
		sts (w06+3), r25
		sts (w06+2), r24
		ret
	#endif


	#if polyphony > 6
		.extern w07
		.global wave07_volume
		wave07_volume:
		sts (w07+4), r24
		ret

		.global wave07_phase
		wave07_phase:
		sts (w07+1), r25
		sts (w07), r24
		ret

		.global wave07_frequency
		wave07_frequency:
		sts (w07+3), r25
		sts (w07+2), r24
		ret
	#endif


	#if polyphony > 7
		.extern w08
		.global wave08_volume
		wave08_volume:
		sts (w08+4), r24
		ret

		.global wave08_phase
		wave08_phase:
		sts (w08+1), r25
		sts (w08), r24
		ret

		.global wave08_frequency
		wave08_frequency:
		sts (w08+3), r25
		sts (w08+2), r24
		ret
	#endif


	#if polyphony > 8
		.extern w09
		.global wave09_volume
		wave09_volume:
		sts (w09+4), r24
		ret

		.global wave09_phase
		wave09_phase:
		sts (w09+1), r25
		sts (w09), r24
		ret

		.global wave09_frequency
		wave09_frequency:
		sts (w09+3), r25
		sts (w09+2), r24
		ret
	#endif


	#if polyphony > 9
		.extern w10
		.global wave10_volume
		wave10_volume:
		sts (w10+4), r24
		ret

		.global wave10_phase
		wave10_phase:
		sts (w10+1), r25
		sts (w10), r24
		ret

		.global wave10_frequency
		wave10_frequency:
		sts (w10+3), r25
		sts (w10+2), r24
		ret
	#endif


	#if polyphony > 10
		.extern w11
		.global wave11_volume
		wave11_volume:
		sts (w11+4), r24
		ret

		.global wave11_phase
		wave11_phase:
		sts (w11+1), r25
		sts (w11), r24
		ret

		.global wave11_frequency
		wave11_frequency:
		sts (w11+3), r25
		sts (w11+2), r24
		ret
	#endif


	#if polyphony > 11
		.extern w12
		.global wave12_volume
		wave12_volume:
		sts (w12+4), r24
		ret

		.global wave12_phase
		wave12_phase:
		sts (w12+1), r25
		sts (w12), r24
		ret

		.global wave12_frequency
		wave12_frequency:
		sts (w12+3), r25
		sts (w12+2), r24
		ret
	#endif


	#if polyphony > 12
		.extern w13
		.global wave13_volume
		wave13_volume:
		sts (w13+4), r24
		ret

		.global wave13_phase
		wave13_phase:
		sts (w13+1), r25
		sts (w13), r24
		ret

		.global wave13_frequency
		wave13_frequency:
		sts (w13+3), r25
		sts (w13+2), r24
		ret
	#endif


	#if polyphony > 13
		.extern w14
		.global wave14_volume
		wave14_volume:
		sts (w14+4), r24
		ret

		.global wave14_phase
		wave14_phase:
		sts (w14+1), r25
		sts (w14), r24
		ret

		.global wave14_frequency
		wave14_frequency:
		sts (w14+3), r25
		sts (w14+2), r24
		ret
	#endif


	#if polyphony > 14
		.extern w15
		.global wave15_volume
		wave15_volume:
		sts (w15+4), r24
		ret

		.global wave15_phase
		wave15_phase:
		sts (w15+1), r25
		sts (w15), r24
		ret

		.global wave15_frequency
		wave15_frequency:
		sts (w15+3), r25
		sts (w15+2), r24
		ret
	#endif


	#if polyphony > 15
		.extern w16
		.global wave16_volume
		wave16_volume:
		sts (w16+4), r24
		ret

		.global wave16_phase
		wave16_phase:
		sts (w16+1), r25
		sts (w16), r24
		ret

		.global wave16_frequency
		wave16_frequency:
		sts (w16+3), r25
		sts (w16+2), r24
		ret
	#endif


	#if polyphony > 16
		.extern w17
		.global wave17_volume
		wave17_volume:
		sts (w17+4), r24
		ret

		.global wave17_phase
		wave17_phase:
		sts (w17+1), r25
		sts (w17), r24
		ret

		.global wave17_frequency
		wave17_frequency:
		sts (w17+3), r25
		sts (w17+2), r24
		ret
	#endif


	#if polyphony > 17
		.extern w18
		.global wave18_volume
		wave18_volume:
		sts (w18+4), r24
		ret

		.global wave18_phase
		wave18_phase:
		sts (w18+1), r25
		sts (w18), r24
		ret

		.global wave18_frequency
		wave18_frequency:
		sts (w18+3), r25
		sts (w18+2), r24
		ret
	#endif


	#if polyphony > 18
		.extern w19
		.global wave19_volume
		wave19_volume:
		sts (w19+4), r24
		ret

		.global wave19_phase
		wave19_phase:
		sts (w19+1), r25
		sts (w19), r24
		ret

		.global wave19_frequency
		wave19_frequency:
		sts (w19+3), r25
		sts (w19+2), r24
		ret
	#endif


	#if polyphony > 19
		.extern w20
		.global wave20_volume
		wave20_volume:
		sts (w20+4), r24
		ret

		.global wave20_phase
		wave20_phase:
		sts (w20+1), r25
		sts (w20), r24
		ret

		.global wave20_frequency
		wave20_frequency:
		sts (w20+3), r25
		sts (w20+2), r24
		ret
	#endif


	#if polyphony > 20
		.extern w21
		.global wave21_volume
		wave21_volume:
		sts (w21+4), r24
		ret

		.global wave21_phase
		wave21_phase:
		sts (w21+1), r25
		sts (w21), r24
		ret

		.global wave21_frequency
		wave21_frequency:
		sts (w21+3), r25
		sts (w21+2), r24
		ret
	#endif


	#if polyphony > 21
		.extern w22
		.global wave22_volume
		wave22_volume:
		sts (w22+4), r24
		ret

		.global wave22_phase
		wave22_phase:
		sts (w22+1), r25
		sts (w22), r24
		ret

		.global wave22_frequency
		wave22_frequency:
		sts (w22+3), r25
		sts (w22+2), r24
		ret
	#endif


	#if polyphony > 22
		.extern w23
		.global wave23_volume
		wave23_volume:
		sts (w23+4), r24
		ret

		.global wave23_phase
		wave23_phase:
		sts (w23+1), r25
		sts (w23), r24
		ret

		.global wave23_frequency
		wave23_frequency:
		sts (w23+3), r25
		sts (w23+2), r24
		ret
	#endif


	#if polyphony > 23
		.extern w24
		.global wave24_volume
		wave24_volume:
		sts (w24+4), r24
		ret

		.global wave24_phase
		wave24_phase:
		sts (w24+1), r25
		sts (w24), r24
		ret

		.global wave24_frequency
		wave24_frequency:
		sts (w24+3), r25
		sts (w24+2), r24
		ret
	#endif


	#if polyphony > 24
		.extern w25
		.global wave25_volume
		wave25_volume:
		sts (w25+4), r24
		ret

		.global wave25_phase
		wave25_phase:
		sts (w25+1), r25
		sts (w25), r24
		ret

		.global wave25_frequency
		wave25_frequency:
		sts (w25+3), r25
		sts (w25+2), r24
		ret
	#endif


	#if polyphony > 25
		.extern w26
		.global wave26_volume
		wave26_volume:
		sts (w26+4), r24
		ret

		.global wave26_phase
		wave26_phase:
		sts (w26+1), r25
		sts (w26), r24
		ret

		.global wave26_frequency
		wave26_frequency:
		sts (w26+3), r25
		sts (w26+2), r24
		ret
	#endif


	#if polyphony > 26
		.extern w27
		.global wave27_volume
		wave27_volume:
		sts (w27+4), r24
		ret

		.global wave27_phase
		wave27_phase:
		sts (w27+1), r25
		sts (w27), r24
		ret

		.global wave27_frequency
		wave27_frequency:
		sts (w27+3), r25
		sts (w27+2), r24
		ret
	#endif


	#if polyphony > 27
		.extern w28
		.global wave28_volume
		wave28_volume:
		sts (w28+4), r24
		ret

		.global wave28_phase
		wave28_phase:
		sts (w28+1), r25
		sts (w28), r24
		ret

		.global wave28_frequency
		wave28_frequency:
		sts (w28+3), r25
		sts (w28+2), r24
		ret
	#endif


	#if polyphony > 28
		.extern w29
		.global wave29_volume
		wave29_volume:
		sts (w29+4), r24
		ret

		.global wave29_phase
		wave29_phase:
		sts (w29+1), r25
		sts (w29), r24
		ret

		.global wave29_frequency
		wave29_frequency:
		sts (w29+3), r25
		sts (w29+2), r24
		ret
	#endif


	#if polyphony > 29
		.extern w30
		.global wave30_volume
		wave30_volume:
		sts (w30+4), r24
		ret

		.global wave30_phase
		wave30_phase:
		sts (w30+1), r25
		sts (w30), r24
		ret

		.global wave30_frequency
		wave30_frequency:
		sts (w30+3), r25
		sts (w30+2), r24
		ret
	#endif


	#if polyphony > 30
		.extern w31
		.global wave31_volume
		wave31_volume:
		sts (w31+4), r24
		ret

		.global wave31_phase
		wave31_phase:
		sts (w31+1), r25
		sts (w31), r24
		ret

		.global wave31_frequency
		wave31_frequency:
		sts (w31+3), r25
		sts (w31+2), r24
		ret
	#endif


	#if polyphony > 31
		.extern w32
		.global wave32_volume
		wave32_volume:
		sts (w32+4), r24
		ret

		.global wave32_phase
		wave32_phase:
		sts (w32+1), r25
		sts (w32), r24
		ret

		.global wave32_frequency
		wave32_frequency:
		sts (w32+3), r25
		sts (w32+2), r24
		ret
	#endif
#endif