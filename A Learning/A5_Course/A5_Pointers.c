#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void allocate_buffer(int **out, int size)
{
    *out = malloc(sizeof(int)*size);

    if (*out == NULL)
    {
        printf("Malloc failed!\n");
    }
}

void swap_pointers(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = *temp;

}

int main(void)
{
    int value = 10;
    int *ptr = &value;
    int **ptr2 = &ptr;

    printf("value = %d\n", value);
    printf("*ptr = %d\n", *ptr);
    printf("**ptr2 = %d\n", **ptr2);

    int *arr = NULL;
    allocate_buffer(&arr, 5);

    if(arr != NULL)
    {
        for(int i = 0; i < 5; i++)
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

return 0;
}