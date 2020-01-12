#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "A String");
	}
	virtual void Print()
	{
		cout << "AAAAAAAAAA" << endl;
	}
	virtual ~A()
	{
		cout << "~A()" << endl;
		if (this->p != nullptr)
		{
			delete[] this->p;
			this->p = nullptr;
		}
	}
private:
	char *p;
};

class B :public A
{
public:
	B()
	{
		cout << "B()" << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "B String");
	}
	~B()
	{
		cout << "~B()" << endl;
		if (this->p != nullptr)
		{
			delete[] this->p;
			this->p = nullptr;
		}
	}
public:
	virtual void Print()
	{
		cout << "BBBBBBBBBBB" << endl;
	}
private:
	char *p;
};

class C :public B
{
public:
	C()
	{
		cout << "C()" << endl;
		this->p = new char[64];
		memset(this->p, 0, 64);
		strcpy(this->p, "C String");
	}
	~C()
	{
		cout << "~C()" << endl;
		if (this->p != nullptr)
		{
			delete[] this->p;
			this->p = nullptr;
		}
	}
public:
	virtual void Print()
	{
		cout << "CCCCCCCCCCC" << endl;
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
	//A *aa = new A;
	//func(aa);
	//B *bb = new B;
	//func(bb);
	C *cc = new C;
	func(cc);
}

void main()
{
	test();
}