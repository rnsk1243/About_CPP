#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"TargetManager.h"
#include"ListTest.h"
#include"TargetClass.h"

char* ch = "abcd";


void pushTT(CTargetManager& manager, CTargetClass* tt)
{
	for (int i = 0; i < 5; i++)
	{
		int* k = new int();
		*k = 3;
		CTargetClass target(k, ch);
		manager.listTest.pushClass(target);
		//tt = &target;
	}
	//cout << "tt! = " << tt->getI() << endl;
}
void test(CTargetManager& manager)
{
	for (int i = 0; i < 3; i++)
	{
		int* k = new int();
		*k = 3;
		CTargetClass target(k, ch);
		manager.listTest.pushClass(target);
	}
}

void main()
{
	CListTest listTest;
	CTargetManager manager(listTest);
	/*CTargetClass* tt = nullptr;
	pushTT(manager, tt);
	cout << "pushTT�Լ� ��" << endl*/;
	//cout << "tt = " << tt->getI() << endl;
	test(manager);
	// main�Լ� �ȿ��� for���� �����°� ��� ���ٸ�.. 
	//for���ȿ��� ��ü�� ����(�Ϲݰ�ü ���ÿ� ���� ��)�ϸ� �� ��ü�� ��� ���´�.
	TestIter iterBegin = manager.listTest.getIterBegin();
	TestIter iterEnd = manager.listTest.getIterEnd();
	for (; iterBegin != iterEnd; ++iterBegin)
	{
		cout << iterBegin->getI() << endl;
	}
	cout << "-------------" << endl;
	CTargetManager M = manager;
	TestIter iterBegin1 = M.listTest.getIterBegin();
	TestIter iterEnd1 = M.listTest.getIterEnd();
	for (; iterBegin1 != iterEnd1; ++iterBegin1)
	{
		cout << iterBegin1->getI() << endl;
	}
	iterBegin = manager.listTest.getIterBegin();
	for (; iterBegin != iterEnd; ++iterBegin)
	{
		cout << iterBegin->getI() << endl;
	}
}