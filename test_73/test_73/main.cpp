#define _CRT_SECURE_NO_WARNINGS 1
//查找组成一个偶数最接近的两个素数
//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
//输入描述 :输入一个偶数
//输出描述 :输出两个素数
//输入: 20
//输出: 7
//      13
#include <iostream>
using namespace std;

bool PrimeNum(int x)//判断素数
{
	for (int i = 2; i < x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}

void Print(int n)
{
	if (n % 2 == 1 || n <= 2)
		return;
	int half = n / 2;//这两个素数一定在n/2的两边
	while (half)
	{
		if (PrimeNum(half))
		{
			if (PrimeNum(n - half))
			{
				cout << n - half << endl;
				cout << half << endl;
				break;
			}
		}
		half++;
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
		Print(n);

	return 0;
}