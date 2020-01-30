#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//C++中的类型转换
void test1()
{
	int a = 65;
	char c = static_cast<char>(a);
	cout << c << endl;
	//static_cast 用于转换内置的数据类型，还有具有继承关系的指针或引用
	//既可以父类转子类，也可以子类转父类


	//dynamic_cast 转换具有继承关系的指针或引用，在转换前会进行类型检查，
	//即子类指针可以转换为父类指针，父类指针不可以转换为子类指针（不安全）
	//不能转换基础数据类型

	//const_cast   //主要针对const的转换

	//reinterpret_cast //强制类型转换
}

int divide(int x, int y)
{
	if (y == 0)
	{
		throw y;//抛异常
	}
	return x / y;
}

void test2()
{
	try //试着去捕获异常
	{
		divide(10, 0);
	}
	catch (int e)  //异常时根据类型进行匹配
	{
		cout << "除数为" << e << endl;
	}
}

void Div(int x, int y)
{
	divide(x, y);
}

void test3()//异常会往上层函数抛异常，如果异常抛到最顶层还没有处理，程序就会挂掉
{
	try
	{
		Div(10, 0);
	}
	catch (int e)
	{
		cout << "除数为" << e << endl;
	}
	catch (...)//可以匹配所以异常的数据类型
	{

	}
}

void main()
{
	//test1();
	//test2();
	test3();
}