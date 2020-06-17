// #include <stdio.h>
// #include <unistd.h>

// send data to stdout which the program got from stdin

// usage : ./a.out 

// int main(int argc, char **argv) {
// 	
// 	char buf[4096];
// 	while(1) {
// 		if (fgets(buf, 4096, stdin)) {
// 			fputf(buf, stdout);
// 		}
// 		else {
// 			if(ferror(stdin)) {
// 				perror("fgets");
// 				return -1;
// 			}
// 			else if(feof(stdin)) {
// 				break;
// 			}
// 		}
// 	}
// 	return 0;
// }

// change code above to code using systemcall

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	
	char buf[4096];
	while(1) {
		ssize_t nRead = read(0, buf, sizeof(buf));
		// You can write STDIN_FILENO instead of 0.
		if(nRead < 0) {
			perror("read");
			return -1;
		}
		else if (nRead == 0) { // Met EOF
			break;
		}
		else {
			ssize_t nWritten = write(1, buf, nRead);
			// You can write STDOUT_FILENO instead of 1.
			if(nWritten < 0) {
				perror("write");
				return -1;
			}
			else if(nWritten != nRead) {
				fprintf(stderr, "write error : %ld / %ld\n", nWritten,  nRead);
				return -1;
			}
		}
	}
	return 0;
}
