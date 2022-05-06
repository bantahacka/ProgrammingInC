#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>
#define INFLOOP 1
#define MAXBUF 1024
#define SERVER argv[1]
#define PORT argv[2]
#define SRCFILE argv[3]
#define DSTFILE argv[4]

int main(int argc, char *argv[])
{
	// Declare vars
	int mysock, counter, filesize, fd, returnStatus;
	struct sockaddr_in cln;
	char buffer[MAXBUF];
	// Check to see if the user has entered a message that will be returned to the server everytime a client receives a message. If not, exit program
	if(argc != 5)
	{
		fprintf(stderr, "Usage: %s <server> <port> <file to read from server> <destination filename>\n", argv[0]);
		return -1;
	}

	// Create socket
	mysock = socket(AF_INET, SOCK_STREAM, 0);
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
	cln.sin_family = AF_INET;
	cln.sin_addr.s_addr = inet_addr(SERVER);
	cln.sin_port = htons(atoi(PORT));

	// Create the connection to the server
	returnStatus = connect(mysock, (struct sockaddr*)&cln, sizeof(cln));
	if(returnStatus == -1)
	{
		fprintf(stderr, "connect: %s (%d)", strerror(errno), errno);
		return -1;
	}

	// If returnStatus is 0, connection is successful. Enter an infinite loop until connection is destroyed
	else if(returnStatus == 0)
	{
		fprintf(stdout, "Connected to %s:%s\n", SERVER, PORT);
		
		// Send the name of the file we want to the server
		returnStatus = write(mysock, SRCFILE, strlen(SRCFILE)+1);
		if(returnStatus == -1)
		{
			fprintf(stderr, "write: %s (%d)\n", strerror(errno), errno);
			return -1;
		}
		else
		{
			fprintf(stdout, "Sent request for file: %s to server\n", DSTFILE);
		}

		// Set the socket to readonly
		shutdown(mysock, SHUT_WR);

		// Open up handle to destination file to receive contents from the server
		fd = open(DSTFILE, O_WRONLY | O_CREAT | O_APPEND);
		if(fd == -1)
		{
			fprintf(stderr, "open: %s (%d)\n", strerror(errno), errno);
			return -1;
		}
		while((counter = read(mysock, buffer, MAXBUF)) > 0)
		{
			write(fd, buffer, counter);
		}
		if(counter == -1)
		{
			fprintf(stderr, "read: %s (%d)\n", strerror(errno), errno);
			return -1;
		}
		else
		{
			chmod(DSTFILE, S_IRUSR | S_IRGRP | S_IROTH);
		}

	}
	close(mysock);
	return 0;
}

