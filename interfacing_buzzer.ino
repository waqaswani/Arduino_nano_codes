/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:11/06/2019
*/

// the setup function runs once when you press reset or power the board
void setup() {
 
pinMode(6,OUTPUT);//Pin D6 is connected to the buzzer
pinMode(A1,INPUT);//Pin A1 is connected to navi switches
}
int val;
// the loop function runs over and over again forever
void loop() {
    val=digitalRead(A1);
    if(val==LOW)
digitalWrite(6,HIGH);//Turn on the buzzer
else
digitalWrite(6,LOW);//Turn off the buzzer

}
