#include<kernel/types.h>
#include<user/user.h>
#include<kernel/fcntl.h>

#define max_size 100

void rev_read(int fd){
  char buf[max_size];
  int n;
  char temp[1];
  int i=0;
  while( (n = read(fd, &temp, 1) ) > 0){
    buf[i] = temp[0];
    buf[i+1] = '\0';
    i++;
    if(temp[0] == '\n'){
      rev_read(fd);     
      break;
    }

  } 
  
  if(n < 0){
    fprintf(2, "Error reading file\n");
    exit(1);
  }

   write(1, buf, sizeof(buf));

}

int main(int argc, char* argv[]){
  if(argc == 1){
    fprintf(2, "insufficient arguments provided!\n");
    exit(1);
  }

  int fd = open(argv[1], O_RDONLY);
  if(fd < 0){
    fprintf(2, "Failed to open file");
    exit(1);
  }

  rev_read(fd);


  exit(0);
}
