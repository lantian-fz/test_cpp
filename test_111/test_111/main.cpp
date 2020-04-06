#define _CRT_SECURE_NO_WARNINGS 1
//分解因数
//所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an, 
//并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。
//输入描述 :输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。
//输出描述 :对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。
//输入：10
//      18
//输出：10 = 2 * 5
//      18 = 2 * 3 * 3

#include <iostream>
#include <vector>
using namespace std;

void NowCoder(int n)
{
	int ret = n;
	vector<int> arr;
	int x = 2;//因子

	while (x <= n)
	{
		if (n%x == 0)
		{
			while (n%x == 0)
			{
				n /= x;
				arr.push_back(x);
			}
		}
		x++;
	}
	cout << ret << " = " << arr[0] ;
	for (size_t i = 1; i < arr.size(); i++)
		cout << " * "<< arr[i];
	cout << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
		NowCoder(n);

	return 0;
}