#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
		cout << "Test()  构造函数：" << "_a: " << _a << " _b: " << _b << " _c: " << _c <<" "<< this<<endl;
	}

	~Test()
	{
		cout << "~Test()  析构函数：" << "_a: " << _a << " _b: " << _b << " _c: " << _c <<" "<< this<< endl;
	}

public:
	int getA()
	{
		return _a;
	}

private:
	int _a;
	int _b;
	int _c;
};

class MyE
{
public:
	MyE() :t1(1, 2, 3), t2(4, 5, 6), m(100)
	{
		cout << "MyD() 构造 " << this<< endl;
	}

	MyE(const MyE & obj) :t1(7, 8, 9), t2(10, 11, 12), m(100)
	{
		cout << "MyD(const MyD & obj) 构造 " << this<< endl;
	}

	~MyE()
	{
		cout << "~MyD() 析构 " << this<< endl;
	}

public:
	Test t1;
	Test t2;
	const int m;
};

int doThing(MyE myel)
{
	cout << "调用doThing() myel.t1.a = " << myel.t1.getA() << endl;
	return 0;
}

int fun()
{
	MyE my_e;
	doThing(my_e);
	return 0;

	//Test()  构造函数：_a: 1 _b : 2 _c : 3 0050FB4C  构造my_e中的t1
	//Test()  构造函数：_a : 4 _b : 5 _c : 6 0050FB58 构造my_e中的t2
	//MyD() 构造 0050FB4C 构造my_e 
	//Test()  构造函数：_a : 7 _b : 8 _c : 9 0050FA40  拷贝构造myel中的t1
	//Test()  构造函数：_a : 10 _b : 11 _c : 12 0050FA4C 拷贝构造myel中的t2
	//MyD(const MyD & obj) 构造 0050FA40 拷贝构造的myel
	//调用doThing() myel.t1.a = 7
	//~MyD() 析构 0050FA40 先析构拷贝构造的myel
	//~Test()  析构函数：_a : 10 _b : 11 _c : 120050FA4C 析构拷贝构造myel中的t2
	//~Test()  析构函数：_a : 7 _b : 8 _c : 90050FA40 析构拷贝构造myel中的t1
	//~MyD() 析构 0050FB4C 析构my_e
	//~Test()  析构函数：_a : 4 _b : 5 _c : 60050FB58 析构my_e中的t2
	//~Test()  析构函数：_a : 1 _b : 2 _c : 30050FB4C 析构my_e中的t1
}

int fun2()
{
	cout << "fun2 开始" << endl;
	Test(400, 500, 600); //匿名的函数，调用完立即析构
	cout << "fun2 结束" << endl;
	return 0;
	//fun2 开始
	//Test()  构造函数：_a: 400 _b : 500 _c : 600 00B5FA90
	//~Test()  析构函数：_a : 400 _b : 500 _c : 600 00B5FA90
	//fun2 结束
}

int fun3()
{
	cout << "fun2 开始" << endl;
	Test t1 = Test(400, 500, 600); //不会立即析构，对象名为t1
	cout << "fun2 结束" << endl;
	return 0;
}

int main()
{
	//fun();
	//fun2();
	fun3();

	return 0;
}