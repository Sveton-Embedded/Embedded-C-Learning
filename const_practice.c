#include <stdio.h>

typedef float Voltage;

void printVoltage(const Voltage *v)
{
    printf("Voltage: %.1f\n", *v);
}

void increaseVoltage(Voltage *v)
{
    *v += 10.0f;
}

int main(void)
{

    Voltage voltage = 400.0f;
    const Voltage *ptr = &voltage;

    printVoltage(ptr);
    increaseVoltage(&voltage);
    printVoltage(ptr);

    return 0;

}
