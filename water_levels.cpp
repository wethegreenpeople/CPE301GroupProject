
#define sensorPower 7
#define sensorPin  A0


int val = 0;

void setup()
{
 

pinMode(sensorPower, OUTPUT)


digitalWrite(sensorPower, LOW);

Serial.begin(9600);  
}

void loop()
{
    int level = readSensor(); 
 Serial.print("Water level: ");
 Serial.printIn(level);
 delay(1000);
}

int readSensor
{

digitalWrite(sensorPower, HIGH); 

delay(10);   

val = analogWrite(sensorPower, LOW) ;

return val;

}
