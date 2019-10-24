#include <iostream>
using namespace std;

class Test
{
public:
	Test(int d = 0) : m_data(d)
	{
		cout << "构造函数" << endl;
	}

	Test(const Test &t)
	{
		cout << "拷贝构造函数" << endl;
		m_data = t.m_data;
	}

	Test& operator=(const Test &t)
	{
		cout << "重载" << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}

	~Test()
	{
		cout << "析构函数 " << this << endl;
	}

private:
	int m_data;
};

int main()
{
	Test a1;
	Test a2(2);
	//a1 = a2;
	Test a3(a1);

	return 0;
}