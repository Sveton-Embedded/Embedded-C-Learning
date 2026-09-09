#include <stdio.h>
#include <stdlib.h>

int* getHeapArray(void)
{
    int *arr = malloc(5 * sizeof(int));

    if (arr == NULL) 
    {
        printf("Malloc failed!\n");
        return NULL;
    }

    return arr;   
}

int main(void)
{


    int stackBuffer[100];

    int *arr = getHeapArray();

    if (arr == NULL) 
    {
        return 1;   
    }

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 10;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}