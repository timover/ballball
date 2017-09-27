
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
#include <tables/chum9_int8.h> // recorded audio wavetable
#include <tables/triangle_valve_2048_int8.h>
#include <tables/sin2048_int8.h>
#include <tables/brownnoise8192_int8.h> // recorded audio wavetable
//#include <tables/SIN2048_int8.h>
#include <tables/envelop2048_uint8.h>
#include <LowPassFilter.h>
#include <mozzi_rand.h>
#include <mozzi_midi.h>
#include <RollingAverage.h>
#include <ControlDelay.h>

#define CONTROL_RATE 64 // powers of 2 please

//Initializing the LED ring
Adafruit_NeoPixel ledstrip = Adafruit_NeoPixel(12, 7, NEO_GRB + NEO_KHZ800);

//Oscillators for audio
Oscil<CHUM9_NUM_CELLS, AUDIO_RATE> a1(CHUM9_DATA);
Oscil<TRIANGLE_VALVE_2048_NUM_CELLS, AUDIO_RATE> a2(TRIANGLE_VALVE_2048_DATA);

// control oscillator for tremelo
Oscil<SIN2048_NUM_CELLS, CONTROL_RATE> kVibrato(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> a3Sin0(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> a3Sin1(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> a3Sin2(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> a3Sin3(SIN2048_DATA);

unsigned int echo_cells_1 = 32;
unsigned int echo_cells_2 = 60;
unsigned int echo_cells_3 = 127;
ControlDelay <128, int> kDelay; // 2seconds

// Audio 4 Synth from PhaseMod_Envelope example
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> a4Carrier(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> a4Modulator(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> a4ModWidth(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, CONTROL_RATE> kModFreq1(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, CONTROL_RATE> kModFreq2(SIN2048_DATA);
Oscil <ENVELOP2048_NUM_CELLS, AUDIO_RATE> a4Envelop(ENVELOP2048_DATA);

Oscil<BROWNNOISE8192_NUM_CELLS, AUDIO_RATE> a5(BROWNNOISE8192_DATA);


//Averaging for smoothing out input signals
RollingAverage <int,16> input1;
RollingAverage <int,16> input2;
RollingAverage <int,16> input3;
RollingAverage <int,16> input4;
RollingAverage <int,16> input5;

LowPassFilter lpf;

int a2Intensity,  a4Intensity, a5Intensity = 0;

void setup(){
  startMozzi(CONTROL_RATE);
  a1.setFreq(mtof(65.f)); //sound 1
  lpf.setResonance(200); //sound 1 filter

  a2.setFreq(mtof(130.f));
  kVibrato.setFreq(15.f);
  kDelay.set(echo_cells_1);

  a4Carrier.setFreq(55);
  kModFreq1.setFreq(3.98f);
  kModFreq2.setFreq(3.31757f);
  a4ModWidth.setFreq(2.52434f);
  a4Envelop.setFreq(9.0f);

  //Serial.begin(9600);
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
  
  // map the modulation into the filter range (0-255), not at full
  lpf.setCutoffFreq(map(value1,0,1023,10,180));

  a2Intensity = map(value2,0,1023,0,255);
  kVibrato.setFreq((float) 31+(value3>>4));
  
  a3Sin0.setFreq(value4);
  a3Sin1.setFreq(kDelay.next(value4));
  a3Sin2.setFreq(kDelay.read(echo_cells_2));
  a3Sin3.setFreq(kDelay.read(echo_cells_3));

  a4Intensity = map(value4,0,1023,0,255);

  a4Modulator.setFreq(277.0f + 0.4313f*kModFreq1.next() + kModFreq2.next());

  a5Intensity = map(value5,0,1023,0,255);
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
  uint32_t c = ledstrip.Color((value1>>2+(value2>>3)>>1),(value3>>2+(value2>>4+value4>>4) >>1),(value5>>2+(value4 >>3) >>1));
  ledstrip.setPixelColor(ledN++, c);
  ledstrip.show();
  if(ledN>=ledstrip.numPixels()) ledN=0;
}

int updateAudio(){
  Q15n16 vibrato = (Q15n16) a2Intensity * kVibrato.next();
  int a4audio = a4Carrier.phMod((int)a4Modulator.next()*(150u+a4ModWidth.next()));
  a4audio *= (byte)a4Envelop.next()*a4Intensity;
  a4audio >>= 8;
  return (int) ((long) lpf.next(a1.next()) + (a2Intensity*a2.phMod(vibrato) >>8) +(3*((int)a3Sin0.next()+a3Sin1.next()+(a3Sin2.next()>>1)
    +(a3Sin3.next()>>2)) >>3) + a4audio + (a5.next()*a5Intensity >>8 ) >> 4);
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



