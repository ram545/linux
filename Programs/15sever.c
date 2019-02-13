/**********************************************************************
* FILENAME:        15.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/


# include <stdio.h>
# include <sys/socket.h>
# include <netinet/in.h>
# define SERVER_ADDR "127.0.0.1" 

void transact_with_client(int sock)
{
	char buf[100],filename[32];
	int n,fdwrite;
	recv(sock,filename,sizeof(filename),0);
	fdwrite = open(filename,O_WRONLY|O_CREAT|O_TRUNC);
	while((n=recv(sock,buf,sizeof(buf),0))>0)
		write(fdwrite,&buf,sizeof(buf));
	close(fdwrite);
}

int main(int argc,char *argv[])
{
	int socfd,port,size,csd;
	struct sockaddr_in server,client;
	socfd=socket(AF_INET,SOCK_STREAM,0);
	port=atoi(argv[1]);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(SERVER_ADDR);
	server.sin_port=htons(port);
	bind(socfd,(struct sockaddr*)&server,sizeof(server));
	listen(socfd,5);	
	while(1)
	{
		size=sizeof(client);
		csd=accept(socfd,(struct sockaddr*)&client,&size);
		transact_with_client(csd);
		close(csd);
	}
	close(socfd);
	return 0;
}
