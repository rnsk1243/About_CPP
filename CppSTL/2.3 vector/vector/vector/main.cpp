#include<iostream>
#include<vector>
using namespace std;

/*
	���� �����̳�
	�ڵ����� ũ�Ⱑ Ŀ����.(�Ҵ�� �뷮(capacity)�� �ʰ��ϴ� ���)
	������ ���� �߰� / ������ �� ȿ�� ��.
*/

void main()
{
	//������
	vector<double> doubles; // �Ҵ� ���� ���� �߰��� �� �ڵ� �Ҵ� ��.
	// �뷮 �ø��� ���
	doubles.reserve(20); // 20�� ���� ���� (�ݺ��� �ٽ� �����ؾ� ��.) �Ҵ� ��� ���

	vector<double>::iterator iterBegin = doubles.begin();
	for (; iterBegin != doubles.end(); ++iterBegin)
	{
		cout << *iterBegin << endl;
	}
}