/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:11/06/2019
*/

#include <EEPROM.h>//Include EEPROM library for accessing functions

// start reading from the first byte (address 0) of the EEPROM
int address=0;
byte value;
// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(9,OUTPUT);//Pin A9 is connected to the green LED
  Serial.begin(9600);//Start the serial comm with baud rate 9600
  value = EEPROM.read(address);
  digitalWrite(9,value);
  EEPROM.write(address,value^255);//xor the value to change it from 1 to 0 or 0 to 1 
}
// the loop function runs over and over again forever
void loop() {
}