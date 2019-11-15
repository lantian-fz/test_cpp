#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
	Test(int a)
	{
		cout << "int 构造   this: " << this << endl;
		this->a = a;
	}

	~Test()
	{
		cout << "~Test 析构   this: " << this << endl;
	}

public:
	void Print()
	{
		cout << "a = " << this->a << endl;
	}

private:
	int a;
};

void test1()
{
	Test* t1 = new Test(10);
	t1->Print();
	(*t1).Print();
	delete t1;
}

void test2()
{
	auto_ptr<Test> ptr(new Test(10));
	ptr->Print();
	(*ptr).Print();
	//使用的自动指针，不需要delete内存
}

class my_auto_ptr
{
public:
	my_auto_ptr(Test *ptr)
	{
		cout << "my_auto_ptr 构造   this: " << this << endl;
		this->ptr = ptr;
	}

	~my_auto_ptr()
	{
		cout << "~my_auto_ptr 析构   this: " << this << endl;
		if (this->ptr != nullptr)
		{
			delete this->ptr;
			this->ptr = nullptr;
		}
	}

public:
	Test* operator->()
	{
		return this->ptr;
	}

	Test& operator*()
	{
		return *ptr;
	}

private:
	Test *ptr;
};

void test3()
{
	my_auto_ptr p(new Test(10));
	//p->Print();
	(*p).Print();
}

int main()
{
	//auto_ptr<int> ptr(new int);
	//*ptr = 20;

	//test1();
	//test2();
	test3();

	return 0;
}