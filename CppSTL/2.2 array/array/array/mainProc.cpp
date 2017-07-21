#include<iostream>
#include<array>
using namespace std;


void main()
{
	// double Ÿ�� ���� 100�� array ����
	array<double, 100> data{}; // ��� ���Ҹ� 0.0���� �ʱ�ȭ

	data.fill(3.1415926); // ��� ���Ҹ� ���̰����� ����

	cout << data[0] << endl;
	try
	{
		cout << data.at(100) << endl; // .at �ε��� ������ ����� ���� �߻�������.(try_catch�� �ɸ�) ������ ��������.
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	array<double, 100>::iterator iterBegin = data.begin();

	for (; iterBegin != data.end(); ++iterBegin)
	{
		cout << *iterBegin << " / ";
	}
	cout << endl;
	cout << "get<5> = " << get<5>(data) << endl; // ��Ÿ�� �˻� ���� �ε��� ������ ���ҿ� ����(�ε��� ����� �ȵȴ�.)

	

}