#include <string.h>
#include "motor.h"

int main(void)
{
    
    Motor motors[MOTOR_COUNT];


    strcpy(motors[0].name, "Siemens24");
    motors[0].voltage = 400.0f;
    motors[0].current = 22.0f;
    motors[0].temperature = 75.0f;
    motors[0].state = RUNNING;

    strcpy(motors[1].name, "Bosch-X");
    motors[1].voltage = 12.0f;
    motors[1].current = 1.5f;
    motors[1].temperature = 36.6f;
    motors[1].state = OFF;

    strcpy(motors[2].name, "Nidec-Pro");
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