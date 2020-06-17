#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv ){
	if(argc != 2){
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}
	--argc, ++argv;

	FILE *fp = fopen(*argv, "r");
	if(fp == NULL) {
		perror("fopen");
		return -1;
	}
	while(1) {
	char buf[4096];
		int nRead = fread(buf, sizeof(char), 4096, fp);
		if(nRead){
			usleep(100000);
			fwrite(buf, sizeof(char), nRead, stdout);
			fflush(stdout);
		}
		else {
			break;	
		}
	}
	fclose(fp);
	return 0;
}


