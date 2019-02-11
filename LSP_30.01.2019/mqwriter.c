# include <unistd.h>
# include <stdio.h>
# include <sys/ipc.h>
# include <sys/types.h>
# include <string.h>

main()
{
	int msqid,i;
	key_t key;
	struct message{
	long type;
	char text[50];}msgwrite;
	key=ftok("/root/Desktop/LSP_30.01.2019/mq.c",100);
	msqid=msgget(key,IPC_CREAT);
	for(i=1;i<=10;i++)
	{
		msgwrite.type=i;
		strcpy(msgwrite.text,"Message in the queue");
		msgsnd(msqid,(void*)&msgwrite,sizeof(msgwrite.text),IPC_NOWAIT);
	}
}
	
