#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int listDir(const char *dname) {
	if (dname == NULL || strlen(dname) == 0) {
		fprintf(stderr, "listDir: argument is wrong\n");
		return -1;
	}

	if (chdir(dname) == -1) {
		perror("chdir");
		return -1;
	}

	char curPath[256];
	if (getcwd(curPath, sizeof(curPath)) == NULL) {
		perror("getcwd");
		return -1;
	}
	printf("\n%s:\n", curPath);

	DIR *dir = opendir(".");
	if (dir == NULL) {				 	
		perror("opendir");		
		return -1;								
	}											

	while (1) {
		errno = 0;
		struct dirent *p = readdir(dir);	
		if (p == NULL) {	// EOF or ERROR
			if (errno != 0) {
				perror("readdir");
				return -1;
			}
			break;
		}
		if(strcmp(p->d_name, ".") && strcmp(p->d_name, ".."))
			printf("%s\n", p->d_name);
	}

	// Travel child-directory.
	rewinddir(dir);
	while(1) {
		struct dirent *p = readdir(dir);
		if(p == NULL) {
			if(errno != 0) {
				perror("readdir");
				return -1;
			}
			break;
		}

		if(p->d_type == DT_DIR) {
			// Check . , .. to avoid infinite loop.
			if(strcmp(p->d_name, ".") && strcmp(p->d_name, "..")) {
				if(listDir(p->d_name) == -1)
					exit(1);
			}
		}
	}

	if (closedir(dir) == -1) {		
		perror("closedir");
		return -1;
	}

	if (chdir("..") == -1) {
		perror("chdir");
		exit(1);
	}
	return 0;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s DIRECTORY\n", *argv);
		return -1;
	}
	--argc, ++argv;
	listDir(*argv);
	return 0;
}
