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
    motors[1].temperature = 80.6f;
    motors[1].state = OFF;


    strncpy(motors[2].name, "Nidec-Pro", sizeof(motors[2].name) - 1);
    motors[2].name[sizeof(motors[2].name) - 1] = '\0';

    motors[2].voltage = 5.0f;
    motors[2].current = 0.8f;
    motors[2].temperature = 100.1f;
    motors[2].state = STARTING;
    
    for (int i = 0; i < MOTOR_COUNT ; i++)
{
    Status result = UpdateMotorState(&motors[i]);

    if (result != STATUS_OK)
    {
        printf("Error updating motor %d!\n", i);
        continue;  
    }

    printMotor(&motors[i]);
}

printf("\n--- Testing setMotorVoltage ---\n");

Status testResult;


testResult = setMotorVoltage(&motors[0], 12.0f);
switch (testResult)
{
    case STATUS_OK:
        printf("Test 1 (valid value): OK, voltage = %.1f\n", motors[0].voltage);
        break;
    case STATUS_ERROR_NULL_PTR:
        printf("Test 1: Error - NULL pointer\n");
        break;
    case STATUS_ERROR_INVALID_PARAM:
        printf("Test 1: Error - invalid parameter\n");
        break;
    default:
        printf("Test 1: Unknown error\n");
        break;
}


testResult = setMotorVoltage(NULL, 12.0f);
switch (testResult)
{
    case STATUS_OK:
        printf("Test 2 (NULL pointer): OK\n");
        break;
    case STATUS_ERROR_NULL_PTR:
        printf("Test 2: Error - NULL pointer, as expected\n");
        break;
    case STATUS_ERROR_INVALID_PARAM:
        printf("Test 2: Error - invalid parameter\n");
        break;
    default:
        printf("Test 2: Unknown error\n");
        break;
}


testResult = setMotorVoltage(&motors[0], 50.0f);
switch (testResult)
{
    case STATUS_OK:
        printf("Test 3 (out of range): OK\n");
        break;
    case STATUS_ERROR_NULL_PTR:
        printf("Test 3: Error - NULL pointer\n");
        break;
    case STATUS_ERROR_INVALID_PARAM:
        printf("Test 3: Error - invalid parameter, as expected\n");
        break;
    default:
        printf("Test 3: Unknown error\n");
        break;
}


    return 0;
}