/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/
// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(6, OUTPUT); //Pin D6 is connected to the  buzzer
  pinMode(A0, INPUT); //Pin A0 is connected to the LDR
  Serial.begin(9600);//To turn on the serial monitor,9600 is the baud rate
}
int temp1;
// the loop function runs over and over again forever
void loop() {
  temp1 = analogRead(A0);	//storing the light intensity from ldr
  if (temp1 >= 500)		//Comparing if light intensity is greater than 500
  {
    analogWrite(6, 0); //Turn off the buzzer
  }
  else
    analogWrite(6, temp1);	//Turn on the buzzer
  Serial.println(temp1);	//Print the vaues of light intensity on the Serial Monitor 
  //ln represents printing the subsequent values in the next line
}
