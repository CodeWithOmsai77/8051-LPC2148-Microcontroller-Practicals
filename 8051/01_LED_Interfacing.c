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
        P1 = 0xFF;
        delay();

        P1 = 0x00;
        delay();
    }
}