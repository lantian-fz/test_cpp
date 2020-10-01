#define _CRT_SECURE_NO_WARNINGS 1
//数组中的第K个最大元素
//在未排序的数组中找到第 k 个最大的元素。请注意，
//你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//输入: [3,2,1,5,6,4] 和 k = 2           输出: 5
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4     输出: 4

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int findKthLargest(vector<int>& nums, int k) 
{
	if (nums.empty() || k < 1)
		return -1;
	priority_queue<int> q(nums.begin(), nums.end());
	for (int i = 0; i < k - 1; i++)
		q.pop();
	return q.top();
}
//int findKthLargest_2(vector<int>& nums, int k)
//{
//	multiset<int> st(nums.begin(), nums.end());
//	int i = 0;
//	for (auto e : st)
//	{
//		i++;
//
//		if (i == k)
//			return e;
//	}
//	return 0;
//}
void main()
{
	vector<int> arr{ 1, 3, 5, 2, 2 };
	cout << findKthLargest(arr, 3) << endl;
}