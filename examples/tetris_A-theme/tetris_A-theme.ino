//requirements:
//3 voices
//5kb +/- program memory



#include <asmsynth.h>

#define DELAY delay_ms(200);


byte counter;

void setup()
{
  synthSetup();
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}



void stop01()
{
  wave01_volume(0);
  wave01_frequency(0);
  wave01_phase(0);
}

void stop02()
{
  wave02_volume(0);
  wave02_frequency(0);
  wave02_phase(0);
}

void stop03()
{
  wave03_volume(0);
  wave03_frequency(0);
  wave03_phase(1<<14);
}



start_interrupt
  wave01();
  squareWave();
  wave02();
  squareWave();
  wave03();
  triangleWave();
end_interrupt

start_secondProgram
  counter=0;
  while(counter!=2)
  {
    wave01_volume(15);
    wave02_volume(15);
    wave03_volume(193);
    wave01_frequency(e5);
    wave02_frequency(b4);
    wave03_frequency(e2);
    DELAY
    wave03_frequency(e3);
    DELAY
    wave01_frequency(b4);
    wave02_frequency(gs4);
    wave03_frequency(e2);
    DELAY
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(e3);
    DELAY
    
    wave01_frequency(d5);
    wave02_frequency(b4);
    wave03_frequency(e2);
    DELAY
    wave03_frequency(e3);
    DELAY
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(e2);
    DELAY
    wave01_frequency(b4);
    wave02_frequency(gs4);
    wave03_frequency(e3);
    DELAY
    
    wave01_frequency(a4);
    wave02_frequency(e4);
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    wave03_frequency(a2);
    DELAY
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(a3);
    DELAY
    
    wave01_frequency(e5);
    wave02_frequency(c5);
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    wave01_frequency(d5);
    wave02_frequency(b4);
    wave03_frequency(a2);
    DELAY
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(a3);
    DELAY
    
    wave01_frequency(b4);
    wave02_frequency(gs4);
    wave03_frequency(gs2);
    DELAY
    wave03_frequency(gs3);
    DELAY
    wave03_frequency(gs2);
    DELAY
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(gs3);
    DELAY
    
    wave01_frequency(d5);
    wave02_frequency(b4);
    wave03_frequency(e2);
    DELAY
    wave03_frequency(e3);
    DELAY
    wave01_frequency(e5);
    wave02_frequency(b4);
    wave03_frequency(e2);
    DELAY
    wave03_frequency(e3);
    DELAY
    
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    wave01_frequency(a4);
    wave02_frequency(e4);
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    stop01();
    stop02();
    wave03_frequency(b2);
    DELAY
    wave03_frequency(c3);
    DELAY
    
    wave01_volume(15);
    wave02_volume(15);
    wave01_frequency(d5);
    wave02_frequency(a4);
    wave03_frequency(d2);
    DELAY
    wave03_frequency(d3);
    DELAY
    wave03_frequency(d2);
    DELAY
    wave01_frequency(f5);
    wave02_frequency(d5);
    wave03_frequency(d3);
    DELAY
    
    wave01_frequency(a5);
    wave02_frequency(f5);
    wave03_frequency(d2);
    DELAY
    wave03_frequency(d3);
    DELAY
    wave01_frequency(g5);
    wave02_frequency(e5);
    wave03_frequency(d2);
    DELAY
    wave01_frequency(f5);
    wave02_frequency(d5);
    wave03_frequency(d3);
    DELAY
    
    wave01_frequency(e5);
    wave02_frequency(c5);
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    wave03_frequency(a2);
    DELAY
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(a3);
    DELAY
    
    wave01_frequency(e5);
    wave02_frequency(c5);
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    wave01_frequency(d5);
    wave02_frequency(b4);
    wave03_frequency(a2);
    DELAY
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(a3);
    DELAY
    
    wave01_frequency(b4);
    wave02_frequency(gs4);
    wave03_frequency(gs2);
    DELAY
    wave03_frequency(gs3);
    DELAY
    wave03_frequency(gs2);
    DELAY
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(gs3);
    DELAY
    
    wave01_frequency(d5);
    wave02_frequency(b4);
    wave03_frequency(e2);
    DELAY
    wave03_frequency(e3);
    DELAY
    wave01_frequency(e5);
    wave02_frequency(b4);
    wave03_frequency(e2);
    DELAY
    wave03_frequency(e3);
    DELAY
    
    wave01_frequency(c5);
    wave02_frequency(a4);
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    wave01_frequency(a4);
    wave02_frequency(e4);
    wave03_frequency(a2);
    DELAY
    wave03_frequency(a3);
    DELAY
    
    wave03_frequency(a2);
    DELAY
    DELAY
    stop01();
    stop02();
    stop03();
    DELAY
    DELAY
    
    counter=counter+1;
  }

  counter=0;
  while(counter!=2)
  {
    wave01_volume(30);
    wave02_volume(30);
    wave03_volume(133);
    wave01_frequency(e4);
    wave02_frequency(c4);
    wave03_frequency(a4);
    DELAY
    wave03_frequency(e5);
    DELAY
    wave03_frequency(a4);
    DELAY
    wave03_frequency(e5);
    DELAY
    
    wave01_frequency(c4);
    wave02_frequency(a3);
    wave03_frequency(a4);
    DELAY
    wave03_frequency(e5);
    DELAY
    wave03_frequency(a4);
    DELAY
    wave03_frequency(e5);
    DELAY
    
    wave01_frequency(d4);
    wave02_frequency(b3);
    wave03_frequency(gs4);
    DELAY
    wave03_frequency(e5);
    DELAY
    wave03_frequency(gs4);
    DELAY
    wave03_frequency(e5);
    DELAY
    
    wave01_frequency(b3);
    wave02_frequency(gs3);
    wave03_frequency(gs4);
    DELAY
    wave03_frequency(e5);
    DELAY
    wave03_frequency(gs4);
    DELAY
    wave03_frequency(e5);
    DELAY

    if(counter==0)
    {
      wave01_frequency(c4);
      wave02_frequency(a3);
      wave03_frequency(a4);
      DELAY
      wave03_frequency(e5);
      DELAY
      wave03_frequency(a4);
      DELAY
      wave03_frequency(e5);
      DELAY
      
      wave01_frequency(a3);
      wave02_frequency(e3);
      wave03_frequency(a4);
      DELAY
      wave03_frequency(e5);
      DELAY
      wave03_frequency(a4);
      DELAY
      wave03_frequency(e5);
      DELAY
      
      wave01_frequency(gs3);
      wave02_frequency(e3);
      wave03_frequency(gs4);
      DELAY
      wave03_frequency(e5);
      DELAY
      wave03_frequency(gs4);
      DELAY
      wave03_frequency(e5);
      DELAY
      
      wave01_frequency(b3);
      wave02_frequency(gs3);
      wave03_frequency(gs4);
      DELAY
      wave03_frequency(e5);
      DELAY
      wave03_frequency(gs4);
      DELAY
      wave03_frequency(e5);
      DELAY
    }
    counter=counter+1;
  }

  
  wave01_frequency(c4);
  wave02_frequency(a3);
  wave03_frequency(a4);
  DELAY
  wave03_frequency(e5);
  DELAY
  wave01_frequency(e4);
  wave02_frequency(c4);
  wave03_frequency(a4);
  DELAY
  wave03_frequency(e5);
  DELAY
  
  wave01_frequency(a4);
  wave02_frequency(e4);
  wave03_frequency(a4);
  DELAY
  wave03_frequency(e5);
  DELAY
  wave03_frequency(a4);
  DELAY
  wave03_frequency(e5);
  DELAY
  
  wave01_frequency(gs4);
  wave02_frequency(e4);
  wave03_frequency(gs4);
  DELAY
  wave03_frequency(e5);
  DELAY
  wave03_frequency(gs4);
  DELAY
  wave03_frequency(e5);
  DELAY

  stop01();
  stop02();
  stop03();
  DELAY
  DELAY
  DELAY
  DELAY
end_secondProgram
