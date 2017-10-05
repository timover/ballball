
#include <CapacitiveSensor.h>

#define WIFI_COMM A0

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_3 = CapacitiveSensor(4,7); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_5 = CapacitiveSensor(4,8); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_6 = CapacitiveSensor(4,12); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor cs_4_7 = CapacitiveSensor(4,13); // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil

#define AV_LENGTH 16
int av_p = 0;
int average1a[AV_LENGTH];
int average2a[AV_LENGTH];
int average3a[AV_LENGTH];
int average4a[AV_LENGTH];
int average5a[AV_LENGTH];
bool isOn = true; 

void setup(){
  Serial.begin(115200);
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_3.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_6.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  cs_4_7.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 
}

void loop(){
  int val = digitalRead(5);
  int potentio = analogRead(1);
  int minOutput = map( potentio, 0, 1023, 10, 700) ; 
  int maxOutput = map( potentio, 0, 1023, 500, 1300) ;
  Serial.println(val);
  if(val > 0)
    {
      isOn = false; 
    }
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

  average1 = max(average1, minOutput);
  average2 = max(average2, minOutput);
  average3 = max(average3, minOutput);
  average4 = max(average4, minOutput);
  average5 = max(average5, minOutput);

  average1 = min(average1, maxOutput);
  average2 = min(average2, maxOutput);
  average3 = min(average3, maxOutput);
  average4 = min(average4, maxOutput);
  average5 = min(average5, maxOutput);

  int averageMapped1 = map(average1, minOutput, maxOutput, 0, 255);
  int averageMapped2 = map(average2, minOutput, maxOutput, 0, 255);
  int averageMapped3 = map(average3, minOutput, maxOutput, 0, 255);
  int averageMapped4 = map(average4, minOutput, maxOutput, 0, 255);
  int averageMapped5 = map(average5, minOutput, maxOutput, 0, 255); 
  Serial.print(averageMapped1);
  Serial.print(",");
  Serial.print(averageMapped2);
  Serial.print(",");
  Serial.print(averageMapped3);
  Serial.print(",");
  Serial.print(averageMapped4);
  Serial.print(",");
  
  Serial.println(averageMapped5);
  
 // if(isOn){
  analogWrite(3, averageMapped1);
  analogWrite(6, averageMapped2);
  analogWrite(9, averageMapped3);
  analogWrite(10, averageMapped4); 
  analogWrite(11, averageMapped5);
  digitalWrite(5, HIGH);
 // }

 /* else{
    analogWrite(3, 0);
    analogWrite(6, 0);
    analogWrite(9, 0);
    analogWrite(10, 0); 
    analogWrite(11, 0);
    digitalWrite(5, LOW);
  }
/*
   analogWrite(3, 500);
    
  analogWrite(6, 600);
  analogWrite(9, 700);
  analogWrite(10, 800);
 analogWrite(11, 900);
   //delay(2000);
 
 /*  analogWrite(3, 200);
 analogWrite(5, 400);
  analogWrite(6, 400);
  analogWrite(9, 600);
  analogWrite(10, 600);
 */
}

