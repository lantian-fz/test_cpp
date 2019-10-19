#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdlib.h>
using namespace std;

namespace N1
{
	int a = 1;
	int Add(int x, int y)
	{
		return x + y;
	}
}

namespace N2
{
	int a = 2;
	int b = 20;
	int Sub(int x, int y)
	{
		return x - y;
	}
}

namespace N3
{
	int a = 3;
	int c = 33;
	int Mul(int x, int y)
	{
		return x*y;
	}
}

//using  N1::a;
//using  N2::b;

int Add(int x, int y = 4, int z = 5)
{
	return x + y + z;
}

//double Add(double x, int y = 4, int z = 5)
//{
//	return x + y + z;
//}

//int Add(int x = 3, int y = 4, int z = 5)//这样不算重载
//{
//	return x * y + z;
//}

int& Addd(int a, int b)
{
	int c = a + b;
	//int& x = c;
	//return x;
	return c;
}

int main()
{
	//cout << N1::a << endl;
	//cout << N2::a << endl;
	//cout << N2::b << endl;
	//cout << N2::Sub(5, 2) << endl;
	//cout << a << endl;
	//cout << b << endl;

	//cout << Add(4) << endl;
	////cout << Add(4.1) << endl;
	//cout << Add(5,5,5) << endl;

	//int a = 5;
	//int& p = a;

	//cout << a << endl;
	//cout << p << endl;
	//cout << &a << endl;
	//cout << &p << endl;

	int& tmp = Addd(3, 4);
	Addd(5, 6);

	cout << tmp << endl;

	system("pause");
	return 0;
}