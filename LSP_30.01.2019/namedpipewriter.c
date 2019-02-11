# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

main()
{
	int fdwrite;
	char writebuffer[100];
	mkfifo("fifo",0660);
	fdwrite=open("fifo",O_WRONLY);
	while(1)
	{
		fgets(writebuffer,100,stdin);
		write(fdwrite,writebuffer,sizeof(writebuffer));
	}
	close(fdwrite);
}
