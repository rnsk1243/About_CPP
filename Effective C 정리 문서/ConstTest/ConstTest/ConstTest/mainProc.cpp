#include<iostream>
using namespace std;

class CIntBlock
{
public:
	mutable int i;
	int c;
	CIntBlock(int a, int b);
	~CIntBlock();
	
private:

};

CIntBlock::CIntBlock(int a, int b)
{
	i = a;
	c = b;
}

CIntBlock::~CIntBlock()
{
}

class CTextBlock
{
public:
	CTextBlock(char* ch);
	~CTextBlock();
	char& operator[](std::size_t position)
	{
		cout << "������ ���� �Լ� ȣ�� ����" << endl;
		return Text[position];
	}
	const char& operator[](std::size_t position) const
	{
		cout << "����� ���� �Լ� ȣ�� ����" << endl;
		return Text[position];
	}
private:
	string Text;
};

CTextBlock::CTextBlock(char* ch)
{
	Text = ch;
}

CTextBlock::~CTextBlock()
{
}

void main()
{
	//const CIntBlock cib(5, 2);
	//cout << cib.i << endl;
	//cib.i = 3;
	////cib.c = 22;  ���� �Ұ�
	//cout << cib.i << endl;
	//cout << cib.c << endl;
	
	const CTextBlock ctb("Hello World");
	
	cout << ctb[0] << endl;
	//ctb[0] = 'J';
	//cout << ctb[0] << endl;

}