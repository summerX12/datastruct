#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

union
{
  struct
  {
    uint16_t i;
    uint16_t j;
  }x;
  uint32_t y;
}a;

int main()
{
  a.y = 0x11223344;

  printf("%x\n",a.x.i+a.x.j);

}
