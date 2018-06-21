#include <LiquidCrystal.h>
int rs=A5,e=A4,d4=9,d5=10,d6=11,d7=12;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);

int R1=2,R2=3,R3=4,R4=5;
int C1=6,C2=7,C3=8;
int n=0,attempt=0,paswd=31297;
void setup(){
  lcd.begin(16,2);
  pinMode(R1,OUTPUT);pinMode(R2,OUTPUT);pinMode(R3,OUTPUT);pinMode(R4,OUTPUT);
  pinMode(C1,INPUT);pinMode(C2,INPUT);pinMode(C3,INPUT);
  lcd.print("WELCOME USER");
  delay(1000);
  lcd.clear();
  lcd.print("ENTER PASSWORD");
  lcd.setCursor(0,1);
}

void loop()
{
  digitalWrite(R1,LOW);digitalWrite(R2,HIGH);digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  digitalWrite(C1,HIGH);digitalWrite(C2,HIGH);digitalWrite(C3,HIGH);

   if(digitalRead(C1)==LOW){  lcd.print("*");n=n*10+1;delay(300);}
  if(digitalRead(C2)==LOW){  lcd.print("*");n=n*10+2;delay(300);}
  if(digitalRead(C3)==LOW){  lcd.print("*");n=n*10+3;delay(300);}

  digitalWrite(R1,HIGH);digitalWrite(R2,LOW);digitalWrite(R3,HIGH);digitalWrite(R4,HIGH);
  digitalWrite(C1,HIGH);digitalWrite(C2,HIGH);digitalWrite(C3,HIGH);
  if(digitalRead(C1)==LOW){  lcd.print("*");n=n*10+4;delay(300);}
  if(digitalRead(C2)==LOW){  lcd.print("*");n=n*10+5;delay(300);}
  if(digitalRead(C3)==LOW){ lcd.print("*");n=n*10+6;delay(300);}

  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);digitalWrite(R3,LOW);digitalWrite(R4,HIGH);
  digitalWrite(C1,HIGH);digitalWrite(C2,HIGH);digitalWrite(C3,HIGH);
  if(digitalRead(C1)==LOW) {lcd.print("*");n=n*10+7;delay(300);}
  if(digitalRead(C2)==LOW){ lcd.print("*");n=n*10+8;delay(300);}
  if(digitalRead(C3)==LOW){ lcd.print("*");n=n*10+9;delay(300);}

  digitalWrite(R1,HIGH);digitalWrite(R2,HIGH);digitalWrite(R3,HIGH);digitalWrite(R4,LOW);
  digitalWrite(C1,HIGH);digitalWrite(C2,HIGH);digitalWrite(C3,HIGH);
  if(digitalRead(C1)==LOW){ lcd.clear();lcd.print("try ");lcd.println(attempt-1);
                                    
                                    lcd.setCursor(0,1);
                                    n=0;}
  if(digitalRead(C2)==0){ lcd.print("*");n=n*10;delay(300);}

  if(digitalRead(C3)==0){
    if(n==paswd)
    {
      lcd.clear();
      lcd.print("paswd");
      lcd.setCursor(0,1);
      lcd.print("correct");
      delay(1200);
      lcd.clear();
      lcd.print("here you are");
    }
    else
    {
      lcd.clear();
      if(attempt<3)
      {
        if(n==paswd)
        {
          lcd.clear();
          lcd.print("paswd");
          lcd.setCursor(0,1);
          lcd.print("correct");
          delay(1000);
          lcd.clear();
          lcd.print("here you are");
        }
        if(n!=paswd)
        {
          lcd.print("incorrect");
          lcd.setCursor(0,1);
          lcd.print("paswd");
          delay(1000);
          lcd.clear();
          lcd.print(" try ");
          lcd.println(attempt+1);
          delay(50);
          lcd.setCursor(0,1);attempt++;
          n=0;
        }
      }
      else
      {lcd.clear();
      lcd.print("System is locked");
      }
    }
  }
}
        
      
    
  

  


