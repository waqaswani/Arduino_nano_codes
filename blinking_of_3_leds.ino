/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(9, OUTPUT);//Pin D9 is connected to the green lED
  pinMode(10, OUTPUT);//Pin D10 is connected to the blue lED
  pinMode(11, OUTPUT);//Pin D11 is connected to the red lED
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(9, HIGH);   	// turn the LED on (HIGH is the voltage level)
  delay(1000); 			// wait for 1 second
  digitalWrite(9, LOW);		// turn the LED off by making the voltage LOW
  delay(1000);
  // wait for a second
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);

  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  delay(1000);


}