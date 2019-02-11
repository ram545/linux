/**********************************************************************
* FILENAME:        2.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int main()
{
	int fd1,fd2;
	char *buf[20];
	fd1=open("source.txt",O_RDONLY);
	if(fd1==-1){
		printf("Unable to open!! Input File\n");
		return 0;
	}
	fd2=dup2(fd1,STDIN_FILENO);
	scanf("%s",buf);
	printf("The input read is :: %s\n",buf);
	close(fd1);
	close(fd2);
	return 0;
}	


/* Observation : It reads input from source.txt instead of taking it from the standard input console*/

