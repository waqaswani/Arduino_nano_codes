
/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

// the setup function runs once when you press reset or power the board
void setup() {


}
// the loop function runs over and over again forever
void loop() {
  pinMode(A4, OUTPUT);	// A4,A5,A6 and A7 are four pins
  pinMode(A5, OUTPUT);	//where 12 leds are chalieplexed
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A5, HIGH); //using this configuration led 1 turns on
  digitalWrite(A4, LOW);
  delay(1000);	//wait for a second





  pinMode(A3, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A5, HIGH);	//led 2 turns on and led 1 turns off
  digitalWrite(A3, LOW);
  delay(1000);

  pinMode(A2, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  digitalWrite(A5, HIGH);	//led 3 turns on and led 2 turns off
  digitalWrite(A2, LOW);
  delay(1000);

  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(A3, LOW);	//led 4 turns on and led 3 turns off
  delay(1000);

  pinMode(A4, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(A2, LOW);	//led 5 turns on and led 4 turns off
  delay(1000);

  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);	//led 6 turns on and led 5 turns off
  delay(1000);


  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A3, HIGH);
  digitalWrite(A2, LOW);	//led 7 turns on and led 6 turns off
  delay(1000);

  pinMode(A3, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A3, HIGH);
  digitalWrite(A5, LOW);	//led 8 turns on and led 7 turns off
  delay(1000);

  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, LOW);	//led 9 turns on and led 8 turns off
  delay(1000);

  pinMode(A2, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  digitalWrite(A2, HIGH);
  digitalWrite(A5, LOW);	//led 10 turns on and led 9 turns off
  delay(1000);

  pinMode(A2, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A2, HIGH);
  digitalWrite(A4, LOW);	//led 11 turns on and led 10 turns off
  delay(1000);


  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);	//led 12 turns on and led 11 turns off
  delay(1000);

}
