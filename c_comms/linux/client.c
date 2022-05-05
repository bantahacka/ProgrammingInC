#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define TERMSTR 2
#define INFLOOP 1
#define SERVER argv[1]
#define PORT argv[2]

int main(int argc, char *argv[])
{
	// Check to see if the user has entered a message that will be returned to the server everytime a client receives a message. If not, exit program
	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
		return -1;
	}

	// Create socket
	int mysock = socket(AF_INET, SOCK_STREAM, 0);
	if(mysock == -1)
	{
		fprintf(stderr, "socket: %s (%d)", strerror(errno), errno);
		return -1;
	}
	else
	{
		fprintf(stdout, "Socket created\n");
	}

	// Declare socket address struct, assign IP and port
	struct sockaddr_in cln;
	cln.sin_family = AF_INET;
	cln.sin_addr.s_addr = inet_addr(SERVER);
	cln.sin_port = htons(atoi(PORT));

	// Create the connection to the server
	int clnconn = connect(mysock, (struct sockaddr*)&cln, sizeof(cln));
	if(clnconn == -1)
	{
		fprintf(stderr, "connect: %s (%d)", strerror(errno), errno);
		return -1;
	}

	// If clnconn is 0, connection is successful. Enter an infinite loop until connection is destroyed
	else if(clnconn == 0)
	{
		fprintf(stdout, "Connected to %s:%s\n", SERVER, PORT);
		while (INFLOOP)
		{
			printf("\nSend your response (max 64 characters): ");

			char user_input[64] = "";
			fgets(user_input, 64, stdin);
			int var = send(mysock, user_input, strlen(user_input), 0);
			if(var == -1)
			{
				fprintf(stderr, "send: %s (%d)", strerror(errno), errno);
				continue;
			}

			char buffer[64] = "";
			int var2 = recv(mysock, buffer, sizeof(buffer), 0);
			if(var2 > 0)
			{
				fprintf(stdout, "\nFrom server: %s\n", buffer);
				continue;
			}
			else if(var2 == 0)
			{
				fprintf(stdout, "Connection closed.");
				break;
			}
			else
			{
				fprintf(stderr, "recv: %s (%d)", strerror(errno), errno);
				continue;
			}
		}
	}
	return 0;
}
