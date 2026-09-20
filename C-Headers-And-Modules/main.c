#include <string.h>
#include <stdio.h>
#include "motor.h"

int main(void)
{
    
    Motor motors[MOTOR_COUNT];


    strncpy(motors[0].name, "Siemens24", sizeof(motors[0].name) - 1);
    motors[0].name[sizeof(motors[0].name) - 1] = '\0';

    motors[0].voltage = 400.0f;
    motors[0].current = 22.0f;
    motors[0].temperature = 75.0f;
    motors[0].state = RUNNING;

    char infoBuffer[50];
    formatMotorInfo(&motors[0], infoBuffer, sizeof(infoBuffer));
    printf("%s\n", infoBuffer);


    

    
    strncpy(motors[1].name, "Bosch-X", sizeof(motors[1].name) - 1);
    motors[1].name[sizeof(motors[1].name) - 1] = '\0';

    motors[1].voltage = 12.0f;
    motors[1].current = 1.5f;
    motors[1].temperature = 36.6f;
    motors[1].state = OFF;


    strncpy(motors[2].name, "Nidec-Pro", sizeof(motors[2].name) - 1);
    motors[2].name[sizeof(motors[2].name) - 1] = '\0';

    motors[2].voltage = 5.0f;
    motors[2].current = 0.8f;
    motors[2].temperature = 42.1f;
    motors[2].state = STARTING;

    
    for (int i = 0; i < MOTOR_COUNT ; i++)
    {
        UpdateMotorState(&motors[i]);
        printMotor(&motors[i]);
    }


    return 0;
}