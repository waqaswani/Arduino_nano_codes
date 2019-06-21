/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/
#include <LiquidCrystal.h>		//Including the library for LCD

//we are using the lcd in 4 bit mode therefore only four data pins are connected(d4,d5,d6 and d7)
//rs and en are register selesct and enable respectively
const int rs = 4, en = 5, d4 = 0, d5 = 1, d6 = 2, d7 = 3;//initialize the library by associating any needed LCD interface pin


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);//with the arduino pin number it is connected to
// the setup function runs once when you press reset or power the board
void setup() {

  lcd.begin(16, 2);// Setting up the rows and columns of the LCD(2 rows and 16 columns)

  pinMode(A7, INPUT); //Taking input from LM35 a temperature sensor connected at pin A7
  pinMode(A0, INPUT); //Taking input from LDR connected at pin A0
  pinMode(A1, INPUT); //Using the switches as input connected at pin A1
}
int temp1; float temp2; int val; int navi; int state = 0;
// the loop function runs over and over again forever
void loop() {
  navi = analogRead(A1);
  lcd.setCursor(0, 0);
  temp1 = analogRead(A7);
  temp2 = ((temp1 * 4.88) / 10); //LM 35 gives 10mv per degree celsius
  //in our case 5 volts correspond to 1023 so we convert accordingly
  val = analogRead(A0);


  if (navi == 0)
  { state = !state; //toggle the state variable so that we use it to toggle between temperature and light reading
    if (state == 1)
    {
      lcd.clear();//clear the lcd
      lcd.print("Temperature =");
      lcd.print(temp2);
    }//print the reading of temperature on the lcd
    else
    { lcd.clear();
      lcd.setCursor(0, 1); //set the cursor on the second row first column


      lcd.print("Light=");
      lcd.print(val);//print the reading of light intensity on the lcd
    }
  }
  delay(1000);// wait for a second
}

