/**********************************************************************
* FILENAME:        15.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/

# include <stdio.h>
# include <string.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <fcntl.h>
# include <unistd.h>

void transact_with_server(int sock,char *filename)
{
	char buf[100];
	int n,fdread;
	send(sock,filename,sizeof(filename),0);
	fdread=open(filename,O_RDONLY);
	while(1)
	{
		bzero(buf,sizeof(buf));
		read(fdread,&buf,sizeof(buf)-1);
		send(sock,buf,strlen(buf),0);
	}
	close(fdread);
}
 
int main(int argc,char *argv[])
{
	int cosfd,port;
	char *filename;
	struct sockaddr_in server;
	cosfd=socket(AF_INET,SOCK_STREAM,0);
	port=atoi(argv[2]);
	filename=argv[3];
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(argv[1]);
	server.sin_port=htons(port);
	connect(cosfd,(struct sockaddr*)&server,sizeof(server));
	transact_with_server(cosfd,filename);
	close(cosfd);
	return 0;
}
