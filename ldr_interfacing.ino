/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(11, OUTPUT); //Pin D11 is connected to the Red led
  pinMode(A0, INPUT); //Pin A0 is connected to the LDR
  Serial.begin(9600);//To turn on the serial monitor,9600 is the baud rate


}
int val;
void loop() {
  val = analogRead(A0); //Read the value of the light intensity
  analogWrite(11, val); //Write the value on the led
  Serial.print(val);//Print the value on the Serial monitor
}
