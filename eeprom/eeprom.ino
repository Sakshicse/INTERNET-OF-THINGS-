
#include<EEPROM.h>
int address=0;
byte value;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  value=EEPROM.read(0);
  Serial.print("value in EEPROM:");
  Serial.println(value);
 if(value==1)
  digitalWrite(13,HIGH);
  else
  digitalWrite(13,LOW);
 }

void loop() {
  if(digitalRead(12)==HIGH){
    if(value==1)
      value=0;
      else
      value=1;
      while(digitalRead(12)==HIGH);
      EEPROM.write(0,value);
      Serial.print("value:");
      Serial.println(value);
  }
    if(value==1)
  digitalWrite(13,HIGH);
  else
  digitalWrite(13,LOW);
 }
 
    
  


