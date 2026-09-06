#include <stdio.h>

int* getDanglingPointer(void)
{
    int danglingValue = 42;
    return &danglingValue;  
}

int main(void)

{
    int *ptr = getDanglingPointer();
    printf("Dangling value: %d\n", *ptr);   

    
    return 0;
}





