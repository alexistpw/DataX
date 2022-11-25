#ifndef _IHM_H_
    #define _IHM_H_

    #define BTN_PIN 0 // D3 MCUpin
    #define LED_WIFI 2 //  D4 MCUpin

    class GPIODATA
    {
        private:
        os_timer_t btnPress;
        bool btn_P {false} ;

        public:
        void initFunc();

    };
#endif