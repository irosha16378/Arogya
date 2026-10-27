#include <Arduino.h>
#include "TDSSensor.h"
#include "MQ3Sensor.h"

// Define GPIO pins for sensors
const int TDS_PIN = 34;
const int MQ3_PIN = 32; // MQ-3 Analog Out pin

// Create objects for each sensor
TDSSensor tdsSensor(TDS_PIN);
MQ3Sensor mq3Sensor(MQ3_PIN);

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  delay(1000);
  
  // Initialize sensors
  tdsSensor.begin();
  mq3Sensor.begin();
  
  Serial.println("Arogya - TDS & MQ-3 Sensors Initialized (OOP Mode)");
}

void loop() {
  // Read values from sensors
  float currentTDS = tdsSensor.readTDS();
  int currentMQ3 = mq3Sensor.readRawValue();

  // Print results to the Serial Monitor
  Serial.print("TDS Value: ");
  Serial.print(currentTDS);
  Serial.print(" ppm | ");
  
  Serial.print("MQ-3 Value: ");
  Serial.println(currentMQ3);

  // Wait for 2 seconds before the next reading
  delay(2000);
}