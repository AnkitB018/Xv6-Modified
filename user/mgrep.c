#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(int argc, char *argv[]){
	if(argc <= 2){
		fprintf(2, "Invalid arguments, usage: mgrep <pattern> <file_1> <file_2> ...\n");
		exit(1);
	}	

	char *pattern = argv[1];
	
	for(int i=2 ; i<argc ; i++){
		int pid = fork();
		if(pid < 0){
			fprintf(2, "Error: Failed to fork \n");
			exit(1);
		}

		
		char *arg[] = {"grep", pattern, argv[i], 0};
		if(pid == 0){
			printf("\n");
			printf("child PID:%d - matching pattern in file: %s \n\n", getpid(), argv[i]);
			exec("grep", &arg[0]);

			fprintf(2, "Failed to call grep on file: %s\n", argv[i]);
			exit(1);
		}else{
			int status;
			wait(&status);
		}
	}
	


	exit(0);
}
