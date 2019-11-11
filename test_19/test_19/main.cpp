#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

public:
	int getA()
	{
		return this->a;
	}

	int getB()
	{
		return this->b;
	}

	void Print()
	{
		cout << "a = " << this->a << ",b = " << this->b << endl;
	}

	//void AddTest(Test &another)
	//{
	//	this->a += another.a;
	//	this->b += another.b;
	//}

	Test& AddTest(Test &another)
	{
		this->a += another.a;
		this->b += another.b;
		return *this;
	}

private:
	int a;
	int b;
};

//Test AddTest(Test &t1, Test &t2)
//{
//	Test tmp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
//	return tmp;
//}

int main()
{
	Test t1(10, 20);
	Test t2(1, 2);

	//Test t3 = AddTest(t1, t2);
	//t3.Print();

	//t1.AddTest(t2);
	//t1.Print();

	t1.AddTest(t2).AddTest(t2).AddTest(t2);
	t1.Print();
	t1.AddTest(t1).Print();

	return 0;
}