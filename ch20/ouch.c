#include <signal.h>
#include "../common/tlpi_hdr.h"

static void sigHandler(int sig){
	printf("ouch\n");
}

int main(int argc, char *argv[]){
	int j;

	if(signal(SIGINT, sigHandler) == SIG_ERR)
		errExit("signal");

	for(j = 0; ; j++){
		printf("%d\n", j);
		sleep(3);
	}
}