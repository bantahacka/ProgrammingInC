#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define INFLOOP 1
#define SERVER argv[1]
#define PORT argv[2]
#define MAXBUF 1024


int main(int argc, char *argv[])
{

	int mysock;
	int returnStatus;
	int addrlen;
	struct sockaddr_in udpClient, udpServer;
	char buf[MAXBUF];

	// Check to see if the user has entered a message that will be returned to the server everytime a client receives a message. If not, exit program
	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
		return -1;
	}

	// Create socket
	mysock = socket(AF_INET, SOCK_DGRAM, 0);
	if(mysock == -1)
	{
		fprintf(stderr, "socket: %s (%d)\n", strerror(errno), errno);
		return -1;
	}
	else
	{
		fprintf(stdout, "Socket created\n");
	}

	// Declare socket address struct, assign IP and port
	udpClient.sin_family = AF_INET;
	udpClient.sin_addr.s_addr = INADDR_ANY;
	udpClient.sin_port = 0;

	// Bind to socket
	returnStatus  = bind(mysock, (struct sockaddr*)&udpClient, sizeof(udpClient));
	if(returnStatus != 0)
	{
		fprintf(stderr, "connect: %s (%d)", strerror(errno), errno);
		return -1;
	}

	// If returnStatus is 0, connection is successful. Enter an infinite loop until connection is destroyed
	else if(returnStatus == 0)
	{
		fprintf(stdout, "Bind completed\n");

		// Get server address from CMD Line args and setup struct for server
		udpServer.sin_family = AF_INET;
		udpServer.sin_addr.s_addr = inet_addr(argv[1]);
		udpServer.sin_port = htons(atoi(argv[2]));
		
		// Send the message in the buffer

		while(INFLOOP)
		{
			// Capture user input and send it to the buffer ready for transmission
			fprintf(stdout, "\nEnter a message to send to the server (max 1024 chars): ");
			fgets(buf, MAXBUF, stdin);

			// Send the message to the server
			returnStatus = sendto(mysock, buf, strlen(buf)+1, 0, (struct sockaddr*)&udpServer, sizeof(udpServer));
			if(returnStatus == -1)
			{
				// Message failed to send			
				fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
				continue;
			}
			else
			{
				// Message sent, await confirmation from server operator
				fprintf(stdout, "Message sent!\n");
				addrlen = sizeof(udpServer);
				returnStatus = recvfrom(mysock, buf, MAXBUF, 0, (struct sockaddr*)&udpServer, &addrlen);
				if(returnStatus == -1)
				{
					// No confirmation received
					fprintf(stderr, "%s (%d)\n", strerror(errno), errno);
				}
				else
				{
					// Confirmation received, print confirmation message
					buf[returnStatus] = 0;
					fprintf(stdout, "Received: %s\n", buf);
				}
				
				continue;
			}

		}

	}
	// Cleanup
	close(mysock);
	return 0;
}
