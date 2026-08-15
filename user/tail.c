#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"


int main(int argc, char* argv[]){
	if(argc != 3){
		fprintf(2, "usage: tail <file_name> <no of lines>\n");
		exit(1);
	}

	int n = atoi(argv[2]);
	if(n < 0){
		fprintf(2, " Invalid number of lines provided\n");
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY);

	if(fd < 0){
		fprintf(2, "Failed to open file\n");
		exit(1);
	}

	char c;
	int total = 0;

	while(read(fd, &c, 1) > 0){
		if(c == '\n'){
			total++;
		}
	}

	int need = total - n;

	int lines = 0;
	
	close(fd);
	fd = open(argv[1], O_RDONLY);

	if(fd < 0){
		fprintf(2, "Failed to open file\n");
		exit(1);
	}

	while(read(fd, &c, 1) > 0){
		if(lines >= need){
			printf("%c", c);
		}

		if(c == '\n'){
			lines++;
		}
	}

	close(fd);
	exit(0);

}
