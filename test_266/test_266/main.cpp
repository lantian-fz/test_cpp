#define _CRT_SECURE_NO_WARNINGS 1
//力扣-存在重复元素
//给定一个整数数组，判断是否存在重复元素。
//如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
//
//输入: [1,2,3,1]                      输出: true
//
//输入: [1,2,3,4]                      输出: false
//
//输入: [1,1,1,3,3,4,3,2,4,2]          输出: true

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	if (nums.empty() || nums.size() == 1)
		return false;
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++)
		mp[nums[i]]++;
	for (auto e : mp)
	{
		if (e.second >= 2)
			return true;
	}
	return false;
}

void main()
{
	vector<int> arr = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	cout << containsDuplicate(arr) << endl;
}