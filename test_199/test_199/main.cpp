#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK
		}
	};
};
int A::k = 1;
void main()
{
	A::B b;
	b.foo(A());
}
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//class A
//{
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	// 非静态成员变量，可以在成员声明时给缺省值。
//	int a = 10;
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//int A::n = 10;
//int main()
//{
//	A a;
//	a.Print();
//	return 0;
//}
//class A
//{
//public:
//	A() :_a(0){}
//	A(int a) :_a(a){}
//
//public:
//	static void show();
//
//	void print()
//	{
//		show();
//	}
//
//private:
//	int _a;
//	static int _b;
//};
//
//int A::_b = 3;
//
//void A::show()
//{
//	cout << "show" << endl;
//}
//
//void main()
//{
//	A a;
//	a.print();
//}
//class Fraction{
//public:
//	Fraction(int numerator, int denominator = 1) : m_numerator(numerator), m_denominator(denominator){}
//	operator double() const
//	{
//		return (double)m_numerator / m_denominator;
//	}
//private:
//	int m_numerator;
//	int m_denominator;
//};
//
//void main()
//{
//	Fraction fraction(3, 5);
//	double d = 3.5 + fraction;
//	cout << d << endl;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a):_a(a){}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref):_aobj(a), _ref(ref), _n(10){}
//private:
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//};
//void main()
//{
//	char* a = new char[3];
//	//a = nullptr;
//	delete[] a;
//}