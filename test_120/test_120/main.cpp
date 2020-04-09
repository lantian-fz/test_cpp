#define _CRT_SECURE_NO_WARNINGS 1
//养兔子
//一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
//输入描述 :测试数据包括多组，每组一行，为整数n(1≤n≤90)。
//输出描述 :对应输出第n天有几只兔子(假设没有兔子死亡现象)。
//输入
//1
//2
//输出
//1
//2

#include <iostream>
using namespace std;

long long fun(int n)
{
	long long a = 1;
	long long b = 1;
	long long c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << fun(n+1) << endl;

	return 0;
}