
#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_3 = CapacitiveSensor(4,3); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_5 = CapacitiveSensor(4,5); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_6 = CapacitiveSensor(4,6); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_7 = CapacitiveSensor(4,7); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil

#define AV_LENGTH 16
int av_p = 0;
int average1a[AV_LENGTH];
int average2a[AV_LENGTH];
int average3a[AV_LENGTH];
int average4a[AV_LENGTH];
int average5a[AV_LENGTH];

void setup(){
  Serial.begin(115200);
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_3.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_6.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_7.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
}

void loop(){
  long start = millis();
  long total1 = cs_4_2.capacitiveSensor(60);
  long total2 = cs_4_3.capacitiveSensor(60);
  long total3 = cs_4_5.capacitiveSensor(60);
  long total4 = cs_4_6.capacitiveSensor(60);
  long total5 = cs_4_7.capacitiveSensor(60);

  //Serial.println((millis()-start));
  average1a[av_p] = total1;
  average2a[av_p] = total2;
  average3a[av_p] = total3;
  average4a[av_p] = total4;
  average5a[av_p++] = total5;
  if(av_p >= AV_LENGTH) av_p = 0;

  long average1, average2,average3,average4,average5 = 0;

  for(int i=0;i<AV_LENGTH;i++) {
    average1 += average1a[i];  
    average2 += average2a[i];  
    average3 += average3a[i];  
    average4 += average4a[i];  
    average5 += average5a[i];  
  }
  
  average1 = average1/AV_LENGTH;
  average2 = average2/AV_LENGTH;
  average3 = average3/AV_LENGTH;
  average4 = average4/AV_LENGTH;
  average5 = average5/AV_LENGTH;

  Serial.print(average1);
  Serial.print(",");
  Serial.print(average2);
  Serial.print(",");
  Serial.print(average3);
  Serial.print(",");
  Serial.print(average4);
  Serial.print(",");
  Serial.println(average5);

}

