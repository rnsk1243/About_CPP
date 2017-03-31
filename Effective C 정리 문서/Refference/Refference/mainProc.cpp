#include<iostream>
using namespace std;

void hap(int& a) // 매개변수 안에 &가 들어가면 원본이 바뀔 수 있다. 
{
	cout << "a = " << a << endl;
	a += 2;
	cout << "a = " << a << endl;
}
//void hap(int& a)
//{
//	cout << "a = " << a << endl;
//	a += 2;
//	cout << "a = " << a << endl;
//}
int& test(int i)
{
	int a = i;
	return a;
}
void main()
{
	int b = test(3);
	cout << "b = " << b << endl;
	cout << "b = " << b << endl;
}
//
//void main()
//{
//	int* c = new int();
//	*c = 87;
//	int& a = *c;
//	
//	//a = 9;
//	cout << "a = " << a << endl;
//	//int* k = new int();
//	int k = 3;
//	//*k = 2;
//	int pk = test(k);
//	cout << "=============" << endl;
//	cout << pk << endl;
//	//cout << k << endl;
//	//int p = 5;
//	//int* i = &p;
//	//int& t = *i; // t는 i의 참조자, i는 p의 주소를 가지고 있으므로 t,i,p중 하나의 값만 바뀌더라도 전체가 다 바뀐다.
//	////hap(p);
//	//t = 99;
//	//cout << "t = " << t << endl;
//	//cout << "i = " << *i << endl;
//	//cout << "p = " << p << endl;
//
//	//int k = 55;
//	//int& kk = k;
//	//k = 88;
//	//cout << "kk = " << kk << endl;
//	//int y = 8;
//	//int x = 5;
//	//int& a = x;
//	//hap(x);
//	//cout << "a = " << a << endl;
//	//a = y;
//	//cout << "a = " << a << endl;
//}