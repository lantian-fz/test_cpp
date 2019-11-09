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

	Test(const Test &another)//�������
	{
		cout << "this" << this << endl;

		m_id = another.m_id;
		m_name = (char*)malloc(strlen(another.m_name) + 1);
		strcpy(m_name, another.m_name);
	}

	~Test()
	{
		cout << "����" << endl;
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
	//Test t2(t1);//ʹ��Ĭ�ϵĿ������췽��  ��ʹ�������  ��Ϊ����ָ��ָ���λ����ͬ
	//��t1������ʱ�����λ���Ѿ��ͷ���һ�Σ�t2���������ͻ��������
	//����취���ṩһ����ʽ��������캯��

	Test t3(t1);
	t3.Print();

	Test t4 = t1;//ͬt3������ͬ ������ÿ������캯��
	t4.Print();

	Test t5;
	t5 = t1;
	t5.Print();
	
	return 0;
}