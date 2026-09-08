#include <stdio.h>
#include <stdlib.h>


int* getStackPointer(void)
{
    int *arr = malloc(5 * sizeof(int));

    if (arr == NULL) 
    {
        printf("Malloc failed!\n");
        return NULL;
    }

    *arr = 42;
    return arr;
}

int main(void)
{

int *arr = getStackPointer();

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

}