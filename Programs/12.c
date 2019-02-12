/**********************************************************************
* FILENAME:        12.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>


main()
{
	pid_t pid,pid1;
	char writebuffer[10],readmessage[10],readmessage1[10];
	int fdread,fdwrite,fdread1;
	pid=fork();
	if(pid==0)
	{
		fdread=open("fifo",O_RDONLY);
		read(fdread,readmessage,sizeof(readmessage));
		printf("%s\n",readmessage);
		close(fdread);
	}
	if(pid!=0&&pid!=-1)
	{
		pid1=fork();
		if(pid1==0){
			fdread1=open("fifo",O_RDONLY);
			read(fdread1,readmessage1,sizeof(readmessage1));
			printf("%s\n",readmessage1);
			close(fdread1);
		}
		if(pid1!=0 && pid1!=-1){
			mkfifo("fifo",0660);
			fdwrite=open("fifo",O_WRONLY);
			fgets(writebuffer,10,stdin);
			write(fdwrite,writebuffer,sizeof(writebuffer));
			close(fdwrite);
			waitpid(pid);
			waitpid(pid1);
		}
	}
}


// two processes can't read the same pipe simultaneously , they can only do it one after the other