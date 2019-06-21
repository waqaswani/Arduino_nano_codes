/*
Arduino IDE version: 1.8.3
Tested on : ARBD-1
Microcontroller:ATMEGA 328p
Written by:Mohammad Waqas
Date:11/06/2019
*/
// the setup function runs once when you press reset or power the board
void setup() {
 
pinMode(9,OUTPUT);	//Pin A9 is connected to the green LED
pinMode(A1,INPUT);	//Pin A1 is connected to the navi switches
}
int temp1;
// the loop function runs over and over again forever
void loop() {
    temp1=analogRead(A1);
    if(temp1==0)
    {analogWrite(9,255);
    }
    else if(temp1==512)//Predefined values calculated using concept of navi switch
    {analogWrite(9,200);}
    else if(temp1==682)//Predefined values calculated using concept of navi switch
    {analogWrite(9,150);}
    else if(temp1==767)
    {analogWrite(9,100);}
    else if(temp1==818)
    {analogWrite(9,50);} 
}
