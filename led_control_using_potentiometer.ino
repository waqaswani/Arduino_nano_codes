/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:11/06/2019
*/
// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);	//Pin A9 is connected to the green LED
pinMode(A6,INPUT);	//Pin A6 is connected to the potentiometer
Serial.begin(9600);	//Start the serial comm with baud rate 9600
}
int pot_value;
// the loop function runs over and over again forever
void loop() {
  
pot_value=map(analogRead(A6),0,1023,0,255);//mapping the value of the potentiometer to match the intensity of the leds
analogWrite(9,pot_value);//glow the led with intensity equal to the 
			 //value of the potentiometer
Serial.print(pot_value);  // print the value on the Serial monitor
}