#include <stdio.h>

extern int shared_var;

int main(void)
{
    printf("shared_var = %d\n", shared_var);

    shared_var = 20;
    printf("shared_var after change = %d\n", shared_var);

    return 0;
}