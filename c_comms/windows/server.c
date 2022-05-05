#include <stdio.h>
#include <winsock2.h>

#pragma comment (lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
	WSADATA WSAData;
	SOCKET serverSocket, clientSocket;
	SOCKADDR_IN serverAddr, clientAddr;

    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>", argv[0]);
		return -1;
    }

	WSAStartup(MAKEWORD(2,0), &WSAData);
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(atoi(argv[1]));

	bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	listen(serverSocket, 10);

	char buffer[1024];
	int clientAddrSize = sizeof(clientAddr);
	if((clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
	{
		printf("New client!\n");
        memset(buffer, 0x00, sizeof(buffer));
		recv(clientSocket, buffer, sizeof(buffer), 0);
        printf("%s\n", buffer);
	}

	closesocket(serverSocket);
	WSACleanup();
	printf("socket closed");
}
