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

	system("pause");//����ĿΪ����Ŀ��û����ͣ����������̫���һ��������������������֮ͣ������У����Կ�����
	return 0;
}

//class Time
//{
//public:
//	//Time()
//	//{
//	//	cout << "���ù��캯��  1" << endl;
//	//}
//
//	Time(int hour = 0, int minute = 0, int second = 0)
//	{
//		this->hour = hour;
//		this->minute = minute;
//		this->second = second;
//		cout << "���ù��캯��  1" << endl;
//	}
//
//private:
//	int hour;
//	int minute;
//	int second;
//	int *h;
//};
//
//int main()
//{
//	Time a1;
//	Time a2(11, 3);
//
//	system("pause");
//	return 0;
//}