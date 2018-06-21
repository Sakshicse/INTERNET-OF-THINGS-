#include<LiquidCrystal.h>
int rs=A4,e=A5,d4=10,d5=11,d6=12,d7=13;
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);

int A=2,B=3,C=4,D=5;
int C1=6,C2=7,C3=8,C4=9;
int n=0,n1=0,op=0,n2=0,n3=0,n4=0,n5=0;

void setup() {
 lcd.begin(16,2);
 pinMode(A,OUTPUT);pinMode(B,OUTPUT);pinMode(C,OUTPUT);pinMode(D,OUTPUT);
 pinMode(C1,INPUT);pinMode(C2,INPUT);pinMode(C3,INPUT);pinMode(C4,INPUT);
 

}

void loop() {
//  for 1
 digitalWrite(A,LOW); digitalWrite(B,HIGH); digitalWrite(C,HIGH); digitalWrite(D,HIGH);
 digitalWrite(C1,HIGH); digitalWrite(C2,HIGH); digitalWrite(C3,HIGH); digitalWrite(C4,HIGH);

if(digitalRead(C1)==LOW){lcd.print("7");n=n*10+7;delay(250);}
if(digitalRead(C2)==LOW){lcd.print("8");n=n*10+8;delay(250);}
if(digitalRead(C3)==LOW){lcd.print("9");n=n*10+9;delay(250);}
if(digitalRead(C4)==LOW){lcd.print("/");op=1;n1=n;n=0;delay(250);}

// for 2
 digitalWrite(A,HIGH); digitalWrite(B,LOW); digitalWrite(C,HIGH); digitalWrite(D,HIGH);
 digitalWrite(C1,HIGH); digitalWrite(C2,HIGH); digitalWrite(C3,HIGH); digitalWrite(C4,HIGH);

if(digitalRead(C1)==LOW){lcd.print("4");n=n*10+4;delay(250);}
if(digitalRead(C2)==LOW){lcd.print("5");n=n*10+5;delay(250);}
if(digitalRead(C3)==LOW){lcd.print("6");n=n*10+6;delay(250);}
if(digitalRead(C4)==LOW){lcd.print("*");op=2;n2=n;n=0;delay(250);}

// for 3
digitalWrite(A,HIGH); digitalWrite(B,HIGH); digitalWrite(C,LOW); digitalWrite(D,HIGH);
 digitalWrite(C1,HIGH); digitalWrite(C2,HIGH); digitalWrite(C3,HIGH); digitalWrite(C4,HIGH);

if(digitalRead(C1)==LOW){lcd.print("1");n=n*10+1;delay(250);}
if(digitalRead(C2)==LOW){lcd.print("2");n=n*10+2;delay(250);}
if(digitalRead(C3)==LOW){lcd.print("3");n=n*10+3;delay(250);}
if(digitalRead(C4)==LOW){lcd.print("-");op=3;n3=n;n=0;delay(250);}

//for 4
digitalWrite(A,HIGH); digitalWrite(B,HIGH); digitalWrite(C,HIGH); digitalWrite(D,LOW);
 digitalWrite(C1,HIGH); digitalWrite(C2,HIGH); digitalWrite(C3,HIGH); digitalWrite(C4,HIGH);

if(digitalRead(C1)==LOW){lcd.clear();n=0;n1=0;n3=0;n4=0;n5=0;delay(250);}
if(digitalRead(C2)==LOW){lcd.print("0");n=n*10;delay(250);}
if(digitalRead(C4)==LOW){lcd.print("+");op=4;n4=n;n=0;delay(250);}
if(digitalRead(C3)==LOW){lcd.print("=");

if(op==1){n5=n1/n;lcd.print((n5/10));lcd.print((n5%10)); delay(250);}
if(op==2){n5=n2*n;lcd.print((n5/10));lcd.print((n5%10)); delay(250);}
if(op==3){n5=n3-n;lcd.print((n5/10));lcd.print((n5%10)); delay(250);}
if(op==4){n5=n4+n;lcd.print((n5/10));lcd.print((n5%10)); delay(250);}
}}







