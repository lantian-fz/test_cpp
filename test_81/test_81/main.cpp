#define _CRT_SECURE_NO_WARNINGS 1
//iNOC产品部--完全数计算
//完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
//它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
//例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1 + 2 + 4 + 7 + 14 = 28。
//给定函数count(int n), 用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
//返回n以内完全数的个数。 异常情况返回 - 1
//
//输入描述:输入一个数字
//输出描述 :输出完全数的个数
//输入: 1000
//输出: 3
#include <iostream>
using namespace std;

bool Num(int x)
{
	int num = 0;
	for (int i = x - 1; i>0; i--)
	{
		if (x%i == 0)
			num += i;
	}
	if (num == x)
		return true;
	return false;
}

int count(int n)
{
	if (n<1 || n>500000)
		return -1;
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Num(i))
			ret++;
	}
	return ret;
}
int main()
{
	int n = 0;
	while (cin >> n)
		cout << count(n) << endl;
	return 0;
}
