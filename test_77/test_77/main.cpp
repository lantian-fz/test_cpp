#define _CRT_SECURE_NO_WARNINGS 1
//计算日期到天数转换
//根据输入的日期，计算是这一年的第几天。。
//详细描述：输入某年某月某日，判断这一天是这一年的第几天？。
//输入描述:输入三行，分别是年，月，日
//输出描述 :成功 : 返回outDay输出计算后的第几天;       失败:返回 - 1
//输入: 2012
//	    12
//      31
//输出: 366
#include <iostream>
using namespace std;

int getOutDay(int year,int month,int day)
{
	//0为闰年时2月天数  1月 2月 3月 4月 5月 6月 7月 8月 9月 10月 11月 12月
	int arr[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,  30,  31 };
	int flag = 0;
	//先判断输入是否标准
	if (month<1 || month>12)
		return -1;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		flag = 1;
		if (month == 2)
		{
			if (day > arr[0])
				return -1;
		}
		else if (day > arr[month])
			return -1;
	}
	else if (day > arr[month])
		return -1;
	int num = 0;
	for (int i = 1; i < month; i++)
		num += arr[i];
	num += day;
	if (flag == 1 && month>2)
		return num + 1;
	else
		return num;
}

int main()
{
	int year = 0, month = 0, day = 0;
	while (cin >> year >> month >> day)
		cout << getOutDay(year, month, day) << endl;
	return 0;
}