#pragma once
#include<iostream>
using namespace std;
#include"ListTest.h"

class CTargetManager
{
public:
	CListTest& listTest;

	CTargetManager(CListTest& listTest_):listTest(listTest_)
	{
		cout << "CTargetManager ������ ȣ��" << endl;
	}
	CTargetManager(const CTargetManager& manger):listTest(manger.listTest)
	{
		cout << "CTargetManager ��������� ȣ��" << endl;
	}

	~CTargetManager()
	{
		cout << "CTargetManager �Ҹ��� ȣ��" << endl;
	}

};

