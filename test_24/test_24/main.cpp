#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test() :a(0)
	{
		cout << "�޲ι���" << endl;
	}

	Test(int a)
	{
		cout << "����" << endl;
		this->a = a;
	}

	~Test()
	{

	}

public:

	void *operator new(size_t size)
	{
		cout << "���� new " << endl;
		return malloc(size);
	}

	void *operator new[](size_t size)
	{
		cout << "���� new[]" << endl;
		return malloc(size);
	}

	void operator delete(void *p)
	{
		cout << "���� delete " << endl;
		if (p != nullptr)
		{
			free(p);
			p = nullptr;
		}
	}

	void operator delete[](void *p)
	{
		cout << "���� delete[]" << endl;
		if (p != nullptr)
		{
			free(p);
			p = nullptr;
		}
	}

	Test& operator+(const Test &another)
	{
		cout << "���� + ����" << endl;

		this->a += another.a;
		return *this;
	}

	bool operator&&(const Test &another)
	{
		cout << "���� && ����" << endl;
		if (this->a&&another.a)
		{
			return true;
		}
		else
			return false;
	}

	bool operator||(const Test &another)
	{
		cout << "���� || ����" << endl;
		if (this->a || another.a)
			return true;
		else
			return false;
	}

private:
	int a;
};

int main()
{
	//Test *t1 = new Test(10);

	//delete t1; 

	//Test *t2 = new Test[10];
	//delete[] t2;

	Test t3(10);
	Test t4(20);

	//if (t3 && (t3 + t4))//��t3Ϊ��ʱ��t3+t4�������У�������&&���߼�
	//{//������������t3 + t4���Ѿ��ı���t3.a��ֵ���������н�� Ϊ��
	//	cout << "Ϊ��" << endl;
	//}
	//else
	//	cout << "Ϊ��" << endl;

	if (t3 || (t3+t4))//������������t3 + t4���Ѿ��ı���t3.a��ֵ�����н��Ҳ Ϊ��
		cout << "Ϊ��" << endl;
	else
		cout << "Ϊ��" << endl;
	//���Բ�Ҫ�������� && �� || 

	return 0;
}