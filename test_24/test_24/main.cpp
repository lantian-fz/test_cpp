#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Test
{
public:
	Test() :a(0)
	{
		cout << "无参构造" << endl;
	}

	Test(int a)
	{
		cout << "构造" << endl;
		this->a = a;
	}

	~Test()
	{

	}

public:

	void *operator new(size_t size)
	{
		cout << "重载 new " << endl;
		return malloc(size);
	}

	void *operator new[](size_t size)
	{
		cout << "重载 new[]" << endl;
		return malloc(size);
	}

	void operator delete(void *p)
	{
		cout << "重载 delete " << endl;
		if (p != nullptr)
		{
			free(p);
			p = nullptr;
		}
	}

	void operator delete[](void *p)
	{
		cout << "重载 delete[]" << endl;
		if (p != nullptr)
		{
			free(p);
			p = nullptr;
		}
	}

	Test& operator+(const Test &another)
	{
		cout << "调用 + 重载" << endl;

		this->a += another.a;
		return *this;
	}

	bool operator&&(const Test &another)
	{
		cout << "调用 && 重载" << endl;
		if (this->a&&another.a)
		{
			return true;
		}
		else
			return false;
	}

	bool operator||(const Test &another)
	{
		cout << "调用 || 重载" << endl;
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

	//if (t3 && (t3 + t4))//当t3为假时，t3+t4还会运行，不符合&&的逻辑
	//{//这里先运行了t3 + t4，已经改变了t3.a的值，所以运行结果 为真
	//	cout << "为真" << endl;
	//}
	//else
	//	cout << "为假" << endl;

	if (t3 || (t3+t4))//这里先运行了t3 + t4，已经改变了t3.a的值，运行结果也 为真
		cout << "为真" << endl;
	else
		cout << "为假" << endl;
	//所以不要轻易重载 && 和 || 

	return 0;
}