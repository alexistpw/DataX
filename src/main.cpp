#include <Arduino.h>
#include "user_interface.h"
#include "ihm.h"

os_timer_t btnPress;
os_timer_t wifiLight;
os_timer_t sensorread;

bool btn_P {false} ;

void btnCB(void *tCall)
{
    btn_P = false;
    
    Serial.print("ESP RESTART!");
    ESP.restart();
}

void wifiLED(void *tCall)
{
    digitalWrite(LED_WIFI, !digitalRead(LED_WIFI));
}

void snsrRead()
{
    
}

void btnDetect()
{
    if ((!digitalRead(BTN_PIN)) && (!btn_P))
    {
        os_timer_arm(&btnPress, 5000, true);
        btn_P = true;
    }
    if (digitalRead(BTN_PIN)  && (btn_P))
    {
        os_timer_disarm(&btnPress);
        btn_P = false;
    }
}

void setup() 
{
    GPIODATA GPD;
    GPD.initFunc();
    os_timer_setfn(&btnPress, btnCB, NULL);
    os_timer_setfn(&wifiLight, wifiLED, NULL);
    os_timer_setfn(&sensorread, snsrRead, NULL);
    os_timer_arm(&wifiLight, 1000, true);
    
}

void loop() 
{
    btnDetect();
}