#define _CRT_SECURE_NO_WARNINGS 1
//两个数组的交集 I
//给定两个数组，编写一个函数来计算它们的交集。
//
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]           输出：[2]
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]     输出：[9, 4]
//
//说明：输出结果中的每个元素一定是唯一的。我们可以不考虑输出结果的顺序。

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> ret;
	if (nums1.empty() || nums2.empty())
		return ret;
	unordered_set<int> st1(nums1.begin(),nums1.end());
	unordered_set<int> st2(nums2.begin(), nums2.end());
	for (auto e : st1)
	{
		if (st2.find(e) != st2.end())
			ret.push_back(e);
	}
	
	return ret;
}

void main()
{
	vector<int> arr1 = { 1, 2, 3, 1 };
	vector<int> arr2 = { 2, 2 };
	vector<int> ret = intersection(arr1, arr2);
	for (auto e : ret)
		cout << e << " ";
	cout << endl;
}