#ifndef _IHM_H_
    #define _IHM_H_

#include <Arduino.h>

#define BTN_GPIO 0 // D3 MCUpin
#define LED_GPIO 2 //  D4 MCUpin

static bool btn_P = false;

void initFunc();
void btnCB(void *tCall);
void wifiLED(void *tCall);
    
#endif