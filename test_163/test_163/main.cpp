#define _CRT_SECURE_NO_WARNINGS 1
//力扣-4.寻找两个有序数组的中位数
//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//你可以假设 nums1 和 nums2 不会同时为空。
//示例 1:
//nums1 = [1, 3]
//nums2 = [2]
//则中位数是 2.0
//
//示例 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//则中位数是(2 + 3) / 2 = 2.5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> num = nums1;
	for (size_t i = 0; i < nums2.size(); i++)
		num.push_back(nums2[i]);
	sort(num.begin(), num.end());
	if (num.size() % 2 == 0)
	{
		int x = num.size() / 2;
		double mid = (num[x] + num[x - 1]) / 2.0;
		return mid;
	}
	else
	{
		double mid = num[num.size() / 2];
		return mid;
	}
}

int main()
{
	vector<int> nums1 = { 1, 2 };
	vector<int> nums2 = { 3, 4 };
	cout << findMedianSortedArrays(nums1, nums2) << endl;

	return 0;
}