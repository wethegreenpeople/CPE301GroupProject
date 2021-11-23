#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  initalizeHumiditySensor();
}

void loop() {
  delay(delayMS);
  double value = getHumidityPercentage();
  Serial.print(value);
}

void initalizeHumiditySensor() {
  dht.begin();
  sensor_t sensor;
  dht.humidity().getSensor(&sensor);
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000; 
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
