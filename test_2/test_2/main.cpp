#include <iostream>
using namespace std;

class Date
{
public:

	Date()
	{}

	Date(int _year, int _month, int _day)
	{
		this->_year = _year;
		this->_month = _month;
		this->_day = _day;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	void Print();

private:
	int _year;
	int _month;
	int _day;
};

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int main()
{
	//Date d1, d2;

	//d1.SetDate(2018, 5, 1);
	//d1.Display();

	//d2.SetDate(2018, 7, 1);
	//d2.Display();

	//d2.SetDate(2018, 7, 1);
	//d2.Print();

	Date d3; //�����޲ι��캯��
	Date d4(2019, 10, 23);
	d4.Print();

	//ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	//Date d5();//������d5�������ú����޲Σ�����һ���������͵Ķ���

	system("pause");
	return 0;
}