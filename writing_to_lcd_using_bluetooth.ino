/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/
#include<LiquidCrystal.h>// include the library code:
#include <SoftwareSerial.h>//including the library for bluetooth communication

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 4, en = 5, d4 = 0, d5 = 1, d6 = 2, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
SoftwareSerial bt(12, 13); // RX, TX

void setup() {
  lcd.begin(16, 2);
  lcd.print("Goodnight moon!");
  delay(2000);
  lcd.clear();

  // set the data rate for the SoftwareSerial port
  bt.begin(9600);
  bt.println("Hello, world?");

}
int c = 0;
int r = 0;
void loop()
{
  if (bt.available())
  {
    lcd.write(bt.read());
    c++;

    if (( c >= 15) && (r == 0))
    {
      lcd.setCursor(0, 1); //setting cursor if the data exceeds the limit for row 0 and column 15
      r++; c = 0;

    }
  }

}