#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class TT
{
public:
	TT();
	~TT();
	TT(const TT& t);
	TT& operator=(const TT& t)
	{
		cout << "tt =��������� ȣ��" << endl;
		int length = strlen(t.ch) + 1;
		ch = new char[length];
		strcpy(ch, t.ch);
	}
	char* ch;
private:

};

TT::TT():ch(new char[10])
{
	cout << "�⺻ ������ ȣ��" << endl;
}

//TT::TT(const TT& t):ch(t.ch)
//{
//	cout << "�⺻ ��������� ȣ��" << endl;
//}

TT::TT(const TT& t)
{
	cout << "tt ��������� ȣ��" << endl;
	int length = strlen(t.ch) + 1;
	ch = new char[length];
	strcpy(ch, t.ch);
}

TT::~TT()
{
	cout << "TT �Ҹ��� ȣ��" << endl;
	delete[] ch;
}

TT& test(TT& t)
{
	return t;
}

void main()
{
	TT myT;
	strcpy(myT.ch, "abc");

	//test(myT);
	TT& copyT = test(myT);
	cout << "copyT.ch = " << copyT.ch << endl;
	strcpy(copyT.ch, "ccc");
	//cout << "return ��.ch = " << test(myT).ch << endl;
	cout << "myT.ch = " << myT.ch << endl;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class UU
{
public:
int k;
UU();
~UU();

private:

};

UU::UU():k(3)
{
}

UU::~UU()
{
cout << "UU �Ҹ��� ȣ��" << endl;
}

class TT
{
public:
UU& uu;
TT(UU& uu_);
~TT();
//TT(const TT& t);
char* ch;
private:

};

TT::TT(UU& uu_):uu(uu_), ch(new char[10])
{
}

//TT::TT(const TT& t)
//{
//	cout << "tt ��������� ȣ��" << endl;
//	int length = strlen(t.ch) + 1;
//	ch = new char[length];
//	strcpy(ch, t.ch);
//}

TT::~TT()
{
cout << "TT �Ҹ��� ȣ��" << endl;
delete& uu;
delete[] ch;
}

void test(TT t)
{
//return t;
}

void main()
{
UU* myUU = new UU();
TT* myT = new TT(*myUU);
strcpy(myT->ch, "abc");

delete myT;
cout << "myT delete ȣ�� ����" << endl;
cout << "myUU->k = " << myUU->k << endl;
//test(myT);

//cout << "myT.ch = " << myT.ch << endl;
}
*/