#include <Arduino.h>
#include "user_interface.h"
#include "ihm.h"

os_timer_t btnPress;
bool btn_P {false} ;

void btnCB(void *tCall)
{
    btn_P = false;
    
    Serial.print("LED WIFI SWITCH!");
    digitalWrite(LED_WIFI, !digitalRead(LED_WIFI));
}



void btnDetect()
{
    if ((!digitalRead(BTN_PIN)) && (!btn_P))
    {
        os_timer_arm(&btnPress, 3000, true);
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
    
}

void loop() 
{
    btnDetect();
}