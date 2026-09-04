#include <stdio.h>
#define MAX_RECORDS 5


float calculateAverage(const float temperatures[], int count)
{
    float sum = 0.0f;

    if (count <= 0) 
    {
        return 0.0f; 
    }

    for(int i = 0 ; i < count ; i++)
    {
        sum += temperatures[i];
    }

    return sum / count;

}

void printTemperatures(const float temperatures[] , int count)
{
    printf("\n=== TEMPERATURE RECORDS ===\n");

    for(int i = 0 ; i < count ; i++)
    {
        printf("%d Temperature : %.1f C\n", i + 1 , temperatures[i]);
    }

    float AT = calculateAverage(temperatures , count);
    printf("\nAverage Tempareture : %.1f C\n", AT);

    printf("\n---------------\n");

}

int main(void)
{
    float temperatures [MAX_RECORDS];
    for(int i = 0 ; i < MAX_RECORDS ; i++)
    {
        printf("Temperature :%d", i+1);
        if (scanf("%f", &temperatures[i]) != 1)
        {
            printf("Invalid input!\n");
        }
    }

    printTemperatures(temperatures , MAX_RECORDS);

    return 0;

}
