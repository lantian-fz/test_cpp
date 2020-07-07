#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct A
{
	char b;
	int f;

	int a;
	struct B
	{
		char c;
		double d;
		double e;
	};
}A;

void main()
{
	printf("%d\n", sizeof(A));
}

//#include <iostream>
//using namespace std;
//
//struct A
//{
//	int a;
//	char b;
//	struct B
//	{
//		char a;
//		double b;
//		double c;
//	};
//};
//
//void main()
//{
//	cout << sizeof(A) << endl;
//}

//class A
//{
//	A(){}
//	virtual ~A(){}
//};
//
//void main()
//{
//	cout << sizeof(A) << endl;
//}