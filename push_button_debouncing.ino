/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

int val;
// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);	//Pin A1 is connected to navi switches
  pinMode(9, OUTPUT);	//Pin A9 is connected to the green LED

}
// the loop function runs over and over again forever
void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(A1);
  if (val == LOW)
  {
    digitalWrite(9, HIGH);
    delay(1000);//wait for a second
  }
  else
  { delay(1000); //delay to remove bouncing we are waiting for the bouncing to finish
    if (val == HIGH)	//after waiting we are still checking whether the value has changed or not
      digitalWrite(9, LOW);
    else
      digitalWrite(9, HIGH);
  }

}