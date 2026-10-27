#ifndef BLE_HANDLER_H
#define BLE_HANDLER_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// Unique UUIDs for BLE Service and Characteristic
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class BLEHandler {
private:
    BLEServer* pServer;
    BLECharacteristic* pCharacteristic;

public:
    BLEHandler() {}

    // Initialize BLE with device name "Arogya"
    void begin(std::string deviceName) {
        BLEDevice::init(deviceName);
        pServer = BLEDevice::createServer();
        
        BLEService *pService = pServer->createService(SERVICE_UUID);
        
        pCharacteristic = pService->createCharacteristic(
                                CHARACTERISTIC_UUID,
                                BLECharacteristic::PROPERTY_READ |
                                BLECharacteristic::PROPERTY_NOTIFY
                            );
        
        pService->start();
        
        BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
        pAdvertising->addServiceUUID(SERVICE_UUID);
        pAdvertising->setScanResponse(true);
        pAdvertising->setMinPreferred(0x06); 
        pAdvertising->setMinPreferred(0x12);
        BLEDevice::startAdvertising();
    }

    // Send sensor data to connected mobile app
    void sendData(float tds, int mq3, int mq135) {
        char txString[64];
        // Format string like: "TDS:120.50,MQ3:2000,MQ135:1500"
        snprintf(txString, sizeof(txString), "TDS:%.2f,MQ3:%d,MQ135:%d", tds, mq3, mq135);
        
        pCharacteristic->setValue(txString);
        pCharacteristic->notify(); // Send notification to app
    }
};

#endif