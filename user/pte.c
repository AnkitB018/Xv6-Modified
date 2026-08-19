#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int x = 10;
  uint64 valid_va = (uint64)&x;
  uint64 invalid_va = 0x100000000ULL;
  
  printf("valid address: %d\n", pte_valid(valid_va));
  printf("invalid address: %d\n", pte_valid(invalid_va));

  exit(0);
}
