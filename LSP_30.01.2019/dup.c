# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
main()

{
	int fd1,fd2;
	char *buf[20];
	fd1=open("source.txt",O_RDONLY);
	fd2=dup(fd1);
	printf("The original file descriptor is %d and the duplicate is %d",fd1,fd2);
	getchar();
	read(fd1,&buf,10);
	getchar();
	read(fd2,&buf,10);
	getchar();
}	

