#define _CRT_SECURE_NO_WARNINGS 1
//淘宝网店
//NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
//现在给你一段时间区间，请你帮他计算总收益有多少。
//输入描述 :输入包含多组数据。
//          每组数据包含两个日期from和to(2000 - 01 - 01 ≤ from ≤ to ≤ 2999 - 12 - 31)。
//          日期用三个正整数表示，用空格隔开：year month day。
//输出描述 :对应每一组数据，输出在给定的日期范围（包含开始和结束日期）内能赚多少钱。
//输入
//2000 1 1 2000 1 31
//2000 2 1 2000 2 29
//输出
//62
//29

#include <iostream>
using namespace std;

bool Year(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}

int NumDay(int year1, int month1, int day1,
	int year2, int month2, int day2)
{
	int ret = 0;
	int month[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year1 == year2&&month1 == month2)
	{
		if (month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
			ret += (day2 - day1 + 1);
		else
			ret += (day2 - day1 + 1) * 2;
		return ret;
	}
	if (year1 < year2)//不在同一年的情况
	{
		//先算这一年到年末是多少钱
		if (month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
			ret += (month[month1]-day1 + 1);//月份为素数时每天赚一元
		else
			ret += (month[month1]-day1 + 1) * 2;//否则每天赚两元
		for (int i = month1 + 1; i <= 12; i++)
		{
			if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
				ret += month[i];//月份为素数时每天赚一元
			else
				ret += month[i] * 2;//否则每天赚两元
		}
		if (Year(year1)&& month1<=2 )//如果这一年是闰年再加1元钱
			ret += 1;

		//再计算每年赚多少钱
		for (int i = year1+1; i < year2; i++)
		{
			ret += (28 + 31 + 31 + 31 + 30);
			ret += (31 + 30 + 30 + 31 + 30 + 31 + 31)*2;
			if (Year(i))
				ret += 1;
		}

		//最后计算year2年初到指定日期赚多少钱
		for (int i = 1; i < month2; i++)
		{
			if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
				ret += month[i];//月份为素数时每天赚一元
			else
				ret += month[i] * 2;//否则每天赚两元
			if (Year(year2) && i == 2)
				ret += 1;
		}
		if (month2 == 2 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 11)
			ret += day2;//月份为素数时每天赚一元
		else
			ret += day2 * 2;//否则每天赚两元
	}
	else
	{
		//先算当月能赚多少钱
		if (month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
			ret += (month[month1] - day1 + 1);//月份为素数时每天赚一元
		else
			ret += (month[month1] - day1 + 1) * 2;//否则每天赚两元
		
		//再算中间隔的月份
		for (int i = month1 + 1; i < month2; i++)
		{
			if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
				ret += month[i];//月份为素数时每天赚一元
			else
				ret += month[i] * 2;//否则每天赚两元
		}

		//最后算指定月份能赚多少钱
		if (month2 == 1 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 11)
			ret += day2;//月份为素数时每天赚一元
		else
			ret += day2 * 2;//否则每天赚两元
		if (Year(year1) && month1 <= 2)
			ret += 1;
	}
	return ret;
}

int main()
{
	int year1 = 0, month1 = 0, day1 = 0;
	int year2 = 0, month2 = 0, day2 = 0;
	while (cin >> year1 >> month1 >> day1
		>> year2 >> month2 >> day2)
	{
		cout << NumDay(year1, month1, day1, year2, month2, day2) << endl;
	}

	return 0;
}