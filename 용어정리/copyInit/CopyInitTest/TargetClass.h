#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;

class CTargetClass
{
	int k;
	int* i;
	char* ch;
public:
	CTargetClass():i(new int()), ch(new char[10]), k(777)
	{
		cout << "CTarget Class �⺻ ������ ȣ��" << endl;
		*i = 3;
		ch = "�⺻������";
	}
	CTargetClass(int* i_, char* ch_):i(i_), k(777)
	{
		cout << "CTarget Class ������ ȣ��" << endl;
		int length = strlen(ch_) + 1;
		ch = new char[length];
		for (int i = 0; i < length-1; i++)
		{
			ch[i] = ch_[i];
		}
		ch[length-1] = '\0';
	}

	CTargetClass(const CTargetClass& copyTarget):k(copyTarget.k)
	{
		cout << "CTargetClass ���� ������ ȣ��" << endl;
		i = new int();
		*i = *copyTarget.i;
		/*int length = sizeof(copyTarget.ch);
		ch = new char[length];
		strcat(ch, copyTarget.ch);*/
		int length = strlen(copyTarget.ch) + 1;
		ch = new char[length];
		for (int i = 0; i < length-1; i++)
		{
			ch[i] = copyTarget.ch[i];
		}
		ch[length-1] = '\0';
	}

	~CTargetClass()
	{
		cout << "CTargetClass �Ҹ��� ȣ��" << endl;
		if (ch != nullptr)
		{
			//cout << "ch = " << ch << endl;
			delete[] ch;
		}
		if (*i > 0)
		{
			cout << *i << "�Ҹ��Ұž�" << endl;
			delete i;
		}
		else
		{
			cout << "i �̹� �Ҹ� ��" << endl;
		}
		
	}
	int getI() 
	{ 
		if (i)
			return *i;
		else
		{
			cout << "i �� nullptr" << endl;
			return 77;
		}
	}
};

