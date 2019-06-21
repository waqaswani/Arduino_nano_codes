/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/
#include <SoftwareSerial.h>//including the library for bluetooth communication

SoftwareSerial bt(12, 13); // RX, TX

// the setup function runs once when you press reset or power the board
void setup()
{ pinMode(D6, OUTPUT); //Pin D6 is connected to Buzzer
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  // set the data rate for the SoftwareSerial port
  bt.begin(9600);
  bt.println("Hello, world?");
}
int count = 0, a = 0;
char str[9] = "Buzzer on"; //Text to turn on the buzzer
char str1[10] = "Buzzer off"; //Text to turn off the buzzer
void loop() // run over and over
{ char test;
  if (bt.available())
  { test = bt.read();
    if (test == str[count]) //Checking if data sent from bluetooth matches the predefined string
    {
      count++;
    }
    else
    {
      count = 0;
    }
    if (test == str1[a])
    {
      a++;
    }
    else
    {
      a = 0;
    }

  }
  if (count == 9)
  { digitalWrite(9, HIGH);
    count = 0;
  }
  if (a == 10)
  { digitalWrite(9, LOW);
    a = 0;
  }
}