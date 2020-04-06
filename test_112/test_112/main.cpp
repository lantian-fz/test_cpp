#define _CRT_SECURE_NO_WARNINGS 1
//美国节日
//和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
//* 1月1日：元旦
//* 1月的第三个星期一：马丁·路德·金纪念日
//* 2月的第三个星期一：总统节
//* 5月的最后一个星期一：阵亡将士纪念日
//* 7月4日：美国国庆
//* 9月的第一个星期一：劳动节
//* 11月的第四个星期四：感恩节
//* 12月25日：圣诞节
//现在给出一个年份，请你帮忙生成当年节日的日期。
//输入描述 :输入包含多组数据，每组数据包含一个正整数year（2000≤year≤9999）。
//输出描述 :对应每一组数据，以“YYYY - MM - DD”格式输出当年所有的节日日期，每个日期占一行。
//          每组数据之后输出一个空行作为分隔。
//输入
//2014
//2013
//输出
//2014-01-01
//2014-01-20
//2014-02-17
//2014-05-26
//2014-07-04
//2014-09-01
//2014-11-27
//2014-12-25
//
//2013-01-01
//2013-01-21
//2013-02-18
//2013-05-27
//2013-07-04
//2013-09-02
//2013-11-28
//2013-12-25

#include <iostream>
#include <string>
using namespace std;

string Festival(int year, int month,int day, int num, int count, bool flag = true)
{
	if (month == 1)
	{
		month = 13;
		year--;
	}
	if (month == 2)
	{
		month = 14;
		year--;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			day++;
	}
	int week = 0;
	int k = 0;
	int i = 0;
	if (flag)
	{
		for (i = 1; i <= day; i++)
		{
			week = (i + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
			if (week + 1 == count)
				k++;
			if (k == num)
				break;
		}
	}
	else
	{
		for (i = day; i >=1; i--)
		{
			week = (i + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
			if (week + 1 == count)
				k++;
			if (k == num)
				break;
		}
	}
	string s;
	if (i < 10)
	{
		s += '0';
		s += to_string(i);//把val转换成string
	}
	else
	{
		s = to_string(i);//把val转换成string
	}
	return s;
}

int main()
{
	int year = 0;
	//0为闰年时2月天数   1月 2月 3月 4月 5月 6月 7月 8月 9月 10月 11月 12月
	int month[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year)
	{
		cout << year << "-" << "01" << "-" << "01" << endl;
		cout << year << "-" << "01" << "-" << Festival(year, 1,month[1], 3, 1) << endl;//1月的第3个星期一
		cout << year << "-" << "02" << "-" << Festival(year, 2,month[2], 3, 1) << endl;//2月的第3个星期一
		cout << year << "-" << "05" << "-" << Festival(year, 5,month[5], 1, 1,false) << endl;//5月的最后一个星期一
		cout << year << "-" << "07" << "-" << "04" << endl;
		cout << year << "-" << "09" << "-" << Festival(year, 9,month[9], 1, 1) << endl;//9月的第1个星期一
		cout << year << "-" << "11" << "-" << Festival(year, 11,month[11], 4, 4) << endl;//11月的第4个星期四
		cout << year << "-" << "12" << "-" << "25" << endl;
		cout << endl;//不加这个牛客通不过emmm
	}

	return 0;
}