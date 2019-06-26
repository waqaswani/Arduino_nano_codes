/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:18/06/2019
*/

// include the EduIntro library
#include <EduIntro.h>

DHT11 dht11(D2);  // creating the object sensor on pin 'D7'

int C;   // temperature C readings are integers
float F; // temperature F readings are returned in float format
int H;   // humidity readings are integers

void setup()
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  dht11.update();

  C = dht11.readCelsius();     	// Reading the temperature in Celsius degrees and store in the C variable
  F = dht11.readFahrenheit();  	// Reading the temperature in Fahrenheit degrees and store in the F variable
  H = dht11.readHumidity();     // Reading the humidity index

  // Print the collected data in a row on the Serial Monitor
  Serial.print("Humidity: ");
  Serial.println(H);
  Serial.print("Temperaturevin celsius: ");
  Serial.println(C);
  Serial.print("Temperature in Fahrenheit: ");
  Serial.println(F);

  delay(1000);                // Wait one second before get another temperature reading
}
