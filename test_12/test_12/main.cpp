#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
	{
		cout << "A 的构造 " << this << endl;
		m_a = a;
	}

	~A()
	{
		cout << "A 的析构 " << this << endl;
	}
public:
	void Print()
	{
		cout << "m_a = " << m_a << endl;
	}

private:
	int m_a;
};

class B
{
public:
	B(int b, A &a1, A &a2) :m_a1(a1), m_a2(a2)//这里是拷贝构造
	{
		cout << "B 的构造 " << this << endl;

		m_b = b;
	}

	//构造对象成员的顺序和初始化列表的顺序无关，和对象的定义
	B(int b, int a1, int a2) :m_a1(a1), m_a2(a2)
	{
		cout << "B 的int int int 构造 " << this << endl;
		m_b = b;
	}

	~B()
	{
		cout << "B 的析构 " << this << endl;
	}

public:
	void Print()
	{
		cout << "m_b = " << m_b << endl;
		m_a1.Print();
		m_a2.Print();
	}

private:
	int m_b;
	A m_a1;
	A m_a2;
};

class ABC
{
public:
	ABC(int a, int b, int c)
	{
		cout << "构造ABC " << this << endl;
		m_a = a;
		m_b = b;
		m_c = c;
	}

	ABC(const ABC &another)
	{
		cout << "ABC 的拷贝构造 " << this << endl;
		m_a = another.m_a;
		m_b = another.m_b;
		m_c = another.m_c;
	}

	~ABC()
	{
		cout << "ABC 析构 " << this << endl;
	}

private:
	int m_a;
	int m_b;
	int m_c;
};

class ABCD
{
public:
	ABCD(int a, int b, int c, int d) :m_abc(a, b, c), m_d(d)
	{
		cout << "构造int int int " << this << endl;
	}

	ABCD(ABC &abc, int d) :m_abc(abc)
	{
		cout << "构造 int " << this << endl;
		m_d = d;
	}

	~ABCD()
	{
		cout << "ABCD 析构" << this << endl;
	}

private:
	int m_d;
	ABC m_abc;
};

void test1()
{
	A a1(10);
	A a2(20);

	B b1(100, a1, a2);
	b1.Print();
	//A 的构造 0133F9C0 构造a1
	//A 的构造 0133F9B4 构造a2
	//B 的构造 0133F9A0 构造b1
	//m_b = 100
	//m_a = 10
	//m_a = 20
	//B 的析构 0133F9A0 析构b1
	//A 的析构 0133F9A8 析构m_a2
	//A 的析构 0133F9A4 析构m_a1
	//A 的析构 0133F9B4 析构a2
	//A 的析构 0133F9C0 析构a1
}

void test2()
{
	B b1(10, 20, 30);
	//A 的构造 006FF898 构造m_a1
	//A 的构造 006FF89C 构造m_a2
	//B 的int int int 构造 006FF894 构造b1
	//B 的析构 006FF894 析构b1
	//A 的析构 006FF89C 析构m_a2
	//A 的析构 006FF898 析构m_a1
}

void test3()
{
	ABC abc1(10, 20, 30);

	ABCD abcd1(1, 2, 3, 4);

	ABCD abcd2(abc1, 40);
	//构造ABC 00BFF9BC 构造abc1
	//构造ABC 00BFF9A8 开始构造abcd1 构造abcd1里面的m_abc
	//构造int int int 00BFF9A4  构造abcd1
	//ABC 的拷贝构造 00BFF990  开始构造abcd2 将abc1拷贝构造给m_abc
	//构造 int 00BFF98C 构造abcd2
	//ABCD 析构00BFF98C 析构abcd2
	//ABC 析构 00BFF990 析构拷贝构造的m_abc
	//ABCD 析构00BFF9A4 析构abcd1
	//ABC 析构 00BFF9A8 析构m_abc
	//ABC 析构 00BFF9BC 析构abc1
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}