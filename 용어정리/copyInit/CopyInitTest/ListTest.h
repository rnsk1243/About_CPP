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
		cout << "listTest 복사 생성자 호출" << endl;
	}

	~CListTest()
	{
		cout << "listTest 소멸자 호출" << endl;
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

