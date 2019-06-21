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
int i;
// the loop function runs over and over again forever
void loop() {

  for (i = 0; i <= 250; i++)
  {
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(A3, INPUT);		//here we are turning 4 led on simultaneouly
    pinMode(A2, INPUT);		//we are using the loop so that the 4ms delay gets
    digitalWrite(A5, HIGH);	//multiplied by 250 to give a 1000ms delay
    digitalWrite(A4, LOW);	// so for 1 sec led 1,2,3 and 4 are on
    // and another seconf led 5,6,7 and 8 are on and so on

    delay(1);// wait for 1 milli second




    pinMode(A3, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A2, INPUT);
    digitalWrite(A5, HIGH);
    digitalWrite(A3, LOW);
    delay(1);

    pinMode(A2, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    digitalWrite(A5, HIGH);
    digitalWrite(A2, LOW);

    delay(1);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, INPUT);
    pinMode(A2, INPUT);
    digitalWrite(A4, HIGH);
    digitalWrite(A3, LOW);
    delay(1);
  }


  for (i = 0; i <= 250; i++)
  {

    pinMode(A4, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, INPUT);
    pinMode(A5, INPUT);
    digitalWrite(A4, HIGH);
    digitalWrite(A2, LOW);
    delay(1);

    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(A3, INPUT);
    pinMode(A2, INPUT);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);

    delay(1);

    pinMode(A3, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
    digitalWrite(A3, HIGH);
    digitalWrite(A2, LOW);
    delay(1);

    pinMode(A3, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A2, INPUT);
    digitalWrite(A3, HIGH);
    digitalWrite(A5, LOW);

    delay(1);
  }

  for (i = 0; i <= 250; i++)
  {
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, INPUT);
    pinMode(A2, INPUT);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);

    delay(1);
    pinMode(A2, OUTPUT);
    pinMode(A5, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A3, INPUT);
    digitalWrite(A2, HIGH);
    digitalWrite(A5, LOW);

    delay(1);
    pinMode(A2, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A3, INPUT);
    pinMode(A5, INPUT);
    digitalWrite(A2, HIGH);
    digitalWrite(A4, LOW);
    delay(1);


    pinMode(A3, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);

    delay(1);
  }

}
