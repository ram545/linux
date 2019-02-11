# include <stdio.h>
# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/msg.h>
# include <string.h>
main()

{
	
	struct message{
	long type;
	char text[50];
	}msgread,msgwrite;
	int msgid;
	key_t key;
	
	key=ftok("/root/Desktop/LSP_30.01.2019/getch.c",100);
	msgid=msgget(key,IPC_CREAT);
	msgwrite.type=100;
	strcpy(msgwrite.text,"Message with type value 100");
	msgsnd(msgid,(void*)&msgwrite,sizeof(msgwrite.text),IPC_NOWAIT);
	msgrcv(msgid,(void*)&msgread,sizeof(msgread.text),100,IPC_NOWAIT);
	printf("The read message is %s\n",msgread.text);
}
	
