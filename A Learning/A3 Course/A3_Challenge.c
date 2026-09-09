#include <stdio.h>
#include <stdlib.h>


int* getDanglingPointer(void)
{
    int danglingValue = 42;
    return &danglingValue;   
}


int* getStaticPointer(void)
{
    static int staticValue = 42;
    return &staticValue;
}

int* getHeapArray(void)
{
    int *arr = malloc(sizeof(int));

    if (arr == NULL)
    {
        printf("Malloc failed!\n");
        return NULL;
    }

    return arr;
}


void getValueViaOutParam(int *out)
{
    *out = 42;
}


int main(void)
{
    
    int *ptr1 = getDanglingPointer();
    printf("Variant 1 (dangling): %d\n", *ptr1);   // опасно! undefined behavior

    
    int *ptr2 = getStaticPointer();
    printf("Variant 2 (static): %d\n", *ptr2);

    
    int *ptr3 = getHeapArray();
    if (ptr3 != NULL)
    {
        *ptr3 = 42;
        printf("Variant 3 (malloc): %d\n", *ptr3);
        free(ptr3);
        ptr3 = NULL;
    }

    
    int value4;
    getValueViaOutParam(&value4);
    printf("Variant 4 (out-param): %d\n", value4);


    return 0;
}