#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-连续子数组最大和
//输入一个整形数组（可能有正数和负数），求数组中连续子数组（最少有一个元素）的最大和。
//要求时间复杂度为O(n)。
//输入描述 :第一行为数组的长度N（N >= 1）接下来N行，每行一个数，代表数组的N个元素
//输出描述 :最大和的结果

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int max_num = 0;
		int sum = 0;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i == 0)
				max_num = arr[0];
			if (sum <= 0)
				sum = arr[i];
			else
				sum += arr[i];
			if (sum>max_num)
				max_num = sum;
		}
		cout << max_num << endl;
	}

	return 0;
}