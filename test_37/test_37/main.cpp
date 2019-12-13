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
public:
	virtual void Print()
	{
		cout << "AAAA a = " << a << endl;
	}
public:
	int a;
};

class B:public A
{
public:
	B(int a) :A(a)
	{

	}
public:
	virtual void Print()
	{
		cout << "BBBBB a = " << a << endl;
	}
public:
	int b;
};

void main()
{
	B arr[] = { B(0), B(1), B(2) };
	A *a = &arr[0];
	B *b = &arr[0];
	a->Print();
	b->Print();
	a++;//a的步长和b的步长不一样长
	b++;
	b++;
	//a->Print();//a++之后，不是指向下一个元素，在这里会报错
	b->Print();

}

//class A
//{
//public:
//	A(int a)
//	{
//		this->a = a;
//		//fun();
//	}
//public:
//	virtual void fun()
//	{
//		cout << "AAAAAAAA" << endl;
//	}
//private:
//	int a;
//};
//
//class B:public A
//{
//public:
//	B(int a, int b) :A(a)
//	{
//		this->b = b;
//		//fun();
//	}
//public:
//	void fun()
//	{
//		cout << "BBBBBB" << endl;
//	}
//private:
//	int b;
//};
//
//void main()
//{
//	//A *a = new B(1, 2);
//	B *b = new B(3, 4);
//
//	A *a2 = b;
//
//	a2->fun();
//
//	//delete b;
//	//delete a2;
//	//a->fun();
//	
//	//delete a;
//}