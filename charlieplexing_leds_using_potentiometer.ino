/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(A6, INPUT); //Pin A6 is connected to the potentiometer

}
int temp;
// the loop function runs over and over again forever
void loop() {

  temp = map(analogRead(A6), 0, 1023, 0, 1000); //Mapping the values of the potentiometer
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A5, HIGH);
  digitalWrite(A4, LOW);
  delay(temp);//delaying the glowing as per the reading of the potentiometer
  temp = map(analogRead(A6), 0, 1023, 0, 1000); //Reading at each stage for timely response of
  //of leds to delay(temp)




  pinMode(A3, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A5, HIGH);
  digitalWrite(A3, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A2, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  digitalWrite(A5, HIGH);
  digitalWrite(A2, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(A3, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A4, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(A2, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A3, HIGH);
  digitalWrite(A2, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A3, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A3, HIGH);
  digitalWrite(A5, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A2, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  digitalWrite(A2, HIGH);
  digitalWrite(A5, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A2, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A2, HIGH);
  digitalWrite(A4, LOW);
  delay(temp);
  temp = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delay(temp);


  temp = map(analogRead(A6), 0, 1023, 0, 1000);

}
