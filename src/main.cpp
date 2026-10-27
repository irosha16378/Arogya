#include <Arduino.h>
#include "TDSSensor.h"

// Define the GPIO pin for the TDS sensor
const int TDS_PIN = 34;

// Create an object of TDSSensor class
TDSSensor tdsSensor(TDS_PIN);

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(115200);
  delay(1000);
  
  // Initialize the TDS sensor pin
  tdsSensor.begin();
  Serial.println("Arogya - TDS Sensor Initialized (OOP Mode)");
}

void loop() {
  // Read current TDS value using the object's method
  float currentTDS = tdsSensor.readTDS();

  // Print the result to the Serial Monitor
  Serial.print("Current TDS Value: ");
  Serial.print(currentTDS);
  Serial.println(" ppm");

  // Wait for 2 seconds before the next reading
  delay(2000);
}