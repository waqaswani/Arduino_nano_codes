/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/
int state[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void col_on(int pattern);
int row_read();
int patternk[4] = {0b1000, 0b0100, 0b0010, 0b0001};		//	Patterns for different columns being high at different times
//1000 represents column 1 high and rest low and so on
int key[4][4] = {{1, 2, 3, 10}, {4, 5, 6, 11}, {7, 8, 9, 12}, {14, 0, 15, 13}};		// a 4*4 matrix where every key of the matrix is mentioned
// In Keypad Matrix A=10,B=11,C=12,D=13,*=14,#=15
int column[4] = {6, 7, 8, 9};
int row[4] = {10, 11, 12, 13};

void cpl(int pattern);

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);			//Pins D6,D7,D8 and D9 are columns of the keypad matrix
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);			////Pins D10,D11,D12,D13 are rows of the keypad matrix
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);

}

void loop() {
  int patterns[12] = {2201, 2021, 221, 2012, 212, 2210, 122, 2120, 2102, 1220, 1202, 1022};	//patterns to glow leds 1-12
  for (int i = 0; i < 12; i++)
  { for (int j = 0; j < 4; j++)
    {
      col_on(patternk[j]);
      int k = row_read();
      if (k != 5) {
        state[key[k][j] - 1] = !state[key[k][j] - 1]; //Storing the key presses and toggling the elements of the stat array
      }
    }
    if (state[i])
      cpl(patterns[i]);
  }


}
void cpl(int pattern)
{
  if ((pattern / 1000 == 1) || (pattern / 1000 == 0))
  {
    pinMode(A2, OUTPUT);					//Checking whether the number at a particluar pin is 1 or 0 or z
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






void col_on(int patternk)
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
  return 5;	//if no key has been pressed
}


