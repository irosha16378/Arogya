#ifndef MQ135_SENSOR_H
#define MQ135_SENSOR_H

#include <Arduino.h>

// MQ135Sensor class following OOP principles
class MQ135Sensor {
private:
    uint8_t _pin; // GPIO pin connected to the MQ-135 sensor AO

public:
    // Constructor to initialize the sensor pin
    MQ135Sensor(uint8_t pin) {
        _pin = pin;
    }

    // Initialize pin mode
    void begin() {
        pinMode(_pin, INPUT);
    }

    // Read analog value from MQ-135 sensor
    int readRawValue() {
        return analogRead(_pin);
    }
};

#endif