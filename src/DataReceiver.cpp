// datareceiver.cpp
#include "DataReceiver.h"

DataReceiver::DataReceiver(LDR &ldr1, LDR &ldr2, LDR &ldr3, LDR &ldr4)
{
    ldrs[0] = &ldr1; // Superior Derecha
    ldrs[1] = &ldr2; // Inferior Derecha
    ldrs[2] = &ldr3; // Superior Izquierda
    ldrs[3] = &ldr4; // Inferior Izquierda
}

void DataReceiver::update()
{
    for (uint8_t i = 0; i < 4; i++)
    {
        rawValues[i] = ldrs[i]->readRaw(); // Actualiza lecturas
    }
}

uint8_t DataReceiver::getBrightestLDR()
{
    uint8_t brightestIdx = 0;
    uint16_t maxValue = rawValues[0];

    for (uint8_t i = 1; i < 4; i++)
    {
        if (rawValues[i] > maxValue)
        {
            maxValue = rawValues[i];
            brightestIdx = i;
        }
    }

    return brightestIdx + 1; // Devuelve 1-6 (no 0-3)
}

float DataReceiver::getLDRVoltage(uint8_t ldrNum)
{
    if (ldrNum < 1 || ldrNum > 4)
        return 0.0; // Validación
    return ldrs[ldrNum - 1]->readVoltage();
}

float DataReceiver::getLDRAverageUp()
{
    float sum = ldrs[0]->readVoltage() + ldrs[2]->readVoltage();
    return sum / 2.0f;
}

float DataReceiver::getLDRAverageDown()
{
    float sum = ldrs[1]->readVoltage() + ldrs[3]->readVoltage();
    return sum / 2.0f;
}

float DataReceiver::getLDRAverageLeft()
{
    float sum = ldrs[0]->readVoltage() + ldrs[1]->readVoltage();
    return sum / 2.0f;
}

float DataReceiver::getLDRAverageRight()
{
    float sum = ldrs[2]->readVoltage() + ldrs[3]->readVoltage();
    return sum / 2.0f;
}

// #define LDR1_PIN 34 // Superior Izquierda 0
// #define LDR2_PIN 35 // Inferior Izquierda 1
// #define LDR3_PIN 32 // Superior Derecha 2
// #define LDR4_PIN 33 // Inferior Derecha 3
