#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int getFileSize(FILE *fp);
int showFileContent(FILE *fp);

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILENAME\n", *argv);
		return -1;
	}
	--argc, ++argv;


	FILE *fp = fopen(*argv, "r");
	if(fp == NULL){
		perror("fopen");
		return -1;
	}

	getFileSize(fp);
	showFileContent(fp);

	fclose(fp);
	return 0;
}

int getFileSize(FILE *fp) {
	
	if(fseek(fp, 0, SEEK_END) == -1) {
		perror("fseek");
		return -1;
	}

	long fsize = ftell(fp);
	if(fsize == -1) {
		perror("ftell");
		return -1;
	}

	printf("FILE SIZE : %ld\n", fsize);
	return 0;
}

int showFileContent(FILE *fp) {

	if(fseek(fp, 0, SEEK_SET) == -1) {
		perror("fseek");
		exit(-1);
	}
	
	while(1){
		char buf[4096];
		int nRead = fread(buf, sizeof(char), 4096, fp);
		if(nRead) {
			usleep(100000);
			fwrite(buf, sizeof(char), nRead, stdout);
			fflush(stdout);
		}
		else
			break;
	}
	return 0;
}
