#include <stdio.h>


typedef enum
{
    OFF,
    STARTING,
    RUNNING,
    ERROR
} MotorState;

typedef struct
{
    char name[20];
    MotorState state;
} Motor;

void handleOff(Motor *m)
{
    printf("%s is OFF\n", m->name);
}

void handleStarting(Motor *m)
{
    printf("%s is STARTING\n", m->name);
}

void handleRunning(Motor *m)
{
    printf("%s is RUNNING\n", m->name);
}

void handleError(Motor *m)
{
    printf("%s is ERROR\n", m->name);
}

void (*stateHandlers[])(Motor*) =
{
    handleOff,
    handleStarting,
    handleRunning,
    handleError,
};

void updateMotorState(Motor *m)
{
     if (m->state < 0 || m->state >= sizeof(stateHandlers)/sizeof(stateHandlers[0]))
    {
        printf("%s unknown state!\n", m->name);
        return;
    }

    stateHandlers[m->state](m);
}

int main(void)
{
    Motor m1 =
    {
        "Motor1", RUNNING
    };

    m1.state = STARTING;
    updateMotorState(&m1);

    return 0;
}