#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
//#include <math.h>
using namespace std;

class Complex
{
public:
	Complex() :a(0), b(0)
	{}

	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	} 

public:
	void Print()
	{
		cout << this->a << " + " << this->b << "i" << endl;
	}

	//Complex& operator+(const Complex &another) //这样是错的，返回引用的话，tmp已经析构，无法再使用
	Complex operator+(const Complex &another)
	{
		Complex tmp;
		tmp.a = this->a + another.a;
		tmp.b = this->b + another.b;
		//this->a += another.a;
		//this->b += another.b;
		return tmp;
	}

private:
	int a;
	int b;
};

int main()
{
	Complex c1(10, 20);
	Complex c2(2, 2);

	Complex c3 = c1 + c2;
	c1.Print();
	c2.Print();

	c3.Print();

	Complex c4 = c1 + c2 + c3;
	c4.Print();


	return 0;
}

//class Test
//{
//	friend double TestDistance(Test &t1, Test &t2);//求两点之间的距离
//	
//public:
//	Test(int x, int y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//
//public:
//	int getX()
//	{
//		return this->x;
//	}
//	int getY()
//	{
//		return this->y;
//	}
//
//private:
//	int x;
//	int y;
//};
//
//double TestDistance(Test &t1, Test &t2)//求两点之间的距离
//{
//	double dis = 0.0;
//	int x = t1.x - t2.x;
//	int y = t1.y - t2.y;
//	dis = sqrt(x*x + y*y);
//	return dis;
//}
//
////double TestDistance(Test &t1, Test &t2)//求两点之间的距离
////{
////	double dis = 0.0;
////	int x = t1.getX() - t2.getX();
////	int y = t1.getX() - t2.getY();
////	dis = sqrt(x*x + y*y);
////	return dis;
////}
//
//int main()
//{
//	Test t1(1, 3);
//	Test t2(1, 5);
//
//	cout << TestDistance(t1, t2) << endl;
//
//	return 0;
//}