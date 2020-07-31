//requirements:
//11 voices
//13kb +/- program memory


#include <asmsynth.h>
volatile byte counter;

void setup()
{
  synthSetup();
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}





start_interrupt
  wave01();
  squareWave();
  
  wave02();
  squareWave();
  
  wave03();
  squareWave();
  
  wave04();
  squareWave();
  
  wave05();
  squareWave();
  
  wave06();
  squareWave();
  
  wave07();
  squareWave();
  
  wave08();
  squareWave();
  
  wave09();
  sawWave();
  
  wave10();
  sawWave();
  
  wave11();
  triangleWave();
end_interrupt





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
  wave03_phase(0);
}

void stop04()
{
  wave04_volume(0);
  wave04_frequency(0);
  wave04_phase(0);
}

void stop05()
{
  wave05_volume(0);
  wave05_frequency(0);
  wave05_phase(0);
}

void stop06()
{
  wave06_volume(0);
  wave06_frequency(0);
  wave06_phase(0);
}

void stop07()
{
  wave07_volume(0);
  wave07_frequency(0);
  wave07_phase(0);
}

void stop08()
{
  wave08_volume(0);
  wave08_frequency(0);
  wave08_phase(0);
}

void stop09()
{
  wave09_volume(0);
  wave09_frequency(0);
  wave09_phase(0);
}

void stop10()
{
  wave10_volume(0);
  wave10_frequency(0);
  wave10_phase(0);
}

void stop11()
{
  wave11_volume(0);
  wave11_frequency(0);
  wave11_phase(1<<14);
}




void voice01(unsigned int a)
{
  cli();
  wave09_frequency(a);
  wave01_frequency(a<<1);
  sei();
}

void voice01v()
{
  //wave01_phase(1<<13);
  wave01_volume(85);//65
  wave09_volume(160);//123
}

void voice01s()
{
  stop01();
  stop09();
}



inline void voice02(unsigned int a) __attribute__((always_inline));
void voice02(unsigned int a)
{
  wave09_frequency(a);
  wave10_frequency(a*0.997);
}

void voice02v()
{
  wave09_volume(127);
  wave10_volume(127);
}

void voice02s()
{
  stop09();
  stop10();
}



void voice03(unsigned int a)
{
  if(counter==0)
    wave09_frequency(a>>1);
  else
    wave01_frequency(a);
}



void voice04(unsigned int a)
{
  byte i=counter;
  while(i!=0)
  {
    a=a>>1;
    i=i-1;
  }
  wave01_frequency(a);
}



start_secondProgram
  voice01v();
  voice01(a4);
  delay_ms(100);
  
  voice01(g4);
  delay_ms(100);
  
  voice01(a4);
  delay_ms(1500);

  voice01s();
  delay_ms(1500);
  


  voice01v();
  voice01(g4);
  delay_ms(225);

  voice01(f4);
  delay_ms(150);

  voice01(e4);
  delay_ms(135);

  voice01(d4);
  delay_ms(125);

  voice01(cs4);
  delay_ms(650);

  voice01(d4);
  delay_ms(1500);
  
  voice01s();
  delay_ms(2000);



  
  voice02v();
  voice02(a3);
  delay_ms(100);
  
  voice02(g3);
  delay_ms(100);
  
  voice02(a3);
  delay_ms(1500);

  voice02s();
  delay_ms(1000);

  voice02v();
  voice02(e3);
  delay_ms(400);

  voice02(f3);
  delay_ms(350);
  
  voice02(cs3);
  delay_ms(450);

  voice02(d3);
  delay_ms(1500);

  voice02s();
  delay_ms(2000);


  





  voice01v();
  voice01(a2);
  delay_ms(100);
  
  voice01(g2);
  delay_ms(100);
  
  voice01(a2);
  delay_ms(1500);

  voice01s();
  delay_ms(1500);
  


  voice01v();
  voice01(g2);
  delay_ms(155);

  voice01(f2);
  delay_ms(140);

  voice01(e2);
  delay_ms(130);

  voice01(d2);
  delay_ms(125);

  voice01(cs2);
  delay_ms(650);

  voice01(d2);
  delay_ms(1500);

  voice01s();
  delay_ms(2000);




  wave09_volume(255);
  wave09_frequency(d1);
  delay_ms(2000);
  
  wave09_volume(191);
  wave01_volume(31);
  wave01_frequency(cs3);
  delay_ms(750);
  
  wave09_volume(151);
  wave01_volume(25);
  wave02_volume(25);
  wave02_frequency(e3);
  delay_ms(700);

  wave09_volume(123);
  wave01_volume(21);
  wave02_volume(21);
  wave03_volume(21);
  wave03_frequency(g3);
  delay_ms(650);

  wave09_volume(103);
  wave01_volume(18);
  wave02_volume(18);
  wave03_volume(18);
  wave04_volume(18);
  wave04_frequency(as3);
  delay_ms(800);
  
  wave09_volume(95);
  wave01_volume(15);
  wave02_volume(15);
  wave03_volume(15);
  wave04_volume(15);
  wave05_volume(15);
  wave05_frequency(cs4);
  delay_ms(1000);
  
  wave09_volume(75);
  wave01_volume(14);
  wave02_volume(14);
  wave03_volume(14);
  wave04_volume(14);
  wave05_volume(14);
  wave06_volume(14);
  wave06_frequency(e4);
  delay_ms(1500);




  wave09_volume(121);
  wave01_volume(14);
  stop02();
  wave03_volume(20);
  wave04_volume(14);
  wave05_volume(14);
  stop06();
  wave01_frequency(d3);
  wave04_frequency(a3);
  wave05_frequency(d4);
  delay_ms(1000);

  wave03_frequency(e3);
  delay_ms(1500);
    
  wave03_frequency(fs3);
  delay_ms(3000);





  
  stop01();
  stop03();
  stop04();
  stop05();
  stop09();
  delay_ms(2000);



  wave09_volume(150);

  counter=0;
  while(counter!=2)
  { 
    voice03(cs5);
    delay_ms(300);
    
    voice03(d5);
    delay_ms(220);
    
    voice03(e5);
    delay_ms(150);
    
    voice03(cs5);
    delay_ms(130);
    
    voice03(d5);
    delay_ms(120);
    
    voice03(e5);
    delay_ms(120);
    
    voice03(cs5);
    delay_ms(120);
    
    voice03(d5);
    delay_ms(120);
    
    voice03(e5);
    delay_ms(130);
    
    voice03(cs5);
    delay_ms(150);
    
    voice03(d5);
    delay_ms(220);
    
    voice03(e5);
    delay_ms(300);
    
    voice03(f5);
    delay_ms(220);
    
    voice03(g5);
    delay_ms(150);
    
    voice03(e5);
    delay_ms(130);
    
    voice03(f5);
    delay_ms(120);
    
    voice03(g5);
    delay_ms(120);
    
    voice03(e5);
    delay_ms(120);
    
    voice03(f5);
    delay_ms(120);
    
    voice03(g5);
    delay_ms(130);
    
    voice03(e5);
    delay_ms(150);
    
    voice03(f5);
    delay_ms(220);
    
    voice03(g5);
    delay_ms(300);
    
    voice03(a5);
    delay_ms(220);
    
    voice03(as5);
    delay_ms(150);
    
    voice03(g5);
    delay_ms(130);
    
    voice03(a5);
    delay_ms(120);
    
    voice03(as5);
    delay_ms(120);
    
    voice03(g5);
    delay_ms(120);
    
    voice03(a5);
    delay_ms(140);
    
    voice03(as5);
    delay_ms(200);
    
    voice03(g5);
    delay_ms(300);
    
    voice03(a5);
    delay_ms(1000);
    
    voice01s();
    delay_ms(2000);
    
    counter=counter+1;
    wave01_volume(75);
  }




  voice01v();
  voice01(a4);
  delay_ms(350);

  voice01(g4);
  delay_ms(250);

  voice01(as4);
  delay_ms(200);

  voice01(e4);
  delay_ms(170);

  voice01(g4);
  delay_ms(150);

  voice01(as4);
  delay_ms(135);

  voice01(e4);
  delay_ms(125);

  voice01(f4);
  delay_ms(120);

  voice01(a4);
  delay_ms(115);

  voice01(d4);
  delay_ms(110);

  voice01(f4);
  delay_ms(110);

  voice01(a4);
  delay_ms(110);

  voice01(d4);
  delay_ms(110);

  voice01(e4);
  delay_ms(110);

  voice01(g4);
  delay_ms(110);

  voice01(c4);
  delay_ms(110);

  voice01(e4);
  delay_ms(110);

  voice01(g4);
  delay_ms(110);

  voice01(c4);
  delay_ms(110);

  voice01(d4);
  delay_ms(110);

  voice01(f4);
  delay_ms(110);

  voice01(as3);
  delay_ms(110);

  voice01(d4);
  delay_ms(110);

  voice01(f4);
  delay_ms(110);

  voice01(as3);
  delay_ms(110);

  voice01(c4);
  delay_ms(110);

  voice01(e4);
  delay_ms(110);

  voice01(a3);
  delay_ms(110);

  voice01(c4);
  delay_ms(110);

  voice01(e4);
  delay_ms(110);

  voice01(a3);
  delay_ms(110);

  voice01(as3);
  delay_ms(110);

  voice01(d4);
  delay_ms(110);

  voice01(g3);
  delay_ms(110);

  voice01(as3);
  delay_ms(110);

  voice01(d4);
  delay_ms(110);
  
  voice01(g3);
  delay_ms(110);

  voice01(a3);
  delay_ms(110);

  voice01(c4);
  delay_ms(110);

  voice01(f3);
  delay_ms(110);

  voice01(a3);
  delay_ms(110);

  voice01(c4);
  delay_ms(110);

  voice01(f3);
  delay_ms(110);

  voice01(g3);
  delay_ms(110);

  voice01(as3);
  delay_ms(110);

  voice01(e3);
  delay_ms(110);

  voice01(g3);
  delay_ms(110);

  voice01(as3);
  delay_ms(110);

  voice01(e3);
  delay_ms(110);

  voice01(f3);
  delay_ms(110);

  voice01(a3);
  delay_ms(110);

  voice01(d3);
  delay_ms(110);

  voice01(f3);
  delay_ms(110);

  voice01(a3);
  delay_ms(110);

  voice01(d3);
  delay_ms(115);

  voice01(e3);
  delay_ms(125);

  voice01(g3);
  delay_ms(135);

  voice01(cs3);
  delay_ms(150);

  voice01(e3);
  delay_ms(170);

  voice01(g3);
  delay_ms(200);
  
  voice01(cs3);
  delay_ms(700);

  
  voice01s();
  wave09_frequency(d1);
  wave09_volume(255);
  delay_ms(1500);

  counter=255;
  while(counter>62)
  {
    wave09_volume(counter);
    counter=counter-1;
    delay_ms(1);
  }

  wave01_volume(11);
  wave02_volume(11);
  wave03_volume(11);
  wave04_volume(11);
  wave05_volume(11);
  wave06_volume(11);
  wave07_volume(11);
  wave08_volume(11);
  wave01_frequency(as4);
  wave02_frequency(g4);
  wave03_frequency(e4);
  wave04_frequency(cs4);
  wave05_frequency(as3);
  wave06_frequency(g3);
  wave07_frequency(e3);
  wave08_frequency(cs3);
  delay_ms(3000);

  stop02();
  stop03();
  stop04();
  stop05();
  stop06();
  stop07();
  stop08();
  stop09();

  
  counter=11;
  while(counter<75)
  {
    counter=counter+1;
    wave01_volume(counter);
    delay_ms(1);
  }

  delay_ms(1200);
  
  wave01_frequency(a4);
  delay_ms(400);
  
  wave01_frequency(g4);
  delay_ms(250);
  
  wave01_frequency(f4);
  delay_ms(200);
  
  wave01_frequency(e4);
  delay_ms(200);
  
  wave01_frequency(d4);
  delay_ms(200);
  
  wave01_frequency(cs4);
  delay_ms(200);
  
  wave01_frequency(h3);
  delay_ms(220);
  
  wave01_frequency(cs4);
  delay_ms(250);
  
  wave01_frequency(a3);
  delay_ms(250);
  
  wave01_frequency(cs4);
  delay_ms(220);
  
  wave01_frequency(e4);
  delay_ms(200);
  
  wave01_frequency(g4);
  delay_ms(300);
  
  wave01_frequency(f4);
  delay_ms(200);
  

  counter=0;
  while(counter<9)
  {
    byte a=counter;
    a=a&1;
    if(a==1)
      wave01_frequency(f4);
    else
      wave01_frequency(g4);
    counter=counter+1;
    delay_ms(80);
  }

  wave01_frequency(f4);
  delay_ms(300);

  wave01_frequency(e4);
  delay_ms(600);

   
  counter=75;
  while(counter>23)
  {
    counter=counter-1;
    wave01_volume(counter);
    delay_ms(1);
  }

  
  wave02_volume(13);
  wave03_volume(13);
  wave04_volume(13);
  wave05_volume(13);
  wave09_volume(95);
  wave09_frequency(d1);
  wave01_frequency(f4);
  wave02_frequency(d4);
  wave03_frequency(a3);
  wave04_frequency(f3);
  wave05_frequency(d3);
  delay_ms(3000);

  stop01();
  stop02();
  stop03();
  stop04();
  stop05();
  stop09();
  delay_ms(1000);


  wave01_volume(75);
  wave01_frequency(a4);
  delay_ms(200);
  counter=0;
  while(counter!=2)
  {
    
    wave01_frequency(d5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    wave01_frequency(e5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    wave01_frequency(f5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    counter=counter+1;
  }
  
  wave01_frequency(g5);
  delay_ms(120);

  wave01_frequency(a4);
  delay_ms(120);

  wave01_frequency(e5);
  delay_ms(120);

  counter=0;
  while(counter!=2)
  {
    wave01_frequency(a4);
    delay_ms(120);
    
    wave01_frequency(f5);
    delay_ms(120);

    wave01_frequency(a4);
    delay_ms(120);
    
    wave01_frequency(g5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    wave01_frequency(a5);
    delay_ms(120);
    counter=counter+1;
  }
  
  counter=0;
  goto skip1;
  while(counter!=3)
  {
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(a5);
    delay_ms(120);
    
    skip1:
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(as5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(g5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(a5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(f5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(g5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(e5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(f5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(d5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);

    if(counter!=0)
    {
      voice04(g5);
      delay_ms(120);
      
      wave01_frequency(a4);
      delay_ms(120);
      
      voice04(e5);
      delay_ms(120);
      
      wave01_frequency(a4);
      delay_ms(120);
      
      voice04(f5);
      delay_ms(120);
      
      wave01_frequency(a4);
      delay_ms(120);
      
      voice04(d5);
      delay_ms(120);
      
      wave01_frequency(a4);
      delay_ms(120);
    }
    
    
    voice04(e5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(cs5);
    delay_ms(120);
    
    wave01_frequency(a4);
    delay_ms(120);
    
    voice04(d5);
    delay_ms(120);
    counter=counter+1;
  }
  delay_ms(390);

  stop01();
  delay_ms(390);


  counter=0;
  while(counter!=2)
  {
    wave11_volume(255);
    wave11_frequency(d4);
    delay_ms(120);
    
    wave11_frequency(f4);
    delay_ms(120);
    
    wave11_frequency(as4);
    delay_ms(120);
    
    wave11_frequency(f4);
    delay_ms(120);
    
    wave11_frequency(c4);
    delay_ms(120);
    
    wave11_frequency(e4);
    delay_ms(120);
    
    wave11_frequency(a4);
    delay_ms(120);
    
    wave11_frequency(e4);
    delay_ms(120);
    
    wave11_frequency(as3);
    delay_ms(120);
    
    wave11_frequency(d4);
    delay_ms(120);
    
    wave11_frequency(g4);
    delay_ms(120);
    
    wave11_frequency(d4);
    delay_ms(120);
    
    wave11_frequency(a3);
    delay_ms(120);
    
    wave11_frequency(cs4);
    delay_ms(120);
    
    wave11_frequency(e4);
    delay_ms(120);
    
    wave11_frequency(a4);
    delay_ms(150);
    
    stop11();
    wave09_volume(103);
    wave01_volume(18);
    wave09_frequency(d2);
    wave01_frequency(d4);
    delay_ms(270);
    
    wave02_volume(18);
    wave03_volume(18);
    wave02_frequency(f4);
    wave03_frequency(as4);
    delay_ms(300);
  
    stop02();
    stop03();
    wave09_frequency(c2);
    wave01_frequency(a3);
    delay_ms(315);
    
    wave02_volume(18);
    wave03_volume(18);
    wave02_frequency(e4);
    wave03_frequency(a4);
    delay_ms(340);
    
    stop02();
    stop03();
    wave09_frequency(as1);
    wave01_frequency(as3);
    delay_ms(350);
    
    wave02_volume(18);
    wave03_volume(18);
    wave02_frequency(d4);
    wave03_frequency(g4);
    delay_ms(400);
    
    wave04_volume(18);
    wave09_frequency(a1);
    wave01_frequency(a4);
    wave02_frequency(e4);
    wave03_frequency(cs4);
    wave04_frequency(e3);
    delay_ms(1000);
  
    if (counter!=1) stop01();
    stop02();
    stop03();
    stop04();
    stop09();
    counter=counter+1;
  }
  
  counter=18;
  while(counter<75)
  {
    counter=counter+1;
    wave01_volume(counter);
    delay_ms(1);
  }
  delay_ms(600);
    
  wave01_frequency(g4);
  delay_ms(250);
    
  wave01_frequency(f4);
  delay_ms(200);
    
  wave01_frequency(e4);
  delay_ms(150);
    
  wave01_frequency(d4);
  delay_ms(120);
    
  wave01_frequency(cs4);
  delay_ms(110);
    
  wave01_frequency(h3);
  delay_ms(120);
    
  wave01_frequency(cs4);
  delay_ms(150);
    
  wave01_frequency(a3);
  delay_ms(130);
    
  wave01_frequency(h3);
  delay_ms(120);
    
  wave01_frequency(cs4);
  delay_ms(110);
    
  wave01_frequency(d4);
  delay_ms(110);
    
  wave01_frequency(e4);
  delay_ms(110);
    
  wave01_frequency(f4);
  delay_ms(110);
    
  wave01_frequency(g4);
  delay_ms(110);
    
  wave01_frequency(a4);
  delay_ms(110);
    
  wave01_frequency(g4);
  delay_ms(110);
    
  wave01_frequency(f4);
  delay_ms(110);
    
  wave01_frequency(e4);
  delay_ms(110);
    
  wave01_frequency(f4);
  delay_ms(110);
    
  wave01_frequency(d4);
  delay_ms(110);
    
  wave01_frequency(f4);
  delay_ms(110);
    
  wave01_frequency(a4);
  delay_ms(110);
    
  wave01_frequency(cs5);
  delay_ms(110);
    
  wave01_frequency(d5);
  delay_ms(200);
    
  wave01_frequency(a4);
  delay_ms(150);
    
  wave01_frequency(h4);
  delay_ms(120);
    
  wave01_frequency(cs5);
  delay_ms(110);
    
  wave01_frequency(d5);
  delay_ms(110);
    
  wave01_frequency(e5);
  delay_ms(110);
    
  wave01_frequency(f5);
  delay_ms(110);
    
  wave01_frequency(g5);
  delay_ms(110);
    
  wave01_frequency(a5);
  delay_ms(110);
    
  wave01_frequency(as5);
  delay_ms(500);

  stop01();
  delay_ms(500);






  counter=0;
  goto skip2;

  while(counter!=2)
  {
    stop01();
    stop02();
    stop03();
    stop04();
    stop09();
    
    wave11_volume(255);
    wave11_frequency(d5);
    delay_ms(120);
    
    wave11_frequency(f5);
    delay_ms(120);
    
    wave11_frequency(as5);
    delay_ms(120);
    
    wave11_frequency(f5);
    delay_ms(120);
    
    wave11_frequency(c5);
    delay_ms(120);
    
    wave11_frequency(e5);
    delay_ms(120);
    
    wave11_frequency(a5);
    delay_ms(120);
    
    wave11_frequency(e5);
    delay_ms(120);
    
    wave11_frequency(as4);
    delay_ms(120);
    
    wave11_frequency(d5);
    delay_ms(120);
    
    wave11_frequency(g5);
    delay_ms(120);
    
    wave11_frequency(d5);
    delay_ms(120);
    
    wave11_frequency(a4);
    delay_ms(120);
    
    wave11_frequency(cs5);
    delay_ms(120);
    
    wave11_frequency(e5);
    delay_ms(120);
    
    wave11_frequency(a5);
    delay_ms(150);
    stop11();
    
    skip2:
    wave09_volume(103);
    wave01_volume(18);
    wave09_frequency(d2);
    wave01_frequency(d5);
    delay_ms(270);
    
    wave02_volume(18);
    wave03_volume(18);
    wave02_frequency(f5);
    wave03_frequency(as5);
    delay_ms(300);
  
    stop02();
    stop03();
    wave09_frequency(c2);
    wave01_frequency(a4);
    delay_ms(315);
    
    wave02_volume(18);
    wave03_volume(18);
    wave02_frequency(e5);
    wave03_frequency(a5);
    delay_ms(340);
    
    stop02();
    stop03();
    wave09_frequency(as1);
    wave01_frequency(as4);
    delay_ms(350);
    
    wave02_volume(18);
    wave03_volume(18);
    wave02_frequency(d5);
    wave03_frequency(g5);
    delay_ms(400);
    
    wave04_volume(18);
    wave09_frequency(a1);
    wave01_frequency(e4);
    wave02_frequency(cs5);
    wave03_frequency(e5);
    wave04_frequency(a5);
    delay_ms(1000);
  
    counter=counter+1;
  }
  
  wave09_frequency(gs1);
  wave01_frequency(h4);
  wave02_frequency(f4);
  wave03_frequency(d4);
  wave04_frequency(h3);
  delay_ms(1000);
  
  wave09_frequency(g1);
  wave01_frequency(cs5);
  wave02_frequency(a4);
  wave03_frequency(e4);
  wave04_frequency(a3);
  delay_ms(1500);
  
  stop02();
  stop03();
  stop04();
  stop09();
  wave01_frequency(h4);
  counter=18;
  while(counter<75)
  {
    counter=counter+1;
    wave01_volume(counter);
    delay_ms(1);
  }
  delay_ms(400);

  wave01_frequency(a4);
  delay_ms(300);

  wave01_frequency(cs5);
  delay_ms(200);

  wave01_frequency(e5);
  delay_ms(200);

  wave01_frequency(g5);
  delay_ms(300);

  wave01_frequency(as5);
  delay_ms(1000);

  wave01_frequency(a5);
  delay_ms(300);

  wave01_frequency(g5);
  delay_ms(200);

  wave01_frequency(f5);
  delay_ms(150);

  wave01_frequency(e5);
  delay_ms(130);

  wave01_frequency(f5);
  delay_ms(120);

  wave01_frequency(e5);
  delay_ms(110);

  wave01_frequency(d5);
  delay_ms(110);

  wave01_frequency(cs5);
  delay_ms(110);

  wave01_frequency(d5);
  delay_ms(110);

  wave01_frequency(c5);
  delay_ms(110);

  wave01_frequency(as4);
  delay_ms(110);

  wave01_frequency(a4);
  delay_ms(110);

  wave01_frequency(g4);
  delay_ms(110);

  wave01_frequency(f4);
  delay_ms(120);

  wave01_frequency(e4);
  delay_ms(130);

  wave01_frequency(d4);
  delay_ms(150);


  counter=75;
  while(counter>14)
  {
    counter=counter-1;
    wave01_volume(counter);
    delay_ms(1);
  }
  wave09_volume(75);
  wave02_volume(14);
  wave03_volume(14);
  wave04_volume(14);
  wave05_volume(14);
  wave06_volume(14);
  wave09_frequency(g2);
  wave01_frequency(cs5);
  wave02_frequency(e4);
  wave03_frequency(cs4);
  wave04_frequency(g4);
  wave05_frequency(as4);
  wave06_frequency(e5);
  delay_ms(1500);

  stop09();
  stop03();
  stop04();
  stop05();
  stop06();
  counter=14;
  while(counter<60)
  {
    counter=counter+1;
    wave01_volume(counter);
    wave02_volume(counter);
    delay_ms(1);
  }
  delay_ms(500);

  counter=0;
  while(counter!=4)
  {
    wave01_frequency(cs5);
    wave02_frequency(e4);
    delay_ms(110);
    
    wave01_frequency(e5);
    wave02_frequency(g4);
    delay_ms(110);
    
    wave01_frequency(cs5);
    wave02_frequency(e4);
    delay_ms(110);
    
    wave01_frequency(as4);
    wave02_frequency(cs4);
    delay_ms(110);
    
    wave01_frequency(cs5);
    wave02_frequency(e4);
    delay_ms(110);
    
    wave01_frequency(as4);
    wave02_frequency(cs4);
    delay_ms(110);
    counter=counter+1;
  }
  
  counter=0;
  while(counter!=4)
  {
    wave01_frequency(g4);
    wave02_frequency(as3);
    delay_ms(110);
    
    wave01_frequency(as4);
    wave02_frequency(cs4);
    delay_ms(110);
    
    wave01_frequency(g4);
    wave02_frequency(as3);
    delay_ms(110);
    
    wave01_frequency(e4);
    wave02_frequency(g3);
    delay_ms(110);
    
    wave01_frequency(g4);
    wave02_frequency(as3);
    delay_ms(110);
    
    wave01_frequency(e4);
    wave02_frequency(g3);
    delay_ms(110);
    counter=counter+1;
  }
  
  counter=0;
  while(counter!=4)
  {
    wave01_frequency(cs4);
    wave02_frequency(e3);
    delay_ms(110);
    
    wave01_frequency(e4);
    wave02_frequency(g3);
    delay_ms(110);
    
    wave01_frequency(cs4);
    wave02_frequency(e3);
    delay_ms(110);
    
    wave01_frequency(as3);
    wave02_frequency(cs3);
    delay_ms(110);
    
    wave01_frequency(cs4);
    wave02_frequency(e3);
    delay_ms(110);
    
    wave01_frequency(as3);
    wave02_frequency(cs3);
    delay_ms(110);
    counter=counter+1;
  }
  
  counter=0;
  while(counter!=4)
  {
    wave01_frequency(cs4);
    wave02_frequency(e3);
    delay_ms(110);
    
    wave01_frequency(e4);
    wave02_frequency(g3);
    delay_ms(110);
    
    wave01_frequency(cs4);
    wave02_frequency(e3);
    delay_ms(110);
    
    wave01_frequency(e4);
    wave02_frequency(g3);
    delay_ms(110);
    
    wave01_frequency(g4);
    wave02_frequency(as3);
    delay_ms(110);
    
    wave01_frequency(e4);
    wave02_frequency(g3);
    delay_ms(110);
    counter=counter+1;
  }
  
  counter=0;
  while(counter!=3)
  {
    wave01_frequency(g4);
    wave02_frequency(e3);
    delay_ms(110);
    
    wave01_frequency(as4);
    wave02_frequency(g3);
    delay_ms(110);
    counter=counter+1;
  }
  
  counter=0;
  while(counter!=3)
  {
    wave01_frequency(g4);
    wave02_frequency(as3);
    delay_ms(110);
    
    wave01_frequency(as4);
    wave02_frequency(cs4);
    delay_ms(110);
    counter=counter+1;
  }
  
  wave01_frequency(cs5);
  wave02_frequency(e4);
  delay_ms(110);
  
  wave01_frequency(as4);
  wave02_frequency(cs4);
  delay_ms(110);
    
  counter=0;
  while(counter!=4)
  {
    wave01_frequency(cs5);
    wave02_frequency(e4);
    delay_ms(110);
    
    wave01_frequency(e5);
    wave02_frequency(cs4);
    delay_ms(110);
    counter=counter+1;
  }
  
  delay_ms(200);
  counter=60;
  while(counter>12)
  {
    counter=counter-1;
    wave01_volume(counter);
    wave02_volume(counter);
    delay_ms(1);
  }
  
  wave09_volume(73);
  wave03_volume(12);
  wave04_volume(12);
  wave05_volume(12);
  wave06_volume(12);
  wave07_volume(12);
  wave09_frequency(g2);
  wave01_frequency(a3);
  wave02_frequency(cs4);
  wave03_frequency(e4);
  wave04_frequency(a4);
  wave05_frequency(cs5);
  wave06_frequency(e5);
  wave07_frequency(a5);
  delay_ms(1000);
  
  wave09_frequency(f2);
  wave02_frequency(d4);
  wave03_frequency(f4);
  wave05_frequency(d5);
  wave06_frequency(f5);
  delay_ms(1200);

  stop06();
  stop07();
  wave09_volume(95);
  wave01_volume(15);
  wave02_volume(15);
  wave03_volume(15);
  wave04_volume(15);
  wave05_volume(15);
  wave09_frequency(as2);
  wave01_frequency(g4);
  wave03_frequency(as4);
  wave04_frequency(g5);
  delay_ms(1500);
  
  stop01();
  stop02();
  stop03();
  stop04();
  stop05();
  counter=95;
  while(counter!=255)
  {
    counter=counter+1;
    wave09_volume(counter);
    delay_ms(1);
  }
  delay_ms(1000);

  wave09_frequency(a2);
  delay_ms(600);

  wave09_frequency(g2);
  delay_ms(400);
  
  counter=255;
  while(counter!=75)
  {
    counter=counter-1;
    wave09_volume(counter);
    delay_ms(1);
  }

  wave01_volume(14);
  wave02_volume(14);
  wave03_volume(14);
  wave04_volume(14);
  wave05_volume(14);
  wave06_volume(14);
  wave09_frequency(a2);
  wave01_frequency(cs4);
  wave02_frequency(e4);
  wave03_frequency(a4);
  wave04_frequency(cs5);
  wave05_frequency(e5);
  wave06_frequency(g5);
  delay_ms(1500);
  
  stop01();
  stop02();
  stop03();
  stop04();
  stop05();
  stop06();
  wave09_frequency(e2);
  counter=74;
  while(counter!=255)
  {
    counter=counter+1;
    wave09_volume(counter);
    delay_ms(1);
  }
  delay_ms(400);

  wave09_frequency(f2);
  delay_ms(400);

  wave09_frequency(d2);
  delay_ms(300);

  wave09_frequency(e2);
  delay_ms(250);

  wave09_frequency(cs2);
  delay_ms(200);

  wave09_frequency(d2);
  delay_ms(200);

  wave09_frequency(h1);
  delay_ms(200);

  wave09_frequency(cs2);
  delay_ms(200);

  wave09_frequency(a1);
  delay_ms(250);

  wave09_frequency(as1);
  delay_ms(300);

  wave09_frequency(gs1);
  delay_ms(400);

  wave09_frequency(a1);
  delay_ms(400);
  
  counter=255;
  while(counter!=103)
  {
    counter=counter-1;
    wave09_volume(counter);
    delay_ms(1);
  }
  
  wave01_volume(18);
  wave02_volume(18);
  wave03_volume(18);
  wave04_volume(18);
  wave09_frequency(g2);
  wave01_frequency(a3);
  wave02_frequency(e4);
  wave03_frequency(cs5);
  wave04_frequency(a4);
  delay_ms(500);

  
  wave09_volume(95);
  wave01_volume(15);
  wave02_volume(15);
  wave03_volume(15);
  wave04_volume(15);
  wave05_volume(15);
  wave09_frequency(f2);
  wave02_frequency(d4);
  wave03_frequency(f4);
  wave05_frequency(d5);
  delay_ms(1000);

  stop04();
  stop05();
  wave09_volume(123);
  wave01_volume(21);
  wave02_volume(21);
  wave03_volume(21);
  wave09_frequency(d2);
  delay_ms(1500);
  
  wave09_frequency(a1);
  wave03_frequency(e4);
  delay_ms(1500);
  
  wave02_frequency(cs4);
  delay_ms(1000);
  
  wave01_frequency(g3);
  delay_ms(1000);
  
  wave09_volume(103);
  wave01_volume(27);
  wave02_volume(15);
  wave03_volume(15);
  wave04_volume(15);
  wave09_frequency(d1);
  wave02_frequency(d3);
  wave03_frequency(a3);
  wave04_frequency(d4);
  delay_ms(2000);
  
  wave01_frequency(f3);
  delay_ms(1000);
  
  wave01_frequency(e3);
  delay_ms(1500);
  
  wave01_frequency(f3);
  delay_ms(5000);

  stop01();
  stop02();
  stop03();
  stop04();
  stop09();
  delay_ms(5000);
end_secondProgram