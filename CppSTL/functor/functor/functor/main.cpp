#include<iostream>
using namespace std;
#include<algorithm>
class MyClass
{
public:
	MyClass();
	~MyClass();
	int MyFunc(int a, int b)
	{
		return a*b;
	}
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int func(int a, int b)
{
	return a + b;
}

class Box
{
	double x_, y_, z_;
public:
	Box(double x, double y, double z);
	~Box();
	double getX()const { return x_; }
	double getY()const { return y_; }
	double getZ()const { return z_; }
private:

};

Box::Box(double x, double y, double z):
	x_(x),y_(y),z_(z)
{
}

Box::~Box()
{
}



class Volume
{
public:
	Volume();
	~Volume();
	// 상수 버전 op()를 호출하고 끝
	double operator()(double a, double b, double c)
	{
		cout << "일반용이지만 사실 상수 버전 op()를 호출 함" << endl;
		return const_cast<double&>(static_cast<const Volume&>(*this)(a, b, c));
	}
	const double& operator()(double a, double b, double c) const/*const가 붙으면 const객체로도 호출 가능*/
	{
		cout << "상수용" << endl;
		return a*b*c;
	}
	double operator()(const Box& box) const
	{
		return  box.getX()*box.getY()*box.getZ();
	}
private:

};

Volume::Volume()
{
}

Volume::~Volume()
{
}

template<typename ForwardIter, typename F>
void change(ForwardIter first, ForwardIter last, F fun)
{
	for (auto iter = first; iter != last; ++iter)
	{
		cout << fun(*iter);
	}
}

template<typename Double, typename F>
void templateFunc(Double d, F funobj)
{
	cout << "뽀이뽀이 = " << funobj(d, d) << endl;
}

template<typename F>
void transform(double x, double y, F z)
{
	cout << "z = " << z << endl;
}

void main()
{

	//int data[]{ 1,2,3,4 };
	//change(begin(data), end(data), [](int value)->int {return value*value; });



	//int(*pf)(int, int) = func;

	//// 멤버 함수 포인터
	//int(MyClass::*mpf)(int, int) = &MyClass::MyFunc;
	//cout << (myClass.*mpf)(3, 6) << endl;

	//Volume volume;
	//double room{ volume(1.2, 1.5, 2.6) };
	//cout << room << endl;

	//const Box box{ 1.0, 2.0, 3.0 };
	//cout << volume(box) << endl;
	int bbq = 16;
	int t = 10;
	auto a = [&t](int i) ->int
	{	
		t = 9;
		return i; 
	};
	a(1);
	cout << "t = " << t << endl;
	//auto aa = [](int i)-> int {return i; };

	//auto t = aa(3);
	//cout << t << endl;

	double data[]{ 1.1,2.2,3.3,4.4 };
	auto bb = [](double x)->double {return x; };
	for (auto iterBegin = begin(data); iterBegin != end(data); ++iterBegin)
	{
		
		transform(*iterBegin, *iterBegin, bb(*iterBegin));
	}
	
	generate(begin(data), end(data), [&]()->double{return *begin(data);});
}