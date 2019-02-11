/**********************************************************************
* FILENAME:        6.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>

void forking(int i){
        pid_t pid=fork();
        int status;
        if(pid==0){
                printf("In %d child process\n",i);
                sleep(2*i);
                exit(i);
        }
        if(pid!=0||pid!=-1){
                i++;
                if(i<10)
                        forking(i);
                waitpid(pid,&status,0);
                printf("Exit Status %d\n",WEXITSTATUS(status));
                if(WIFEXITED(status))
                        printf("Normal Termination\n");
                if(WIFSIGNALED(status))
                        printf("Terminated by signal\n");
        }
}
 
int main()
{
        forking(0);
        return 0;
}