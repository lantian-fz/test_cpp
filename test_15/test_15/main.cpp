#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		cout << "构造 " << this << endl; 
		m_a = a;
		m_b = b;
	}

	~Test()
	{
		cout << "析构 " << this << endl;
	}

public:
	void Print()
	{
		cout << "m_a = " << m_a << " m_b = " << m_b << endl;
	}

private:
	int m_a;
	int m_b;
};

void test1()
{
	int *q = (int *)malloc(sizeof(int)* 10);
	int *p = new int[10];
	for (int i = 0; i < 10; i++)
		p[i] = i;
	for (int i = 0; i < 10; i++)
		cout << p[i] << " ";
	cout << endl;

	if (p != nullptr)
	{
		delete[] p;//new 的空间可以用delete和free来释放
		//free(p);
		p = nullptr;
	}
	if (q != nullptr)
	{
		delete[] q;//malloc的空间可以用delete和free来释放
		//free(q);
		q = nullptr;
	}
}

void test2()
{
	Test *p = (Test*)malloc(sizeof(Test));
	p->Print();//无法触发构造函数
	if (p != nullptr)
	{
		free(p);
		p = nullptr;
	}

	cout << "------------------------------" << endl;

	Test *q = new Test(10, 20);
	q->Print();
	if (q != nullptr)
	{
		delete q;
		q = nullptr;
	}
}

int main()
{
	//test1();
	test2();

	return 0;
}