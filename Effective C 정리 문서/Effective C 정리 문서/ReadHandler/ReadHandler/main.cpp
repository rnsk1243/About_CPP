#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
#include"ReadHandler.h"
#include"WriteHandler.h"
#include"ReadyNetWork.h"
#include"ActionNetWork.h"

void main()
{
	CReadyNetWork readyNetWork;
	CActionNetWork netWork;
	SOCKET* clientSocket = new SOCKET();
	readyNetWork.Accept(*clientSocket);
	CReadHandler rHandler;
	CWriteHandler wHandler;
	bool isLogin = false;
	string id, pw;
	while (!isLogin)
	{
		cout << "ȯ��!" << endl;
		switch (netWork.recvn(*clientSocket))
		{
		case 1:
			netWork.recvn(*clientSocket);
			id = netWork.getIdPw().message;
			if (0 == id.compare("9"))
				break;
			netWork.recvn(*clientSocket);
			pw = netWork.getIdPw().message;
			if (0 == pw.compare("9"))
				break;
			if (rHandler.CheckIDandPassWord(id, pw))
			{
				cout << "�α��� ����" << endl;
				isLogin = true;
				break;
			}
			else
			{
				cout << "�α��� ����" << endl;
				break;
			}
		case 2:
			netWork.recvn(*clientSocket);
			id = netWork.getIdPw().message;
			if (0 == id.compare("9"))
				break;
			netWork.recvn(*clientSocket);
			pw = netWork.getIdPw().message;
			if (0 == pw.compare("9"))
				break;
			if (!rHandler.CheckOverlapID(id))
			{
				cout << "id �ߺ� �Դϴ�." << endl;
				break;
			}
			if (wHandler.write("test.txt", 2, id, pw))
			{
				cout << "ȸ������ ����" << endl;
				break;
			}
			else
			{
				cout << "ȸ������ ����" << endl;
				break;
			}
		default:
			break;
		}
	}
	cout << "��ſ� ��ȭ �Ͻʽÿ�." << endl;
	while (true)
	{
		netWork.recvn(*clientSocket);
	}
}

/*
ifstream inFile("test.txt");
if (!inFile)
{
cout << "������ �����ϴ�." << endl;
return;
}
CReadHandler readHandler;

string id = "def";
string pass = "456";

while (!inFile.eof())
{
char temp[Buff_Size];
inFile.getline(temp, Buff_Size);
string tempString = temp;
vector<string> tempVec = readHandler.parse(tempString, '|');
IDandPassWord idPassStruct(tempVec[0], tempVec[1]);
if (readHandler.CheckIDandPassWord(idPassStruct, id, pass))
{
cout << "����" << endl;
break;
}
}
*/

//CReadHandler handle;
//	CWriteHandler wHandle;
//
/////////////////////////////////////////////////////
//	//string id = "hgrefer";
//	//string pass = "9767876666";
//	//string ppp = "����� ȭ����";
//	//const char* fileName = "test.txt";
//
//	//if (wHandle.write(fileName, 3, id, pass, ppp))
//	//{
//	//	cout << "ȸ������ ����" << endl;
//	//}
//	//else
//	//{
//	//	cout << "ȸ������ ����" << endl;
//	//}
///////////////////////////////////////////////////
//	string id = "hgrefer";
//	string pass = "9767876666";
//	string ppp = "����� ȭ���� �Դϴ�";
//	const char* fileName = "test.txt";
//
//	/*if (handle.CheckIDandPassWord(id, pass))
//	{
//		cout << "�α��� ����" << endl;
//	}
//	else
//	{
//		cout << "�α��� ����" << endl;
//	}
//
//	if (handle.CheckOverlapID(id))
//	{
//		cout << "����� �� �ִ� ���̵�" << endl;
//	}
//	else
//	{
//		cout << "����� �� ���� ���̵�" << endl;
//	}*/
//
//	if (handle.Search(fileName, true, 3, id, pass, ppp))
//	{
//		cout << "�α��� ����(ã�Ҵ�)" << endl;
//	}
//	else 
//	{
//		cout << "�α��� ����" << endl;
//	}