#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"


#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
	if(argc <= 2){
		fprintf(2, "Invalid arguments, usage: cp <source_file> <destination_file>\n");
		exit(1);	
	}

	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		fprintf(2, "Unable to open file: %s\n", argv[1]);
		exit(1);
	}

	int fd_w = open(argv[2], O_WRONLY | O_TRUNC | O_CREATE);

	if(fd_w < 0){
		fprintf(2, "unable to open file: %s\n", argv[2]);
		exit(1);
	}

	char buffer[BUFFER_SIZE];

	
	int bytes_read = 0;
	
	
	while((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0){
		write(fd_w, buffer, bytes_read);			
	}


	close(fd);
	close(fd_w);

	exit(1);
}

