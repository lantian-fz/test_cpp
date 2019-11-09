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
		cout << "Test()  ���캯����" << "_a: " << _a << " _b: " << _b << " _c: " << _c <<" "<< this<<endl;
	}

	~Test()
	{
		cout << "~Test()  ����������" << "_a: " << _a << " _b: " << _b << " _c: " << _c <<" "<< this<< endl;
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
		cout << "MyD() ���� " << this<< endl;
	}

	MyE(const MyE & obj) :t1(7, 8, 9), t2(10, 11, 12), m(100)
	{
		cout << "MyD(const MyD & obj) ���� " << this<< endl;
	}

	~MyE()
	{
		cout << "~MyD() ���� " << this<< endl;
	}

public:
	Test t1;
	Test t2;
	const int m;
};

int doThing(MyE myel)
{
	cout << "����doThing() myel.t1.a = " << myel.t1.getA() << endl;
	return 0;
}

int fun()
{
	MyE my_e;
	doThing(my_e);
	return 0;

	//Test()  ���캯����_a: 1 _b : 2 _c : 3 0050FB4C  ����my_e�е�t1
	//Test()  ���캯����_a : 4 _b : 5 _c : 6 0050FB58 ����my_e�е�t2
	//MyD() ���� 0050FB4C ����my_e 
	//Test()  ���캯����_a : 7 _b : 8 _c : 9 0050FA40  ��������myel�е�t1
	//Test()  ���캯����_a : 10 _b : 11 _c : 12 0050FA4C ��������myel�е�t2
	//MyD(const MyD & obj) ���� 0050FA40 ���������myel
	//����doThing() myel.t1.a = 7
	//~MyD() ���� 0050FA40 ���������������myel
	//~Test()  ����������_a : 10 _b : 11 _c : 120050FA4C ������������myel�е�t2
	//~Test()  ����������_a : 7 _b : 8 _c : 90050FA40 ������������myel�е�t1
	//~MyD() ���� 0050FB4C ����my_e
	//~Test()  ����������_a : 4 _b : 5 _c : 60050FB58 ����my_e�е�t2
	//~Test()  ����������_a : 1 _b : 2 _c : 30050FB4C ����my_e�е�t1
}

int fun2()
{
	cout << "fun2 ��ʼ" << endl;
	Test(400, 500, 600); //�����ĺ�������������������
	cout << "fun2 ����" << endl;
	return 0;
	//fun2 ��ʼ
	//Test()  ���캯����_a: 400 _b : 500 _c : 600 00B5FA90
	//~Test()  ����������_a : 400 _b : 500 _c : 600 00B5FA90
	//fun2 ����
}

int fun3()
{
	cout << "fun2 ��ʼ" << endl;
	Test t1 = Test(400, 500, 600); //��������������������Ϊt1
	cout << "fun2 ����" << endl;
	return 0;
}

int main()
{
	//fun();
	//fun2();
	fun3();

	return 0;
}