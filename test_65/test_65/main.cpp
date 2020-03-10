#define _CRT_SECURE_NO_WARNINGS 1
//求最小公倍数
//正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
//输入描述 :输入两个正整数A和B。
//输出描述 :输出A和B的最小公倍数。
//输入: 5 7
//输出: 35
#include <iostream>
using namespace std;

int main()
{
	size_t a = 0;
	size_t b = 0;
	cin >> a >> b;
	int i = a;
	while (i)
	{
		if (i%a == 0 && i%b == 0)
			break;
		i++;
	}
	cout << i << endl;

	return 0;
}