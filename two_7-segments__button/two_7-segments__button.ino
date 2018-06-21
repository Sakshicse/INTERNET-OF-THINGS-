int i,count,digits[][7]={{0,0,0,0,0,0,1},{1,0,0,1,1,1,1},{0,0,1,0,0,1,0},{0,0,0,0,1,1,0},{1,0,0,1,1,0,0},{0,1,0,0,1,0,0},{0,1,0,0,0,0,0},{0,0,0,1,1,1,1},{0,0,0,0,0,0,0},{0,0,0,0,1,1,0}};
void setup() {
  for(i=2;i<9;i++){
    pinMode(11,INPUT);
    pinMode(i,OUTPUT);
    pinMode(12,INPUT);
     }
}
void show(int count)
{
  for(int i=2;i<9;i++){
    digitalWrite(i,digits[count][i-2]);
  }
  }
int but1,but2;
void loop() {
  but1=digitalRead(11);
  if(but1==1)
  {
    if(count<9)
    count++;
    else
    count=0;
    while(digitalRead(11)==1);
  }
  
  show(count);
 
 but2=digitalRead(12);
  if(but2==1)
  {
    if(count>0)
    count--;
    else
    count=0;
    while(digitalRead(12)==1);
  }
show(count);
}

