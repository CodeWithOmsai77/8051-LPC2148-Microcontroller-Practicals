#include <LPC214x.h>

#define CS (1 << 7)

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 10000; i++);
}

void spi_init(void)
{
    PINSEL0 |= 0x00001500;

    IO0DIR |= CS;
    IO0SET = CS;

    S0SPCR = 0x20;
    S0SPCCR = 8;
}

unsigned char spi_transfer(unsigned char data)
{
    S0SPDR = data;

    while(!(S0SPSR & 0x80));

    return S0SPDR;
}

void sd_send_command(unsigned char cmd,
                     unsigned long arg,
                     unsigned char crc)
{
    IO0CLR = CS;

    spi_transfer(0x40 | cmd);
    spi_transfer(arg >> 24);
    spi_transfer(arg >> 16);
    spi_transfer(arg >> 8);
    spi_transfer(arg);
    spi_transfer(crc);

    spi_transfer(0xFF);

    IO0SET = CS;
}

void main(void)
{
    unsigned char i;

    spi_init();

    for(i = 0; i < 10; i++)
        spi_transfer(0xFF);

    sd_send_command(0, 0, 0x95); // CMD0

    while(1);
}