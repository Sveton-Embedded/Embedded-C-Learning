#include <stdio.h>

int main (void)
{
    unsigned char reg = 0;

    reg |= (1 << 0);

    reg |= (1 << 3);

    printf("%u\n" , reg);

    return 0;
}