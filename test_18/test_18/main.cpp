#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a)
	{
		this->m_a = a;
	}

public:
	int getA()
	{
		this->m_a = 100;//this指针不是const Test *类型的，所以可以修改变量的值
		//this++;//this指针是一个常指针，其类型为Test * const 类型
		return this->m_a;
	}

	int getAA()const  //在成员函数尾部加上const 就可以修饰this指针，使其不能修改变量的值，相当于const Test *const 类型
	{
		//this->m_a = 200;
		return this->m_a;
	}

	//静态成员函数属于整个类
	static int s_getA()//静态成员函数不传this指针
	{
		//return this->m_a;
		//return m_a;
		return m_b;//静态成员函数只能返回静态成员变量
	}

private:
	int m_a;
	static int m_b;
};

int Test::m_b = 0;

int main()
{
	Test t1(10);

	cout<<"a = "<< t1.getA() <<endl;

	return 0;
}