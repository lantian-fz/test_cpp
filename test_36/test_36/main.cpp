#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class A
{
public:
	A(int a)
	{
		this->a = a;
	}
	virtual void fun()
	{
		cout << "AAAAAAAAAA" << endl;
	}

private:
	int a;
};

class B:public A
{
public:
	B(int a, int b) :A(a)
	{
		this->b = b;
	}
	void fun()
	{
		cout << "BBBBBBBBB" << endl;
	}
private:
	int b;
};

int main()
{
	A a;
	B b;
	a.fun();
	b.fun();

	return 0;
}

//class A
//{
//public:
//	virtual void fun()
//	{
//		cout << "AAAAAAAAAA" << endl;
//	}
//
//	virtual void fun(int a)
//	{
//		cout << "AAAAAAAAAAaaaaaaaaa" << endl;
//	}
//
//private:
//	int a;
//};
//
//class B
//{
//public:
//	void fun()
//	{
//		cout << "BBBBBBBBB" << endl;
//	}
//private:
//	int a;
//};
//
//int main()
//{
//	A a;
//	B b;
//	a.fun();
//	b.fun();
//
//	cout << "sizeof(a) " << sizeof(a) << endl;//没有virtual时是4，有了是8，多了一个vptr指针
//	cout << "sizeof(b) " << sizeof(b) << endl;
//
//	return 0;
//}