#ifndef __PANTALLITAXD_H__
#define __PANTALLITAXD_H__

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class PantallitaXD
{
public:
    PantallitaXD();
    void init();
    void printData(float &data1, float &data2, float &data3, float &data4, int &steps1, int &steps2, int *direcction);

private:
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
};

#endif // __PANTALLITAXD_H__