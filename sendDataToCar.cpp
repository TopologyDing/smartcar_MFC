#include "stdafx.h"
#include "sendDataToCar.h"
#include <windows.h>  
#include <stdio.h>  

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

int sendDataToCar(unsigned char *message, int length)
{
	//����socker����
	WSADATA wsaData;
	SOCKET sockClient;//�ͻ���Socket
	SOCKADDR_IN addrServer;//����˵�ַ
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//�½��ͻ���socket
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	//����Ҫ���ӵķ���˵�ַ
	addrServer.sin_addr.S_un.S_addr = inet_addr("192.168.1.1");
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(2001);
	//���ӵ������
	if (connect(sockClient, (SOCKADDR*)&addrServer, sizeof(SOCKADDR)))
	{
		MessageBoxW(NULL, _T("���ӵ�С��������ʧ��"),NULL,0);
		return -1;
	}
	send(sockClient, (char*)message, length, 0);
	closesocket(sockClient);
	return 0;
}