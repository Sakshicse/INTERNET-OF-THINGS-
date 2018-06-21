int led=9;
int brightness=0;
int fadeamount=5;
void setup() {
pinMode(led,OUTPUT);

}

void loop() {
  analogWrite(led,brightness);
  if(brightness<=255){
    brightness=brightness+fadeamount;
  }
  else if(brightness>=0){
    brightness=brightness-fadeamount;
  }
  delay(30);
}
