#include <fcntl.h>
#include "../common/tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd;
	int bFlg = 0;
	int numbytes;
	int i = 0;
	//char r = 'c';

	if((argc != 3 && argc != 4) || strcmp(argv[1], "--help") == 0)
		usageErr("%s filename num-bytes [x]\n", argv[0]);

	numbytes = getInt(argv[2], GN_ANY_BASE, argv[2]);
	printf("len = %d \n", numbytes);

	if(argc == 4){		
		bFlg = 1;
	}

	if(bFlg)
		fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	else
		fd = open(argv[1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(fd == -1)
		errExit("open");

	while (i < numbytes){
		if(bFlg){
			if(lseek(fd, 0, SEEK_END) == -1)
				errExit("seek");
		}
		if(write(fd, "r", 1) != 1)
			errExit("write bflg == true\n");

		i++;
	}

	if(close(fd) == -1)
		errExit("close");

	exit(EXIT_SUCCESS);
}