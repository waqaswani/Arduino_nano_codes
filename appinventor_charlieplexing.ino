/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:29/06/2019
*/

#include<SoftwareSerial.h>

SoftwareSerial bt(12,13);//Bluetooth RX:12,TX:13

void setup()
{
  

  bt.begin(9600);
}

int x;
void loop()
{
  if(bt.available())
  {                   
    x= bt.read();//Storing the data send from the app
   
  }
  pinMode(A4,OUTPUT);	
   pinMode(A5,OUTPUT);	
   pinMode(A3,INPUT);
   pinMode(A2,INPUT);
   digitalWrite(A5,HIGH);
   digitalWrite(A4,LOW);
   delay(x); //Giving delay according to the value sent
	      
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   
   
   

   pinMode(A3,OUTPUT);
   pinMode(A5,OUTPUT);
   pinMode(A4,INPUT);
   pinMode(A2,INPUT);//led 2 turns on and led 1 turns off and so on further
   digitalWrite(A5,HIGH);
   digitalWrite(A3,LOW);
   delay(x);
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   
   pinMode(A2,OUTPUT);
   pinMode(A5,OUTPUT);
   pinMode(A3,INPUT);
   pinMode(A4,INPUT);
   digitalWrite(A5,HIGH);
   digitalWrite(A2,LOW);
   delay(x);
   
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   pinMode(A3,OUTPUT);
   pinMode(A4,OUTPUT);
   pinMode(A5,INPUT);
   pinMode(A2,INPUT);
   digitalWrite(A4,HIGH);
   digitalWrite(A3,LOW);
   delay(x);
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   
   pinMode(A4,OUTPUT);
   pinMode(A2,OUTPUT);
   pinMode(A3,INPUT);
   pinMode(A5,INPUT);
   digitalWrite(A4,HIGH);
   digitalWrite(A2,LOW);
   delay(x);
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
  
   pinMode(A4,OUTPUT);
   pinMode(A5,OUTPUT);
   pinMode(A3,INPUT);
   pinMode(A2,INPUT);
   digitalWrite(A4,HIGH);
   digitalWrite(A5,LOW);
   delay(x);
   
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   
   pinMode(A3,OUTPUT);
   pinMode(A2,OUTPUT);
   pinMode(A4,INPUT);
   pinMode(A5,INPUT);
   digitalWrite(A3,HIGH);
   digitalWrite(A2,LOW);
   delay(x);
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   
   pinMode(A3,OUTPUT);
   pinMode(A5,OUTPUT);
   pinMode(A4,INPUT);
   pinMode(A2,INPUT);
   digitalWrite(A3,HIGH);
   digitalWrite(A5,LOW);
   delay(x);
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   
   pinMode(A3,OUTPUT);
   pinMode(A4,OUTPUT);
   pinMode(A5,INPUT);
   pinMode(A2,INPUT);
   digitalWrite(A3,HIGH);
   digitalWrite(A4,LOW);
   delay(x);
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   
   pinMode(A2,OUTPUT);
   pinMode(A5,OUTPUT);
   pinMode(A4,INPUT);
   pinMode(A3,INPUT);
   digitalWrite(A2,HIGH);
   digitalWrite(A5,LOW);
   delay(x);
   
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   pinMode(A2,OUTPUT);
   pinMode(A4,OUTPUT);
   pinMode(A3,INPUT);
   pinMode(A5,INPUT);
   digitalWrite(A2,HIGH);
   digitalWrite(A4,LOW);
   delay(x);
   
   if(bt.available())
  {                   
    x= bt.read();
   
  }
   
   
   pinMode(A3,OUTPUT);
   pinMode(A2,OUTPUT);
   pinMode(A4,INPUT);
   pinMode(A5,INPUT);
   digitalWrite(A2,HIGH);
   digitalWrite(A3,LOW);
   delay(x);
   
   
   
   
  
}
