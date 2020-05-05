#define _CRT_SECURE_NO_WARNINGS 1
//力扣-50.Pow(x, n)
//实现 pow(x, n) ，即计算 x 的 n 次幂函数。
//示例 1:
//输入: 2.00000, 10
//输出: 1024.00000
//
//示例 2:
//输入: 2.10000, 3
//输出: 9.26100
//
//示例 3:
//输入: 2.00000, -2
//输出: 0.25000
//解释: 2^-2 = 1/2^2 = 1/4 = 0.25
//说明: -100.0 < x < 100.0
//      n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。

#include <iostream>
using namespace std;

double myPow_1(double x, int n) //会超市
{
	if (n == 0 || x == 1.0)
		return 1.0;
	double ret = x;
	if (n > 0)
	{
		int count = n;
		while (--count)
			ret *= x;
	}
	else
	{
		int count = -n;
		while (--count)
			ret *= x;
		ret = 1.0 / ret;
	}
	return ret;
}

double fastPow(double x, long long n) 
{
	if (n == 0) 
		return 1.0;
	double half = fastPow(x, n / 2);
	if (n % 2 == 0) 
		return half * half;
	else 
		return half * half * x;
}
double myPow_2(double x, int n) //快速幂算法（递归）
{
	long long N = n;
	if (N < 0) 
	{
		x = 1 / x;
		N = -N;
	}
	return fastPow(x, N);
}

double myPow_3(double x, int n) 
{
	long long N = n;
	if (N < 0) 
	{
		x = 1 / x;
		N = -N;
	}
	double ans = 1;
	double current_product = x;
	for (long long i = N; i; i /= 2) 
	{
		if ((i % 2) == 1) 
			ans = ans * current_product;
		
		current_product = current_product * current_product;
	}
	return ans;
}

double myPow_4(double x, int n) //二分思想递归
{
	if (n == 0)
		return 1.0;
	if (n == 1)
		return x;
	if (n == -1)
		return 1 / x;
	double half = myPow_4(x, n / 2);
	double rest = myPow_4(x, n % 2);
	return rest * half * half;
}

int main()
{
	double x = 0.0;
	int n = 0;
	while (cin >> x >> n)
		cout << myPow_4(x, n) << endl;
	
	return 0;
}