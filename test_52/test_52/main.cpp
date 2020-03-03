#define _CRT_SECURE_NO_WARNINGS 1
//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A, 
//他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他 最少 可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2
//输入描述 :输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)
//          第二行包括n个整数A_i(1 ≤ A_i ≤ 10 ^ 9), 表示数组A的每个数字。
//输出描述 :输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
//输入
//6
//1 2 3 2 2 1
//输出 2
#include <iostream>
#include <vector>
using namespace std;
//思路:判断每段子序列的第二个数比第一个数大还是小来确定是否连续
size_t Estimate(vector<long> arr)
{
	size_t num = 1;//子序列数量，本身算一段
	int count = 0;//判断是否连续
	for (size_t i = 1; i < arr.size(); i++)
	{

		if (arr[i] > arr[i - 1])
		{
			if (count == 0)
				count = 1;
			if (count == -1)
			{
				count = 0;
				num++;
			}
		}
		else if (arr[i] < arr[i - 1])
		{
			if (count == 0)
				count = -1;
			if (count == 1)
			{
				count = 0;
				num++;
			}
		}
	}

	return num;
}

int main()
{
	size_t n = 0;
	cin >> n;
	vector<long> arr;
	for (size_t i = 0; i < n; i++)
	{
		long count = 0;
		cin >> count;
		arr.push_back(count);
	}

	cout << Estimate(arr) << endl;

	return 0;
}