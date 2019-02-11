# include <unistd.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
main()

{
	struct stat buf;
	int fd;
	fd=open("source.txt",O_RDONLY);
	/*stat("source.txt",&buf);*/
	fstat(fd,&buf);
	printf("inode no=%d\t mode=%o\t blocks=%d\n",buf.st_ino,buf.st_mode,buf.st_blocks);
}
