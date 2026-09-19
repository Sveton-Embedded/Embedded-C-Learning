#include <stdio.h>
#include <stdbool.h>

static inline bool isEven(int number)
{
    return (number % 2) == 0;
}

int main(void)
{
    for (int i =1 ; i <= 5; i++)
    {
        printf("%d is even: %s\n", i, isEven(i) ? "yes" : "no");
    }

    return 0;
}