#include<iostream>
using namespace std;

void hap(int& a) // �Ű����� �ȿ� &�� ���� ������ �ٲ� �� �ִ�. 
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
//	//int& t = *i; // t�� i�� ������, i�� p�� �ּҸ� ������ �����Ƿ� t,i,p�� �ϳ��� ���� �ٲ���� ��ü�� �� �ٲ��.
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