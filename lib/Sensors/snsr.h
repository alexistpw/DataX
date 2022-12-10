#ifndef _SNSR_H_
    #define _SNSR_H_

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define TMP_GPIO 5 //  D1 MCUpin



class DataSnsr
{
    protected:
    float T_average;
    float T_deviation;
    DallasTemperature *prt_T = new DallasTemperature;
    
    private:
    float T_measure{};
    float T_data[10]{999.99, 999.99, 999.99, 999.99, 999.99, 999.99, 999.99, 999.99, 999.99, 999.99};
    const uint8_t T_index;
    uint8_t T_except;

    public:
    float getT_Measure();
    int getT_index();
    void displayT_data();
    void feedT_data();
    void ADT_data(); // Average / Deviation
    float getT_average();

    // Construct / Destruct
    DataSnsr(DallasTemperature*, int index = 0);
    ~DataSnsr();
};
    

#endif