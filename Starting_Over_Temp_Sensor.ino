#include <DHT.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;
int dt=150;
int ledPin=3;
int whileDelay=10;
float upperTempLimit=27.5;
float goodTemp=27.2;
int pushDelay=1000;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
HT.begin();
delay(setTime);
pinMode (ledPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

humidity=HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true);

if (tempC>upperTempLimit)
    {
    Serial.println("I'm in the if statement ");
    Serial.println("Temperature in C ");
    Serial.print(tempC);
    digitalWrite(ledPin, HIGH);
    delay(pushDelay);
    digitalWrite(ledPin, LOW);
    while (tempC>goodTemp){
     //radio.read(&message, sizeof(message));
     //message = temp;
     Serial.println("I'm in the while loop ");
     tempC=HT.readTemperature();
     Serial.println("Temperature in C ");
     Serial.print(tempC);
     delay(whileDelay);
     }
    digitalWrite(ledPin, HIGH);
    delay(pushDelay);
    digitalWrite(ledPin, LOW);
    }
  else{    
    Serial.println("Temperature in C ");
    Serial.print(tempC);
    Serial.println(); 
    Serial.println();
    Serial.println();
    delay(dt);
}
}
