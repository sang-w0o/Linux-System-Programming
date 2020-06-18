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

	// Close the original file descriptor.
	// 0 is still connected to the file *argv.
	close(fd);

	char buf[32] = {0,};
	read(0, buf, 5);
	
	// After dup() was performed, if the original file descriptor is closed,
	// duplicated file descriptor is still using the file sturcture.
	// This is because inode has variable ref, which counts the number of 
	// itself being referenced by others.
	// After open() was called, ref is increased to 1.
	// After dup() was performed, ref is increased to 2.
	// After close(fd) was called, ref is decreased to 1.
	// File stucture is destroyed when ref becomes 0.
	printf("%s\n", buf);

	return 0;
}
