#define  _FILE_OFFSET_BITS 64

#include <sys/stat.h>
#include <fcntl.h>
#include "../common/tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd;
	off_t off;
	
	if(argc != 3 || strcmp(argv[1], "--help") == 0){
		usageErr("%s pathname offset\n", argv[0]);
	}

	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1){
		errExit("open");
	}

	off = atoll(argv[2]);
	if(lseek(fd, off, SEEK_SET) == -1)
		errExit("seek");

	if(write(fd, "test", 4) == -1)
		errExit("write");

	if(close(fd) == -1)
		errExit("close");

	exit(EXIT_SUCCESS);
}