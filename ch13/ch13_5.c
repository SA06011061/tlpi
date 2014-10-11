#include <fcntl.h>
#include "../common/tlpi_hdr.h"

#define BUF_SIZE 65536

int main(int argc, char *argv[]){
	int fd;
	ssize_t nNum;
	int delit;
	char buf[BUF_SIZE];
	char *pPos;	
	//int i;

	int iNum = 0;
	int xxx;

	if(!(argc == 2 || argc == 4) || strcmp(argv[0], "--help") == 0)
		usageErr("%s [-n num] file\n", argv[0]);

	if(argc == 2){
		fd = open(argv[1], O_RDONLY);
		if(fd == -1)
			errExit("open");
	}else{
		fd = open(argv[3], O_RDONLY);
		if(fd == -1)
			errExit("open");

		iNum = getInt(argv[2], GN_ANY_BASE, argv[2]);
		//printf("%d\n", iNum);
	}

	nNum = read(fd, buf, BUF_SIZE);
	if(nNum == -1)
		errExit("read");

	pPos = buf;
	while(*pPos != '\0'){
		pPos++;
	}

	//printf("%s\n", pPos - 5);
	xxx = iNum;
	
		while(pPos != buf){
			if(*pPos == '\n'){
				//printf("true\n");
				iNum--;		
				if(iNum == 0)
					break;		
			}
			pPos--;
		}
	


	if(xxx != 0){
		printf("last num line: %s\n", pPos);
	}else{
		printf("last num line: %s\n", buf);
	}

	exit(EXIT_SUCCESS);
}