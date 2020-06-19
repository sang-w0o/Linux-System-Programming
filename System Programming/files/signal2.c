#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void SIG_handler(int signo) {
	switch(signo) {
		case SIGALRM: 
			printf("SIGALRM!\n");
			alarm(1);
			break;
		case SIGINT:
			printf("SIGINT!\n");
			break;
	}
}

int main() {
	
	if(signal(SIGALRM, SIG_handler) == SIG_ERR) {
		perror("signal");
		alarm(1);
	}

	if(signal(SIGINT, SIG_handler) == SIG_ERR) {
		perror("signal");
		return -1;
	}

	alarm(1);

	while(1);

	return 0;
}
