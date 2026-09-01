#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int pid = getpid();

  printf("Initial mapped pages: %d\n", get_page_count(pid));

  char *p = sbrk(4096);

  printf("After sbrk: %d\n", get_page_count(pid));

  p[0] = 'A';

  printf("After touching page: %d\n", get_page_count(pid));

  char *q = sbrk(4096);
  q[0] = 'B';

  printf("After touching second page: %d\n", get_page_count(pid));

  exit(0);
}
