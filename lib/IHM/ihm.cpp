#include <Arduino.h>
#include "ihm.h"

    
void GPIODATA::initFunc()
{
    Serial.begin(115200);
    pinMode(LED_WIFI, OUTPUT);
    pinMode(BTN_PIN, INPUT_PULLUP);
}


    