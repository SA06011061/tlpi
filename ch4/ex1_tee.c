#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include "../common/tlpi_hdr.h"

#define SIZE 65535
int main(int argc, char *argv[]){
	int fd;
	size_t len;
	char buf[SIZE];
	char *pathname;
	int bFlag = 0;
	ssize_t wNum;
	char *ret;

	// determine number of parameters
	if(argc < 2 || argc > 3){
		usageErr("%s file | -a file.\n", argv[0]);
	}

	if(argc == 2)
		pathname = argv[1];
	else{
		if(strcmp(argv[1], "-a") != 0){
			errExit("parameter error!");
		}
		pathname = argv[2];
		bFlag = 1;
	}

	if(bFlag == 1){
		fd = open(pathname, O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);	
	}else{
		fd = open(pathname, O_CREAT | O_RDWR , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	}
	if(fd == -1){
		errExit("open");
	}

	ret = fgets(buf, SIZE, stdin);
	len = strlen(ret);

	wNum = write(fd, ret, len);
	if(wNum == -1){
		errExit("write");
	}

	if(close(fd) == -1){
		errExit("close");
	}

	printf("you input is: \n");
	printf("%s\n", buf);
}