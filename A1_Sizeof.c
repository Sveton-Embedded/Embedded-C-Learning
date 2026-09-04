#include <stdio.h>

void foo(int arr[])
{
    printf("In Function Foo():\n");
    printf("sizeof(arr) =%zu bait \n\n", sizeof(arr));
}

int main(void)
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    size_t count = sizeof(arr) / sizeof(arr[0]);

    printf("----------IN function Main----------\n");
    printf("sizeof(arr)  = %zu bait\n", sizeof(arr));
    printf("sizeof(arr[0]) = %zu bait\n", sizeof(arr[0]));
    printf("Value elemment in main(): %zu\n", count);
    printf("---------------------------------------\n");

    foo(arr);

    printf("\n-----------Elemment Value-----------\n");
    printf("sizeof(int)  = %zu bait\n", sizeof(int));
    printf("sizeof(char)  = %zu bait\n", sizeof(char));
    printf("sizeof(long)  = %zu bait\n", sizeof(long));
    printf("sizeof(short)  = %zu bait\n", sizeof(short));
    printf("sizeof(double)  = %zu bait\n", sizeof(double));
    printf("sizeof(float)  = %zu bait\n", sizeof(float));
    printf("sizeof(int arr[10])  = %zu bait\n", sizeof(int[10]));

    return 0;
}
