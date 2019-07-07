/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:05/07/2019
*/

#include<SoftwareSerial.h>

SoftwareSerial bt(12,13);//Bluetooth RX:12,TX:13

void setup()
{
  Serial.begin(9600);//setting up baud rate for serial communication
  pinMode(9,OUTPUT);//red led
  pinMode(10,OUTPUT);//green led
  pinMode(11,OUTPUT);//blue led
pinMode(2,OUTPUT);//Relay is connected at pin 2
pinMode(3,OUTPUT);//Buzzer is connected at pin 3
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
    
    analogWrite(9,val);
  }
  if(led=='G')
  
  {
    
    analogWrite(10,val);
  }
  if(led=='B')
  
  {
    
    analogWrite(11,val);
  }
  if(led=='A') //for accelerometer sensor
  
  {
    analogWrite(11,val);
    analogWrite(9,val);
    analogWrite(10,val);
  }
 
  if(led=='O')
  
  {
    
    digitalWrite(2,LOW);//Low Triggered Relay(to turn it on)
  }
  if(led=='F')
  
  {
    
    digitalWrite(2,HIGH);
  }
 if(led=='Z')
  
  {
    
    digitalWrite(3,HIGH);//For turning on the buzzer
  }
  if(led=='Y')
  
  {
    
    digitalWrite(3,LOW);
  }
}
