#pragma once
#include<list>
#include<iostream>
using namespace std;
#include"TargetClass.h"

typedef list<CTargetClass>::iterator TestIter;

class CListTest
{
	list<CTargetClass>* myList;
public:

	CListTest():myList(new list<CTargetClass>())
	{
		cout << "listTest ���� ������ ȣ��" << endl;
	}

	~CListTest()
	{
		cout << "listTest �Ҹ��� ȣ��" << endl;
		delete myList;
	}
	void pushClass(CTargetClass& target)
	{
		myList->push_front(target);
	}
	void eraseClass(TestIter target)
	{
		myList->erase(target);
	}
	TestIter getIterBegin()
	{
		return myList->begin();
	}
	TestIter getIterEnd()
	{
		return myList->end();
	}
};

