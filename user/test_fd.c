#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(void)
{
  int fd = open("sample.txt", O_RDONLY);

  if(fd < 0){
    printf("failed to open test.txt\n");
    exit(1);
  }

  printf("[parent] fd=%d, inode=%d, offset=%d\n",
         fd, get_inode_num(fd), get_read_offset(fd));

  printf("[parent] forking a child...\n");

  int pid = fork();

  if(pid < 0){
    printf("fork failed\n");
    exit(1);
  }

  if(pid == 0){
    printf("[child] fd=%d, inode=%d, offset=%d\n",
           fd, get_inode_num(fd), get_read_offset(fd));

    printf("[child] reading 5 bytes from fd=%d\n", fd);

    char buf[5];
    read(fd, buf, 5);

    printf("[child] fd=%d, inode=%d, offset=%d\n",
           fd, get_inode_num(fd), get_read_offset(fd));

    exit(0);
  }

  wait(0);

  printf("[parent] reaping child...\n");
  printf("[parent] fd=%d, inode=%d, offset=%d\n",
         fd, get_inode_num(fd), get_read_offset(fd));

  close(fd);
  exit(0);
}
