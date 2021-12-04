#define sensorPower 7
#define sensorPin  A0
#import <Arduino.h>

int val = 0;

void setupWaterLevelSensors()
{
Serial.write(sensorPower, OUTPUT); // not sure if this correct //
Serial.write(sensorPower, LOW);// not sure if this correct //
Serial.begin(9600);  // initalize serial communition 
}

void loop()
{
int level = readSensor(); 
 Serial.print("Water level: ");  // print "Water level: "
 level = Serial.Read(A0); // read the input on the analong pin 0
 Serial.printIn(level); // print in the value you need
 delay(1); // pause in between for stability //
 }

int readSensor()
{
Serial.write(sensorPower, HIGH); // send a byte with ...
delay(10);  //wait for a second
val = Serial.Write(sensorPower, LOW) ;//
return val; // returns the value

return 0;
}

void printWaterLevels()
{
 int level = readSensor(); 
 Serial.print("Water level: ");
 Serial.println(level);
 delay(1000);
}


