#include <stdio.h>
#include <winsock2.h>

#pragma comment (lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
	WSADATA WSAData;
	SOCKET serverSocket;
	SOCKADDR_IN addr;
	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s <ip_addr> <message_to_send>", argv[0]);
		return -1;
	}
	WSAStartup(MAKEWORD(2,0), &WSAData);
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_family = AF_INET;
    	addr.sin_addr.s_addr = inet_addr(argv[1]);
    	addr.sin_port = htons(8989);

	connect(serverSocket, (SOCKADDR*)&addr, sizeof(addr));
	printf("Connected to server!\n");
	int var = send(serverSocket, argv[2], sizeof(argv[2]), 0);
	if(var == -1)
	{
		fprintf(stderr, "Unable to send message.\n");
	}
	closesocket(serverSocket);
	WSACleanup();
	printf("socket closed\n");
	return 0;
}
