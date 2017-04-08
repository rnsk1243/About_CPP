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
		cout << "환영!" << endl;
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
				cout << "로그인 성공" << endl;
				isLogin = true;
				break;
			}
			else
			{
				cout << "로그인 실패" << endl;
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
				cout << "id 중복 입니다." << endl;
				break;
			}
			if (wHandler.write("test.txt", 2, id, pw))
			{
				cout << "회원가입 성공" << endl;
				break;
			}
			else
			{
				cout << "회원가입 실패" << endl;
				break;
			}
		default:
			break;
		}
	}
	cout << "즐거운 대화 하십시오." << endl;
	while (true)
	{
		netWork.recvn(*clientSocket);
	}
}

/*
ifstream inFile("test.txt");
if (!inFile)
{
cout << "파일이 없습니다." << endl;
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
cout << "승인" << endl;
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
//	//string ppp = "이재명 화이팅";
//	//const char* fileName = "test.txt";
//
//	//if (wHandle.write(fileName, 3, id, pass, ppp))
//	//{
//	//	cout << "회원가입 성공" << endl;
//	//}
//	//else
//	//{
//	//	cout << "회원가입 실패" << endl;
//	//}
///////////////////////////////////////////////////
//	string id = "hgrefer";
//	string pass = "9767876666";
//	string ppp = "이재명 화이팅 입니다";
//	const char* fileName = "test.txt";
//
//	/*if (handle.CheckIDandPassWord(id, pass))
//	{
//		cout << "로그인 성공" << endl;
//	}
//	else
//	{
//		cout << "로그인 실패" << endl;
//	}
//
//	if (handle.CheckOverlapID(id))
//	{
//		cout << "사용할 수 있는 아이디" << endl;
//	}
//	else
//	{
//		cout << "사용할 수 없는 아이디" << endl;
//	}*/
//
//	if (handle.Search(fileName, true, 3, id, pass, ppp))
//	{
//		cout << "로그인 성공(찾았다)" << endl;
//	}
//	else 
//	{
//		cout << "로그인 실패" << endl;
//	}