#include <stdio.h>

int main (void)
{
    unsigned char reg = 255;

    reg &= ~(1 << 0);
    reg &= ~(1 << 2);

    printf("%u\n" , reg);

    return 0;
}