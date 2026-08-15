#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(int argc, char *argv[]){

	if(argc < 2){
		fprintf(2, "Command not provided!\n");
		exit(1);
	}

	int pid = fork();
	if(pid < 0){
		fprintf(2, "Failed to fork!\n");
		exit(1);
	}

	if(pid == 0){
		exec(argv[1], &argv[1]);	

		fprintf(2, "failed to execute");
		exit(1);
	}else{
		int status;
		wait(&status);

		exit(1);
	}


	exit(0);
	
	
}
