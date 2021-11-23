#define sensorPower 7
#define sensorPin  A0
#import <Arduino.h>

int val = 0;

void setupWaterLevelSensors()
{
 

pinMode(sensorPower, OUTPUT);


digitalWrite(sensorPower, LOW);

Serial.begin(9600);  
}

int readSensor()
{

digitalWrite(sensorPower, HIGH); 

delay(10);

analogWrite(sensorPower, LOW);

return 0;
}

void printWaterLevels()
{
 int level = readSensor(); 
 Serial.print("Water level: ");
 Serial.println(level);
 delay(1000);
}


