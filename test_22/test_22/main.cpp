#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
	friend ostream& operator<<(ostream &out, Test &t);

public:
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	~Test()
	{}

public:
	void Print()
	{
		cout << "a = " << this->a << ",b = " << this->b << endl;
	}

	Test& operator++(int)
	{
		this->a++;
		this->b++;
		return *this;
	}

	Test& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}

	//ostream& operator<<(ostream &out)
	//{
	//	out << "a = " << this->a << ",b = " << this->b;
	//	return out;
	//}

private:
	int a;
	int b;
};

ostream& operator<<(ostream &out,Test &t)
{
	out << "a = " << t.a << ",b = " << t.b ;
	return out;
}

int main()
{
	Test t1(10, 20);
	//t1++++++;
	++++t1;

	t1.Print();

	cout << t1 << t1 << t1 << endl;
	//t1 << cout;

	return 0;
}