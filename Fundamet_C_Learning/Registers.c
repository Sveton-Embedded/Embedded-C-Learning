#include <stdio.h>

void setBit(unsigned char *reg, int bit)
{
    *reg |= (1 << bit);
}

void clearBit(unsigned char *reg, int bit)
{
    *reg &= ~(1 << bit);
}

void toggleBit(unsigned char *reg, int bit)
{
    *reg ^= (1 << bit);
}

int main(void)
{
    unsigned char GPIO = 155;

    setBit(&GPIO , 3 );
    clearBit(&GPIO , 5);
    toggleBit(&GPIO , 4);

    printf("%d\n" , GPIO);

    return 0;
}