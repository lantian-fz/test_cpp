#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-和为S的两个数字
//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
//如果有多对数字的和等于S，输出两个数的乘积最小的。
//对应每个测试案例，输出两个数，小的先输出。

#include <iostream>
#include <vector>
using namespace std;

//双指针
vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	if (array.empty())
		return array;
	int left = 0;
	int right = array.size() - 1;
	vector<int> ret;
	while (left < right)
	{
		int n = array[left] + array[right];
		if (n>sum)
			right--;
		else if (n < sum)
			left++;
		else
		{
			ret.push_back(array[left]);
			ret.push_back(array[right]);
			return ret;
		}
	}
	return ret;
}

void main()
{
	vector<int> arr = { 1, 2, 4, 7, 11, 15 };
	vector<int> arr2 = FindNumbersWithSum(arr, 15);
	for (auto e : arr2)
		cout << e << " ";
	cout << endl;
}