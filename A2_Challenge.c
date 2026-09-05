#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t u_counter = 255;
    u_counter++;
    printf("uint8_t: 255 + 1 = %u (predictable, defined by standard)\n", u_counter);

    int8_t s_counter = 127;
    s_counter++;
    printf("int8_t: 127 + 1 = %d (undefined behavior, may vary)\n", s_counter);

    return 0;
}


