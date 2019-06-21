/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(6, OUTPUT);	//Pins D6,D7,D8 and D9 are columns of the keypad matrix
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);	//Pins D10,D11,D12,D13 	are rows of the keypad matrix
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);//To turn on the serial monitor,9600 is the baud rate
}
int column[4] = {6, 7, 8, 9};
int row[4] = {10, 11, 12, 13};

// the loop function runs over and over again forever
void loop() {
  digitalWrite(column[0], HIGH); //Here we make the first column high and the others low
  digitalWrite(column[1], LOW);
  digitalWrite(column[2], LOW);
  digitalWrite(column[3], LOW);
  a = digitalRead(10);
  b = digitalRead(11);		//Now we read the value of the rows
  c = digitalRead(12);
  d = digitalRead(13);
  if (digitalRead(10))
  {
    Serial.println("Key 1 has been pressed");//if the first row has read a high value it implies that key 1 has been pressed

    while (digitalRead(10));		    //wait until next key is pressed
  }
  else if (digitalRead(11))
  {
    Serial.println("Key 4 has been pressed");	//if the second row has read a high value it implies that key 4 has been pressed

    while (digitalRead(11));
  }

  else if (digitalRead(12))
  {
    Serial.println("Key 7 has been pressed");	//if the third row has read a high value it implies that key 7 has been pressed
    while (digitalRead(12));
  }

  else if (digitalRead(13))
  {
    Serial.println("Key * has been pressed");	//if the fourth row has read a high value it implies that key * has been pressed
    while (digitalRead(13));
  }
  digitalWrite(column[0], LOW);
  digitalWrite(column[1], HIGH);
  digitalWrite(column[2], LOW);			//Similarly we make the second column high and others low
  digitalWrite(column[3], LOW);
  a = digitalRead(10);
  b = digitalRead(11);
  c = digitalRead(12);				//Now we read values of rows and then continue as when column 1 was high
  d = digitalRead(13);

  if (digitalRead(10))
  {
    Serial.println("Key 2 has been pressed");

    while (digitalRead(10));
  }
  else if (digitalRead(11))
  {
    Serial.println("Key 5 has been pressed");

    while (digitalRead(11));
  }

  else if (digitalRead(12))
  {
    Serial.println("Key 8 has been pressed");
    while (digitalRead(12));
  }

  else if (digitalRead(13))
  {
    Serial.println("Key 0 has been pressed");
    while (digitalRead(13));
  }



  digitalWrite(column[0], LOW);
  digitalWrite(column[1], LOW);
  digitalWrite(column[2], HIGH);
  digitalWrite(column[3], LOW);

  a = digitalRead(10);
  b = digitalRead(11);
  c = digitalRead(12);
  d = digitalRead(13);

  if (digitalRead(10))
  {
    Serial.println("Key 3 has been pressed");

    while (digitalRead(10));
  }
  else if (digitalRead(11))
  {
    Serial.println("Key 6 has been pressed");

    while (digitalRead(11));
  }

  else if (digitalRead(12))
  {
    Serial.println("Key 9 has been pressed");
    while (digitalRead(12));
  }

  else if (digitalRead(13))
  {
    Serial.println("Key # has been pressed");
    while (digitalRead(13));
  }


  digitalWrite(column[0], LOW);
  digitalWrite(column[1], LOW);
  digitalWrite(column[2], LOW);
  digitalWrite(column[3], HIGH);
  a = digitalRead(10);
  b = digitalRead(11);
  c = digitalRead(12);
  d = digitalRead(13);

  if (digitalRead(10))
  {
    Serial.println("Key A has been pressed");

    while (digitalRead(10));
  }
  else if (digitalRead(11))
  {
    Serial.println("Key B has been pressed");

    while (digitalRead(11));
  }

  else if (digitalRead(12))
  {
    Serial.println("Key C has been pressed");
    while (digitalRead(12));
  }

  else if (digitalRead(13))
  {
    Serial.println("Key D has been pressed");
    while (digitalRead(13));
  }

}
