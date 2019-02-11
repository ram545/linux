# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
main()

{
	int fd1,fd2;
	char *buf[20];
	fd1=open("source.txt",O_WRONLY);
	getchar();
	fd2=dup2(fd1,STDOUT_FILENO);
	getchar();
	printf("The original file descriptor is %d and the duplicate is %d",fd1,fd2);

}	

