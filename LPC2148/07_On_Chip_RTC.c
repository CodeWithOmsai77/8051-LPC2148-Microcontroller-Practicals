#include <LPC214x.h>

void rtc_init(void)
{
    CCR = 0x00;

    SEC = 0;
    MIN = 30;
    HOUR = 10;

    DOM = 15;
    MONTH = 11;
    YEAR = 2026;

    CCR = 0x01;
}

void main(void)
{
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;

    rtc_init();

    while(1)
    {
        seconds = SEC;
        minutes = MIN;
        hours = HOUR;
    }
}