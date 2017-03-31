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
		cout << "CTarget Class 기본 생성자 호출" << endl;
		*i = 3;
		ch = "기본생성자";
	}
	CTargetClass(int* i_, char* ch_):i(i_), k(777)
	{
		cout << "CTarget Class 생성자 호출" << endl;
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
		cout << "CTargetClass 복사 생성자 호출" << endl;
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
		cout << "CTargetClass 소멸자 호출" << endl;
		if (ch != nullptr)
		{
			//cout << "ch = " << ch << endl;
			delete[] ch;
		}
		if (*i > 0)
		{
			cout << *i << "소멸할거야" << endl;
			delete i;
		}
		else
		{
			cout << "i 이미 소멸 됨" << endl;
		}
		
	}
	int getI() 
	{ 
		if (i)
			return *i;
		else
		{
			cout << "i 가 nullptr" << endl;
			return 77;
		}
	}
};

