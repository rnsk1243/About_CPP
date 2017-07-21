#include<iostream>
#include"Widget.h"
using namespace std;
using namespace WidgetStuff;

template<typename T>
void doSomething(T& obj1, T& obj2)
{
	using std::swap;

	swap(obj1, obj2);
}




void main()
{
	cout << "Hello World!" << endl;
	int a = 10;
	int b = 5;

	doSomething(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	CWidget<int> w1;
	w1.setA(11);
	CWidget<int> w2;
	cout << "w1.a = " << w1.getA() << endl;
	cout << "w2.a = " << w2.getA() << endl;
	cout << "==================" << endl;
	doSomething(w1, w2);
	cout << "==================" << endl;
	cout << "w1.a = " << w1.getA() << endl;
	cout << "w2.a = " << w2.getA() << endl;
}