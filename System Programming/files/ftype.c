#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// usage : ./a.out hello.txt

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "usage : %s FILE\n", *argv);
		return -1;
	}

	--argc, ++argv;

	struct stat sb = {0,};
	if(lstat(*argv, &sb) == -1) {
		perror("lstat");
		return -1;
	}

	// Extract type and permission of file.
	char perm[11] = "----------";
	// 1 + 3 + 3 + 3 + 1(ASCII NULL) = 10

	switch(sb.st_mode & S_IFMT) {
		case S_IFBLK: perm[0] = 'b'; break;
		case S_IFCHR : perm[0] = 'c'; break;
		case S_IFDIR : perm[0] = 'd'; break;
		case S_IFIFO : perm[0] = 'p'; break;
		case S_IFLNK : perm[0] = 'l';break;
		case S_IFREG : perm[0] = '-';break;
		case S_IFSOCK : perm[0] = 's';; break;
		default : perm[0] = ' '; break;
	}

// 	perm[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
// 	perm[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
// 	perm[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
// 	perm[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
// 	perm[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
// 	perm[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
// 	perm[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
// 	perm[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
// 	perm[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';

	char rwx[] = "rwx";
	for(int i = 0; i< 9; i++) {
		if((sb.st_mode >> (8-i)) & 0x1)
			perm[i+1] = rwx[i % 3];
	}


	long nlink = sb.st_nlink;

	printf("%s %ld %ud %ud %s\n", perm, nlink, sb.st_uid, sb.st_gid, *argv);
	return 0;
}
