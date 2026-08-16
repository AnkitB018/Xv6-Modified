#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  printf("Testing syscalls...\n");

  // These generate some syscall invocations.
  getpid();
  getpid();
  get_child_count();

  printf("\nCurrent process:\n");
  print_syscalls();

  int pid = fork();

  if(pid == 0){
    getpid();

    printf("\nChild process:\n");
    print_syscalls();

    exit(0);
  }

  wait(0);

  printf("\nParent checking child:\n");
  print_process_syscalls(pid);

  exit(0);
}
