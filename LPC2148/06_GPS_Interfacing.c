#include <LPC214x.h>

void uart1_init(void)
{
    PINSEL0 |= (1 << 16) | (1 << 18);

    U1LCR = 0x83;
    U1DLL = 97;
    U1DLM = 0;
    U1LCR = 0x03;
}

void uart0_init(void)
{
    PINSEL0 |= 0x00000005;

    U0LCR = 0x83;
    U0DLL = 97;
    U0DLM = 0;
    U0LCR = 0x03;
}

void uart0_send(unsigned char data)
{
    while(!(U0LSR & 0x20));
    U0THR = data;
}

void main(void)
{
    unsigned char gps_data;

    uart1_init();
    uart0_init();

    while(1)
    {
        if(U1LSR & 0x01)
        {
            gps_data = U1RBR;
            uart0_send(gps_data);
        }
    }
}