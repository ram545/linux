# include <stdio.h>
# include <string.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <fcntl.h>
# include <unistd.h>

void transact_with_server(int sock)
{
	char buf[100];
	int n;
	while(1)
	{
		bzero(buf,sizeof(buf));
		fgets(buf,sizeof(buf)-1,stdin);
		send(sock,buf,strlen(buf),0);
		n=recv(sock,buf,sizeof(buf),0);
		write(STDOUT_FILENO,buf,n);
	}
} 
main(int argc,char *argv[])
{
	int cosfd,port;
	struct sockaddr_in server;
	cosfd=socket(AF_INET,SOCK_STREAM,0);
	port=atoi(argv[2]);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(argv[1]);
	server.sin_port=htons(port);
	connect(cosfd,(struct sockaddr*)&server,sizeof(server));
	transact_with_server(cosfd);
	close(cosfd);
}
