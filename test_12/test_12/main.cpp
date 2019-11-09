#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
	{
		cout << "A �Ĺ��� " << this << endl;
		m_a = a;
	}

	~A()
	{
		cout << "A ������ " << this << endl;
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
	B(int b, A &a1, A &a2) :m_a1(a1), m_a2(a2)//�����ǿ�������
	{
		cout << "B �Ĺ��� " << this << endl;

		m_b = b;
	}

	//��������Ա��˳��ͳ�ʼ���б��˳���޹أ��Ͷ���Ķ���
	B(int b, int a1, int a2) :m_a1(a1), m_a2(a2)
	{
		cout << "B ��int int int ���� " << this << endl;
		m_b = b;
	}

	~B()
	{
		cout << "B ������ " << this << endl;
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
		cout << "����ABC " << this << endl;
		m_a = a;
		m_b = b;
		m_c = c;
	}

	ABC(const ABC &another)
	{
		cout << "ABC �Ŀ������� " << this << endl;
		m_a = another.m_a;
		m_b = another.m_b;
		m_c = another.m_c;
	}

	~ABC()
	{
		cout << "ABC ���� " << this << endl;
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
		cout << "����int int int " << this << endl;
	}

	ABCD(ABC &abc, int d) :m_abc(abc)
	{
		cout << "���� int " << this << endl;
		m_d = d;
	}

	~ABCD()
	{
		cout << "ABCD ����" << this << endl;
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
	//A �Ĺ��� 0133F9C0 ����a1
	//A �Ĺ��� 0133F9B4 ����a2
	//B �Ĺ��� 0133F9A0 ����b1
	//m_b = 100
	//m_a = 10
	//m_a = 20
	//B ������ 0133F9A0 ����b1
	//A ������ 0133F9A8 ����m_a2
	//A ������ 0133F9A4 ����m_a1
	//A ������ 0133F9B4 ����a2
	//A ������ 0133F9C0 ����a1
}

void test2()
{
	B b1(10, 20, 30);
	//A �Ĺ��� 006FF898 ����m_a1
	//A �Ĺ��� 006FF89C ����m_a2
	//B ��int int int ���� 006FF894 ����b1
	//B ������ 006FF894 ����b1
	//A ������ 006FF89C ����m_a2
	//A ������ 006FF898 ����m_a1
}

void test3()
{
	ABC abc1(10, 20, 30);

	ABCD abcd1(1, 2, 3, 4);

	ABCD abcd2(abc1, 40);
	//����ABC 00BFF9BC ����abc1
	//����ABC 00BFF9A8 ��ʼ����abcd1 ����abcd1�����m_abc
	//����int int int 00BFF9A4  ����abcd1
	//ABC �Ŀ������� 00BFF990  ��ʼ����abcd2 ��abc1���������m_abc
	//���� int 00BFF98C ����abcd2
	//ABCD ����00BFF98C ����abcd2
	//ABC ���� 00BFF990 �������������m_abc
	//ABCD ����00BFF9A4 ����abcd1
	//ABC ���� 00BFF9A8 ����m_abc
	//ABC ���� 00BFF9BC ����abc1
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}