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
		cout << "CTargetManager 생성자 호출" << endl;
	}
	CTargetManager(const CTargetManager& manger):listTest(manger.listTest)
	{
		cout << "CTargetManager 복사생성자 호출" << endl;
	}

	~CTargetManager()
	{
		cout << "CTargetManager 소멸자 호출" << endl;
	}

};

