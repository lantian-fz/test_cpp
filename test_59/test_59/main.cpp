#define _CRT_SECURE_NO_WARNINGS 1
//连续最大和
//一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1, 2, 1]，和最大的连续子数组为[2, 1]，其和为 3
//输入描述:输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素, 每个整数都在32位int范围内。以空格分隔。
//输出描述 :所有连续子数组中和最大的值。
//输入: 3 -1 2 1
//输出: 3
#include <iostream>
#include <vector>
using namespace std;

int Max_Arr(vector<int> arr)
{
	int max = arr[0];
	int num = arr[0];
	if (arr.size() == 1)
		return arr[0];
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (num < 0)
			num = arr[i];
		else
			num += arr[i];
		if (num>max)
			max = num;
	}

	return max;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp; 
		arr.push_back(tmp);
	}
	cout << Max_Arr(arr) << endl;
	return 0;
}