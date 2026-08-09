#ifndef MOTOR_H
#define MOTOR_H
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


void printMotor(Motor *m);
void UpdateMotorState(Motor *m);

#endif