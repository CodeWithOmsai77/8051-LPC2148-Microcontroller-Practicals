#include <LPC214x.h>

#define GLCD_DATA 0x00FF0000

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 10000; i++);
}

void glcd_command(unsigned char cmd)
{
    IO0CLR = GLCD_DATA;
    IO0SET = ((unsigned int)cmd << 16);

    IO0CLR = (1 << 8);  // RS = 0
    IO0CLR = (1 << 9);  // RW = 0
    IO0SET = (1 << 10); // EN = 1

    delay();

    IO0CLR = (1 << 10);
}

void glcd_data(unsigned char data)
{
    IO0CLR = GLCD_DATA;
    IO0SET = ((unsigned int)data << 16);

    IO0SET = (1 << 8);  // RS = 1
    IO0CLR = (1 << 9);  // RW = 0
    IO0SET = (1 << 10);

    delay();

    IO0CLR = (1 << 10);
}

void main(void)
{
    IO0DIR |= GLCD_DATA | (1 << 8) | (1 << 9) | (1 << 10);

    glcd_command(0x3F); // Display ON
    glcd_command(0xC0); // Start line

    glcd_data('H');
    glcd_data('E');
    glcd_data('L');
    glcd_data('L');
    glcd_data('O');

    while(1);
}