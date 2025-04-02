#ifndef NEMA_H
#define NEMA_H

#include <Arduino.h>
class NEMA17
{

public:
    // PinEnable - PinDirection - PinSteps
    NEMA17(uint8_t _pinENA, uint8_t _pinDIR, uint8_t _pinSTEP);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void testMotorM1();
    void testMotorM2();

private:
    int stepsPerRevolutionM1 = 2400;
    int stepsPerRevolutionM2 = 2400;
    uint8_t pinENA;
    uint8_t pinDIR;
    uint8_t pinSTEP;
    // const int stepsPerRevolution = 2400;
};

#endif