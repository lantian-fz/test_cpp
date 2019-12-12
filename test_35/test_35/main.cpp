#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
public:
	void Print(int a)
	{
		cout << "aaaaaaaaaaaaaaa" << endl;
	}
	void Print(int a, int b)
	{
		cout << "aaaaaaaaabbbbbbbbb" << endl;
	}
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int a, int b) :Parent(a)
	{
		this->b = b;
	}
public:
	void Print(int a)
	{
		cout << "AAAAAAAAAAAAAA" << endl;
	}
	void Print(int a, int b)
	{
		cout << "AAAAAAABBBBBBBBBBB" << endl;
	}
private:
	int b;
};

void fun(Parent *p)
{
	p->Print(10);
}

int main()
{
	Parent *p1 = new Parent(10);
	Parent *p2 = new Child(100,200);
	Child *c = new Child(10, 20);

	cout << p1 << endl;
	cout << p2 << endl;

	//fun(p1);
	//p2->Print(30);
	//p1->Print(2, 6);
	//p2->Print(3, 4);
	//c->Print(2, 6);
	//fun(p2);
	//fun(c);

	return 0;
}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()的构造函数" << endl;
//		this->p = new char[64];
//		memset(this->p, 0, 64);
//		strcpy(this->p, "AAAAAAAAAAAA");
//	}
//
//	virtual ~A()
//	{
//		cout << "~A()析构函数" << endl;
//		if (this->p != nullptr)
//		{
//			delete[] this->p;
//			this->p = nullptr;
//		}
//	}
//public:
//	virtual void Print()
//	{
//		cout << "A: " << this->p << endl;
//	}
//private:
//	char *p;
//};
//
//class B :public A
//{
//public:
//	B()
//	{
//		cout << "B()的构造函数" << endl;
//		this->p = new char[64];
//		memset(this->p, 0, 64);
//		strcpy(this->p, "BBBBBB");
//	}
//
//	~B()
//	{
//		cout << "~B的析构函数" << endl;
//		if (this->p != nullptr)
//		{
//			delete[] this->p;
//			this->p = nullptr;
//		}
//	}
//public:
//	virtual void Print()
//	{
//		cout << "B: " << this->p << endl;
//	}
//	
//private:
//	char *p;
//};
//
//void func(A *ap)
//{
//	ap->Print();
//	delete ap; 
//}
//
//void test()
//{
//	//A *a = new A();
//	//func(a);
//	//delete a;
//
//	B *b = new B();
//	func(b);
//	//delete b;
//	//delete b;
//	//delete b;
//	//A a;
//	//B b;
//	//func(&a);
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}