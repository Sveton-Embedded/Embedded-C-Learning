#include <stdio.h>

void checkMotorStart(void)
{
    static int checkStart = 0;
    checkStart ++;
    printf("Motor started\n");
    printf("Start count: %d\n", checkStart);

}

void motorTemperature(float temperature)
{
    static int measurementCount = 0;
    measurementCount ++;
    printf("Measurement #%d\n", measurementCount);
    printf("Temperature : %.1f C\n\n\n", temperature);
}

int main(void)
{
    checkMotorStart();
    motorTemperature(75.0f);

    checkMotorStart();
    motorTemperature(89.0f);

    checkMotorStart();
    motorTemperature(24.5f);

    checkMotorStart();
    motorTemperature(56.0f);

    checkMotorStart();
    motorTemperature(38.9f);

    return 0;
}