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
		this->m_a = 100;//thisָ�벻��const Test *���͵ģ����Կ����޸ı�����ֵ
		//this++;//thisָ����һ����ָ�룬������ΪTest * const ����
		return this->m_a;
	}

	int getAA()const  //�ڳ�Ա����β������const �Ϳ�������thisָ�룬ʹ�䲻���޸ı�����ֵ���൱��const Test *const ����
	{
		//this->m_a = 200;
		return this->m_a;
	}

	//��̬��Ա��������������
	static int s_getA()//��̬��Ա��������thisָ��
	{
		//return this->m_a;
		//return m_a;
		return m_b;//��̬��Ա����ֻ�ܷ��ؾ�̬��Ա����
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