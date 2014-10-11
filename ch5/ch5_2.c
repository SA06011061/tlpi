#include <stdio.h>
#include <fcntl.h>
#include "../common/tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd;
	off_t position;

	fd = open("./test4ch5_2.txt", O_APPEND | O_WRONLY);
	if(fd == -1)
		errExit("open");

	position = lseek(fd, 0, SEEK_SET);
	if(position == -1)
		errExit("seek");

	if(write(fd, "qwer1234", 8) != 8)
		errExit("write");

	if(close(fd) == -1)
		errExit("close");

	exit(EXIT_SUCCESS);
}