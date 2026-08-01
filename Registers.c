#include <stdio.h>

typedef char LED1;
typedef char LED4;
typedef char LED7;

int main(void)
{
    unsigned char GPIO = 0;
    
    GPIO |= (1 <<  1);

    if(GPIO &(1 << 1))
    {
        printf("LED1 ON\n");
    }
    else
    {
        printf("LED1 OFF\n");
    }

    GPIO |= (1 <<  4);

    if(GPIO &(1 << 1))
    {
        printf("LED4 ON\n");
    }
    else
    {
        printf("LED4 OFF\n");
    }

    GPIO |= (1 <<  7);

    if(GPIO &(1 << 1))
    {
        printf("LED7 ON\n");
    }
    else
    {
        printf("LED7 OFF\n");
    }

 return 0;
}