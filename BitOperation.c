#include <stdio.h>

int main (void)
{
  unsigned char gpio = 0;

  gpio |= (1 << 1);
  gpio |= (1 << 5);

  gpio ^= (1 << 1);

  if(gpio & (1 << 5))

  printf("%u\n", gpio);

  return 0;
}