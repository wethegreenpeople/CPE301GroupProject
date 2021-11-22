#include "DHT.h"
#define DHTPIN 2 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11

void main
{
    DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

    double tempReading = TemperatureSensor(); // get value from temperature sensor
    double waterReading = WaterLevelSensor(); // 
    double waterLevel = ; // need to decide what the minimum water level needs to be
    double threshold = ; // need to decide what the minimum temperature (in Celcius per the library function) needs to be
    
    while ((threshold <= tempReading) && (waterLevel <= waterReading)) // See if it's hot enough to run the fan and that the water level is high enough
    {
        runMotor();
    }
}

double TemperatureSensor()
{
    delay(2000);
    double temperature = dht.readTemperature(); // Read temperature
    return temperature; // Return temperature reading
}

double WaterLevelSensor()
{
    return waterLevel;
}

double runMotor()
{

}