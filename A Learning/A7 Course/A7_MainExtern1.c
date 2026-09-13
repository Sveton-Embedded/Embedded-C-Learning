#include <stdio.h>

extern int motorCount;

void printfFromMotorFile(void);

int main(void)
{
    printf("motorCount inside A7_MainExtern1.c:  %d\n", motorCount);

    motorCount = 10;

    printfFromMotorFile();

    return 0;
}
