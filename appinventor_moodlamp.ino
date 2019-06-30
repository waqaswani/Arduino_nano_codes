/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:28/06/2019
*/

#include<SoftwareSerial.h>

SoftwareSerial bt(12,13);//Bluetooth RX:12,TX:13

void setup()
{
  Serial.begin(9600);//setting up baud rate for serial communication
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  bt.begin(9600);//setting up baud rate for communication through bluetooth
}
char led;
int val;
void loop()
{
  if(bt.available()>1)//available returns 1 byte we want it to assign values only when
  {                   //both bytes are available
    led = bt.read();//for recieving whether R,G or B was sent
    val = bt.read();//for recieving the value of the slider
  }
  
  if(led=='R')
  
  {
    
    analogWrite(11,val);
  }
  if(led=='G')
  
  {
    
    analogWrite(9,val);
  }
  if(led=='B')
  
  {
    
    analogWrite(10,val);
  }
}
