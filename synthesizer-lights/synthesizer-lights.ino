
/* 
 *  DH2400 Physical Interaction and Design
 *  Fall 2017
 *  Group 11
 *  Synthesizer and LED ring controller
 *  
 *  Inputs: A0 - A4: sensor data from another arduino
 *  
 */
#import <Adafruit_NeoPixel.h>
#include <MozziGuts.h>
#include <Oscil.h>
#include <Sample.h>
#include <tables/chum9_int8.h> // recorded audio wavetable
//#include <tables/triangle_valve_2048_int8.h>
#include <tables/SIN8192_int8.h>
//#include <tables/envelop2048_uint8.h>
#include <LowPassFilter.h>
#include <mozzi_rand.h>
//#include <mozzi_midi.h>
#include <RollingAverage.h>
#include <ControlDelay.h>
#include "Airsynt.h"
#include "bass.h"

#define CONTROL_RATE 64 // powers of 2 please
//#define AUDIO_RATE 16384 // powers of 2 please

#define INPUT_1 1
#define INPUT_2 2
#define INPUT_3 3
#define INPUT_4 4

//Initializing the LED ring
Adafruit_NeoPixel ledstrip = Adafruit_NeoPixel(16, 7, NEO_GRB + NEO_KHZ800);

//Oscillators for audio
//sound 1
Sample<AIRSYNTH_8192_NUM_CELLS, AUDIO_RATE> a1(AIRSYNTH_8192_DATA);

//sound 2
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> a2(SIN8192_DATA);
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> kVibrato(SIN8192_DATA);

// sound 3
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> a3Sin0(SIN8192_DATA);
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> a3Sin1(SIN8192_DATA);
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> a3Sin2(SIN8192_DATA);
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> a3Sin3(SIN8192_DATA);
unsigned int echo_cells_1 = 32;
unsigned int echo_cells_2 = 60;
unsigned int echo_cells_3 = 127;
ControlDelay <128, int> kDelay; // 2seconds

//sound 4
Sample<BASS_8192_NUM_CELLS, AUDIO_RATE> a4(BASS_8192_DATA);

//Averaging for smoothing out input signals
RollingAverage <int,16> input1;
RollingAverage <int,16> input2;
RollingAverage <int,16> input3;
RollingAverage <int,16> input4;

LowPassFilter lpf;

uint16_t ledN = 0; //led number to update. Only 1 led per control cycle

boolean enableOutput = false;

int a1Intensity, a2Intensity,  a3Intensity, a4Intensity = 0;

void setup(){
  pinMode(3,INPUT); //set pin 3 to work as a kill switch for output
  
  startMozzi(CONTROL_RATE);
  a1.setFreq(1.6f); //sound 1
  a1.setLoopingOn();
  lpf.setResonance(200); //sound 1 filter

  a2.setFreq(440);
  kVibrato.setFreq(10);
  kDelay.set(echo_cells_1);

  a4.setFreq(4.f);
  a4.setLoopingOn();

  ledstrip.begin();
  ledstrip.show();
}

void loop(){
  audioHook();
}


void updateControl(){
  enableOutput = (boolean) digitalRead(3);
  
  int value1 = input1.next(mozziAnalogRead(INPUT_1));
  int value2 = input2.next(mozziAnalogRead(INPUT_2));
  int value3 = input3.next(mozziAnalogRead(INPUT_3));
  int value4 = input4.next(mozziAnalogRead(INPUT_4));

  a1Intensity = map(value1,0,1023,0,255);
  //a1Intensity = 200;
  
  a2Intensity = map(value2,0,1023,0,255);
  kVibrato.setFreq(a2Intensity >> 4);
  
  a3Sin0.setFreq(value3);
  a3Sin1.setFreq(kDelay.next(value3));
  a3Sin2.setFreq(kDelay.read(echo_cells_2));
  a3Sin3.setFreq(kDelay.read(echo_cells_3));

  a4Intensity = map(value4,0,1023,0,255);
  // map the modulation into the filter range (0-255), not at full
  lpf.setCutoffFreq(map(value4,0,1023,10,230));


  
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
  if(enableOutput) {
    //idle mode
    if(value1 < 40 && value2 < 40 &&  value3 < 40 && value4 < 40) {
      uint32_t c = ledstrip.Color(64,64,64);
      ledstrip.setPixelColor(ledN++, c);
      ledstrip.show();
      if(ledN>=ledstrip.numPixels()) ledN=0;
    }
    //normal mode
    else {
      uint32_t c = ledstrip.Color(
        a1Intensity, a2Intensity, a4Intensity
      );
      ledstrip.setPixelColor(ledN++, c);
      ledstrip.show();
      if(ledN>=ledstrip.numPixels()) ledN=0;
    }
  }
  else {
      ledstrip.setPixelColor(ledN++, ledstrip.Color(0,0,0));
      ledstrip.show();
  }
}



int updateAudio(){
  Q15n16 vibrato = (Q15n16) kVibrato.next() * a2Intensity;
 
  if(enableOutput) return (int) (
    (long)
    (a1.next() * a1Intensity >>8)
    +
    (a2.phMod(vibrato)*a2Intensity >>8 )
    +
    (3*((int)a3Sin0.next()+a3Sin1.next()+(a3Sin2.next()>>1)+(a3Sin3.next()>>2) >>3))
    +
    (lpf.next(a4.next())*a4Intensity >>8 )

    >> 2
    );
  else return 0;
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



