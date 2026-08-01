#include <stdio.h>

int main (void)
{
    unsigned char reg = 255;

    reg = ~reg;

    printf("%u\n" , reg);

    return 0;
}