#include <8051.h>

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 200; i++)
        for(j = 0; j < 500; j++);
}

void main(void)
{
    while(1)
    {
        P1_0 = 1;    // Relay ON
        P1_1 = 1;    // Buzzer ON

        delay();

        P1_0 = 0;    // Relay OFF
        P1_1 = 0;    // Buzzer OFF

        delay();
    }
}