#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Write the content to FILENAME
// which user input from stdin.

// usage : ./a.out FILENAME

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}

	--argc, ++argv;

	int fd = open(*argv, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if(fd < 0) {
		perror("open");
		return -1;
	}


	char buf[4096];
	while(1) {
		int nRead = read(0, buf, sizeof(buf));
		if(nRead < 0) {
			perror("read");
			return -1;
		}
		// Met EOF.
		else if (nRead == 0) {
			break;
		}
		else {
			write(fd, buf, nRead);
		}
	}
	close(fd);
	return 0;
}

