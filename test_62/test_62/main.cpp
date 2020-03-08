#define _CRT_SECURE_NO_WARNINGS 1
//Fibonacci数列
//Fibonacci数列是这样定义的：F[0] = 0; F[1] = 1; for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
//给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
//输入描述:输入为一个正整数N(1 ≤ N ≤ 1,000,000)
//输出描述:输出一个最小的步数变为Fibonacci数"
//输入: 15
//输出: 2
#include <iostream>
using namespace std;

int Fi(int n)//迭代的方法
{
	int a = 0;
	int b = 1;
	//a为n的前一个Fibonacci数，b为后一个
	while (b <= n)
	{
		int c = a + b;
		a = b;
		b = c;
	}
	if (n - a > b - n)
		return b - n;
	else
		return n - a;
}

int main()
{
	int n = 0;
	cin >> n;

	cout << Fi(n) << endl;

	return 0;
}