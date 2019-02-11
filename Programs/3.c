/**********************************************************************
* FILENAME:        3.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int main()
{
	int fd1,fd2,offset;
	char *buf[100];
	fd1=open("source.txt",O_RDONLY);
	if(fd1==-1){
		printf("Unable to open!! Input File\n");
		return 0;
	}
	fd2 = dup(fd1);    
	read(fd1, &buf, 100);     //R1 
	read(fd2, &buf, 10);      //R2
	read(fd1, &buf, 10); 	  //R3
	offset=lseek(fd1,0,SEEK_CUR);
	printf("%d\n",offset);     
	read(fd2, &buf, 100);     //R4
	close(fd1);
	close(fd2);
	return 0;
}	

//120 is the offset value in between R3 and R4