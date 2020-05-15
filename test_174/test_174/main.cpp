#define _CRT_SECURE_NO_WARNINGS 1
//力扣-560.和为K的子数组
//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
//
//输入:nums = [1,1,1], k = 2
//输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
//说明 :数组的长度为 [1, 20,000]。
//数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) //勉强通过
{
	if (nums.size() == 1)
		return nums[0] == k ? 1 : 0;
	int count = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		int n = 0;
		for (int j = i; j >=0; j--)
		{
			n += nums[j];
			if (n == k)
			{
				count++;
				//break;
			}
		}
	}
	return count;
}

int main()
{
	vector<int> arr = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int k = 0;
	cout << subarraySum(arr, k) << endl;

	return 0;
}