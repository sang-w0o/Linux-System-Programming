#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILE\n", *argv);
		return -1;
	}

	--argc, ++argv;

	// Open file.
	int fd = open(*argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fd < 0) {
		perror("open");
		return -1;
	}

	// Send stdin to fd
	
	printf("hello, world\n");
	  // == fprintf(stdout, "hello, world\n");

	// Close 1, which is stdout.
	close(1);
	
	// Duplicate 1, which is the lowest number availiable 
	//in file description table to fd.
	dup(fd);
	
	// printf uses 1, but in this case it points at fd, which is *argv.
	printf("hello, world\n");

	close(fd);
	return 0;
}
