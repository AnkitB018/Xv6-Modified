#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int pid = getpid();

  printf("Pid of the process is %d\n", pid);

  printf("Size of process: %d Bytes\n", getvasize(pid));

  char *p = sbrk(1024);

  printf("Address returned by sbrk: 0x%lx\n", (uint64)p);
  printf("Size of process: %d Bytes\n", getvasize(pid));

  exit(0);
}
