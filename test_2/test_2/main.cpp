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

	Date d3; //调用无参构造函数
	Date d4(2019, 10, 23);
	d4.Print();

	//注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	//Date d5();//声明了d5函数，该函数无参，返回一个日期类型的对象

	system("pause");
	return 0;
}