#include <MozziGuts.h>
#import <Adafruit_NeoPixel.h>
#include <Oscil.h>
#include <tables/chum9_int8.h> // recorded audio wavetable
//#include <tables/triangle_valve_2048_int8.h>
#include <tables/SIN4096_int8.h>
#include <tables/whitenoise8192_int8.h> // recorded audio wavetable
//#include <tables/SIN4096_int8.h>
#include <tables/envelop2048_uint8.h>
#include <LowPassFilter.h>
#include <mozzi_rand.h>
//#include <mozzi_midi.h>
#include <RollingAverage.h>
#include <ControlDelay.h>

#define CONTROL_RATE 64 // powers of 2 please

//Initializing the LED ring
Adafruit_NeoPixel ledstrip = Adafruit_NeoPixel(16, 7, NEO_GRB + NEO_KHZ800);

//Oscillators for audio
Oscil<CHUM9_NUM_CELLS, AUDIO_RATE> a1(CHUM9_DATA);
Oscil<SIN4096_NUM_CELLS, AUDIO_RATE> a2(SIN4096_DATA);

// control oscillator for tremelo
Oscil<SIN4096_NUM_CELLS, AUDIO_RATE> kVibrato(SIN4096_DATA);
Oscil <SIN4096_NUM_CELLS, AUDIO_RATE> a3Sin0(SIN4096_DATA);
Oscil <SIN4096_NUM_CELLS, AUDIO_RATE> a3Sin1(SIN4096_DATA);
Oscil <SIN4096_NUM_CELLS, AUDIO_RATE> a3Sin2(SIN4096_DATA);
Oscil <SIN4096_NUM_CELLS, AUDIO_RATE> a3Sin3(SIN4096_DATA);

unsigned int echo_cells_1 = 32;
unsigned int echo_cells_2 = 60;
unsigned int echo_cells_3 = 127;
ControlDelay <128, int> kDelay; // 2seconds

//Sound 5
Oscil<WHITENOISE8192_NUM_CELLS, AUDIO_RATE> a5(WHITENOISE8192_DATA);
Oscil <SIN4096_NUM_CELLS, CONTROL_RATE> a5Mod(SIN4096_DATA);
Oscil<SIN4096_NUM_CELLS, AUDIO_RATE> a5Howl(SIN4096_DATA);
int a5HowlFreq = 440;
int a5HowlDir = 3;

//Averaging for smoothing out input signals
RollingAverage <int,16> input1;
RollingAverage <int,16> input2;
RollingAverage <int,16> input3;
RollingAverage <int,16> input4;
RollingAverage <int,16> input5;

LowPassFilter lpf;

int a1Intensity, a2Intensity,  a4Intensity, a5Intensity = 0;

void setup(){
  startMozzi(CONTROL_RATE);
  a1.setFreq(2.f); //sound 1
  lpf.setResonance(200); //sound 1 filter

  a2.setFreq(440);
  kVibrato.setFreq(.05f);
  kDelay.set(echo_cells_1);


  a5.setFreq(1.f);
  a5Mod.setFreq(.1f);
  a5Howl.setFreq(420);

  ledstrip.begin();
  ledstrip.show();
  
}

void loop(){
  audioHook();
}

uint16_t ledN = 0;

void updateControl(){
  int value1 = input1.next(mozziAnalogRead(0));
  int value2 = input2.next(mozziAnalogRead(1));
  int value3 = input3.next(mozziAnalogRead(2));
  int value4 = input4.next(mozziAnalogRead(3));
  int value5 = input5.next(mozziAnalogRead(4));

  //debug
  value1 = 0;
  
  // map the modulation into the filter range (0-255), not at full
  lpf.setCutoffFreq(map(value1,0,1023,10,180));

  a1Intensity = map(value3,0,1023,0,255);
  a2Intensity = map(value2,0,1023,0,255);
  //kVibrato.setFreq((float) 31+(value3>>4));
  
  a3Sin0.setFreq(value2);
  a3Sin1.setFreq(kDelay.next(value2));
  a3Sin2.setFreq(kDelay.read(echo_cells_2));
  a3Sin3.setFreq(kDelay.read(echo_cells_3));

  a4Intensity = map(value4,0,1023,0,255);
  a5Intensity = map(value2,0,1023,0,255);

  //debug:
  //a1Intensity = a2Intensity =  a4Intensity = 0;

  //a5Intensity = 128;
  //a5Intensity = 128+a5Mod.next();
  a5Howl.setFreq(a5HowlFreq+((int) a5Intensity));

  Serial.println(a5Intensity);
  /* LED ring color mapping:
     R: input1
     Y: input2
     G: input3
     C: input4, 
     B: input5
     
     => R = (i1 + (i2/2)) / 2
     => G = (i3 + (i2/4 + i4/4)) / 2
     => B = (i5 + (i4/2) /2
     */
  uint32_t c = ledstrip.Color(
    a1Intensity, a2Intensity, a4Intensity
    //(value1>>2+(value2>>3)>>1),
    //(value3>>2+(value2>>4+value4>>4) >>1),
    //(value5>>2+(value4 >>3) >>1)
  );
  ledstrip.setPixelColor(ledN++, c);
  ledstrip.show();
  if(ledN>=ledstrip.numPixels()) ledN=0;
}

int updateAudio(){
  //Q15n16 vibrato = (Q15n16) a2Intensity * kVibrato.next();
  //int a4audio = a4Carrier.phMod((int)a4Modulator.next()*(150u+a4ModWidth.next()));
  //a4audio *= (byte)a4Envelop.next()*a4Intensity;
  //a4audio >>= 8;
  return (int) (
    
    (lpf.next(a1.next()) * a1Intensity >>8)+
    //(a2Intensity*a2.phMod(vibrato) >>8)
    (3*((int)a3Sin0.next()+a3Sin1.next()+(a3Sin2.next()>>1)+(a3Sin3.next()>>2) >>3)) +
    //a4audio + 
    (a5.next()*a5Intensity >>8 ) +
    (a5Howl.next()*a5Intensity >>8 )
   // >> 2
    //) ;
   //return a2Intensity*a2.next() >>8;
    //return a2.next();
    );
}




/*
 * Helper functions for LED lights
*/
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<ledstrip.numPixels(); i++) {
    ledstrip.setPixelColor(i, c);
  }
    ledstrip.show();
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<ledstrip.numPixels(); i++) {
      ledstrip.setPixelColor(i, Wheel((i+j) & 255));
    }
    ledstrip.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< ledstrip.numPixels(); i++) {
      ledstrip.setPixelColor(i, Wheel(((i * 256 / ledstrip.numPixels()) + j) & 255));
    }
    ledstrip.show();
    delay(wait);
  }
}
// Slightly different, this makes the rainbow equally distributed throughout

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < ledstrip.numPixels(); i=i+3) {
        ledstrip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      ledstrip.show();

      delay(wait);

      for (int i=0; i < ledstrip.numPixels(); i=i+3) {
        ledstrip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < ledstrip.numPixels(); i=i+3) {
        ledstrip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      ledstrip.show();

      delay(wait);

      for (int i=0; i < ledstrip.numPixels(); i=i+3) {
        ledstrip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return ledstrip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return ledstrip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return ledstrip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}



