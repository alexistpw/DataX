#include "user_interface.h"
#include "ihm.h"
#include "snsr.h"

os_timer_t btnPress;
os_timer_t wifiLight;
os_timer_t sensorread;

OneWire wire_T(TMP_GPIO);
DallasTemperature snsr_T(&wire_T);
DataSnsr tsensor(&snsr_T,0);

void btnDetect()
{
    if ((!digitalRead(BTN_GPIO)) && (!btn_P))
    {
        os_timer_arm(&btnPress, 5000, true);
        btn_P = true;
    }
    if (digitalRead(BTN_GPIO)  && (btn_P))
    {
        os_timer_disarm(&btnPress);
        btn_P = false;
    }
}

void snsrRead(void *tCall)
{
    // tsensor.feedT_data(snsr_T);
    // tsensor.displayT_data();
}

void setup() 
{
    initFunc();

    snsr_T.begin();

    os_timer_setfn(&btnPress, btnCB, NULL);
    os_timer_setfn(&wifiLight, wifiLED, NULL);
    os_timer_setfn(&sensorread, snsrRead, NULL);
    os_timer_arm(&wifiLight, 1000, true);
    os_timer_arm(&sensorread, 1000, true);
    
}

void loop() 
{
    btnDetect();
}