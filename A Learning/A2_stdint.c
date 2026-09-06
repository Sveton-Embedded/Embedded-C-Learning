
#include <stdio.h>
#include <stdint.h>

void setBit(uint32_t *reg, uint8_t pin)
{
    *reg |= (1U << pin);
}




int main(void)
{
    printf("uint8_t = %zu byte(s)\n", sizeof(uint8_t));
    printf("uint16_t = %zu byte(s)\n", sizeof(uint16_t));
    printf("uint32_t = %zu byte(s)\n", sizeof(uint32_t));


    uint32_t fakeRegister = 0;
    setBit(&fakeRegister, 6);   
    printf("Register value: %u\n", fakeRegister);  

    return 0;
}