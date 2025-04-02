// datareceiver.cpp
#include "DataReceiver.h"

DataReceiver::DataReceiver(LDR &ldr1, LDR &ldr2, LDR &ldr3, LDR &ldr4, LDR &ldr5, LDR &ldr6)
{
    ldrs[0] = &ldr1;
    ldrs[1] = &ldr2;
    ldrs[2] = &ldr3;
    ldrs[3] = &ldr4;
    ldrs[4] = &ldr5;
    ldrs[5] = &ldr6;
}

void DataReceiver::update()
{
    for (uint8_t i = 0; i < 6; i++)
    {
        rawValues[i] = ldrs[i]->readRaw(); // Actualiza lecturas
    }
}

uint8_t DataReceiver::getBrightestLDR()
{
    uint8_t brightestIdx = 0;
    uint16_t maxValue = rawValues[0];

    for (uint8_t i = 1; i < 6; i++)
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
    if (ldrNum < 1 || ldrNum > 6)
        return 0.0; // Validación
    return ldrs[ldrNum - 1]->readVoltage();
}

float DataReceiver::getLDRAverageUp()
{
    float sum = 0.0f;
    for (uint8_t i = 0; i < 3; i++)
    {
        sum += ldrs[i]->readVoltage();
    }
    return sum / 3.0f;
}

float DataReceiver::getLDRAverageDown()
{
    float sum = 0.0f;
    for (uint8_t i = 3; i < 6; i++)
    {
        sum += ldrs[i]->readVoltage();
    }
    return sum / 3.0f;
}

float DataReceiver::getLDRAverageLeft()
{
    float sum = ldrs[0]->readVoltage() + ldrs[3]->readVoltage();
    return sum / 2.0f;
}

float DataReceiver::getLDRAverageRight()
{
    float sum = ldrs[2]->readVoltage() + ldrs[5]->readVoltage();
    return sum / 2.0f;
}

float DataReceiver::getLDRAverageCenter()
{
    float sum = ldrs[1]->readVoltage() + ldrs[4]->readVoltage();
    return sum / 2.0f;
}