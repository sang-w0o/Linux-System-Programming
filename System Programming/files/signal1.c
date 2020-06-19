#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void SIGALRM_handler(int signo) {
	printf("SIGALRM!\n");
	alarm(1);
}

void SIGINT_handler(int signo) {
	printf("SIGINT!\n");
}

int main() {
	
	if(signal(SIGALRM, SIGALRM_handler) == SIG_ERR) {
		perror("signal");
		alarm(1);
	}

	if(signal(SIGINT, SIGINT_handler) == SIG_ERR) {
		perror("signal");
		return -1;
	}

	alarm(1);

	while(1);

	return 0;
}
