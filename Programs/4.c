/**********************************************************************
* FILENAME:        4.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <error.h>
# include <errno.h>     

int fileCopy(int fin,int fout,int buffSize){
	int bytesRead,bytesWritten,flag=1;
	char *buff=(char)malloc(buffSize*sizeof(char));
	while((bytesRead = read(fin,&buff,buffSize))>0){
        bytesWritten = write(fout,&buff,bytesRead);
		if(fin==0)
			break;
		if(bytesRead!=bytesWritten){
			flag=0;
			break;
		}
    }
	if(flag)
		return 0;
	else 
		return -1;
}


int main(int argc,char** argv){
	int fin=0,fout=1,retVal;
	char *inputfile;
	if(argc>1){
		inputfile=argv[1];
		fin=open(inputfile,O_RDONLY);
		if(fin==-1){
			printf("Unable to Open!! Input File\n");
			return 0;
		}
	}
	retVal=fileCopy(fin,fout,100);
	if(retVal==0)
		printf("Copy Successful\n");
	else
		printf("Copy UnSuccessful\n");
	close(fin);
	close(fout);
	return 0;
}