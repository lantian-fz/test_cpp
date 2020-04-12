#define _CRT_SECURE_NO_WARNINGS 1
//力扣-1-两数之和
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9   所以返回[0, 1]

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> arr(2, 0);
	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] == target - nums[j])
			{
				arr[0] = i;
				arr[1] = j;
				return arr;
			}
		}
	}
	return arr;
}

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> &arr = twoSum(nums, target);
	cout << arr[0] << ", " << arr[1] << endl;

	return 0;
}