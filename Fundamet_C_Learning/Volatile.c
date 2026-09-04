#include <stdio.h>
#include <stdbool.h>

volatile float temperature = 0.0f;
volatile bool newData = false;

void sensorInterrupt(float newTemperature)
{
    temperature = newTemperature;
    newData = true;
}

int main(void)
{
    float testMeasurements[3] = {75.0f, 85.0f, 105.0f};

    for (int i = 0; i < 3; i++)
    {
        int waitCount = 0;
        while(!newData)
        {
            printf("Waiting for sensor...\n");
            
            waitCount++;
            
            if(waitCount == 3)
            {
                sensorInterrupt(testMeasurements[i]);
            }
        }

        printf("========================\n");
        printf("NEW SENSOR DATA\n");
        printf("========================\n");
        printf("Temperature: %.1f C\n\n", temperature);

        if (temperature < 80.0f)
        {
            printf("MOTOR OK\n\n");
        }
        else if (temperature < 100.0f)
        {
            printf("WARNING\n\n");
        }
        else
        {
            printf("CRITICAL\n\n");
        }

        newData = false;
    }

    return 0;
}

