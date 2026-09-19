#include <stdio.h>
#include <assert.h>

void testAssert(int value)
{
    assert(value > 0);
    printf("Value is: %d\n", value);
}

int main(void)
{
    testAssert(-5);   

    return 0;
}