#include <stdio.h>
#include <stdlib.h>


int* getHeapPointer(void)
{
    int *heapValue = malloc(sizeof(int));

    if (heapValue == NULL) {
        printf("Malloc failed!\n");
        return NULL;
    }

    *heapValue = 42;
    return heapValue;
}

int main(void)
{
int *ptr = getHeapPointer();
printf("Heap value: %d\n", *ptr);

free(ptr);  
}





