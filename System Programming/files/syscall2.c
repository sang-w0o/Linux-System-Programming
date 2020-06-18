#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Print contenf of the file to stdout.

// usage : ./a.out hello.txt

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}

	--argc, ++argv;

// 	FILE *fp = fopen(*argv, "r");
// 	if(fp == NULL) {
// 		perror("fopen");
// 		return -1;
// 	}
	
// change the code above using syscall function.

	int fd = open(*argv, O_RDONLY);
	if(fd < 0) {
		perror("open");
		return -1;
	}

	// print content to stdout.

	char buf[4096];
	while(1) {
		int nRead = read(fd, buf, sizeof(buf));
		if(nRead < 0) {
			perror("read");
			return -1;
		}
		// Met EOF.
		else if (nRead == 0) {
			break;
		}
		else {
			write(1, buf, nRead);
		}
	}
	close(fd);
	return 0;
}

