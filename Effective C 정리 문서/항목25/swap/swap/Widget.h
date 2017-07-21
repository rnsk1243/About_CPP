#pragma once
#include<vector>
#include<iostream>


namespace WidgetStuff
{
	template<typename T>
	class CWidgetImpl
	{
	private:
		int a, b, c;
		std::vector<double> v;
	public:
		CWidgetImpl() :a(1), b(2), c(3)
		{
			v.reserve(10);
		}

		~CWidgetImpl()
		{
		}
	};

	template<typename T>
	class CWidget
	{
		CWidgetImpl<T>* pImpl;
		int a;
	public:

		CWidget():a(0)
		{
		}

		CWidget& operator=(const CWidget& rhs)
		{
			std::cout << "���� ���� ������ ȣ�� ��." << std::endl;
			if (this == &rhs)
				return *this;
			*pImpl = *(rhs.pImpl);
			a = rhs.a;
			return *this;
		}

		~CWidget()
		{
		}

		void swap(CWidget& other)
		{
			std::cout << "��� swap �Լ� ȣ�� ��." << std::endl;
			using std::swap;
			swap(pImpl, other.pImpl);
			swap(a, other.a);
		}
		void setA(int newA) { a = newA; }
		int getA() { return a; }
	};

	template<typename T>
	void swap(CWidget<T>& a, CWidget<T>& b)
	{
		std::cout << "template swap �Լ� ȣ�� ��." << std::endl;
		a.swap(b);
	}
}



