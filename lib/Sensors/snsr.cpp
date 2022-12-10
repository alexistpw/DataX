#include "snsr.h"


//Construct
DataSnsr::DataSnsr(DallasTemperature *s_T, int index): T_index{index}
{
    prt_T = s_T;
    prt_T->begin();
    if (index >= 0 && index < 7) T_measure = prt_T->getTempCByIndex(T_index);
    else T_measure = 999.99;
    T_except = 0;
}

//Destruct
DataSnsr::~DataSnsr()
{
    delete prt_T;
}

//====================================================================
//Methods
float DataSnsr::getT_Measure()
{
    return T_measure;
}

int DataSnsr::getT_index()
{
    return T_index;
}

void DataSnsr::displayT_data()
{
    Serial.println();
    Serial.print("{");
    for (auto i:T_data)
    {
        Serial.print(i);
        Serial.print(", ");
    }
    Serial.print("}");
}

void DataSnsr::ADT_data()
{
    T_average = 0;
    T_deviation = 0;
    for (auto i:T_data) T_average += i;
    T_average /= 10;

    for (auto i:T_data)
    {
        T_deviation += (i-T_average)*(i-T_average);
    }
    T_deviation /= 10;
    T_deviation = sqrt(T_deviation);

    #ifdef _DEBUG_
    Serial.print("Average Radings: "); Serial.println(T_average); 
    Serial.print("Deviation: "); Serial.println(T_deviation); 
    #endif
}

void DataSnsr::feedT_data()
{
    if (T_index >= 0 && T_index < 7)
    {
        T_measure = prt_T->getTempCByIndex(T_index);
        for (auto &i:T_data)
        {
            if (i == 999.99) 
            {
                i = T_measure;
                return;
            }
        }
        if (((T_measure - T_average) < (1.3*T_deviation)) || (T_except==3))
        {
            for (int i=0; i<9; i++)
            {
                T_data[i+1] = T_data[i];
            }
            T_data[0] = T_measure;
            
            ADT_data();
            T_except = 0;
            return;
        }
        else T_except++;
    }
    else T_measure = 999.99;
}

float DataSnsr::getT_average()
{
    return T_average;
}
