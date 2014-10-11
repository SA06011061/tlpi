#include "../common/tlpi_hdr.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	printf("if i had more time, \n" );
	write(STDOUT_FILENO, "i would have written you a shorter letter.\n", 43);

	exit(EXIT_SUCCESS);
}