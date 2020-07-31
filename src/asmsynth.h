#ifndef MusicSynthesizer_h
#define MusicSynthesizer_h
#include <config.h>



//12-TET, in tune: a4=440hz
#define TUNE 440 //in hz
#define TONE_INTERVAL 2
#define NUMBER_OF_TONES 12
#define KEY_SHIFT 69 //midi number: 69 (a4 has a 69 key number), piano keyboard: 49 (a4=49)
//define enable_quickProgramChange
//define lowProgramMemory

#ifdef enable_highSamplingRate
#define INTERRUPT_COUNTER 2
#else
#define INTERRUPT_COUNTER 4
#endif

#ifndef F_CPU
#define F_CPU 16000000
#endif

//#ifdef F_CPU
#define SOUND_SAMPLING 1000000*256*INTERRUPT_COUNTER/F_CPU
//#else
//#define SOUND_SAMPLING 64 //in microseconds
//#endif





#if polyphony > 0
	volatile char w01[5];
	void wave01();
#endif
#if polyphony > 1
	volatile char w02[5];
	void wave02();
#endif
#if polyphony > 2
	volatile char w03[5];
	void wave03();
#endif
#if polyphony > 3
	volatile char w04[5];
	void wave04();
#endif
#if polyphony > 4
	volatile char w05[5];
	void wave05();
#endif
#if polyphony > 5
	volatile char w06[5];
	void wave06();
#endif
#if polyphony > 6
	volatile char w07[5];
	void wave07();
#endif
#if polyphony > 7
	volatile char w08[5];
	void wave08();
#endif
#if polyphony > 8
	volatile char w09[5];
	void wave09();
#endif
#if polyphony > 9
	volatile char w10[5];
	void wave10();
#endif
#if polyphony > 10
	volatile char w11[5];
	void wave11();
#endif
#if polyphony > 11
	volatile char w12[5];
	void wave12();
#endif
#if polyphony > 12
	volatile char w13[5];
	void wave13();
#endif
#if polyphony > 13
	volatile char w14[5];
	void wave14();
#endif
#if polyphony > 14
	volatile char w15[5];
	void wave15();
#endif
#if polyphony > 15
	volatile char w16[5];
	void wave16();
#endif
#if polyphony > 16
	volatile char w17[5];
	void wave17();
#endif
#if polyphony > 17
	volatile char w18[5];
	void wave18();
#endif
#if polyphony > 18
	volatile char w19[5];
	void wave19();
#endif
#if polyphony > 19
	volatile char w20[5];
	void wave20();
#endif
#if polyphony > 20
	volatile char w21[5];
	void wave21();
#endif
#if polyphony > 21
	volatile char w22[5];
	void wave22();
#endif
#if polyphony > 22
	volatile char w23[5];
	void wave23();
#endif
#if polyphony > 23
	volatile char w24[5];
	void wave24();
#endif
#if polyphony > 24
	volatile char w25[5];
	void wave25();
#endif
#if polyphony > 25
	volatile char w26[5];
	void wave26();
#endif
#if polyphony > 26
	volatile char w27[5];
	void wave27();
#endif
#if polyphony > 27
	volatile char w28[5];
	void wave28();
#endif
#if polyphony > 28
	volatile char w29[5];
	void wave29();
#endif
#if polyphony > 29
	volatile char w30[5];
	void wave30();
#endif
#if polyphony > 30
	volatile char w31[5];
	void wave31();
#endif
#if polyphony > 31
	volatile char w32[5];
	void wave32();
#endif





#if mode == 2
	volatile char sPin;
#endif

#ifndef disable_secondProgram
	volatile unsigned long sTime;
	volatile unsigned long sDelay;
	volatile unsigned int ProgramCounter;
#else
	volatile char sTime;
#endif

#ifndef disable_volume
	volatile char sVolume;
#endif

#ifdef enable_motor
	volatile char sMotorA;
	#if channel == 2
		volatile char sMotorB;
	#endif
#endif



void startinterrupt();
void endinterrupt();
void inline squareWave() __attribute__((always_inline));
void inline sawWave() __attribute__((always_inline));
void inline triangleWave() __attribute__((always_inline));
//void sinWave();
//void noise();

int hz(double hz);
unsigned int keyboard(double key);
unsigned int keyboard(double key, double cent);

#ifndef disable_secondProgram
	void delay_ms(float a);
	float get_ms();
#endif


extern "C"
{
	void synthSetup();

	void pause();
	void play();
	void reset();
	void stop();
	
	#ifndef disable_volume
		void volume(char a);
	#endif

	#ifdef enable_ADC
		void ADCchannel(char a);
	#endif

	#ifdef enable_motor
		void motorA(char a);
		#if channel == 2
			void motorB(char b);
		#endif
	#endif

	#ifndef disable_secondProgram
		void delay_ci(unsigned long a);
		unsigned long get_ci();
	#else
		unsigned char get_ci();
	#endif



	//void wave(char wave, char mode, unsigned float value);
	#ifndef lowProgramMemory
		#if polyphony > 0
			void wave01_volume(char a);
			void wave01_phase(int a);
			void wave01_frequency(int a);
		#endif
		#if polyphony > 1
			void wave02_volume(char a);
			void wave02_phase(int a);
			void wave02_frequency(int a);
		#endif
		#if polyphony > 2
			void wave03_volume(char a);
			void wave03_phase(int a);
			void wave03_frequency(int a);
		#endif
		#if polyphony > 3
			void wave04_volume(char a);
			void wave04_phase(int a);
			void wave04_frequency(int a);
		#endif
		#if polyphony > 4
			void wave05_volume(char a);
			void wave05_phase(int a);
			void wave05_frequency(int a);
		#endif
		#if polyphony > 5
			void wave06_volume(char a);
			void wave06_phase(int a);
			void wave06_frequency(int a);
		#endif
		#if polyphony > 6
			void wave07_volume(char a);
			void wave07_phase(int a);
			void wave07_frequency(int a);
		#endif
		#if polyphony > 7
			void wave08_volume(char a);
			void wave08_phase(int a);
			void wave08_frequency(int a);
		#endif
		#if polyphony > 8
			void wave09_volume(char a);
			void wave09_phase(int a);
			void wave09_frequency(int a);
		#endif
		#if polyphony > 9
			void wave10_volume(char a);
			void wave10_phase(int a);
			void wave10_frequency(int a);
		#endif
		#if polyphony > 10
			void wave11_volume(char a);
			void wave11_phase(int a);
			void wave11_frequency(int a);
		#endif
		#if polyphony > 11
			void wave12_volume(char a);
			void wave12_phase(int a);
			void wave12_frequency(int a);
		#endif
		#if polyphony > 12
			void wave13_volume(char a);
			void wave13_phase(int a);
			void wave13_frequency(int a);
		#endif
		#if polyphony > 13
			void wave14_volume(char a);
			void wave14_phase(int a);
			void wave14_frequency(int a);
		#endif
		#if polyphony > 14
			void wave15_volume(char a);
			void wave15_phase(int a);
			void wave15_frequency(int a);
		#endif
		#if polyphony > 15
			void wave16_volume(char a);
			void wave16_phase(int a);
			void wave16_frequency(int a);
		#endif
		#if polyphony > 16
			void wave17_volume(char a);
			void wave17_phase(int a);
			void wave17_frequency(int a);
		#endif
		#if polyphony > 17
			void wave18_volume(char a);
			void wave18_phase(int a);
			void wave18_frequency(int a);
		#endif
		#if polyphony > 18
			void wave19_volume(char a);
			void wave19_phase(int a);
			void wave19_frequency(int a);
		#endif
		#if polyphony > 19
			void wave20_volume(char a);
			void wave20_phase(int a);
			void wave20_frequency(int a);
		#endif
		#if polyphony > 20
			void wave21_volume(char a);
			void wave21_phase(int a);
			void wave21_frequency(int a);
		#endif
		#if polyphony > 21
			void wave22_volume(char a);
			void wave22_phase(int a);
			void wave22_frequency(int a);
		#endif
		#if polyphony > 22
			void wave23_volume(char a);
			void wave23_phase(int a);
			void wave23_frequency(int a);
		#endif
		#if polyphony > 23
			void wave24_volume(char a);
			void wave24_phase(int a);
			void wave24_frequency(int a);
		#endif
		#if polyphony > 24
			void wave25_volume(char a);
			void wave25_phase(int a);
			void wave25_frequency(int a);
		#endif
		#if polyphony > 25
			void wave26_volume(char a);
			void wave26_phase(int a);
			void wave26_frequency(int a);
		#endif
		#if polyphony > 26
			void wave27_volume(char a);
			void wave27_phase(int a);
			void wave27_frequency(int a);
		#endif
		#if polyphony > 27
			void wave28_volume(char a);
			void wave28_phase(int a);
			void wave28_frequency(int a);
		#endif
		#if polyphony > 28
			void wave29_volume(char a);
			void wave29_phase(int a);
			void wave29_frequency(int a);
		#endif
		#if polyphony > 29
			void wave30_volume(char a);
			void wave30_phase(int a);
			void wave30_frequency(int a);
		#endif
		#if polyphony > 30
			void wave31_volume(char a);
			void wave31_phase(int a);
			void wave31_frequency(int a);
		#endif
		#if polyphony > 31
			void wave32_volume(char a);
			void wave32_phase(int a);
			void wave32_frequency(int a);
		#endif
	#endif
}



//definitions
#define start_interrupt \
extern "C" void vectorInterrupt () __attribute__ ((signal, naked, used)); \
void vectorInterrupt () { \
startinterrupt();


#define end_interrupt \
endinterrupt();}

//na przysz³oœæ:
//dodaæ atrybut przerwania (przenoszenie rejestrów na stos)
//dodaæ osobny stos dla drugiego programu
#ifndef disable_secondProgram
#define start_secondProgram \
extern "C" void secondprogram() __attribute__ ((naked));\
void secondprogram() { \
asm volatile ("playMusic:\n");


#define end_secondProgram \
asm volatile("jmp playMusic\n");}
#endif



//12 equal temperament
//a=440hz

//#undef B0
//#undef B1

#define c0 hz(16.3515978313)
#define cs0 hz(17.3239144361)
#define d0 hz(18.3540479948)
#define ds0 hz(19.4454364826)
#define e0 hz(20.6017223071)
#define f0 hz(21.8267644646)
#define fs0 hz(23.1246514195)
#define g0 hz(24.4997147489)
#define gs0 hz(25.9565435987)
#define a0 hz(27.5)
#define as0 hz(29.1352350949)
#define b0 hz(30.8677063285)
#define h0 hz(30.8677063285)

#define c1 hz(32.7031956626)
#define cs1 hz(34.6478288721)
#define d1 hz(36.7080959897)
#define ds1 hz(38.8908729653)
#define e1 hz(41.20344446141)
#define f1 hz(43.6535289291)
#define fs1 hz(46.249302839)
#define g1 hz(48.9994294977)
#define gs1 hz(51.9130871975)
#define a1 hz(55)
#define as1 hz(58.2704701898)
#define b1 hz(61.735412657)
#define h1 hz(61.735412657)

#define c2 hz(65.4063913251)
#define cs2 hz(69.2956577442)
#define d2 hz(73.4161919794)
#define ds2 hz(77.7817459305)
#define e2 hz(82.4068892282)
#define f2 hz(87.3070578583)
#define fs2 hz(92.4986056779)
#define g2 hz(97.9988589954)
#define gs2 hz(103.823174395)
#define a2 hz(110)
#define as2 hz(116.5409403795)
#define b2 hz(123.470825314)
#define h2 hz(123.470825314)

#define c3 hz(130.8127826503)
#define cs3 hz(138.5913154884)
#define d3 hz(146.8323839587)
#define ds3 hz(155.563491861)
#define e3 hz(164.8137784564)
#define f3 hz(174.6141157165)
#define fs3 hz(184.9972113558)
#define g3 hz(195.9977179909)
#define gs3 hz(207.65234897)
#define a3 hz(220)
#define as3 hz(233.081880759)
#define b3 hz(246.9416506281)
#define h3 hz(246.9416506281)

#define c4 hz(261.6255653006)
#define cs4 hz(277.1826309769)
#define d4 hz(293.6647679174)
#define ds4 hz(311.1269837221)
#define e4 hz(329.6275569129)
#define f4 hz(349.228231433)
#define fs4 hz(369.9944227116)
#define g4 hz(391.9954359817)
#define	gs4 hz(415.3046975799)
#define	a4 hz(440)
#define as4 hz(466.1637615181)
#define b4 hz(493.8833012561)
#define h4 hz(493.8833012561)

#define c5 hz(523.2511306012)
#define cs5 hz(554.3652619537)
#define d5 hz(587.3295358348)
#define ds5 hz(622.2539674442)
#define e5 hz(659.2551138257)
#define f5 hz(698.456462866)
#define fs5 hz(739.9888454233)
#define g5 hz(783.9908719635)
#define gs5 hz(830.6093951599)
#define a5 hz(880)
#define as5 hz(932.3275230362)
#define b5 hz(987.7666025122)
#define h5 hz(987.7666025122)

#define c6 hz(1046.5022612024)
#define cs6 hz(1108.7305239075)
#define d6 hz(1174.6590716696)
#define ds6 hz(1244.5079348883)
#define e6 hz(1318.5102276515)
#define f6 hz(1396.912925732)
#define fs6 hz(1479.9776908465)
#define g6 hz(1567.981743927)
#define gs6 hz(1661.2187903198)
#define a6 hz(1760)
#define as6 hz(1864.6550460724)
#define b6 hz(1975.5332050245)
#define h6 hz(1975.5332050245)

#define c7 hz(2093.0045224048)
#define cs7 hz(2217.461047815)
#define d7 hz(2349.3181433393)
#define ds7 hz(2489.0158697766)
#define e7 hz(2637.020455303)
#define f7 hz(2793.825851464)
#define fs7 hz(2959.9553816931)
#define g7 hz(3135.963487854)
#define gs7 hz(3322.4375806396)
#define a7 hz(3520)
#define as7 hz(3729.3100921447)
#define b7 hz(3951.066410049)
#define h7 hz(3951.066410049)

#define c8 hz(4186.0090448096)
#define cs8 hz(4434.92209563)
#define d8 hz(4698.6362866785)
#define ds8 hz(4978.0317395533)
#define e8 hz(5247.0409106059)
#define f8 hz(5587.6517029281)
#define fs8 hz(5919.9107633862)
#define g8 hz(6271.926975708)
#define gs8 hz(6644.8751612791)
#define a8 hz(7040)
#define as8 hz(7458.6201842894)

#define b8 hz(7902.132820098)
#define h8 hz(7902.132820098)



#define MusicSynthesizer_c
#include <asmsynth.c>
#undef MusicSynthesizer_c
#endif