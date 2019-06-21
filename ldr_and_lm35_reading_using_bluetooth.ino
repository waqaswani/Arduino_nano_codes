/*
  Arduino IDE version: 1.8.3
  Tested on : ARBD-1
  Microcontroller:ATMEGA 328p
  Written by:Mohammad Waqas
  Date:11/06/2019
*/

#include <SoftwareSerial.h>//including the library for bluetooth communication


SoftwareSerial bt(12, 13); // RX, TX

void setup()
{ pinMode(A0, INPUT); //Pin A0 is connected to the LDR
  pinMode(A7, INPUT); //Pin A7 is connected to the LM35 temperaturre sensor
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  // set the data rate for the SoftwareSerial port
  bt.begin(9600);
  bt.println("Hello, world?");
}
int ldr;
int temp1, temp2;
void loop() // run over and over
{
  ldr = analogRead(A0);
  temp1 = analogRead(A7);
  temp2 = ((temp1 * .488) / 10); //LM 35 gives 10mv per degree celsius
  //in our case 5 volts correspond to 1023 so we convert accordingly


  bt.println(ldr);	//Print the value of the light intensity
  delay(1000);//Wait for 1 sec
  bt.println(temp2);	//Print teh value of the temperature
  delay(1000);

}
