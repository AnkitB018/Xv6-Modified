#include <kernel/types.h>
#include <user/user.h>

int main(){
  int pid = fork();

  if(pid < 0){
    printf("failed to create child\n");
    exit(1);
  }

  if(pid == 0){
    for(volatile int i=0 ; i<100000 ; i++){
     //do nothing
    }
    exit(0);
  }

  printf("Parent state: ");
  get_process_state(getpid());
  printf("\nChild state: ");
  get_process_state(pid);
  printf("\n");
  int status;
  wait(&status);

  exit(0);

}
