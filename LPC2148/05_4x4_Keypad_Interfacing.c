#include <LPC214x.h>

unsigned char keypad[4][4] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

unsigned char read_keypad(void)
{
    unsigned int row, col;
    unsigned int rows = 0x000F0000;
    unsigned int cols = 0x000F0000;

    for(row = 0; row < 4; row++)
    {
        IO1SET = rows;
        IO1CLR = (1 << (16 + row));

        for(col = 0; col < 4; col++)
        {
            if(!(IO1PIN & (1 << (20 + col))))
            {
                while(!(IO1PIN & (1 << (20 + col))));
                return keypad[row][col];
            }
        }
    }

    return 0;
}

void main(void)
{
    unsigned char key;

    PINSEL2 = 0x00000000;

    IO1DIR |= 0x000F0000;
    IO1DIR &= ~0x00F00000;

    while(1)
    {
        key = read_keypad();

        if(key != 0)
            IO0PIN = (IO0PIN & ~0xFF) | key;
    }
}