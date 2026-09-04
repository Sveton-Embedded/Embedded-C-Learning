#include <stdio.h>

void setBit(volatile unsigned *reg , int bit)
{
    *reg |= (1 << bit);
}

void clearBit(volatile unsigned *reg , int bit)
{
    *reg &= ~(1 << bit);
}

void checkBit(volatile unsigned *reg , int bit)
{  

if (*reg & (1 << bit))
{
    printf("Bit %d is ON\n", bit);

}
else
{
    printf("Bit %d is OFF\n", bit);
}

}

int main(void)
{
    volatile unsigned int *reg = (volatile unsigned int* )0X40021004;

    unsigned int val = *reg;


    setBit(reg , 3 );
    clearBit(reg , 3);
    checkBit(reg , 5);

    return 0;


}