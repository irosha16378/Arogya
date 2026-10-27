#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H

#include <Arduino.h>

// TDSSensor class following OOP principles for modular design
class TDSSensor {
private:
    uint8_t _pin; // GPIO pin connected to the TDS sensor

public:
    // Constructor to initialize the sensor pin
    TDSSensor(uint8_t pin) {
        _pin = pin;
    }

    // Initialize pin mode
    void begin() {
        pinMode(_pin, INPUT);
    }

    // Read analog value and calculate TDS in ppm
    float readTDS() {
        int rawValue = analogRead(_pin);
        
        // Convert raw ADC value to voltage (ESP32 ADC is 3.3V)
        float voltage = rawValue * (3.3 / 4095.0);
        
        // Formula to calculate TDS value from voltage
        float tdsValue = (133.42 * voltage * voltage * voltage - 255.86 * voltage * voltage + 857.39 * voltage) * 0.5;
        
        // Ensure TDS value is not negative
        if (tdsValue < 0) tdsValue = 0;
        
        return tdsValue;
    }
};

#endif