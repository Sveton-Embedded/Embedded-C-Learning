#include <stdio.h>
#include <stdint.h>

typedef struct
{
    char name[20];
    float voltage;
    float capacity;
    float temperature;
    uint8_t motorStatus;
} Motor;

int find_free_motor(Motor **motors, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (motors[i]->motorStatus == 0)
        {
            return i; 
        }
    }

    return -1;  
}

int main(void)
{
    Motor m1 = {"Motor1", 12.0f, 5.0f, 30.0f, 1};   
    Motor m2 = {"Motor2", 12.0f, 5.0f, 35.0f, 1};   
    Motor m3 = {"Motor3", 12.0f, 5.0f, 40.0f, 0};   

    Motor *motorPtrs[3] = {&m1, &m2, &m3};

    int freeIndex = find_free_motor(motorPtrs, 3);

    if (freeIndex != -1)
    {
        printf("First free motor index: %d\n", freeIndex);
    }
    else
    {
        printf("No free motors found.\n");
    }

    return 0;
}
