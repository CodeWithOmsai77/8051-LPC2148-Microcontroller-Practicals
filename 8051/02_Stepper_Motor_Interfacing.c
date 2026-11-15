#include <8051.h>

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
        for(j = 0; j < 500; j++);
}

void main(void)
{
    unsigned char step[4] = {0x09, 0x0C, 0x06, 0x03};
    unsigned char i;

    while(1)
    {
        for(i = 0; i < 4; i++)
        {
            P1 = step[i];
            delay();
        }
    }
}