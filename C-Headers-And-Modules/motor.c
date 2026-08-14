#include <stdio.h>
#include "motor.h"

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

static void checkTemperature(const Motor *m)
    {
        printf("\nTemperature: %.1f C\n", m->temperature);
        if(m->temperature >= 100.0f)
        {
            printf("Temperature Status : CRITICAL\n\n");
        }

        else if(m->temperature >= 80.0f)
        {
            printf("Temperature Status : WARNING\n\n");
        }

        else
        {
            printf("Temperature Status : NORMAL\n\n");
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

    checkTemperature(m);

}

