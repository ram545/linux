/**********************************************************************
* FILENAME:        13.c

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
	char writebuffer[10]="Thisistry",writebuffer[10]="Thisistry",readmessage[10];
	int fdread,fdwrite,fdwrite1;
	mkfifo("fifo",0660);
	pid=fork();
	if(pid==0)
	{
		fdwrite1=open("fifo",O_WRONLY);
		fgets(writebuffer1,10,stdin);
		write(fdwrite1,writebuffer1,sizeof(writebuffer1));
		close(fdwrite1);
	}
	if(pid!=0&&pid!=-1)
	{
		pid1=fork();
		if(pid1==0){
			fdwrite=open("fifo",O_WRONLY);
			fgets(writebuffer,10,stdin);
			write(fdwrite,writebuffer,sizeof(writebuffer));
			close(fdwrite);
		}
		if(pid1!=0 && pid1!=-1){
			fdread=open("fifo",O_RDONLY);
			read(fdread,readmessage,sizeof(readmessage));
			printf("%s\n",readmessage);
			close(fdread);
			waitpid(pid);
			waitpid(pid1);
		}
	}
}


// two processes can't read the same pipe simultaneously , they can only do it one after the other