# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
main()
{
	int fd;
	char *buf[11];
	fd=open("source.txt",O_RDONLY);
	getchar();
	read(fd,&buf,10);
	printf("%s\n",buf);
	getchar();
	lseek(fd,-10,SEEK_CUR);
	getchar();
	read(fd,&buf,10);
	printf("%s\n",buf);
	getchar();
	lseek(fd,10,SEEK_SET);
	getchar();
	read(fd,&buf,10);
	printf("%s\n",buf);
	lseek(fd,-10,SEEK_END);
	getchar();
	read(fd,&buf,10);
	printf("%s\n",buf);
	getchar();
}
