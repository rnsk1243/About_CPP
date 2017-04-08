#include "ActionNetWork.h"
const int IntSize = 4;


CActionNetWork::CActionNetWork()
{
}


CActionNetWork::~CActionNetWork()
{
}

int CActionNetWork::recvn(SOCKET & socket, int flags)
{
	char temp[4];
	
	int isSuccess = recv(socket, temp, IntSize, flags);

	if (isSuccess == SOCKET_ERROR)
	{
		cout << "1recvn ERROR" << endl;
		return SOCKET_ERROR;
	}
	IdPw.sendRecvSize = *(int*)temp;

	// 임시로 만든 temp 메모리 반환
#pragma endregion
#pragma region 메세지 받기
	size_t left = IdPw.sendRecvSize;
	isSuccess = 0;
	while (left > 0)
	{
		isSuccess += recv(socket, IdPw.message, left, flags);
		//cout << "success = " << isSuccess << endl;
		if (isSuccess == SOCKET_ERROR)
		{
			cout << "2recvn ERROR" << endl;
			return SOCKET_ERROR;
		}
		else if (isSuccess >= left)
			break;
	}
	IdPw.message[left] = '\0';
#pragma endregion
	cout << "받은 메시지 = " << IdPw.message << endl;
	return chooseMenu(IdPw.message);
}

int CActionNetWork::chooseMenu(char * message)
{
	switch (message[0])
	{
	case '1':
		cout << "로그인" << endl;
		return 1;
	case '2':
		cout << "회원가입" << endl;
		return 2;
	case '9': 
		cout << "이전 메뉴로 돌아가기" << endl;
		return 9;
	default:
		return -1;
	}
	return -1;
}
