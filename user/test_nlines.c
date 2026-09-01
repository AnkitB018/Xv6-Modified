#include<kernel/types.h>
#include<kernel/fcntl.h>
#include<user/user.h>

int main(){
  int fd = open("sample.txt", O_RDONLY);
  if(fd < 0){
    fprintf(2, "failed to open file\n");
    exit(1);
  }
 
  printf("Got file inode number: %d\n", get_inode_num(fd)); 
  printf("current read offset before getting number of lines: %d\n", get_read_offset(fd));

  printf("number of lines: %d\n", file_nlines(fd));

  printf("current read offset after getting number of lines: %d\n", get_read_offset(fd));

  close(fd);

  exit(0);

}
