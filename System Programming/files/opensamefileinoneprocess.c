#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILE\n", *argv);
		return -1;
	}

	--argc, ++argv;

	int fd1 = open(*argv, O_RDONLY);
	if(fd1 < 0){
		perror("open");
		return -1;
	}

	int fd2 = open(*argv, O_RDONLY);
	if(fd2 < 0){
		perror("open");
		return -1;
	}

	char buf1[32] = {0,};
	char buf2[32] = {0,};

	// Read 5 bytes from each file descriptors.
	// Skipped error-checking to simplify code.
	read(fd1, buf1, 5);
	read(fd2, buf2, 5);


	printf("%s\n", buf1);
	printf("%s\n", buf2);
	
	// The print results above are same.
	// This means that when the same file is opened in a same process,
	// File Stucture is created seperately every time open() is called.
	close(fd1);
	close(fd2);
	return 0;

}	
