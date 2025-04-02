#include "LDR.h"
#include "DataReceiver.h"
#include "NEMA17.h"
// Definición de pines LDR
#define LDR1_PIN 34 // LefTop
#define LDR2_PIN 35 // CenTop
#define LDR3_PIN 32 // RiTop
#define LDR4_PIN 33 // LefDown
#define LDR5_PIN 31 // CenDown
#define LDR6_PIN 30 // RiDown
#define STEP 16
#define DIR 17
#define ENA 18
// Crear instancias de LDR
LDR ldr1(LDR1_PIN);
LDR ldr2(LDR2_PIN);
LDR ldr3(LDR3_PIN);
LDR ldr4(LDR4_PIN);
LDR ldr5(LDR4_PIN);
LDR ldr6(LDR4_PIN);

// Crear DataReceiver con los 4 LDRs
DataReceiver receiver(ldr1, ldr2, ldr3, ldr4, ldr5, ldr6);
NEMA17 motorBase(ENA, DIR, STEP);
void setup()
{
    Serial.begin(115200);
}

void loop()
{
    receiver.update(); // Actualiza lecturas

    // Obtener el LDR más brillante (1-4)
    // uint8_t brightest = receiver.getBrightestLDR();
    // uint8_t valueLDR1 = ldr1.readMapped();
    // Serial.print(ldr1.readVoltage());
    // Serial.print(" + ");
    // Serial.print(ldr2.readVoltage());
    // Serial.print(" + ");
    // Serial.print(ldr3.readVoltage());
    // Serial.println("");
    // float promedioTop = receiver.getLDRAverageUp();
    // Serial.print("LDR más brillante: ");
    // Serial.println(brightest);
    // Serial.println(promedioTop);
    motorBase.testMotorM1();

    // delay(500);
}