#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#define MOTOR_COUNT 3

typedef float Voltage;
typedef float Current;
typedef float Temperature;

typedef enum
{
    OFF,
    STARTING,
    RUNNING,
    ERROR,
}MotorState;

typedef struct
{
    char name[20];
    Voltage voltage;
    Current current;
    Temperature temperature;
    MotorState state;
}Motor;

void printMotor(Motor *m)
{
    printf("Name        : %s\n", m->name);
    printf("Voltage     : %.1f V\n", m->voltage);
    printf("Current     : %.1f A\n", m->current);
    printf("Temperature : %.1f C\n", m->temperature);

    switch(m->state)
    {
        case OFF:
        printf("State : OFF\n");
        break;

        case STARTING:
        printf("State : STARTING\n");
        break;

        case RUNNING:
        printf("State : RUNNING\n");
        break;

        case ERROR:
        printf("State : ERROR\n");
        break;

        default:
        printf("State : UNKNOWN\n");
        break;
    }
}
    
void UpdateMotorState(Motor *m)
    {
        if (m == NULL) 
        {
        return; 
        }

    if (m->temperature >= 100.0f) 

    {
        m->state = ERROR;
    }

    else if (m->voltage > 0.0f) 

    {
        m->state = RUNNING;
    } 

    else 
    {
        m->state = OFF;
    }
}


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