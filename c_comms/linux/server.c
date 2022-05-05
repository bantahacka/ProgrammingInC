#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#define PORT argv[1]
#define IP "0.0.0.0"

int main(int argc, char *argv[])
{
	char readbuff[64];
	struct sockaddr_in srv, cln;
	int bnd, len, lstn, rd, sfd, new_sfd;

	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <port to listen on>", argv[0]);
		return -1;
	}

	sfd = socket(PF_INET, SOCK_STREAM, 0);
	if(sfd == -1)
	{
		fprintf(stderr, "%s (%d)", strerror(errno), errno);
		return -1;
	}
	else
	{
		fprintf(stdout, "Socket created.\n");
	}

	int val = 1;
	int result = 0;
	result = setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	if(result == -1)
	{
		fprintf(stderr, "%s (%d)", strerror(errno), errno);
	}
	else
	{
		fprintf(stdout, "Address reuse set\n");
	}

	srv.sin_family = PF_INET;
	srv.sin_addr.s_addr = inet_addr(IP);
	srv.sin_port = htons(atoi(PORT));
	len = sizeof(srv);

	bnd = bind(sfd, (struct sockaddr*)&srv, len);
	if(bnd == 0)
	{
		fprintf(stdout, "Socket bound.\n");
	}
	if(bnd == -1)
	{
		fprintf(stderr, "%s (%d)", strerror(errno), errno);
		return -1;
	}
	lstn = listen(sfd, 10);
	if(lstn == 0)
	{
		fprintf(stdout, "Server listening on %s:%s\n", IP, PORT);
	}
	else
	{
		fprintf(stderr, "%s (%d)", strerror(errno), errno);
		return -1;
	}
	
	len = sizeof(cln);
	new_sfd = accept(sfd, (struct sockaddr*)&cln, &len);
	if(new_sfd == -1)
	{
		fprintf(stderr, "accept: %s (%d)", strerror(errno), errno);
		return -1;
	}
	else
	{
		char *ip_c = inet_ntoa(cln.sin_addr);
		fprintf(stdout, "New connection from client: %s:%d\n", ip_c, ntohs(cln.sin_port));		
		fprintf(stdout, "Waiting for data from client...\n");
		while(1)
		{
			memset(readbuff,0x00,sizeof(readbuff));
			char recv_success[10] = "Received!";
			rd = recv(new_sfd, readbuff, sizeof(readbuff), 0);
			if(rd > 0)
			{
				fprintf(stdout, "\nFrom client: %s", readbuff);
				int send_success = send(new_sfd, recv_success, sizeof(recv_success), 0);
				if(send_success == -1)
				{
					fprintf(stderr, "\n send: %s (%d)", strerror(errno), errno);
					continue;
				}
			continue;

			}
			else if(rd == 0)
			{
				fprintf(stdout, "\nClient connection closed\n");
				break;
			}
			else
			{
				fprintf(stderr, "\nrecv: %s (%d)", strerror(errno), errno);
				continue;
			}
		}
	}

	return 0;

}
