/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(9, OUTPUT); //Pin A9 is connected to the green LED
  pinMode(10, OUTPUT); //Pin A10 is connected to the blue LED
  pinMode(11, OUTPUT); //Pin A11 is connected to the red LED
  pinMode(A6, INPUT); //Pin A6 is connected to the potentiometer


}
int pot_value;
// the loop function runs over and over again forever
void loop() {

  pot_value = map(analogRead(A6), 0, 1023, 0, 255); //Read the value from the potentiometer and map it to the intensities of the leds(0-255)
  if (pot_value >= 0 && pot_value <= 100)
  {
    analogWrite(9, pot_value); //green is on rest are off
    analogWrite(10, 0);
    analogWrite(11, 0);
  }
  else if (pot_value > 100 && pot_value <= 180)
  {

    analogWrite(9, 0);
    analogWrite(10, pot_value); //blue is on rest are off
    analogWrite(11, 0);

  }
  else if (pot_value > 180 && pot_value <= 255)
  {
    analogWrite(10, 0);
    analogWrite(11, pot_value); //red is on rest are off
    analogWrite(9, 0);

  }
  else
  { digitalWrite(11, LOW);
    digitalWrite(9, LOW); //all are off
    digitalWrite(1, LOW);

  }
}
