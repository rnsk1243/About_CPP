#include<iostream>
#include<array>
using namespace std;


void main()
{
	// double 타입 원소 100개 array 생성
	array<double, 100> data{}; // 모든 원소를 0.0으로 초기화

	data.fill(3.1415926); // 모든 원소를 파이값으로 설정

	cout << data[0] << endl;
	try
	{
		cout << data.at(100) << endl; // .at 인덱스 범위를 벗어나면 예외 발생시켜줌.(try_catch에 걸림) 하지만 성능저하.
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
	cout << "get<5> = " << get<5>(data) << endl; // 런타임 검사 없이 인덱스 값으로 원소에 접근(인덱스 벗어나면 안된다.)

	

}