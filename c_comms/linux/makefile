all: client server

clean:
	rm client
	rm server
	rm client_u
	rm server_u

client:
	gcc client.c -o client
	gcc udp_client.c -o client_u

server:
	gcc server.c -o server
	gcc udp_server.c -o server_u
