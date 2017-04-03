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
	cout << "pushTT함수 끝" << endl*/;
	//cout << "tt = " << tt->getI() << endl;
	test(manager);
	// main함수 안에서 for문을 돌리는건 상관 없다만.. 
	//for문안에서 객체를 생성(일반객체 스택에 들어가는 것)하면 그 객체는 계속 남는다.
	TestIter iterBegin = manager.listTest.getIterBegin();
	TestIter iterEnd = manager.listTest.getIterEnd();
	for (; iterBegin != iterEnd; ++iterBegin)
	{
		cout << iterBegin->getI() << endl;
	}
	cout << "-------------" << endl;
	
}