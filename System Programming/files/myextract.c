#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct File {
	char name[32];
	long size;
}File;

int main(int argc, char **argv) {

	if(argc != 2) {
		fprintf(stderr, "usage : %s TARGET.mytar\n", *argv);
		return -1;
	}

	--argc, ++argv;

	FILE *tarFile = fopen(*argv, "r");
	if(tarFile == NULL) {
		perror("fopen");
		return -1;
	}

	while(1) {
		// read file information
		File file = {0,};
		
		size_t nRead = fread(&file, 1, sizeof(File), tarFile);
		if(nRead) {
			FILE *fp = fopen(file.name, "w");
			if(fp == NULL) {
				perror("fopen");
				return -1;
			}
			
			char buf[4096];
			while(file.size > 0) {
				size_t bufSize = file.size > sizeof(buf) ? sizeof(buf) : file.size;
				nRead = fread(buf, 1, bufSize, tarFile);
				if(nRead) {
					size_t nWritten = fwrite(buf, 1, nRead, fp);
					if(nWritten != nRead) {
						perror("fwrite");
						return -1;
					}
					file.size -= nRead;
				}
				else {
					if(ferror(fp)) {
						perror("fread");
						return -1;
				} else if(feof(fp)){
					break;
					}	
				}
			}
			fclose(fp);
		}
		else{
			if(ferror(tarFile)) {
				perror("fread");
				return -1;
			}
			else if(feof(tarFile)) {
				break;
			}
		}
	}
	return 0;
}
