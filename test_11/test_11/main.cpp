#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
//#include <stdlib.h>
using namespace std;

class Test
{
public:
	Test()
	{
	}

	Test(int id, char *name)
	{
		cout << "this" << this << endl;
		m_id = id;
		m_name = (char*)malloc(strlen(name) + 1);
		strcpy(m_name, name);
	}

	Test(const Test &another)//深拷贝函数
	{
		cout << "this" << this << endl;

		m_id = another.m_id;
		m_name = (char*)malloc(strlen(another.m_name) + 1);
		strcpy(m_name, another.m_name);
	}

	~Test()
	{
		cout << "析构" << endl;
		cout << "this" << this << endl;

		if (m_name != nullptr)
		{
			free(m_name);
			m_name = nullptr;
		}
	}

public:
	void operator=(const Test &another)
	{
		cout << "operator=  " << endl;
		cout << "this" << this << endl;
		m_id = another.m_id;
		m_name = (char*)malloc(strlen(another.m_name) + 1);
		strcpy(m_name, another.m_name);
	}

public:
	void Print()
	{
		cout << "m_id = " << m_id << "  m_name = " << m_name << endl;
	}

private:
	int m_id;
	char *m_name;
};

int main()
{
	Test t1(1, "abc");

	t1.Print();
	//Test t2(t1);//使用默认的拷贝构造方法  会使程序崩溃  因为两个指针指向的位置相同
	//在t1析构的时候，这个位置已经释放了一次，t2再析构，就会出现问题
	//解决办法，提供一个显式的深拷贝构造函数

	Test t3(t1);
	t3.Print();

	Test t4 = t1;//同t3处的相同 都会调用拷贝构造函数
	t4.Print();

	Test t5;
	t5 = t1;
	t5.Print();
	
	return 0;
}