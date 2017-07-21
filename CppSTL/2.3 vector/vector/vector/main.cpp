#include<iostream>
#include<vector>
using namespace std;

/*
	순차 컨테이너
	자동으로 크기가 커진다.(할당된 용량(capacity)을 초과하는 즉시)
	끝에서 원소 추가 / 삭제할 때 효율 적.
*/

void main()
{
	//생성법
	vector<double> doubles; // 할당 공간 없음 추가할 때 자동 할당 됨.
	// 용량 늘리는 방법
	doubles.reserve(20); // 20개 원소 수용 (반복자 다시 생성해야 함.) 할당 비용 비쌈

	vector<double>::iterator iterBegin = doubles.begin();
	for (; iterBegin != doubles.end(); ++iterBegin)
	{
		cout << *iterBegin << endl;
	}
}