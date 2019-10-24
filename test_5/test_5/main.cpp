#include <iostream>
using namespace std;

class Test
{
public:
	Test(int d = 0) : m_data(d)
	{
		cout << "���캯��" << endl;
	}

	Test(const Test &t)
	{
		cout << "�������캯��" << endl;
		m_data = t.m_data;
	}

	Test& operator=(const Test &t)
	{
		cout << "����" << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}

	~Test()
	{
		cout << "�������� " << this << endl;
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