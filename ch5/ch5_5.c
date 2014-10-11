#include <fcntl.h>
#include <unistd.h> 
#include "../common/tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd1, fd2;
	off_t pos1, pos2;
	int flg1, flg2;

	fd1 = open("f1", O_RDWR);
	if(fd1 == -1)
		errExit("open fd1");
	fd2 = dup(fd1);
	if(fd2 == -1)
		errExit("open fd2");

	pos1 = lseek(fd1, 3, SEEK_SET);
	pos2 = lseek(fd2, 0, SEEK_CUR);

	flg1 = fcntl(fd1, F_GETFL);
	flg2 = fcntl(fd2, F_GETFL);
	printf("pos1: %ld, pos2: %ld\n", pos1, pos2);
	printf("fd1 flg: %d, fd2 flg: %d\n", flg1, flg2);
}