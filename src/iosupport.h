#ifndef iosupport
#define iosupport

//dedicated for atmega328p or other similar boards


#if defined(vectorInterrupt) || defined(C_STI_25) || defined(C_LTI_25) || defined(asm_STI_25)
#define timerInterruptMacro
#endif

#if defined(C_PWM1_21) || defined(asm_PWM1_24)
#define PWM1Macro
#endif

#if defined(C_PWM2_20) || defined(C_PWM2_21) || defined(asm_PWM2_24)
#define PWM2Macro
#endif

#if defined(C_PWM3_20) || defined(asm_PWM3_24)
#define PWM3Macro
#endif

#if defined(C_PWM4_20) || defined(asm_PWM4_24)
#define PWM4Macro
#endif

#if defined(C_Cpin1) || defined(C_Spin1) || defined(asm_Cpin1) || defined(asm_Spin1)
#define pin1Macro
#endif

#if defined(C_Cpin2) || defined(C_Spin2) || defined(asm_Cpin2) || defined(asm_Spin2)
#define pin2Macro
#endif

#if defined(C_Cpin3) || defined(C_Spin3) || defined(asm_Cpin3) || defined(asm_Spin3)
#define pin3Macro
#endif

#if defined(C_Cpin4) || defined(C_Spin4) || defined(asm_Cpin4) || defined(asm_Spin4)
#define pin4Macro
#endif




//reporting errors
#ifdef enable_highSamplingRate
	#if !defined(polyphony) || polyphony < 1 || polyphony > 16
	#error "You must define the 'polyphony' with using numbers in the range: 1-16."
	#endif
#else
	#if !defined(polyphony) || polyphony < 1 || polyphony > 32
	#error "You must define the 'polyphony' with using numbers in the range: 1-32."
	#endif
#endif

#if mode != 1 && mode != 2 && mode != 3
#error "You must define the 'mode' with using these numbers: 1, 2 or 3."
#endif

#if channel != 1 && channel != 2
#error "You must define the 'channel' (number of channels) with using these numbers: 1 or 2."
#endif



#if !defined(timerInterruptMacro) && !defined(timerInterrupt) || timerInterrupt != 0 && timerInterrupt != 1 && timerInterrupt != 2
#error "You must define the 'timerInterrupt' with using these numbers: 0, 1 or 2."
#endif

#if !defined(PWM1Macro) && !defined(PWM1) || PWM1 != 3 && PWM1 != 5 && PWM1 != 6 && PWM1 != 9 && PWM1 != 10 && PWM1 != 11
#error "You must define the 'PWM1' with using these numbers: 3, 5, 6, 9, 10 or 11."
#endif


#if channel == 2 || mode == 3
	#if !defined(PWM2Macro) && !defined(PWM2) || PWM2 != 3 && PWM2 != 5 && PWM2 != 6 && PWM2 != 9 && PWM2 != 10 && PWM2 != 11
	#error "You must define the 'PWM2' with using these numbers: 3, 5, 6, 9, 10 or 11."
	#endif
#endif

#if channel == 2 && mode == 3
	#if !defined(PWM3Macro) && !defined(PWM3) || PWM3 != 3 && PWM3 != 5 && PWM3 != 6 && PWM3 != 9 && PWM3 != 10 && PWM3 != 11
	#error "You must define the 'PWM3' with using these numbers: 3, 5, 6, 9, 10 or 11."
	#endif
	
	#if !defined(PWM4Macro) && !defined(PWM4) || PWM4 != 3 && PWM4 != 5 && PWM4 != 6 && PWM4 != 9 && PWM4 != 10 && PWM4 != 11
	#error "You must define the 'PWM4' with using these numbers: 3, 5, 6, 9, 10 or 11."
	#endif
#endif

#if mode == 2
	#if !defined(pin1Macro) && !defined(pin1) || pin1 < 2 || pin1 > 13
	#error "You must define the 'pin1' with using numbers in the range: 2-13."
	#endif
	
	#if !defined(pin2Macro) && !defined(pin2) || pin2 < 2 || pin2 > 13
	#error "You must define the 'pin2' with using numbers in the range: 2-13."
	#endif
	
	#if channel == 2
		#if !defined(pin3Macro) && !defined(pin3) || pin3 < 2 || pin3 > 13
		#error "You must define the 'pin3' with using numbers in the range: 2-13."
		#endif
		
		#if !defined(pin4Macro) && !defined(pin4) || pin4 < 2 || pin4 > 13
		#error "You must define the 'pin4' with using numbers in the range: 2-13."
		#endif
	#endif
#endif



#if channel == 2 || mode == 3
	#if !defined(PWM1Macro) && !defined(PWM2Macro) && PWM1 == PWM2
	#error "You can not use the same pins for PWM1 and PWM2."
	#endif
#endif

#if channel == 2 && mode == 3
		#if !defined(PWM1Macro) && !defined(PWM3Macro) && PWM1 == PWM3
		#error "You can not use the same pins for PWM1 and PWM3."
		#endif
		
		#if !defined(PWM2Macro) && !defined(PWM3Macro) && PWM2 == PWM3
		#error "You can not use the same pins for PWM2 and PWM3."
		#endif
	
		#if !defined(PWM1Macro) && !defined(PWM4Macro) && PWM1 == PWM4
		#error "You can not use the same pins for PWM1 and PWM4."
		#endif
		
		#if !defined(PWM2Macro) && !defined(PWM4Macro) && PWM2 == PWM4
		#error "You can not use the same pins for PWM2 and PWM4."
		#endif
		
		#if !defined(PWM3Macro) && !defined(PWM4Macro) && PWM3 == PWM4
		#error "You can not use the same pins for PWM3 and PWM4."
		#endif
#endif

#if mode == 2
	#if !defined(PWM1Macro) && !defined(pin1Macro) && PWM1 == pin1
	#error "You can not use the same pins for PWM1 and pin1."
	#endif
	
	#if !defined(PWM1Macro) && !defined(pin2Macro) && PWM1 == pin2
	#error "You can not use the same pins for PWM1 and pin2."
	#endif
		
	#if !defined(pin1Macro) && !defined(pin2Macro) && pin1 == pin2
	#error "You can not use the same pins for pin1 and pin2."
	#endif
	
	#if channel == 2
		#if !defined(PWM2Macro) && !defined(pin1Macro) && PWM2 == pin1
		#error "You can not use the same pins for PWM2 and pin1."
		#endif
		
		#if !defined(PWM2Macro) && !defined(pin2Macro) && PWM2 == pin2
		#error "You can not use the same pins for PWM2 and pin2."
		#endif
		
		#if !defined(PWM1Macro) && !defined(pin3Macro) && PWM1 == pin3
		#error "You can not use the same pins for PWM1 and pin3."
		#endif
			
		#if !defined(PWM2Macro) && !defined(pin3Macro) && PWM2 == pin3
		#error "You can not use the same pins for PWM2 and pin3."
		#endif
			
		#if !defined(pin1Macro) && !defined(pin3Macro) && pin1 == pin3
		#error "You can not use the same pins for pin1 and pin3."
		#endif
			
		#if !defined(pin2Macro) && !defined(pin3Macro) && pin2 == pin3
		#error "You can not use the same pins for pin2 and pin3."
		#endif
		
		#if !defined(PWM1Macro) && !defined(pin4Macro) && PWM1 == pin4
		#error "You can not use the same pins for PWM1 and pin4."
		#endif
			
		#if !defined(PWM2Macro) && !defined(pin4Macro) && PWM2 == pin4
		#error "You can not use the same pins for PWM2 and pin4."
		#endif
			
		#if !defined(pin1Macro) && !defined(pin4Macro) && pin1 == pin4
		#error "You can not use the same pins for pin1 and pin4."
		#endif
			
		#if !defined(pin2Macro) && !defined(pin4Macro) && pin2 == pin4
		#error "You can not use the same pins for pin2 and pin4."
		#endif
			
		#if !defined(pin3Macro) && !defined(pin4Macro) && pin3 == pin4
		#error "You can not use the same pins for pin3 and pin4."
		#endif
	#endif
#endif





#if timerInterrupt == 0
	#define timer0
#endif

#if timerInterrupt == 1
	#define timer1
#endif

#if timerInterrupt == 2
	#define timer2
#endif


#if PWM1 == 3
	#define sPin3
	#define timer2
#endif
#if PWM1 == 5
	#define sPin5
	#define timer0
#endif
#if PWM1 == 6
	#define sPin6
	#define timer0
#endif
#if PWM1 == 9
	#define sPin9
	#define timer1
#endif
#if PWM1 == 10
	#define sPin10
	#define timer1
#endif
#if PWM1 == 11
	#define sPin11
	#define timer2
#endif

#if channel == 2 || mode == 3
	#if PWM2 == 3
		#define sPin3
		#define timer2
	#endif
	#if PWM2 == 5
		#define sPin5
		#define timer0
	#endif
	#if PWM2 == 6
		#define sPin6
		#define timer0
	#endif
	#if PWM2 == 9
		#define sPin9
		#define timer1
	#endif
	#if PWM2 == 10
		#define sPin10
		#define timer1
	#endif
	#if PWM2 == 11
		#define sPin11
		#define timer2
	#endif
#endif

#if channel == 2 && mode == 3
	#if PWM3 == 3
		#define sPin3
		#define timer2
	#endif
	#if PWM3 == 5
		#define sPin5
		#define timer0
	#endif
	#if PWM3 == 6
		#define sPin6
		#define timer0
	#endif
	#if PWM3 == 9
		#define sPin9
		#define timer1
	#endif
	#if PWM3 == 10
		#define sPin10
		#define timer1
	#endif
	#if PWM3 == 11
		#define sPin11
		#define timer2
	#endif

	#if PWM4 == 3
		#define sPin3
		#define timer2
	#endif
	#if PWM4 == 5
		#define sPin5
		#define timer0
	#endif
	#if PWM4 == 6
		#define sPin6
		#define timer0
	#endif
	#if PWM4 == 9
		#define sPin9
		#define timer1
	#endif
	#if PWM4 == 10
		#define sPin10
		#define timer1
	#endif
	#if PWM4 == 11
		#define sPin11
		#define timer2
	#endif
#endif



#if mode == 2
	#if pin1 == 2
		#define sPin2
	#endif
	#if pin1 == 3
		#define sPin3
	#endif
	#if pin1 == 4
		#define sPin4
	#endif
	#if pin1 == 5
		#define sPin5
	#endif
	#if pin1 == 6
		#define sPin6
	#endif
	#if pin1 == 7
		#define sPin7
	#endif
	#if pin1 == 8
		#define sPin8
	#endif
	#if pin1 == 9
		#define sPin9
	#endif
	#if pin1 == 10
		#define sPin10
	#endif
	#if pin1 == 11
		#define sPin11
	#endif
	#if pin1 == 12
		#define sPin12
	#endif
	#if pin1 == 13
		#define sPin13
	#endif

	#if pin2 == 2
		#define sPin2
	#endif
	#if pin2 == 3
		#define sPin3
	#endif
	#if pin2 == 4
		#define sPin4
	#endif
	#if pin2 == 5
		#define sPin5
	#endif
	#if pin2 == 6
		#define sPin6
	#endif
	#if pin2 == 7
		#define sPin7
	#endif
	#if pin2 == 8
		#define sPin8
	#endif
	#if pin2 == 9
		#define sPin9
	#endif
	#if pin2 == 10
		#define sPin10
	#endif
	#if pin2 == 11
		#define sPin11
	#endif
	#if pin2 == 12
		#define sPin12
	#endif
	#if pin2 == 13
		#define sPin13
	#endif

	#if channel == 2
		#if pin3 == 2
			#define sPin2
		#endif
		#if pin3 == 3
			#define sPin3
		#endif
		#if pin3 == 4
			#define sPin4
		#endif
		#if pin3 == 5
			#define sPin5
		#endif
		#if pin3 == 6
			#define sPin6
		#endif
		#if pin3 == 7
			#define sPin7
		#endif
		#if pin3 == 8
			#define sPin8
		#endif
		#if pin3 == 9
			#define sPin9
		#endif
		#if pin3 == 10
			#define sPin10
		#endif
		#if pin3 == 11
			#define sPin11
		#endif
		#if pin3 == 12
			#define sPin12
		#endif
		#if pin3 == 13
			#define sPin13
		#endif

		#if pin4 == 2
			#define sPin2
		#endif
		#if pin4 == 3
			#define sPin3
		#endif
		#if pin4 == 4
			#define sPin4
		#endif
		#if pin4 == 5
			#define sPin5
		#endif
		#if pin4 == 6
			#define sPin6
		#endif
		#if pin4 == 7
			#define sPin7
		#endif
		#if pin4 == 8
			#define sPin8
		#endif
		#if pin4 == 9
			#define sPin9
		#endif
		#if pin4 == 10
			#define sPin10
		#endif
		#if pin4 == 11
			#define sPin11
		#endif
		#if pin4 == 12
			#define sPin12
		#endif
		#if pin4 == 13
			#define sPin13
		#endif
	#endif
#endif




#if !defined(timerInterruptMacro)
	#if timerInterrupt == 0
		#define vectorInterrupt __vector_16
		#define asm_STI_25 sts 0x6E, r25
		#define asm_LTI_25 lds r25, 0x6E
	#endif
	#if timerInterrupt == 1
		#define vectorInterrupt __vector_13
		#define asm_STI_25 sts 0x6F, r25
		#define asm_LTI_25 lds r25, 0x6F
	#endif
	#if timerInterrupt == 2
		#define vectorInterrupt __vector_9
		#define asm_STI_25 sts 0x70, r25
		#define asm_LTI_25 lds r25, 0x70
	#endif
#endif

#if !defined(PWM1Macro)
	#if PWM1 == 3
		#define C_PWM1_20 "sts 0xB4, r20\n"
		#define asm_PWM1_24 sts 0xB4, r24
	#endif
	#if PWM1 == 5
		#define C_PWM1_20 "out 0x28, r20\n"
		#define asm_PWM1_24 out 0x28, r24
	#endif
	#if PWM1 == 6
		#define C_PWM1_20 "out 0x27, r20\n"
		#define asm_PWM1_24 out 0x27, r24
	#endif
	#if PWM1 == 9
		#define C_PWM1_20 "sts 0x88, r20\n"
		#define asm_PWM1_24 sts 0x88, r24
	#endif
	#if PWM1 == 10
		#define C_PWM1_20 "sts 0x8A, r20\n"
		#define asm_PWM1_24 sts 0x8A, r24
	#endif
	#if PWM1 == 11
		#define C_PWM1_20 "sts 0xB3, r20\n"
		#define asm_PWM1_24 sts 0xB3, r24
	#endif
#endif
#if channel == 2 || mode == 3
	#if !defined(PWM2Macro)
		#if PWM2 == 3
			#define C_PWM2_20 "sts 0xB4, r20\n"
			#define C_PWM2_21 "sts 0xB4, r21\n"
			#define asm_PWM2_24 sts 0xB4, r24
		#endif
		#if PWM2 == 5
			#define C_PWM2_20 "out 0x28, r20\n"
			#define C_PWM2_21 "out 0x28, r21\n"
			#define asm_PWM2_24 out 0x28, r24
		#endif
		#if PWM2 == 6
			#define C_PWM2_20 "out 0x27, r20\n"
			#define C_PWM2_21 "out 0x27, r21\n"
			#define asm_PWM2_24 out 0x27, r24
		#endif
		#if PWM2 == 9
			#define C_PWM2_20 "sts 0x88, r20\n"
			#define C_PWM2_21 "sts 0x88, r21\n"
			#define asm_PWM2_24 sts 0x88, r24
		#endif
		#if PWM2 == 10
			#define C_PWM2_20 "sts 0x8A, r20\n"
			#define C_PWM2_21 "sts 0x8A, r21\n"
			#define asm_PWM2_24 sts 0x8A, r24
		#endif
		#if PWM2 == 11
			#define C_PWM2_20 "sts 0xB3, r20\n"
			#define C_PWM2_21 "sts 0xB3, r21\n"
			#define asm_PWM2_24 sts 0xB3, r24
		#endif
	#endif
#endif
#if channel == 2 && mode == 3
	#if !defined(PWM3Macro)
		#if PWM3 == 3
			#define C_PWM3_21 "sts 0xB4, r21\n"
			#define asm_PWM3_24 sts 0xB4, r24
		#endif
		#if PWM3 == 5
			#define C_PWM3_21 "out 0x28, r21\n"
			#define asm_PWM3_24 out 0x28, r24
		#endif
		#if PWM3 == 6
			#define C_PWM3_21 "out 0x27, r21\n"
			#define asm_PWM3_24 out 0x27, r24
		#endif
		#if PWM3 == 9
			#define C_PWM3_21 "sts 0x88, r21\n"
			#define asm_PWM3_24 sts 0x88, r24
		#endif
		#if PWM3 == 10
			#define C_PWM3_21 "sts 0x8A, r21\n"
			#define asm_PWM3_24 sts 0x8A, r24
		#endif
		#if PWM3 == 11
			#define C_PWM3_21 "sts 0xB3, r21\n"
			#define asm_PWM3_24 sts 0xB3, r24
		#endif
	#endif
	#if	!defined(PWM4Macro)
		#if PWM4 == 3
			#define C_PWM4_21 "sts 0xB4, r21\n"
			#define asm_PWM4_24 sts 0xB4, r24
		#endif
		#if PWM4 == 5
			#define C_PWM4_21 "out 0x28, r21\n"
			#define asm_PWM4_24 out 0x28, r24
		#endif
		#if PWM4 == 6
			#define C_PWM4_21 "out 0x27, r21\n"
			#define asm_PWM4_24 out 0x27, r24
		#endif
		#if PWM4 == 9
			#define C_PWM4_21 "sts 0x88, r21\n"
			#define asm_PWM4_24 sts 0x88, r24
		#endif
		#if PWM4 == 10
			#define C_PWM4_21 "sts 0x8A, r21\n"
			#define asm_PWM4_24 sts 0x8A, r24
		#endif
		#if PWM4 == 11
			#define C_PWM4_21 "sts 0xB3, r21\n"
			#define asm_PWM4_24 sts 0xB3, r24
		#endif
	#endif
#endif
#if mode == 2
	#if !defined(pin1Macro)
		#if pin1 == 2
			#define C_Cpin1 "cbi 0x0B, 2\n"
			#define C_Spin1 "sbi 0x0B, 2\n"
			#define asm_Cpin1 cbi 0x0B, 2
			#define asm_Spin1 sbi 0x0B, 2
		#endif
		#if pin1 == 3
			#define C_Cpin1 "cbi 0x0B, 3\n"
			#define C_Spin1 "sbi 0x0B, 3\n"
			#define asm_Cpin1 cbi 0x0B, 3
			#define asm_Spin1 sbi 0x0B, 3
		#endif
		#if pin1 == 4
			#define C_Cpin1 "cbi 0x0B, 4\n"
			#define C_Spin1 "sbi 0x0B, 4\n"
			#define asm_Cpin1 cbi 0x0B, 4
			#define asm_Spin1 sbi 0x0B, 4
		#endif
		#if pin1 == 5
			#define C_Cpin1 "cbi 0x0B, 5\n"
			#define C_Spin1 "sbi 0x0B, 5\n"
			#define asm_Cpin1 cbi 0x0B, 5
			#define asm_Spin1 sbi 0x0B, 5
		#endif
		#if pin1 == 6
			#define C_Cpin1 "cbi 0x0B, 6\n"
			#define C_Spin1 "sbi 0x0B, 6\n"
			#define asm_Cpin1 cbi 0x0B, 6
			#define asm_Spin1 sbi 0x0B, 6
		#endif
		#if pin1 == 7
			#define C_Cpin1 "cbi 0x0B, 7\n"
			#define C_Spin1 "sbi 0x0B, 7\n"
			#define asm_Cpin1 cbi 0x0B, 7
			#define asm_Spin1 sbi 0x0B, 7
		#endif
		#if pin1 == 8
			#define C_Cpin1 "cbi 0x05, 0\n"
			#define C_Spin1 "sbi 0x05, 0\n"
			#define asm_Cpin1 cbi 0x05, 0
			#define asm_Spin1 sbi 0x05, 0
		#endif
		#if pin1 == 9
			#define C_Cpin1 "cbi 0x05, 1\n"
			#define C_Spin1 "sbi 0x05, 1\n"
			#define asm_Cpin1 cbi 0x05, 1
			#define asm_Spin1 sbi 0x05, 1
		#endif
		#if pin1 == 10
			#define C_Cpin1 "cbi 0x05, 2\n"
			#define C_Spin1 "sbi 0x05, 2\n"
			#define asm_Cpin1 cbi 0x05, 2
			#define asm_Spin1 sbi 0x05, 2
		#endif
		#if pin1 == 11
			#define C_Cpin1 "cbi 0x05, 3\n"
			#define C_Spin1 "sbi 0x05, 3\n"
			#define asm_Cpin1 cbi 0x05, 3
			#define asm_Spin1 sbi 0x05, 3
		#endif
		#if pin1 == 12
			#define C_Cpin1 "cbi 0x05, 4\n"
			#define C_Spin1 "sbi 0x05, 4\n"
			#define asm_Cpin1 cbi 0x05, 4
			#define asm_Spin1 sbi 0x05, 4
		#endif
		#if pin1 == 13
			#define C_Cpin1 "cbi 0x05, 5\n"
			#define C_Spin1 "sbi 0x05, 5\n"
			#define asm_Cpin1 cbi 0x05, 5
			#define asm_Spin1 sbi 0x05, 5
		#endif
	#endif
	#if	!defined(pin2Macro)
		#if pin2 == 2
			#define C_Cpin2 "cbi 0x0B, 2\n"
			#define C_Spin2 "sbi 0x0B, 2\n"
			#define asm_Cpin2 cbi 0x0B, 2
			#define asm_Spin2 sbi 0x0B, 2
		#endif
		#if pin2 == 3
			#define C_Cpin2 "cbi 0x0B, 3\n"
			#define C_Spin2 "sbi 0x0B, 3\n"
			#define asm_Cpin2 cbi 0x0B, 3
			#define asm_Spin2 sbi 0x0B, 3
		#endif
		#if pin2 == 4
			#define C_Cpin2 "cbi 0x0B, 4\n"
			#define C_Spin2 "sbi 0x0B, 4\n"
			#define asm_Cpin2 cbi 0x0B, 4
			#define asm_Spin2 sbi 0x0B, 4
		#endif
		#if pin2 == 5
			#define C_Cpin2 "cbi 0x0B, 5\n"
			#define C_Spin2 "sbi 0x0B, 5\n"
			#define asm_Cpin2 cbi 0x0B, 5
			#define asm_Spin2 sbi 0x0B, 5
		#endif
		#if pin2 == 6
			#define C_Cpin2 "cbi 0x0B, 6\n"
			#define C_Spin2 "sbi 0x0B, 6\n"
			#define asm_Cpin2 cbi 0x0B, 6
			#define asm_Spin2 sbi 0x0B, 6
		#endif
		#if pin2 == 7
			#define C_Cpin2 "cbi 0x0B, 7\n"
			#define C_Spin2 "sbi 0x0B, 7\n"
			#define asm_Cpin2 cbi 0x0B, 7
			#define asm_Spin2 sbi 0x0B, 7
		#endif
		#if pin2 == 8
			#define C_Cpin2 "cbi 0x05, 0\n"
			#define C_Spin2 "sbi 0x05, 0\n"
			#define asm_Cpin2 cbi 0x05, 0
			#define asm_Spin2 sbi 0x05, 0
		#endif
		#if pin2 == 9
			#define C_Cpin2 "cbi 0x05, 1\n"
			#define C_Spin2 "sbi 0x05, 1\n"
			#define asm_Cpin2 cbi 0x05, 1
			#define asm_Spin2 sbi 0x05, 1
		#endif
		#if pin2 == 10
			#define C_Cpin2 "cbi 0x05, 2\n"
			#define C_Spin2 "sbi 0x05, 2\n"
			#define asm_Cpin2 cbi 0x05, 2
			#define asm_Spin2 sbi 0x05, 2
		#endif
		#if pin2 == 11
			#define C_Cpin2 "cbi 0x05, 3\n"
			#define C_Spin2 "sbi 0x05, 3\n"
			#define asm_Cpin2 cbi 0x05, 3
			#define asm_Spin2 sbi 0x05, 3
		#endif
		#if pin2 == 12
			#define C_Cpin2 "cbi 0x05, 4\n"
			#define C_Spin2 "sbi 0x05, 4\n"
			#define asm_Cpin2 cbi 0x05, 4
			#define asm_Spin2 sbi 0x05, 4
		#endif
		#if pin2 == 13
			#define C_Cpin2 "cbi 0x05, 5\n"
			#define C_Spin2 "sbi 0x05, 5\n"
			#define asm_Cpin2 cbi 0x05, 5
			#define asm_Spin2 sbi 0x05, 5
		#endif
	#endif
	#if channel == 2
		#if !defined(pin3Macro)
			#if pin3 == 2
				#define C_Cpin3 "cbi 0x0B, 2\n"
				#define C_Spin3 "sbi 0x0B, 2\n"
				#define asm_Cpin3 cbi 0x0B, 2
				#define asm_Spin3 sbi 0x0B, 2
			#endif
			#if pin3 == 3
				#define C_Cpin3 "cbi 0x0B, 3\n"
				#define C_Spin3 "sbi 0x0B, 3\n"
				#define asm_Cpin3 cbi 0x0B, 3
				#define asm_Spin3 sbi 0x0B, 3
			#endif
			#if pin3 == 4
				#define C_Cpin3 "cbi 0x0B, 4\n"
				#define C_Spin3 "sbi 0x0B, 4\n"
				#define asm_Cpin3 cbi 0x0B, 4
				#define asm_Spin3 sbi 0x0B, 4
			#endif
			#if pin3 == 5
				#define C_Cpin3 "cbi 0x0B, 5\n"
				#define C_Spin3 "sbi 0x0B, 5\n"
				#define asm_Cpin3 cbi 0x0B, 5
				#define asm_Spin3 sbi 0x0B, 5
			#endif
			#if pin3 == 6
				#define C_Cpin3 "cbi 0x0B, 6\n"
				#define C_Spin3 "sbi 0x0B, 6\n"
				#define asm_Cpin3 cbi 0x0B, 6
				#define asm_Spin3 sbi 0x0B, 6
			#endif
			#if pin3 == 7
				#define C_Cpin3 "cbi 0x0B, 7\n"
				#define C_Spin3 "sbi 0x0B, 7\n"
				#define asm_Cpin3 cbi 0x0B, 7
				#define asm_Spin3 sbi 0x0B, 7
			#endif
			#if pin3 == 8
				#define C_Cpin3 "cbi 0x05, 0\n"
				#define C_Spin3 "sbi 0x05, 0\n"
				#define asm_Cpin3 cbi 0x05, 0
				#define asm_Spin3 sbi 0x05, 0
			#endif
			#if pin3 == 9
				#define C_Cpin3 "cbi 0x05, 1\n"
				#define C_Spin3 "sbi 0x05, 1\n"
				#define asm_Cpin3 cbi 0x05, 1
				#define asm_Spin3 sbi 0x05, 1
			#endif
			#if pin3 == 10
				#define C_Cpin3 "cbi 0x05, 2\n"
				#define C_Spin3 "sbi 0x05, 2\n"
				#define asm_Cpin3 cbi 0x05, 2
				#define asm_Spin3 sbi 0x05, 2
			#endif
			#if pin3 == 11
				#define C_Cpin3 "cbi 0x05, 3\n"
				#define C_Spin3 "sbi 0x05, 3\n"
				#define asm_Cpin3 cbi 0x05, 3
				#define asm_Spin3 sbi 0x05, 3
			#endif
			#if pin3 == 12
				#define C_Cpin3 "cbi 0x05, 4\n"
				#define C_Spin3 "sbi 0x05, 4\n"
				#define asm_Cpin3 cbi 0x05, 4
				#define asm_Spin3 sbi 0x05, 4
			#endif
			#if pin3 == 13
				#define C_Cpin3 "cbi 0x05, 5\n"
				#define C_Spin3 "sbi 0x05, 5\n"
				#define asm_Cpin3 cbi 0x05, 5
				#define asm_Spin3 sbi 0x05, 5
			#endif
		#endif
		#if !defined(pin4Macro)
			#if pin4 == 2
				#define C_Cpin4 "cbi 0x0B, 2\n"
				#define C_Spin4 "sbi 0x0B, 2\n"
				#define asm_Cpin4 cbi 0x0B, 2
				#define asm_Spin4 sbi 0x0B, 2
			#endif
			#if pin4 == 3
				#define C_Cpin4 "cbi 0x0B, 3\n"
				#define C_Spin4 "sbi 0x0B, 3\n"
				#define asm_Cpin4 cbi 0x0B, 3
				#define asm_Spin4 sbi 0x0B, 3
			#endif
			#if pin4 == 4
				#define C_Cpin4 "cbi 0x0B, 4\n"
				#define C_Spin4 "sbi 0x0B, 4\n"
				#define asm_Cpin4 cbi 0x0B, 4
				#define asm_Spin4 sbi 0x0B, 4
			#endif
			#if pin4 == 5
				#define C_Cpin4 "cbi 0x0B, 5\n"
				#define C_Spin4 "sbi 0x0B, 5\n"
				#define asm_Cpin4 cbi 0x0B, 5
				#define asm_Spin4 sbi 0x0B, 5
			#endif
			#if pin4 == 6
				#define C_Cpin4 "cbi 0x0B, 6\n"
				#define C_Spin4 "sbi 0x0B, 6\n"
				#define asm_Cpin4 cbi 0x0B, 6
				#define asm_Spin4 sbi 0x0B, 6
			#endif
			#if pin4 == 7
				#define C_Cpin4 "cbi 0x0B, 7\n"
				#define C_Spin4 "sbi 0x0B, 7\n"
				#define asm_Cpin4 cbi 0x0B, 7
				#define asm_Spin4 sbi 0x0B, 7
			#endif
			#if pin4 == 8
				#define C_Cpin4 "cbi 0x05, 0\n"
				#define C_Spin4 "sbi 0x05, 0\n"
				#define asm_Cpin4 cbi 0x05, 0
				#define asm_Spin4 sbi 0x05, 0
			#endif
			#if pin4 == 9
				#define C_Cpin4 "cbi 0x05, 1\n"
				#define C_Spin4 "sbi 0x05, 1\n"
				#define asm_Cpin4 cbi 0x05, 1
				#define asm_Spin4 sbi 0x05, 1
			#endif
			#if pin4 == 10
				#define C_Cpin4 "cbi 0x05, 2\n"
				#define C_Spin4 "sbi 0x05, 2\n"
				#define asm_Cpin4 cbi 0x05, 2
				#define asm_Spin4 sbi 0x05, 2
			#endif
			#if pin4 == 11
				#define C_Cpin4 "cbi 0x05, 3\n"
				#define C_Spin4 "sbi 0x05, 3\n"
				#define asm_Cpin4 cbi 0x05, 3
				#define asm_Spin4 sbi 0x05, 3
			#endif
			#if pin4 == 12
				#define C_Cpin4 "cbi 0x05, 4\n"
				#define C_Spin4 "sbi 0x05, 4\n"
				#define asm_Cpin4 cbi 0x05, 4
				#define asm_Spin4 sbi 0x05, 4
			#endif
			#if pin4 == 13
				#define C_Cpin4 "cbi 0x05, 5\n"
				#define C_Spin4 "sbi 0x05, 5\n"
				#define asm_Cpin4 cbi 0x05, 5
				#define asm_Spin4 sbi 0x05, 5
			#endif
		#endif
	#endif
#endif


#endif


/*
NOTATKI



potrzebne makra/funkcje io:

	(setup)
	?zapisz ustawienia zegarów					c			r25
	?zapisz ustawienia pinów					c			-
	=zapisz ustawienia ADC (ADCSRA)				c asm		r25

	(inne)
	+zapisz ustawienia zegar przerwania			c asm		r25; r25
	+odczytaj ustawienia zegar przerwania		asm			r25
	+zapisz PWM									c asm		r21, r20; r24	|
	+w³¹cz pin									c asm		-				|
	+wy³acz pin									c asm		-				|
	=zapisz ustawienia ADC (ADMUX)				c asm		r25; r25
	=odczytaj ustawienia ADC (ADMUX)			asm			r25
	=odczytaj wartoœæ ADC (ADCH)				c			r16				|


= sta³a definicja (sta³y adres, zostawiæ)
? ró¿na iloœæ elementów do ustawienia (setup)
| wykorzystywane w przerwaniu
- nie zrobione
+ zrobione
sprawdziæ rejestry!






+sprawdzanie u¿ytych makr

+sprawdzanie trybu (tryb, iloœæ kana³ów)
	mode (1, 2, 3)
	channel (1, 2)
	
+sprawdzanie czy potrzebne io zosta³o poprawnie zdefiniowane
	(b³¹d je¿eli nie zdefiniowano ani definicji ani makra)
	(osobnie dla ka¿dego pinu/io)
	0-nie zdefiniowano
	1-zdefiniowano (poprawnie)
	makro	pin		wynik
	0		0		b³¹d - brak definicji
	0		1		ok
	1		0		ok
	1		1		ok		???
	

+sprawdzanie czy piny nie pokrywaj¹ siê ze sob¹
	(je¿eli zdefiniowano pin)
	(je¿eli kolejny pin zosta³ zdefiniowany to jest on sprawdzany z pozosta³ymi)
	makro	pin		wynik
	0		0		nie sprawdzaæ tej opcji
	0		1		sprawdzanie poprawnoœci z innymi pinami
	1		0		pomiñ sprawdzanie tego pinu
	1		1		sprawdzanie numeru z innymi pianmi		???


+deklarowanie/w³¹czanie ustawnieñ dla setapu
	(je¿eli zdefiniowano pin)
	makro	pin		wynik
	0		0		nie sprawdzaæ tej opcji
	0		1		w³¹cz ustawienie w setapie
	1		0		nic nierób
	1		1		w³¹cz ustawienie w setapie (jeœli to mo¿liwe)	???


+deklarowanie makr
	makro	pin		wynik
	0		0		nie sprawdzaæ tej opcji
	0		1		zadeklaruj makro
	1		0		nic nierób
	1		1		nic nierób




podsumowanie, u¿yte funkcjie (makra):
asm_STI_25
asm_LTI_25

asm_PWM1_24
asm_PWM2_24
asm_PWM3_24
asm_PWM4_24
C_PWM1_20
C_PWM2_21
C_PWM2_20
C_PWM3_21
C_PWM4_21

asm_Cpin1
asm_Spin1
asm_Cpin2
asm_Spin2
asm_Cpin3
asm_Spin3
asm_Cpin4
asm_Spin4
C_Cpin1
C_Spin1
C_Cpin2
C_Spin2
C_Cpin3
C_Spin3
C_Cpin4
C_Spin4




plik S
//funkcje
#ifndef disable_secondProgram
.extern secondprogram
#endif



(szkice)
ustawienia fal (dane wejœciowe):
-tryb ustawienia fali (faza, czêstotliwoœæ, g³oœnoœæ)
-numer fali
-wartoœ do zapisania
void ustawfale([numer fali], [tryb], [wartoœæ])

???adres pamiêci liczony w assemblerze lub liczony w c (sta³a/zmienna wartoœæ)???


w przysz³oœci:
odczytywanie czystych danych z pamiêci (bez wykonywania instrukcji asm)
-tryb (sprawdzanie trybu):
 -faza
 -czêstotliwoœæ
 -g³oœnoœæ
 -czekanie
-zapisanie kolejnych wartoœci do ram
  

organizacja pamiêci:
[tryb - 2B (ew. 3B) | numer fali/iloœæ bajtów czekania - 6B (ew. 5B)] [wartoœæ (hb)] [wartoœæ (lb)]





*/