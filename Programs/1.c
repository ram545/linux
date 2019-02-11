/**********************************************************************
* FILENAME:        1.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <error.h>
# include <errno.h>     
# include <string.h>
 
int main(int argc,char **argv){
    int fin,fout,k=1,fflag=0,buffSize=512,bytesRead,bytesWritten;
    char *inputFile,*outputFile,buff[buffSize];
    if(argc>3){
        fflag=1;
        k++;
    }
    inputFile=argv[k++];
    outputFile=argv[k];
    fin = open(inputFile,O_RDONLY);
    fout = open(outputFile,O_WRONLY|O_CREAT|O_EXCL);
    if(fin==-1 || fout==-1){
        if(fin==-1){
            printf("Unable to open!! input file\n");
            return 0;
                }
        else{
            if(errno==EEXIST && fflag==1)
                fout = open(outputFile,O_WRONLY|O_TRUNC);
            else{
                printf("File already exists overwrite flag not provided\n");
                return 0;
				}
        }
    }
    while((bytesRead = read(fin,&buff,buffSize))>0){
        printf("Bytes Read %d\n",bytesRead);
        bytesWritten = write(fout,&buff,bytesRead);
        printf("Bytes Written %d\n",bytesWritten);
    }
	close(fin);
	close(fout);
    return 0;
}