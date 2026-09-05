#include <stdio.h>
#include <stddef.h>
#define MOTOR_COUNTS 5

struct Motor
{
    int id;
    int speed;
};

#define ARRAY_LEN(arr) (sizeof(arr)/sizeof((arr)[0]))

int main(void)
{
    struct Motor motors[] =
    {
        {1, 100}, {2, 200}, {3, 300}, {4, 400}, {5, 500}
    };
    
    for (size_t i = 0; i < ARRAY_LEN(motors); i++) 
    {

    printf("Motor ID: %d, Speed: %d RPM\n", motors[i].id, motors[i].speed);

    }

    return 0;


}