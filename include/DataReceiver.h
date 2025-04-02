// datareceiver.h
#ifndef ESP_TRAINNER_H
#define ESP_TRAINNER_H

#include <Arduino.h>
#include "LDR.h"


class DataReceiver
{
public:
    DataReceiver(LDR &ldr1, LDR &ldr2, LDR &ldr3, LDR &ldr4, LDR &ldr5, LDR &ldr6);
    void update();
    uint8_t getBrightestLDR();
    float getLDRVoltage(uint8_t ldrNum);
    float getLDRAverageUp();
    float getLDRAverageDown();
    float getLDRAverageCenter();
    float getLDRAverageLeft();
    float getLDRAverageRight();

private:
    LDR *ldrs[6];          // Array de punteros a LDRs
    uint16_t rawValues[6]; // Almacena lecturas actuales
};
#endif