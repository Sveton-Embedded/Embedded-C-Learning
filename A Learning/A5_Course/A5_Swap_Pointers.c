#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void swap_pointers(int **x , int **y)
{
    int *temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int x = 5;
    int y = 20;

    int *ptrX = &x;
    int *ptrY = &y;

    printf("Before : ptrX -> %d , ptrY -> %d\n", *ptrX , *ptrY);

    swap_pointers(&ptrX , &ptrY);

    printf("After : ptrX -> %d , ptrY -> %d\n", *ptrX , *ptrY);

    return 0 ;
}