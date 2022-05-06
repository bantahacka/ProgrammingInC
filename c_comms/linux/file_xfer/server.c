#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#define PORT argv[1]
#define IP "0.0.0.0"
#define MAXBUF 1024


int main(int argc, char *argv[])
{
	int srvSock, clnSock, addrlen, returnStatus, fd, i, readCounter, writeCounter, val, result, len;
	char readbuff[MAXBUF];
	char filename[MAXBUF];
	char *bufptr;
	struct sockaddr_in srv, cln;

	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <port to listen on>\n", argv[0]);
		return -1;
	}

	srvSock = socket(AF_INET, SOCK_STREAM, 0);
	if(srvSock == -1)
	{
		fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
		return -1;
	}
	else
	{
		fprintf(stdout, "Socket created.\n");
	}

	val = 1;
	result = 0;
	result = setsockopt(srvSock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	if(result == -1)
	{
		fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
	}
	else
	{
		fprintf(stdout, "Address reuse set\n");
	}

	srv.sin_family = AF_INET;
	srv.sin_addr.s_addr = inet_addr(IP);
	srv.sin_port = htons(atoi(PORT));
	len = sizeof(srv);

	returnStatus = bind(srvSock, (struct sockaddr*)&srv, len);
	if(returnStatus == 0)
	{
		fprintf(stdout, "Socket bound.\n");
	}
	if(returnStatus == -1)
	{
		fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
		return -1;
	}
	returnStatus = listen(srvSock, 10);
	if(returnStatus == 0)
	{
		fprintf(stdout, "Server listening on %s:%s\n", IP, PORT);
	}
	else
	{
		fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
		return -1;
	}
	
	for(;;)
	{
		addrlen = sizeof(cln);
		
		clnSock = accept(srvSock, (struct sockaddr*)&cln, &addrlen);
		if(clnSock == -1)
		{
			fprintf(stderr, "accept: %s (%d)\n", strerror(errno), errno);
			continue;
		}

		i = 0;
		
		if((readCounter = read(clnSock, filename + i, MAXBUF)) > 0)
		{
			i += readCounter;
		}

		if(readCounter == -1)
		{
			fprintf(stderr, "read: %s (%d)\n", strerror(errno), errno);
			close(clnSock);
			continue;
		}

		filename[i+1] = '\0';
		fprintf(stdout, "Reading file %s\n", filename);

		fd = open(filename, O_RDONLY);

		if(fd == -1)
		{
			fprintf(stderr, "open: %s (%d)\n", strerror(errno), errno);
			close(clnSock);
			continue;
		}

		readCounter = 0;

		while((readCounter = read(fd, readbuff, MAXBUF)) > 0)
		{
			writeCounter = 0;
			bufptr = readbuff;

			while(writeCounter < readCounter)
			{
				readCounter -= writeCounter;
				bufptr += writeCounter;
				writeCounter = write(clnSock, bufptr, readCounter);

				if(writeCounter == -1)
				{
					fprintf(stderr, "write: %s (%d)\n", strerror(errno), errno);
					close(clnSock);
					close(fd);
					continue;
				}
			}
		}
		
		close(clnSock);
		close(fd);
	}		
	close(srvSock);
	return 0;

}
