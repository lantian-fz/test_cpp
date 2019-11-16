#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "Parent 无参 构造 " << this << endl;
		this->a = 0;
	}

	Parent(int a)
	{
		cout << "Parent int 构造 " << this << endl;
		this->a = a;
	}

	~Parent()
	{
		cout << "~Parent  析构 " << this << endl;
	}
	int getA()
	{
		return a;
	}
	static int x;
//public:
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int a, int b) :Parent(b)
	{
		cout << "Child int int构造 " << this << endl;

		this->a = a;//这里会调用父类的无参构造
	}
	~Child()
	{
		cout << "~Child  析构 " << this << endl;
	}

public:
	void PrintC()
	{
		cout << "a = " << this->a << endl;
		//cout << Parent::a << endl;//如果父类的变量是public行的就可以这样调用
		cout << Parent::getA() << endl;
	}
	static int b;

public:
	int a;
};

int Parent::x = 0;
int Child::b = 0;

int main()
{
	Child c1(10, 20);
	c1.PrintC();
	cout << "x = "<< c1.x << endl;

	Parent p1;
	cout << "x = " << p1.x << endl;

	c1.x = 1000;
	cout << "x = " << c1.x << endl;//父类和子类共用一个static变量
	cout << "x = " << p1.x << endl;

	//p1.b;//父类无法使用子类自己的static变量


	return 0;
}
//--------------------------------------------------------------
//class Parent
//{
//public:
//	Parent()
//	{
//		cout << "Parent 无参 构造 " << this << endl;
//		this->a = 0;
//	}
//
//	Parent(int a)
//	{
//		cout << "Parent int 构造 " << this << endl;
//		this->a = a;
//	}
//
//	~Parent()
//	{
//		cout << "~Parent  析构 " << this << endl;
//	}
//
//public:
//	int a;
//};
//
//class Child :public Parent
//{
//public:
//	Child(int a, int b)
//	{
//		cout << "Child int int构造 " << this << endl;
//
//		this->a = a;//这里会调用父类的无参构造
//		this->b = b;
//	}
//	~Child()
//	{
//		cout << "~Child  析构 " << this << endl;
//	}
//
//public:
//	void PrintC()
//	{
//		cout << "b = " << this->b << endl;
//	}
//
//public:
//	int b;
//};
////Parent 无参 构造 00AFF8AC
////Child int int构造 00AFF8AC
////b = 20
////~Child  析构 00AFF8AC
////~Parent  析构 00AFF8AC
//int main()
//{
//	Child c1(10, 20);
//	c1.PrintC();
//
//	return 0;
//}