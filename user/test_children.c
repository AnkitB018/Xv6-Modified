#include<kernel/types.h>
#include<user/user.h>

int main(){
	int pid = fork();
	
	if(pid < 0){
		fprintf(2, "Failed to fork\n");
		exit(1);
	}

	if(pid == 0){
		//do nothing
	}else{
		int child = get_child_count();
		int cc = get_process_child_count(pid);
		
		printf("number of child of process: %d\n", child);
		printf("number of child of child with PID: %d -> %d\n", pid, cc);
		int status;	
		wait(&status);
	}

	exit(0);


}
