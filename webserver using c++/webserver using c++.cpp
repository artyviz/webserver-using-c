#define _WINSOCK_DEPRECTAED_NO_WARNINGS
#pragma comment(lib , "ws2_32.lib")
#include <iostream>
#include <WinSock2.h>
#include <string>
int main()
{
	std::cout << "Attempting to create a server";
	
	SOCKET wsocket;
	SOCKET new_wsocket;
	WSADATA wsaData;
	struct sockaddr_in server;
	int server_len;
	int BUFFER_SIZE = 37020;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		std::cout << "couldn't initialize";
	}
	
	wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (wsocket == INVALID_SOCKET)
	{
		std::cout << "Coudln't create a socket";
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(8080);
	server_len = sizeof(server);

	if (bind(wsocket, (SOCKADDR*)&server, server_len) != 0)
	{
		std::cout << "unable to bind the socket";
	}

	if (listen(wsocket, 20) != 0)
	{
		std::cout << "couldn't start  listening";
	}

	std::cout << "listening on 127.0.0.1:8080\n";

	int bytes = 0;
	while (true)
	{
		new_wsocket = accept(wsocket, (SOCKADDR*)&server, &server_len);
		if (new_wsocket == INVALID_SOCKET)
		{
			std::cout << "couldn't accept \n";
		}
		
		char buff[30720] = { 0 };
		bytes = recv(new_wsocket, buff, BUFFER_SIZE, 0);
		if (bytes < 0)
		{
			std::cout << "couldn't read client request";
		}
		std::string serverMessage = "HTTP/1.1 200 ok\n Content-Type : text/html \ n Content - length: ";
		std::string response = "<html><h1>SERVER SUCCESSFULLY CREATED: 'HELLO' </H1></HTML>";
		serverMessage.append(std::to_string(response.size()));
		serverMessage.append("\n\n");
		serverMessage.append(response);
	}	

	return 0; 
}