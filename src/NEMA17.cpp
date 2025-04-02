#include "NEMA17.h"
// PinEnable - PinDirection - PinSteps
NEMA17::NEMA17(uint8_t _pinENA, uint8_t _pinDIR, uint8_t _pinSTEP)
{
    pinENA = _pinENA;
    pinDIR = _pinDIR;
    pinSTEP = _pinSTEP;
    pinMode(pinSTEP, OUTPUT);
    pinMode(pinDIR, OUTPUT);
    pinMode(pinENA, OUTPUT);
    digitalWrite(pinENA, LOW);
}

void NEMA17::moveRight()
{
    digitalWrite(pinDIR, HIGH);
    digitalWrite(pinSTEP, HIGH);
    delay(5);
    digitalWrite(pinSTEP, LOW);
    delay(5);
}

void NEMA17::moveUp()
{
    digitalWrite(pinDIR, HIGH);
    digitalWrite(pinSTEP, HIGH);
    delay(5);
    digitalWrite(pinSTEP, LOW);
    delay(5);
}

void NEMA17::moveLeft()
{
    digitalWrite(pinDIR, LOW);
    digitalWrite(pinSTEP, HIGH);
    delay(5);
    digitalWrite(pinSTEP, LOW);
    delay(5);
}

void NEMA17::moveDown()
{
    digitalWrite(pinDIR, LOW);
    digitalWrite(pinSTEP, HIGH);
    delay(5);
    digitalWrite(pinSTEP, LOW);
    delay(5);
}

void NEMA17::testMotorM1()
{
    for (int i = 0; i < stepsPerRevolutionM1; i++)
    {
        moveRight();
    }
    delay(2000);
    for (int i = 0; i < stepsPerRevolutionM1; i++)
    {
        moveLeft();
    }
    delay(2000);
}

void NEMA17::testMotorM2()
{
    for (int i = 0; i < stepsPerRevolutionM2; i++)
    {
        moveUp();
    }
    delay(2000);
    for (int i = 0; i < stepsPerRevolutionM2; i++)
    {
        moveDown();
    }
    delay(2000);
}
