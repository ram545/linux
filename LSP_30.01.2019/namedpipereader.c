# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

main()

{
	int fdread;
	char readmessage[100];
	fdread=open("fifo",O_RDONLY);
	while(1)
	{
		read(fdread,readmessage,sizeof(readmessage));
		printf("%s\n",readmessage);
	}
	close(fdread);
}	
