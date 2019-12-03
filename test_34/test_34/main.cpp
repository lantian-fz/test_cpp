#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A(string str)
	{
		this->str = str;
	}
	virtual void Print()
	{
		cout << "姓名1111" << "，是" << this->str << endl;
	}
//private:
	string str;
};

class B:public A
{
public:
	B(string str) :A(str)
	{

	}
	void Print()
	{
		cout << "姓名2222" << "，是" << this->str << endl;
	}

};

void test(A *t)
{
	cout << "调用了test" << endl;
	t->Print();
}
//1.没在父类Print()前面加virtual
//调用了test
//姓名1111，是AAAAAA
//调用了test
//姓名1111，是BBBBBB   本应该是：姓名2222，是BBBBBB，但这里没有调用子类的方法

//2.在父类Print()前面加virtual
//调用了test
//姓名1111，是AAAAAA
//调用了test
//姓名2222，是BBBBBB
int main()
{
	A *a = new A("AAAAAA");
	//a->Print();
	//delete a;

	B *b = new B("BBBBBB");
	//b->Print();
	//delete b;
	test(a);
	test(b);

	return 0;
}