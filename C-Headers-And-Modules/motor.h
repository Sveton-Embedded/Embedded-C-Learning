#ifndef MOTOR_H
#define MOTOR_H
#define MOTOR_COUNT 3

typedef float Voltage;
typedef float Current;
typedef float Temperature;

typedef enum {
    STATUS_OK = 0,
    STATUS_ERROR_NULL_PTR,
    STATUS_ERROR_TIMEOUT,
    STATUS_ERROR_INVALID_PARAM
} Status;

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
Status UpdateMotorState(Motor *m);
void formatMotorInfo(Motor *m , char *buffer, size_t bufferSize);

#endif