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
	char text[50];}msgread;
	key=ftok("/root/Desktop/LSP_30.01.2019/mq.c",100);
	msqid=msgget(key,IPC_CREAT);
	for(i=1;i<=10;i++)
	{
		msgrcv(msqid,(void*)&msgread,sizeof(msgread.text),i,IPC_NOWAIT);
		printf("The message with type value %d is %s\n",i,msgread.text);
	}
	msgctl(msqid,IPC_RMID,0);
}
	
