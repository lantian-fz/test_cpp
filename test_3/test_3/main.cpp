#include <iostream>
using namespace std;

class Date
{
public:
	//Date()
	//{
	//	year = 2019;
	//	month = 10;
	//	day = 23;
	//}

	Date(int year = 2019, int month = 10, int day = 23)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	void Print();

private:
	int year;
	int month;
	int day;
};

void Date::Print()
{
	cout << year << "/" << month << "/" << day << endl;
}

int main()
{
	//Date d1;//err
	Date d2(2, 3, 5);
	d2.Print();

	system("pause");
	return 0;
}