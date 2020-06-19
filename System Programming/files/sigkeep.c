#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int signo) {
	printf("SIGINT!\n");

	if(signal(SIGINT, SIG_DFL) == SIG_ERR) {
		perror("signal");
}

int main() {
	if(signal(SIGINT, SIG_IGN) == SIG_ERR) {
		perror("signal");
		return -1;
	}

	while(1)
		;
	return 0;
}
