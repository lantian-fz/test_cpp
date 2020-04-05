#define _CRT_SECURE_NO_WARNINGS 1
//因子个数
//一个正整数可以分解成一个或多个数组的积。例如36 = 2 * 2 * 3 * 3，即包含2和3两个因子。
//NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。
//输入描述 :输入包括多组数据。每组数据仅有一个整数n(2≤n≤100000)。
//输出描述 :对应每个整数，输出其因子个数，每个结果占一行。
//输入：30
//      26
//      20
//输出：3
//      2
//      2

#include <iostream>
#include <math.h>
using namespace std;

void NowCoder(int n)
{
	int ret = 0;
	int x = 2;//因子

	while (x<=n)
	{
		if (n%x == 0)
		{
			while (n%x == 0)
				n /= x;
			ret++;
		}
		x++;
	}
	cout << ret << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
		NowCoder(n);
	//for (int i = 2; i < 1000; i++)
	//{
	//	int ret = NowCoder(i);
	//	if (ret>2)
	//		cout << i << " " << ret << endl;
	//}

	return 0;
}