#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()�Ĺ��캯��" << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "AAAAAAAAAAAA");
	}

	~A()
	{
		cout << "~A()��������" << endl;
		if (this->p != nullptr)
		{
			delete[] this->p;
			this->p = nullptr;
		}
	}
public:
	virtual void Print()
	{
		cout << "A: " << this->p << endl;
	}
private:
	char *p;
};

class B :public A
{
public:
	B()
	{
		cout << "B()�Ĺ��캯��" << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "BBBBBB");
	}

	~B()
	{
		cout << "~B����������" << endl;
		if (this->p != nullptr)
		{
			delete[] this->p;
			this->p = nullptr;
		}
	}
public:
	virtual void Print()
	{
		cout << "B: " << this->p << endl;
	}
	
private:
	char *p;
};

void func(A *ap)
{
	ap->Print();
	delete ap; 
}

void test()
{
	//A *a = new A();
	//func(a);
	//delete a;

	B *b = new B();
	func(b);
	//delete b;
	//delete b;
	//A a;
	//B b;
	//func(&a);
}

int main()
{
	test();

	return 0;
}