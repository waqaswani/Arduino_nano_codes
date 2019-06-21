/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

#include<LiquidCrystal.h>// include the library code
LiquidCrystal lcd(4, 5, 0, 1, 2, 3); // initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to
//pin 4 is rs ,pin 5 is en and 0,1,2,3 are data pins
void col_on(int pattern);
int row_read();
int pattern[4] = {0b1000, 0b0100, 0b0010, 0b0001}; //	Patterns for different columns being high at different times
//1000 represents column 1 high and rest low and so on
char key[4][4] = {{'1', '2', '3', '+'}, {'4', '5', '6', '-'}, {'7', '8', '9', '*'}, {'c', '0', '=', '/'}};
int column[4] = {6, 7, 8, 9};
int row[4] = {10, 11, 12, 13};
long ctoi(char num[7], int num_count);
void disp();
void setup()
{ pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);		//Pins D6,D7,D8 and D9 are columns of the keypad matrix
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);		//Pins D10,D11,D12,D13 	are rows of the keypad matrix
  pinMode(13, INPUT);
  //Serial.begin(9600);
  lcd.begin(16, 2);
}
int a, b, c;
char num1[7] = {0}, op;
char num2[7];
int count = 0;


int vnum = 0;
int num1_count;
void loop()
{
  for (int i = 0; i < 4; i++)
  {
    col_on(pattern[i]);//Calling col_on function and passing patterns
    int j = row_read(); //Storing the values of the rows reading value from the user
    if (j != 5) //Indicating that one of the keys has been pressed
    { if ((key[j][i] == '+') || (key[j][i] == '-') || (key[j][i] == '*') || (key[j][i] == '/')) //Checking for operator press
      {
        if (vnum != 1) { //
          op = key[j][i];
          lcd.print(key[j][i]);
          num1_count = count; //store the count for converting the character into integer
          count = 0;
          vnum = 1;
        } else {
          lcd.print("press equal to!!");
        }
      }
      else if (key[j][i] == 'c')
      {
        if (count > 0)
          count--;
      }
      else if (key[j][i] == '=')
      { lcd.print('=');
        switch (op)
        {
          case '+': lcd.setCursor(0, 1);
            lcd.print(ctoi(num1, num1_count) + ctoi(num2, count));
            disp();


            break;
          case '-': lcd.setCursor(0, 1);
            lcd.print(ctoi(num1, num1_count) - ctoi(num2, count));
            disp();
            break;
          case '*': lcd.setCursor(0, 1);
            lcd.print(ctoi(num1, num1_count)*ctoi(num2, count));
            disp();
            break;
          case '/': lcd.setCursor(0, 1);
            if (ctoi(num2, count) == 0)
            { lcd.print("inf");//division by zero is not defined
              disp();
            }
            else
            { lcd.print(ctoi(num1, num1_count) / ctoi(num2, count));
              disp();
            }
            break;
          default: lcd.setCursor(0, 1);
            lcd.print(ctoi(num1, num1_count));
            disp();

        }
        count = 0;
        vnum = 0;
      }
      else {
        if (vnum == 0)
        {
          num1[count] = key[j][i];
          lcd.print(key[j][i]);
          count++;			//storing the first entered number
          if (count > 7)
          {
            lcd.print("Maxm limit reached");
          }
        }
        else
        { num2[count] = key[j][i];
          lcd.print(key[j][i]);
          count++;				//Storing the second entered number
          if (count > 7)
          {
            lcd.print("Maxm limit reached");
          }
        }
      }
    }
  }

}
void disp()
{
  lcd.setCursor(0, 0);
  delay(3000);
  lcd.print("                ");	//Function to display appropriately on led
  lcd.setCursor(0, 0);

}



long ctoi(char num[7], int num1_count) //Function to convert character to integer
{
  long temp = 1;
  long res = 0;
  for (int i = num1_count - 1; i >= 0; i--)
  {

    res = res + (temp * (num[i] - 48));
    temp = temp * 10;

  }
  return res;
}

void col_on(int pattern)
{


  digitalWrite(column[0], pattern == 8); //set columns to high or low here set column 1 to high and rest low
  digitalWrite(column[1], pattern == 4); //column 2 high and rest low
  digitalWrite(column[2], pattern == 2);
  digitalWrite(column[3], pattern == 1);



}

int row_read()
{

  if (digitalRead(row[0]))
  {
    delay(2);//to remove slight bouncing
    while (digitalRead(row[0])); //Wait until another key is pressed
    return 0;
  }
  if (digitalRead(row[1]))

  { delay(2);
    while (digitalRead(row[1]));

    return 1;
  }
  if (digitalRead(row[2]))
  {
    delay(2); while (digitalRead(row[2]));
    return 2;

  }
  if (digitalRead(row[3]))
  { delay(2);
    while (digitalRead(row[3]));

    return 3;
  }
  return 5;//if no key has been pressed
}