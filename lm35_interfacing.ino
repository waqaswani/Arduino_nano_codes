/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:11/06/2019
*/
// the setup function runs once when you press reset or power the board
void setup() {
 
Serial.begin(9600);			//To turn on the serial monitor,9600 is the baud rate
pinMode(A7,INPUT);			//The LM35 temperature sensor is connected at pin A7
}
int temp1;float temp2;

// the loop function runs over and over again forever
void loop() {
    temp1=analogRead(A7);
    temp2=((temp1*4.88)/10);		//LM 35 gives 10mv per degree celsius
   					//in our case 5 volts correspond to 1023 so we convert accordingly
    Serial.print("Temperature =");
    Serial.print(temp2);		//Print the value of temperature on the serial monitor
    Serial.print("\n");
    delay(1000);			// wait for a second

}
