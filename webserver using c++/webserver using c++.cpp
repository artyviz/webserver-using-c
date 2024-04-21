#define _WINSOCK_DEPRECTAED_NO_WARNINGS
#pragma comment(lib , "ws2_32.lib")
#include <iostream>
#include <WinSock2.h>
#include <string>
int main()
{
	std::cout << "Attempting to create a server";
	
	SOCKET wsocket;
	SOCKET new_wsockety;
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

	return 0;
}