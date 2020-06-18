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

	// Close keyboard file descriptor.
	close(0);
	
	// Set fd's value to 0, which is the lowest number availiable in
	// file descriptor table.
	dup(fd);
	
	char buf1[32] = {0,};
	read(fd, buf1, 5);

	char buf2[32] = {0,};
	read(0, buf2, 5);

	// For the original file descriptor and duplicated file desciptor,
	// if an operation is performed, results are shown continually.
	// We can know that dup() shares the same file structure.
	printf(" 0 : %s\n", buf2);
	printf(" fd: %s\n", buf1);

	close(fd);
	return 0;
}
