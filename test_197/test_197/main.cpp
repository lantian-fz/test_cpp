#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class A
{
public:
	A(){_a = 0;}
	A(int a){_a = a;}

	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()const
	{
		cout << "show" << endl;
		//PrintA();//����
	}
private:
	int _a;
};
void main()
{
	A a;
	a.PrintA();
}
//struct A
//{
//	char a;
//	int b;
//	int c;
//	struct B
//	{
//		char a;
//		double b;
//		double c;
//	}B;
//}A;
//
//struct E
//{
//	char a;
//	int b;
//	int c;
//	struct B
//	{
//		char a;
//		double b;
//		double c;
//	};
//}E;
//
//struct C
//{
//	char a;
//	int b;
//	int d;
//}C;
//struct D
//{
//	char a;
//	int b;
//	int d;
//};
//void main()
//{
//	cout << sizeof(A) << endl;//40��������Ϊ4ʱ�����Ϊ32
//	cout << sizeof(A.B) << endl;//24��������Ϊ4ʱ�����Ϊ20
//	cout << sizeof(C) << endl;//12��������Ϊ4ʱ�����Ϊ12
//	cout << sizeof(D) << endl;//12��������Ϊ4ʱ�����Ϊ12
//	cout << sizeof(E) << endl;//12��������Ϊ4ʱ�����Ϊ12
//	//cout << sizeof(E.B) << endl;//����
//}