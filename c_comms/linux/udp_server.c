#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#define PORT argv[1]
#define MAXBUF 1024
#define INFLOOP 1

int main(int argc, char *argv[])
{
	int mysock;
	int returnStatus = 0;
	int addrlen = 0;
	char readbuff[MAXBUF];
	struct sockaddr_in udpServer, udpClient;

	// Check arguments 
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <port to listen on>\n", argv[0]);
		return -1;
	}

	// Create socket
	mysock = socket(AF_INET, SOCK_DGRAM, 0);
	if(mysock == -1)
	{
		fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
		return -1;
	}
	else
	{
		fprintf(stdout, "Socket created.\n");
	}

	// Setup server struct
	udpServer.sin_family = AF_INET;
	udpServer.sin_addr.s_addr = htonl(INADDR_ANY);
	udpServer.sin_port = htons(atoi(PORT));
	
	// Bind to port
	returnStatus = bind(mysock, (struct sockaddr*)&udpServer, sizeof(udpServer));
	if(returnStatus == 0)
	{
		fprintf(stdout, "Socket bound.\n");
	}
	else if(returnStatus == -1)
	{
		fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
		return -1;
	}
	// Enter loop and receive data
	while(INFLOOP)
	{
		addrlen = sizeof(udpClient);
		// Receive data from client
		returnStatus = recvfrom(mysock, readbuff, MAXBUF, 0, (struct sockaddr*)&udpClient, &addrlen);
		if(returnStatus == -1)
		{
			fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
			continue;
		}
		else
		{
			fprintf(stdout, "\nReceived from %s: %s", inet_ntoa(udpClient.sin_addr), readbuff);
			// Message was received so send a confirmation
			strncpy(readbuff, "OK", MAXBUF);
			returnStatus = sendto(mysock, readbuff, strlen(readbuff)+1, 0, (struct sockaddr*)&udpClient, addrlen);
			if(returnStatus == -1)
			{
				fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
			}
			else
			{
				// Confirmation sent
				fprintf(stdout, "Reponse sent.\n");
			}
			// Loop back to start and wait for data
			continue;
		}
	}
// Tear down socket
close(mysock);
return 0;

}

