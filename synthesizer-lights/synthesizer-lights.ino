
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
//#include <tables/chum9_int8.h> // recorded audio wavetable
//#include <tables/triangle_valve_2048_int8.h>
#include <tables/SIN8192_int8.h>
#include <tables/SAW4096_int8.h>
//#include <tables/envelop2048_uint8.h>
#include <LowPassFilter.h>
//#include <mozzi_rand.h>
//#include <mozzi_midi.h>
#include <RollingAverage.h>
#include <ControlDelay.h>
#include <EventDelay.h>
#include "Airsynt.h"
#include "bass.h"
//#include "bassdrum.h"
//#include "snare.h"
//#include "hihat.h"

#define CONTROL_RATE 64 // powers of 2 please
#define AUDIO_RATE 8192 // powers of 2 please

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
Oscil<SAW4096_NUM_CELLS, AUDIO_RATE> a2(SAW4096_DATA);
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> kVibrato(SIN8192_DATA);

// sound 3
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> a3Sin0(SIN8192_DATA);
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> a3Sin1(SIN8192_DATA);
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> a3Sin2(SIN8192_DATA);
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> a3Sin3(SIN8192_DATA);
unsigned int echo_cells_1 = 32;
unsigned int echo_cells_2 = 64;
unsigned int echo_cells_3 = 128;
ControlDelay <128, int> kDelay; // 2seconds

//sound 4
Sample<BASS_8192_NUM_CELLS, AUDIO_RATE> a4(BASS_8192_DATA);

//Drums
//Sample<SNARE_8192_NUM_CELLS, AUDIO_RATE> snare(SNARE_8192_DATA);
//Sample<BD_8192_NUM_CELLS, AUDIO_RATE> bd(BD_8192_DATA);
//Sample<HH_8192_NUM_CELLS, AUDIO_RATE> hh(HH_8192_DATA);
EventDelay drumDelay;
boolean playSnare = false;
boolean playHihat = false;

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
  //a1.setFreq(3.19f); //sound 1
  a1.setFreq(4.f);
  a1.setLoopingOn();
  lpf.setResonance(200); //sound 1 filter

  a2.setFreq(152);
  kVibrato.setFreq(10);
  kDelay.set(echo_cells_1);

  a4.setFreq(3.f);
  a4.setLoopingOn();

  ledstrip.begin();
  ledstrip.show();

  //snare.setFreq((float) SNARE_8192_SAMPLERATE / (float) SNARE_8192_NUM_CELLS);
  //bd.setFreq((float) BD_8192_SAMPLERATE / (float) BD_8192_NUM_CELLS);
  //hh.setFreq((float) HH_8192_SAMPLERATE / (float) HH_8192_NUM_CELLS);
  //drumDelay.set(300);
  //drumDelay.start();
}

void loop(){
  audioHook();
}


void updateControl(){
  enableOutput = true; //(boolean) digitalRead(3);
  
  int value1 = input1.next(mozziAnalogRead(INPUT_1));
  int value2 = input2.next(mozziAnalogRead(INPUT_2));
  int value3 = input3.next(mozziAnalogRead(INPUT_3));
  int value4 = input4.next(mozziAnalogRead(INPUT_4));

  a1Intensity = map(value1,0,1023,0,255);
  //a1Intensity = 200;
  
  a2Intensity = map(value2,0,1023,0,180);
  kVibrato.setFreq(a2Intensity >> 5);
  
  a3Sin0.setFreq(value3);
  a3Sin1.setFreq(kDelay.next(value3));
  a3Sin2.setFreq(kDelay.read(echo_cells_2));
  a3Sin3.setFreq(kDelay.read(echo_cells_3));

  a4Intensity = map(value4,0,1023,0,255);
  // map the modulation into the filter range (0-255), not at full
  lpf.setCutoffFreq(map(value4,0,1023,10,230));

  /*if(drumDelay.ready()){
    if(playHihat) {
      //hh.start();
    }
    else {
      if(playSnare) snare.start();
      else bd.start();
      playSnare = !playSnare;
    }
    playHihat = !playHihat;
    drumDelay.start();
  }*/
  
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
  
  long out = (
    (a1.next() * a1Intensity >>8) +
    (a2.phMod(vibrato)*a2Intensity >>8 ) +
    (3*((int)a3Sin0.next()+a3Sin1.next()+(a3Sin2.next()>>1)+(a3Sin3.next()>>2) >>3)) +
    (lpf.next(a4.next())*a4Intensity >>8 )

    /*+ bd.next()
    + snare.next()
    + hh.next()*/
    >> 2
    );
  if(enableOutput) return (int) constrain( out,-254,255);
  else return 0;
}





