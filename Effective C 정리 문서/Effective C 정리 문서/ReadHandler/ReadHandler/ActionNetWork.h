#pragma once
#include<WinSock2.h>
#include"ReadHandler.h"
#include<iostream>
using namespace std;

class CActionNetWork
{
	MessageStruct IdPw;
	CActionNetWork(const CActionNetWork&);
	CActionNetWork& operator=(const CActionNetWork&);
public:
	CActionNetWork();
	~CActionNetWork();
	//int sendn(S, int flags = 0);
	int recvn(SOCKET& socket, int flags = 0);
	MessageStruct getIdPw() { return IdPw; }
	int chooseMenu(char* message);
};

