/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

#include <SoftwareSerial.h>//including the library for bluetooth communication


SoftwareSerial bt(12, 13); // RX, TX

int chartoint(char val[3]) {
  return 100 * (int(val[0]) - 48) + 10 * (int(val[1]) - 48) + (int(val[2]) - 48); //for converting ascii character to integer
}
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(9, OUTPUT); //Pin D9 is connected to green led
  pinMode(10, OUTPUT); //Pin D10 is connected to blue led
  pinMode(11, OUTPUT); //Pin D11 is connected to red led
  bt.begin(9600); // set the data rate for the SoftwareSerial port
  Serial.begin(9600); // Open serial communications
}

int value;
char temp;
void loop()
{
  if (bt.available())
  { temp = bt.read();
    if (temp == 'G')			//if we type G 120 we get the corresponding intensity
      // on the green led and similarly R 099 B 123(for eg) for other leds

    { char val[3];
      //Serial.println(bt.available());
      delay(1);
      Serial.println(bt.read());
      for (int v = 0; v < 3 ; v++) {
        val[v] = bt.read();
        Serial.println(val[v]);  //Storing the value of intensity
        delay(1);
      }
      int inten = chartoint(val);
      Serial.println(inten);
      //Serial.println(temp);

      value = map(inten, 0, 255, 0, 100);
      analogWrite(9, value);

    }
    if (temp == 'B')
    { char val[3];
      //Serial.println(bt.available());
      delay(1);
      Serial.println(bt.read());
      for (int v = 0; v < 3 ; v++) {
        val[v] = bt.read();	//Storing the value of intensity
        Serial.println(val[v]);
        delay(1);
      }
      int inten = chartoint(val);
      Serial.println(inten);
      //Serial.println(temp);

      value = map(inten, 0, 255, 0, 100);
      analogWrite(10, value);
    }
    else if (temp == 'R')
    { char val[3];
      //Serial.println(bt.available());
      delay(1);
      Serial.println(bt.read());
      for (int v = 0; v < 3 ; v++) {
        val[v] = bt.read();	//Storing the value of intensity
        Serial.println(val[v]);
        delay(1);
      }
      int inten = chartoint(val);
      Serial.println(inten);
      //Serial.println(temp);

      value = map(inten, 0, 255, 0, 100);
      analogWrite(11, value);
    }
  }
}
