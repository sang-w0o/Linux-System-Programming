#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void showMask() {
	sigset_t curMask;
	if(sigprocmask(0, NULL, &curMask) == -1) {
		perror("sigprocmask");
		return;
	}

	printf("====Blocked signal list====\n");

	if(sigismember(&curMask, SIGINT)) printf("SIGINT\n");
	if(sigismember(&curMask, SIGQUIT)) printf("SIGQUIT\n");
	if(sigismember(&curMask, SIGALRM)) printf("SIGALRM\n");
}

// 1. Block signal and un-block it.

int main() {

	sigset_t newMask;
	if(sigemptyset(&newMask) == -1) {
		perror("sigemptyset");
		return -1;
	}

	// set signal to block
	if(sigaddset(&newMask, SIGINT) == -1) {
		perror("sigaddset");
		return -1;
	}
	
	// register signal to block
	sigset_t oldMask;  // oldSet for backup.
	if(sigprocmask(SIG_BLOCK, &newMask, &oldMask) == -1) {
		perror("sigprocmask");
		return -1;
	}

	// Check the signal set.
	showMask();
	getchar();


	// un-block signals
	if(sigprocmask(SIG_SETMASK, &oldMask, NULL) == -1) {
		perror("sigprocmask");
		return -1;
	}

	showMask();
	return 0;
}
