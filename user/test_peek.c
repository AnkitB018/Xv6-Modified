#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(void)
{
  char buf[20];
  int fd = open("sample.txt", O_RDONLY);

  if(fd < 0){
    printf("failed to open test.txt\n");
    exit(1);
  }

  printf("inode: %d, offset: %d\n",
         get_inode_num(fd), get_read_offset(fd));

  int n = filepeek(fd, buf, 5);
  if(n < 0){
    printf("peek failed\n");
    exit(1);
  }

  buf[n] = '\0';
  printf("peek: %s\n", buf);

  printf("after peek - inode: %d, offset: %d\n",
         get_inode_num(fd), get_read_offset(fd));

  n = filepeek(fd, buf, 5);
  buf[n] = '\0';
  printf("peek again: %s\n", buf);

  printf("after second peek - offset: %d\n",
         get_read_offset(fd));

  n = read(fd, buf, 2);
  buf[n] = '\0';
  printf("read: %s\n", buf);

  printf("after read - inode: %d, offset: %d\n",
         get_inode_num(fd), get_read_offset(fd));

  n = filepeek(fd, buf, 3);
  buf[n] = '\0';
  printf("peek after read: %s\n", buf);

  printf("final offset: %d\n", get_read_offset(fd));

  close(fd);
  exit(0);
}
