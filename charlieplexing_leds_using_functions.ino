/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/


void cpl(int pattern);
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);//To turn on the serial monitor,9600 is the baud rate
}

}
// the loop function runs over and over again forever
void loop() {
  int patterns[12] = {2201, 2021, 221, 2012, 212, 2210, 122, 2120, 2102, 1220, 1202, 1022}; //These are the patterns to turn on the leds 1,2,3 upto 12
  //here 2 represents z or high impedance
  for (int i = 0; i < 12; i++)								// These are of the form A2 A3 A4 A5  where A5 is the pin where the number at ones palce
    //is present
  {
    cpl(patterns[i]);	//we call the cpl function passing the patterns one by one
    delay(1000);
  }


}
void cpl(int pattern)
{

  Serial.println(pattern / 1000); //for printing the number at ten thousandth place
  Serial.println((pattern / 100) % 10); //for printing the number at thousandth place
  Serial.println((pattern / 10) % 10); //for printing the number at tens place
  Serial.println(pattern % 10);	//for printing the number at ones place
  if ((pattern / 1000 == 1) || (pattern / 1000 == 0))
  {
    pinMode(A2, OUTPUT);//Checking whether the number at a particluar pin is 1 or 0 or z
    			// if 1 or 0 then assign it as output otherwise assign it as an input
    digitalWrite(A2, pattern / 1000);
  }
  else
    pinMode(A2, INPUT);
  if (((pattern / 100) % 10 == 1) || ((pattern / 100) % 10 == 0))
  {
    pinMode(A3, OUTPUT);
    digitalWrite(A3, (pattern / 100) % 10);
  }
  else
    pinMode(A3, INPUT);
  if (((pattern / 10) % 10 == 1) || ((pattern / 10) % 10 == 0))
  {
    pinMode(A4, OUTPUT);
    digitalWrite(A4, (pattern / 10) % 10);
  }
  else
    pinMode(A4, INPUT);
  if (((pattern) % 10 == 1) || ((pattern) % 10 == 0))
  {
    pinMode(A5, OUTPUT);
    digitalWrite(A5, (pattern) % 10);
  }
  else
    pinMode(A5, INPUT);

}