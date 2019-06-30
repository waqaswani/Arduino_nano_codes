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
   pinMode(5,OUTPUT);
}

void loop() {
   long duration, feet, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   feet = microsecondsTofeet(duration);
   cm = microsecondsToCentimeters(duration);
   
   /*Serial.print(feet);
   Serial.print("feet, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();*/
   delay(100);
   if(feet>=4)
   {
     digitalWrite(5,HIGH);
     delay(1000);
   }
   else
   {digitalWrite(5,LOW);
     delay(1000);
   }
}

long microsecondsTofeet(long duration) {
   return duration / 888 / 2;//converting 343m/s into foot/us 
				//divide by 2 is for the wave going and returning 
}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;//converting 343m/s into cm/us 
}				//divide by 2 is for the wave going and returning