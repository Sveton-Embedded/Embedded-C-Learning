#include <stdio.h>

typedef struct 
{
    char name[20];
    float voltage;
}Motor;

typedef void (*MotorCallback)(Motor*);


void printMotor(Motor *m)
{
    printf("%s: %.2fV\n", m->name, m->voltage);
}

void forEachMotor(Motor *motors, int count, MotorCallback action)
{
    for(int i = 0; i < count; i++)
    {
        action(&motors[i]);
    }
}


int main(void)
{
    Motor motors[3] = {
        {"Motor1", 55.0f},
        {"Motor2", 24.0f},
        {"Motor3", 50.0f}
    };

    forEachMotor(motors, 3, printMotor);   
    return 0;
}