#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//#include <cstdlib>
using namespace std;

class A
{
public:
	A(int a)
	{
		this->a = a;
	}

	virtual void Print()
	{
		cout << "A  Print  " << a << endl;
	}

public:
	int a;
};

class B :public A
{
public:
	B(int a) :A(a)
	{

	}
	virtual void Print()
	{
		cout << "B  Print  " << a << endl;
	}
public:
	int b;
};



int main()
{
	B arr[] = { B(0), B(1), B(2) };
	int i = 0;
	A *a = &arr[0];//
	//a->Print();
	for (a = &arr[0], i = 0; i < 3; i++, a++)
	{
		a->Print();//父类与子类指针的步长不一定相等
	}

	return 0;
}///:~
//int main()
//{
//	cout << dec << 15 << endl;//十进制
//	cout << oct << 15 << endl;//八进制
//	cout << hex << 15 << endl;//十六进制
//	cout << char(65) << endl;
//
//	return 0;
//}