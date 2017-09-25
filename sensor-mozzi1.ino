
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator
#include <RollingAverage.h>
#include <ControlDelay.h>


#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_5 = CapacitiveSensor(4,5); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil


unsigned int echo_cells_1 = 32;
unsigned int echo_cells_2 = 60;
unsigned int echo_cells_3 = 127;

#define CONTROL_RATE 64
ControlDelay <128, int> kDelay; // 2seconds

// oscils to compare bumpy to averaged control input
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin0(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin1(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin2(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin3(SIN2048_DATA);

// use: RollingAverage <number_type, how_many_to_average> myThing
RollingAverage <int, 32> kAverage; // how_many_to_average has to be power of 2
int averaged;
RollingAverage <int, 32> kAverage2; // how_many_to_average has to be power of 2
int averaged2;

const int smooth_size =30;
int smooth_a[smooth_size];
int smooth_p = 0;
int value;
int smooth_a2[smooth_size];
int smooth_p2 = 0;
int value2;

void setup(){
  Serial.begin(9600);
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  kDelay.set(echo_cells_1);
  startMozzi();
}

void updateControl(){
  long start = millis();
  
  long total1 = cs_4_2.capacitiveSensor(20)*3;
  
  long total2 = cs_4_5.capacitiveSensor(20)*3;
/*  smooth_a[smooth_p++] = total1;
  if(smooth_p >= smooth_size) smooth_p = 0;

  smooth_a2[smooth_p2++] = total2;
  if(smooth_p2 >= smooth_size) smooth_p2 = 0;

  int average, average2 = 0;

  for(int i=0;i<smooth_size;i++) {
    average += smooth_a[i];  
    average2 += smooth_a2[i];  
  }
  
  value = average/smooth_size;
  if(value < 60) value = 0;
  value2 = average2/smooth_size;
  if(value2 < 60) value2 = 0;
*/

  averaged = kAverage.next(total1);
  averaged2 = kAverage2.next(total2);

  //Serial.print(total1);
  //Serial.print(",");
  //Serial.println(total2); // print sensor output 1
  //Serial.println(total1);
  //delay(10); // arbitrary delay to limit data to serial port
  //int bumpy_input = mozziAnalogRead(0);
  //averaged = kAverage.next(bumpy_input);
  
  aSin0.setFreq(averaged);
  aSin1.setFreq(averaged2);
  //aSin2.setFreq(kDelay2.next(averaged2));
  //aSin3.setFreq(kDelay.read(echo_cells_2));

}


int updateAudio(){
  //return 3*((int)aSin0.next()+aSin1.next()+(aSin2.next()>>1)
  //  +(aSin3.next()>>2)) >>3;
  return (int)aSin0.next()+aSin1.next()>>1;
}

void loop(){
  audioHook();
}
