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

	// �ӽ÷� ���� temp �޸� ��ȯ
#pragma endregion
#pragma region �޼��� �ޱ�
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
	cout << "���� �޽��� = " << IdPw.message << endl;
	return chooseMenu(IdPw.message);
}

int CActionNetWork::chooseMenu(char * message)
{
	switch (message[0])
	{
	case '1':
		cout << "�α���" << endl;
		return 1;
	case '2':
		cout << "ȸ������" << endl;
		return 2;
	case '9': 
		cout << "���� �޴��� ���ư���" << endl;
		return 9;
	default:
		return -1;
	}
	return -1;
}
