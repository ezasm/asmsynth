#ifdef MusicSynthesizer_c

//#include <asmsynth.h>

#ifndef disable_secondProgram
	//extern void delay_ci(unsigned long a);
	void delay_ms(float a)
	{
		a=a*F_CPU/256/1000;
		delay_ci(a);
	}

	//extern long get_ci();
	float get_ms()
	{
		return get_ci()*1000*256/F_CPU;
	}
#endif

int hz(double hz)
{
	//x=hz*a*b/1000000
	//a-wave sampling (number of samples per wave)
	//b-sound sampling (in microseconds)
	return hz*65536*SOUND_SAMPLING/1000000;
}

unsigned int keyboard(double key)
{
	key=hz(TUNE*pow(TONE_INTERVAL, ((key-KEY_SHIFT)/NUMBER_OF_TONES)));
	return key;
}

unsigned int keyboard(double key, double cent)
{
	key=keyboard(key+cent/100);
	return key;
}

void startinterrupt()
{
	asm volatile
	(
		"push r25\n"
		"in r25, 0x3F\n"
		"push r25\n"
		#if mode == 2
			"lds r25, (sPin)\n"
			"cpi r25, 255\n"
			"breq pominpiny\n"
			"sbrs r25, 0\n"
			C_Cpin1
			"sbrs r25, 1\n"
			C_Cpin2
			#if channel == 2
				"sbrs r25, 2\n"
				C_Cpin3
				"sbrs r25, 3\n"
				C_Cpin4
			#endif
			"sbrc r25, 0\n"
			C_Spin1
			"sbrc r25, 1\n"
			C_Spin2
			#if channel == 2
				"sbrc r25, 2\n"
				C_Spin3
				"sbrc r25, 3\n"
				C_Spin4
			#endif
			"ser r25\n"
			"sts (sPin), r25\n"
			"pominpiny:\n"
		#endif
		#ifndef disable_secondProgram
			"clt\n"
			"push r24\n"
			"lds r25, (sTime)\n"
			"lds r24, (sDelay)\n"
			"cp r24, r25\n"
			"brne pominprogram\n"
			"lds r25, (sTime+1)\n"
			"lds r24, (sDelay+1)\n"
			"cp r24, r25\n"
			"brne pominprogram\n"
			"lds r25, (sTime+2)\n"
			"lds r24, (sDelay+2)\n"
			"cp r24, r25\n"
			"brne pominprogram\n"
			"lds r25, (sTime+3)\n"
			"lds r24, (sDelay+3)\n"
			"cp r24, r25\n"
			"brne pominprogram\n"
			"set\n"
			"pominprogram:\n"
		#endif
		"lds r25, (sTime)\n"
		"inc r25\n"
		"sts (sTime), r25\n"
		#ifndef disable_secondProgram
			"brne przerwanie\n"
			"lds r24, (sTime+1)\n"
			"inc r24\n"
			"sts (sTime+1), r24\n"
			"brne przerwanie\n"
			"lds r24, (sTime+2)\n"
			"inc r24\n"
			"sts (sTime+2), r24\n"
			"brne przerwanie\n"
			"lds r24, (sTime+3)\n"
			"inc r24\n"
			"sts (sTime+3), r24\n"
			"przerwanie:\n"
		#endif
		#if INTERRUPT_COUNTER == 4
			"andi r25, 0x03\n"
			"cpi r25, 3\n"
			"breq dzw\n"
		#endif
		#if INTERRUPT_COUNTER == 2
			"sbrs r25, 0\n"
		#endif
		"rjmp pomindzw\n"
		"dzw:\n"
		"sei\n"
		#ifdef disable_secondProgram
			"push r24\n"
		#endif
		"push r23\n"
		"push r22\n"
		"push r21\n"
		"push r20\n"
		"push r1\n"
		"push r0\n"
		"clr r20\n"
	);
}

void endinterrupt()
{
	asm volatile
	(
		#ifndef disable_volume
			"lds r21, (sVolume)\n"
			"mulsu r20, r21\n"
			"mov r20, r1\n"
		#endif
		#ifdef enable_ADC
			"lds r21, 0x79\n"
			"mulsu r20, r21\n"
			"mov r20, r1\n"
		#endif
		#if channel == 2
			"mov r21, r20\n"
		#endif
		#ifdef enable_motor
			"lds r22, (sMotorA)\n"
			"mov r23, r22\n"
			"sbrs r22, 7\n"
			"com r22\n"
			"lsl r22\n"
			"mulsu r20, r22\n"
			"mov r20, r1\n"
			"add r20, r23\n"
			#if channel == 2
				"lds r22, (sMotorB)\n"
				"mov r23, r22\n"
				"sbrs r22, 7\n"
				"com r22\n"
				"lsl r22\n"
				"mulsu r21, r22\n"
				"mov r21, r1\n"
				"add r21, r23\n"
			#endif
		#endif
		"cli\n"
		#if mode == 1
			"subi r20, 128\n"
			C_PWM1_20
			#if channel == 2
				"subi r21, 128\n"
				C_PWM2_21
			#endif
		#endif
		#if mode == 2
			"sbrs r20, 7\n"
			"rjmp plus1\n"
			"com r20\n"
			"lsl r20\n"
			C_PWM1_20
			"ldi r22, 2\n"
			#if channel == 1
				"sts (sPin), r22\n"
				"rjmp stos\n"
			#endif
			#if channel == 2
				"rjmp channel2\n"
			#endif
			"plus1:\n"
			"cpi r20, 0\n"
			"breq zero1\n"
			"lsl r20\n"
			C_PWM1_20
			"ldi r22, 1\n"
			#if channel == 1
				"sts (sPin), r22\n"
				"rjmp stos\n"
			#endif
			#if channel == 2
				"rjmp channel2\n"
			#endif
			"zero1:\n"
			C_PWM1_20
			#if channel == 1
				"sts (sPin), r20\n"
			#endif
			#if channel == 2
				"clr r22\n"
				"channel2:\n"
				"sbrs r21, 7\n"
				"rjmp plus2\n"
				"com r21\n"
				"lsl r21\n"
				C_PWM2_21
				"ori r22, 8\n"
				"sts (sPin), r22\n"
				"rjmp stos\n"
				"plus2:\n"
				"cpi r21, 0\n"
				"breq zero2\n"
				"lsl r21\n"
				C_PWM2_21
				"ori r22, 4\n"
				"sts (sPin), r22\n"
				"rjmp stos\n"
				"zero2:\n"
				C_PWM2_21
				"sts (sPin), r22\n"
			#endif
		#endif
		#if mode == 3
			"sbrs r20, 7\n"
			"rjmp plus1\n"
			"com r20\n"
			"lsl r20\n"
			C_PWM2_20
			"clr r20\n"
			C_PWM1_20
			#if channel == 1
				"rjmp stos\n"
			#endif
			#if channel == 2
				"rjmp channel2\n"
			#endif
			"plus1:\n"
			"lsl r21\n"
			C_PWM1_20
			"clr r20\n"
			C_PWM2_20
			#if channel == 2
				"channel2:\n"
				"sbrs r21, 7\n"
				"rjmp plus2\n"
				"com r21\n"
				"lsl r21\n"
				C_PWM4_21
				"clr r21\n"
				C_PWM3_21
				"rjmp stos\n"
				"plus2:\n"
				"lsl r21\n"
				C_PWM3_21
				"clr r21\n"
				C_PWM4_21
			#endif
		#endif
		"stos:\n"
		"pop r0\n"
		"pop r1\n"
		"pop r20\n"
		"pop r21\n"
		"pop r22\n"
		"pop r23\n"
		#ifdef disable_secondProgram
			"pop r24\n"
		#endif
		"pomindzw:\n"
		#ifndef disable_secondProgram
			"brtc powrot\n"
			"sei\n"
			"push r23\n"
			"push r22\n"
			"push r21\n"
			#ifndef enable_quickProgramChange
				"push r31\n"
				"push r30\n"
				"push r29\n"
				"push r28\n"
				"push r27\n"
				"push r26\n"
				"push r20\n"
				"push r19\n"
				"push r18\n"
				"push r17\n"
				"push r16\n"
				"push r15\n"
				"push r14\n"
				"push r13\n"
				"push r12\n"
				"push r11\n"
				"push r10\n"
				"push r9\n"
				"push r8\n"
				"push r7\n"
				"push r6\n"
				"push r5\n"
				"push r4\n"
				"push r3\n"
				"push r2\n"
				"push r1\n"
				"push r0\n"
				"clr r1\n"
			#endif
			"lds r25, (ProgramCounter)\n"
			"push r25\n"
			"lds r25, (ProgramCounter+1)\n"
			"push r25\n"
			"ret\n"
			"powrot:\n"
			"pop r24\n"
		#endif
		"pop r25\n"
		"out 0x3F, r25\n"
		"pop r25\n"
		"reti\n"
	);
}

void squareWave()
{
	asm volatile
	(
		"sbrc r23, 7\n"
		"com r21\n"
		"add r20, r21\n"
	);
}

void sawWave()
{
	asm volatile
	(
		"mulsu r23, r21\n"
		"add r20, r1\n"
	);
}

void triangleWave()
{
	
	asm volatile
	(
		"sbrs r23, 7\n"
		"com r23\n"
		"lsl r23\n"
		"subi r23, 127\n"
		"mulsu r23, r21\n"
		"add r20, r1\n"
	);
}

#if polyphony > 0
	void wave01()
	{
		asm volatile
		(
			"lds r22, (w01)\n"
			"lds r23, (w01+1)\n"
			"lds r24, (w01+2)\n"
			"lds r25, (w01+3)\n"
			"lds r21, (w01+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w01+1), r23\n"
			"sts (w01), r22\n"
		);
	}
#endif

#if polyphony > 1
	void wave02()
	{
		asm volatile
		(
			"lds r22, (w02)\n"
			"lds r23, (w02+1)\n"
			"lds r24, (w02+2)\n"
			"lds r25, (w02+3)\n"
			"lds r21, (w02+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w02+1), r23\n"
			"sts (w02), r22\n"
		);
	}
#endif

#if polyphony > 2
	void wave03()
	{
		asm volatile
		(
			"lds r22, (w03)\n"
			"lds r23, (w03+1)\n"
			"lds r24, (w03+2)\n"
			"lds r25, (w03+3)\n"
			"lds r21, (w03+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w03+1), r23\n"
			"sts (w03), r22\n"
		);
	}
#endif

#if polyphony > 3
	void wave04()
	{
		asm volatile
		(
			"lds r22, (w04)\n"
			"lds r23, (w04+1)\n"
			"lds r24, (w04+2)\n"
			"lds r25, (w04+3)\n"
			"lds r21, (w04+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w04+1), r23\n"
			"sts (w04), r22\n"
		);
	}
#endif

#if polyphony > 4
	void wave05()
	{
		asm volatile
		(
			"lds r22, (w05)\n"
			"lds r23, (w05+1)\n"
			"lds r24, (w05+2)\n"
			"lds r25, (w05+3)\n"
			"lds r21, (w05+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w05+1), r23\n"
			"sts (w05), r22\n"
		);
	}
#endif

#if polyphony > 5
	void wave06()
	{
		asm volatile
		(
			"lds r22, (w06)\n"
			"lds r23, (w06+1)\n"
			"lds r24, (w06+2)\n"
			"lds r25, (w06+3)\n"
			"lds r21, (w06+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w06+1), r23\n"
			"sts (w06), r22\n"
		);
	}
#endif

#if polyphony > 6
	void wave07()
	{
		asm volatile
		(
			"lds r22, (w07)\n"
			"lds r23, (w07+1)\n"
			"lds r24, (w07+2)\n"
			"lds r25, (w07+3)\n"
			"lds r21, (w07+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w07+1), r23\n"
			"sts (w07), r22\n"
		);
	}
#endif

#if polyphony > 7
	void wave08()
	{
		asm volatile
		(
			"lds r22, (w08)\n"
			"lds r23, (w08+1)\n"
			"lds r24, (w08+2)\n"
			"lds r25, (w08+3)\n"
			"lds r21, (w08+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w08+1), r23\n"
			"sts (w08), r22\n"
		);
	}
#endif

#if polyphony > 8
	void wave09()
	{
		asm volatile
		(
			"lds r22, (w09)\n"
			"lds r23, (w09+1)\n"
			"lds r24, (w09+2)\n"
			"lds r25, (w09+3)\n"
			"lds r21, (w09+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w09+1), r23\n"
			"sts (w09), r22\n"
		);
	}
#endif

#if polyphony > 9
	void wave10()
	{
		asm volatile
		(
			"lds r22, (w10)\n"
			"lds r23, (w10+1)\n"
			"lds r24, (w10+2)\n"
			"lds r25, (w10+3)\n"
			"lds r21, (w10+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w10+1), r23\n"
			"sts (w10), r22\n"
		);
	}
#endif

#if polyphony > 10
	void wave11()
	{
		asm volatile
		(
			"lds r22, (w11)\n"
			"lds r23, (w11+1)\n"
			"lds r24, (w11+2)\n"
			"lds r25, (w11+3)\n"
			"lds r21, (w11+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w11+1), r23\n"
			"sts (w11), r22\n"
		);
	}
#endif

#if polyphony > 11
	void wave12()
	{
		asm volatile
		(
			"lds r22, (w12)\n"
			"lds r23, (w12+1)\n"
			"lds r24, (w12+2)\n"
			"lds r25, (w12+3)\n"
			"lds r21, (w12+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w12+1), r23\n"
			"sts (w12), r22\n"
		);
	}
#endif

#if polyphony > 12
	void wave13()
	{
		asm volatile
		(
			"lds r22, (w13)\n"
			"lds r23, (w13+1)\n"
			"lds r24, (w13+2)\n"
			"lds r25, (w13+3)\n"
			"lds r21, (w13+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w13+1), r23\n"
			"sts (w13), r22\n"
		);
	}
#endif

#if polyphony > 13
	void wave14()
	{
		asm volatile
		(
			"lds r22, (w14)\n"
			"lds r23, (w14+1)\n"
			"lds r24, (w14+2)\n"
			"lds r25, (w14+3)\n"
			"lds r21, (w14+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w14+1), r23\n"
			"sts (w14), r22\n"
		);
	}
#endif

#if polyphony > 14
	void wave15()
	{
		asm volatile
		(
			"lds r22, (w15)\n"
			"lds r23, (w15+1)\n"
			"lds r24, (w15+2)\n"
			"lds r25, (w15+3)\n"
			"lds r21, (w15+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w15+1), r23\n"
			"sts (w15), r22\n"
		);
	}
#endif

#if polyphony > 15
	void wave16()
	{
		asm volatile
		(
			"lds r22, (w16)\n"
			"lds r23, (w16+1)\n"
			"lds r24, (w16+2)\n"
			"lds r25, (w16+3)\n"
			"lds r21, (w16+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w16+1), r23\n"
			"sts (w16), r22\n"
		);
	}
#endif

#if polyphony > 16
	void wave17()
	{
		asm volatile
		(
			"lds r22, (w17)\n"
			"lds r23, (w17+1)\n"
			"lds r24, (w17+2)\n"
			"lds r25, (w17+3)\n"
			"lds r21, (w17+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w17+1), r23\n"
			"sts (w17), r22\n"
		);
	}
#endif

#if polyphony > 17
	void wave18()
	{
		asm volatile
		(
			"lds r22, (w18)\n"
			"lds r23, (w18+1)\n"
			"lds r24, (w18+2)\n"
			"lds r25, (w18+3)\n"
			"lds r21, (w18+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w18+1), r23\n"
			"sts (w18), r22\n"
		);
	}
#endif

#if polyphony > 18
	void wave19()
	{
		asm volatile
		(
			"lds r22, (w19)\n"
			"lds r23, (w19+1)\n"
			"lds r24, (w19+2)\n"
			"lds r25, (w19+3)\n"
			"lds r21, (w19+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w19+1), r23\n"
			"sts (w19), r22\n"
		);
	}
#endif

#if polyphony > 19
	void wave20()
	{
		asm volatile
		(
			"lds r22, (w20)\n"
			"lds r23, (w20+1)\n"
			"lds r24, (w20+2)\n"
			"lds r25, (w20+3)\n"
			"lds r21, (w20+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w20+1), r23\n"
			"sts (w20), r22\n"
		);
	}
#endif

#if polyphony > 20
	void wave21()
	{
		asm volatile
		(
			"lds r22, (w21)\n"
			"lds r23, (w21+1)\n"
			"lds r24, (w21+2)\n"
			"lds r25, (w21+3)\n"
			"lds r21, (w21+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w21+1), r23\n"
			"sts (w21), r22\n"
		);
	}
#endif

#if polyphony > 21
	void wave22()
	{
		asm volatile
		(
			"lds r22, (w22)\n"
			"lds r23, (w22+1)\n"
			"lds r24, (w22+2)\n"
			"lds r25, (w22+3)\n"
			"lds r21, (w22+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w22+1), r23\n"
			"sts (w22), r22\n"
		);
	}
#endif

#if polyphony > 22
	void wave23()
	{
		asm volatile
		(
			"lds r22, (w23)\n"
			"lds r23, (w23+1)\n"
			"lds r24, (w23+2)\n"
			"lds r25, (w23+3)\n"
			"lds r21, (w23+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w23+1), r23\n"
			"sts (w23), r22\n"
		);
	}
#endif

#if polyphony > 23
	void wave24()
	{
		asm volatile
		(
			"lds r22, (w24)\n"
			"lds r23, (w24+1)\n"
			"lds r24, (w24+2)\n"
			"lds r25, (w24+3)\n"
			"lds r21, (w24+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w24+1), r23\n"
			"sts (w24), r22\n"
		);
	}
#endif

#if polyphony > 24
	void wave25()
	{
		asm volatile
		(
			"lds r22, (w25)\n"
			"lds r23, (w25+1)\n"
			"lds r24, (w25+2)\n"
			"lds r25, (w25+3)\n"
			"lds r21, (w25+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w25+1), r23\n"
			"sts (w25), r22\n"
		);
	}
#endif

#if polyphony > 25
	void wave26()
	{
		asm volatile
		(
			"lds r22, (w26)\n"
			"lds r23, (w26+1)\n"
			"lds r24, (w26+2)\n"
			"lds r25, (w26+3)\n"
			"lds r21, (w26+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w26+1), r23\n"
			"sts (w26), r22\n"
		);
	}
#endif

#if polyphony > 26
	void wave27()
	{
		asm volatile
		(
			"lds r22, (w27)\n"
			"lds r23, (w27+1)\n"
			"lds r24, (w27+2)\n"
			"lds r25, (w27+3)\n"
			"lds r21, (w27+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w27+1), r23\n"
			"sts (w27), r22\n"
		);
	}
#endif

#if polyphony > 27
	void wave28()
	{
		asm volatile
		(
			"lds r22, (w28)\n"
			"lds r23, (w28+1)\n"
			"lds r24, (w28+2)\n"
			"lds r25, (w28+3)\n"
			"lds r21, (w28+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w28+1), r23\n"
			"sts (w28), r22\n"
		);
	}
#endif

#if polyphony > 28
	void wave29()
	{
		asm volatile
		(
			"lds r22, (w29)\n"
			"lds r23, (w29+1)\n"
			"lds r24, (w29+2)\n"
			"lds r25, (w29+3)\n"
			"lds r21, (w29+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w29+1), r23\n"
			"sts (w29), r22\n"
		);
	}
#endif

#if polyphony > 29
	void wave30()
	{
		asm volatile
		(
			"lds r22, (w30)\n"
			"lds r23, (w30+1)\n"
			"lds r24, (w30+2)\n"
			"lds r25, (w30+3)\n"
			"lds r21, (w30+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w30+1), r23\n"
			"sts (w30), r22\n"
		);
	}
#endif

#if polyphony > 30
	void wave31()
	{
		asm volatile
		(
			"lds r22, (w31)\n"
			"lds r23, (w31+1)\n"
			"lds r24, (w31+2)\n"
			"lds r25, (w31+3)\n"
			"lds r21, (w31+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w31+1), r23\n"
			"sts (w31), r22\n"
		);
	}
#endif

#if polyphony > 31
	void wave32()
	{
		asm volatile
		(
			"lds r22, (w32)\n"
			"lds r23, (w32+1)\n"
			"lds r24, (w32+2)\n"
			"lds r25, (w32+3)\n"
			"lds r21, (w32+4)\n"
			"add r22, r24\n"
			"adc r23, r25\n"
			"sts (w32+1), r23\n"
			"sts (w32), r22\n"
		);
	}
#endif

#endif