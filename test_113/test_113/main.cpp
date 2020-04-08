#define _CRT_SECURE_NO_WARNINGS 1
//斐波那契凤尾
//NowCoder号称自己已经记住了1 - 100000之间所有的斐波那契数。
//为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。
//因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。
//输入描述 :输入有多组数据。每组数据一行，包含一个整数n(1≤n≤100000)。
//输出描述 :对应每一组输入，输出第n个斐波那契数的最后6位。
//输入
//1
//2
//3
//4
//100000
//输出
//1
//2
//3
//5
//537501
#include <iostream>
#include <iomanip>
using namespace std;

int fi(int n)//不行，牛客上运行超时
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = (a+b)%1000000;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	int arr[100001] = { 1, 1 };//用空间换时间
	for (int i = 2; i < 100001; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	while (cin >> n)
	{
		if (n < 29)
			cout << arr[n] << endl;
		else
			cout << setw(6) << setfill('0') << arr[n] << endl;//不足6位补0
	}
		
	return 0;
}