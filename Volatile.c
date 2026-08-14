#include <stdio.h>
#include <stdbool.h>

volatile float sensorValue = 0.0f;
volatile bool dataReady = false;

void sensorInterrupt(void)
{
    sensorValue = 75.0f;
    dataReady = true;
}

int main(void)
{

int waitCount = 0;

    while(!dataReady)
    {
       printf("Waiting for sensor...\n"); 

       waitCount++;

    if(waitCount == 5)
    {
        sensorInterrupt();
    }
    }


    printf("========================\n");
    printf("Sensor Data received\n");
    printf("========================\n");
    printf("Temperature: %.1f C\n", sensorValue);

    return 0;

}



