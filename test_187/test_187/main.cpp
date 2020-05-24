#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//链接：https://www.nowcoder.com/questionTerminal/3b25d265f6794524af6d8280a1cf6b94
//来源：牛客网

class Base 
{
public:
	Base(int j) : i(j)  {}
	virtual~Base() {}
	void func1() 
	{
		i *= 10;
		func2();
	}
	int getValue() 
	{
		return  i;
	}
protected:
	virtual void func2() 
	{
		i++;
	}
protected:
	int i;
};
class Child : public Base 
{
public:
	Child(int j) : Base(j) {}
	void func1() 
	{
		i *= 100;
		func2();
	}
protected:
	void func2() 
	{
		i += 2;
	}
};
int main() 
{
	Base *pb = new Child(1);
	pb->func1();
	cout << pb->getValue() << endl; 
	delete pb;
	return 0;
}

//class A
//{
//public:
//	virtual void func(int val = 1)
//	{
//		std::cout << "A->" << val << std::endl;
//	}
//	virtual void test()
//	{
//		func();
//	}
//};
//class B : public A
//{
//public:
//	void func(int val = 0)
//	{
//		std::cout << "B->" << val << std::endl;
//	}
//};
//int main()
//{
//	B *p = new B;
//	p->test();
//	return 0;
//}

//class A
//{
//public:
//	A() :m_iVal(0){ test(); }
//	virtual void func() { std::cout << m_iVal << ' '; }
//	void test(){ func(); }
//public:
//	int m_iVal;
//};
//class B : public A
//{
//public:
//	B(){ test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		std::cout << m_iVal << ' ';
//	}
//};
//int main()
//{
//	A*p = new B;
//	p->test();
//	return 0;
//}

