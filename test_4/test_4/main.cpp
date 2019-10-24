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

	system("pause");//此项目为空项目，没有暂停，程序运行太快会一闪而过，析构函数在暂停之后才运行，所以看不到
	return 0;
}

//class Time
//{
//public:
//	//Time()
//	//{
//	//	cout << "调用构造函数  1" << endl;
//	//}
//
//	Time(int hour = 0, int minute = 0, int second = 0)
//	{
//		this->hour = hour;
//		this->minute = minute;
//		this->second = second;
//		cout << "调用构造函数  1" << endl;
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