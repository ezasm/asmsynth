#ifndef config
#define config





//main setting:
	#define polyphony 16
	#define mode 1
	#define channel 1

//io setting:
	#define timerInterrupt 2
	#define PWM1 11
	//#define PWM2 10
	//#define PWM3 9
	//#define PWM4 3
	//#define pin1 10
	//#define pin2 9
	//#define pin3 5
	//#define pin4 6


//additional options:
	//#define disable_volume
	//#define disable_secondProgram
	//#define enable_highSamplingRate
	//#define enable_motor
	//#define enable_ADC














//manual mode:
	//timerInterrupt:
		//#define vectorInterrupt __vector_0
		//#define asm_STI_25 sts 0x00, r25
		//#define asm_LTI_25 lds r25, 0x00
	//PWM:
		//PWM1:
			//#define C_PWM1_21 "sts 0x00, r21\n"
			//#define asm_PWM1_24 sts 0x00, r24
		//PWM2:
			//#define C_PWM2_20 "sts 0x00, r20\n"
			//#define C_PWM2_21 "sts 0x00, r21\n"
			//#define asm_PWM2_24 sts 0x00, r24
		//PWM3:
			//#define C_PWM3_20 "sts 0x00, r20\n"
			//#define asm_PWM3_24 sts 0x00, r24
		//PWM4:
			//#define C_PWM4_20 "sts 0x00, r20\n"
			//#define asm_PWM4_24 sts 0x00, r24
	//pins:
		//pin1:
			//#define C_Cpin1 "cbi 0x00, 0\n"
			//#define C_Spin1 "sbi 0x00, 0\n"
			//#define asm_Cpin1 cbi 0x00, 0
			//#define asm_Spin1 sbi 0x00, 0
		//pin2:
			//#define C_Cpin2 "cbi 0x00, 0\n"
			//#define C_Spin2 "sbi 0x00, 0\n"
			//#define asm_Cpin2 cbi 0x00, 0
			//#define asm_Spin2 sbi 0x00, 0
		//pin3:
			//#define C_Cpin3 "cbi 0x00, 0\n"
			//#define C_Spin3 "sbi 0x00, 0\n"
			//#define asm_Cpin3 cbi 0x00, 0
			//#define asm_Spin3 sbi 0x00, 0
		//pin4:
			//#define C_Cpin4 "cbi 0x00, 0\n"
			//#define C_Spin4 "sbi 0x00, 0\n"
			//#define asm_Cpin4 cbi 0x00, 0
			//#define asm_Spin4 sbi 0x00, 0
	
	
	
	
	
#include <iosupport.h>
#endif