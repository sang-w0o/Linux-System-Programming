#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Implemenet cp command of linux.

// usage : ./a.out SRCFILE NEWFILE

int main(int argc, char **argv) {
	if(argc != 3) {
		fprintf(stderr, "usage : %s SRCFILE NEWFILE\n", *argv);
		return -1;
	}

	--argc, ++argv;

	int src = open(argv[0], O_RDONLY);
	if(src < 0) {
		perror("open");
		return -1;
	}

	int target = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);

	if(target < 0) {
		perror("open");
		return -1;
	}
	
	char buf[BUFSIZ];
	while(1) {
		ssize_t nRead = read(src, buf, sizeof(buf));
		if(nRead < 0) {
			perror("read");
			return -1;
		}
		else if(nRead == 0) {
			break;
		}
		else{
			write(target, buf, nRead);
		}
	}
	close(target);
	close(src);
	return 0;
}

