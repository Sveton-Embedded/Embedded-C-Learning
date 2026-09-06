#include <stdio.h>

int* getStaticPointer(void)
{
    static int staticValue = 42;
    return &staticValue;
}

int main(void)
{
    int *ptr = getStaticPointer();
    printf("Value: %d\n", *ptr);

    *ptr = 100;
    printf("Value after change: %d\n", *(getStaticPointer()));

    return 0;
}