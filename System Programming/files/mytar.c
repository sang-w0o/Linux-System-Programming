#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long getFileSize(FILE *fp) {
	if(fp == NULL) {
		fprintf(stderr, "getFileSize : argument is NULL.\n");
		return -1;
	}

	long oldPos = ftell(fp);
	if(oldPos == -1){
		perror("ftell");
		return -1;
	}

	if(fseek(fp, 0, SEEK_END) == -1) {
		perror("fseek");
		return -1;
	}

	long fsize = ftell(fp);
	if(fsize == -1) {
		perror("ftell");
		return -1;
	}

	if(fseek(fp, oldPos, SEEK_SET) == -1) {
		perror("fseek");
		return -1;
	}

	return fsize;
}

typedef struct File {
	char name[32];
	long size;
}File;

// usage ex) ./mytar hello.txt result.mytar

int main(int argc, char **argv) {

	if(argc < 3) {
		fprintf(stderr, "usage : %s FILE1 [FILE2...] TARGET.mytar\n", *argv);
		return -1;
	}

	--argc, ++argv;

	FILE *target = fopen(argv[argc-1], "w");
	if(target == NULL) {
		perror("fopen");
		return -1;
	}

	for(int i = 0; i < (argc -1); i++) {
		FILE *srcFile = fopen(argv[i], "r");
		if(srcFile == NULL) {
			perror("fopen");
			return -1;
		}

		File file = {0,};
		strcpy(file.name, argv[i]);
		file.size = getFileSize(srcFile);

		size_t nWritten = fwrite(&file, 1, sizeof(File), target);
		if(nWritten != sizeof(File)) {
			perror("fwrite");
			return -1;
		}
		
		char buf[4096];
	
		while(1) {
			size_t nRead = fread(buf, 1, sizeof(buf), srcFile);
			if(nRead) {
				nWritten = fwrite(buf, 1,nRead, target);
				if(nWritten != nRead) {
					perror("fwrite");
					return -1;
				}
			}
			else {
				if(ferror(srcFile)){	
					perror("fread");
					return -1;
				} else if (feof(srcFile)) {
					break;
				}
			}
		}

		fclose(srcFile);
	}
	fclose(target);
	return 0;
}
