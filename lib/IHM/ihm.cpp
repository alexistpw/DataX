#include "ihm.h"

    
void initFunc()
{
    Serial.begin(115200);
    pinMode(LED_GPIO, OUTPUT);
    pinMode(BTN_GPIO, INPUT_PULLUP);
}

void btnCB(void *tCall)
{
    btn_P = false; 
    Serial.print("ESP RESTART!");
    ESP.restart();
}

void wifiLED(void *tCall)
{
    digitalWrite(LED_GPIO, !digitalRead(LED_GPIO));
}




    