#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
////#pragma pack(4)
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
//	cout << sizeof(A.B) << endl;//24��������Ϊ4ʱ�����Ϊ32
//	cout << sizeof(C) << endl;//12��������Ϊ4ʱ�����Ϊ32
//	cout << sizeof(D) << endl;//12��������Ϊ4ʱ�����Ϊ32
//	cout << sizeof(E) << endl;//12��������Ϊ4ʱ�����Ϊ32
//	//cout << sizeof(E.B) << endl;//����
//}

#include <stdio.h>
struct A
{
	char a;
	int b;
	int c;
	struct B
	{
		char d;
		double e;
		double f;
	}B;
}A;

struct E
{
	char a;
	int b;
	int c;
	struct F
	{
		char d;
		double e;
		double f;
	};
}E;

struct C
{
	char a;
	int b;
	int d;
}C;
struct D
{
	char a;
	int b;
	int d;
};

void main()
{
	
	printf("%d\n", sizeof(A));//40
	printf("%d\n", sizeof(A.B));//24
	printf("%d\n", sizeof(C));//12
	printf("%d\n", sizeof(struct D));//12
	printf("%d\n", sizeof(E));//12
	//printf("%d\n", sizeof(E.F));//����
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