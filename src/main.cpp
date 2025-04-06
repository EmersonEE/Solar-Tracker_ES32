#include "LDR.h"
#include "DataReceiver.h"
#include "NEMA17.h"
#include "JOYSTICK.h"
#include "DEF.h"

// Crear instancias de LDR
LDR ldr1(LDR_SI);
LDR ldr2(LDR_II);
LDR ldr3(LDR_SD);
LDR ldr4(LDR_ID);
float promedioUp = 0;
float promedioDown = 0;
float promedioLeft = 0;
float promedioRight = 0;
// Crear DataReceiver con los 4 LDRs
DataReceiver receiver(ldr1, ldr2, ldr3, ldr4);
NEMA17 motorBase(ENA, DIR, STEP);
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
        receiver.update();
        promedioUp = receiver.getLDRAverageUp();
        promedioDown = receiver.getLDRAverageDown();
        promedioLeft = receiver.getLDRAverageLeft();
        promedioRight = receiver.getLDRAverageRight();
        Serial.print("Promedio LDR Superiores: ");
        Serial.print(promedioUp);
        Serial.print(", Promedio LDR Inferiores: ");
        Serial.print(promedioDown);
        Serial.print(", Promedio LDR Derecha: ");
        Serial.print(promedioRight);
        Serial.print(", Promedio LDR Izquierda: ");
        Serial.println(promedioLeft);
        // Comparar los valores y mover el motor
        
        // promedioDown = ldr1.readVoltage();
        // promedioLeft = ldr2.readVoltage();
        // promedioRight = ldr3.readVoltage();
        // promedioUp = ldr4.readVoltage();
        // Serial.print(promedioDown);
        // Serial.print(",");
        // Serial.print(promedioLeft);
        // Serial.print(",");
        // Serial.print(promedioRight);
        // Serial.print(",");
        // Serial.println(promedioUp);
        delay(100);
        if (promedioLeft - promedioRight > 0.20)
        {
            Serial.println("Moviendo hacia la izquierda...");
            motorBase.moveLeft(); // Mover el motor hacia la izquierda
        }
        else if (promedioRight - promedioLeft > 0.50)
        {
            Serial.println("Moviendo hacia la derecha...");
            motorBase.moveRight(); // Mover el motor hacia la derecha
        }
        else
        {
            Serial.println("Ambas LDR tienen el mismo valor. Motor detenido.");
        }

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
                motorBase.moveRight();
            }
            else if (valorX < 75)
            {
                Serial.println("Moviendo Izquierda");
                motorBase.moveLeft();
            }
        }

        delay(5);
    }

// }
