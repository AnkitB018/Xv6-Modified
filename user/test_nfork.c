#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int pids[3];

  printf("[parent] pid: %d\n", getpid());

  int ret = nfork(3, pids);

  if(ret == 0){
    exit(0);
  }

  printf("[parent] nfork returned: %d\n", ret);
  printf("[parent] child count: %d\n", get_child_count());

  for(int i = 0; i < 3; i++)
    printf("[parent] child pid: %d\n", pids[i]);

  for(int i = 0; i < 3; i++)
    wait(0);

  printf("[parent] child count after reap: %d\n", get_child_count());

  exit(0);
}
