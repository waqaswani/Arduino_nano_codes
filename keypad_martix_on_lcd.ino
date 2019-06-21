/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:11/06/2019
*/

// include the library code:
#include <LiquidCrystal.h>
void col_on(int pattern);
int row_read();
int pattern[4]={0b1000,0b0100,0b0010,0b0001};//	Patterns for different columns being high at different times
 //1000 represents column 1 high and rest low and so on
int key[4][4]={{1,2,3,10},{4,5,6,11},{7,8,9,12},{14,0,15,13}};// a 4*4 matrix where every key of the matrix is mentioned
								// In Keypad Matrix A=10,B=11,C=12,D=13,*=14,#=15 
int column[4]={6,7,8,9};
int row[4]={10,11,12,13};
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 4, en = 5, d4 = 0, d5 = 1, d6 = 2, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  
  pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);		//Pins D6,D7,D8 and D9 are columns of the keypad matrix
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,INPUT);
 pinMode(11,INPUT);		//Pins D10,D11,D12,D13 	are rows of the keypad matrix
 pinMode(12,INPUT);
 pinMode(13,INPUT);
 
}

void loop() {
  // set the cursor to column 0, row 1
  
  lcd.setCursor(0, 1);
 
  for(int i=0;i<4;i++)
  {
    col_on(pattern[i]);//Calling col_on function and passing patterns
    int j=row_read();//Storing the values of the rows reading value from the user
    if(j!=5)		//Indicating that one of the keys has been pressed
   lcd.print(key[j][i]);//print the value of the key on the lcd pressed by the user by accesing the row and column of the 4*4 matrix
  }
  
}

void col_on(int pattern)
{
  digitalWrite(column[0],pattern==8);//set columns to high or low here set column 1 to high and rest low
  digitalWrite(column[1],pattern==4);//column 2 high and rest low
  digitalWrite(column[2],pattern==2);
  digitalWrite(column[3],pattern==1);
  
  
  
}
  
int row_read()
{
  
  if(digitalRead(row[0]))
  {
    delay(2);//to remove slight bouncing
while(digitalRead(row[0]));//Wait until another key is pressed
  return 0;}
  if(digitalRead(row[1]))
  
  {delay(2);
    while(digitalRead(row[1]));
    
    return 1;}
  if(digitalRead(row[2]))
  {
    delay(2);while(digitalRead(row[2]));
    return 2;
    
  }
  if(digitalRead(row[3]))
  {delay(2);
    while(digitalRead(row[3]));
  
  return 3;
  }
  return 5; //if no key has been pressed
}


