#define _CRT_SECURE_NO_WARNINGS 1
//牛客-数值的整数次方-剑指offer-11
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//保证base和exponent不同时为0，不得使用库函数，同时不需要考虑大数问题

#include <iostream>
using namespace std;

//剑指offer答案，但未通过牛客,没有考虑exponent为负数的情况
double Power(double base, int exponent) 
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double ret = Power(base, exponent >> 1);//>>相当于除2，但效率更高
	ret *= ret;
	if ((exponent & 1) == 1)//判断奇偶，比取模速度更快
		ret *= base;
	return ret;
}

double Power_2(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	bool flag = false;
	if (exponent < 0)
	{
		exponent = -exponent;
		flag = true;
	}
	double ret = 1.0f;
	for (int i = 0; i < exponent; i++)
		ret *= base;
	if (flag)
		ret = 1 / ret;
	return ret;
}
void main()
{
	double num = 3.14f;
	cout << Power_2(num, -2) << endl;
}