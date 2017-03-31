#pragma once
#include<list>
#include<iostream>
using namespace std;
#include"TargetClass.h"

typedef list<CTargetClass>::iterator TestIter;

class CListTest
{
	list<CTargetClass> myList;
public:

	CListTest()
	{
		cout << "listTest �⺻ ������ ȣ��" << endl;
	}
	CListTest(const CListTest& tt):myList(tt.myList)
	{
		cout << "listTest ���� ������ ȣ��" << endl;
	}

	~CListTest()
	{
		cout << "listTest �Ҹ��� ȣ��" << endl;
	}
	void pushClass(CTargetClass& target)
	{
		myList.push_front(target);
	}
	void eraseClass(TestIter target)
	{
		myList.erase(target);
	}
	TestIter getIterBegin()
	{
		return myList.begin();
	}
	TestIter getIterEnd()
	{
		return myList.end();
	}
};

