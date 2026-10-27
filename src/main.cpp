#include <Arduino.h>
#include "TDSSensor.h"
#include "MQ3Sensor.h"
#include "MQ135Sensor.h"

// Define GPIO pins for sensors
const int TDS_PIN = 34;
const int MQ3_PIN = 32;
const int MQ135_PIN = 35; // MQ-135 Analog Out pin

// Create objects for each sensor
TDSSensor tdsSensor(TDS_PIN);
MQ3Sensor mq3Sensor(MQ3_PIN);
MQ135Sensor mq135Sensor(MQ135_PIN);

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  delay(1000);
  
  // Initialize all sensors
  tdsSensor.begin();
  mq3Sensor.begin();
  mq135Sensor.begin();
  
  Serial.println("Arogya - TDS, MQ-3 & MQ-135 Sensors Initialized (OOP Mode)");
}

void loop() {
  // Read values from sensors
  float currentTDS = tdsSensor.readTDS();
  int currentMQ3 = mq3Sensor.readRawValue();
  int currentMQ135 = mq135Sensor.readRawValue();

  // Print results to the Serial Monitor
  Serial.print("TDS: ");
  Serial.print(currentTDS);
  Serial.print(" ppm | ");
  
  Serial.print("MQ-3: ");
  Serial.print(currentMQ3);
  Serial.print(" | ");

  Serial.print("MQ-135: ");
  Serial.println(currentMQ135);

  // Wait for 2 seconds before the next reading
  delay(2000);
}