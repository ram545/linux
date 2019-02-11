# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <error.h>
# include <errno.h>	
# include <string.h>

main()

{
	int fdread,fdwrite,bytesread;
	char rdbuf[BUFSIZ];	
	fdread=open("source.txt",O_RDONLY);
	if(fdread==-1)
	{
		printf("%d\n",errno);
		perror("Unable to open the file to read:");
	}
	fdwrite=open("destination.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);		
	if(fdwrite==-1)
	{
		perror("Unable to open the write file:");
	}
	while((bytesread=read(fdread,&rdbuf,10))>0)
	{
		printf("%s",rdbuf);
		write(fdwrite,&rdbuf,bytesread);
		getchar();
	}
	close(fdread);
	close(fdwrite);
}

