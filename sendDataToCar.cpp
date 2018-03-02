#include "stdafx.h"
#include "sendDataToCar.h"
#include <windows.h>  
#include <stdio.h>  

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

int sendDataToCar(unsigned char *message, int length)
{
	//建立socker连接
	WSADATA wsaData;
	SOCKET sockClient;//客户端Socket
	SOCKADDR_IN addrServer;//服务端地址
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//新建客户端socket
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	//定义要连接的服务端地址
	addrServer.sin_addr.S_un.S_addr = inet_addr("192.168.1.1");
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(2001);
	//连接到服务端
	if (connect(sockClient, (SOCKADDR*)&addrServer, sizeof(SOCKADDR)))
	{
		MessageBoxW(NULL, _T("连接到小车服务器失败"),NULL,0);
		return -1;
	}
	send(sockClient, (char*)message, length, 0);
	closesocket(sockClient);
	return 0;
}