#include "LDR.h"
#include "DataReceiver.h"
#include "NEMA17.h"
#include "JOYSTICK.h"
#include "DEF.h"

LDR ldr1(LDR_SI);
LDR ldr2(LDR_II);
LDR ldr3(LDR_SD);
LDR ldr4(LDR_ID);
float promedioUp = 0;
float promedioDown = 0;
float promedioLeft = 0;
float promedioRight = 0;

DataReceiver receiver(ldr1, ldr2, ldr3, ldr4);
NEMA17 motorHorizontal(ENA, DIR, STEP);
NEMA17 motorVertical(ENA_V,DIR_V,STEP_V);
JOYSTICK joystick(VRX_PIN, VRY_PIN, SW_PIN);
bool configuracion = false;
void setup()
{
    Serial.begin(115200);
}

void loop()
{
    // Leer los valores del joystick
    int valorX = joystick.mapX(0, 255);
    int valorY = joystick.mapY(0, 255);
    // receiver.update();
    // promedioUp = receiver.getLDRAverageUp();
    // promedioDown = receiver.getLDRAverageDown();
    // promedioLeft = receiver.getLDRAverageLeft();
    // promedioRight = receiver.getLDRAverageRight();
    // Serial.print("Promedio LDR Superiores: ");
    // Serial.print(promedioUp);
    // Serial.print(", Promedio LDR Inferiores: ");
    // Serial.print(promedioDown);
    // Serial.print(", Promedio LDR Derecha: ");
    // Serial.print(promedioRight);
    // Serial.print(", Promedio LDR Izquierda: ");
    // Serial.println(promedioLeft);

    // if (promedioLeft - promedioRight > 0.20)
    // {
    //     Serial.println("Moviendo hacia la izquierda...");
    //     motorHorizontal.moveLeft(); // Mover el motor hacia la izquierda
    // }
    // else if (promedioRight - promedioLeft > 0.50)
    // {
    //     Serial.println("Moviendo hacia la derecha...");
    //     motorHorizontal.moveRight(); // Mover el motor hacia la derecha
    // }
    // else
    // {
    //     Serial.println("Ambas LDR tienen el mismo valor. Motor detenido.");
    // }

    if (joystick.wasPressed())
    {
        configuracion = !configuracion;

        if (configuracion)
        {
            Serial.println("Entrando en modo configuración");
        }
        else
        {
            Serial.println("Saliendo de modo configuración");
        }
    }

    if (configuracion)
    {
        Serial.println("Dentro del modo configuración");
        if (valorX > 175)
        {
            Serial.println("Moviendo Derecha");
            motorHorizontal.moveRight();
        }
        else if (valorX < 75)
        {
            Serial.println("Moviendo Izquierda");
            motorHorizontal.moveLeft();
        }
        Serial.println("Dentro del modo configuración");
        if (valorY > 175)
        {
            Serial.println("Moviendo Arriba");
            motorVertical.moveUp();
        }
        else if (valorY < 75)
        {
            Serial.println("Moviendo Abajo");
            motorVertical.moveDown();
        }
    }

    delay(5);
}

// }
