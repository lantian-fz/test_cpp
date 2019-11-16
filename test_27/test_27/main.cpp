#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "Parent �޲� ���� " << this << endl;
		this->a = 0;
	}

	Parent(int a)
	{
		cout << "Parent int ���� " << this << endl;
		this->a = a;
	}

	~Parent()
	{
		cout << "~Parent  ���� " << this << endl;
	}
	int getA()
	{
		return a;
	}
	static int x;
//public:
private:
	int a;
};

class Child :public Parent
{
public:
	Child(int a, int b) :Parent(b)
	{
		cout << "Child int int���� " << this << endl;

		this->a = a;//�������ø�����޲ι���
	}
	~Child()
	{
		cout << "~Child  ���� " << this << endl;
	}

public:
	void PrintC()
	{
		cout << "a = " << this->a << endl;
		//cout << Parent::a << endl;//�������ı�����public�еľͿ�����������
		cout << Parent::getA() << endl;
	}
	static int b;

public:
	int a;
};

int Parent::x = 0;
int Child::b = 0;

int main()
{
	Child c1(10, 20);
	c1.PrintC();
	cout << "x = "<< c1.x << endl;

	Parent p1;
	cout << "x = " << p1.x << endl;

	c1.x = 1000;
	cout << "x = " << c1.x << endl;//��������๲��һ��static����
	cout << "x = " << p1.x << endl;

	//p1.b;//�����޷�ʹ�������Լ���static����


	return 0;
}
//--------------------------------------------------------------
//class Parent
//{
//public:
//	Parent()
//	{
//		cout << "Parent �޲� ���� " << this << endl;
//		this->a = 0;
//	}
//
//	Parent(int a)
//	{
//		cout << "Parent int ���� " << this << endl;
//		this->a = a;
//	}
//
//	~Parent()
//	{
//		cout << "~Parent  ���� " << this << endl;
//	}
//
//public:
//	int a;
//};
//
//class Child :public Parent
//{
//public:
//	Child(int a, int b)
//	{
//		cout << "Child int int���� " << this << endl;
//
//		this->a = a;//�������ø�����޲ι���
//		this->b = b;
//	}
//	~Child()
//	{
//		cout << "~Child  ���� " << this << endl;
//	}
//
//public:
//	void PrintC()
//	{
//		cout << "b = " << this->b << endl;
//	}
//
//public:
//	int b;
//};
////Parent �޲� ���� 00AFF8AC
////Child int int���� 00AFF8AC
////b = 20
////~Child  ���� 00AFF8AC
////~Parent  ���� 00AFF8AC
//int main()
//{
//	Child c1(10, 20);
//	c1.PrintC();
//
//	return 0;
//}