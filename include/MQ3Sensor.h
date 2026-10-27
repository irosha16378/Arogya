#ifndef MQ3_SENSOR_H
#define MQ3_SENSOR_H

#include <Arduino.h>

// MQ3Sensor class following OOP principles for alcohol/fermentation detection
class MQ3Sensor {
private:
    uint8_t _pin; // GPIO pin connected to the MQ-3 sensor AO

public:
    // Constructor to initialize the sensor pin
    MQ3Sensor(uint8_t pin) {
        _pin = pin;
    }

    // Initialize pin mode
    void begin() {
        pinMode(_pin, INPUT);
    }

    // Read analog value from MQ-3 sensor
    int readRawValue() {
        return analogRead(_pin);
    }
};

#endif