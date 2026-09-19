#include <stdio.h>

void assertionFailed(const char *file, int line)
{
    printf("MY_ASSERT failed at %s:%d\n", file, line);
}

#define MY_ASSERT(condition) \
    if (!(condition)) \
    { \
        assertionFailed(__FILE__, __LINE__); \
        while(1) {} \
    }

void testFunction(int value)
{
    MY_ASSERT(value > 0);
    printf("Value is: %d\n", value);   
}

int main(void)
{
    testFunction(-5);
    printf("This will never print\n");   

    return 0;
}