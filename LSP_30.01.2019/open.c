# include <fcntl.h>
# include <stdio.h>

main()

{
	int fd1,fd2,fd3;
	fd1=open("text.txt",O_RDONLY);
	fd2=open("test1.txt",O_WRONLY|O_CREAT,0664);
	fd3=open("text.txt",O_WRONLY);
	printf("The file descriptors are %d & %d & %d",fd1,fd2,fd3);
	getchar();
}
