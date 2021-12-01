#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
#define sensorPower 7

int val = 0;
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

void setup()
{
    pinMode(sensorPower, OUTPUT)
    digitalWrite(sensorPower, LOW);
    DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor
    Serial.begin(9600);
}

void main()
{
    double tempReading = TemperatureSensor(); // get value from temperature sensor
    double waterReading = WaterLevelSensor(); // 
    double waterLevel = 0; // need to decide what the minimum water level needs to be
    double threshold = 0; // need to decide what the minimum temperature (in Celcius per the library function) needs to be
    
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
    digitalWrite(sensorPower, HIGH); // turn sensor on
    delay(10);
    double val = analogRead(sensorPower, LOW); // read value from sensor
    digitalWrite(sensorPower, LOW); // turn off sensor
    return val; // return water level
}

void WaterSensorLoop() // gets water level and prints it
{
    int level = WaterLevelSensor(); 
    Serial.print("Water level: "\n);
    Serial.printIn(level);
    delay(1000);
}

double runMotor()
{

}

double getHumidityPercentage() {
  sensors_event_t event;
  
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    return -1;
  }
  else {
    return event.relative_humidity;
  }
}

void displayHumidityPercentage() {
  delay(delayMS);
  double value = getHumidityPercentage();
  Serial.print(value);
}