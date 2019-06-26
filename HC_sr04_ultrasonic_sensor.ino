/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:26/06/2019
*/


const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);		//Writing high for 10us to start the UV sensor
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   
   Serial.println(duration);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}


long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;//343m/s is the speed of sound so from this we calculated that it needs 74 usec per inch
}//divide by 2 is for the distance travelled twice
long microsecondsToCentimeters(long microseconds) {//343m/s is the speed of sound so from this we calculated that it needs 29 usec per cm
   return microseconds / 29 / 2;
}